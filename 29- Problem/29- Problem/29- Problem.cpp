
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    Problem #29:

    Write a program to fill array that can hold a maximum of 100 elements,
    with random numbers from 1 to 100, 
    
    copy ONLY prime numbers to another array and print it.


    Input:
    Number of random numbers to fill the array with: 10


    Output:

    Array 1 elements:

    42 68 35 1 70 25 79 59 63 65


    Prime Numbers in Array2:

    1 79

*/






// we START CODING with enums:

enum enPrimeOrNot { Prime = 1, NotPrime = 0}; // the enumeration constants (enumerators) that are Prime & NotPrime act as labels for the raw integral values they represent
// so FOREVER FORGET about these raw values and ONLY deal with their labels from now and on.
// so far, only an enum user-defined data type has been created and nothing more. 
// the next natural step is creating a variable of this enum user-defined data type in main():




int ReadIntegerNumber(const string& message)    // pass by const. ref.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}




bool ValidateLengthInRange(const int& number, int min, int max) // 'number' is passed by const- ref. since it's ONLY used for comparison against the range
{
    return (min <= number && number <= max);
}




int ReadArrayLength(const string& message, int min, int max)   // pass by constant reference.   // ranges ALWAYS passed by value.
{
    int number;  // what's returned.

    do
    {
        number = ReadIntegerNumber(message);  // 'number' is IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateLengthInRange(number, min, max));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return number; 
}




int GenerateRandomNumberInRange(int from, int to)
{
    return rand() % (to - from + 1) + from;
}




void FillArrayWithRandomNumbers(int array[], int& ArrayLength)   // array is automatically passed by ref; including the & sign results in an exception thrown.
{
    int min = 1;  // we want the array to, at least, hold one element.
    int max = 100;  // the maximum capacity of the array
    ArrayLength = ReadArrayLength("Enter the number of random elements to fill the array with: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100);  // the CORE INEVITABLE utility to generate random numbers and should always return integer.
    }
}





enPrimeOrNot CheckIfPrime(int number)  // pass by value
{
    if (number <= 1)  // a number that is 1 or less, is NOT a prime nunmber
    {
        return enPrimeOrNot::NotPrime;
    }

    int M = round(number / 2.0);
    for (int i = M; i > 1; i--)
    {
        if (number % i == 0)
        {
            return enPrimeOrNot::NotPrime;
        }
    }

    return enPrimeOrNot::Prime;

    /*   // originally I had (which is correct), but to reduce the number of iterations then use the above version.
    for (int i = number - 1; i > 1; i--)
    {
        if (number % i == 0)
        {
            return enPrimeOrNot::NotPrime;
        }
    }

    return enPrimeOrNot::prime;
    */
}





void CopyArrayWithPrimeNumbers(int SourceArray[], int ArrayLength, int DestinationArray[], int& Array2Length)   // arrays auitomatically passed by ref without including the & sign 
{
    int count = 0;

    for (int i = 0; i < ArrayLength; i++)
    {
        if (CheckIfPrime(SourceArray[i]) == enPrimeOrNot::Prime)  // to the right of the operand: Equates to 1 (of data type enPrimeorNot)
        {
            DestinationArray[count] = SourceArray[i];
            count++;
        }
    }

    Array2Length = count;
   
}



void PrintSourceArray(const int array[], const int& ArrayLength)
{
    cout << "Array 1 elements: ";

    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    } 
    cout << endl << endl;
}


void PrintDestinationArray(const int Array2[], const int& Array2Length)
{
    cout << "Prime Numbers in Array2: \n\n";
    for (int i = 0; i < Array2Length; i++)
    {
        cout << Array2[i] << " ";
    }
    cout << "\n";
}

void PrintBothArrays(const int array[], const int& ArrayLength, const int Array2[], const int& Array2Length)
{
    PrintSourceArray(array, ArrayLength);
    PrintDestinationArray(Array2, Array2Length);
}


