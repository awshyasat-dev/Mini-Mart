// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#ifndef DAILYREPORT_H
#define DAILYREPORT_H

#include "Inventory.h"
#include "Order.h"

class DailyReport {
    public:
        // Constructor
        DailyReport();

        // Functions and Methods
        void generate(Inventory& inventory, Order** orders, int orderCount) const;

        // Destructor
        ~DailyReport();
};

#endif