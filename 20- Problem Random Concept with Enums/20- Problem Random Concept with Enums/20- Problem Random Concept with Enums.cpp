
#include <iostream>
#include <cstdlib>
using namespace std;

/*
 Problem #20:

 Write a program to print random:

  - small letter,
  - capital letter,
  - special character,
  - digit

  All in order.

 Output:

 i
 G
 $
 7


*/




                   /**********ALWAYS start the program with ENUMS for random numbers**********
                   ********** ALWAYS start the program with ENUMS for random numbers*********/


enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, digit = 4 };
// the enumeration constants (enumerators), [that are SmallLetter, CapitalLetter, etc.], act as labels for the raw integral values they represent.
// Therefore- FOREVER FORGET about these raw values and ALWAYS deal with their labels.
// 
// So far, only an enum user-defined data type has been created and nothing more.
// the next natural step, is creating a variable of this enum user-defined data type in MAIN()


int GenerateRandomNumberInRange(int from, int to)  // MUST BE A UTILITY THAT ALWAYS return an integer  // generates a random integer number ranging from: 'from'   to   'to'.
{
	return (rand() % (to - from + 1) + from);
}


char GenerateRandomCharacter(enCharType CharType)    // pass by value.  // MUST BE A UTILITY
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(GenerateRandomNumberInRange(97, 122));

	case enCharType::CapitalLetter:
		return char(GenerateRandomNumberInRange(65, 90));

	case enCharType::SpecialCharacter:
		return char(GenerateRandomNumberInRange(33, 47));

	case enCharType::digit:
		return char(GenerateRandomNumberInRange(48, 57));
	}
}


int main()
{
	srand((unsigned)time(NULL));  // to initialize the random number generator.

	//enCharType CharType;   // the next natural step is creating a variable of the enum user-defined data type.
    // commented out - turned out you can simply send its different values as arguments as illustrated below:
	// Otherwise- Variable CharType can only take one value (Ex:  CharType = enCharType::smallLetter), so for another value, the name of the variable has to be something different.


	cout << GenerateRandomCharacter(enCharType::SmallLetter) << endl;      // the argument equates to 1 (of data type  enCharType).
	cout << GenerateRandomCharacter(enCharType::CapitalLetter) << endl;    // the argument equates to 2 (of data type  enCharType).
	cout << GenerateRandomCharacter(enCharType::SpecialCharacter) << endl; // the argument equates to 3 (of data type  enCharType).
	cout << GenerateRandomCharacter(enCharType::digit) << endl << endl;    // the argument equates to 4 (of data type  enCharType).

	// each argument is equivalent to what the user enters. Instead, here it's initialized directly in main, 
	// so that it can be used as the argument of a switch statement that's compared against the enumeration constants(enumerators) that we have since the enum creation step

	return 0;
}





























































