
#include <iostream>
#include <string>
using namespace std;

/*
    Problem #10

    Problem:
    Write a program to read a number and print it in order from left to right.

    Input:
    1234

    Output:
    1
    2
    3
    4

*/


int ReadIntegerNumber(const string& message)
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidatePositiveNumber(const int& number)
{
    return (number > 0);
}


int ReadPositiveNumber(const string& message)
{
    int number;  // what's returned

    number = ReadIntegerNumber(message);

    while (!ValidatePositiveNumber(number))
    {
        cout << "Error. Only positive numbers allowed. ";
        number = ReadIntegerNumber(message);
    }

    return number;
}



int ReverseNumber(int number)   // pass by value.
{
    int ReversedNumber = 0;                                             

    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;

        ReversedNumber = (ReversedNumber * 10) + remainder;     
    }

    return ReversedNumber;
}


void PrintDigitsInOrderFromLeftToRight(int ReversedNumber)
{
    int remainder = 0;
    while (ReversedNumber > 0)
    {
       remainder = ReversedNumber % 10;
       ReversedNumber = ReversedNumber / 10; 

       cout << remainder << endl;
    }
}

int main()
{
    
    PrintDigitsInOrderFromLeftToRight(ReverseNumber(ReadPositiveNumber("Enter a number: ")));   // Range is NOT included as its value is NOT intrinsic.

    return 0;
}



















/////////////////////// First-attempt UNOPTIMIZED SOLUTION://///////////////////////////////////////////////////////////////////////////////////////
/////////////////////// First-attempt UNOPTIMIZED SOLUTION://///////////////////////////////////////////////////////////////////////////////////////
//int ReadIntegerNumber(const string& message)
//{
//    int number;  // what's returned.
//
//    cout << message;
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//
//bool ValidatePositiveNumber(const int& number)
//{
//    return (number > 0);
//}
//
//
//int ReadPositiveNumber(const string& message)
//{
//    int number;  // what's returned
//
//    number = ReadIntegerNumber(message);
//
//    while (!ValidatePositiveNumber(number))
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
//void PrintDigitsInOrderFromLeftToRight(const int& number)   // pass by constant reference.
//{
//     string value = to_string(number); 
//     for (int i = 0; i < value.length() ; i++)
//     {
//         cout << value[i] << endl;
//     }
//}
//
//
//int main()
//{
//    
//    PrintDigitsInOrderFromLeftToRight(ReadPositiveNumber("Enter a number: "));   // Range is NOT included as its value is NOT intrinsic.
//
//    return 0;
//}


