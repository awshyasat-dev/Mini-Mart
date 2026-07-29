#ifndef SHELFLOCATION_H
#define SHELFLOCATION_H

class ShelfLocation
{
	private:
		char aisleLetter;
		int slotNumber;

	public:
		ShelfLocation() = default;

		void displayLocation() const;
};
#endif