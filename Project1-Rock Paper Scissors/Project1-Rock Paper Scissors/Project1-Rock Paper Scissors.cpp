
#include <iostream>
#include <string >   // for  to_string
#include <cstdlib>;  // for randomness
#include <ctime>;   // for randonmness 
using namespace std;




enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enPlayAgain { Yes = 'Y', yes = 'y', No = 'N', no = 'n' };

// Next, look for state enums: 
	// what are they ? ( they are: Computer, Player1, No Winner)
enum enWinState { Player = 1, Computer = 2, Draw = 3 };    // for state enums always start from 1 for the integer values.

// Now, look for structure(s):

struct stRoundInfo
{
	enChoice PlayerChoice;
	enChoice ComputerChoice;
	enWinState RoundWinner;
};
// so far only a structure user-defined data type is created. The next natural step is creating a variable of it
// But the main question is - where to create it ?
// if it's going to be initialized directly, then do it in main()
// if it's going to be initialized via reading user input, then declare it in a reading function of this structure user-defined data type that returns this variable 
     // if this is the case, then do it NOW below IMMEDIATELY.
// since it's neither of those 2 cases, then declare it inside main() NOW ( inside StartGame() in this specific case).

struct stCount
{
	short PlayerWinCount = 0;
	short ComputerWinCount = 0;
	short DrawCount = 0;
};
// same story as above.



short ReadShortNumber(const string &message)    // Ranges are ALWAYS passed by value.
{
	short number; // what's returned

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}



bool ValidateShortInRange(const short& number, short MinRound, short MaxRound)  // pass by const ref. as we^re ONLY comparing against the ranges. 
{
	return (MinRound <= number && number <= MaxRound);
}



short ReadShortInRange(const string& message, short min, short max)  // Ranges are ALWAYS passed by value.
{
	short number;   // what's returned.

	number = ReadShortNumber(message); // 'number' is to be IMMEDIATELY validated against the range, in the while condition.

	while (!ValidateShortInRange(number, min, max))
	{
		cout << "Error. Enter a valid number. \n";
		number = ReadShortNumber(message);
	}

	return number;
}



enChoice CastToEnumFromShort(short c)
{
	return (enChoice)c;
}



int ReadRandomNumberInRange(int from, int to)
{
	return rand() % (to - from + 1) + from;
}



enChoice CastToEnumFromInteger(int RandomNumber)
{
	return (enChoice)RandomNumber;
}



enWinState DecideRoundWinner(stRoundInfo RoundInfo)   // pass by value
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinState::Draw;
	}
   

	switch (RoundInfo.PlayerChoice)
	{
	case enChoice::Paper:
		if (RoundInfo.ComputerChoice == enChoice::Scissors)
		{
			return enWinState::Computer;     // since the computer is the winner, then in the next return lines ensure that the computer remains the winner 
		}                                      // and finally, return the player as the winner outside of the switch statement, This is the MOST OPTIMIZED & READABLE solution.
		break;  // ESSENTIAL. (OUT OF THE SWITCH statement)

	 
	case enChoice::Stone:
		if (RoundInfo.ComputerChoice == enChoice::Paper)
		{
			return enWinState::Computer;
		}
		break; // ESSENTIAL.

	case enChoice::Scissors:
		if (RoundInfo.ComputerChoice == enChoice::Stone)
		{
			return enWinState::Computer;
		}
		break;  // ESSENTIAL.
	}

	return enWinState::Player;
}




string ChoiceName(enChoice choice)   // pass by value
{
	string Thechoice[3] = { "Stone", "Paper", "Scissors" };
	return Thechoice[choice - 1];
}



string WinnerName(enWinState RoundWinner)    
{
	string winner[3] = { "Player1" , "Computer", "No Winner" };
	return winner[RoundWinner - 1];
}



void PrintRoundResults(const int &i, const stRoundInfo& RoundInfo)
{
	cout << "________________Round[" << i + 1 << "]________________\n\n";
	cout << "Player1 Choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << WinnerName(RoundInfo.RoundWinner) << "]" << endl;
	cout << "________________________________________\n\n";
}




void CountWins(enWinState RoundWinner, stCount &CountWinsAndDraws)   // passing by reference.
{
	switch (RoundWinner)
	{
	case enWinState::Computer:
		CountWinsAndDraws.ComputerWinCount++;
		break;

	case enWinState::Player:
		CountWinsAndDraws.PlayerWinCount++;
		break;

	case enWinState::Draw:
		CountWinsAndDraws.DrawCount++;
		break;

	default: 
		cout << "A programming error. Variable 'RoundWinner' contains some unexpected value.\n";
	}
}



void ChangeColorForWinner(const enWinState &RoundWinner)    // pass by constant reference
{
	switch (RoundWinner)
	{
	case enWinState::Computer:
	
		system("color 40");  // solid red
		cout << "\a";       // a nudge
		break;

	case enWinState::Player:
		system("color 20");   // solid green.
		break;             

	case enWinState::Draw:
		system("color 60");   // solid yellow.
		break;

	default:                  // The default is useful as a safety net in case RoundWinner somehow contains an unexpected value   // plus prevents compiler's 'complaint'.
		cout << "A programming error. Variable 'RoundWinner' contains some unexpected value.\n";
	}
}




void ResetConsole()   // reset by 1- clearing the text  2- changing back to the default black colour.
{
	system("cls");
	system("color 07");

}



enWinState DetermineFinalWinner(stCount CountWinsAndDraws)
{
	if (CountWinsAndDraws.ComputerWinCount > CountWinsAndDraws.PlayerWinCount)
	{
		return enWinState::Computer;
	}

	else if (CountWinsAndDraws.ComputerWinCount < CountWinsAndDraws.PlayerWinCount)
	{
		return enWinState::Player;
	}

	return enWinState::Draw;
}




string tab(short NumberOfTabs)   // pass by value
{
	string t = "";

	for (int i = 0; i < NumberOfTabs; i++)
	{
		t = t + "\t";
	}

	return t;
}





void PrintGameHeader()
{
	cout << tab(2) << "___________________________________________________________________\n\n";    // note:    tab(2)  =   \t\t
	cout << tab(5) << "+++ G a m e  O v e r +++" << endl << endl;                                   //          tab(3) =    \t\t\t
	cout << tab(2) << "___________________________________________________________________\n\n";

}




void PrintGameResult(const short& NumberOfRounds, const stCount& CountWinsAndDraws)
{
	PrintGameHeader();

	cout << tab(2) << "______________________________[Game Results]_______________________\n\n";
	cout << tab(2) << "Game Rounds        :" << NumberOfRounds << endl;
	cout << tab(2) << "Player1 Win Times  :" << CountWinsAndDraws.PlayerWinCount << endl;
	cout << tab(2) << "Computer Win Times :" << CountWinsAndDraws.ComputerWinCount << endl;
	cout << tab(2) << "Draw Times         :" << CountWinsAndDraws.DrawCount << endl;
	cout << tab(2) << "Final Winner       :" << WinnerName(DetermineFinalWinner(CountWinsAndDraws)) << endl << endl;
	cout << tab(2) << "____________________________________________________________________\n\n";
}




char ReadCharValue(const string& message)
{
	char character; // what's returned
	
	cout << message;
	cin >> character;
	cout << endl;

	return character;
}




bool ValidateCharacter(const char& character)
{
	return (character == 'Y' || character == 'y' || character == 'N' || character == 'n');
}




