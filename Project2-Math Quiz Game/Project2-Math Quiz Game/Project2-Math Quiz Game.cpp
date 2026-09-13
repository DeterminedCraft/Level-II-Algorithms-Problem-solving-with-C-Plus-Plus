
#include <iostream>
#include <cstdlib>    // for generating random numbers.
#include <ctime>     // for generating random numbers.
using namespace std;

enum enQuestionLevel { Easy = 1, Medium = 2, Hard = 3, MixLevel = 4};   
enum enOperationType { Add = 1, Subtract = 2, Multiply = 3, Divide = 4, MixOperation = 5 };  // You can't have two enumration constants(enumerators) having the exact name across two enums.
enum enPlayAgain { Yes = 'Y', yes = 'y', No = 'N', no = 'n' };

// Now, look for state enums:
enum enAnswerState { Right = 1, Wrong = 2 };
enum enFinalResultState { Pass = 1, Fail = 2, Draw = 3 };


// Now, Look for structure(s):
struct stEquationElements        // it goes hand in hand with the simple calculator utility.
{
	int Num1;
	int Num2;
	enOperationType OperationType;
	int result;
};
// declare the variable of this structure user-defined data type in main(), since it's neither going to be initialized directly nor initialized via reading user input.

struct stCount
{
	int RightAnswerCount = 0;
	int WrongAnswerCount = 0;
};
// declare the variable of this structure user-defined data type in main(), since it's neither going to be initialized directly nor initialized via reading user input.
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Note: ALL the above lines of code are composed on one shot before proceeding further.



int ReadIntegerNumber(const string& message)
{
	int number;  // what's returned.

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}


bool ValidateIntegerInRange(int number, int min, int max)
{
	return (min <= number && number <= max);
}



int ReadIntegerInRange(string message, int min, int max)
{
	int number; // what's returned.

	number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the while condition.
	while (!ValidateIntegerInRange(number, min, max))
	{
		cout << "Error. Enter a value between " << min << " & " << max << endl;
		number = ReadIntegerNumber(message);
	}

	return number;
	// the above block of code is to be sequentially composed line by line, & at the end implement all the functions.
}




enQuestionLevel CastToLevelEnumFromInteger(int c)
{
	return (enQuestionLevel)c;
}


enOperationType CastToTypeEnumFromInteger(int c)
{
	return (enOperationType)c;
}



int GenerateRandomNumberInRange(int from, int to)  // pass by value
{
	return rand() % (to - from + 1) + from;
}




int SimpleCalculator(stEquationElements EquationElements)   // this is a utility.
{
	switch (EquationElements.OperationType)
	{
	case enOperationType::Add:
		return (EquationElements.Num1 + EquationElements.Num2);

	case enOperationType::Subtract:
		return (EquationElements.Num1 - EquationElements.Num2);

	case enOperationType::Divide:
		return (EquationElements.Num1 / EquationElements.Num2);

	case enOperationType::Multiply:
		return (EquationElements.Num1 * EquationElements.Num2);

	default:
		cout << "Variable 'EquationElements' contains some unexpected value.\n";
	}
}




void GenerateOneQuestionAndItsAnswer(enQuestionLevel QuestionLevel, stEquationElements& EquationElements)
{
	if ( QuestionLevel == enQuestionLevel::MixLevel)   // to the right: equates to '4' of data type enQuestionLevel //  if 4 selected for mixed level, there is an additional step of randomly overriding the value to (1-3) to become either 1:easy  or  2:medium or  3:hard
	{
		QuestionLevel = (enQuestionLevel)GenerateRandomNumberInRange(1, 3);
	}

	if (EquationElements.OperationType == enOperationType::MixOperation)  // to the right: equates to '5' of data type enOperationType // if 5 selected for mixed operation, there is an additional step of randomly overring this value to ( 1 to 4)
	{
		EquationElements.OperationType = (enOperationType)GenerateRandomNumberInRange(1, 4);
	}

	switch (QuestionLevel)
	{
     
	case enQuestionLevel::Easy:
		EquationElements.Num1 = GenerateRandomNumberInRange(1, 10);
		EquationElements.Num2 = GenerateRandomNumberInRange(1, 10);
		EquationElements.result = SimpleCalculator(EquationElements);
		break;

	case enQuestionLevel::Medium:
		EquationElements.Num1 = GenerateRandomNumberInRange(11, 50);
		EquationElements.Num2 = GenerateRandomNumberInRange(11, 50);
		EquationElements.result = SimpleCalculator(EquationElements);
		break;

	case enQuestionLevel::Hard:
		EquationElements.Num1 = GenerateRandomNumberInRange(51, 100);
		EquationElements.Num2 = GenerateRandomNumberInRange(51, 100);
		EquationElements.result = SimpleCalculator(EquationElements);
		break;

	default:
		cout << " Variable 'QuestionLevel' contains unexpected value.\n";
	}

}




