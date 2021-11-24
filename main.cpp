#include "std_lib_facilities.h"
using namespace std;

// this function will find the integer value
// of the specified key
// whether it is in number or word form
// the main function checks if the key is in neither vector before this function is called
int findIndex(vector<string> text, vector<string> num, string key) {
    int index;
    // the key is in number form as it could not be found in the text vector
    if (find(text.begin(), text.end(), key) == text.end()) {
        // traverse the numbers vector to find the equivalent value
        for (int i=0; i<num.size(); ++i) {
            if (num[i] == key) {
                index = i;
                break;
            }
        }

    }

    // the key is in text form
    else {
        for (int i=0; i<text.size(); ++i) {
            // traverse the text vector to find the equivalent value
            if (num[i] == key) {
                index = i;
                break;
            }
        }
    }
    // return the index which will be used in the calculation
    // the index is equal to the actual value due to the order
    // of the elements in the vectors
    return index;
}

int main() {

    string a, b;
    char operation;

    // declare and initialize vectors containing all possible operator values
    vector<string> text;
    vector<string> num;

    text.push_back("zero");
    text.push_back("one");
    text.push_back("two");
    text.push_back("three");
    text.push_back("four");
    text.push_back("five");
    text.push_back("six");
    text.push_back("seven");
    text.push_back("eight");
    text.push_back("nine");

    num.push_back("0");
    num.push_back("1");
    num.push_back("2");
    num.push_back("3");
    num.push_back("4");
    num.push_back("5");
    num.push_back("6");
    num.push_back("7");
    num.push_back("8");
    num.push_back("9");

    // get user input and assign it to variables
    cout << "------Simple Calculator------\n";
    cout << "Only single digit numbers are accepted.\n";
    cout << "Enter two operands followed by an operator :  ";
    cin >> a >> b >> operation;

    // see if a and b are in either vectors
    // if one is not found, the calculator cannot continue
    if (find(text.begin(), text.end(), a) == text.end() && find(num.begin(), num.end(), a) == num.end()) {
            cout << "The operand " << a << " is not valid.";
            return 0;
    }
    else if (find(text.begin(), text.end(), b) == text.end() && find(num.begin(), num.end(), b) == num.end()) {
            cout << "The operand " << b << " is not valid.";
            return 0;
    }

    // add
    if (operation == '+') {
        int index1, index2;

        index1 = findIndex(text, num, a);
        index2 = findIndex(text, num, b);
        cout << index1+index2;
    }


    // subtract
    else if (operation == '-') {
        int index1, index2;

        index1 = findIndex(text, num, a);
        index2 = findIndex(text, num, b);
        cout << index1-index2;
    }

    // multiply
    else if (operation == '*') {
        int index1, index2;

        index1 = findIndex(text, num, a);
        index2 = findIndex(text, num, b);
        cout << index1*index2;
    }


    // divide
    else if (operation == '/') {
        int index1, index2;

        index1 = findIndex(text, num, a);
        index2 = findIndex(text, num, b);
        if (index2 == 0)
            cout << "You cannot divide by 0.";
        else
            cout << index1/index2;
    }


    else
        cout << "The operation entered is not valid.";


    return 0;

}