char ReadCharacter(const string& message)
{
	bool validate; // was added when it was needed.

	char character; // what's returned
	
	do
	{
		character = ReadCharValue(message); // 'character' is to be IMMEDIATELY validated against the range, in the while condition.

		validate = ValidateCharacter(character);
		if (!validate)
		{
			cout << "Invalid Character. \n";
		}

	} while (!validate);

	return character;
	// The above lines of code are to be sequentially composed line by line & at the end, implement all the functions.
}




enPlayAgain CastToEnumFromCharacter(char c)
{
	return (enPlayAgain)c;
}




bool IsPlayAgain(enPlayAgain EnumC)  // pass by value
{
	switch (EnumC)
	{
	case enPlayAgain::yes:     // equates to y (of data type enPlayAgain)
		return true;

	case enPlayAgain::Yes:   // equates to Y (of data type enPlayAgain)
		return true;

	case enPlayAgain::no:   // equates to n (of data type enPlayAgain)
		return false;

	case enPlayAgain::No:  // equates to N (of data type enPlayAgain)
		return false;

	default:
		cout << "A programming error. Variable 'EnumC' contains some unexpected value.\n";// included to stop compiler from complaining. Plus, what if one had (by mistake):   return (enPlayAgain)Z;  
		return false;                                                                           // but can only happen if one had no character validation in the program for N, n, Y, y.
	}
}




void StartGame()
{

	bool PlayAgain;

	do
	{
		ResetConsole();   

		stRoundInfo RoundInfo;
		stCount CountWinsAndDraws;

		short MinRound = 1;
		short MaxRound = 10;
		short NumberOfRounds = ReadShortInRange("How many Rounds (" + to_string(MinRound) + " to " + to_string(MaxRound) + ") ?: \n", MinRound, MaxRound);

		for (int i = 0; i < NumberOfRounds; i++)
		{
			cout << "Round [" << i + 1 << "] begins: \n\n";

			short MinChoice = 1;
			short MaxChoice = 3;
			short c = ReadShortInRange("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?: ", MinChoice, MaxChoice);  
			RoundInfo.PlayerChoice =  CastToEnumFromShort(c);    // now, for example, '2' is of data type enChoice
			// NOTE: placing PlayerChoice in a switch statement to compare it against the enumeration constants (enumerators)& then returning an enumeration constant is a redundant (the step above did that already)

			//** For the computer's choice :
			int RandomNumber = ReadRandomNumberInRange(1, 3);   // our INEVITABLE CORE utility to generate random numbers (it's implementation SHOULD return integer).
			RoundInfo.ComputerChoice =  CastToEnumFromInteger(RandomNumber);   // for example - 3 of data type enChoice.
			// NOTE: placing ComputerChoice in a switch statement to compare it against the enumeration constants(enumerators) so that an enumberation constant is returned is redundant (the step above did that already)

			//** For the Round Winner:
			RoundInfo.RoundWinner = DecideRoundWinner(RoundInfo);
			//wrong line, you are not using structures: //RoundInfo.RoundWinner = DecideRoundWinner(RoundInfo.PlayerChoice, RoundInfo.ComputerChoice);
			// 'RoundInfo' is now initialized with all of its member variables.

			ChangeColorForWinner(RoundInfo.RoundWinner);
			CountWins(RoundInfo.RoundWinner, CountWinsAndDraws);
			// 'CountWinsAndDraws' has been fully initialized with all of its member variables.


			PrintRoundResults(i, RoundInfo);
		}
		// for the Game Over section:

		PrintGameResult(NumberOfRounds, CountWinsAndDraws); // the printing procedure is implemented so that it contains a function /the standard way of programming).


		char c = ReadCharacter("Do you want to play again? Y/N ?: ");
		enPlayAgain EnumC = CastToEnumFromCharacter(c);
		PlayAgain = IsPlayAgain(EnumC);

		// PlayAgain = implement this function later

	} while (PlayAgain);
}




int main()
{

	StartGame();

	return 0;
}














/*   The starting structure/ template:
     
	 bool PlayAgain;

	do
	{





		// PlayAgain = implement this function later

	} while (PlayAgain);




*/




