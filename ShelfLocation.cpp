#include "ShelfLocation.h"
#include <iostream>
using namespace std;

void ShelfLocation::displayLocation() const {
	cout << "Aisle: " << aisleLetter << ", Slot: " << slotNumber << endl;
}