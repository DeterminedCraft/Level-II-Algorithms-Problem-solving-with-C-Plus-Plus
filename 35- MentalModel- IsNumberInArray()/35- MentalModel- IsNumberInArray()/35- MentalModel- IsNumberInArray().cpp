
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// NOTE: IsNumberInArray() function is VERY FOUNDATIONAL- This is why I classified it as a mental model (so that it's not overlooked).



/*
Problem #35:

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

 Yes, the number is found :)             No, the number isn't found.


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




int FindIndexOfNumberInArray(int array[], int ArrayLength, int NumberToSearch)
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

bool IsNumberInArray(int array[], int ArrayLength, int NumberToSearch)
{
    return FindIndexOfNumberInArray(array, ArrayLength, NumberToSearch) != -1;
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

    cout << "------------------------------------------------------------\n";
    cout << "\nNumber you are looking for is: " << NumberToSearch << endl << endl;



    if (!IsNumberInArray(array, ArrayLength, NumberToSearch))
    {
        cout << "Number is NOT in the array. \n\n";
    }
    else
    {
        cout << "Number is in the array. \n\n";
    }


    return 0;
}



// I could have simply just written: (remove the ! and swap the cout messages)

/*
if (IsNumberInArray(array, ArrayLength, NumberToSearch))
{
    cout << "Number is found. \n\n";

}
else
{
    cout << "Number is NOT found. \n\n";
}
*/


// but I intentionally intended to use the ! sign, for getting used to it.