/* Immediately review this:
   
   What stands out to me isn't simply that you arrived at a better solution—it's the sequence of ideas you arrived at on your own. 
   Looking at your commented history, I can almost reconstruct your thought process:

 "The game works."
 Strings everywhere.
 Lots of variables.
 Long parameter lists.
 
 "Why am I comparing strings?"
 Introduce enum enChoice.
 Keep enums until the final display step.

 "There are only three winner possibilities."
 Introduce enWinnerState.

 "These three variables always travel together."
 Create stRoundInfo.

 "These counters also belong together."
 Create stWinCounter.

 "Functions shouldn't receive four or five separate arguments."
 Pass a structure instead.

 That progression is exactly how many experienced programmers refine code. 
 They usually don't produce the final design on the first attempt either—they recognize patterns as they build and then reorganize around those patterns.








*/
//
//enum enChoice { Stone = 1, Paper = 2, Scissors = 3};
//enum enPlayAgain { Yes = 'Y', yes = 'y', No = 'N', no = 'n' };
//
//// Now, looking for a state enums: There are only 3 winner states (possibilities) in the program: Player1, Computer, & No Winner.
//enum enWinnerState { Player1 = 1, Computer = 2, NoWinner = 3};   // assign any integer value to each.
//
//// After coding enums, ALWAYS see if you can create structure(s)
//struct stRoundInfo
//{
//	enChoice PlayerChoice;
//	enChoice ComputerChoice;
//	enWinnerState RoundWinner;
//};
//
//
//struct stWinCounter
//{
//	int PlayerWinCount = 0;
//	int ComputerWinCount = 0;
//	int DrawCount = 0;
//
//};
//
//
//short ReadShortNumber(string message)
//{
//	short number;
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//
//bool ValidateShortInRange(const short& number, short min, short max)
//{
//	return (min <= number && number <= max);
//}
//
//
//
//short ReadShortInRange(const string& message, short min, short max)
//{
//	short number;
//
//	number = ReadShortNumber(message);
//
//	while (!ValidateShortInRange(number, min, max))
//	{
//		cout << "Error- Enter a valid number. \n";
//		number = ReadShortNumber(message);
//	}
//
//	return number;
//}
//
//
//enChoice CastToEnumFromShort(short c)
//{
//	return (enChoice)c;
//}
//
//
//
//enChoice DetermineChoice(enChoice EnumC)
//{
//	switch (EnumC)
//	{
//	case enChoice::Paper:
//		return enChoice::Paper;
//
//	case enChoice::Scissors:
//		return enChoice::Scissors;
//
//	case enChoice::Stone:
//		return enChoice::Stone;
//
//	default:                       // included to prevent compiler from complaining. Plus, what if one had (by mistake):   return (enChoice)100;  for example (but one's only has that if no 
//		return enChoice::Paper;       // range validation ( MinChoice or MaxChoice) was.included 
//	}
//}
//
//
//
//int ReadRandomNumberInRange(int from, int to)     // our INEVITABLE CORE randomness utility that is implemented to ALWAYS return an integer.
//{
//	return rand() % (to - from + 1) + from;
//}
//
//
//
//
//enWinnerState DetermineRoundWinner(enChoice PlayerChoice, enChoice ComputerChoice)
//{
//	if (PlayerChoice == ComputerChoice)
//	{
//		return enWinnerState::NoWinner;
//	}
//
//	switch (PlayerChoice)       
//	{
//	case enChoice::Paper:
//		if (ComputerChoice == enChoice::Stone)
//		{
//			return enWinnerState::Player1;          // since we arranged the if statement so that Player1 is the winner, then in the rest of the cases player1 should be returned as the winner
//		}                                               // and at the end return the winner as the computer (indicating that player1 lost)
//		break; // to exit the switch statement,         // However- if you arrange the if statement so that the winner is the computer, then for the rest of the cases the computer should persist as the winner
//		// without it you get the wron results           // and at the end return the winner as the player (indicating that the computer has lost)
//
//	case enChoice::Scissors:                            
//		if (ComputerChoice == enChoice::Paper)
//		{
//			return enWinnerState::Player1;
//		}
//		break;
//
//	case enChoice::Stone:
//		if (ComputerChoice == enChoice::Scissors)
//		{
//			return enWinnerState::Player1;
//		}
//		break;
//	}
//		return enWinnerState::Computer;
//
//}
//
//
//string ChoiceName(enChoice choice)   // so the values of the variable 'choice' is:  enchoice:.Stone (equates to 1 (of data type enChoice) or enChoice::Paper  or enChoice::Scissors
//{
//	string TheChoice[3] = { "Stone", "Paper", "Scissors" };
//	return  TheChoice[choice - 1];   // 'choice' is implicitly converted to an integer type from enum, producing an integer array index.
//}
//
//
//string ConvertWinToString(enWinnerState winner)   // revisit for argument name ( understand how i selected it)
//{
//	string TheWinner[3] = { "Player1", "Computer", "No Winner" };
//	return TheWinner[winner - 1];
//}
//
//
//
//
//
//void PrintRoundResults(const int& i, const stRoundInfo& RoundInfo)
//{
//	cout << "____________Round [" << i + 1 << "]____________\n\n";
//	cout << "Player1 Choice : "  << ChoiceName(RoundInfo.PlayerChoice) << endl;   // AssociateWithString is better naming ?
//	cout << "Computer Choice: "  << ChoiceName(RoundInfo.ComputerChoice) << endl;
//	cout << "Round Winner   : [" << ConvertWinToString(RoundInfo.RoundWinner) << "]" << endl << endl;
//	cout << "_________________________________\n\n";
//}
//
//
//void CountWinsAndDraws(enWinnerState RoundWinner, stWinCounter &WinCounter)
//{
//	if (RoundWinner == enWinnerState::Computer)
//	{
//		 WinCounter.ComputerWinCount++;
//	}
//
//	else if (RoundWinner == enWinnerState::Player1)
//	{
//		WinCounter.PlayerWinCount++;
//	}
//
//	else if (RoundWinner == enWinnerState::NoWinner)
//	{
//		WinCounter.DrawCount++;
//	}
//}
//
//
//enWinnerState DetermineFinalWinner(const stWinCounter &WinCounter)   // by const. ref. since we're only comparing.
//{
//	if(WinCounter.PlayerWinCount > WinCounter.ComputerWinCount)
//	{
//		return enWinnerState::Player1;
//	}
//
//	else if (WinCounter.PlayerWinCount < WinCounter.ComputerWinCount)
//	{
//		return enWinnerState::Computer;
//	}
//
//	return enWinnerState::NoWinner;
//}
//
//string ConvertFinalWinnerToString(enWinnerState FinalWinner)
//{
//	if (FinalWinner == enWinnerState::Computer)
//	{
//		return "Computer";
//	}
//
//	else if (FinalWinner == enWinnerState::Player1)
//	{
//		return "Player1";
//	}
//
//	return "No Winner";
//}
//
//
//
//
//string tab(short NumberOfTabs)
//{
//	string t = "";
//	for (int i = 0; i < NumberOfTabs; i++)
//	{
//		t = t + "\t";
//	}
//
//	return t;
//}
//
//
//
//
//void PrintHeader()
//{
//	cout << tab(2) << "----------------------------------------------------------------\n\n";         // note:  tab(1)  returns \t        tab(3)  \t\t\t   and so on.  // never use spaces as values. Instead, use tab(s)
//	cout << tab(5) << "+++ G a m e   O v e r +++\n\n";
//	cout << tab(2) << "----------------------------------------------------------------\n\n";
//}
//
//
//
//
//void PrintGameResults(const int& NumberOfRounds, const stWinCounter &WinCounter)
//{
//	PrintHeader();
//
//	cout << tab(2) << "----------------------[Game Results]----------------------------\n\n";
//	cout << tab(2) << "Game Rounds   : " << NumberOfRounds                << endl;
//	cout << tab(2) << "Player1 Wins  : " << WinCounter.PlayerWinCount     << endl;
//	cout << tab(2) << "Computer Wins : " << WinCounter.ComputerWinCount   << endl;
//	cout << tab(2) << "Draw Times    : " << WinCounter.DrawCount          << endl;
//	cout << tab(2) << "Final Winner  : " << ConvertWinToString(DetermineFinalWinner(WinCounter)) << endl;
//	cout << tab(2) << "---------------------------------------------------------------- \n\n";
//}
//
//
//char ReadCharacterValue(const string& message)
//{
//	char character;
//
//	cout << message;
//	cin >> character;
//	cout << endl;
//
//	return character;
//}
//
//
//bool ValidateCharacter(const char& character)
//{
//	return (character == 'Y' || character == 'y' || character == 'N' || character == 'n');
//}
//
//
//char ReadCharacter(string message)
//{   
//	int CountWinsAndDraws = 0;
//	char character;
//
//	do
//	{
//		CountWinsAndDraws++;
//		if (CountWinsAndDraws > 1)
//		{
//			cout << "Error- Wrong character.\n";
//		}
//
//		character = ReadCharacterValue(message);
//
//	} while (!ValidateCharacter(character));
//
//	return character;
//}
//
//enPlayAgain CastToEnumFromCharacter(char c)
//{
//	return (enPlayAgain)c;
//}
//
//bool PlayAgainChoice(enPlayAgain EnumC)
//{
//	switch (EnumC)
//	{
//	case enPlayAgain::Yes:
//	    return true;
//		
//
//	case enPlayAgain::yes:
//		return true;
//
//	case enPlayAgain::No:
//		return false;
//
//	case enPlayAgain::no:
//		return false;
//
//	default:
//		return false;    // to prevent compiler's complaint.
//	}
//}
//
//void SetWinnerConsoleColour(const enWinnerState& RoundWinner)
//{
//	switch (RoundWinner)
//	{
//	case enWinnerState::Player1:
//		system("color 20");
//		break;                  // a fall-through behaviour is induced if the break statement is not introduced.
//
//	case enWinnerState::Computer:
//		system("color 40");
//		cout << "\a";
//		break;
//
//	case enWinnerState::NoWinner:
//		system("color 60");
//		break;
//	}
//}
//
//void ResetConsole()
//{
//	system("cls");    // Clear the console screen from all text
//	system("color 07");  // Reset the console to the default colour: black background and light-gray text.
//}
//
//void StartGame()
//{
//  
//	bool PlayAgain;
//	// stWinCounter WinCounter;   // never place it here.
//
//	do
//	{
//		ResetConsole();   // does 2 things: clears all text, & resets the console colour to the default black-colored backgound.
//
//		stWinCounter WinCounter;  // member variables initialized to 0 everytime the program begins from the do statement.
//		short MinRound = 1;
//		short MaxRound = 10;
//		short NumberOfRounds = ReadShortInRange("How many rounds (" + to_string(MinRound) + " to " + to_string(MaxRound) + " )?: ", MinRound, MaxRound);
//
//		for (int i = 0; i < NumberOfRounds; i++)
//		{
//			stRoundInfo RoundInfo; 
//
//			cout << "\nRound [" << i + 1 << "] begins: \n\n";
//			
//			// Player's choice
//			short MinChoice = 1;
//			short MaxChoice = 3;
//			short c = ReadShortInRange("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?: ", MinChoice, MaxChoice );  // for example 2 of type int.
//			enChoice EnumC= CastToEnumFromShort(c);    // now becomes '2' of type enChoice.
//			RoundInfo.PlayerChoice = DetermineChoice(EnumC);
//			//enChoice PlayerChoice = DetermineChoice(EnumC);   // before creating a structure.
//
//			// Computer's choice:
//			int RandomNumber = ReadRandomNumberInRange(1, 3);   // our INEVITABLE CORE randomness utility that is implemented to ALWAYS return an integer.   
//			enChoice EnumRandomNumber = CastToEnumFromShort(RandomNumber);    // for example '2' of enChoice data type.
//			RoundInfo.ComputerChoice = DetermineChoice(EnumRandomNumber);
//			// enChoice ComputerChoice = DetermineChoice(EnumRandomNumber);    // before creating a structure.
//
//			// RoundWinner:
//			RoundInfo.RoundWinner = DetermineRoundWinner(RoundInfo.PlayerChoice, RoundInfo.ComputerChoice);
//			//enWinnerState RoundWinner = DetermineRoundWinner(PlayerChoice, ComputerChoice);  // before creating a structure.
//			// PrintRoundResults(i, PlayerChoice, ComputerChoice, RoundWinner);   // before creating a structure: You know something is wrong here (too many params = a structure user-defined data type
//			                                                                  // should've been created but it wasn't so start creating it IMMEDIATELY.
//			SetWinnerConsoleColour(RoundInfo.RoundWinner);
//			// The variable 'RoundInfo' is now fully initialized ( of the stRoundInfo structure user-defined data type):
//			CountWinsAndDraws(RoundInfo.RoundWinner, WinCounter); 
//			// 'WinCounter' is now initialized on line 209(WinCounter.ComputerWinCount ,  WinCounter.PlayerWinCount,  & WinCounter.DrawCount)
//			PrintRoundResults(i, RoundInfo);
//		}
//
//		// now outside of the for-loop and onto the Game over section.
//
//		PrintGameResults(NumberOfRounds, WinCounter);
//
//		char c = ReadCharacter(tab(2) + "Do you want to play again ? Y/N: ");   // example  'N' of char data type    // tab(2) called at the very end when it was needed. 
//		enPlayAgain EnumC = CastToEnumFromCharacter(c);     // 'N' is now of enPlayAgain  data type.
//		PlayAgain = PlayAgainChoice(EnumC);
//
//     // PlayAgain = Implement a function at the VERY end.
//
//	} while (PlayAgain);
//
//}
//
//
//
//
//
//int main()
//{
//	srand((unsigned)time(NULL));   // to seed random numbers.
//
//	StartGame();
//
//	return 0;
//}





