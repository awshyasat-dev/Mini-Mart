

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
};

#endif 