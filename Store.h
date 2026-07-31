#ifndef STORE_H
#define STORE_H

#include "Inventory.h"
#include "Supplier.h"

class Store
{
	private:
		// Data Members
		char* name;
		char* address;
		Inventory storeInventory;
		Supplier* storeSupplier;

	public:
		// Constructor
		Store(char* n, char* a, int sizeOfInventory, Supplier* sup);

		// Getters
		const char* getName() const;

		const char* getAddress() const;

		Inventory* getStoreInventory();

		Supplier* getStoreSupplier();

		// Functions and Methods
		void openStore() const;

		void closeStore() const;

		// Destructor
		~Store();
};

#endif