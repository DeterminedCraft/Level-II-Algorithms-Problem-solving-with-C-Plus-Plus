// 34- Problem.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



// NOTE: FindIndexOfNumberInArray() function is VERY FOUNDATIONAL- This is why I classified it as a mental model (so that it's not overlooked).

/*
Problem #34:

 Write a program to fill array with max size 100 with random numbers from
 1 to 100, read number and return its index in array if found otherwise
 return -1.


 Input:                                  Input:
 Enter the number of random numbers      Enter the number of random numbers
 to fill in the array with:  10          to fill in the array with:  10


 Output:                                 Output:

 Array 1 elements:                       Array 1 elements:
 80 79 12 80 81 29 3 37 25 91            80 79 12 80 81 29 3 37 25 91


 Please enter a number to search for?    Please enter a number to search for?
 12                                      55

 Number you are looking for is: 12       Number you are looking for is: 55

 The number is found at index: 2         The number is not found :-(
 The number's order : 3

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


int GenerateRandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumbers(int array[], int& ArrayLength) // arrays are automatically passed by ref
{
    int min = 1;
    int max = 100;
    ArrayLength = ReadArrayLength("Enter the number of random numbers to fill in the array with: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumber(1, 100);  // our CORE INEVITABLE randomness function that ALWAYS return an integer number.
    }
}


void PrintArray(const int array[], const int& ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n\n";
}


bool ValidatePositiveNumber(const int& number)
{
    return (number > 0);
}


int ReadPositiveNumber(const string& message)    // pass by constant ref
{
    int count = 0;
    int number;  // what's returned

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error- Only positive numbers allowed. ";
        }
        number = ReadIntegerNumber(message);

    } while (!ValidatePositiveNumber(number));

    return number;
}



int FindIndexOfNumberInArray(int NumberToSearch, int array[], int ArrayLength)  // pas by value.
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (array[i] == NumberToSearch)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    srand((unsigned)time(NULL));  // to seed random numbers.

    int array[100], ArrayLength;
    FillArrayWithRandomNumbers(array, ArrayLength);
    // 'array' & 'ArrayLength' are now initialized.     // Note: ArrayLength will be used in the condition of the for-loop of the array variable 'array'.

    cout << "Array 1 elements: \n";
    PrintArray(array, ArrayLength);

    int NumberToSearch = ReadPositiveNumber("\nEnter a number to search for: ");  // range NOT included as its value is NOT intrinsic.
    /*       |
             |--> to be typed at the end, after finishing typing the "return" keyword in the implementing function. */

    cout << "\nNumber you are looking for is: " << NumberToSearch << endl;

    int index = FindIndexOfNumberInArray(NumberToSearch, array, ArrayLength);
    if (index != -1)
    {
        cout << "The element is found at index: " << index << endl;
        cout << "The element's order is: " << index + 1 << endl;
    }
    else
    {
        cout << "Number NOT found \n";
    }



    return 0;
}


