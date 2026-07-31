// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat


#ifndef LABEL_H
#define LABEL_H

class Label
{
private:
	char* labelText;
public:
	//Constructors
	Label();
	Label(const char* _label);

	//Destructors
	virtual ~Label();

	//Getters
	const char* getLabelText() const;

	//Methods
	void printLabel() const;

};

#endif // LABEL_H