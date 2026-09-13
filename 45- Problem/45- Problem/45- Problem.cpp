
#include <iostream>
using namespace std;

/*
 Problem #45

 Write a program to fill array with max size 100 with random
 numbers from -100 to 100, then print the count of Negative
 numbers.


 Input:

 Enter the number of random numbers to fill the array with ?: 10


 Output:

 Array Elements: 17 -9 -9 -90 -72 -100 -4 60 -84 -15

 Negative Numbers count is: 8

*/




int ReadIntegerNumber(const string& message)
{
	int number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}



bool ValidateIntegerInRange(const int& number, int MinLength, int MaxLength)
{
	return (MinLength <= number && number <= MaxLength);
}



int ReadIntegerInRange(const string& message, int MinLength, int MaxLength)
{
	int number; // what's returned.

	number = ReadIntegerNumber(message);

	while (!ValidateIntegerInRange(number, MinLength, MaxLength))
	{
		cout << "Error- Value entered must be between " << MinLength << " & " << MaxLength << endl;
		number = ReadIntegerNumber(message);
	}

	return number;
}


int GenerateRandomIntegerInRange(int from, int to)
{
	return rand() % (to - from + 1) + from;
}


void FillArrayWithRandomNumbers(int array[], int& ArrayLength)
{
	int MinLength = 1;
	int MaxLength = 100;
	ArrayLength = ReadIntegerInRange("Enter the number of random numbers to fill the array with ?: ", MinLength, MaxLength);

	for (int i = 0; i < ArrayLength; i++)
	{
		array[i] = GenerateRandomIntegerInRange(-100, 100);  // our CORE INEVITABLE random function for generating random numbers. In the implementation it MUST return integer.
	}
}





void PrintArray(const int array[], const int& ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\n\n";
}


bool IsNumberNegative(int number)
{
	return (number < 0);
}



int CalculateCountOfNegativeNumbersInArray(int array[], int ArrayLength)   // pass by value
{
	int count = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (IsNumberNegative(array[i]))
		{
			count++;
		}
	}

	return count;
}


int main()
{

	srand((unsigned)time(NULL));  // for seeding random numbers.

	int array[100], ArrayLength;
	FillArrayWithRandomNumbers(array, ArrayLength);
	// 'array' & 'ArrayLength' are now initialized.

	
	int CountOfnegativeNumbersInArray = CalculateCountOfNegativeNumbersInArray(array, ArrayLength);

	cout << "Array elements: ";
	PrintArray(array, ArrayLength);

	cout << "Negative Numbers count is: " << CountOfnegativeNumbersInArray << endl << endl;


	return 0;
}



