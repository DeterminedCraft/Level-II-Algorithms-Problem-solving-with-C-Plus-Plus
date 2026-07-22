
#include <iostream>
#include <cstdlib>;
#include <ctime>
using namespace std;

/*
 Problem #33

 Write a program to read how many keys to generate and fill
 them in array then print them on the screen.


 Input:

 How many keys would you like to generate ?:
 5


 Output:

 Array elements:

 Array[0]: NRXC-DXRO-QEAM-WRWE
 Array[1]: BJTR-KIKF-ATEW-WNTT
 Array[2]: QQFX-KZEL-SSDP-AKSI
 Array[3]: GFOI-ELFX-ZCVE-PSTP
 Array[4]: MATF-PRQA-PQEQ-TRIM

*/






// This example involves random characters. Therefore, we BEGING CODING with enums.
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };



int ReadIntegerNumber(const string& message)
{
    int number;

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}



bool ValidateLengthInRange(const int& number, int min, int max)
{
    return (min <= number && number <= max);
}




int ReadArrayLength(const string& message, int min, int max)
{
    int count = 0;
    int number;  // what's returned.

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error - The number of keys to generate is between " << min << " & " << max << endl;
        }
        number = ReadIntegerNumber(message);

    } while (!ValidateLengthInRange(number, min, max));

    return number;
    // this block of code is to be sequentially composed line by line & at the end, implement all functions in order.
}



int GenerateRandomNumberInRange(int from, int to)  // our CORE INEVITABLE randomness UTILITY that is desinged to ALWAYS return an integer.
{
    return rand() % (to - from + 1) + from;
}



char GenerateRandomCharacter(enCharType CharType)   // pass by value
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(GenerateRandomNumberInRange(97, 122));     // our CORE INEVITABLE randomness UTILITY that is desinged to ALWAYS return an integer.

    case enCharType::CapitalLetter:
        return char(GenerateRandomNumberInRange(65, 90));   // our CORE INEVITABLE randomness UTILITY that is desinged to ALWAYS return an integer. 

    case enCharType::SpecialCharacter:
        return char(GenerateRandomNumberInRange(33, 47));   // our CORE INEVITABLE randomness UTILITY that is desinged to ALWAYS return an integer.

    case enCharType::Digit:
        return char(GenerateRandomNumberInRange(48, 57));  // our CORE INEVITABLE randomness UTILITY that is desinged to ALWAYS return an integer.

    default:                                              // if the argument passed is anything other than the cases' values.
        return '\0';
    }
}

string GenerateWord(enCharType CharType, int WordLength)   // pass by value
{
    string word = "";
    for (int i = 0; i < WordLength; i++)
    {
        word = word + GenerateRandomCharacter(CharType);   // the argument ? ( why not enCharType::CapitalLetter)
    }

    return word;

}


string GenerateKey()
{
    string key = "";

    key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4);

    return key;
}




void FillArrayWithRandomKeys(string keys[], int& ArrayLength)   // arrays are automatically passed by ref without the & sign (including it, renders exception).
{
    int min = 1;  // we^d like to have at least 1 key in the array.
    int max = 100; // array can be filled up with up to 100 keys.
    ArrayLength = ReadArrayLength("How many keys would you like to generate ?: ", min, max);

    for (int i = 0; i < ArrayLength; i++)
    {
        keys[i] = GenerateKey();
    }

    // this block of code is to be sequentially composed line by line & at the end, implement all functions in order.
}



void PrintKeys(const string keys[], const int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "Array[" << i << "]: " << keys[i] << endl;
    }

    cout << endl << endl;
}



int main()
{
    srand((unsigned)time(NULL));   // to seed random numbers.

    //enCharType CharType;  // commented out as it turned out it was needed somewhere else  //the next natural step of declaring a variable of the enum user-defined data type. 

    string keys[100];
    int ArrayLength;
    FillArrayWithRandomKeys(keys, ArrayLength);
    // the array variable 'keys[]'   & 'ArrayLength' are now initialized.

    // Note: 'ArrayLength' will be used in the condition of the for-loop for the 'keys[]' array.

    PrintKeys(keys, ArrayLength);


    return 0;
}


