
#include <iostream>
using namespace std;

/*
 Problem #6:
 Write a program to read a number and print the sum of its digits.

 Input:
 1234

 Output:
 Sum Of Digits = 10


*/


int ReadIntegerNumber(const string& message)   // pass by constant reference.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidatePositiveNumber(const int& number)   // pass by const. ref. since 'number' is ONLY used for comparison against the range.
{
    return (number > 0);
}


int ReadPositiveNumber(const string& message)   // pass by constant reference.
{
    int counter = 0;
    int number;  // what's returned.

    do
    {
        counter++;
        if (counter > 1)
        {
            cout << "Error. Only positive number allowed. ";
        }

        number = ReadIntegerNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidatePositiveNumber(number));

    return number; 
}


int  CalculateSumOfDigits(int number)   // pass by value.
{
    int sum = 0;   // routine   // ALWAYS
    int remainder = 0;

    while (number > 0)
    { 
        remainder = number % 10;
        number = number / 10;
        sum = sum + remainder;
    }

    return sum;
}


void PrintSumOfDigits(const int& number)    // pass by constant ref.
{
    cout << "Sum of digits = " << CalculateSumOfDigits(number) << endl;
}


int main()
{
    
    PrintSumOfDigits(ReadPositiveNumber("Enter a number: "));  // Range NOT included as its value is NOT intrinsic.

    return 0;
}


