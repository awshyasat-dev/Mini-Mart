#include "Store.h"

// Constructor
Store::Store(char* n, char* a, int sizeOfInventory, Supplier* sup) : storeInventory(sizeOfInventory) {
	int sizeOfName;
	for (sizeOfName = 0; n[sizeOfName] != '\0'; sizeOfName++);

	name = new char[sizeOfName + 1];

	for (int i = 0; i < sizeOfName; i++) {
		name[i] = n[i];
	}
	name[sizeOfName] = '\0';

	int sizeOfAddress;
	for (sizeOfAddress = 0; a[sizeOfAddress] != '\0'; sizeOfAddress++);

	address = new char[sizeOfAddress + 1];

	for (int i = 0; i < sizeOfAddress; i++) {
		address[i] = a[i];
	}
	address[sizeOfAddress] = '\0';

	storeSupplier = sup;

	cout << "Store " << name << " created" << endl;
}

// Getters
const char* Store::getName() const {
	return name;
}

const char* Store::getAddress() const {
	return address;
}

Inventory* Store::getStoreInventory() {
	return &storeInventory;
}

Supplier* Store::getStoreSupplier() {
	return storeSupplier;
}

// Functions and Methods
void Store::openStore() const {
	cout << "Store is opened" << endl;
}

void Store::closeStore() const {
	cout << "Store is closed" << endl;
}


// Destructor
Store::~Store() {
	cout << "Store " << name << " destroyed" << endl;

	delete[] name;
	delete[] address;
}