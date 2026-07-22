
#include <iostream>
using namespace std;

/*
    Problem #11

    Write a program to read a number and check if it is Palindrome.

    A palindrome is a number that reads the same
    from left to right and from right to left.

    Input:

    1234
    12321

    Output:

    No, it is NOT a Palindrome number.
    Yes, it is a Palindrome number.

*/


int ReadIntegerNumber(const string& message)    // pass by constant reference.
{
    int number;   // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidatePositiveInteger(const int& number)  // pass by const. ref. as 'number' is ONLY used for comparison against the range.
{
    return (number > 0);
}

int ReadPositiveInteger(const string& message)   // pass by constant reference.
{
    bool validate;
    int number;  // what's returned.

    do
    {
        number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

        validate = ValidatePositiveInteger(number);
        if (!validate)
        {
            cout << "Error - Only positive numbers allowed. ";
        }

    } while (!validate);

    return number;

    /*   Note: The above block of code is to be sequentially composed line by line,
               & at the end, implement the functions of: ReadIntegerNumber()   &    ValidatePositiveInteger()   */
}

bool IsPalindrome(int number, int ReversedNumber)    // pass by value.
{
    return (number == ReversedNumber);
}

int ReverseNumber(int number)    // pass by value.
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


void PrintPalindromeOrNot(const int& number)    // pass by constant reference.
{
    if (IsPalindrome(number, ReverseNumber(number)))
    {
        cout << number << " is a palindrome.\n";
    }
    else
    {
        cout << number << " is NOT a palindrome.\n";
    }
}


int main()
{

    PrintPalindromeOrNot(ReadPositiveInteger("Enter a number: "));  // Range NOT included as its value is NOT intrinsic.
    // This printing procedure contains the function IsPalindrome() in an if statement.
    // This is a standard coding approach that's also conducive to the printing procedure
    // having access to the original value entered by the user, so that
    // it's accessible / can be referenced by this printing procedure.

    return 0;
}











//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////// First attempt UNOPTIMIZED solution: //////////////////////////////////////
//////////// First attempt UNOPTIMIZED solution: //////////////////////////////////////
//////////// First attempt UNOPTIMIZED solution: //////////////////////////////////////
//////////// First attempt UNOPTIMIZED solution: //////////////////////////////////////
// 
// 
//int ReadIntegerNumber(const string& message)    // pass by constant reference.
//{
//    int number;   // what's returned.
//
//    cout << message;
//    cin >> number;
//    cout << endl;
//
//    return number; 
//}
//
//bool ValidatePositiveInteger(const int& number)  // pass by const. ref. as 'number' is ONLY used for comparison against the range.
//{
//    return (number > 0);
//}
//
//int ReadPositiveInteger(const string& message)   // pass by constant reference.
//{
//    bool validate; 
//    int number;  // what's returned.
//
//    do
//    {
//        number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.
//
//        validate = ValidatePositiveInteger(number);
//        if (!validate)
//        {
//            cout << "Error - Only positive numbers allowed. ";
//        }
//
//    } while (!validate);
//
//    return number; 
//
//    /*   Note: The above block of code is to be sequentially composed line by line, 
//               & at the end, implement the functions of: ReadIntegerNumber()   &    ValidatePositiveInteger()   */
//}
//
//bool IsPalindrome(int number)    // pass by value.
//{
//    int OriginalNumber = number; 
//    int ReversedNumber = 0;
//
//    int remainder = 0;
//    while (number > 0)
//    {
//        remainder = number % 10; 
//        number = number / 10; 
//
//        ReversedNumber = (ReversedNumber * 10) + remainder;
//    }
//
//    if (ReversedNumber == OriginalNumber)   // this thinking results in a bug because the program exists the while loop when number = 0 as all decimals would've been extracted.
//    {
//        return true;
//    }
//
//    /*   
//     
//    if (ReversedNumber == number)   // this thinking results in a bug because the program exists the while loop when number = 0 as all decimals would've been extracted.
//    {
//        return true;
//    }  
//    
//    */
//    
//     return false;
//}
//
//
//void PrintPalindromeOrNot(const int& number)    // pass by constant reference.
//{
//    if (IsPalindrome(number))
//    {
//        cout << number << " is a palindrome.\n";
//    }
//    else
//    {
//        cout << number << " is NOT a palindrome.\n"; 
//    }
//}
//
//
//int main()
//{
//  
//    PrintPalindromeOrNot(ReadPositiveInteger("Enter a number: "));  // Range NOT included as its value is NOT intrinsic.
//
//	return 0;
//}
//
