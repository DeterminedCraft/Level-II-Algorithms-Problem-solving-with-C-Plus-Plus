
#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Problem #25:

    Write a program to fill an array, that can hold a maximum of 100 elements,
    with random numbers from 1 to 100,

    then print min.


    Input:
    Number of random numbers to fill the array with: 10


    Output:

    Array Elements: 65 91 83 71 32 52 17 28 71 52
    Min number is: 17


*/

int ReadIntegerNumber(const string& message)   // pass by constant reference.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidateLengthInRange(const int& number, int min, int max)  // pass by constant ref. as this value is ONLY used for comparison against the range.
{
    return (min <= number && number <= max);
}


int ReadArrayLength(const string& message, int min, int max)   // pass by constant reference.   // Ranges ALWAYS passed by value.
{
    int count = 0;
    int number;   // what's returned.

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error- Number entered must be between " << min << " & " << max << "\n";
        }
        number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLengthInRange(number, min, max));  // the argument is written so that, it evaluates to TRUE when condition is INVALID.

    return number;
}

int GenerateRandomNumberInRange(int from, int to)   // our CORE RANDOMNESS utilty function (inevitable) that ALWAYS return int
{
    return rand() % (to - from + 1) + from;
}


void FillArrayWithRandomNumbers(int array[], int& ArrayLength)  // array ALWAYS passed by ref. (including the & renders exception)
{
    int min = 1;
    int max = 100; // the number of elements in the array should be from 1 to the 100 (the max number the array can hold).
    ArrayLength = ReadArrayLength("Enter Number of random numbers to fill the array with: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100); // our CORE INEVITABLE radomness function that ALWAYS returns an integer.
    }
}


void PrintArray(int array[], int ArrayLength)
{
    cout << "Array elements: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n\n";
}

int CalculateMinimumNumber(int array[], int ArrayLength)   // pass by value
{
    int minimum = array[0];

    for (int i = 1; i < ArrayLength; i++)      // one can stasrt from i = 0 (no problem).
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }

    return minimum;
}

void PrintMinNumberInArray(int array[], const int& ArrayLength)
{
    cout << "Minimum number is " << CalculateMinimumNumber(array, ArrayLength) << endl << endl;
}

void PrintArrayInformation(int array[], const int& ArrayLength) // array ALWAYS passed by ref. (including the & renders exception)
{
    PrintArray(array, ArrayLength);
    PrintMinNumberInArray(array, ArrayLength);
}


int main()
{
    srand((unsigned)time(NULL));   // to seed random numbers.

    int array[100], ArrayLength;
    // Initializing the above variableS via reading user input (Using Procedure- since an array contains MORE than one element):

    FillArrayWithRandomNumbers(array, ArrayLength);// the array variable 'array' is automatically passed in the argument along with its address in memory. hence, its implementation is by reference always.
    // the array variable 'array'  & the normal variable 'ArrayLength' are now initialized.
    // 
    // Note: 'ArrayLength' will only serve as the condition of the for-loops.
    PrintArrayInformation(array, ArrayLength);

    return 0;
}

