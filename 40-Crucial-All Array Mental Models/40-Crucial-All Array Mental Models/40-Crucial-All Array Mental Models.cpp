
#include <iostream>
using namespace std;

/*
 This example incorporates ALL array mental models that are:

 - IsNumberInArray()
 - FindIndexOfElementInArray()
 - AddElementToArray()


*/


/*
    Problem #40


    Write a program to fill an array with the following hardcoded numbers: 10 10 10 50 50 70 70 70 70 90
   ,then print the numbers WITH NO REPETITION to another array.



    Output:

    Array 1 elements:
    10 10 10 50 50 70 70 70 70 90

    Array 2 with elements NOT repeated:
    10 50 70 90


*/


void InitializeArrayDirectly(int array[], int& ArrayLength) // arrays are AUTOMATICALLY passed by ref.
{
    ArrayLength = 10;

     array[0] = 10;
     array[1] = 10;
     array[2] = 10;
     array[3] = 50;
     array[4] = 50;
     array[5] = 70;
     array[6] = 70;
     array[7] = 70;
     array[8] = 70;
     array[9] = 90;
}


int FindIndexOfElementInArray(int number, int Array2[], int Array2Length)   // pass by value.
{
    for (int i = 0; i < Array2Length; i++)
    {
        if (Array2[i] == number)
        {
            return i;
        }
    }

    return -1;
}

bool IsNumberInArray(int number, int Array2[], int Array2Length)   // pass by value
{
    return (FindIndexOfElementInArray(number, Array2, Array2Length) != -1);
}


void AddNumberToArray(int number, int Array2[], int& Array2Length)
{
    Array2[Array2Length] = number;
    Array2Length++;
}

void CopyArrayToArray2WithNoRepete(int array[], int ArrayLength, int Array2[], int &Array2Length)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if(! IsNumberInArray(array[i], Array2, Array2Length))
        {
            AddNumberToArray(array[i], Array2, Array2Length);
        }
    }

    // this block is to be sequentially composed line by line and at the end implement, in order, all functions.
}



void PrintArray(const int SomeArray[], const int& LengthOfArray)
{
    for (int i = 0; i < LengthOfArray; i++)
    {
        cout << SomeArray[i] << " ";
    }

    cout << "\n\n";
}



int main()
{
    int array[100], ArrayLength;
    InitializeArrayDirectly(array, ArrayLength);
    // 'array'  & ' ArrayLength' are now initialized.

    int Array2[100] = {}, Array2Length = 0;
    CopyArrayToArray2WithNoRepete(array, ArrayLength, Array2, Array2Length);


    cout << "Array 1 elements: \n";
    PrintArray(array, ArrayLength);

    cout << "Array 2 with elements NOT repeated: \n";
    PrintArray(Array2, Array2Length);

    return 0;
}







































