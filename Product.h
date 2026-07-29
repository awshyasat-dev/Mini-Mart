// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
private:
	const int barcode;
	char name[100];
	double price;
	int inStock;
	char* description;
	static int productCounter;
public:
	//Constructors

	Product(int _barcode);
	Product(int _barcode, const char* _name, double _price, int _inStock, const char* _description);
	Product(const Product& other);

	//Destructor

	virtual ~Product();

	//Setters

	//must return Product to allow chained setters
	Product& setName(const char* newName);
	Product& setPrice(double newPrice);
	Product& setStock(int newStock);

	// Getters

	int getBarcode() const;
	double getPrice() const;
	int getStock() const;

	//Member Functions

	//units = 1 to acheive -> addStock() with no para adds 1
	void addStock(int units = 1);
	bool isSameItem(const Product& other) const;
	double totalStockValue() const;
	virtual void displayInfo() const;
	static int getProductCounter();
};
#endif 
