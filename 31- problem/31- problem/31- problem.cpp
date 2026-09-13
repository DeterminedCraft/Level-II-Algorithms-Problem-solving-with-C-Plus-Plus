
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    Problem #31:

    Write a program to fill array with ordered numbers from 1 to N,
    then print it, 
    
    after that shuffle this array and print it after shuffle.

    --

    Input:
    Number of elements to populate the array with ?:  10

    Output:

    Array elements before shuffle:
    1 2 3 4 5 6 7 8 9 10

    Array elements after shuffle:
    2 4 6 3 10 1 7 8 5 9
*/





// Solution:


/*
    There are two methods of solving this problem:

    1. Preserve the original array by copying it to a second array,
       then shuffle the second array.

    2. Shuffle the original array directly.
*/


 //////Below is for #2  (Shuffling the original array directly)

int ReadIntegerNumber(const string& message)   // pass by constant ref.
{
    int number;  // what's returned

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}




bool ValidateLengthInRange(const int& number, int min, int max)  // 'number'is passed by constant ref since it's ONLY used for comparison againt the ranges
{
    return (min <= number && number <= max);
}




int ReadArrayLength(const string& message, int min, int max)  // pass by const. ref.   // ranges ALWAYS passed by value.
{
    int number;  // what's returned

    number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    while (!ValidateLengthInRange(number, min, max))   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
    {
        cout << "The length of the array should be between " << min << " & " << max << endl;
        number = ReadIntegerNumber(message);
    }

    return number;
}



void FillArrayFrom1ToN(int array[], int& ArrayLength)  //the array is automatically passed by ref without including the & sing ( including it renders exception).
{
    int min = 1;  // we want to at least have one element in the array.
    int max = 100; 
    ArrayLength = ReadArrayLength("Number of elements to populate the array with ?: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = i + 1;
    }
}




// Below:
// by reference because you want to swap the original numbers (standard practice),
// instead of swapping copies of them which entails that we have to continue coding 
// inside the swapping procedure which is ridiculous and also happens to violate the SRP
void SwapTwoNumbers(int& Number1, int &Number2)
{
    int temp = Number1;
    Number1 = Number2;
    Number2 = temp;
}


int GenerateRandomNumberInRange(int from, int to)  // our CORE INEVITABVLE random number generator that SHOULD ALWAYS return int.
{
    return rand() % (to - from + 1) + from;
}

void ShuffleTheArray(int array[], int ArrayLength) // the array is AUTOMATICALLY passed by ref. ALWAYS (we have no say in that).
{
    for (int i = 0; i < ArrayLength; i++)
    {
        SwapTwoNumbers(    array[GenerateRandomNumberInRange(0, ArrayLength - 1)]     ,     array[GenerateRandomNumberInRange(0, ArrayLength - 1)]    );
    }
}


void PrintTheArray(const int array[], const int& ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n\n";
}

int main()
{
    srand((unsigned)time(NULL));   // to see random number

    int array[100], ArrayLength;

    FillArrayFrom1ToN(array, ArrayLength);
    // the variables 'array' & 'ArrayLength' are now initialized.
    cout << "The array BEFORE shuffle: ";
    PrintTheArray(array, ArrayLength);

    ShuffleTheArray(array, ArrayLength);

    cout << "The array AFTER shuffle: ";
    PrintTheArray(array, ArrayLength);
    

    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////// Below is for #1:  Preserve the original array by copying it to a second array, then shuffle the second array.


int ReadIntegerNumber(const string& message)   // pass by constant ref.
{
    int number;  // what's returned

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}




bool ValidateLengthInRange(const int& number, int min, int max)  // 'number'is passed by constant ref since it's ONLY used for comparison againt the ranges
{
    return (min <= number && number <= max);
}




int ReadArrayLength(const string& message, int min, int max)  // pass by const. ref.   // ranges ALWAYS passed by value.
{
    int number;  // what's returned

    number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    while (!ValidateLengthInRange(number, min, max))   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
    {
        cout << "The length of the array should be between " << min << " & " << max << endl;
        number = ReadIntegerNumber(message);
    }

    return number;
}


void FillArrayFrom1ToN(int array[], int& ArrayLength)  // this array is automatically passed by ref.
{
    int min = 1;
    int max = 100;
    ArrayLength = ReadArrayLength("Number of elements to populate the array with ?: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = i + 1; 
    }
}

void CopyArrayToArray2(int array[], int ArrayLength, int Array2[])  // 'Array2' is automatically passd by ref (including & renders exception=.
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array2[i] = array[i];
    }
}


void PrintArray(const int TheArray[], const int& ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << TheArray[i] << " ";
    }

    cout << endl << endl;
}



int GenerateRandomNumberInRange(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

// Below:
// by reference because you want to swap the original numbers (standard practice),
// instead of swapping copies of them which entails that we have to continue coding 
// inside the swapping procedure which is ridiculous and also happens to violate the SRP
                                                  
                                                                                                  
void SwapTwoNumbers(int &Number1, int &Number2)  
{
    int temp;
    temp = Number1;
    Number1 = Number2;
    Number2 = temp;
    
}

void ShuffleArray(int Array2[], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        SwapTwoNumbers(Array2[GenerateRandomNumberInRange(0, ArrayLength - 1)]    ,   Array2[GenerateRandomNumberInRange(0, ArrayLength - 1)]);
    }
}



int main()
{
    srand((unsigned)time(NULL));
    int array[100], ArrayLength;

    FillArrayFrom1ToN(array, ArrayLength);
    // 'array' & ' ArrayLength' are now initialized.   // 'ArrayLength' is used in the condition of the for-loop for the array variable 'array'.

    int Array2[100];
    CopyArrayToArray2(array, ArrayLength, Array2);
    // 'Array2' is now initialized.


    ShuffleArray(Array2, ArrayLength);


    cout << "The original array is: \n";
    PrintArray(array, ArrayLength);

    cout << "The shuffled array is: \n";
    PrintArray(Array2, ArrayLength);
   

    return 0;
}




