void PrintQuestion(const stEquationElements &EquationElements)    // pass by constant reference.
{
	switch (EquationElements.OperationType)
	{
	case enOperationType::Add:
		cout << EquationElements.Num1 << endl << EquationElements.Num2 << " +" << endl << endl << "__________\n";
		break;

	case enOperationType::Subtract:
		cout << EquationElements.Num1 << endl << EquationElements.Num2 << " -" << endl << endl << "__________\n";
		break;

	case enOperationType::Multiply:
		cout << EquationElements.Num1 << endl << EquationElements.Num2 << " *" << endl << endl << "__________\n";
		break;

	case enOperationType::Divide:
		cout << EquationElements.Num1 << endl << EquationElements.Num2 << " /" << endl << endl << "__________\n";
		break;

	default:
		cout << " Variable 'EquationElements.OperationType' constains some unexpected value.\n";
	}
}



int ReadAnswer()  // input validation ignored on purpose.
{
	int number;   // what's returned.
	cin >> number;
	cout << endl;
	return number;
}




enAnswerState GiveFeedBackOnAnswer(int answer, int result)
{
	if (answer == result)
	{
		return enAnswerState::Right;
	}
	return enAnswerState::Wrong;
}



void PrintCorrectAnswer(int result)
{
	cout << "The right answer is: " << result << endl << endl;
}



void PrintFeedback(enAnswerState FeedbackState, int result)
{
	switch (FeedbackState)
	{
	case enAnswerState::Right:
		cout << "Right Answer :-) \n\n";
		break;

	case enAnswerState::Wrong:
		cout << "Wrong Answer :-( \n";
		PrintCorrectAnswer(result);
		break;
	}
}

void ChangeConsoleColor(const enAnswerState &FeedbackState) // pass by constant reference.
{
	switch (FeedbackState)
	{
	case enAnswerState::Right:
		system("color 2F");
		break;

	case enAnswerState::Wrong:
		system("color 4F");
		break;

	default:
		cout << "variable 'FeedbackState' has some unexpected value.\n";
	}
}

void CountCorrectAndWrongAnswers(enAnswerState FeedbackState, stCount &count)   // passing by reference is crucial.
{
	switch (FeedbackState)
	{
	case enAnswerState::Right:
		count.RightAnswerCount++;
		break;

	case enAnswerState::Wrong:
		count.WrongAnswerCount++;
		break;

	default:
		cout << "Variable 'FeedBackState' has some unexpected value.\n";
	
	}
}


enFinalResultState DetermineFinalResult(stCount count)   // pass by value
{
	if (count.RightAnswerCount == count.WrongAnswerCount)
	{
		return enFinalResultState::Draw;    // equates to 3 ( of data type enFinalState).
	}

	else if (count.RightAnswerCount > count.WrongAnswerCount)
	{
		return enFinalResultState::Pass;   // equates to 1 ( of data type enFinalState).
	}

	return enFinalResultState::Fail;    //equates to 2 ( of data type enFinalState).
}



string FinalResultStateName(enFinalResultState FinalResultState)
{
	string result[3] = { "PASS", "FAIL", "DRAW" };    // corresponding to:        enum enFinalResultState { Pass = 1, Fail = 2, Draw = 3 };
	return result[FinalResultState - 1];   // ex [ enFinalResultSate::Pass - 1]    // equates to [ 1-1]
}



void PrintHeader(const enFinalResultState& FinalResultState)      // pass by constant reference
{
	cout << "--------------------------------------------------\n\n";
	cout << "Final Results is " << FinalResultStateName(FinalResultState) << " :-)" << endl << endl;
	cout << "--------------------------------------------------\n\n";
}


string QuestionsLevelName(enQuestionLevel QuestionLevel)
{
	string TheLevel[4] = { "Easy", "Medium", "Hard", "Mix" };    // enum enQuestionLevel { Easy = 1, Medium = 2, Hard = 3, MixLevel = 4};  
	return TheLevel[QuestionLevel - 1];
}


