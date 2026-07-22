
#include <iostream>
using namespace std;



/*  Mental Model:

	"Semi-Dynamic Array". For example:


	 Enter a number: 6
	 Do you want to enter another number ? [0]:No, [1]:Yes? 1


	 Where, when the user enters the first element into the array,
	 the ArrayLength is IMMEDIATELY incremented to 1 so that it reflects
	 the total current number of elements in the array,

	 regardless of whether the user want to continue adding the next number or not.

	 and if the user chooses to enter the second element into the array,
	 then the ArrayLength is IMMEDIATELY incremented to 2 so that it reflects
	 the total current number of elements in the array,

	 regardless of whether the user want to continue adding the next number or not.

	 and so on and so on.

	 **** this is done via the method: ****

	 AddElementToArray(ReadPositiveInteger(message), array, ArrayLength);


		// whose implementation is :


		AddElementToArray(int number, int array[], int ArrayLength )
		{
		  array[ArrayLength] = number;
		  ArrayLength++;
		}


		------------
	 WHERE again the length of the array gets updated IMMEDIATELY after
	 a value is stored in the array (what dynamic reading implies).

	 NOTE: Asking, first, the user to specify how many elements to store is NOT dynamic reading.


	This is done for scenarios when you want to keep on adding a single value
	such as keeping on adding students, keeping on adding patients, keeping on adding cars, etc.

	BUT,

	If we want to store multiple RECORDS (each record contains several fields
	such as name, age, ID, phone, etc. for students or patients for example)

	or
	for cars (car type, car model, car year, etc.),

	or
	for books, etc.  Then STRUCTURES are utilized.


	// CRUCIAL: ENUMS are NEVER used in this mental model.

/*





	Instruction: Just understand the below #1, WITHOUT thinking where it fits into the program's structure
				 (As this will be shown in step #2):

   #1- Start with ArrayLength = 0. It represents the index of the array where the first element will be stored.

						 array[ArrayLength] = value;
   THEN IMMEDIATELY:     ArrayLength++;

	'ArrayLength' first serves as an array index, indicating where the new element should be stored.

	Immediately after the insertion, increment ArrayLength so that
	it serves as the length of the array (= the number of elements currently stored).

	and if the user decides to enter a second number, then
	this incremented ArrayLength serves as the next array index where the second element will be stored.

	Immediately after the insertion, increment ArrayLength so that
	it serves as the length of the array (the number of elements currently stored).

	and so on and so on.


 Example:

 ArrayLength = 0 → add element at index 0 → ArrayLength becomes 1
 ArrayLength = 1 → add element at index 1 → ArrayLength becomes 2
 ArrayLength = 2 → add element at index 2 → ArrayLength becomes 3

 /*

 Before insertion:
 ArrayLength = 0 (next available index)
 ↓
 array[0] = value;
 ArrayLength++;
 ↓
 ArrayLength = 1 (array now contains 1 element)

 Before insertion:
 ArrayLength = 1 (next available index)
 ↓
 array[1] = value;
 ArrayLength++;
 ↓
 ArrayLength = 2 (array now contains 2 elements)

 Before insertion:
 ArrayLength = 2 (next available index)
 ↓
 array[2] = value;
 ArrayLength++;
 ↓
 ArrayLength = 3 (array now contains 3 elements)








   #2: Understand the AddElementToArray procedure:
   *********************************************

 void AddElementToArray(int number, int array[], int &ArrayLength)   // the array is automatically passed by ref.
 {
	array[ArrayLength] = number;
	ArrayLength++;

	// Here there are two ways:
		// For-loops not possible, as this is a dynamic array (user enters a value, then asked if they want to add more values or not).
		// The ArrayLength serves as the index of the array to add the element. Then IMMEDIATELY the ArrayLength has to be incremented by 1 to reflect
		// the current number of elements in the array & to serve as the next index of the array shall the user want to add an additional value.
 }






 #3- You start with the following in main:
 *****************************************



  int main()
  {
	int array[100], ArrayLength = 0;
	ReadArray("Please enter a number ?: ", array, ArrayLength);

	// Once the program reaches here, then 'array' & 'ArrayLength'
	// SHOULD have been already initialized.

	// meaning that

	// this output sample:
	//
	//
		Enter a number: 6
		Do you want to enter another number ? [0]:No, [1]:Yes? 1

   // have already been implemented.

	return 0;
  }





  #4:  And the remaining core structure of this mental model is: ( add the error message layer when solving problems - Here, it's removed for simplicity).
  **************************************************************

   void ReadArray(const string &message, int array[100], int& ArrayLength) // arrays AUTOMATICALLY passed by ref. (Including the & sign renders exception).
   {
	  bool AddMore;

	  do
	  {
		AddElementToArray(ReadPositiveInteger(message), array, ArrayLength);

		AddMore = ReadBoolValue("Do you want to add more numbers? [0]: No, [1]: Yes?: "); // ranges NOT included as their values are NOT intrinsic ( they're 1 and 0).
		  |
		  |-->  to be added at the very end, after finishing typing the "return" keyword in the implementing function.

	 } while (AddMore);



	 Note: The above block of code is to be sequentially composed line by line, and at the end, implement the function(s) in order.
  }



				   ----------------------------------------------
					  The implementation of the ReadBoolValue: ( add the error message layer when solving problems - Here, it's removed for simplicity).
				   ----------------------------------------------



  bool ValidateBoolValue(const int& response)   // pass by constant ref. since 'response' is ONLY used for comparison against the range.
  {
	return (response == 1 || response == 0);
  }




 bool ReadBoolValue(const string& message)
 {
	 int number;  // what's returned  // it HAS to be an int (follow along).

	 do
	 {
		number = ReadIntegerNumber(message); // 'response' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidateBoolValue(number));

	return number;      // before number is returned, it's implicitly converted from int to bool. Afterwards, it's returned.



	// The above block of code is to be sequentially composed line by line,
	// & at the end, implement all the functions in order.
 }

   */








   //// Example:

  /*
   Problem #36:

   Write a program to DYNAMICALLY READ NUMBERS
   and save them in an array.

   Max size of array is 100, allocate semi-dynamic array length.

   Output:

   Please enter a number? 10
   Do you want to add more numbers? [0]:No, [1]:Yes? 1

   Please enter a number? 20
   Do you want to add more numbers? [0]:No, [1]:Yes? 1

   Please enter a number? 30
   Do you want to add more numbers? [0]:No, [1]:Yes? 0



   Array Length: 3
   Array elements: 10 20 30




  */

