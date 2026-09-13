
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


/*
 Problem #42

 Write a program to fill an array with max size 100 with random
 numbers from 1 to 100, then print the count of Odd numbers.


 Input:
 How many random numbers to fill up the array with ?: 10


 Output:
 Array Elements: 60 78 15 49 56 6 4 3 21 23

 Odd Numbers count is: 5


*/

enum enEvenOrOdd { Even = 0, Odd = 1 }; // the enumeration constants (enumerators) that are Even & Odd, act as labels for the raw integral values they represent,
// so FOREVER FORGET about these raw values and always deal with their labels.
// so far, only an enum user-defined data type has been created and nothing more.
// the next natural step is creating a variable of this enum user-defined data type in main()



int ReadIntegerNumber(const string& message)
{
	int number;  // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}


bool ValidateIntegerInRange(const int& number, int MinLength, int MaxLength) // 'number' is passed by const ref. since it's ONLY used for comparison.
{
	return (MinLength <= number && number <= MaxLength);
}


int ReadIntegerInRange(const string& message, int MinLength, int MaxLength)  // Ranges ALWAYS passed by ref.
{
	int number;  // what's returned.

	do
	{
		number = ReadIntegerNumber(message); // 'number' is to be IMMEDIATELY validated against the range. in the while condition.

	} while (!ValidateIntegerInRange(number, MinLength, MaxLength));

	return number;
	// The above block of code is to be sequentially composed line by line, & at the end implement all the functions.
}


int GenerateRandomNumberInRange(int from, int to)   // pass by value
{
	return rand() % (to - from + 1) + from;
}


void FillArrayWithRandomNumbers(int array[], int& ArrayLength)   // arrays are AUTOMATICALLY passed by ref without including the & sign ( = renders exception).
{
	int MinLength = 1;  // we want at least one element in the array.
	int MaxLength = 100; // and up to the max capacity of the array.

	ArrayLength = ReadIntegerInRange("How many random numbers to fill the array with ?: ", MinLength, MaxLength);

	for (int i = 0; i < ArrayLength; i++)
	{
		array[i] = GenerateRandomNumberInRange(1, 100);   // our CORE INEVITABLE utility for generating random number. it's implemented so it ALWAYS return an integer.
	}
}



bool IsNumberOdd(int number)   // pass by value.
{
	return (number % 2 !=0);
}



enEvenOrOdd CheckIfEvenOrOdd(int number)   // pass by value
{
	if (IsNumberOdd(number))    // no matter how small   'number % 2 == 0'   is, always wrap it in its own a function
	{
		return enEvenOrOdd::Odd;
	}
	else
	{
		return enEvenOrOdd::Even;
	}
}




int CalculateNumberOfOddNumbersInArray(int array[], int ArrayLength)   // pass by value.
{
	int count = 0; 

	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckIfEvenOrOdd(array[i]) == enEvenOrOdd::Odd)    // to the right-side of the = operator, it equates to 1 (of data type enEvenOrOdd).
		{
			count++;
		}
	}

	return count;
	// this block of code is to be sequentially composed line by line, & at the end implement all the functions.
}


void PrintArray(const int array[], const int& ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << endl;
}



int main()
{
	srand((unsigned)time(NULL));  // to seed random numbers.

	//enEvenOrOdd EvenOrOdd; // // commented out as it turned out it was not neded //the next natural step of creating a variable of the enum user defined data type.

	int array[100], ArrayLength;
	FillArrayWithRandomNumbers(array, ArrayLength);
	// 'array'  and 'arrayLength' are now initialized.

	int NumberOfOddNumbers = CalculateNumberOfOddNumbersInArray(array, ArrayLength);

	cout << "Array Elements: ";
	PrintArray(array, ArrayLength);

	cout << "Odd Number count is: " << NumberOfOddNumbers << endl;


	return 0;
}













////////// Without enums (The optimized solution should be utilizing enums as shown above):
////////// Without enums (The optimized solution should be utilizing enums as shown above):

//int ReadIntegerNumber(const string& message)
//{
//	int number;  // what's returned
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//
//
//bool ValidateNumberInRange(const int& number, int MinLength, int MaxLength)
//{
//	return (MinLength <= number && number <= MaxLength);
//}
//
//
//
//int ReadNumberInRange(const string& message, int MinLength, int MaxLength)
//{
//	int number;
//
//	do
//	{
//		number = ReadIntegerNumber(message);
//
//	} while (!ValidateNumberInRange(number, MinLength, MaxLength));
//
//	return number;
//}
//
//
//int GenerateRandomNumberInRange(int from, int to)   // pass by value
//{
//	return  rand() % (to - from + 1) + from;
//}
//
//
//void FillArrayWithRandomNumbers(int array[], int& ArrayLength)
//{
//	int MinLength = 1;
//	int MaxLength = 100;
//
//	ArrayLength = ReadNumberInRange("How many random numbers to fill up the array with ?: ", MinLength, MaxLength);
//
//	for (int i = 0; i < ArrayLength; i++)
//	{
//		array[i] = GenerateRandomNumberInRange(1, 100);   // out CORE INEVITABLE utility for geenrating random integers. SHOULD be of integer types.
//	}
//}
//
//bool IsNumberOdd(int number)   // pass by value
//{
//	if (number % 2 == 0)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//int CalculateNumberOfOddNumbersInArray(int array[], int ArrayLength)
//{
//	int count = 0;
//
//	for (int i = 0; i < ArrayLength; i++)
//	{
//		if (IsNumberOdd(array[i]))
//		{
//			count++;
//		}
//	}
//
//	return count;
//}
//
//
//
//void PrintArray(const int array[], const int& ArrayLength)
//{
//	for (int i = 0; i < ArrayLength; i++)
//	{
//		cout << array[i] << " ";
//	}
//
//	cout << endl << endl;
//}
//
//
//
//int main()
//{
//	srand((unsigned)time(NULL));  // to seed randon numbers.
//
//	int array[100], ArrayLength;
//	FillArrayWithRandomNumbers(array, ArrayLength);
//	// 'array'  &  ' ArrayLength' are now initialized.
//
//	int count = CalculateNumberOfOddNumbersInArray(array, ArrayLength);
//
//	cout << "Array Elements: ";
//	PrintArray(array, ArrayLength);
//
//	cout << "Odd Numbers count is: " << count << endl << endl;
//
//
//
//
//	return 0;
//}