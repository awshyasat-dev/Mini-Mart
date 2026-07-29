// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include <iostream>
#include "Supplier.h"
using namespace std;

// Constructor
Supplier::Supplier(const char* name, const char* phone, const char* _address) {
	int sizeName;
	for (sizeName = 0; name[sizeName] != '\0'; sizeName++);
	companyName = new char[sizeName + 1];

	for (int i = 0; name[i] != '\0'; i++)
		companyName[i] = name[i];
	companyName[sizeName] = '\0';

	int sizePhone;
	for (sizePhone = 0; phone[sizePhone] != '\0'; sizePhone++);
	phoneNumber = new char[sizePhone + 1];

	for (int i = 0; phone[i] != '\0'; i++)
		phoneNumber[i] = phone[i];
	phoneNumber[sizePhone] = '\0';

	int sizeAddress;
	for (sizeAddress = 0; _address[sizeAddress] != '\0'; sizeAddress++);
	address = new char[sizeAddress + 1];

	for (int i = 0; _address[i] != '\0'; i++)
		address[i] = _address[i];
	address[sizeAddress] = '\0';

	barcodeCount = 0;

	cout << "Supplier " << companyName << " created" << endl;
}

// Setters
void Supplier::setCompanyName(const char* name) {
	delete[] companyName;

	int sizeName;
	for (sizeName = 0; name[sizeName] != '\0'; sizeName++);
	companyName = new char[sizeName + 1];

	for (int i = 0; name[i] != '\0'; i++)
		companyName[i] = name[i];
	companyName[sizeName] = '\0';
}

void Supplier::setPhoneNumber(const char* phone) {
	delete[] phoneNumber;

	int sizePhone;
	for (sizePhone = 0; phone[sizePhone] != '\0'; sizePhone++);
	phoneNumber = new char[sizePhone + 1];

	for (int i = 0; phone[i] != '\0'; i++)
		phoneNumber[i] = phone[i];
	phoneNumber[sizePhone] = '\0';
}

void Supplier::setAddress(const char* _address) {
	delete[] address;

	int sizeAddress;
	for (sizeAddress = 0; _address[sizeAddress] != '\0'; sizeAddress++);
	address = new char[sizeAddress + 1];

	for (int i = 0; _address[i] != '\0'; i++)
		address[i] = _address[i];
	address[sizeAddress] = '\0';
}

// Getters
const char* Supplier::getCompanyName() const {
	return companyName;
}

const char* Supplier::getPhoneNumber() const {
	return phoneNumber;
}

const char* Supplier::getAddress() const {
	return address;
}

const int* Supplier::getBarcodes() const {
	return barcodes;
}

// Functions and Methods
void Supplier::addSuppliedProduct(int barcode) {
	int* temp = new int[barcodeCount + 1];
	for (int i = 0; i < barcodeCount; i++)
		temp[i] = barcodes[i];
	temp[barcodeCount] = barcode;

	delete[] barcodes;
	barcodes = temp;
	barcodeCount++;
}

void Supplier::displayInfo() const {
	cout << "Company name: " << companyName
		<< "\nPhone number: " << phoneNumber
		<< "\nAddress: " << address
		<< "\nBarcodes:" << endl;

	for (int i = 0; i < barcodeCount; i++)
		cout << "Barcode (" << i+1 << ") " << barcodes[i] << endl;
}

// Destructor
Supplier::~Supplier() {
	cout << "Supplier " << companyName << " destroyed" << endl;

	delete[] companyName;
	delete[] phoneNumber;
	delete[] address;
	delete[] barcodes;
}
