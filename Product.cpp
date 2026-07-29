// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "Product.h"
#include <iostream>
using namespace std;

//Constructors

Product::Product(int _barcode) :
    barcode(_barcode) {
    name[0] = '\0';
    price = 0.0;
    inStock = 0;
    description = nullptr;
    cout << "A product has been created\n" << endl;
    productCounter++;
}
Product::Product(int _barcode, const char* _name, double _price, int _inStock, const char* _description)
    : barcode(_barcode) {

    int countChar = 0;

    for (int i = 0; _name[i] != '\0'; i++) {
        countChar++;
    }
    for (int i = 0; i <= countChar; i++) {
        name[i] = _name[i];
    }

    price = _price;
    inStock = _inStock;


    int descCount = 0;

    for(int i = 0; _description[i] != '\0'; i++) {
        descCount++;
    }

    description = new char[descCount + 1];

    for (int i = 0; i <= descCount; i++) {
        description[i] = _description[i];
    }
    cout << "A product has been created\n" << endl;
    productCounter++;


}

Product::Product(const Product& other) :
    barcode(other.barcode) {
    price = other.price;
    inStock = other.inStock;

    int countChar = 0;

    for (int i = 0; other.name[i] != '\0'; i++) {
        countChar++;
    }
    for (int i = 0; i <= countChar; i++) {
        name[i] = other.name[i];
    }

    // Here because we didn't cover the Rule of three and string library
    // must use for loop instead of string library
    // and dot method instead of rule of three
    int descCount = 0;

    for (int i = 0; other.description[i] != '\0'; i++) {
        descCount++;
    }

    description = new char[descCount + 1];

    for (int i = 0; i <= descCount; i++) {
        description[i] = other.description[i];
    }
    cout << "A product has been copied\n" << endl;
    productCounter++;

}

//Destructors

Product::~Product() {
    delete[] description;
    cout << "A product has been removed\n" << endl;
}

//Setters

Product& Product::setName(const char* newName) {
    int countChar = 0;

    for (int i = 0; newName[i] != '\0'; i++) {
        countChar++;
    }
    for (int i = 0; i <= countChar; i++) {
        name[i] = newName[i];
    }
    return *this;

}

Product& Product::setPrice(double newPrice) {
    if (newPrice < 0) {
        cout << "Price can't be negative" << endl;
    }
    else {
        price = newPrice;
    }
    return *this;
}

Product& Product::setStock(int newStock) {
    if (newStock < 0) {
        cout << "Stock can't be below 0" << endl;
    }
    else {
        inStock = newStock;
    }
    return *this;

}

//Getters

int Product::getBarcode() const {
    return barcode;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return inStock;
}

//Members Functions

void Product::addStock(int units) {
    inStock += units;
}

bool Product::isSameItem(const Product& other) const {
    if (barcode == other.barcode) {
        return true;
    }
    else {
        return false;
    }
}

double Product::totalStockValue() const {
   return price * inStock;
}

void Product::displayInfo() const {
    cout << "=== Product Details ===\n";
    cout << "Barcode: " << barcode << '\n';
    cout << "Name: " << name << '\n';
    cout << "Price: " << price << '\n';
    cout << "Quantity in Stock: " << inStock << '\n';
    cout << "Description: ";
    //used this method to handle the error without crash as requested
    //because I initialized the description dynamic arr
    //as a nullptr in the default constructor
    if (description != nullptr) {
        int i = 0;
        while (description[i] != '\0') {
            cout << description[i];
            i++;
        }
        cout << '\n';
    }
    else {
        cout << "No description available.\n";
    }
    cout << "=======================" << endl;
}

int Product::productCounter = 0;

int Product::getProductCounter() {
    return productCounter;
}