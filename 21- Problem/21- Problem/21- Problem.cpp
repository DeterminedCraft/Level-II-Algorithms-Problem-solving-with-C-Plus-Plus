
#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Problem #21:
    Write a program to read how many keys to generate and print
    them on the screen.

    Input:
    5

    Output:
    Key [1] : ETAI-HJUV-PEIP-CFRX
    Key [2] : UMCO-YSPQ-PHYK-STIL
    Key [3] : QBSR-MZEC-BYNA-DSYK
    Key [4] : MISQ-ULYB-ZRAZ-LMAG
    Key [5] : NQCR-PPFJ-KZLF-ZHMT
*/



/*********** ALWAYS start the program with ENUMS for random numbers**********
 *********** ALWAYS start the program with ENUMS for random numbers**********/



enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, digit = 4 };


int ReadIntegerNumber(const string message)
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}



bool ValidatePositiveInteger(const int& number)   // pass by constant ref. since 'number' is ONLY used for validation against the range.
{
    return (number > 0);
}



int ReadPositiveInteger(const string& message)   // pass by constant reference.
{
    int number;   // what's returned

    number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition

    while (!ValidatePositiveInteger(number))  // the condition is written so that it evaluates to true when the condition is INVALID.
    {
        cout << "Error- only positive value is accepted. ";
        number = ReadIntegerNumber(message);
    }

    return number;
    /* The above block of code is to be sequentially composed line by line & at the end,
    implement the functions of:  ReadIntegerNumber()    &  ValidatePositiveInteger()   */
}



int GenerateRandomNumberInRange(int from, int to)   // pass by value
{
    return rand() % (to - from + 1) + from;
}


char GenerateRandomCharacter(enCharType CharType)  // pass by value   // SHOULD be a utility.
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(GenerateRandomNumberInRange(97,122));

    case enCharType::CapitalLetter:
        return char(GenerateRandomNumberInRange(65, 90));

    case enCharType::SpecialCharacter:
        return char(GenerateRandomNumberInRange(33, 47));

    case enCharType::digit:
        return char(GenerateRandomNumberInRange(48, 57));
    }
}


string GenerateWord(enCharType CharType, short length)     // pass by value
{
    string word = "";

    for (int i = 1; i <= length; i++)
    {
        word = word + GenerateRandomCharacter(CharType);    // our MUST core random function    GenerateRandomNumberInRange()
    }

    return word;
}


string GenerateKey()
{
    string key = "";     //  ETAI-HJUV-PEIP-CFRX

    key = GenerateWord(enCharType::CapitalLetter, 4) + "-";          // the argument equates to 1 ( of data type enCharType).   
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";   // the argument equates to 1 ( of data type enCharType).
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";  // the argument equates to 1 ( of data type enCharType).
    key = key + GenerateWord(enCharType::CapitalLetter, 4);       // the argument equates to 1 ( of data type enCharType).
    // the number represents the length of each word.
    return key;
}



void PrintGeneratedKeys(const int& number)      // pass by constant reference.
{

    for (int i = 1; i <= number; i++)
    {
        cout << "Key[" << i << "]" << " : " << GenerateKey() << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL)); // to seed the randon number generator. Added ONCE inside main(). 

    //enCharType CharType;   // the next natural step of creating a variable of the enum user-defined data type.  // commented out as it turned out it was not needed.

    PrintGeneratedKeys(ReadPositiveInteger("Enter a positive number: "));  // Range NOT added as its value is NOT intrinsic.

    return 0;
}





















//
//
/////////// My first-attempt solution:
/////////// My first-attempt solution:
/////////// My first-attempt solution:
/////////// My first-attempt solution:
//
//enum enCharType { CapitalLetter = 1};
//
//int ReadIntegerNumber(const string message)
//{
//    int number;  // what's returned.
//
//    cout << message;
//    cin >> number;
//    cout << endl;
//
//    return number;
//}
//
//bool ValidatePositiveInteger(const int& number)   // pass by constant ref. since 'number' is ONLY used for validation against the range.
//{
//    return (number > 0);
//}
//
//int ReadPositiveInteger(const string& message)   // pass by constant reference.
//{
//    int number;   // what's returned
//
//    number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition
//
//    while (!ValidatePositiveInteger(number))  // the condition is written so that it evaluates to true when the condition is INVALID.
//    {
//        cout << "Error- only positive value is accepted. ";
//        number = ReadIntegerNumber(message);
//    }
//
//    return number;
//    /* The above block of code is to be sequentially composed line by line & at the end,
//    implement the functions of:  ReadIntegerNumber()    &  ValidatePositiveInteger()   */
//
//}
//
//
//string GenerateRandomWord(int from, int to)   // at the end the name of this IMPERATIVE CORE FUNCTION was changed from "GenerateRandomNumberInRange" since we modified this utility to fulfill our needs.
//{
//    string RandWord = "";
//    
//    for (int i = 1; i <= 4; i++)
//    {
//        RandWord += char(rand() % (to - from + 1) + from);    // RandWord = RandWord + char(rand() % (to - from + 1) + from);
//    }
//
//    return RandWord;
//    
//   
//
//}
//
//
//string GenerateRandomCombination(enCharType CharType)   // pass by value
//{
//    switch (CharType)
//    {
//    case enCharType::CapitalLetter:
//        return GenerateRandomWord(65,90);
//
//    default:
//            return "";
//
//    }
//}
//
//
//int main()
//{
//    srand((unsigned)time(NULL));   // seeding the random number generator. Without this, you'll get the same "random" keys every time you run the program.
//   // Initializing the below variable via reading user-input:
//
//    int number = ReadPositiveInteger("How many keys to generate ?: ");  // Range NOT included as its value is NOT intrinsic.
///*       |
//         |---> to be typoed at the very end, after finishing typing the "return" keyboard    */
//   
//    for (int i = 1; i <= number; i++)
//    {
//        cout << "Key[" << i << "] : " << GenerateRandomCombination(enCharType::CapitalLetter) << "-"       // the argument equates to 1 (of data type enCharType).
//                                      << GenerateRandomCombination(enCharType::CapitalLetter) << "-"      // the argument equates to 1 (of data type enCharType).
//                                      << GenerateRandomCombination(enCharType::CapitalLetter) << "-"     // the argument equates to 1 (of data type enCharType).
//                                      << GenerateRandomCombination(enCharType::CapitalLetter) << endl;    // the argument equates to 1 (of data type enCharType).
//    }
//
//    return 0;
//}


