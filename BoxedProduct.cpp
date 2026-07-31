// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include <iostream>
#include "BoxedProduct.h"

using namespace std;

//Constructors
BoxedProduct::BoxedProduct(int _barcode)
	:Product(_barcode), weight(0.0) {
    // location was built using its default constructor 

	cout << "A BoxedProduct has been created\n" << endl;

}

BoxedProduct::BoxedProduct(int _barcode, const char* _name, double _price, int _inStock, const char* _description, double _weight, char _aisle, int _slot)
    : Product(_barcode, _name, _price, _inStock, _description), weight(_weight) {

    // location was built using its default constructor 
    // so I used setters to fill it
    location.setAisle(_aisle);
    location.setSlot(_slot);

    cout << "A BoxedProduct has been created\n" << endl;
}

// Destructor
BoxedProduct::~BoxedProduct() {

    cout << "A BoxedProduct has been removed\n" << endl;

}

// Methods
double BoxedProduct::deliveryCharge() const {
    //depending on avg of delivery charge per kilo in Jordan
    return weight * 2;
}

void BoxedProduct::displayInfo() const {
    Product::displayInfo();

    cout << "Weight: " << weight << " kg\n";
    cout << "Shelf Location: ";
    location.displayLocation();
    cout << "=======================" << endl;
}
