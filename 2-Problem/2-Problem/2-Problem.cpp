
#include <iostream>
using namespace std;

/*
 Problem #2:
 Write a program that prints all prime numbers from 1 to N.

 Input:
 10

 Output:
 1
 2
 3
 5
 7

*/




/*
 Solution: 
 So a prime number is ONLY divisible by itself and 1 and not by any number that precedes it.
 meaning - when divided, then the remainder will not be equal to zero.

 since the remainder value represents whether the number is prime or not prime
 and since it's not involved in any subsequent arithmetic operations ( /, *, -, +)
 then the concept of enums should be utilized.

 Enums are to be CODED FIRST and before anything else in the program.
 If structures are followed, then the structure may included the enum variable as a member variable (Only when it's correct/ logical to do so).


*/




enum enPrimeOrNot { Prime = 1, NotPrime = 0 };   // the enumeration constants (enumerators) that are Prime & NotPrime act as labels for the raw integral values they represent,
// so FOREVER forget about these raw values and ALWAYS use their labels.
// so far, only an enum user-defined data type has been created and nothing more.-
// the next natural step, is creating a variable of this enum user-defined data type in main()



int ReadNumber(const string& message)   // pass by const. ref.
{
    int number;  // what's returned.

    cout << message;
    cin >> number;
    cout << "\n";

    return number;
}

bool ValidatePositiveNumber(const int& number)   // pass by constant ref. as 'number' is ONLY used for comparison against the range
{
    return (number > 0);
}

int ReadPositiveNumber(const string& message)    // pass by constant reference.
{
    int counter = 0;

    int number;  // what's returned

    do
    {
        counter++;
        if (counter > 1)
        {
            cout << "Error. Only a positive value is accepted. ";
        }

        number = ReadNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidatePositiveNumber(number));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return number;
}





enPrimeOrNot DeterminePrimeOrNot(int number)   // pass by value.
{

    int m = round(number / 2.0);       // instead of dividing on all numbers to find out if this single number (existing in 1 to N) is prime or not (makes the code faster & more efficient).
    
    for (int i = m; i > 1; i--)
    {
        if (number % i == 0)
        {
            return enPrimeOrNot::NotPrime;
        }
    }
    

    if (number == 1)   // better to move it to the top in this function.
    {
        return enPrimeOrNot::NotPrime;   // 1 is NOT a prime number (controversial but true).
    }

    return enPrimeOrNot::Prime;
}

/*  // without dividing the inputed number by half:
    for (int i = number - 1; i > 1; i--)
    {
        if (number % i == 0)
        {
            return enPrimeOrNot::NotPrime;
        }
    }
*/


void PrintPrimeNumbersFrom1ToN(const int& N)   // pass by constant reference.
{
    for (int i = 1; i <= N; i++)
    {
        if (DeterminePrimeOrNot(i) == enPrimeOrNot::Prime)   // right-hand side equates to 1 (of data type enPrimeOrNot).
        {
            cout << i << endl;
        }
    }
}




int main()
{
    // enPrimeOrNot PrimeOrNot;   // the next natural step of creating a variable of the enum user-defined data type. // commented out as it turned out that it was not needed,

    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Enter a positive number: ")); // Range NOT included as its value is NOT intrinsic.



    return 0;
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//// Old Unoptimized solution:
//enum enPrimeOrNot { Prime = 1, NotPrime = 0};   // the enumeration constants (enumerators) that are Prime & NotPrime act as labels for the raw integral values they represent,
//// so FOREVER forget about these raw values and ALWAYS use their labels.
//// so far, only an enum user-defined data type has been created and nothing more.-
//// the next natural step, is creating a variable of this enum user-defined data type in main()
//
//
//
//int ReadNumber(const string& message)   // pass by const. ref.
//{
//    int number;  // what's returned.
//
//    cout << message;
//    cin >> number;
//    cout << "\n";
//
//    return number;
//}
//
//bool ValidatePositiveNumber(const int& number)   // pass by constant ref. as 'number' is ONLY used for comparison against the range
//{
//    return (number > 0);
//}
//
//int ReadPositiveNumber(const string& message)    // pass by constant reference.
//{
//    int counter = 0;
//
//    int number;  // what's returned
//
//    do
//    {
//        counter++; 
//        if (counter > 1)
//        {
//            cout << "Error. Only a positive value is accepted. ";
//        }
//
//        number = ReadNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition.
//
//    } while (!ValidatePositiveNumber(number));  // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//    return number;
//}
//
//
//
//enPrimeOrNot DeterminePrimeOrNot(int number)     // pass by value
//{   
//    /*
//    for (int i = number-1; i > 1; i--)
//    {
//        if (number % i == 0)
//        {
//            return enPrimeOrNot::NotPrime;
//        }
//    }
//    */
//    for (int i = 2; i < number; i++)
//    {
//        if (number % i == 0)
//        {
//            return enPrimeOrNot::NotPrime;
//        }
//    }
//    return enPrimeOrNot::Prime;
//}
//
//
//void PrintPrimeNumbersFrom1ToN(const int& N)
//{
//    for (int i = 1; i <= N; i++)
//    {
//        if (DeterminePrimeOrNot(i) == enPrimeOrNot::Prime)   // Right-hand side equates to 1 (of enPrimeOrNot data type).
//        {
//            cout << i << endl;   // prints the prime number.
//        }
//        
//    }
//}
//
//
//
//
//int main()
//{
//   // enPrimeOrNot PrimeOrNot;   // the next natural step of creating a variable of the enum user-defined data type.
//
//    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Enter a positive number: ")); // Range NOT included as its value is NOT intrinsic.
//
//
//
//    return 0;
//}

