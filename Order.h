

//Basel Alquoqa 20250226
//Aws Hyasat 20250356
//Omar Khalaf 20250410
#ifndef order_h
#define order_h

#include "Product.h"
#include <string>
class Order {
private:
	//data members
	const int Order_number;
	char* Customer_name;
	Product* product;
	int ItemCount;
	int* quantities;
	int capacity;

	static int Counter;
public:
	//default-parametrized constructor
	Order(const char* name = "");

	//copy constructor
	Order(const Order& other);
	//destructor
	~Order();

	//member functions
	void addItem(const Product& p, int quantity);
	void mergeWith(const Order& other);
	void complete(Inventory& inventory);
	double total();
	void displayOrder();

	//getter
	int getOrderNumber() const;

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