//
/////////////// before the final- attempt solution
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };
//enum enPlayAgain { Yes = 'Y', yes = 'y', No = 'N', no = 'n' };
//
//// Now, looking for a state enums: There are only 2 winner states (possibilities) in the program: Player1, Computer, & No Winner.
//enum enWinnerState { Player1 = 1, Computer = 2, NoWinner = 3 };   // assign any integer value to each.
//
//// After coding enums, ALWAYS see if you can create structure(s)
//struct stRoundInfo
//{
//	enChoice PlayerChoice;
//	enChoice ComputerChoice;
//	enWinnerState RoundWinner;
//};
//
//
//struct stWinCounter
//{
//	int PlayerWinCount = 0;
//	int ComputerWinCount = 0;
//	int DrawCount = 0;
//
//};
//
//
//int ReadIntegerNumber(string message)
//{
//	int number;
//
//	cout << message;
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//
//bool ValidateIntegerInRange(const int& number, int min, int max)
//{
//	return (min <= number && number <= max);
//}
//
//
//
//int ReadIntegerInRange(const string& message, int min, int max)
//{
//	int number;
//
//	number = ReadIntegerNumber(message);
//
//	while (!ValidateIntegerInRange(number, min, max))
//	{
//		cout << "Error- Enter a valid number. \n";
//		number = ReadIntegerNumber(message);
//	}
//
//	return number;
//}
//
//
//enChoice CastToEnumFromInteger(int c)
//{
//	return (enChoice)c;
//}
//
//
//
//enChoice DetermineChoice(enChoice EnumC)
//{
//	switch (EnumC)
//	{
//	case enChoice::Paper:
//		return enChoice::Paper;
//
//	case enChoice::Scissors:
//		return enChoice::Scissors;
//
//	case enChoice::Stone:
//		return enChoice::Stone;
//
//	default:                       // included to prevent compiler from complaining. Plus, what if one had (by mistake):   return (enChoice)100;  for example (but one's only has that if no 
//		return enChoice::Paper;       // range validation ( MinChoice or MaxChoice) was.included 
//	}
//}
//
//
//
//int ReadRandomNumberInRange(int from, int to)     // our INEVITABLE CORE randomness utility that is implemented to ALWAYS return an integer.
//{
//	return rand() % (to - from + 1) + from;
//}
//
//
//
//
//enWinnerState DetermineRoundWinner(enChoice PlayerChoice, enChoice ComputerChoice)
//{
//	if (PlayerChoice == ComputerChoice)
//	{
//		system("color 60");
//		return enWinnerState::NoWinner;
//	}
//
//	else if (PlayerChoice == enChoice::Paper)
//	{
//		if (ComputerChoice == enChoice::Stone)
//		{
//			system("color 20");
//			return enWinnerState::Player1;
//		}
//
//		system("color 40");
//		cout << "\a";
//		return enWinnerState::Computer;  // scissors is what's left.
//
//	}
//
//	else if (PlayerChoice == enChoice::Scissors)
//	{
//		if (ComputerChoice == enChoice::Paper)
//		{
//			system("color 20");
//			return enWinnerState::Player1;
//		}
//
//		system("color 40");
//		cout << "\a";
//		return enWinnerState::Computer;   // stone is what's left.
//	}
//
//
//	else if (PlayerChoice == enChoice::Stone)
//	{
//		if (ComputerChoice == enChoice::Paper)
//		{
//			system("color 40");
//			cout << "\a";
//			return enWinnerState::Computer;
//		}
//
//		system("color 20");
//		return enWinnerState::Player1;   // stone is what's left.
//	}
//}
//
//
//string ConvertChoiceToString(enChoice choice)
//{
//	switch (choice)
//	{
//	case enChoice::Paper:
//		return "Paper";
//
//	case enChoice::Scissors:
//		return "Scissors";
//
//	case enChoice::Stone:
//		return "Stone";
//
//	default: "Internal Error..Check your code.";   // Include it so that no compiler complaints are rendered.
//	}
//}
//
//
//string ConvertWinToString(enWinnerState RoundWinner)   // revisit for argument name ( understand how i selected it)
//{
//	switch (RoundWinner)
//	{
//	case enWinnerState::Computer:
//		return "Computer";
//
//	case enWinnerState::Player1:
//		return "Player1";
//
//	case enWinnerState::NoWinner:
//		return "No Winner";
//
//	default: "Internal Error..Check your code.";  // Include it so that no compiler complaints are rendered.
//	}
//}
//
//
//
//
//
//void PrintRoundResults(const int& i, const stRoundInfo& RoundInfo)
//{
//	cout << "____________________________Round [" << i + 1 << "]____________________________\n\n";
//	cout << "Player1 Choice : " << ConvertChoiceToString(RoundInfo.PlayerChoice) << endl;   // AssociateWithString is better naming ?
//	cout << "Computer Choice: " << ConvertChoiceToString(RoundInfo.ComputerChoice) << endl;
//	cout << "Round Winner   : [" << ConvertWinToString(RoundInfo.RoundWinner) << "]" << endl << endl;
//	cout << "___________________________________________________________________________\n\n";
//}
//
//
//void CountWinsAndDraws(enWinnerState RoundWinner, stWinCounter& WinCounter)
//{
//	if (RoundWinner == enWinnerState::Computer)
//	{
//		WinCounter.ComputerWinCount++;
//	}
//
//	else if (RoundWinner == enWinnerState::Player1)
//	{
//		WinCounter.PlayerWinCount++;
//	}
//
//	else if (RoundWinner == enWinnerState::NoWinner)
//	{
//		WinCounter.DrawCount++;
//	}
//}
//
//
//enWinnerState DetermineFinalWinner(const stWinCounter& WinCounter)   // by const. ref. since we're only comparing.
//{
//	if (WinCounter.PlayerWinCount > WinCounter.ComputerWinCount)
//	{
//		return enWinnerState::Player1;
//	}
//
//	else if (WinCounter.PlayerWinCount < WinCounter.ComputerWinCount)
//	{
//		return enWinnerState::Computer;
//	}
//
//	return enWinnerState::NoWinner;
//}
//
//string ConvertFinalWinnerToString(enWinnerState FinalWinner)
//{
//	if (FinalWinner == enWinnerState::Computer)
//	{
//		return "Computer";
//	}
//
//	else if (FinalWinner == enWinnerState::Player1)
//	{
//		return "Player1";
//	}
//
//	return "No Winner";
//}
//
//
//void PrintGameResults(const int& NumberOfRounds, const stWinCounter& WinCounter)
//{
//	cout << "                   ----------------------------------------------------------------                \n\n";
//	cout << "                                    +++ G a m e   O v e r +++                                      \n\n";
//	cout << "                   ----------------------------------------------------------------                \n\n";
//	cout << "                   ----------------------[Game Results]----------------------------                \n\n";
//	cout << "                   Game Rounds   : " << NumberOfRounds << endl;
//	cout << "                   Player1 Wins  : " << WinCounter.PlayerWinCount << endl;
//	cout << "                   Computer Wins : " << WinCounter.ComputerWinCount << endl;
//	cout << "                   Draw Times    : " << WinCounter.DrawCount << endl;
//	cout << "                   Final Winner  : " << ConvertFinalWinnerToString(DetermineFinalWinner(WinCounter)) << endl;
//	cout << "                   ----------------------------------------------------------------                \n\n";
//}
//
//
//char ReadCharacterValue(const string& message)
//{
//	char character;
//
//	cout << message;
//	cin >> character;
//	cout << endl;
//
//	return character;
//}
//
//
//bool ValidateCharacter(const char& character)
//{
//	return (character == 'Y' || character == 'y' || character == 'N' || character == 'n');
//}
//
//
//char ReadCharacter(string message)
//{
//	int CountWinsAndDraws = 0;
//	char character;
//
//	do
//	{
//		CountWinsAndDraws++;
//		if (CountWinsAndDraws > 1)
//		{
//			cout << "Error- Wrong character.\n";
//		}
//
//		character = ReadCharacterValue(message);
//
//	} while (!ValidateCharacter(character));
//
//	return character;
//}
//
//enPlayAgain CastToEnumFromCharacter(char c)
//{
//	return (enPlayAgain)c;
//}
//
//bool PlayAgainChoice(enPlayAgain EnumC)
//{
//	switch (EnumC)
//	{
//	case enPlayAgain::Yes:
//		return true;
//
//
//	case enPlayAgain::yes:
//		return true;
//
//	case enPlayAgain::No:
//		return false;
//
//	case enPlayAgain::no:
//		return false;
//
//	default:
//		return false;    // to prevent compiler's complaint.
//	}
//}
//
//void StartGame()
//{
//
//	bool PlayAgain;
//	// stWinCounter WinCounter;   // never place it here.
//
//	do
//	{
//		stWinCounter WinCounter;  // member variables initialized to 0 everytime the program begins from the do statement.
//		int MinRound = 1;
//		int MaxRound = 10;
//		int NumberOfRounds = ReadIntegerInRange("How many rounds (" + to_string(MinRound) + " to " + to_string(MaxRound) + " )?: ", MinRound, MaxRound);
//
//		for (int i = 0; i < NumberOfRounds; i++)
//		{
//			stRoundInfo RoundInfo;
//
//			cout << "\nRound [" << i + 1 << "] begins: \n\n";
//
//			// Player's choice
//			int MinChoice = 1;
//			int MaxChoice = 3;
//			int c = ReadIntegerInRange("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?: ", MinChoice, MaxChoice);  // for example 2 of type int.
//			enChoice EnumC = CastToEnumFromInteger(c);    // now becomes '2' of type enChoice.
//			RoundInfo.PlayerChoice = DetermineChoice(EnumC);
//			//enChoice PlayerChoice = DetermineChoice(EnumC);   // before creating a structure.
//
//			// Computer's choice:
//			int RandomNumber = ReadRandomNumberInRange(1, 3);   // our INEVITABLE CORE randomness utility that is implemented to ALWAYS return an integer.   
//			enChoice EnumRandomNumber = CastToEnumFromInteger(RandomNumber);    // for example '2' of enChoice data type.
//			RoundInfo.ComputerChoice = DetermineChoice(EnumRandomNumber);
//			// enChoice ComputerChoice = DetermineChoice(EnumRandomNumber);    // before creating a structure.
//
//			// RoundWinner:
//			RoundInfo.RoundWinner = DetermineRoundWinner(RoundInfo.PlayerChoice, RoundInfo.ComputerChoice);
//			//enWinnerState RoundWinner = DetermineRoundWinner(PlayerChoice, ComputerChoice);  // before creating a structure.
//			// PrintRoundResults(i, PlayerChoice, ComputerChoice, RoundWinner);   // before creating a structure: You know something is wrong here (too many params = a structure user-defined data type
//																			  // should've been created but it wasn't so start creating it IMMEDIATELY.
//
//			// The variable 'RoundInfo' is now fully initialized ( of the stRoundInfo structure user-defined data type):
//			CountWinsAndDraws(RoundInfo.RoundWinner, WinCounter);
//			// 'WinCounter' is now initialized on line 209(WinCounter.ComputerWinCount ,  WinCounter.PlayerWinCount,  & WinCounter.DrawCount)
//			PrintRoundResults(i, RoundInfo);
//		}
//
//		// now outside of the for-loop and onto the Game over section.
//
//		PrintGameResults(NumberOfRounds, WinCounter);
//
//
//		char c = ReadCharacter("Do you want to play again ? Y/N: ");   // example  'N' of char data type
//		enPlayAgain EnumC = CastToEnumFromCharacter(c);     // 'N' is now of enPlayAgain  data type.
//		PlayAgain = PlayAgainChoice(EnumC);
//
//		// PlayAgain = Implement a function at the VERY end.
//
//	} while (PlayAgain);
//
//}
//
//
//
//
//
//int main()
//{
//	srand((unsigned)time(NULL));   // to seed random numbers.
//
//	StartGame();
//
//	return 0;
//}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////// Second-attempt solution
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*   My Approach:
     







   bool PlayAgain;

	do
	{






	 // PlayAgain = Implement a function at the VERY end.

	} while (PlayAgain);







