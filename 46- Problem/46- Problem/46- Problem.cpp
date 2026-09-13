
#include <iostream>
using namespace std;

/*
 Problem #46

 Write a program to print abs of numbers, don't use the built-in abs function

 Input:
 Enter a number: -10

 Output:

 My abs result: 10
 C++ abs result: 10

 

*/

float ReadNumber(const string& message)  // I decided to not have a range for user-input
{
    float number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

float CalculateAbsNumber(float number)   // pass by value.
{
    if (number < 0)
        return number * -1;
    
    else
    return number;
   
}



int main()
{
    float number = ReadNumber("Enter a number: "); 

    float AbsNumberUsingCustomFunction = CalculateAbsNumber(number);

    cout << "My abs result: " << AbsNumberUsingCustomFunction << endl << endl;

    float AbsNumber = abs(number);
    cout << "C++ abs result: " << AbsNumber << endl << endl;


    



    return 0;
}

