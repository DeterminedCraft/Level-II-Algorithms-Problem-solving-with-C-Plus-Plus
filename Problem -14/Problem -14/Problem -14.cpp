
#include <iostream>
using namespace std;

/*
 Problem #14:
 Write a program to read a number and print inverted letter pattern as follows?

 Input:        Output:
 3             CCC
               BB
               A


 Input:       Output:
 5            EEEEE
              DDDD
              CCC
              BB
              A




*/


int ReadIntegerNumber(const string& message)    // pass by constant reference.
{
    int number;   // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidatePositiveInteger(const int& number, int min, int max)  // pass by const. ref. as 'number' is ONLY used for comparison against the range.
{
    return (min <= number && number <= max);
}

int ReadIntegerNumberInRange(const string& message, int min, int max)   // pass by constant reference.   // Ranges ALWAYS passed by value.
{
    bool validate;
    int number;  // what's returned.

    do
    {
        number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

        validate = ValidatePositiveInteger(number, min, max);
        if (!validate)
        {
            cout << "Error - Only a number between " << min << " & " << max << " is allowed. \n";
        }

    } while (!validate);

    return number;

    /*   Note: The above block of code is to be sequentially composed line by line,
               & at the end, implement the functions of: ReadIntegerNumber()   &    ValidatePositiveInteger()   */
}


void PrintInvertedLetterPattern(const int& number)
{
    for (int i = number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(i +64);
        }

        cout << "\n";
    }
}





/*    ////  another version
void PrintInvertedLetterPattern(const int& number)       // pass by constant reference.
{
    for (int i = 64 + number; i >= 65; i--)
    {
        for (int j = 65; j <= i; j++)
        {
            cout << char(i);
        }

        cout << endl;
    }
}
*/


int main()
{
    int min = 1;
    int max = 26;

    PrintInvertedLetterPattern(ReadIntegerNumberInRange("Enter a number: ", min, max));   // Ranges included as their values are intrinsic.

    return 0;

}





