
#include <iostream>
#include <cmath>
using namespace std;

/*
 Problem #49

 Write a program to print ceil of numbers, don't use the built-in ceil function.

 Input: 10.7
 My MyCeil Result: 11
 C++ Ceil Result: 11


 Input: -10.7
 My MyCeil Result: -10
 C++ Ceil Result: -10

 Input: -13
 My MyCeil Result: -13
 C++ Ceil Result: -13

 Input: 13
 My MyCeil Result:13
 C++ Ceil Result: 13

 Note: The Ceiling Function returns a result that is bigger or equal to the original number.

*/





float ReadNumber(const string& message)   // pass by const. ref.  // Again- I choose not to have any user-input range validation.
{
    float number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}



int ExtractInteger(float number)   // pass by value.
{
    return (int)number; 
}



float ExtractDecimal(float number, int IntegerPart)   // pass by value
{
    return number - IntegerPart;
}



int CustomCeiling(float number)   // pass by value
{
    int IntegerPart = ExtractInteger(number);
    float DecimalPart = ExtractDecimal(number, IntegerPart);

    if (DecimalPart == 0)
    {
        return IntegerPart;       // or:  return (int)number;    
    }
    else if (number > 0) // if program reaches here, then the decimal part isn't 0.
    {
        return IntegerPart + 1;     //  or  return ++IntegerPart         // WARNING:  return IntegerPart++ is FATAL ( Integer part is returned first. Then, IntegerPart is increased by 1).
    }
    else if (number < 0)
    {
        return IntegerPart;
    }

}

/* Another Equally valid Approach:
   
    if (abs(DecimalPart) > 0)  // if the decimal part is something other than 0. The abs() is necessary as the decimal part could be negative ( ex:  -11.3)
    {
        if (number > 0)
        {
            return IntegerPart + 1;
        }
        else if (number < 0)
        {
            return IntegerPart;
        }
    }

    return IntegerPart;   // or   return (int)number

*/




int main()
{
    float number = ReadNumber("Enter a number: ");  // I choose not to have any user-input range validation.

    int CeilingValue = CustomCeiling(number);
    cout << "My MyCeil Result: " << CeilingValue << endl;

    cout << "C++ Ceil Result: " << ceil(number) << endl << endl;





    return 0;
}