string OperationTypeName(enOperationType OperationType)
{
	string TheOperationType [5] = { "+", "-", "*", "/", "Mix" };   // enum enOperationType { Add = 1, Subtract = 2, Multiply = 3, Divide = 4, MixOperation = 5 }; 
	return TheOperationType [OperationType - 1];
}





void PrintFinalResult(enFinalResultState FinalResultState, int NumberOfQuestions, int c1, int c2, stCount count)
{
	PrintHeader(FinalResultState);

	cout << "NumberOf Questions     : " << NumberOfQuestions << endl;
	cout << "Questions Level        : " << QuestionsLevelName((enQuestionLevel)c1) << endl;
	cout << "OpType                 : " << OperationTypeName((enOperationType)c2) << endl;
	cout << "Number of Right Answers: " << count.RightAnswerCount << endl;
	cout << "Number of Wrong Answers: " << count.WrongAnswerCount << endl;
	cout << "-----------------------------------------------------------------\n\n";
}


void ResetColor()
{
	system("cls");
	system("color 0F");
}


char ReadCharacterValue(string message)
{
	char character;
	
	cout << message;
	cin >> character;
	cout << endl;

	return character;
}

bool ValidateCharacterValue(const char& character)
{
	return (character == 'Y' || character == 'y' || character == 'N' || character == 'n');
}




char ReadCharacter(const string& message)
{
	char character;  // what's returned.

	character = ReadCharacterValue(message);

	while (!ValidateCharacterValue(character))
	{
		cout << "Wrong character. Try again\n";
		character = ReadCharacterValue(message);
	}

	return character;
}


enPlayAgain CastToEnumFromCharacter(char character)
{
	return (enPlayAgain)character;
}



bool IsPlayAgainResponse(enPlayAgain EnumCharacter)
{
	switch (EnumCharacter)
	{
	case enPlayAgain::Yes:
		return true;

	case enPlayAgain::yes:
		return true;

	case enPlayAgain::No:
		return false;

	case enPlayAgain::no:
		return false;

	default:
		cout << "Variable 'EnumCharacter' holds some unexpected value.\n";
		return false;
	}
}



void StartGame()
{
	bool IsToPlayAgain = false;

	do
	{
		ResetColor();   // clears the text and re-sets the colour to background color to black

		stEquationElements EquationElements;
		stCount count;

		int MinNumberOfQuestions = 1;
		int MaxNumberOfQuestions = 100;
		int NumberOfQuestions = ReadIntegerInRange("How many questions do you want to answer ?: ", MinNumberOfQuestions, MaxNumberOfQuestions);

		int MinLevel = 1;
		int MaxLevel = 4;
		int c1 = ReadIntegerInRange("Enter Questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ?: ", MinLevel, MaxLevel);   // example: 2 stored in an integer variable.
		enQuestionLevel QuestionLevel = CastToLevelEnumFromInteger(c1);   // ex, 2 is of data type  enQuestionLevel  // note placing it in switch statement to compare it agains enumerators is redundant.

		int MinOperatioChoice = 1;
		int MaxOperationChoice = 5;
		int c2 = ReadIntegerInRange("Enter Operation Type [1] Add, [2] Subtract, [3] Multiply, [4] Divide, [5] Mix ?: ", MinOperatioChoice, MaxOperationChoice); // example: 5 stored in an integer variable.
		EquationElements.OperationType = CastToTypeEnumFromInteger(c2); // ex, 5 is of data type  enOperationType  // note placing it in switch statement to compare it agains enumerators is redundant.


		for (int i = 0; i < NumberOfQuestions; i++)
		{
			// the below 2 lines of code has to be duplicated, this time, inside the for-loops:
			// reason is, for the 2 mix options- the 2 random numbers generated for each, will persist for every single subsequent question.
			// unless one retains the original mix options with the start of each for-loop iteration.
			enQuestionLevel QuestionLevel = CastToLevelEnumFromInteger(c1);  // waht if I do not re-declare ?
			EquationElements.OperationType = CastToTypeEnumFromInteger(c2);

			GenerateOneQuestionAndItsAnswer( QuestionLevel, EquationElements);  // for questionLevel we pass it as enum and not integer, becasue the program understands and deals with states.
		    
			cout << "Question [" << i+1 << "/" << NumberOfQuestions << "]" << endl << endl,
			PrintQuestion(EquationElements);


			int answer = ReadAnswer();


			enAnswerState FeedbackState = GiveFeedBackOnAnswer(answer, EquationElements.result);
			ChangeConsoleColor(FeedbackState);
			CountCorrectAndWrongAnswers(FeedbackState, count);

			PrintFeedback(FeedbackState, EquationElements.result);   // associating the enum state with string appearing to user (the association with string is done at the last moment when it's needed).	
		}

		// results section:

		enFinalResultState FinalResultState = DetermineFinalResult(count); // It should be expressed as a state (enum) as this is what computers understand. And when the moment/exact time comes to display that to user, then later you convert to string for display.

		PrintFinalResult(FinalResultState, NumberOfQuestions, c1, c2, count);  // why so many variables here.

		char character = ReadCharacter("Do you want to play again ? Y/N?: ");   // ex:   'Y' of char sata type.
		enPlayAgain EnumCharacter = CastToEnumFromCharacter(character);
		IsToPlayAgain = IsPlayAgainResponse(EnumCharacter);
		

     // IsToPlayAgain = Implement this function at the very end.
	} while(IsToPlayAgain);



}



