
#include <iostream>
using namespace std;


/*
    Problem #22:

    Write a program to read N elements and store them in an array,
    then print all array elements and ask for a number to check.
    Finally, print how many times that number is repeated in the array.


    Input:


    Enter number of array elements: 5

    Element [1]: 1
    Element [2]: 1
    Element [3]: 1
    Element [4]: 2
    Element [5]: 3

    Enter the number you want to check: 1


    Output:

    Original array: 1 1 1 2 3

    1 is repeated 3 time(s)

*/






/*
   The re-usable UTILITY for Array (Fixed-length data structure) Mental Model:

    Included at the very end.     */




int ReadIntegerNumber(const string& message)
{
    int number;

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}

bool ValidateArrayLengthInRange(const int& number, int min, int max)  // ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}


int ReadArrayLength(const string &message, int min, int max)   // ranges always passed by value.
{
    int count = 0;
    int number;

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error - Number must be between " << min << " & " << max << endl;
        }

        number = ReadIntegerNumber(message);

    } while (!ValidateArrayLengthInRange(number, min, max));

    return number;
}


int ReadIntegerNumberElement(const string& message, int i)
{
    int number;

    cout << message << "[" << i << "]: ";
    cin >> number;
    cout << endl;

    return number;
}



bool ValidateBiggerOrEqualZeroInteger(const int& number)
{
    return (number >= 0);
}


void ReadArray(string message, int array[], int& ArrayLength)   // A UTILITY  //the array is ALWAYS passed by ref. (including the & renders exception).
{
    bool validate;   // added at the very end when it was needed    // using the count way, for the error message, doesn't work when implementing the for-loop.

    int min = 1;
    int max = 100;  // is the max number the array can hold.
    ArrayLength = ReadArrayLength("Enter number of array elements: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {

        do
        {
            array[i] = ReadIntegerNumberElement(message, i);

            validate = ValidateBiggerOrEqualZeroInteger(array[i]);

            if (!validate)
            {
                cout << "Error - Element value can't be negative. ";
            }

        } while (!validate);  // I decided that only 0 and positive array elements are acceptable; make your own decision.
    }

}

int ReadNumberToCheck(const string& message)
{
    int count = 0;
    int number; // what's returned.

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error- No negative array element exists. Try again.\n";
        }

        number = ReadIntegerNumber(message);

    } while (!ValidateBiggerOrEqualZeroInteger(number));

    return number;
}


void PrintArrayElements(const int array[], int ArrayLength)  // array ALWAYS passed by ref without including the & sign ( = renders excaption if included).
{
    cout << "Original array: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl << endl;
}



int CalculateNumberOfRepetitions(int array[], int NumberToCheck, int ArrayLength)
{
    int count = 0;
    for (int i = 0; i < ArrayLength; i++)
    {
        if (array[i] == NumberToCheck)
        {
            count++;
        }
    }

    return count;
}


void PrintNumberOfRepetitions(int array[], const int& NumberToCheck, int const& ArrayLength)   // array ALWAYS passed by ref without including the & sign ( = renders excaption if included).
{
    cout << NumberToCheck << " is repeated " << CalculateNumberOfRepetitions(array, NumberToCheck, ArrayLength) << " time(s)." << endl;
}


void  PrintResults(int array[], const int& NumberToCheck, const int& ArrayLength)    // array ALWAYS passed by ref without including the & sign ( = renders excaption if included).
{
    PrintArrayElements(array, ArrayLength);
    PrintNumberOfRepetitions(array, NumberToCheck, ArrayLength);
}

int main()
{
    int array[100], ArrayLength, NumberToCheck;    // declared an array that can hold up to 100 elements.

    // Initializing the above variableS via reading user-input (Using Procedure - since an array contains MORE than one element):
    ReadArray("Enter Element ", array, ArrayLength); // 'array' is passed along its address in memory. Hence, its implementation is ALWAYS by reference without including the & sign.
    // The array 'array' has been fully initialized. Along with 'ArrayLength

    // Note: 'ArrayLength' will only serve as the condition of the for-loops.
    NumberToCheck = ReadNumberToCheck("Enter number to check: ");  // Range NOT included as its value is NOT inbtrinsic

    PrintResults(array, NumberToCheck, ArrayLength);

    return 0;
}