*/


/*  before creating a structure (when I suddeny realized, at the last line of printing procedure, that I need a structure):
* 
* 
* int MinRound = 1;
		int MaxRound = 10;
		int NumberOfRounds = ReadIntegerInRange("How many rounds (" + to_string(MinRound) + " to " + to_string(MaxRound) + " )?: ", MinRound, MaxRound);

		for (int i = 0; i < NumberOfRounds; i++)
		{
			cout << "\nRound [" << i + 1 << "] begins: \n\n";
			
			// Player's choice
			int MinChoice = 1;
			int MaxChoice = 3;
			int c = ReadIntegerInRange("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?: ", MinChoice, MaxChoice );  // for example 2 of type int.
			enChoice EnumC= CastToEnumFromInteger(c);    // now becomes '2' of type enChoice.
			enChoice PlayerChoice = DetermineChoice(EnumC);

			// Computer's choice:
			int RandomNumber = ReadRandomNumberInRange(1, 3);   // our INEVITABLE CORE randomness utility that is implemented to ALWAYS return an integer.   
			enChoice EnumRandomNumber = CastToEnumFromInteger(RandomNumber);    // for example '2' of enChoice data type.
			enChoice ComputerChoice = DetermineChoice(EnumRandomNumber);

			// RoundWinner:
			enWinnerState RoundWinner = DetermineRoundWinner(PlayerChoice, ComputerChoice);

			PrintRoundResults(i, PlayerChoice, ComputerChoice, RoundWinner);   // too many params (did you miss a structure-creating step ?   Answer is - Yes )







*/







