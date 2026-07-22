
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 Problem #32:

 Write a program to fill array with max size 100 with random numbers from
 1 to 100, copy it to another array in reverse order and print it.


 Input:
 Enter the number of random numbers to fill in the array: 10


 Output:

 Array 1 elements:
 64 8 62 19 2 21 15 74 96 85


 Array 2 elements after copying array 1 in reversed order:
 85 96 74 15 21 2 19 62 8 64

*/

int ReadIntegerNumber(const string& message)
{
    int number;  // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}



bool ValidateLengthInRange(const int& number, int min, int max)
{
    return (min <= number && number <= max);
}




int ReadArrayLength(const string& message, int min, int max)
{
    int count = 0;
    int number;  // what's returned

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error- value entered must be between " << min << " & " << max << endl;
        }
        number = ReadIntegerNumber(message); 

    } while (!ValidateLengthInRange(number, min, max));

    return number;

    // This block of code is to be sequentially composed line by line, & at the end implement all the functions in order.
}


int GenerateRandomNumbersInRange(int from, int to)   // pass by value
{
    return rand() % (to - from + 1) + from;
}



void FillArrayWithRandomNumbers(int array[], int& ArrayLength) // The array is automatically passed by ref.$
{
    int min = 1;
    int max = 100;
    ArrayLength = ReadArrayLength("Enter the number of random numbers to fill in the array: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumbersInRange(1, 100);  // our CORE randomness utility (in its implementation it MUST return int).
    }

    // This block of code is to be sequentially composed line by line, & at the end implement all the functions in order.
}









void PrintArray(const int TheArray[], const int& ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << TheArray[i] << " ";
    }

    cout << endl << endl;
}



void CopyArrayInReversedOrder(int array[], int ArrayLength, int ReversedArray[]) //  'ReversedArray[]' is AUTOMATICALLY passed by ref ( all arrays parameters anyway).
{
    // so start looping from the last index.
    // But, how about looping from the first index (instead of the usual looping from the last index)
    for (int i = 0; i < ArrayLength; i++)
    {
        ReversedArray[i] = array[ArrayLength - 1 - i];
    }

    //// or, as usual,  start looping from the last index.
    //int count = 0;
    //for (int i = ArrayLength - 1; i >= 0; i--)
    //{
    //    ReversedArray[count] = array[i];
    //    count++;
    //}
     
}



int main()
{
    srand((unsigned)time(NULL));

    int array[100], ArrayLength;
    FillArrayWithRandomNumbers(array, ArrayLength);
    // 'array' & 'ArrayLength' are now initialized.

    // Note: ArrayLength will be used in the condition of the for-loop of the array variable 'array'.

    int ReversedArray[100];
    CopyArrayInReversedOrder(array, ArrayLength, ReversedArray);
    // 'ReversedArray' is now initialized.



    
    cout << "The original array is: ";
    PrintArray(array, ArrayLength);

    cout << "The reversed array is: ";
    PrintArray(ReversedArray, ArrayLength);
    
    return 0;
}

