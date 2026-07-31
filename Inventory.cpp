// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "Inventory.h"
#include "Product.h"

// Constructor
Inventory::Inventory(int size) {
	slotsCount = 0;
	warehouseCount = 0;

	warehouseSize = size;
	warehouse = new Product*[size];

	for (int i = 0; i < size; i++)
		warehouse[i] = nullptr;

	for (int i = 0; i < 50; i++)
		shelf[i] = nullptr;

	cout << "Inventory created" << endl;
}

// Getters
int Inventory::getSlotsCount() const {
	return slotsCount;
}

int Inventory::getWarehouseCount() const {
	return warehouseCount;
}

// Functions and Methods
void Inventory::addProduct(Product* prod) {
	/*
		Adds a product to the warehouse's dynamically-sized array by
		finding the first free (nullptr) slot
	*/

	for (int i = 0; i < warehouseSize; i++)
		if (warehouse[i] == nullptr) {
			warehouse[i] = prod;
			warehouseCount++;
			break;
		}
}

void Inventory::removeByBarcode(int barcode) {
	/*
		Removes a product from the warehouse by its barcode.
	*/

	// Search the shelf
	for (int i = 0; i < 50; i++) {
		if (shelf[i] != nullptr && shelf[i]->getBarcode() == barcode) {
			// Frees the memory of the removed product
			delete shelf[i];

			// the slot is simply set to nullptr so future additions can reuse it
			shelf[i] = nullptr;

			slotsCount--;
			return;
		}
	}

	// Search the warehouse
	for (int i = 0; i < warehouseSize; i++) {
		if (warehouse[i] != nullptr && warehouse[i]->getBarcode() == barcode) {
			// Frees the memory of the removed product
			delete warehouse[i]; 

			// the slot is simply set to nullptr so future additions can reuse it
			warehouse[i] = nullptr; 

			warehouseCount--;
			return;
		}
	}
}

Product* Inventory::findByBarcode(int barcode) const {
	// Search the shelf
	for (int i = 0; i < 50; i++)
		if (shelf[i] != nullptr && shelf[i]->getBarcode() == barcode)
			return shelf[i];
	
	// Search the warehouse
	for (int i = 0; i < warehouseSize; i++) {
		if (warehouse[i] != nullptr && warehouse[i]->getBarcode() == barcode)
			return warehouse[i];
	}

	return nullptr;
}

bool namesMatch(const char* first, const char* last) {
	/*
		Compares two strings character by character
	*/
	int i;
	for (i = 0; first[i] != '\0' && last[i] != '\0'; i++) 
		if (first[i] != last[i])
			return false;

	// verifying both reach '\0' at the same index
	return first[i] == '\0' && last[i] == '\0';
}

Product* Inventory::findByName(char name[]) const {
	// Search the shelf
	for (int i = 0; i < 50; i++)
		if (shelf[i] != nullptr && namesMatch(shelf[i]->getName(), name))
			return shelf[i];

	// Search the warehouse
	for (int i = 0; i < warehouseSize; i++) {
		if (warehouse[i] != nullptr && namesMatch(warehouse[i]->getName(), name))
			return warehouse[i];
	}

	return nullptr;
}

void Inventory::listShelf() const {
	for (int i = 0; i < 50; i++) 
		if (shelf[i] != nullptr)
			shelf[i]->displayInfo();
}

double Inventory::sellableStockValue() const {
	/*
		Sums the value (price * quantity) of every product ththe has not
		expired, across both the shelf and the warehouse
	*/

	double total = 0;
	
	// Products in shelf
	for (int i = 0; i < 50; i++)
		if (shelf[i] != nullptr && shelf[i]->getStock() > 0 && !shelf[i]->hasExpired())
			total += shelf[i]->totalStockValue();

	// Products in warehouse
	for (int i = 0; i < warehouseSize; i++)
		if (warehouse[i] != nullptr && !warehouse[i]->hasExpired())
			total += warehouse[i]->totalStockValue();

	return total;
}

void Inventory::addToShelf(Product* prod) {
	/*
		Add product to shelf
	*/
	if (slotsCount < 50) {
		for (int i = 0; i < 50; i++) {
			if (shelf[i] == nullptr) {
				shelf[i] = prod;
				slotsCount++;

				break;
			}
		}
	}
}

// Destructor
Inventory::~Inventory() {
	// Delete Products in shelf
	for (int i = 0; i < 50; i++)
		if (shelf[i] != nullptr)
			delete shelf[i];

	// Delete Products in Warehouse
	for (int i = 0; i < warehouseSize; i++)
		if (warehouse[i] != nullptr)
			delete warehouse[i];

	// Delete warehouse 
	delete[] warehouse;

	cout << "Inventory destroyed" << endl;
}