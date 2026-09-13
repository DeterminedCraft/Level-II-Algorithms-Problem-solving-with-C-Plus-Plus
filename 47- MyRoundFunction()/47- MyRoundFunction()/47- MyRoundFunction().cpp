
#include <iostream>
#include <cmath>     // for round(), abs(), floor(9, ceil()
using namespace std;

/*
 Problem #47
 Write a program to print round of numbers, don't use the built‑in round function.

 Input: 10.7                    Input: 10.3                   Input: -10.7
 My Round Result: 11            My Round Result: 10           My Round Result: -11
 C++ Round Result: 11           C++ Round Result: 10          C++ Round Result: -11

 Input: 10.5                    Input: 10                   Input: -10
 My Round Result: 11            My Round Result: 10           My Round Result: -10
 C++ Round Result: 11           C++ Round Result: 10          C++ Round Result: -10

*/




float ReadNumber(const string& message)  // Again -  // I choose not to have range validation for user input.
{
	float number; // waht's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}


int ExtractIntegerPart(float number)   // pass by value
{
	return (int)number;
}


float ExtractDecimalPart(float number, int IntegerPart)    // pass by value
{
	return number - (float)IntegerPart;    // explicitly casting to float instead of relying on the compiler's implicit conversion.
}


int CustomRound(float number)   // pass by value
{
	int IntegerPart = ExtractIntegerPart(number);
	float DecimalPart = ExtractDecimalPart(number, IntegerPart);

	if (abs(DecimalPart) >= 0.5)    // using abs() as the decimal could be positive or negative (Just how the integer part could be positive or negative).
	{
		if (number > 0)
		{
			return IntegerPart + 1;   // or:    return ++IntegerPart;    WARNING: return IntegerPart++ is FATAL  as IntegerPart will be returned. Then, IntegerPart is later incremented by 1
		}

		else if (number < 0)
		{
			return IntegerPart - 1;   // or:    return --IntegerPart;    WARNING: return IntegerPart-- is FATAL  as IntegerPart will be returned. Then, IntegerPart is later decremented by 1
		}
	}

	return IntegerPart;   // in any case where the decimal is less than 0.5   


}


int main()
{
	float number = ReadNumber("Enter a number: ");  // I choose not to have range validation for user input.

	int RoundedValue = CustomRound(number);    // just how we have a built-in round() function, where you pass the number to it.
	cout << "my Custom Round result: " << RoundedValue << endl;

	cout << "C++ Rounding Result: " << round(number) << endl<<endl;


	return 0;
}





// Old brainstorming inside the  int CustomRound(float number)
/* Example:   -11.7

       I'll extract -11:           (int)-11.7  = -11
       then, extract the decimal:  -11.7 - (-11)  = -0.7   
*/

















