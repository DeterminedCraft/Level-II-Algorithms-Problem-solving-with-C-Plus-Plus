
#include <iostream>
using namespace std;
#include <string>

/*
 Problem #5:

  Write a program to read a number and print it in a reversed order.

  Input:
  1234

  Output:
  4
  3
  2
  1

*/




int ReadIntegerNumber(const string& message)   // pass by const ref.
{
	int number;  // what's returned.

	cout << message;
	cin >> number;
	cout << "\n";

	return number;
}


bool ValidatePositiveInteger(const int& number)   // pass by const ref since 'number' is ONLY used for comparison against the range.
{
	return (number > 0);
}

int ReadPositiveInteger(const string& message)   // pass by const. ref.
{
	bool validation;
	int number; // what's returned

	do
	{
		number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated againt the range, in the while condition.

		validation = ValidatePositiveInteger(number);
		if (!validation)
		{
			cout << "Error. Only positive numbers allowed. ";
		}

	} while (!validation);   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

	return number;

	// the above block of code is to be sequentially composed line by line and at the end, $
	// implement the functions of: ReadIntegerNumber()   &   ValidatePositiveInteger()
}


void PrintNumberInReverse( int number)
{
	int remainder = 0;  // initialize it. Otherwise, garbage values are stored.

	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;
		cout << remainder << endl;
	}

}


int main()
{
	 
	PrintNumberInReverse(ReadPositiveInteger("Enter a positive number: "));  // Range NOT included as its value is NOT intrinsic.

	return 0;
}

























//
//bool ValidateValueLength(const string& value, size_t MinChar)   // pass by constant reference as 'value' is ONLY used for comparison.
//{
//	return (value.length() >= MinChar);
//}
//
//string ReadStringValue(const string& message)  //  pass by constant  reference
//{
//	string value;  // what's returned
//
//	cout << message;
//	getline(cin, value);
//	cout << endl;
//
//	return value;
//}
//
//
//
//string ReadString(const string &message, size_t MinChar)  // pass by constant reference.   // Range ALWAYS passed by value.
//{
//	int counter = 0;
//	string value;  // what's returned.
//
//	do
//	{
//		counter++;
//		if (counter > 1)
//		{
//			cout << "Error. The number/characters entered must be at least " << MinChar << " digits/characters.\n";
//		}
//
//		value = ReadStringValue(message);    // 'value' is to be IMMEDIATELY validated against the range, in the while condition.
//
//	} while (!ValidateValueLength(value, MinChar));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.
//
//	return value; 
//
//	// the above code block is to be sequentially composed line by line, & at the end implement the functions: ReadStringValue()   &  ValidateValueLength()
//}
//
//  
// void PrintReversedNumber(const string& value)   // pass by constant ref.
//{
//	for (int i = (int)value.length() - 1; i >= 0; i--)    // casting explicitly rather than depending on the compiler to implicitly do so.
//	{
//		cout << value[i] << endl;
//	}
//}
//
//
//
//int main()
//{
//	size_t MinChar = 2;    // size_t  as .length() returns a number of size_t data type.
//
//	PrintReversedNumber(ReadString("Enter a number: ", MinChar));   // Including the range 'MinChar' as the value is INTRINSIC.
//
//	return 0;
//}