//
//// we ALWAYS start the program with enums when it's possible and logical to do so:
//enum enChoice { Paper = 2, Scissors = 3, Stone = 1};
//enum enPlayAgain { No = 'N', Yes = 'Y', no = 'n', yes = 'y' };
//
//// then, think if there are enums representing status/ state: 
//// 
//// below enums representing state ( should be re-named to enWinnerStatus ( or enWinnerState)
//enum enRoundWinner { Player1 = 1, Computer = 2, Draw = 3};  // should be changed to enWinnerStatus since it applies on both- the round (shows the winner) & the game result level (shows the final winner).
//
//// Immediately after enums, ask yourself is there any structure(s) to code: ( still 100 percent correct)
//
//struct stGameResults
//{
//	int Player1Wins;
//	int PcWins;
//	int draws;
//};
//
//
//stGameResults ReadGameResults()
//{
//	stGameResults GameResults;
//
//	GameResults.Player1Wins = 0;
//	GameResults.PcWins = 0;
//	GameResults.draws = 0;
//
//	return GameResults;
//	// no validation for each member variable as their values are not initialized via user-input.
//}
//
//
//int ReadIntegerNumber(string message)
//{
//	int number;
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
//bool ValidateNumberInRange(const int& number, int min, int max)
//{
//	return (min <= number && number <= max);
//}
//
//
//
//int ReadNumberInRange(string message, int min, int max)
//{
//	int number;
//
//    number = ReadIntegerNumber(message);
//	while (!ValidateNumberInRange(number, min, max))
//	{
//		cout << "Enter a valid number.\n";
//		number = ReadIntegerNumber(message);
//	}
//
//	return number;
//}
//
//
//
//enChoice CastToEnumFromInteger(int c)
//{
//	return (enChoice)c;
//}
//
//
//
//
//enChoice DetermineChoice(enChoice EnumC)
//{
//	switch (EnumC)
//	{
//	case enChoice::Paper:
//		return  enChoice::Paper; // 100 times better than : return "Paper"  (cuz  enChoice::Paper is ALREADY expressive enough/ the comparisons become spelling dependent when using strings (scissors instead of scissor)/ you're returning strings too early)
//
//	case enChoice::Scissors:
//		return enChoice::Scissors;
//
//	case enChoice::Stone:
//		return enChoice::Stone;
//
//	default:                       // ONLY necessary to avoid compiler's error. (also, think of it this way: what is the implementation by mistake is: return (enChoice)100; 
//		return enChoice::Paper;
//	}
//}
//
//
//int ReadRandomNumberInRange(int from, int to)
//{
//	return rand() % (to - from + 1) + from;
//}
//
//
//enChoice PcChoice(int i)
//{
//	int RandomNumber = ReadRandomNumberInRange(1,3);   // out CORE INEVIATABLE function for genrating random numbers. It MUST return integer for a start.
//	enChoice EnumRandomValue = CastToEnumFromInteger(RandomNumber);   // for example '3' (of enChoice data type).
//
//	enChoice  ComputerChoice = DetermineChoice(EnumRandomValue);
//	return ComputerChoice;
//}
//
//
//enChoice PlayerChoice(int i)
//{
//	cout << "\nRound[" << i+1 << "] begins: \n\n";
//
//	int MinChoice = 1;
//	int MaxChoice = 3;
//
//	int c = ReadNumberInRange("Your Choice: [1]: Stone, [2]: Paper, [3]:Scissors ?: ", MinChoice, MaxChoice);   // stores, for example '2' of type int.
//	enChoice EnumC = CastToEnumFromInteger(c);     // stores '2' of type enChoice
//
//	enChoice Player1Choice = DetermineChoice(EnumC);
//	return Player1Choice;
//}
//
//
//
//enRoundWinner DetermineRoundWinner(enChoice Player1Choice, enChoice ComputerChoice)
//{
//	if (Player1Choice == ComputerChoice)
//	{
//		system("color 60");
//		return enRoundWinner::Draw;            // instead of return "No Winner";
//	}
//
//	else if (Player1Choice == enChoice::Paper)
//	{
//		if (ComputerChoice == enChoice::Scissors)
//		{
//			system("color 40");
//			cout << "\a";
//			return enRoundWinner::Computer;      // instead of return "Computer";
//		}
//
//		else if(ComputerChoice == enChoice::Stone)
//		{
//			system("color 20");
//			return enRoundWinner::Player1;            // instead of return "Player1";
//		}
//	}
//
//	else if (Player1Choice == enChoice::Scissors)
//	{
//		if (ComputerChoice == enChoice::Stone)
//		{
//			system("color 40");
//			cout << "\a";
//			return enRoundWinner::Computer;      // instead of return "Computer";
//		}
//
//		else if (ComputerChoice == enChoice::Paper)
//		{
//			system("color 20");
//			return enRoundWinner::Player1;            // instead of return "Player1";
//		}
//	}
//
//	else if (Player1Choice == enChoice::Stone)
//	{
//		if (ComputerChoice == enChoice::Paper)
//		{
//			system("color 40");
//			cout << "\a";
//			return enRoundWinner::Computer;      // instead of return "Computer";
//		}
//
//		else if (ComputerChoice == enChoice::Scissors)
//		{
//			system("color 20");
//			return enRoundWinner::Player1;            // instead of return "Player1";
//		}
//	}
//}
//
//
//
//int CountNumberOfWinsAndDraws(enRoundWinner RoundWinner, stGameResults &GameResults)
//{
//	
//	if (RoundWinner == enRoundWinner::Player1)
//	{
//		return ++GameResults.Player1Wins;
//	}
//
//	else if (RoundWinner == enRoundWinner::Computer)
//	{
//		return ++GameResults.PcWins;
//	}
//
//	return ++GameResults.draws;
//}
//
//
//
//
//
//string ChoiceToString(enChoice Player1Choice)
//{
//	switch (Player1Choice)
//	{
//	case enChoice::Paper:
//		return  "Paper";
//
//	case enChoice::Scissors:
//		return "Scissors";
//
//	case enChoice::Stone:
//		return "Stone";
//
//	default:                       // ONLY necessary to avoid compiler's error. (also, think of it this way: what is the implementation by mistake is: fill in the blank; 
//		return "Paper";
//	}
//}
//
//
//
//string DetermineFinalWinner(stGameResults GameResults)
//{
//	if (GameResults.Player1Wins > GameResults.PcWins)
//	{
//		return "Player1";
//	}
//	else if (GameResults.PcWins > GameResults.Player1Wins)
//	{
//		return "Computer";
//	}
//
//	return "No Winner";
//}
//
//
//string RoundWinnerToString(enRoundWinner RoundWinner)
//{
//	switch (RoundWinner)
//	{
//	case enRoundWinner::Computer:
//		return "Computer";
//
//	case enRoundWinner::Player1:
//		return "Player1";
//
//	case enRoundWinner::Draw:
//		return "Draw";
//
//	default:                                         // Not including it renders comppiler's error.
//		return "Error- Internal Coding Error.";
//	}
//}
//
//
//
//void PrintRoundInfo(const int &i, const enChoice &Player1Choice, const enChoice &ComputerChoice, const enRoundWinner &RoundWinner)
//{
//	cout << "\n\n";
//	cout << "____________________Round[" << i + 1 << "]____________________\n\n";    // why + not working instead of <<
//	cout << "Player1 Choice : " << ChoiceToString(Player1Choice) << endl;
//	cout << "Computer Choice: " << ChoiceToString(ComputerChoice) << endl;
//	cout << "RoundWinner    : [" << RoundWinnerToString(RoundWinner) << "]" << endl << endl;
//	cout << "________________________________________________________\n\n\n";
//}
//
//
//
//
//void GameResult(const int &NumberOfRounds, const stGameResults &GameResults)
//{
//	cout << "                   ----------------------------------------------------------------                \n\n";
//	cout << "                                    +++ G a m e   O v e r +++                                      \n\n";
//	cout << "                   ----------------------------------------------------------------                \n\n";
//	cout << "                   ----------------------[Game Results]----------------------------                \n\n";
//	cout << "                   Game Rounds   : " << NumberOfRounds << endl;
//	cout << "                   Player1 Wins  : " << GameResults.Player1Wins << endl;
//	cout << "                   Computer Wins : " << GameResults.PcWins<< endl;
//	cout << "                   Draw Times    : " << GameResults.draws << endl;
//	cout << "                   Final Winner  : " << DetermineFinalWinner(GameResults) << endl << endl;
//	cout << "                   ----------------------------------------------------------------                \n\n";
//
//}
//
//
//
//char ReadCharactervalue(const string& message)
//{
//	char character;
//
//	cout << message;
//	cin >> character;
//	cout << endl;
//
//	return character;
//}
//
//
//
//bool ValidateCharacterRange(char character)
//{
//	return (character == 'Y'|| character == 'N' || character == 'y' || character == 'n');
//}
//
//
//
//char ReadPlayAgainResponse(string message)
//{
//	int CountWinsAndDraws = 0;
//	char character;
//
//	do
//	{
//		CountWinsAndDraws++;
//		if (CountWinsAndDraws > 1)
//		{
//			cout << "Error- Invalid Character\n";
//		}
//
//		character = ReadCharactervalue(message);
//
//	} while (!ValidateCharacterRange(character));
//
//	return character;
//}
//
//
//
//enPlayAgain CastToEnumFromChar(char c)
//{
//	return (enPlayAgain)c;
//}
//
//
//
//bool DeterminePlayAgainResponse(enPlayAgain EnumC)
//{
//	switch (EnumC)
//	{
//	case enPlayAgain::Yes:
//		return true;
//
//	case enPlayAgain::yes:
//			return true;
//
//	case enPlayAgain::No:
//		return false;
//
//	case enPlayAgain::no:
//		return false;
//
//	default: false;     // to avoid compiler's warning messages
//	}
//}
//
//
//
//void StartGame()   
//{
//	bool PlayAgain;
//	
//	do
//	{
//		int MinRound = 1;
//		int MaxRound = 10;
//		int NumberOfRounds = ReadNumberInRange("How Many Rounds (" + to_string(MinRound) + " to " + to_string(MaxRound) + ") ?: \n",    MinRound, MaxRound);
//
//		stGameResults GameResults = ReadGameResults();   //Where should I create my stGameResults variable so it exists for the whole game?  The answer is once, before the for loop begin( added when it turned out that it was needed).
//
//		for (int i = 0; i < NumberOfRounds; i++)
//		{
//			enChoice Player1Choice = PlayerChoice(i);
//			enChoice  ComputerChoice = PcChoice(i);
//			enRoundWinner RoundWinner = DetermineRoundWinner(Player1Choice, ComputerChoice);
//
//
//			CountNumberOfWinsAndDraws(RoundWinner, GameResults);  // Instead of having (RoundWinner, CountPlayerWins, CountPcWins, CountDraws)
//			PrintRoundInfo(i, Player1Choice, ComputerChoice, RoundWinner);   // nah, group them under a structure.
//		}
//
//		GameResult(NumberOfRounds, GameResults);
//		
//		char c = ReadPlayAgainResponse("Do you want to play again? Y/N?: ");
//		enPlayAgain EnumC = CastToEnumFromChar(c);
//
//		PlayAgain = DeterminePlayAgainResponse(EnumC);
//
//	} while (PlayAgain);
//}
//
//
//
//
//
//int main()
//{
//	srand((unsigned)time(NULL));   // to seed random numbers.
//
//	StartGame();
//
//	return 0;
//}








