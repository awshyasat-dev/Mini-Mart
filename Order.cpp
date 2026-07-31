// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "Order.h"
#include "Inventory.h"
#include <iostream>
using namespace std;

int Order::Counter = 1;

Order::Order(const char* name) : Order_number(Counter++), ItemCount(0) {
    int x = 0;
    for (int i = 0; name[i] != 0; i++) { x++; }
    Customer_name = new char[x + 1];
    for (int i = 0; i < x; i++)
        Customer_name[i] = name[i];
    Customer_name[x] = '\0';
    capacity = 5;
    product = new Product * [capacity];
    quantities = new int[capacity];
    cout << "Order " << Order_number << " created" << endl;
}

Order::Order(const Order& other) : Order_number(Counter++), ItemCount(other.ItemCount) {
    int x = 0;
    while (other.Customer_name[x] != '\0') x++;
    Customer_name = new char[x + 1];
    for (int i = 0; i < (x + 1); i++)
        Customer_name[i] = other.Customer_name[i];
    capacity = other.capacity;
    product = new Product * [capacity];
    quantities = new int[capacity];
    for (int i = 0; i < ItemCount; i++)
        product[i] = other.product[i];
    for (int i = 0; i < ItemCount; i++)
        quantities[i] = other.quantities[i];
    cout << "Order " << Order_number << " copied" << endl;
}

Order::~Order() {
    cout << "Order " << Order_number << " destroyed" << endl;
    delete[] Customer_name;
    delete[] product;      // only deletes the pointer array itself — NOT the Products,
    // since Inventory owns and deletes those
    delete[] quantities;
}

void Order::addItem(Product* p, int quantity) {
    for (int i = 0; i < ItemCount; i++) {
        if (product[i]->isSameItem(*p)) {
            quantities[i] += quantity;
            return;
        }
    }
    if (ItemCount == capacity) {
        Product** temp = new Product * [capacity + 5];
        int* temp2 = new int[capacity + 5];
        for (int i = 0; i < ItemCount; i++) {
            temp[i] = product[i];
            temp2[i] = quantities[i];
        }
        delete[] product;
        delete[] quantities;
        product = temp;
        quantities = temp2;
        capacity += 5;
    }
    product[ItemCount] = p;
    quantities[ItemCount] = quantity;
    ItemCount++;
}

void Order::mergeWith(const Order& other) {
    bool test = true;
    int i = 0;
    while (Customer_name[i] != '\0' || other.Customer_name[i] != '\0') {
        if (Customer_name[i] != other.Customer_name[i]) {
            test = false;
            break;
        }
        i++;
    }
    if (test) {
        capacity += other.ItemCount;
        Product** temp = new Product * [capacity];
        int* temp2 = new int[capacity];
        for (int i = 0; i < ItemCount; i++) {
            temp[i] = product[i];
            temp2[i] = quantities[i];
        }
        int newitems = 0;
        for (int i = 0; i < other.ItemCount; i++) {
            bool found = false;
            for (int j = 0; j < ItemCount; j++) {
                if (product[j]->isSameItem(*other.product[i])) {
                    temp2[j] += other.quantities[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                temp[ItemCount + newitems] = other.product[i];
                temp2[ItemCount + newitems] = other.quantities[i];
                newitems++;
            }
        }
        ItemCount += newitems;
        delete[] product;
        delete[] quantities;
        product = temp;
        quantities = temp2;
    }
    else
        cout << "The customers do not match \n";
}

void Order::complete(Inventory& inventory) {
    bool wecandoorder = true;
    for (int i = 0; i < ItemCount; i++) {
        if (product[i]->getStock() < quantities[i]) {
            wecandoorder = false;
            break;
        }
    }
    if (wecandoorder) {
        for (int i = 0; i < ItemCount; i++) {
            product[i]->setStock(product[i]->getStock() - quantities[i]);
        }
        cout << "Order completed\n";
    }
    else
        cout << "Order failed\n";
}

double Order::total() {
    double sum = 0;
    for (int i = 0; i < ItemCount; i++) {
        sum += product[i]->getPrice() * quantities[i];
    }
    return sum;
}

void Order::displayOrder() {
    cout << "Order number: " << Order_number << endl;
    cout << "Customer name: " << Customer_name << endl;
    cout << "Items: " << ItemCount << endl;
    cout << "--------------------------------\n";
    for (int i = 0; i < ItemCount; i++) {
        product[i]->displayInfo();
        cout << "Ordered quantity: " << quantities[i] << endl;
        cout << "--------------------------------\n";
    }
    cout << "Total = " << total() << endl;
}

int Order::getOrderNumber() const {
    return Order_number;
}