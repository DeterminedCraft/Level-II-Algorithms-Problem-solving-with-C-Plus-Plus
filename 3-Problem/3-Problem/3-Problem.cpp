
#include <iostream>
using namespace std;

/*
 Problem #3:

 Write a program to check if the number is Perfect or not?
 Note: Perfect Number = Sum(all divisors)

 Examples:
 28 = 1 + 2 + 4 + 7 + 14
 6  = 1 + 2 + 3

 Input:
 28
 12

 Output:
 28 is perfect.
 12 is not perfect.

*/


int ReadIntegerNumber(const string& message)    // pass by const. ref.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}

bool ValidatePositiveNumber(const int& number)        // pass by const ref. since 'number' is ONLY used for comparison against the range.
{
    return (number > 0);
}


int ReadPositiveNumber(const string& message)  // pass by const. ref.
{
    int number;  // what's returned.

    number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    while (!ValidatePositiveNumber(number))   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
    {
        cout << "Error. Only positive numbers allowed. ";
        number = ReadIntegerNumber(message);
    }

    return number;
}




bool IsNumberPerfect(int number)   // pass by value
{
    int sum = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;         // sum = sum + i;
        }
    }

    return (sum == number);

    /* redundant approach:
    
        if (sum == number)
        {
         return true;  
        }

        return false;
    */
}



void PrintNumberPerfectOrNot(const int& number)   // pass by const ref.
{
    if (IsNumberPerfect(number))
    {
        cout << number << " is perfect. \n";
    }
    else
    {
        cout << number << " is NOT perfect. \n";
    }

}




int main()
{

    PrintNumberPerfectOrNot(ReadPositiveNumber("Enter a positive number: "));   // No range is included as the value is NOT intrinsic. 
    // the printing procedure is written so that,
    // it contains the function IsNumberPerfect() which is the argument of an if statement.

    return 0;
}















//// Unoptimized first-attempt solution:
//
//int ReadIntegerNumber(const string& message)    // pass by const. ref.
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
//bool ValidatePositiveNumber(const int& number)        // pass by const ref. since 'number' is ONLY used for comparison against the range.
//{
//    return (number > 0);
//}
//
//
//int ReadPositiveNumber(const string& message)  // pass by const. ref.
//{
//    int number;  // what's returned.
//
//    number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition.
//
//    while (!ValidatePositiveNumber(number))   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//    {
//        cout << "Error. Only positive numbers allowed. ";
//        number = ReadIntegerNumber(message);
//    }
//
//    return number;
//}
//
//
//
//
//bool IsNumberPerfect(int number)   // pass by value
//{
//    int sum = 0;
//
//    for (int i = 1; i < number; i++)
//    {
//        if (number % i == 0)
//        {
//            sum = sum + i;
//        }
//    }
//
//    if (sum == number)
//    {
//        return true;  
//    }
//
//    return false;
//
//}
//
//
//
//void PrintNumberPerfectOrNot(const int& number)   // pass by const ref.
//{
//    if (IsNumberPerfect(number))
//    {
//        cout << number << " is perfect. \n";
//    }
//    else
//    {
//        cout << number << " is NOT perfect. \n";
//    }
//
//}
//
//
//
//
//int main()
//{
//
//    PrintNumberPerfectOrNot(ReadPositiveNumber("Enter a positive number: "));   // No range is included as the value is NOT intrinsic. 
//
//    // the printing procedure is written so that, it contains the function IsNumberPerfect() which is the argument of an if statement.
//
//    return 0;
//}