/* Notes:
   
   In the StartGame(), I started off with the following skeleton:


 void StartGame()
{
	bool PlayAgain;

	do
	{

	
	 PlayAgain = do it when at the end

	} while (PlayAgain);

 }

*/








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
// First attempt(below) SOME of the mistakes:

 1- you are converting enums to strings far too early. This is the biggest design issue:
    enChoice > string > then compare strings > if (MyChoice == "Stone")
 so, The entire game logic is now based on text. That means your program's correctness depends on spelling.
  Imagine changing "Scissor" to "Scissors"; Suddenly the game breaks.
  *** The enum already represents the choice.***


 2. DetermineChoice() has no default return
 Your switch covers all enum values. But the compiler cannot guarantee that. 
  for eaxample, If someone later casts enChoice x = (enChoice)100; your function reaches the end without returning anything.
 your function reaches the end without returning anything.


 3. Same issue in CheckResponse()


 4. CheckRoundWinner() is doing several jobs:
    It currently

 decides winner
 updates scores
 changes console color
 plays sound
 returns text

 That's a lot of responsibility. Functions become easier to maintain when each has one responsibility. 
 

 5. Heavy string comparisons: if (MyChoice == "Paper")    or  if (PcChoice == "Stone")
    String comparisons are more expensive and less robust than comparing enums.


 6.Magic strings: 
   The code depends on "Paper", "Stone", & "Scissor"

   appearing exactly the same in several places.
   Whenever identical literals appear repeatedly, ask yourself whether there's a better representation.
 
 7. Platforms dependence: system("color 20");   &  system("color 40"); are Windows-only. 
    Not a problem for the assignment, but worth remembering.

 8. Minor naming: PcRandomNumber   isn't really a random number anymore. It's an enum.
    The name becomes slightly misleading.
 
 */
  



