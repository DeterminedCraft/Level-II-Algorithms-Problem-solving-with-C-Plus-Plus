
// Separate: Treat the below code snippets as separate info
    // Look at these false implementation
    // Understanding it will help you level up in yopur understanding:

void CopyArrayToArray2InReverse(int array[], int ArrayLength, int Array2[])
{
    for (int i = 0; i < ArrayLength; i++)
    {
        AddElementToArray(array[i], Array2, ArrayLength);
    }
}


void AddElementToArray(int number, int Array2[], int ArrayLength)
{
    Array2[ArrayLength - 1] = number;
    ArrayLength--;
}

// WRONG: ArrayLength is passed by value, so ArrayLength-- only modifies a local copy.
// Once the function exits, the local copy is destroyed, and the original ArrayLength
// in the calling function remains unchanged.

 //AddElementToArray's ArrayLength = 3  (destroyed)
// main's ArrayLength = 4              (unchanged)

 ///////////////////////////////////////

 // this version is wrong too (same problem). + suggest a solution 

int count = 0;
void AddElementToArray(int number, int Array2[], int ArrayLength, int count)  // NEVER pass ArrayLength by reference as it is already initialized.
{
    count = ArrayLength - 1;

    Array2[count] = number;                                                // Then, the first index here can NOT start from 0, where we have to go to main() and declare Array2Length = 0;
    count--;                                                                                   // instead, we have to start from the LAST index because 'number' is the first element in the original array.
}

