
#include <iostream>
using namespace std;

/*
    Problem #41

    Write a program to fill an array with numbers, then check if it is
    a Palindrome array or not.

    Note:
    A Palindrome array can be read the same from right to left
    and from left to right.

    Input:


    Enter number of elements to add to array: 6

    Enter number: 10
    Enter number: 20
    Enter number: 30
    Enter number: 30
    Enter number: 20
    Enter number: 10


 

    Output:

    The reversed Array Elements are:
    10 20 30 30 20 10

    Yes, array is Palindrome.


*/







int ReadIntegerNumber(const string& message)
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}




bool ValidateIntegerInRange(const int& number, int MinNumber, int MaxNumber)  // 'number' is passed by const. ref. as it's ONLY used for comparison  // ranges ALWAYS passed by value.
{
    return (MinNumber <= number && number <= MaxNumber);
}




int ReadIntegerInRange(const string& message, int MinLength, int MaxLength)
{
    int number;  // what's returned.

    number = ReadIntegerNumber(message);  // 'number' is IMMEDIATELY validated against the range, in the while condition

    while (!ValidateIntegerInRange(number, MinLength, MaxLength))
    {
        cout << "Error- Length must be between " << MinLength << " & " << MaxLength << endl;
        number = ReadIntegerNumber(message);
    }

    return number;
}





void ReadArray(const string& message, int MinElement, int MaxElement, int array[], int& ArrayLength)  // Ranges ALWAYS passed by value.// arrays AUTOMATICALLY passed by ref (including & renders exception).  
{
    int MinLength = 1;  // I want to at least have one element in the array
    int MaxLength = 100;  // and up to 100 elements which is the max capacity of the array.

    ArrayLength = ReadIntegerInRange("How many elements would you like to enter in the array ?: ", MinLength, MaxLength);  // instead of ReadArrayLength so that an existing utility is called.

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = ReadIntegerNumber(message);  // 'array[i]' is to be immediately validated against the range, in the while condition

        while (!ValidateIntegerInRange(array[i], MinElement, MaxElement))
        {
            cout << "Error. Number must be between " << MinElement << " & " << MaxElement << endl;
            array[i] = ReadIntegerNumber(message);
        }
    }
      // this block of code is to be sequentially composed line by line & at the end, implement all functions.
}


bool IsArrayPalindrome(int array[], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (array[i] != array[ArrayLength - 1 - i])
        {
            return false;
        }
    }
    return true;
}





void PrintReversedArray(const int Array2[], const int& Array2Length)
{
    for (int i = 0; i < Array2Length; i++)
    {
        cout << Array2[i] << "";
    }

    cout << "\n\n";
}


void AddElementToArray(int number, int Array2[], int &Array2Length)  // do NOT forget to pass Array2Length by ref.
{
    Array2[Array2Length] = number;  // best practice: start adding from the zero index. // ArrayLength value has already been initialized and can't be used. so set Array2Length = 0 in main()
    Array2Length++;
}


void CopyArrayToArray2InReverse(int array[], int ArrayLength, int Array2[], int &Array2Length) // Array2[] is AUTOMATICALLY passed by ref. without including the & sign.
{
    for (int i = ArrayLength - 1; i >= 0; i--)
    {
        AddElementToArray(array[i], Array2, Array2Length);
    }
}
//// Below: Very unideal solutions:
// 
//    /*for (int i = 0; i < ArrayLength; i++)
//    {
//        Array2[i] = array[ArrayLength - 1 - i];
//    }*/
//    
//    /*int count = 0;
//    for (int i = ArrayLength - 1; i >= 0; i--)
//    {
//        Array2[count] = array[i];
//        count++;
//    }*/

int main()
{
    int MinElement = -1000;
    int MaxElement = 1000;
    
    int array[100], ArrayLength;
    ReadArray("Enter number: ", MinElement, MaxElement, array, ArrayLength);
    // 'array'  & ' ArrayLength' are now initialized.

    int Array2[100], Array2Length = 0;
    CopyArrayToArray2InReverse(array, ArrayLength, Array2, Array2Length);



    PrintReversedArray(Array2, ArrayLength);


    if (IsArrayPalindrome(array, ArrayLength))
    {
        cout << "It's a palindrome\n";
    }
    else
    {
        cout << "It's NOT a palindrome\n";
    }

    return 0;
}



































































