// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "PerishableProduct.h"
#include <iostream>
using namespace std;

//Constructors
PerishableProduct::PerishableProduct(int _barcode) 
    : Product(_barcode), storageTemp(0.0), daysLeft(0) {
    cout << "A PerishableProduct has been created\n" << endl;
}

PerishableProduct::PerishableProduct(int _barcode, const char* _name, double _price, int _inStock, const char* _description, double _temp, int _days)
    : Product(_barcode, _name, _price, _inStock, _description), storageTemp(_temp), daysLeft(_days) {
    cout << "A PerishableProduct has been created\n" << endl;
}

// Destructor
PerishableProduct::~PerishableProduct() {
    cout << "A PerishableProduct has been removed\n" << endl;
}

bool PerishableProduct::hasExpired() const {
    // If the days left drop to zero or below, the item is expired
    if (daysLeft <= 0) {
        return true;
    }
    else {
        return false;
    }
}

double PerishableProduct::deliveryCharge() const {
    // Perishable products require refrigerated transport
    // so I applied a approximated rate
    return 10.0;
}

void PerishableProduct::displayInfo() const {
    Product::displayInfo();
    cout << "Storage Temperature: " << storageTemp << " C\n";
    cout << "Days Until Expiration: " << daysLeft << '\n';
    if (hasExpired()) {
        cout << "*** WARNING! THIS ITEM HAS EXPIRED ***\n";
    }
    cout << "=======================" << endl;
}

double PerishableProduct::totalStockValue() const {
    if (hasExpired()) {
        return 0.0; // Expired items hold no sellable value as noted in the file 
    }
    else {
        return Product::totalStockValue();
    }
}


