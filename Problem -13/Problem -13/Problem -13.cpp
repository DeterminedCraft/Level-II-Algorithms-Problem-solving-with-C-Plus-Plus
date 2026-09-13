
#include <iostream>
using namespace std;

/*
    Problem #13
    Write a program to read a number and print inverted pattern as follows:


    Input:     Output:
    3          1
               22
               333
    


    Input:    Output:
    5         1
              22
              333
              4444
              55555
    

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





void PrintNumberIncreasingPattern(const int& number)    // pass by constant reference.
{

    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }

        cout << endl;
    }

}



int main()
{
    
    PrintNumberIncreasingPattern(ReadPositiveInteger("Enter a number: "));

    return 0;

}


