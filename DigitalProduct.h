// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat


#ifndef DIGITALPRODUCT_H
#define DIGITALPRODUCT_H
#include "Product.h"

class DigitalProduct : public Product
{
private:
    double DownloadSize;
    char* licenceKey;
public:
    // Constructors
    DigitalProduct(int _barcode);
    DigitalProduct(int _barcode, const char* _name, double _price, int _inStock, const char* _description, double _size, const char* _key);

    // Destructor
    ~DigitalProduct();

    // Methods
    double deliveryCharge() const;
    void displayInfo() const;
};


#endif // DIGITALPRODUCT_H