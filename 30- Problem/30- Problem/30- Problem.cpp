
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    Problem #30:

    Write a program to fill array that can hold a maximum of 100 elements,
    with random numbers from 1 to 100,
    
    sum their elements in a third array and print the results.


    Input:
    10
    


    Output:

    Array 1 elements:
    42 68 35 1 70 25 79 59 63 65


    Array 2 elements:
    6 46 82 28 62 92 96 43 28 37


    Sum of array1 and array2 elements:
    48 114 117 29 132 117 175 102 91 102

*/


int ReadIntegerNumber(const string& message)   // pass by constant reference
{
    int number;  // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}





bool ValidateLengthInRange(const int& number, int min, int max)  //'number' is passed by const. ref. since it's ONLY used for comparison against the range.   // ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}





int ReadArrayLength(const string& message, int min, int max)  // pass by constant ref.   // ranges ALWAYS passed by value.
{
    int number;  // what's returned.

    do
    {
        number = ReadIntegerNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLengthInRange(number, min, max));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return number;
    // this block of code is to be sequentially composed line by line. And at the end, implement the functions of
    // ReadIntegerNumber()  &  ValidateLengthInRange()
}





int GenerateRandomNumberInRange(int from, int to)  // should ALWAYS return an int. ALWAYS use this utility as is.
{
    return rand() % (to - from + 1) + from;
}




void FillArrayWithRandomNumber(int array[], int ArrayLength)   // array is automatically passed by ref. without including the & sing (including it renders exception).
{
    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100);  // our CORE INEVITABLE UTILITY for generating random number, it should always return true
    }
}


void ProduceArraySum(int array[], int Array2[], int ArraySum[], int ArrayLength) // the array 'Array3' is passed by ref. by default (including the & sign renders exception).
{
    for (int i = 0; i < ArrayLength; i++)
    {
        ArraySum[i] = array[i] + Array2[i];
    }
}



void PrintFirstArray(const int array[], const int& ArrayLength)
{
    cout << "Array1 Elements: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " "; 
    }
    cout << endl << endl;
}

void PrintSecondArray(const int Array2[], const int &ArrayLength)
{
    cout << "Array 2 elements: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array2[i] << " ";
    }

    cout << endl << endl;
}


void PrintThirdArray(const int ArraySum[], const int& ArrayLength)
{
    cout << "Sum of array1 and array2 elements: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << ArraySum[i] << " ";
    }
    cout << endl << endl;
}

void PrintAllArrayElements(const int array[], const int Array2[], const int Array3[], const int& ArrayLength)
{
    PrintFirstArray(array, ArrayLength);
    PrintSecondArray(Array2, ArrayLength);
    PrintThirdArray(Array3, ArrayLength);
}




int main()
{
    srand((unsigned)time(NULL));    // to seed random numbers.

    int min = 1;  // we want at least an element in the array.
    int max = 100;  // since the array maximum capacity is 100

   int ArrayLength = ReadArrayLength("Enter the number of random numbers to fill the array with: ",min, max); // Ranges INCLUDED as their values are intrinsic.
/*        |
          |-- >  to be added at the very end, after typing the "return keyword in the implementing function. */


   int array[100], Array2[100];
   FillArrayWithRandomNumber(array, ArrayLength);
   // the array variable 'array' is now initialized.

   FillArrayWithRandomNumber(Array2, ArrayLength);
   // the array variable 'Array2' is now initialized.


   int ArraySum[100];
   ProduceArraySum(array, Array2, ArraySum, ArrayLength);
   // the array variable 'Array3' is now initialized.

   PrintAllArrayElements(array, Array2, ArraySum, ArrayLength);


	return 0;
}









