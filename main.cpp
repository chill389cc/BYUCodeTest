#include <iostream>
#include <string>

using namespace std;

/*
 * FIXME - make a function that converts the string of alphanumeric characters to uppercase, in case of a lowercase inclusion
 */


int main() {
    string givenString = "";

    bool continueLooping = true;
    //int maxValueIndex = 0;
    int length = 0;

    cout << "Welcome to the roman numeral calculator! To use this calculator, type either a decimal integer or a roman numeral

    while (continueLooping) {
        cout << endl << "Please input your roman numeral in alphabetic capitals, no spaces. Only values up to 3999 (MMMCMXCIX) are supported. If you want to quit, enter \'0\'."
                << endl << "Your Roman Numeral: " << endl;

        cin >> givenString;
        length = givenString.length(); //set length to the length of the numeral, for easier coding
         //declares the array that will be used more than the string

         bool errorThrown = false;
         if (givenString == "0") { //if the user wants to quit, quit! Don't do the rest.
            continueLooping = false;
            cout << "was zero, time to quit!" << endl;
        }
        else if (givenString < "A") { // if the string is just decimal numbers, go with this path. comparing against "A" will result in false for any strings with anything higher than a decimal number, basically, but we'll do more checking inside the string itself.
            /*int givenInt
            for (int i = length-1; i >= 0; i--) {
                if (isdigit(givenString.at(i))) {

                }
            }*/
            "3999";
            string romanNumeral = "";
            int reverseInc = 0; // basically this allows me to have a loop that includes an incrementing variable and a decrementing variable at the same time. I could mitigate this by reversing the string, I think, to make decimal places line up with string index placement, but this is faster for me to write in the time given, probably less code too.
            for (int i = length-1; i >= 0; i--) {
                if (isdigit(givenString.at(i))) {
                    string temp = "";
                    //cout << "Index: " << i << " givenString.at(i) : " << givenString.at(i) << " roman Numeral thus far: " << romanNumeral << endl; //This is a debugging line FIXME remove this line
                    switch (givenString.at(i)) {
                        case '9':
                            switch (reverseInc) {
                                case 0:
                                    temp = "IX";
                                    break;
                                case 1:
                                    temp = "XC";
                                    break;
                                case 2:
                                    temp = "CM";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                            }
                            break;
                        case '8':
                            switch (reverseInc) {
                                case 0:
                                    temp = "VIII";
                                    break;
                                case 1:
                                    temp = "LXXX";
                                    break;
                                case 2:
                                    temp = "DCCC";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '7':
                            switch (reverseInc) {
                                case 0:
                                    temp = "VII";
                                    break;
                                case 1:
                                    temp = "LXX";
                                    break;
                                case 2:
                                    temp = "DCC";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '6':
                            switch (reverseInc) {
                                case 0:
                                    temp = "VI";
                                    break;
                                case 1:
                                    temp = "LX";
                                    break;
                                case 2:
                                    temp = "DC";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '5':
                            switch (reverseInc) {
                                case 0:
                                    temp = "V";
                                    break;
                                case 1:
                                    temp = "L";
                                    break;
                                case 2:
                                    temp = "V";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '4':
                            switch (reverseInc) {
                                case 0:
                                    temp = "IV";
                                    break;
                                case 1:
                                    temp = "XL";
                                    break;
                                case 2:
                                    temp = "CD";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '3':
                            switch (reverseInc) {
                                case 0:
                                    temp = "III";
                                    break;
                                case 1:
                                    temp = "XXX";
                                    break;
                                case 2:
                                    temp = "CCC";
                                    break;
                                case 3:
                                    temp = "MMM";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '2':
                            switch (reverseInc) {
                                case 0:
                                    temp = "II";
                                    break;
                                case 1:
                                    temp = "XX";
                                    break;
                                case 2:
                                    temp = "CC";
                                    break;
                                case 3:
                                    temp = "MM";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '1':
                            switch (reverseInc) {
                                case 0:
                                    temp = "I";
                                    break;
                                case 1:
                                    temp = "X";
                                    break;
                                case 2:
                                    temp = "C";
                                    break;
                                case 3:
                                    temp = "M";
                                    break;
                                default:
                                    cout << "invalid number" << endl;
                                    exit(0);
                                    break;
                            }
                            break;
                        case '0':
                            break;
                        default:
                            cout << "something must have gone wrong here" << endl;
                            exit(0);
                    }
                    romanNumeral = temp + romanNumeral;
                }
                else {
                    errorThrown = true;
                    i = -1;
                }
                reverseInc++;
            }
            cout << "Roman Numeral as a string: " << romanNumeral << endl;
        }
        else {
            //cout << "checkpoint 2" << endl;
            int romanInt = 0;
            //Convert the string to an array
            int stringArray[length];
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
                        errorThrown = true;
                        break;
                }
                /*if (stringArray[i] > stringArray[maxValueIndex]) { // sets the position of the greatest value
                    maxValueIndex = i;
                }*/
            }
            if (!errorThrown) { // if the string is valid, then we're happy
                for (int i = 0; i < length; i++) {
                    if (i == length - 1) { // if we're at the last digit, don't do the same calculation
                        romanInt += stringArray[i];
                    }
                    else if (stringArray[i] < stringArray[i+1] ) {
                        romanInt += stringArray[i+1] - stringArray[i];
                        i++;
                    }
                    else {
                        romanInt+=stringArray[i];
                    }
                }
                cout << "Roman Integer: " << romanInt << endl;
            }


        }



    }
    return 0;
}