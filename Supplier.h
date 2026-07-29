// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#ifndef SUPPLIER_H
#define SUPPLIER_H

class Supplier
{
	private:
		char* companyName = nullptr;
		char* phoneNumber = nullptr;
		char* address = nullptr;
		int* barcodes = nullptr;
		int barcodeCount;

	public:
		// Constructor
		Supplier(const char* name = "", const char* phone = "", const char* _address = "");

		// Setters
		void setCompanyName(const char* name);

		void setPhoneNumber(const char* phone);

		void setAddress(const char* _address);

		// Getters
		const char* getCompanyName() const;

		const char* getPhoneNumber() const;

		const char* getAddress() const;

		const int* getBarcodes() const;

		// Functions and Methods
		void addSuppliedProduct(int barcode);

		void displayInfo() const;

		// Destructor
		~Supplier();
};
#endif