int main()
{
	srand((unsigned)time(NULL));   // to seed random numbers.

	StartGame();



	return 0;
}





/*
   This code snippet can't compile because the value used in
   the 'case' label must be known at compile time.

   'result' is a function parameter, so its value is only known
   at run time.
*/

// enAnswerState GiveFeedBackOnAnswer(int answer, int result)
// {
//     switch (answer)
//     {
//     case result:
//         return enAnswerState::Right;
//     }
// }



















































//
//
//enum enQuestionsLevel { Easy = 1, Medium = 2, Hard = 3, MixQuestion = 4};        // having Mix here
//enum enOperationType { Add = 1, Subtract = 2, Multiply = 3, Divide = 4, MixOperations = 5};   // na Mix here, renders a compiler error.
//enum enPlayAgain { Yes = 'Y', yes = 'y', No = 'N', no = 'n' };
//
//// Now, look for state enum(s):
//enum enAnswerState { Right = 1, Wrong = 2};
//enum FinalResultState {Pass = 1, Fail = 2};
//
//// Now- any structure(s) ?
//
//struct stMathVariables   // to think about later: the plural is worthwhile !
//{
//	short Num1;
//	short Num2;
//	short result;
//};
//
//struct stCount
//{
//	short RightAnswerCount = 0;
//	short WrongAnswerCount = 0;
//};
//
//// for the above 2 structures: so far, only a structure user-defined data type has been created and nothing more.
//// the next natural step, is creating a variable of this structure user-defined data type.
//// But the main question is- where to create it ?
////  - If it's going to be initialized directly, then do it inside main().
////  - If it's going to be initialized via reading user input, then do it inside a reading procedure of this structure user-defined data type, that returns this variable. If this is the case then implement this reading function NOW below IMMEDIATELY.
////    Since the answer is none, then declare it inside main().
//
//
//short ReadShortNumber(const string& message)
//{
//	short number;  // what's returned.
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
//
//
//bool ValidateShortInRange(const short& number, short min, short max)   // pass by const. ref. since it's ONLY used for comparison.  // ranges ALWAYS passed by value.
//{
//	return (min <= number && number <= max);
//}
//
//
//
//
//short ReadShortInRange(const string& message, short min, short max)   // ranges ALWAYS passed by value.
//{
//	short number;   // what's returned
//
//	number = ReadShortNumber(message);   // review the mental model.
//	
//	while (!ValidateShortInRange(number, min, max))
//	{
//		cout << "Error- Enter a valid number between " << min << " & " << max << endl;
//		number = ReadShortNumber(message);
//	}
//
//	return number;
//}
//
//
//
//
//
//bool ValidateIntegerInRange(const int& number, int min, int max)   // pass by const. ref. since it's ONLY used for comparison.  // ranges ALWAYS passed by value.
//{
//	return (min <= number && number <= max);
//}
//
//
//
//
//
//int ReadIntegerNumber(const string& message)
//{
//	int number;  // what's returned.
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
//
//int ReadIntegerInRange(const string& message, int min, int max)   // ranges ALWAYS passed by value.
//{
//	int number;   // what's returned
//
//	number = ReadIntegerNumber(message);   // review the mental model.
//
//	while (!ValidateIntegerInRange(number, min, max))
//	{
//		cout << "Error- Enter a valid number between " << min << " & " << max << endl;
//		number = ReadIntegerNumber(message);
//	}
//
//	return number;
//}
//
//
//
//
//enQuestionsLevel CastToLevelEnumFromInteger(int c)
//{
//	return (enQuestionsLevel)c;
//}
//
//
//
//
//enOperationType CastToOperationEnumFromInteger(int c)
//{
//	return (enOperationType)c;
//}
//
//
//
//int GenerateRandomNumberInRange(int from, int to)   // pass by value
//{
//	return rand() % (to - from + 1) + from;
//}
//
//
//
//
//
//void ReadMathVariables(enQuestionsLevel QuestionsLevel, stMathVariables & MathVariables)   // pass by value
//{
//	switch (QuestionsLevel)
//	{
//
//	case enQuestionsLevel::Easy:
//		MathVariables.Num1 = GenerateRandomNumberInRange(1, 10);  // our CORE INEVITABLE function for randomness. Its implementation SHOULD return int.
//		MathVariables.Num2 = GenerateRandomNumberInRange(1, 10);
//		break;
//
//	case enQuestionsLevel::Medium:
//		MathVariables.Num1 = GenerateRandomNumberInRange(11, 49);
//		MathVariables.Num2 = GenerateRandomNumberInRange(11, 49);
//		break;
//
//	case enQuestionsLevel::Hard:
//		MathVariables.Num1 = GenerateRandomNumberInRange(50, 99);
//		MathVariables.Num2 = GenerateRandomNumberInRange(50, 99);
//		break;
//
//	case enQuestionsLevel::MixQuestion:
//		MathVariables.Num1 = GenerateRandomNumberInRange(1, 99);
//		MathVariables.Num2 = GenerateRandomNumberInRange(1, 99);
//		break;
//
//	}
//}
//
//
//
//
//int CalculateRandomMathResult(int MixedOperation, stMathVariables MathVariables)
//{
//	switch (MixedOperation)
//	{
//
//	case 1:
//	{
//		return MathVariables.Num1 + MathVariables.Num2;
//	}
//
//	case 2:
//	{
//		return MathVariables.Num1 - MathVariables.Num2;
//	}
//
//	case 3:
//	{
//		return MathVariables.Num1 * MathVariables.Num2;
//	}
//
//	case 4:
//	{
//		return MathVariables.Num1 / MathVariables.Num2;    // we want integer division.
//	}
//
//	default: 
//		cout << "Error- 'RandomNumber' variable contains unexpected value. \n";
//		return 0;
//	}
//}
//
//
//
//
//int CalculateMathResult(stMathVariables MathVariables, enOperationType OperationType, short MixedOperation)   // pass by value
//{
//	switch (OperationType)
//	{
//	case enOperationType::Add:
//		return MathVariables.Num1 + MathVariables.Num2;
//
//	case enOperationType::Subtract:
//		return MathVariables.Num1 - MathVariables.Num2;
//
//	case enOperationType::Multiply:
//		return MathVariables.Num1 * MathVariables.Num2;
//
//	case enOperationType::Divide:
//		return MathVariables.Num1 / MathVariables.Num2;   // we need integer division.
//
//	case enOperationType::MixOperations:
//		return CalculateRandomMathResult(MixedOperation, MathVariables);
//
//	default:
//		cout << "Error- variable 'OperationType' contains unexpected value. \n";
//		return 0;
//	}
//}
//
//
//
//
//
//void PrintMathQuestion(const stMathVariables &MathVariables, const enOperationType &OperationType, const int &MixedOperation)
//{
//	if (OperationType == enOperationType::Add)
//	{
//	  cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " +" << endl << endl << "-----------\n";
//	}
//
//	else if (OperationType == enOperationType::Subtract)
//	{
//	  cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " -" << endl << endl << "-----------\n";
//	}
//
//	else if (OperationType == enOperationType::Multiply)
//	{
//		cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " *" << endl << endl << "-----------\n";
//	}
//
//	else if (OperationType == enOperationType::Divide)
//	{
//		cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " /" << endl << endl << "-----------\n";
//
//	}
//
//	else if (OperationType == enOperationType::MixOperations)
//	{
//		if (MixedOperation == 1)
//		{
//			cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " +" << endl << endl << "-----------\n";
//		}
//
//		else if (MixedOperation == 2)
//		{
//			cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " -" << endl << endl << "-----------\n";
//		}
//
//		else if (MixedOperation == 3)
//		{
//			cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " *" << endl << endl << "-----------\n";
//		}
//
//		else if (MixedOperation == 4)
//		{
//			cout << MathVariables.Num1 << "\n" << MathVariables.Num2 << " /" << endl << endl << "-----------\n";
//		}
//		
//
//	}
//
//}
//
//
//int ReadMathAnswer()
//{
//	int number;  // what's returned
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//
//
//
//enAnswerState CheckUserAnswer(int UserAnswer, int MathResult)
//{
//	if (UserAnswer == MathResult)
//	{
//		return enAnswerState::Right;
//	}
//
//	return enAnswerState::Wrong;
//}
//
//
//
//string ToString(enAnswerState AnswerState)    // pass by value
//{
//	string decision[2] = { "Right", "Wrong" };
//	return decision[AnswerState - 1];
//}
//
//
//
//
//
//void PrintAnswerFeedBack( enAnswerState AnswerState, int MathResult)
//{
//
//	switch (AnswerState)
//	{
//
//	case enAnswerState::Right:
//
//		cout << ToString(AnswerState) << " Answer :)-" << endl << endl;
//		break;
//
//	case enAnswerState::Wrong:
//
//		cout << ToString(AnswerState) << " Answer :-(" << endl;
//		cout << "The right answer is: " << MathResult << endl << endl;
//		break;
//
//	default:
//		cout << "Error- Variable 'AnswerState' holds some unexpected value.\n";
//
//	}
//}
//
//
//
//
//
//void StartGame()
//{
//
//	bool PlayAgain = true;  // initialize it first, so that garbage data is not initially carried over.
//
//	do
//	{
//		stMathVariables MathVariables;
//		stCount count;
//
//		short MinNumberOfQuest = 1;
//		short MaxNumberOfQuest = 500;
//		short NumberOfQuestions = ReadShortInRange("How many questions do you want to answer ?: ", MinNumberOfQuest, MaxNumberOfQuest);
//
//		int MinLevelValue = 1;
//		int MaxLevelValue = 4;
//		int c = ReadIntegerInRange("Enter Questions level- [1]:Easy , [2]:Medium, [3]:Hard, [4]:Mix ?: ", MinLevelValue, MaxLevelValue);  // for example, 3 of type int.
//		enQuestionsLevel QuestionsLevel =   CastToLevelEnumFromInteger(c);    // now, for example, 3 is of data type enQuestionsLevel.
//
//		int MinOperationValue = 1;
//		int MaxOperationValue = 5;
//		c = ReadIntegerInRange("Enter Operation Type- [1]:Add, [2]:Subtract, [3]:Multiply, [4]:Divide, [5]:Mix ?: ", MinOperationValue, MaxOperationValue);
//		enOperationType OperationType = CastToOperationEnumFromInteger(c);  // now, for example, 1 is of data type enOperationType.
//
//
//
//		for (int i = 0; i < NumberOfQuestions; i++)
//		{
//			ReadMathVariables(QuestionsLevel, MathVariables);
//			// Variable 'MathVariables' is now initialized with some of it's member variables.
//			
//			int MixedOperation = GenerateRandomNumberInRange(1, 4);
//			int MathResult = CalculateMathResult(MathVariables, OperationType, MixedOperation);
//
//			cout << "\nQuestion [" << i + 1 << "/" << NumberOfQuestions << "]" << endl << endl;
//			
//			PrintMathQuestion(MathVariables, OperationType, MixedOperation);
//
//			int UserAnswer = ReadMathAnswer();
//			enAnswerState AnswerState= CheckUserAnswer(UserAnswer, MathResult);
//
//			PrintAnswerFeedBack(AnswerState, MathResult);
//		}
//
//
//
//
//
//
//		// PlayAgain = Implement this function at the very end.
//
//	} while (PlayAgain);
//}
//
//
//
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	StartGame();
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//











/*   // the following is my main structural template:





 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 bool PlayAgain = true;  // initialize it first, so that garbage data is not initially carried over.

	do
	{




     // PlayAgain = Implement this function at the very end.

	} while(PlayAgain):



 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	
	
	// and if no utilities are used:



	
	char PlayAgain = '';

	do
	{




	 PlayAgain = ReadPlayAgainResponse("Do you want to play again ? Y/N ?: ");

	} while(PlayAgain == 'Y' || PlayAgain == 'y');







*/