// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#ifndef PERISHABLEPRODUCT_H
#define PERISHABLEPRODUCT_H
#include "Product.h"

class PerishableProduct : public Product
{
private:
	double storageTemp;
	int daysLeft;
public :
	//Constructors
	PerishableProduct(int _barcode);
	PerishableProduct(int _barcode, const char* _name, double _price, int _inStock, const char* _description, double _temp, int _days);

	// Destructor
	~PerishableProduct();

	// Methods
	bool hasExpired() const;
	double deliveryCharge() const;
	void displayInfo() const;
	double totalStockValue() const;
};

#endif // PERISHABLEPRODUCT_H