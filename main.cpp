#include <iostream>
#include <string>

using namespace std;

void PrintNumberTooBig() {
    cout << "Your input is invalid! Please reread the instructions and try another value" << endl;
}

int main() {
    string givenString = "";

    bool continueLooping = true;
    //int maxValueIndex = 0;
    unsigned long length = 0;

    cout << "Welcome to the roman numeral converter!" << endl <<
            "This converter converts integers to roman numerals and roman numerals to integer numbers. " << endl <<
            "To use this calculator, type either a decimal integer or a roman numeral (alphabet characters), between the values of 1 and 3999 (MMMCMXIX), and the program will convert it to the other form for you! " << endl <<
            "Simply enter '0' to quit. Happy converting!" << endl;

    while (continueLooping) { // this loop will ask for and compute user input until the user types 0
        cout << "-> "; // cursor

        cin >> givenString;
        length = givenString.length(); //set length to the length of the numeral, for easier coding

         bool errorThrown = false;
         if (givenString == "0") { //if the user wants to quit, quit! Don't do the rest.
            continueLooping = false;
            cout << "Goodbye!" << endl;
        }
        else if (givenString < "A") { // if the string is just decimal numbers, go with this path. comparing against "A" will result in false for any strings with anything higher than a decimal number, basically, but we'll do more checking inside the string itself.
            int errorCheckInteger = givenString.at(0)-'0'; // This is the additional checking.
            if (errorCheckInteger < 0 || errorCheckInteger > 9 || length > 4 || (length == 4 && (errorCheckInteger >= 4))) {
                errorThrown = true;
                PrintNumberTooBig();
            }
            string romanNumeral = "";
            int reverseInc = 0; // basically this allows me to have a loop that includes an incrementing variable and a decrementing variable at the same time. I could mitigate this by reversing the string, I think, to make decimal places line up with string index placement, but this is faster for me to write in the time given, probably less code too.
            for (int i = length-1; i >= 0; i--) {
                 if (!errorThrown && isdigit(givenString.at(i))) {
                     string temp = "";
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
                                             break;
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
                                         break;
                                 }
                                 break;
                         case '0':
                             break;
                         default:
                            PrintNumberTooBig();
                            break;
                         }
                     romanNumeral = temp + romanNumeral; // appends the temp string onto the front of the current number
                 }
                 else {
                     errorThrown = true;
                     i = -1; // this cancels the for() loop, ending the loop
                 }
                 reverseInc++;
            }
            cout << romanNumeral << endl;
        }
        else {
            int romanInt = 0; // this is ultimately the value that will be returned on this branch

            // code beginning now is in charge of converting the string to an array
            int stringArray[length]; //declares the array that will be used more than the string
            for (int i = 0; i < length; i++) {
                switch (toupper(givenString.at(i))) { // the toupper() function makes the program work even in lowercase
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
                        PrintNumberTooBig(); // if any other string is given, don't return a happy value
                        i = length + 1;
                        errorThrown = true;
                        break;
                }
            }
            //this code handles converting the array of values into an int.
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
                if (romanInt < 4000) {
                    cout << romanInt << endl;
                }
                else {
                    PrintNumberTooBig();
                }
            }
        }
    }
    return 0;
}