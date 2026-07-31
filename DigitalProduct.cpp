// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "DigitalProduct.h"
#include <iostream>
using namespace std;

// Constructors
DigitalProduct::DigitalProduct(int _barcode)
    : Product(_barcode), DownloadSize(0.0) {
    licenceKey = new char[1];
    licenceKey[0] = '\0';
    cout << "A DigitalProduct has been created\n" << endl;
}

DigitalProduct::DigitalProduct(int _barcode, const char* _name, double _price, int _inStock, const char* _description, double _size, const char* _key)
    : Product(_barcode, _name, _price, _inStock, _description), DownloadSize(_size) {

    int countChar = 0;
    for (int i = 0; _key[i] != '\0'; i++) {
        countChar++;
    }

    licenceKey = new char[countChar + 1];

    for (int i = 0; i < countChar; i++) {
        licenceKey[i] = _key[i];
    }

   
    licenceKey[countChar] = '\0';

    cout << "A DigitalProduct has been created\n" << endl;
}

// Destructor
DigitalProduct::~DigitalProduct() {
    delete[] licenceKey;
    cout << "A DigitalProduct has been removed\n" << endl;
}

// Methods
double DigitalProduct::deliveryCharge() const {
    // Digital products do not require physical delivery
    // so the charge is zero
    return 0.0;
}

void DigitalProduct::displayInfo() const {
    Product::displayInfo();
    cout << "Download Size: " << DownloadSize << " MB\n";
    cout << "Licence Key: " << licenceKey << '\n';
    cout << "=======================" << endl;
}