/*   The Array (Fixed-length data structure) Mental Model:

     The re-usable array utility is as follows:



 int ReadIntegerNumber(const string& message)
 {
    int number;

    cout << message;
    cin >> number;
    cout << endl;

    return number;
 }

 bool ValidateLengthInRange(const int& number, int min, int may)
 {
    return (min <= number && number <= max);
 }


 int ReadArrayLength(const string &message, int min, int max)
 {
    int count = 0;
    int number;

    do
     {
        count++;
        if (count > 1)
        {
            cout << "Error- Number must be between " << min << " & " << max << endl; 
        }

        number = ReadIntegerNumber(message);

     } while (!ValidateLengthInRange(number, min, max));

    return number;
 }


int ReadIntegerNumberElement(const string& message, int i)
 {
    int number;

    cout << message << "[" << i << "]";
    cin >> number;
    cout << endl;

    return number;
 }



bool ValidateBiggerOrEqualZeroInteger(const int& element)
 {
    return (element >= 0);
 }


void ReadArray(string message, int array[], int& ArrayLength)   // the array is ALWAYS passed by ref. (including the & renders exception).
 {
    bool validate;   // added at the very end when it was needed    // using the count way, for the error message, doesn't work when implementing the for-loop.

    short min = 1;       // we want the array to at least have one element.
    short max = 100;    // is the max number the array can hold.
    ArrayLength = ReadArrayLength("Enter number of array elements: ", min, max);  // Ranges INCLUDED as their values are INTRINSIC.



    for (int i = 0; i < ArrayLength; i++)
     {

        do
         {
            array[i] = ReadIntegerNumberElement(message, i);   // to distinguish it from   ReadIntegerNumber

            validate = ValidateBiggerOrEqualZeroInteger(array[i]);

            if (!validate)
            {
                cout << "Error - Element value can't be negative. ";                    
            }

        } while (!validate);  // I decided that only 0 and positive array elements are acceptable; make your own decision.
    }

 }



int main()
 {
    int array[100], ArrayLength;    // declared an array that can hold up to 100 elements.
    // Initializing the above variableS via reading user-input (Using Procedure - since an array contains MORE than one element):

    ReadArray("Enter Element ", array, ArrayLength); // 'array' is passed along its address in memory. Hence, its implementation is ALWAYS by reference without including the & sign.
    // The array variable 'array'  &  the normnal variable 'ArrayLength' are now initialized. 

  
    **From now and on the ArrayLength variable will be used in the condition of the for-loopS**

    return 0;
 }






                              ///////////////////////////////////////////////////////////////////////////////////////////////////////
                          ##### Now if the values to fill the array with are random numbers from, for example, 346  to 666, then we will have:
                              ///////////////////////////////////////////////////////////////////////////////////////////////////////


  void FillArrayWithRandomNumbers(string message, int array[], int& ArrayLength)    // Change the procedure's method from ReadArray.
  {
   
    short min = 1;
    short max = 100;    // is the max number the array can hold.
    ArrayLength = ReadArrayLength("Enter number of array elements: ", min, max);  


    for (int i = 0; i < ArrayLength; i++)
    {
       array[i] = ReadRandomNumberInRange(346, 666);        // our CORE INEVITABLE random function utility, that should ALWAYS return an integer
    }

 }

    Notice that there is no do-while loop inside the for-loop.

    This is because there is no user input (or any other external input)
    that must be validated immediately.

    Instead, each value is produced by GenerateRandomNumberInRange(),
    which is designed to always return a number within the specified
    range (346 to 666). Therefore, additional validation is unnecessary.


 ---


 int main()
 {
    int array[100], ArrayLength;    // declared an array that can hold up to 100 elements.
    // Initializing the above variableS via reading user-input (Using Procedure - since an array contains MORE than one element):

    FillArrayWithRandomElements(array, ArrayLength);  // no msg included as random numbers will fill up the array instead of prompting the user to enter values.
    // The array variable 'array'  &  the normnal variable 'ArrayLength' are now initialized.


    **From now and on the ArrayLength variable will be used in the condition of the for-loopS**

    return 0;
 }

  
       
*/













