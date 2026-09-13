
#include <iostream>
using namespace std; 

/*
 Problem #15:
 Write a program to read a number and print letter pattern as follows:

 Input: 3
 Output:

 A
 BB
 CCC

 Input: 5
 Output:

 A
 BB
 CC
 DDDD
 EEEEE



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

int ReadNumberInRange(const string& message, int min, int max)   // pass by constant reference.   // Ranges ALWAYS passed by value.
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


void PrintLetterPattern(const int& number)
{
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(64 + i);
        }
        cout << endl; 
    }
}


int main()
{
	int min = 1;
	int max = 26;

	PrintLetterPattern(ReadNumberInRange("Enter a number: ", min, max));

	return 0;
}