int ReadIntegerNumber(const string& message)
{
	int number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}



bool ValidatePositiveInteger(const int& number)    // pass by constant reference as 'number' is ONly used for comparion against the range.
{
	return (number > 0);
}



int ReadPositiveInteger(const string& message)
{
	int count = 0;   // added at the end for the error message
	int number;  // what's returned.

	do
	{
		count++;
		if (count > 1)
		{
			cout << "Error- ONLY positive numebrs allowed. ";
		}

		number = ReadIntegerNumber(message);   // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

	} while (!ValidatePositiveInteger(number));

	return number;

	// the above block of code is to be sequentially composed line by line and at the end, implement all functions in order.
}


void AddElementToArray(int number, int array[], int& ArrayLength)   // the array is automatically passed by ref.
{
	array[ArrayLength] = number;
	ArrayLength++;

	// Here there are two ways:
		// For-loops not possible, as this is a dynamic array (user enters a value, then asked if they want to add more values or not).
		// The ArrayLength serves as the index of the array to add the element. Then IMMEDIATELY the ArrayLength has to be incremented by 1 to reflect
		// the current number of elements in the array & to serve as the next index of the array shall the user want to add an additional value.
}

bool ValidateBoolValue(const int& response)   // pass by constant ref. since 'response' is ONLY used for comparison against the range.
{
	return (response == 1 || response == 0);
}


