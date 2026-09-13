
#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Problem #26:

    Write a program to fill an array, that can hold a maximum of 100 elements,
    with random numbers from 1 to 100,

    then print the sum of all numbers


    Input:
    Number of random numbers to fill the array with: 10


    Output:

    Array Elements: 65 91 83 71 32 52 17 28 71 52

    Sum of all numbers is: 562


*/

int ReadIntegerNumber(const string& message)    // pass by constant reference.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}




bool ValidateLengthInRange(const int& number, int min, int max)   // pass by constant reference since 'number' is ONLY used for comparison against the range   // Ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}




int ReadArrayLength(string message, int min, int max)   // pass by constant reference.  // ranges ALWAYS passed by value.
{
    int count = 0;
    int number; // what's returned.

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error - number entered must be between " << min << " & " << max << endl;
        }

        number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLengthInRange(number, min, max));  // the condition is written so that, it evaluates to TRUE when the condition is INVALID.

    return number;
}


int GenerateRandomNumberInRange(int from, int to)    // pass by value   // our CORE untility for geenrating randomness. SHOULD ALWAYS return integer.
{
    return rand() % (to - from + 1) + from;
}



void FillArrayWithRandomNumbers(int array[], int& ArrayLength)  // array passed by ref. without including the & sign (including it yields exception).
{
    int min = 1;
    int max = 100;  // is the maximum capacity of the array
    
    ArrayLength = ReadArrayLength("Enter the number of random numbers to fill the array with: ", min, max); // 'ArrayLength' is to be IMMEDIATELY validated against the range, in the while condition.

  
    
    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100);  // this is our CORE INEVITABLE UTILITY for generating random numners
    }
    
}


void PrintArrayElements(const int array[], const int ArrayLength)
{
    cout << "Array Elements: ";

    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n\n";
}


int CalculateSumOfNumbers(int array[], int ArrayLength)    // pass by value.
{
    int sum = 0; // routine  // what's returned.

    for (int i = 0; i < ArrayLength; i++)
    {
        sum += array[i];
    }

    return sum;
}


void PrintSumOfArrayElements( int array[], const int& ArrayLength)
{
    cout << "Sum of all numbers is: " << CalculateSumOfNumbers(array, ArrayLength) << endl << endl;
}



void PrintArrayInfo( int array[], const int& ArrayLength)
{
    PrintArrayElements(array, ArrayLength);
    PrintSumOfArrayElements(array, ArrayLength);
}


int main()
{
    srand((unsigned)time(NULL));   // to seed random numbers // MUST be included in main() ONLY and for once.

    int array[100], ArrayLength;

    // Initializing the above variableS via reading user input (Using Procedure- since array contains MORE than one element):
    FillArrayWithRandomNumbers(array, ArrayLength);  // the array variable 'array' is passed as an argument along with its address in memory (by default)
                                    // hence- in the implementing function, it's passed by reference WITHOUT including the & sign.
    // 'array' & 'ArrayLength' are now fully initialized.
    

    // Note:ArrayLength is ALWAYS used in the for-loop condition.
    PrintArrayInfo(array, ArrayLength);
    

    return 0;
}


