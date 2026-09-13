
#include <iostream>
#include <cstdlib>;
#include <ctime>;          // required for:  srand((unsigned)time(NULL)); 
using namespace std;

/*
    Problem #23:

    Write a program to fill an array, that can hold a maximum of 100 elements,
    with random numbers from 1 to 100.

    Input:

    Number of random numbers to fill the array with: 10

    Output:

    Array Elements: 56 55 83 71 32 52 17 28 71 52
*/


// Solving this examples using the Array (fixed-length data structure) utility (Array mental model) but somewhat modified:
// Do NOT start coding using enums, as we are printing out integers,
// and even if the question asks us to print out single digits, then deal with them as how they are represented, which is numbers = integers.

int ReadIntegerNumber(const string& message)
{
    int number;

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidateLengthInRange(const int &number, int min, int max)   // ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}


int ReadArrayLength(const string& message, int min, int max)
{
    int count = 0;
    int number; // what's returned

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error- Number must be between " << min << " & " << max << endl;
        }
        number = ReadIntegerNumber(message);

    } while (!ValidateLengthInRange(number, min, max));

    return number;
}

int GenerateRandomNumberInRange(int from, int to)   // our CORE INEVITABLE randomness utility that ALWAYS return integer & should NEVER be modified.
{
    return rand() % (to - from + 1) + from; 
}

void FillArrayWithRandomNumbers(int array[], int& ArrayLength) // A UTILITY  //array always passed by ref. Including the & renders exception.
{
    short min = 1;
    short max = 100;  // the max number the array can hold onto.

    ArrayLength = ReadArrayLength("Number of random numbers to fill the array with: ", min, max ); // Ranges included as their values are NOT intrinsic.

    for (int i = 0; i < ArrayLength; i++)
    {
            array[i] = GenerateRandomNumberInRange(1, 100);   // our CORE INEVITABLE randomness utility. 
    }
}


void PrintArrayElements(const int array[], const int& ArrayLength)
{
    cout << "Array Elements: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl << endl;

}

int main()
{
    srand((unsigned)time(NULL));    // requires the #include <ctime>; library.

    int array[100], ArrayLength;

    // Initializing the above variables (array & ArrayLength) via reading user input (Using Procedure - since an array contains MORE than one element):
    FillArrayWithRandomNumbers(array, ArrayLength);   // array is passed along with its address in memory. hence- it's always implemented by passing by ref without including the & sign.
    // The array variable 'array' & the variable 'ArrayLength' are now initialized.


    // Note: 'ArrayLength' will only serve as the condition of the for-loops.
    PrintArrayElements(array, ArrayLength);

    return 0;
}


