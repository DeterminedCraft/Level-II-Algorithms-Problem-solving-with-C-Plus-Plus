

#include <iostream>
#include <string>
using namespace std;

/*
 Problem #8:
 Write a program read a number and a digit, then print digit frequency in that number

 Input:
 1223222
 2

 Output:
 Digit 2 Frequency is 5 Time(s).


*/



int ReadIntegerNumber(const string& message)    // pass by constant reference.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}

bool ValidatePositiveNumberInRange(const int& value, int MinValue, int MaxValue)   // pass by const ref. since 'number' is ONLY used for comparison against the range.
{
    return (MinValue <= value && value <= MaxValue);
}

int ReadNumberInRange(const string& message, const string &ErrorMessage, int MinValue, int MaxValue)    // pass by constant reference.   // Ranges ALWAYS passed by value.
{
    bool validate;
    int value;  // what's returned.

    do
    {
        value = ReadIntegerNumber(message);  // 'number' is IMMEDIATELY validated against the range, in the while condition.

        validate = ValidatePositiveNumberInRange(value, MinValue, MaxValue);

        if (!validate)
        {
            cout << ErrorMessage << "between " << MinValue << " & " << MaxValue << endl;
        }

    } while (!validate);  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return value;

    /* Note: The above block of code is to be sequentially composed line by line, and at the end
             implement the functions for:   ReadIntegerNumber()   &  ValidatePositiveNumber()
    */
}




int CalculateDigitFrequency(int number, short digit)    // pass by value
{
    int count = 0;  // added at the end when it was needed.
    int remainder = 0;


    if (number == 0 && digit == 0)   // edge case that was added at the VERY END after testing our program with number = 0  & digit = 0.
    {
        return 1;
    }


    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;

        if (remainder == digit)
        {
            count++;
        }
    }
       // Adding this block here, instead of above, results in a BUG:
            // because the above while loop stops when number = 0  so that:     while (number > 0) --->   while (0 > 0)  -----> while(false) -----> Exit the while loop.

               // so that if user enters:  any number (example:  550300, followed by digit = 0  --> the output will ALWAYS be:    Digit 0 frequency is 0 time(s).
  /*  if (number == 0 && digit == 0)   
    {
        return 1;
    } */ 

    return count;
}

void PrintDigitFrequency(const int& number, const short& digit)   // pass by constant reference.
{
    cout << "Digit " << digit << " frequency is " << CalculateDigitFrequency(number, digit) << " time(s). \n";
}



int main()
{
    int MinNum = 0;
    int MaxNum = 100000000;

    int MinDigit = 0;
    int MaxDigit = 9;

    string NumberErrorMessage = "Error - Only positive value allowed ";
    string DigitErrorMessage = "Error - Only a digit is allowed ";

    int number = ReadNumberInRange("Enter a number: ", NumberErrorMessage, MinNum, MaxNum);
    /*       |
             |--> // to be typed at the end, after finishing typing the "return" keyboard.  */

    int digit = ReadNumberInRange("Enter a digit: ", DigitErrorMessage, MinDigit, MaxDigit);
    /*       |
             |--> // to be typed at the end, after finishing typing the "return" keyboard.  */


    PrintDigitFrequency(number, digit);// Range is NOT included as its value is NOT intrinsic.

    return 0;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////First attempt unoptimzed solution:
////////////////////First attempt unoptimzed solution:
////////////////////First attempt unoptimzed solution:
//
//int ReadIntegerNumber(const string& message)    // pass by constant reference.
//{
//    int number;  // what's returned.
//
//    cout << message;
//    cin >> number;
//    cout << "\n";
//
//    return number;
//}
//
//bool ValidatePositiveNumber(const int& number)   // pass by const ref. since 'number' is ONLY used for comparison against the range.
//{
//    return (number > 0);
//}
//
//int ReadPositiveNumber(const string& message)    // pass by constant reference.
//{
//    bool validate; 
//    int number;  // what's returned.
//    
//    do
//    {
//        number = ReadIntegerNumber(message);  // 'number' is IMMEDIATELY validated against the range, in the while condition.
//
//        validate = ValidatePositiveNumber(number);
//
//        if (!validate)
//        {
//            cout << "Error - Only positive value allowed. ";
//        }
//
//    } while (!validate);  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//    return number; 
//
//    /* Note: The above block of code is to be sequentially composed line by line, and at the end
//             implement the functions for:   ReadIntegerNumber()   &  ValidatePositiveNumber()
//    */
//}
//
//
//bool ValidateDigitLength(const int &number, int DigitLength)   // pass by const ref since 'number' is ONLY used for comparison gainst the range that's 'DigitLength'    // Range is ALWAYS passed by value.
//{
//    return (to_string(number).length() == DigitLength);
//}
//
//
//int ReadDigit(const string& message, int DigitLength)    // pass by const. ref.   // Range is ALWAYS passed by value.
//{   
//    bool validate;
//    int number;   // what's returned
//
//    do
//    {
//        number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition.
//
//        validate = ValidateDigitLength(number, DigitLength);
//        if (!validate)
//        {
//            cout << "Error- Only a digit is allowed. ";
//        }
//
//    } while (!validate);  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//    return number; 
//
//    /* Note: The above block of code is to be sequentially composed line by line, and at the end
//             implement the functions for:  ValidateDigitLength()    */
//}
//
//
//int CalculateDigitFrequency(int number, int digit)    // pass by value
//{
//    int count = 0;  // added at the end when it was needed.
//
//    int remainder = 0;
//    
//    while (number > 0)
//    {
//        remainder = number % 10; 
//        number = number / 10; 
//
//        if (remainder == digit)
//        {
//            count++;
//        }
//    }
//
//    return count;
//}
//
//void PrintDigitFrequency(const int& number, const int& digit)   // pass by constant reference.
//{
//    cout << "Digit " << digit << " frequency is " << CalculateDigitFrequency(number, digit) << ". \n";
//}
//
//
//
//int main()
//{
//    const int DigitLength = 1;     // must be removed as a digit is a digit (digit = length 1).
//
//    int number = ReadPositiveNumber("Enter a number: ");
///*       |
//         |--> // to be typed at the end, after finishing typing the "return" keyboard.  */
//
//    int digit = ReadDigit("Enter a digit: ", DigitLength);  // The range 'DigitLength' is includes as its value is INTRINSIC.
///*       |
//         |--> // to be typed at the end, after finishing typing the "return" keyboard.  */
//
//
//    PrintDigitFrequency(number, digit);// Range is NOT included as its value is NOT intrinsic.
//
//    return 0;
//}


