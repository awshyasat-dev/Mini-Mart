#include <iostream>
#include <string>
#include "Product.h"
#include "BoxedProduct.h"
#include "PerishableProduct.h"
#include "DigitalProduct.h"
#include "Label.h"
#include "ShelfLocation.h"
#include "Supplier.h"
#include "Inventory.h"
#include "Store.h"
#include "Order.h"
#include "DailyReport.h"
using namespace std;
int main() {
    DailyReport report;
    cout << "Current Product Count: " << Product::getProductCount() << endl;
    int warehouseSize;
    do {
        cout << "Enter warehouse size: ";
        cin >> warehouseSize;
    } while (warehouseSize <= 0);
    string storeNameStr;
    cout << "Enter store name: ";
    cin.ignore();
    getline(cin, storeNameStr);

    int len = 0;
    while (storeNameStr[len] != '\0')
        len++;

    char* storeName = new char[len + 1];

    for (int i = 0; i < len; i++)
        storeName[i] = storeNameStr[i];

    storeName[len] = '\0';


    string storeAddressStr;
    cout << "Enter store address: ";
    getline(cin, storeAddressStr);

    len = 0;
    while (storeAddressStr[len] != '\0')
        len++;

    char* storeAddress = new char[len + 1];

    for (int i = 0; i < len; i++)
        storeAddress[i] = storeAddressStr[i];

    storeAddress[len] = '\0';


    Supplier supplier;
    Store store(storeName, storeAddress, warehouseSize, &supplier);

    delete[] storeName;
    delete[] storeAddress;


    int capacity = 5;
    int orderCount = 0;
    Order** orders = new Order * [capacity];

    int choice;
    store.openStore();
    do
    {
        cout << "\n========== MiniMart ==========\n";
        cout << "1. Add a product to the shelf\n";
        cout << "2. Add a product to the warehouse\n";
        cout << "3. Display all products on the shop floor\n";
        cout << "4. Search for a product by barcode\n";
        cout << "5. Search for a product by name\n";
        cout << "6. Remove a product by barcode\n";
        cout << "7. Add a supplier and the products it delivers\n";
        cout << "8. Start a new customer order\n";
        cout << "9. Add an item to an order\n";
        cout << "10. Merge two orders from the same customer\n";
        cout << "11. Complete an order\n";
        cout << "12. Print the total value of sellable stock\n";
        cout << "13. Print how many products currently exist\n";
        cout << "14. Print a label for a product, a shelf and a delivery box\n";
        cout << "15. Print the end of day report\n";
        cout << "16. Close the shop and exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        ShelfLocation loc;
        loc.setAisle('A');
        loc.setSlot(1);

        const BoxedProduct oliveOil(1001, "Olive Oil 1L", 4.25, 50, 1.0, loc);

        if (choice == 1) {
            string name;
            double price;
            int stock;
            int barcode;
            int type;

            cout << "Enter product type (1=Boxed, 2=Perishable, 3=Digital): ";
            cin >> type;
            cin.ignore();

            cout << "Enter barcode: ";
            cin >> barcode;
            cin.ignore();

            cout << "Enter product name: ";
            getline(cin, name);

            int len = 0;
            while (name[len] != '\0')
                len++;

            char* productName = new char[len + 1];

            for (int i = 0; i < len; i++)
                productName[i] = name[i];

            productName[len] = '\0';

            cout << "Enter price: ";
            cin >> price;

            cout << "Enter stock: ";
            cin >> stock;

            if (store.getStoreInventory()->getSlotsCount() >= 50)
            {
                cout << "Shelf is full. Cannot add product.\n";
                delete[] productName;
            }
            else if (type == 1)
            {
                double weight;
                cout << "Enter weight (kg): ";
                cin >> weight;

                char aisle1;
                int slot1;

                cout << "Enter aisle letter: ";
                cin >> aisle1;

                cout << "Enter slot number: ";
                cin >> slot1;

                ShelfLocation loc;
                loc.setAisle(aisle1);
                loc.setSlot(slot1);

                BoxedProduct* p = new BoxedProduct(barcode, productName, price, stock, weight, loc);

                store.getStoreInventory()->addToShelf(p);

                delete[] productName;
            }
            else if (type == 2)
            {
                double temp1;
                int daysLeft1;

                cout << "Enter storage temperature: ";
                cin >> temp1;

                cout << "Enter days left before expiry: ";
                cin >> daysLeft1;

                PerishableProduct* p = new PerishableProduct(barcode, productName, price, stock, temp1, daysLeft1);

                store.getStoreInventory()->addToShelf(p);

                delete[] productName;
            }
            else if (type == 3)
            {
                double size1;
                string licence;

                cout << "Enter download size (MB): ";
                cin >> size1;
                cin.ignore();

                cout << "Enter licence key: ";
                getline(cin, licence);

                len = 0;
                while (licence[len] != '\0')
                    len++;

                char* licenceName = new char[len + 1];

                for (int i = 0; i < len; i++)
                    licenceName[i] = licence[i];

                licenceName[len] = '\0';

                DigitalProduct* p = new DigitalProduct(barcode, productName, price, stock, size1, licenceName);

                store.getStoreInventory()->addToShelf(p);

                delete[] productName;
                delete[] licenceName;
            }
            else
            {
                cout << "Invalid product type.\n";
                delete[] productName;
            }
        }
        else if (choice == 2) {
            string name;
            double price;
            int stock;
            int barcode;
            int type;

            cout << "Enter product type (1=Boxed, 2=Perishable, 3=Digital): ";
            cin >> type;
            cin.ignore();

            cout << "Enter barcode: ";
            cin >> barcode;
            cin.ignore();

            cout << "Enter product name: ";
            getline(cin, name);

            int len = 0;
            while (name[len] != '\0')
                len++;

            char* productName = new char[len + 1];

            for (int i = 0; i < len; i++)
                productName[i] = name[i];

            productName[len] = '\0';

            cout << "Enter price: ";
            cin >> price;

            cout << "Enter stock: ";
            cin >> stock;

            if (type == 1) {
                double weight;

                cout << "Enter weight (kg): ";
                cin >> weight;

                char aisle1;
                int slot1;

                cout << "Enter aisle letter: ";
                cin >> aisle1;

                cout << "Enter slot number: ";
                cin >> slot1;

                ShelfLocation loc;
                loc.setAisle(aisle1);
                loc.setSlot(slot1);

                BoxedProduct* p = new BoxedProduct(barcode, productName, price, stock, weight, loc);

                store.getStoreInventory()->addProduct(p);

                delete[] productName;
            }
            else if (type == 2) {
                double temp1;
                int daysLeft1;

                cout << "Enter storage temperature: ";
                cin >> temp1;

                cout << "Enter days left before expiry: ";
                cin >> daysLeft1;

                PerishableProduct* p = new PerishableProduct(barcode, productName, price, stock, temp1, daysLeft1);

                store.getStoreInventory()->addProduct(p);

                delete[] productName;
            }
            else if (type == 3) {
                double size1;
                string licence;

                cout << "Enter download size (MB): ";
                cin >> size1;
                cin.ignore();

                cout << "Enter licence key: ";
                getline(cin, licence);

                len = 0;
                while (licence[len] != '\0')
                    len++;

                char* licenceName = new char[len + 1];

                for (int i = 0; i < len; i++)
                    licenceName[i] = licence[i];

                licenceName[len] = '\0';

                DigitalProduct* p = new DigitalProduct(barcode, productName, price, stock, size1, licenceName);

                store.getStoreInventory()->addProduct(p);

                delete[] productName;
                delete[] licenceName;
            }
            else {
                cout << "Invalid product type.\n";
                delete[] productName;
            }
        }
        else if (choice == 3) {
            cout << "\n--- Products on the Shelf ---\n";
            store.getStoreInventory()->listShelf();
        }
        else if (choice == 4) {
            int barcode;
            cout << "Enter barcode to search: ";
            cin >> barcode;

            Product* p = store.getStoreInventory()->findByBarcode(barcode);
            if (p == nullptr) {
                cout << "No product found with barcode " << barcode << endl;
            }
            else {
                p->displayInfo();
            }
        }
        else if (choice == 5) {
            string name;

            cout << "Enter product name to search: ";
            cin.ignore();
            getline(cin, name);

            int len = 0;
            while (name[len] != '\0')
                len++;

            char* productName = new char[len + 1];

            for (int i = 0; i < len; i++)
                productName[i] = name[i];

            productName[len] = '\0';

            Product* p = store.getStoreInventory()->findByName(productName);

            if (p == nullptr) {
                cout << "No product found with name " << name << endl;
            }
            else {
                p->displayInfo();
            }

            delete[] productName;
        }
        else if (choice == 6) {
            int barcode;
            cout << "Enter barcode to remove: ";
            cin >> barcode;

            Product* p = store.getStoreInventory()->findByBarcode(barcode);
            if (p == nullptr) {
                cout << "No product found with barcode " << barcode << endl;
            }
            else {
                store.getStoreInventory()->removeByBarcode(barcode);
                cout << "Product removed.\n";
            }
        }
        else if (choice == 7) {
            string companyName;
            cout << "Enter company name: ";
            cin.ignore();
            getline(cin, companyName);

            int len = 0;
            while (companyName[len] != '\0')
                len++;

            char* company = new char[len + 1];

            for (int i = 0; i < len; i++)
                company[i] = companyName[i];

            company[len] = '\0';


            string phoneNumber;
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);

            len = 0;
            while (phoneNumber[len] != '\0')
                len++;

            char* phone = new char[len + 1];

            for (int i = 0; i < len; i++)
                phone[i] = phoneNumber[i];

            phone[len] = '\0';


            string addressStr;
            cout << "Enter address: ";
            getline(cin, addressStr);

            len = 0;
            while (addressStr[len] != '\0')
                len++;

            char* address = new char[len + 1];

            for (int i = 0; i < len; i++)
                address[i] = addressStr[i];

            address[len] = '\0';


            store.getStoreSupplier()->setCompanyName(company);
            store.getStoreSupplier()->setPhoneNumber(phone);
            store.getStoreSupplier()->setAddress(address);



            int count;
            cout << "How many products does this supplier deliver? ";
            cin >> count;

            for (int i = 0; i < count; i++)
            {
                int barcode;
                cout << "Enter barcode #" << i + 1 << ": ";
                cin >> barcode;

                store.getStoreSupplier()->addSuppliedProduct(barcode);
            }

            delete[] company;
            delete[] phone;
            delete[] address;

            cout << "Supplier added successfully.\n";
        }
        else if (choice == 8) {
            string name;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            //to get the string lenght
            int len = 0;
            while (name[len] != '\0') { len++; }

            //make it as char array
            char* customerName = new char[len + 1];
            for (int i = 0; i < len; i++) { customerName[i] = name[i]; }
            customerName[len] = '\0';

            //to expand the order list if there is no capacity
            if (orderCount == capacity) {
                capacity += 5;
                Order** temp = new Order * [capacity];
                for (int i = 0; i < orderCount; i++) { temp[i] = orders[i]; }
                delete[] orders;
                orders = temp;
            }

            orders[orderCount] = new Order(customerName);
            delete[] customerName;
            orderCount++;

            cout << "Order created successfully.\n";
        }
        else if (choice == 9)
        {
            int orderNumber;

            cout << "Enter order number: ";
            cin >> orderNumber;

            Order* selectedOrder = nullptr;

            for (int i = 0; i < orderCount; i++)
            {
                if (orders[i]->getOrderNumber() == orderNumber)
                {
                    selectedOrder = orders[i];
                    break;
                }
            }

            if (selectedOrder == nullptr)
            {
                cout << "Order not found.\n";
            }
            else
            {
                int barcode;
                cout << "Enter product barcode: ";
                cin >> barcode;

                Product* p = store.getStoreInventory()->findByBarcode(barcode);

                if (p == nullptr)
                {
                    cout << "Product not found.\n";
                }
                else
                {
                    int quantity;

                    cout << "Enter quantity: ";
                    cin >> quantity;

                    selectedOrder->addItem(*p, quantity);

                    cout << "Item added successfully.\n";
                }
            }
        }

        else if (choice == 10)
        {
            int firstNumber;
            int secondNumber;

            cout << "Enter first order number: ";
            cin >> firstNumber;

            cout << "Enter second order number: ";
            cin >> secondNumber;

            Order* firstOrder = nullptr;
            Order* secondOrder = nullptr;

            for (int i = 0; i < orderCount; i++)
            {
                if (orders[i]->getOrderNumber() == firstNumber)
                    firstOrder = orders[i];

                if (orders[i]->getOrderNumber() == secondNumber)
                    secondOrder = orders[i];
            }

            if (firstOrder == nullptr || secondOrder == nullptr)
            {
                cout << "Order not found.\n";
            }
            else
            {
                firstOrder->mergeWith(*secondOrder);

                cout << "Orders merged successfully.\n";
            }
        }

        else if (choice == 11)
        {
            int orderNumber;

            cout << "Enter order number: ";
            cin >> orderNumber;

            Order* selectedOrder = nullptr;

            for (int i = 0; i < orderCount; i++)
            {
                if (orders[i]->getOrderNumber() == orderNumber)
                {
                    selectedOrder = orders[i];
                    break;
                }
            }

            if (selectedOrder == nullptr)
            {
                cout << "Order not found.\n";
            }
            else
            {
                selectedOrder->complete(*store.getStoreInventory());

                cout << "Order completed successfully.\n";
            }
        }
        else if (choice == 12) {
            cout << "Sellable Stock Value = "
                << store.getStoreInventory()->sellableStockValue()
                << endl;
        }
        else if (choice == 13) {
            cout << "Current Product Count = "
                << Product::getProductCount()
                << endl;
        }
        else if (choice == 14) {
            string text;
            cin.ignore();
            cout << "Enter label text: ";
            getline(cin, text);
            int len = 0;
            while (text[len] != '\0')
                len++;
            char* labelText = new char[len + 1];
            for (int i = 0; i < len; i++)
                labelText[i] = text[i];
            labelText[len] = '\0';
            Label l(labelText);
            l.printLabel();
            delete[] labelText;
        }
        else if (choice == 15) {
            report.generate(*store.getStoreInventory(), orders, orderCount);
        }
        else if (choice == 16) {
            cout << "Closing shop...\n";
            cout << "Goodbye!\n";
            store.closeStore();
        }
        else
            cout << "INVALID CHOICE\n";
    } while (choice != 16);


    for (int i = 0; i < orderCount; i++) { delete orders[i]; }
    delete[] orders;

    return 0;
}