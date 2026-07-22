
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 Note:  Copying an array using AddElementToArray() function is BETTER than the other seemingly straight-forward solution:

        Additionally,
        This problem requires acquaintance with the AddElementToArray() function explained in lesson #36.
        AddElementToArray()  is a better solution than the other seemingly straight-forward one.



 Problem #37

 Write a program to fill an array with max size of 100 with random numbers from
 1 to 100, copy it to another array using AddElementToArray() function, and print it.


 Input:
 How many random numbers would you like to fill the array with ?: 10


 Output:

 Array 1 elements:
 1 47 51 18 85 62 51 61 82 4


 Array 2 elements after copy:
 1 47 51 18 85 62 51 61 82 4


*/


int ReadIntegerNumber(const string& message)   // pass by constant reference.
{
    int number; // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateLengthRange(const int& number)   // pass by const ref. as 'number' is ONLY compared against the range
{
    return (number > 0);
}


int ReadArrayLength(const string& message)
{
    int number;  // what's returned.

    do
    {
        number = ReadIntegerNumber(message);   // 'number' is IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLengthRange(number));

    return number;
    // this block of code is to be sequentially composed line by line, and at the end implement all the functions.
}




int GenerateRandomNumberInRange(int from, int to)    // our CORE INEVITABLE utility for generating random numbers.  // HAS to ALWAYS return int.
{
    return rand() % (to - from + 1) + from;
}




void FillArrayWithRandomNumbers(int array[], int& ArrayLength)   // arrays are AUTOMATICALLY passed by ref (Including & renders exception).
{
    ArrayLength = ReadArrayLength("How many random numbers would you like to fill the array with ?: ");   // Range NOT included as its value is NOT intrinsic.

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100);   // our CORE INEVITABLE UTILITY for generating random number
    }

    // this block of code is to be sequentially composed line by line, and at the end implement all the functions.
}


void AddElementToArray(int number, int Array2[], int ArrayLength, int& ArrayLength2)  // arrays are AUTOMATICALLY passed by ref.
{
    Array2[ArrayLength2] = number;
    ArrayLength2++;
}



void CopyArrayToArray2(int array[], int ArrayLength, int Array2[], int& ArrayLength2)  // Array2[] is AUTOMATICALLY passed by ref. (Including the & sign renders exception)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        AddElementToArray(array[i], Array2, ArrayLength, ArrayLength2);

        // This solution is BETTER than the below one:
        /*


         for(int i = 0; i < ArrayLength; i++)
         {
           Array2[i] = array[i];
         }


        */
    }
}


void PrintArray(const int SomeArray[], const int& ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << SomeArray[i] << " ";
    }

    cout << "\n\n";
}



int main()
{
    srand((unsigned)time(NULL));   // to seed random numbers.

    int array[100], ArrayLength = 0;
    FillArrayWithRandomNumbers(array, ArrayLength);
    // 'array'  & 'ArrayLength' are now initialized.


    int Array2[100], ArrayLength2 = 0;
    CopyArrayToArray2(array, ArrayLength, Array2, ArrayLength2);
    // 'Array2'  &  'ArrayLength2' are now initialized.


    cout << "Array 1 elements: \n";
    PrintArray(array, ArrayLength);

    cout << "Array 2 elements after copy: \n";
    PrintArray(Array2, ArrayLength);



    return 0;
}