bool ReadBoolValue(const string& message)
{
	int count = 0; // added at the end for the error message.
	int number;  // what's returned  // it HAS to be an int (follow along).

	do
	{
		count++;
		if (count > 1)
		{
			cout << "Error- Only enter 0 for No / 1 for Yes. \n";
		}
		number = ReadIntegerNumber(message); // 'response' is to be IMMEDIATELY validated against the range, in the while condition

	} while (!ValidateBoolValue(number));

	return number;  // before number is returned, it's implicitly converted from int to bool. Afterwards, it's returned.

	// The above block of code is to be sequentially composed line by line, 
	// & at the end, implement all the functions in order.
}


void ReadArray(const string& message, int array[100], int& ArrayLength) // arrays AUTOMATICALLY passed by ref. (Including the & sign renders exception).
{
	bool AddMore;

	do
	{
		AddElementToArray(ReadPositiveInteger(message), array, ArrayLength);

		AddMore = ReadBoolValue("Do you want to add more numbers? [0]: No, [1]: Yes?: "); // ranges NOT included as their values are NOT intrinsic ( they're 1 and 0).
		/*        |
				  |-->  to be added at the very end, after finishing typing the "return" keyword in the implementing function. */

	} while (AddMore);

	// Note: The above block of code is to be sequentially composed line by line
	//       and at the end, implement the function(s).
}



void PrintArrayElements(const int array[], const int& ArrayLength)
{
	cout << "Array Elements: ";
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}




int main()
{
	int array[100], ArrayLength = 0;
	ReadArray("Please enter a number ?: ", array, ArrayLength);
	// 'array' & 'ArrayLength' are now initialized.

	cout << "Array Length: " << ArrayLength << endl;
	PrintArrayElements(array, ArrayLength);

	return 0;
}










//////// Initial Unoptimized primitive solution:
// //////// Initial Unoptimized primitive solution:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////// Initial Unoptimized primitive solution:




//enum enResponse { Yes = 1, No = 0 };
//
//int ReadIntegerNumber(const string& message)
//{
//	int number;   // what's returned
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidatePositiveInteger(const int& number)
//{
//	return (number > 0);
//}
//
//
//
//void ReadArray(const string& message, int array[], int& ArrayLength) // array AUTOMATICALLY passed by reference only.
//{
//		do
//		{
//			array[ArrayLength] = ReadIntegerNumber(message);
//
//		} while(!ValidatePositiveInteger(array[ArrayLength]));
//
//		ArrayLength++;   // Increase length after successfully adding a number
//}
//
//
//int ReadAnotherNumber(const string& message)
//{
//	int count = 0;
//	int number; // what's returned
//	
//	do
//	{
//		count++;
//		if (count > 1)
//		{
//			cout << "Error- Value entered must be 1 or 0";
//		}
//		number = ReadIntegerNumber(message);
//
//	} while (number != 0 && number != 1);
//
//	return number;
//}
//
//
//enResponse CastToEnumFromInteger(int response)  // pass by value
//{
//	return (enResponse)response;
//}
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
//int main()
//{ 
//	int array[100], ArrayLength = 0;
//	ReadArray("Please enter a number ?: ", array, ArrayLength);
//
//	int ResponseNumber = ReadAnotherNumber("Do you want to add more numbers? [0]:No, [1]:Yes? 1: ");
//	enResponse response =  CastToEnumFromInteger(ResponseNumber);
//
//
//	while(response == enResponse::Yes)
//	{
//		ReadArray("Please enter a number ?: ", array, ArrayLength);
//
//		ResponseNumber = ReadAnotherNumber("Do you want to add more numbers? [0]:No, [1]:Yes? 1: ");
//		response = CastToEnumFromInteger(ResponseNumber);    // I had  a re-declaration:   enResponse response
//	}
//
//	
//
//	// If the program reaches here, then 'array' & 'ArrayLength' are now fully initialized
//
//	cout << "Array length: " << ArrayLength << endl;
//	cout << "Array elements: ";
//	PrintArray(array, ArrayLength);
//	
//	return 0;
//}





