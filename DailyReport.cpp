// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "DailyReport.h"
#include "Product.h"
#include <iostream>
using namespace std;

// Constructor
DailyReport::DailyReport() {
    cout << "DailyReport created" << endl;
}

// Functions and Methods
void DailyReport::generate(Inventory& inventory, Order** orders, int orderCount) const {
    cout << "\n========== MiniMart End of Day Report ==========\n";

    // Calculate total revenue
    double totalRev = 0.0;

    for (int i = 0; i < orderCount; i++) {
        totalRev += orders[i]->total();
    }

    cout << "Total Orders Processed : " << orderCount << endl;
    cout << "Total Revenue          : $" << totalRev << endl;

    cout << "\nOrders Summary\n";
    cout << "----------------------------------------\n";

    if (orderCount == 0) {
        cout << "No orders were processed today.\n";
    }
    else {
        // Display orders
        for (int i = 0; i < orderCount; i++) {
            orders[i]->displayOrder();
            cout << "----------------------------------------\n";
        }
    }

    // Orders against inventory
    cout << "\nChecking Orders Against Inventory\n";

    bool disFound = false;

    for (int i = 0; i < orderCount; i++) {
        for (int j = 0; j < orders[i]->ItemCount; j++) {

            // Get a pointer to the ordered product
            Product* orderedProduct = &(orders[i]->product[j]);
            int requestedQty = orders[i]->quantities[j];

            // Search the inventory
            Product* current = nullptr;
            int targetBarcode = orderedProduct->getBarcode();

            for (int s = 0; s < 50; s++) { // search -> shelf
                if (inventory.shelf[s] != nullptr && inventory.shelf[s]->getBarcode() == targetBarcode) {
                    current = inventory.shelf[s];
                    break;
                }
            }

            if (current == nullptr) { // search -> warehouse
                for (int w = 0; w < inventory.warehouseSize; w++) {
                    if (inventory.warehouse[w] != nullptr && inventory.warehouse[w]->getBarcode() == targetBarcode) {
                        current = inventory.warehouse[w];
                        break;
                    }
                }
            }

            if (current == nullptr) {
                cout << "[WARNING] Product from Order #"
                    << orders[i]->getOrderNumber()
                    << " no longer exists in inventory "
                    << "(Barcode "
                    << orderedProduct->getBarcode()
                    << ")." << endl;

                disFound = true;
            }
            else if (current->getStock() < requestedQty) {
                // Case 2: product exists, but not enough stock to cover what was ordered
                cout << "[WARNING] Order #" << orders[i]->getOrderNumber()
                    << " requested " << requestedQty
                    << " of \"" << current->getName() << "\""
                    << " but only " << current->getStock()
                    << " are available in inventory."
                    << endl;

                disFound = true;
            }
        }
    }

    if (!disFound) {
        cout << "No discrepancies found." << endl;
    }

    cout << "----------------------------------------\n";

    cout << "Current Product Count      : "
        << Product::getProductCounter() << endl;

    cout << "Sellable Stock Value       : $"
        << inventory.sellableStockValue() << endl;

    cout << "========================================\n";
}

// Destructor
DailyReport::~DailyReport() {
    cout << "DailyReport destroyed" << endl;
}
