// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "ShelfLocation.h"
#include <iostream>
using namespace std;

void ShelfLocation::displayLocation() const {
	cout << "Aisle: " << aisleLetter << ", Slot: " << slotNumber << endl;
}