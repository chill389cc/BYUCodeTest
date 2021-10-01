#include <iostream>
#include <string>

using namespace std;


int main() {
    string givenString = "";

    bool continueLooping = true;
    int romanInt = 0;
    int maxValueIndex = 0;
    int length = 0;

    while (continueLooping) {
        cout << "Please input your roman numeral in alphabetic capitals, no spaces. Only values up to 3999 (MMMCMXCIX) are supported. If you want to quit, enter \'0\'."
                << endl << "Your Roman Numeral: " << endl;

        cin >> givenString;
        length = givenString.length(); //set length to the length of the numeral, for easier coding
        int stringArray[length]; //declares the array that will be used more than the string

        if (givenString == "0") { //if the user wants to quit, quit! Don't do the rest.
            continueLooping = false;
            cout << "was zero, time to quit!" << endl;
        }
        else {
            //cout << "checkpoint 2" << endl;

            //Convert the string to an array
            for (int i = 0; i < length; i++) {
                switch (givenString.at(i)) {
                    case 'I':
                        stringArray[i] = 1;
                        break;
                    case 'V':
                        stringArray[i] = 5;
                        break;
                    case 'X':
                        stringArray[i] = 10;
                        break;
                    case 'L':
                        stringArray[i] = 50;
                        break;
                    case 'C':
                        stringArray[i] = 100;
                        break;
                    case 'D':
                        stringArray[i] = 500;
                        break;
                    case 'M':
                        stringArray[i] = 1000;
                        break;
                    default:
                        cout << "Please only use valid characters!" << endl << endl; // if any other string is given, don't return a happy value
                        i = length + 1;
                        break;
                }
                if (stringArray[i] > stringArray[maxValueIndex]) { // sets the position of the greatest value
                    maxValueIndex = i;
                }
            }
            cout << maxValueIndex << endl;
        }



    }
    return 0;
}