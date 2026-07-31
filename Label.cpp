
// 20250410 Omar Mustafa Khalaf
// 20250226 Basel Ahmed Alquoqa
// 20250356 Aws Hamdan Al Hiyasat

#include "Label.h"
#include <iostream>
using namespace std;


//Constructors
Label::Label() {
    labelText = new char[1];
    labelText[0] = '\0';
    cout << "A Label has been created\n" << endl;
}

Label::Label(const char* _label) {

    int countChar = 0;
    for (int i = 0; _label[i] != '\0'; i++) {
        countChar++;
    }

    labelText = new char[countChar + 1];

    for (int i = 0; i <= countChar; i++) {
        labelText[i] = _label[i];
    }
    cout << "A Label has been created\n" << endl;
}
//Destructors
Label::~Label() {
    delete[] labelText;
    cout << "A Label has been removed\n" << endl;

}

//Getters
const char* Label::getLabelText() const {
    return labelText;
}

// Methods
void Label::printLabel() const {
    cout << "\n+--------------------------------+" << endl;
    cout << "| LABEL: " << labelText << endl;
    cout << "+--------------------------------+\n" << endl;
}
