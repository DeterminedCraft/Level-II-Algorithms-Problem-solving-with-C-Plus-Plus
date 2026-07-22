
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 Problem #38:

 Write a program to fill array with max size 100 with random numbers from
 1 to 100, COPY ONLY ODD NUMBERS to another array using AddElementToArray,
 and print it.


 Input:
 
 Enter the number of random numbers you'd like to fill the array with ?: 10


 Output:

 Array 1 elements:
 59 14 84 36 6 51 48 91 96 67


 Array 2 copy but with only Odd numbers:
 59 51 91 67


*/


int ReadIntegerNumber(const string& message)
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}



bool ValidateLengthRange(const int& number)    // pass by constant reference as 'number' is ONly used for comparion against the range.
{
    return (number > 0);
}




int ReadArrayLength(const string& message)
{
    int number;   // what's returned

    do
    {
        number = ReadIntegerNumber(message);

    } while (!ValidateLengthRange(number));

    return number;
}


int GenerateRandomNumberInRange(int from, int to) // our CORE INEVITABLE utility to generate random numbers. // it HAS to return int
{
    return  rand() % (to - from + 1) + from;
}



void FillArrayWithRandomNumbers(int array[], int& ArrayLength)  // arrays are AUTOMATICALLY passed by ref.
{
    ArrayLength = ReadArrayLength("Enter the number of random numbers, you'd like to fill the array with ?: ");  // Range NOT included as its value is NOT intrinsic.

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100); // our CORE INEVITABLE utility to generate random numbers. 
    }

}


bool IsNumberOdd(int number)    // pass by value
{
    return (number % 2 != 0);
}


void AddElementToArray(int number, int Array2[], int &Array2Length)
{
    Array2[Array2Length] = number;
    Array2Length++;
}



void CopyOddNumbersInArrayToArray2(int array[], int ArrayLength, int Array2[], int& Array2Length)   // Array[] is AUTOMATICALLY passed by ref without & (including it renders exception).
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (IsNumberOdd(array[i]))  // array[i] % 2 != 0    no matter how small & simple the lineis, always wrap it into its own function.
        {
            AddElementToArray(array[i], Array2, Array2Length);
        }
    }
}


void PrintArray(const int SomeArray[], const int& LengthOfArray)
{
    for (int i = 0; i < LengthOfArray; i++)
    {
        cout << SomeArray[i] << " ";
    }
    cout << endl << endl;
}


int main()
{
    srand((unsigned)time(NULL));  // to seed random numbers. Must be included ONCE inside main().

    int array[100], ArrayLength;
    FillArrayWithRandomNumbers(array, ArrayLength);
    // 'array'  &  'ArrayLength'   are now initialized.


    int Array2[100], Array2Length = 0;
    CopyOddNumbersInArrayToArray2(array, ArrayLength, Array2, Array2Length);
    // 'Array2' & 'Array2Length'  are now initialized.

    cout << "Array 1 is: ";
    PrintArray(array, ArrayLength);

    cout << "Array 1 copied with ONLY ODD numbers: ";
    PrintArray(Array2, Array2Length);


    return 0;
}

