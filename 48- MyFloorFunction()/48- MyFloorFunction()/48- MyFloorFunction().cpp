
#include <iostream>
#include <cmath>
using namespace std;

/*
 Problem #48 — Write a program to print floor of numbers, don't use the built‑in floor function.

 Input: 10.7  
 My MyFloor Result: 10   C++ floor Result: 10


 Input: 10.3  
 My MyFloor Result: 10   C++ floor Result: 10


 Input: -10.3  
 My MyFloor Result: -11  C++ floor Result: -11

 Input: 2
 My MyFloor Result: 2  C++ floor Result: 2

 Input: -2
 My MyFloor Result: -2  C++ floor Result: -2



 NOTE** The floor function means: Return the integer that is less than or equal to the number.

*/



float ReadNumber(const string& message)   // Again - I choose to not range validate the user input.
{
	float number; // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}

int ExtractIntegerPart(float number)
{
	return (int)number;
}

float ExtractDecimalPart(float number, int IntegerPart)    // pass by value.
{
	return number - (float)IntegerPart;    // casting to float instead of relying on the compiler's implicit conversion.  // PLUS- for readability and intent.
}


int CustomFloor(float number)   // pass by value.
{
	int IntegerPart = ExtractIntegerPart(number);
	float DecimalPart = ExtractDecimalPart(number, IntegerPart);

	if (DecimalPart == 0)
	{
		return IntegerPart;    // or return (int)number
	}
	else if (number > 0)    // if program reaches here, then the decimal is something other than 0.
	{
		return IntegerPart;
	}
	else if (number < 0)
	{
		return IntegerPart - 1;
	}

	// Added only to satisfy the compiler.
	return IntegerPart;
	//Even though this line is never reached for valid inputs, it prevents "control reaches end of non-void function" warnings.
}


int main()
{
	float number = ReadNumber("Enter a number: "); // I choose to not range validate the user input.

	int FloorValue = CustomFloor(number);
	cout << " My MyFloor Result: " << FloorValue << endl;

	cout << "C++ floor Result : " << floor(number) << endl << endl;

	return 0;
}


// Another equally valid suggestion:

/* if (abs(ExtractedDecimal) > 0)
	{
		if (number > 0)
		{
			return ExtractedInteger;
		}
		else
		{
			return ExtractedInteger - 1;
		}
	}

	return number;   // or return IntegerPart;
*/



























