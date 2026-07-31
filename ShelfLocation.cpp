// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "ShelfLocation.h"
#include <iostream>
using namespace std;

void ShelfLocation::displayLocation() const {
	/*
	Information display
	*/
	cout << "Aisle: " << aisleLetter << ", Slot: " << slotNumber << endl;
}
void ShelfLocation::setAisle(char _aisle) {
	aisleLetter = _aisle;
}

void ShelfLocation::setSlot(int _slot) {
	slotNumber = _slot;
}