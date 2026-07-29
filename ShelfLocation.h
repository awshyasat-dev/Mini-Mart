// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

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