
#include <iostream>
#include <string>
using namespace std;

/*
 Problem #7
 Write a program to read a number and print it reversed.

 Input:
 1234

 Output:

 Reverse is:
 4321


*/

int ReadIntegerNumber(const string& message)   // pass by const. ref.
{
	int number;   // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveNumber(const int& number)  // pass by constant reference since 'number' is ONLY used for validation against the range.
{
	return (number > 0);
}



int ReadPositiveNumber(const string& message)   // passing by constant reference
{
	int number;  // what's returned.

	number = ReadIntegerNumber(message);   // 'number' is IMMEDIATELY validated against the range, in the while condition.

	while (!ValidatePositiveNumber(number))    // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
	{
		cout << "Error. Only positive number is allowed. ";
		number = ReadIntegerNumber(message);
	}

	return number;
	
	// Note: The above block of code is to be sequentially composed line by line, and
	//       at the end, implement the functions of ReadIntegerNumber()  & ValidatePositiveNumber()
}

int ReversingTheNumber(int number)    // pass by value.
{
	int reverse = 0;    // routine
    
	int remainder = 0;
	while (number > 0)
	{
	    remainder = number % 10;
		number = number / 10;
		reverse = (reverse * 10) + remainder; 
	}

	return reverse;

}



void PrintingTheReversedNumber(const  int &number)   // pass by constant reference.
{
	cout << "Reverse is: \n" << ReversingTheNumber(number) << endl;
}


int main()
{
   
	PrintingTheReversedNumber(ReadPositiveNumber("Enter number: "));    // Range NOT included as its value is NOT intrinsic.

	return 0;
}


