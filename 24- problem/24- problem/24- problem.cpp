
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    Problem #24:

    Write a program to fill an array, that can hold a maximum of 100 elements,
    with random numbers from 1 to 100,

    then print max.


    Input:
    Number of random numbers to fill the array with: 10

    
    Output:

    Array Elements: 65 91 83 71 32 52 17 28 71 52
    Max number is: 91


*/

int ReadIntegerNumber(const string& message)
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidateArrayLengthInRange(const int& number, int min, int max)   // ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}


int ReadArrayLength(const string& message, int min, int max)   // Ranges ALWAYS passed by value
{
    int count = 0;
    int number; // what's returned.

    do
    {
        count++;
        if (count > 1)
        {
            cout << "The number should be between " << min << " & " << max << endl;
        }
        number = ReadIntegerNumber(message);   // 'number' is to be immediately validated against the range, in the while condition.

    } while (!ValidateArrayLengthInRange(number, min, max));

    return number;
}




int GenerateRandomNumberInRange(int from, int to)
{
    return rand() % (to - from + 1) + from;
}





void FillArrayWithRandomNumbers(int array[], int& ArrayLength)
{
    int min = 1;
    int max = 100; // the max the array can hold.
    ArrayLength = ReadArrayLength("Enter the number of random numbers to fill in the array: ", min, max);  // Range INCLUDED as its value is INTRINSIC.

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100);  // our CORE INEVITABLE randomness function that ONLY generate a random integer.
    }
}


void PrintArrayElements(const int array[], const int& ArrayLength)
{
    cout << "Array Elements: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n\n";
}


int CalculateMaxNumberInArray(int array[], int ArrayLength)   // pass by value.
{
    int max = array[0];  // assume that the max value is the first element in the array.

    for (int i = 1; i < ArrayLength; i++)   // starting from i = 0 is ok too but there is no need for that.
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}


void PrintMaxNumberInArray( int array[], const int& ArrayLength)
{
    cout << "Max number is: " << CalculateMaxNumberInArray(array, ArrayLength) << endl << endl;
}


void PrintArrayInfo(int array[], const int &ArrayLength)
{
    PrintArrayElements(array, ArrayLength);
    PrintMaxNumberInArray(array, ArrayLength);
}


int main()
{
    srand((unsigned)time(NULL));   // to seed random numbers.
 
    int array[100], ArrayLength;
    // Initializing the above variable via reading user-input (Using Procedure - since an array contains MORE than one element):

    FillArrayWithRandomNumbers(array, ArrayLength);
    // The array variable 'array'  & the normal variable 'ArrayLength' are now initialized.

    // Note: 'ArrayLength' will only serve as the condition of the for-loops.
    PrintArrayInfo(array, ArrayLength);


    return 0;
 }