/*
#include <iostream>
#include <string>   // to use to_string
#include <cstdlib>
#include <ctime>
using namespace std;



enum enChoice {Stone = 1, Paper = 2, Scissor = 3};
enum enPlayAgain {Yes = 'Y', No = 'N' };




int ReadIntegerNumber(const string& message)
{
	int number;

	cout << message;
	cin >> number;
	cout << endl;

	return number;
}



bool ValidateNumberInRange(const int& number, int MinRound, int MaxRound)
{
	return (MinRound <= number && number <= MaxRound);
}




int ReadChoiceInRange(const string& message, int MinRound, int MaxRound)
{
	int number;

	do
	{
		number = ReadIntegerNumber(message);

	} while (!ValidateNumberInRange(number, MinRound, MaxRound));

	return number;
}



enChoice CastToEnumFromInteger(int number)
{
	return (enChoice)number;
}



string DetermineChoice(enChoice ChoiceNumber)
{
	switch (ChoiceNumber)
	{
	case enChoice::Paper:
		return "Paper";

	case enChoice::Scissor:
			return "Scissor";

	case enChoice::Stone:
		return "Stone";
	}
}



int GenerateRandomNumberInRange(int from, int to)
{
	return rand() % (to - from + 1) + from;
}



string CheckRoundWinner(string MyChoice, string PcChoice, int &CountPlayer1Wins, int &CountPcWins, int &CountDraws)
{
	if (MyChoice == PcChoice)
	{
		CountDraws++;
		system("color 60");
		return "[No Winner]";
	}

	else if (MyChoice == "Scissor")
	{
		if (PcChoice == "Paper")
		{
			CountPlayer1Wins++;
			system("color 20");
			return "[Player1]";
		}
		else
		{
			CountPcWins++;
			system("color 40");
			cout << "\a";
			return "[Computer]";
		}
	}


	else if (MyChoice == "Stone")
	{
		if (PcChoice == "Paper")
		{
			CountPcWins++;
			system("color 40");
			cout << "\a";
			return "[Computer]";
		}
		else
		{
			CountPlayer1Wins++;
			system("color 20");
			return "[Player1]";
		}
	}

	else if (MyChoice == "Paper")
	{
		if (PcChoice == "Scissor")
		{
			CountPcWins++;
			system("color 40");
			cout << "\a";
			return "[Computer]";
		}
		else
		{
			CountPlayer1Wins++;
			system("color 20");
			return "[Player1]";
		}
	}

}


void PrintRoundResult(string MyChoice, string PcChoice, string RoundWinner, int i)
{
	cout << "\n\n";
	cout << "____________________Round[" << i << "]____________________\n\n";    // why + not working instead of <<
	cout << "Player1 Choice : " << MyChoice << endl;
	cout << "Computer Choice: " << PcChoice << endl;
	cout << "RoundWinner    : " << RoundWinner << endl << endl;
	cout << "________________________________________________________\n\n\n";
}



string DetermineFinalWinner(int CountPlayer1Wins, int CountPcWins, int CountDraws)
{
	if (CountPlayer1Wins > CountPcWins)
	{
		return "Player1";
	}
	else if (CountPlayer1Wins < CountPcWins)
	{
		return "Computer";
	}

	return "Draw";
}


void PrintGameResults(const int& NumberOfRounds, const int& CountPlayer1Wins, const int& CountPcWins, const int& CountDraws)
{
	cout << "                   ----------------------------------------------------------------                \n\n";
	cout << "                                    +++ G a m e   O v e r +++                                      \n\n";
	cout << "                   ----------------------------------------------------------------                \n\n";
	cout << "                   ----------------------[Game Results]----------------------------                \n\n";
	cout << "                   Game Rounds   : " << NumberOfRounds << endl;
	cout << "                   Player1 Wins  : " << CountPlayer1Wins << endl;
	cout << "                   Computer Wins : " << CountPcWins << endl;
	cout << "                   Draw Times    : " << CountDraws << endl;
	cout << "                   Final Winner  : " << DetermineFinalWinner(CountPlayer1Wins, CountPcWins, CountDraws) << endl <<endl;
	cout << "                   ----------------------------------------------------------------                \n\n";
}


char ReadCharacter(const string& message)
{
	char character;

	cout << message;
	cin >> character;
	cout << endl;

	return character;
}

bool ValidateCharacter(const char& character)
{
	return (character == 'Y' || character == 'N' );
}


char CheckResponse(const string& message)
{
	char character;
	do
	{
		character = ReadCharacter(message);

	} while (!ValidateCharacter(character));

	return character;
}


enPlayAgain CastToEnumFromCharacter(char ResponseChar)
{
	return (enPlayAgain)ResponseChar;
}



bool IsUserPlayingAgain(string message)
{
	char character = CheckResponse(message);
	enPlayAgain ResponceCharacter = CastToEnumFromCharacter(character);


	/*
	if((enPlayAgain)CheckResonse(message) == enPlayAgain::Yes)
	{
		return true;
	}

	return false; 
}


void StartGame()
{
	bool PlayAgain;

	do
	{
		int MinRound = 1;
		int MaxRound = 10;
		int NumberOfRounds = ReadChoiceInRange("How Many Rounds: (" + to_string(MinRound) + " to " + to_string(MaxRound) + "): \n", MinRound, MaxRound);

		int CountPlayer1Wins = 0;
		int CountPcWins = 0;
		int CountDraws = 0;


		int MinChoice = 1;
		int MaxChoice = 3;

		for (int i = 0; i < NumberOfRounds; i++)
		{
			cout << "\nRound " << "[" << i + 1 << "]" << " begins: \n\n";

			int ChoiceNumber = ReadChoiceInRange("Your Choice: [1]: Stone, [2]: Paper, [3]: Scissors ?: ", MinChoice, MaxChoice);
			enChoice MyChoiceNumber = CastToEnumFromInteger(ChoiceNumber);   // could be for example '3' (of data type enChoice)

			string MyChoice = DetermineChoice(MyChoiceNumber);

			int RandomNumber = GenerateRandomNumberInRange(1, 3);
			enChoice PcRandomNumber = CastToEnumFromInteger(RandomNumber);
			string PcChoice = DetermineChoice(PcRandomNumber);

			string RoundWinner = CheckRoundWinner(MyChoice, PcChoice, CountPlayer1Wins, CountPcWins, CountDraws);

			PrintRoundResult(MyChoice, PcChoice, RoundWinner, i);
		}

		PrintGameResults(NumberOfRounds, CountPlayer1Wins, CountPcWins, CountDraws);
		PlayAgain = IsUserPlayingAgain("Do you want to play again? Y/N?: ");

	} while (PlayAgain);

}




int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}

*/