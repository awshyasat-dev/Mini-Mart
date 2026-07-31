// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#ifndef order_h
#define order_h

#include "Product.h"
#include "Inventory.h"

class Order {
private:
    const int Order_number;
    char* Customer_name;
    Product** product;
    int ItemCount;
    int* quantities;
    int capacity;
    static int Counter;

public:
    Order(const char* name = "");
    Order(const Order& other);
    ~Order();

    void addItem(Product* p, int quantity);
    void mergeWith(const Order& other);
    void complete(Inventory& inventory);
    double total();
    void displayOrder();
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