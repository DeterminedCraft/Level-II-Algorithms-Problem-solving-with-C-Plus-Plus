
#include <iostream>
using namespace std;


/*
 Problem #9:
 Write a program read a number, then print all digit frequency in that number

 Input:
 1223222

 Output:
 Digit 1 Frequency is 1 Time(s).
 Digit 2 Frequency is 5 Time(s).
 Digit 3 Frequency is 1 Time(s).


*/








int ReadIntegerNumber(const string& message)
{
	int number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}


bool ValidatePositiveNumber(const int& number)   // pass by constant reference since 'number' is going to be ONLY used for comparison against the range
{
	return (number > 0);
}



int ReadPositiveNumber(const string& message)   // pass by constant reference.
{
	int number; // what's returned.

	number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validate against the range, in the while condition.

	while (!ValidatePositiveNumber(number))   // the condition is written so that, it evaluates to TRUE when the condition is INVALID.
	{
		cout << "Error. Only positive numbers allowed. ";
		number = ReadIntegerNumber(message);
	}

	return number;
}



int CalculateDigitFrequency(int i, int number)    // pass by value.
{
	int count = 0;  // added at the very end, when it was needed.
	int remainder = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;

		if (remainder == i)
		{
			count++;
		}
	}

	return count;
}


void PrintDigitsFrequencyInNumber(const int& number)     // pass by constant reference
{
	for (int i = 0; i < 10; i++)
	{
		int DigitFrequency = CalculateDigitFrequency(i, number);
		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency is " << DigitFrequency << endl;
		}

		
	}
}





int main()
{
   
	PrintDigitsFrequencyInNumber(ReadPositiveNumber("Enter a number: "));  // Range NOT included as its value is NOT intrinsic.


	return 0;
}











































