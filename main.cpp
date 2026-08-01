// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat
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
    //taking data 
    DailyReport report;
    cout << "Current Product Count: " << Product::getProductCounter() << endl;
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
    //starting the menu

    const BoxedProduct oliveOil(1001, "Olive Oil 1L", 4.25, 50, "Extra Virgin Olive Oil", 1.0, 'A', 1, "Olive Oil");

    int choice;
    store.openStore();
    do
    {   //print the menu
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
        // Case 1: Add a product to the shelf
        if (choice == 1) {
            string name;
            double price;
            int stock;
            int barcode;
            int type;
            //taking the type
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

            cin.ignore();

            string descriptionStr;
            cout << "Enter product description: ";
            getline(cin, descriptionStr);

            int descLen = 0;
            while (descriptionStr[descLen] != '\0')
                descLen++;

            char* description = new char[descLen + 1];

            for (int i = 0; i < descLen; i++)
                description[i] = descriptionStr[i];

            description[descLen] = '\0';

            //checking before continue 
            if (store.getStoreInventory()->getSlotsCount() >= 50)
            {
                cout << "Shelf is full. Cannot add product.\n";
                delete[] productName;
                delete[] description;
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
                cin.ignore();
                string labelStr;
                cout << "Enter label text: ";
                getline(cin, labelStr);

                int labelLen = 0;
                while (labelStr[labelLen] != '\0')
                    labelLen++;

                char* labelText = new char[labelLen + 1];

                for (int i = 0; i < labelLen; i++)
                    labelText[i] = labelStr[i];

                labelText[labelLen] = '\0';
                BoxedProduct* p = new BoxedProduct(barcode, productName, price, stock, description, weight, aisle1, slot1, labelText);

                store.getStoreInventory()->addToShelf(p);

                delete[] description;
                delete[] labelText;
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

                PerishableProduct* p = new PerishableProduct(
                    barcode,
                    productName,
                    price,
                    stock,
                    description,
                    temp1,
                    daysLeft1
                );

                store.getStoreInventory()->addToShelf(p);

                delete[] description;
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

                DigitalProduct* p = new DigitalProduct(
                    barcode,
                    productName,
                    price,
                    stock,
                    description,
                    size1,
                    licenceName
                );

                delete[] description;
                store.getStoreInventory()->addToShelf(p);

                delete[] productName;
                delete[] licenceName;
            }
            else
            {
                cout << "Invalid product type.\n";
                delete[] productName;
                delete[] description;
            }
        }
        // Case 2: Add a product to the warehouse
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
            cin.ignore();

            string descriptionStr;
            cout << "Enter product description: ";
            getline(cin, descriptionStr);

            int descLen = 0;
            while (descriptionStr[descLen] != '\0')
                descLen++;

            char* description = new char[descLen + 1];

            for (int i = 0; i < descLen; i++)
                description[i] = descriptionStr[i];

            description[descLen] = '\0';

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
                cin.ignore();
                string labelStr;
                cout << "Enter label text: ";
                getline(cin, labelStr);

                int labelLen = 0;
                while (labelStr[labelLen] != '\0')
                    labelLen++;

                char* labelText = new char[labelLen + 1];

                for (int i = 0; i < labelLen; i++)
                    labelText[i] = labelStr[i];

                labelText[labelLen] = '\0';
                BoxedProduct* p = new BoxedProduct(barcode, productName, price, stock, description, weight, aisle1, slot1, labelText);

                store.getStoreInventory()->addProduct(p);

                delete[] description;
                delete[] labelText;
                delete[] productName;
            }
            else if (type == 2) {
                double temp1;
                int daysLeft1;

                cout << "Enter storage temperature: ";
                cin >> temp1;

                cout << "Enter days left before expiry: ";
                cin >> daysLeft1;

                PerishableProduct* p = new PerishableProduct(
                    barcode,
                    productName,
                    price,
                    stock,
                    description,
                    temp1,
                    daysLeft1
                );

                store.getStoreInventory()->addProduct(p);

                delete[] description;
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

                DigitalProduct* p = new DigitalProduct(
                    barcode,
                    productName,
                    price,
                    stock,
                    description,
                    size1,
                    licenceName
                );

                delete[] description;

                store.getStoreInventory()->addProduct(p);

                delete[] productName;
                delete[] licenceName;
            }
            else {
                cout << "Invalid product type.\n";
                delete[] productName;
                delete[] description;
            }
        }
        // Case 3: Display all products on the shelf
        else if (choice == 3) {
            cout << "\n--- Products on the Shelf ---\n";
            store.getStoreInventory()->listShelf();
        }
        // Case 4: Search for a product using its barcode
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
        // Case 5: Search for a product by its name
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
        }       // Case 6: Remove a product using its barcode
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
        // Case 7: Add supplier information and delivered products
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
        // Case 8: Create a new customer order
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
        // Case 9: Add a product to an existing order
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
            else {
                int barcode;
                cout << "Enter product barcode: ";
                cin >> barcode;
                Product* p = store.getStoreInventory()->findByBarcode(barcode);
                if (p == nullptr) { cout << "Product not found.\n"; }
                else {
                    int quantity;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    selectedOrder->addItem(p, quantity);
                    cout << "Item added successfully.\n";
                }
            }
        }
        // Case 10: Merge two orders from the same customer
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
            for (int i = 0; i < orderCount; i++) {
                if (orders[i]->getOrderNumber() == firstNumber)
                    firstOrder = orders[i];

                if (orders[i]->getOrderNumber() == secondNumber)
                    secondOrder = orders[i];
            }

            if (firstOrder == nullptr || secondOrder == nullptr) { cout << "Order not found.\n"; }
            else {
                firstOrder->mergeWith(*secondOrder);
                cout << "Orders merged successfully.\n";
            }
        }
        // Case 11: Complete the selected order
        else if (choice == 11) {
            int orderNumber;
            cout << "Enter order number: ";
            cin >> orderNumber;
            Order* selectedOrder = nullptr;
            for (int i = 0; i < orderCount; i++) {
                if (orders[i]->getOrderNumber() == orderNumber) {
                    selectedOrder = orders[i];
                    break;
                }
            }

            if (selectedOrder == nullptr) { cout << "Order not found.\n"; }
            else {
                selectedOrder->complete(*store.getStoreInventory());

            }
        }
        // Case 12: Print the total sellable stock value
        else if (choice == 12) {
            cout << "Sellable Stock Value = "
                << store.getStoreInventory()->sellableStockValue()
                << endl;
        }
        // Case 13: Display the current product count
        else if (choice == 13) {
            cout << "Current Product Count = "
                << Product::getProductCounter()
                << endl;
        }
        // Case 14: Print labels
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
        // Case 15: Generate the end-of-day report
        else if (choice == 15) {
            report.generate(*store.getStoreInventory(), orders, orderCount);
        }
        // Case 16: Close the store and exit the program
        else if (choice == 16) {
            cout << "Closing shop...\n";
            cout << "Goodbye!\n";
            store.closeStore();
        }
        else
            cout << "INVALID CHOICE\n";
    } while (choice != 16);

    //delete 
    for (int i = 0; i < orderCount; i++) { delete orders[i]; }
    delete[] orders;

    return 0;
}