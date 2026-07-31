// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#ifndef BOXEDPRODUCT_H
#define BOXEDPRODUCT_H
#include "ShelfLocation.h"
#include "Product.h"
class BoxedProduct : public Product {

private:
	double weight;
	//Composition from ShelfLocation Class
	ShelfLocation location;
public:
	//Constructors
	BoxedProduct(int _barcode);
	BoxedProduct(int _barcode, const char* _name, double _price, int _inStock, const char* _description, double _weight, char _aisle, int _slot);

	//Destructor
	~BoxedProduct();

	// Methods
	double deliveryCharge() const;
	void displayInfo() const;
};

#endif // BOXEDPRODUCT_H
