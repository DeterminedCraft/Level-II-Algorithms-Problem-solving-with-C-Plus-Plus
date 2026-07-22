
#include <iostream>
using namespace std;

/*
 Problem #4:
 Write a program to print all perfect numbers from 1 to N

 Input:
 500

 Output:
 6
 28
 496

*/



int ReadIntegerNumber(const string& message)   // pass by const. ref.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}


bool ValidatePositiveNumber(const int& number)   // pass by const ref. since 'number' is ONLY used for comparison against the range.
{
    return (number > 0);
}



int ReadPositiveNumber(const string& message)   // pass by const ref.
{
    int number;  // what's returned.
    bool validation;

    do
    {
        number = ReadIntegerNumber(message);  // 'number' is IMMEIDATELY validated against the range, in the while condition.

        validation = ValidatePositiveNumber(number);
        if (!validation)
        {
            cout << "Error. Only positive number allowed. ";
        }


    } while (!validation);   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.


    return number; 
}


bool IsNumberPerfect(int number)
{
    int sum = 0;

    for (int i = number - 1; i >= 1; i--)
    {
        if (number % i == 0)
        {
            sum += i;     // sum = sum + i;
        }
    }
    return (sum == number);
}


void PrintAllPerfectNumbersFrom1ToN(const int& N)    // pass by constant reference.
{
    for (int i = 1; i <= N; i++)
    {
        if (IsNumberPerfect(i))
        {
            cout << i << endl;
        }
    }
}


int main()
{
    
    PrintAllPerfectNumbersFrom1ToN(ReadPositiveNumber("Enter a positive number: "));  // No range included as its value is NOT intrinsic.

    return 0;
}