int main()
{
    srand((unsigned)time(NULL));   // to seed the random numbers.

    //enPrimeOrNot PrimeOrNot;  // not needed //the next natural step of declaring a variable of the enum user-defined data type.

    int array[100], ArrayLength;  // 'ArrayLength' because we will be asking the user, how many elements should fill up the array.
    // the above variableS are initialized via reading user input (using Procedure - since an array contains MORE than one element):

    FillArrayWithRandomNumbers(array, ArrayLength);   // the array variable 'array' is automatically passed alone its address in memory. Therefore, in the implementation it's passed by ref.
    // the array variable 'array'   & the normal variable 'ArrayLength'  are now initialized.
    // Note:  ArrayLength will be used in the condition of the for-loop of the 'array' variable.

    int Array2[100], Array2Length;   // the length of this second array will be different as it will only hold a copy of the prime numbers stored in the original array.
    CopyArrayWithPrimeNumbers(array, ArrayLength, Array2, Array2Length);
    // Array2  & Array2Length  are now initialized:
        // where Array2 only contains all the prime numbers copied from the original array 'array'.
        // and Array2Length is the length of this new array. And, it will be used in the condition of the for-loop that loops through the Array2[].
    
    PrintBothArrays(array, ArrayLength, Array2, Array2Length);

    return 0;
}








/*******************************************************     ANOTHER EQUALLY VALID SOLUTION   ******************************************************************
  ***********************************************************************************************************************************************************************
  ***********************************************************************************************************************************************************************
 
 
 ****** WHEN we have in MAIN(): 




 int main()
 {
   int Array2[100], Array2Length = 0;
    CopyArrayWithPrimeNumbers(array, ArrayLength, Array2, Array2Length);
 }




 ****** WHERE the implementation is:
 


 
 
 void CopyArrayWithPrimeNumbers(int SourceArray[], int ArrayLength, int DestinationArray[], int& Array2Length)   // arrays auitomatically passed by ref without including the & sign 
{

    for (int i = 0; i < ArrayLength; i++)
    {
        if (IsNumberPrime(SourceArray[i]) == enPrimeOrNot::Prime)  // to the right of the operand: Equates to 1 (of data type enPrimeorNot)
        {
            DestinationArray[Array2Length] = SourceArray[i];
            Array2Length++;
        }
    }
   
}

  ***********************************************************************************************************************************************************************
  ***********************************************************************************************************************************************************************


*/


/////////////  A COMMENTED OUT VERSION FOR THE ABOVE CORRECT & OPTIMIZED CODE 



#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime = 0 };

int ReadIntegerNumber(const string& message)
{
    int number;

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
    int number;

    do
    {
        number = ReadIntegerNumber(message);

    } while (!ValidateLengthInRange(number, min, max));

    return number;
}

int GenerateRandomNumberInRange(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumbers(int array[], int& ArrayLength)
{
    int min = 1;
    int max = 100;

    ArrayLength = ReadArrayLength("Enter the number of random elements to fill the array with: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        array[i] = GenerateRandomNumberInRange(1, 100);
    }
}

enPrimeOrNot CheckIfPrime(int number)
{
    if (number <= 1)
    {
        return enPrimeOrNot::NotPrime;
    }

    int M = round(number / 2.0);

    for (int i = M; i > 1; i--)
    {
        if (number % i == 0)
        {
            return enPrimeOrNot::NotPrime;
        }
    }

    return enPrimeOrNot::Prime;
}

void CopyArrayWithPrimeNumbers(int SourceArray[], int ArrayLength, int DestinationArray[], int& Array2Length)
{
    int count = 0;

    for (int i = 0; i < ArrayLength; i++)
    {
        if (CheckIfPrime(SourceArray[i]) == enPrimeOrNot::Prime)
        {
            DestinationArray[count] = SourceArray[i];
            count++;
        }
    }

    Array2Length = count;
}

void PrintSourceArray(const int array[], const int& ArrayLength)
{
    cout << "Array 1 elements: ";

    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl << endl;
}

void PrintDestinationArray(const int Array2[], const int& Array2Length)
{
    cout << "Prime Numbers in Array2: \n\n";

    for (int i = 0; i < Array2Length; i++)
    {
        cout << Array2[i] << " ";
    }

    cout << "\n";
}

void PrintBothArrays(const int array[], const int& ArrayLength, const int Array2[], const int& Array2Length)
{
    PrintSourceArray(array, ArrayLength);
    PrintDestinationArray(Array2, Array2Length);
}

int main()
{
    srand((unsigned)time(NULL));

    int array[100], ArrayLength;

    FillArrayWithRandomNumbers(array, ArrayLength);

    int Array2[100], Array2Length;

    CopyArrayWithPrimeNumbers(array, ArrayLength, Array2, Array2Length);

    PrintBothArrays(array, ArrayLength, Array2, Array2Length);

    return 0;
}







