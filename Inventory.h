// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "Product.h"
using namespace std;

/*
	- This class represents the store's stock: a fixed-size shelf (shop floor)
	- and a dynamically-sized warehouse (back storage)
*/

class Inventory
{
	private:
		// Data memebers
		Product* shelf[50];
		Product** warehouse;
		int slotsCount,
			warehouseSize,
			warehouseCount;

	public:
		// Constructor
		Inventory(int size);

		// Getters
		int getSlotsCount() const;

		int getWarehouseCount() const;

		// Functions and Methods
		void addProduct(Product* prod);

		void removeByBarcode(int barcode);

		Product* findByBarcode(int barcode) const;

		Product* findByName(char name[]) const;

		void listShelf() const;

		double sellableStockValue() const;

		void addToShelf(Product* prod);

		// Destructor
		~Inventory();

		// Friend class
		/*
			- DailyReport is granted friend access to read private order data (items, quantities)
			  because a daily report must compare orders against inventory as a whole

			- This is safe because access is limited to exactly one named class (DailyReport)
			  unlike making the members public which would expose them to the entire program.
			  DailyReport only READS this data to generate the report, it never modifies
			  Order's private members, so Order's invariants remain fully protected
		*/
		friend class DailyReport;
};

#endif
