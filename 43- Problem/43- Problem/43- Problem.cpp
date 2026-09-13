
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

/*
 Problem #43

 Write a program to fill array with max size 100 with random
 numbers from 1 to 100, then print the count of Even numbers.


 Input:
 10


 Output:
 Array Elements: 14 92 70 15 58 76 84 62 10 43

 Even Numbers count is: 8


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




bool IsNumberEven(int number)   // pass by value
{
	return (number % 2 == 0);
}

enEvenOrOdd CheckNumberEvenOrOdd(int number)   // pass by value
{
	if (IsNumberEven(number))   // no matter how small   'number % 2 == 0'   is, always wrap it in its own a function
	{
		return enEvenOrOdd::Even;
	}
	else
	{
		return enEvenOrOdd::Odd;
	}
}



int NumberOfEvenNumbersInArray(int array[], int ArrayLength)   // pass by value
{
	int count = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckNumberEvenOrOdd(array[i]) == enEvenOrOdd::Even)
		{
			count++;
		}
	}
	return count;
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


	int CountOfEvenNumbersInArray = NumberOfEvenNumbersInArray(array, ArrayLength);



	cout << "Array Elements: ";
	PrintArray(array, ArrayLength);

	

	cout << "Even Number count is: " << CountOfEvenNumbersInArray << endl;


	return 0;
}










