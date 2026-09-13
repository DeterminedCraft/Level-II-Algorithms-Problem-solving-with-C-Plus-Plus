
#include <iostream>
using namespace std;

/*    These are crucially important variations to master:

      Cover ALL POSSIBLE SOLUTIONS for each item:

      1- Copy the array as it is.
      2- Copy the array in reverse.

      --------------------------------------------------------------------

      Key Principle:

      In both cases, you MUST iterate through every element of the original array.

      - To copy the array as it is:
        Start iterating from index 0.

      - To copy the array in reverse:
        Start iterating from the last index (ArrayLength - 1).

      The destination array is to be populated starting
      from index 0. This is the preferred approach because it keeps the code
      easier to read and less confusing.

      (Other approaches are possible, but this one is the clearest.)
*/



// 1- Copy array as it is: (verified)

void DirectlyInitializeArray(int array[], int& ArrayLength)  // Arrays are AUTOMATICALLY passed by ref (including & sign for arrays renders exception)
{
    ArrayLength = 4;

    array[0] = 2;
    array[1] = 7;
    array[2] = 9;
    array[3] = 5;
}

void AddElementToArray(int number, int Array2[], int& Array2Length)   // do NOT forget to pass 'Array2Length' by reference.
{
    Array2[Array2Length] = number;  // the logic here is that, the index argument HAS to be first = 0. 'ArrayLength' can't help here as it's already initialized so don't tamper with it.  // Instead, in main(), declare the variable Array2Length = 0;
    Array2Length++;
}



void CopyArrayToArray2(int array[], int ArrayLength, int Array2[], int& Array2Length)
{
    for (int i = 0; i < ArrayLength; i++)   // this step is ALWAYS MANDATORY and can NEVER be replaced (you HAVE to iterate through every single element)
    {
        //Array2[i] = array[i];     // this is very straight-forward ! But AddElementToArray is better !
        AddElementToArray(array[i], Array2, Array2Length);
    }
}


int main()
{

    int array[100], ArrayLength;
    DirectlyInitializeArray(array, ArrayLength);
    // 'array'  &  'ArrayLength' are now initialized.

    int Array2[100], Array2Length = 0;            // Initially I didn't include length for Array2 as we're copying the original array where length does not change,
    CopyArrayToArray2(array, ArrayLength, Array2, Array2Length);     // , so later. I included 'Array2Length = 0' as it's needed in AddElementToArray(). // and (crucial) do not forget to pass it by ref. in the implementation.                                                               
    // 'Array2' & ' Array2Length' are now initialized.


    return 0;
}







/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//2- Copy array in reverse (verified)


void DirectlyInitializeArray(int array[], int& ArrayLength) // Arrays are AUTOMATICALLY passed by ref without the & (doing so renders exception).
{
    ArrayLength = 4;

    array[0] = 3;
    array[1] = 1;
    array[2] = 7;
    array[3] = 2;
}




/*
void CopyArrayToArray2InReverse(int array[], int ArrayLength, int Array2[])
{
    int count = 0;

    for (int i = ArrayLength - 1; i >= 0; i--)
    {
        Array2[count] = array[i];   // CRUCIAL: Always start inserting elements into the new array from index 0 and move forward,
        count++;                           // even when the elements are copied in reverse order from the original array.
    }

    // But this is very straight-forward ! But AddElementToArray is better !
    // so instead, do it as illustated below:
}
*/


void AddElementToArray(int number, int Array2[], int& Array2Length)  // NEVER forget to pass by ref. for 'Array2Length'.
{
    Array2[Array2Length] = number; // the logic here is that, the index argument HAS to be first = 0 EVEN if you add in reverse. 'ArrayLength' can't help here as it's already initialized so don't tamper with it.  // Instead, in main(), declare the variable Array2Length = 0;
    Array2Length++;
}



void CopyArrayToArray2InReverse(int array[], int ArrayLength, int Array2[], int& Array2Length)  // Array2[] is AUTOMATICALLY passed by ref without inlcuding the & sign ( = renders exception)
{
    for (int i = ArrayLength - 1; i >= 0; i--)
    {
        AddElementToArray(array[i], Array2, Array2Length);
    }
}



int main()
{
    int array[100], ArrayLength;
    DirectlyInitializeArray(array, ArrayLength); // 'array' is passed as an argument in the calling function along with its address in memory. hence, it's ALWAYS passed by ref. in the implementation.
    // 'array' & 'ArrayLength' are now initialized.

    int Array2[100], Array2Length = 0;    // Array2Length = 0  was needed later, during the implementation of AddElementToArray(). never forget to add it by ref.
    CopyArrayToArray2InReverse(array, ArrayLength, Array2, Array2Length);  // 'array' is passed as an argument in the calling function along with its address in memory. hence, it's ALWAYS passed by ref. in the implementation.
    // 'Array2'  &  'Array2Length'  are now initialized.



    return 0;
}




/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


//Exercise: 
// Assume the following Unideal scenario (that we don't go about doing):
// 
//For copying the array in reverse, the UNIDEAL REQUIREMENT is that: Use a for-loop that starts from the 0 index:



void AddElementToArray(int number, int Array2[], int ArrayLength, int& Array2Length)
{
    Array2[Array2Length] = number;   // populate the array from index 0 and upwards 
    Array2Length++;
}


void CopyArrayToArray2InReverse(int array[], int ArrayLength, int Array2[], int& Array2Length)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        AddElementToArray(array[ArrayLength - 1 - i], Array2, ArrayLength, Array2Length);   //  <------------ The difference is made here in passing array[ArrayLength - 1 - i] instead of array[i]
    }
}


int main()
{
    int array[100], ArrayLength;
    DirectlyInitializeArray(array, ArrayLength);
    // 'array' & 'ArrayLength' are now initialized.

    int Array2[100], Array2Length = 0;
    CopyArrayToArray2InReverse(array, ArrayLength, Array2, Array2Length);
    // 'Array2'  &  'Array2Length' are now initialized.

    return 0;
}




