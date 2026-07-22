
#include <iostream>
using namespace std;

/*
    Problem #39

    Write a program to fill an array with a maximum size of 100 with random
    numbers from 1 to 100, COPY ONLY PRIME NUMBERS to another array using
    AddArrayElement(), and print it.

    Input:
    How many random number would you like to enter to fill the array with ?: 10



    Output:

    Array 1 elements:
    61 100 32 75 81 95 50 98 13 70

    Array 2 Prime numbers:
    61 13


*/





enum enPrimeOrNot { NotPrime = 1, Prime = 0 };




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



enPrimeOrNot CheckPrime(int number)    // pass by value.
{
    if (number <= 1)   // 1 or less is NOT a prime number. 
    {
        return enPrimeOrNot::NotPrime;
    }

    int M = round(number / 2.0);   // Warning: only using 2 results in integer division.
    for (int i = M; i > 1; i--)
    {
        if (number % i == 0)
        {
            return enPrimeOrNot::NotPrime;
        }
    }
    return enPrimeOrNot::Prime;

    /*   // this is a less optimized solution.
    for (int i = number - 1; i > 1; i--)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    */
   
}


void AddElementToArray(int number, int Array2[], int& Array2Length)
{
    Array2[Array2Length] = number;
    Array2Length++;
}



void CopyPrimeNumbersFromArrayToArray2(int array[], int ArrayLength, int Array2[], int& Array2Length)   // Array2[] is AUTOMATICALLY passed by reference.
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (CheckPrime(array[i]) == enPrimeOrNot::Prime)   // right of the '=' operand: equates to 1 (of data type enPrimeOrNot).
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
    CopyPrimeNumbersFromArrayToArray2(array, ArrayLength, Array2, Array2Length);
    // 'Array2'  &  'Array2Length'  are now initialized.


    cout << "Array 1 elements: ";
    PrintArray(array, ArrayLength);

    cout << "Array 2 Prime Numbers: ";
    PrintArray(Array2, Array2Length);



    return 0;
}



