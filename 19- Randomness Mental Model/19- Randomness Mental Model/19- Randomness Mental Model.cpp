
/*  Random numbers in C++:

               


    1- Include the library  #include <cstdlib>

    2- Rand() returns a random number between 0 and the max int value limit.

    3- To use this function -  Include for ONLY ONCE, in MAIN() :

       srand((unsigned)time(NULL));   // to seed random numbers.

        - This function commands the random generator to start from a specific number (initialization for the random generator).

        - If placed inside a function or a procedure (NOT INSIDE MAIN()),
          then the same exact number is going to be generated everytime.


    4- If we want to generate a random number between 0  &  9 then,
          one can take the first digit of the randomly generated number
          utilizing the mod 10 concept:

          rand() % 10

          because the number of digits in the remainder spans from 0 to the divisior-1


          EX: The randomly generated number is 563327
              then,
              563327 % 10   = 7



      but, we do this by creating a CORE RANDOM UTILITY function ALWAYS returning an integer (ALWAYS USED - AS IT'S WHAT'S USED FOR GENERATING A RANDOM NUMBER):

       int GenerateRandomNumberInRange(int from, int to)       // It's goal is to SIMPLY generate a random number [from,to]    // FORGET ABOUT THE ASCII TABLE, it's to generate a random number, it's that simple !
       {
        int RandNum = rand() % (To - from + 1) + from;      // for [0-9]+   we will have % 10
        return RandNum
       }

       So, THE FOUNDATION is generating a random integer number,

       and then if one wants, this returned integer
       can be converted to a keyboard character (ASCII character) using the char() function.

       Keyboard characters are:            Their respective integers

        - Small letters.                    --->  97-122
        - Capital letters.                  --->  65-90
        - Special charcters                 --->  33 -47  &   58-64   &  91-96  &   23-126
        - digits (0-9 on the keyboard).     --->  48-57



        Separate Note:

        The remainder of a % b is always between 0 and (b - 1), inclusive.

        Example:
        4523345 % 1000 = 345

        Since the divisor is 1000, the remainder must be between 0 and 999.
        345 falls within that range.

 */

#include <iostream>
#include <cstdlib>
using namespace std;




int GenerateRandomNumberInRange(int from, int to)   // it's goal here is to generate
{
    int random = rand() % (to - from + 1) + from; // seeds the random number generator in C++, called only once.

    return random;
}


int main()
{
    int from = 0;
    int to = 9;

    srand((unsigned)time(NULL));    // to seed random numbers.

    cout << "Below - randonly generated numbers between 0 and the max int boundary limit: \n\n";
    cout << rand() << endl << endl;
    cout << rand() << endl << endl;

    cout << "-----------------------------------------------\n\n";
    cout << "Randomly generating a number between " << from << " & " << to << " : " << GenerateRandomNumberInRange(from, to) << endl;
    cout << "Randomly generating a number between " << from << " & " << to << " : " << GenerateRandomNumberInRange(from, to) << endl;
    cout << "Randomly generating a number between " << from << " & " << to << " : " << GenerateRandomNumberInRange(from, to) << endl;



    return 0;
}







////////////// This example is demonstrate that placing the  srand((unsigned)time(NULL)) line inside a function / procedure
/////////////  is conducive to genrating the SAME number over and over (defaeting the purpose of the random number generator).
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int GenerateRandomNumberInRange(int from, int to)
{
    srand((unsigned)time(NULL));   // WRONG PLACE
    int random = rand() % (to - from + 1) + from; // seeds the random number generator in C++, called only once.

    return random;
}


int main()
{
    int from = 0;
    int to = 9;


    cout << "Below - randonly generated numbers between 0 and the max int boundary limit: \n\n";
    cout << rand() << endl << endl;
    cout << rand() << endl << endl;

    cout << "-----------------------------------------------\n\n";
    cout << "Randomly generating a number between " << from << " & " << to << " : " << GenerateRandomNumberInRange(from, to) << endl;
    cout << "Randomly generating a number between " << from << " & " << to << " : " << GenerateRandomNumberInRange(from, to) << endl;
    cout << "Randomly generating a number between " << from << " & " << to << " : " << GenerateRandomNumberInRange(from, to) << endl;



    return 0;
}



/*   Randomness Mental Model:
  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Pre-requisite: 

     This mental model is for generating random characters that are:
     
     1- Small Letters   2- Capital Letters   3- Special Characters   4- Digits.

     As for ONLY generating random numbers,
     then simple use the GenerateRandomNumberInRange()  CORE INEVITABLE UTILITY that should always return an integer.

     if your goal begins and ends with genrating numbers, then this approach suffices.
     Enums are to be ONLY used when dealing with the 4 types of random characters aforementioned above.

     
     
     
     
     
     SECTION ##A:

              1- Add:   #include <cstdlib>
                        #include <ctime>

              2- Include ONCE & only in main():      srand((unsigned)time(NULL));    // seeds random numbers  // one needs   #include <ctime>  library.
                        // without it OR if placed anywhere except in main(), then the random numbers will only be generated once and always remain the same.

              3- ALWAYS start the program with ENUMS as follows:

              enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, digit = 4 };

              you HAVE to include all of these enumeration constants (enumerators) even if one is asked to generate, for example, only capital letters
              as this deems our program maintainable, shall we need to modify our program to also generate special characters for example, etc.

 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    SECTION ##B:

     1- The core inevitable [GenerateRandomNumberInRange(from, to)] utility that SHOULD ALWAYS return an integer.

        Implementation:


        int GenerateRandomNumberInRange(int from, int to)  // pass by value.
        {
          return rand() % (to - from + 1) + from;
        }




   -----------------------------------------------------------------------------------------------
    2- This randomly generated number, can be converted to a keyboard character that's either:
       a small letter, a capital letter, a special character, a digit

       using the utility: [GenerateRandomCharacter()] that returns char,
       that takes the argument of an enum user-defined data type variable,

       that's compared in a switch statement against enumeration constants (enumerators) defined early in the enum creation step.
       and what's returned is the GenerateRandomNumberInRange(#,#) casted into char.


       Implementation:
       // this whole function serves just to return one single random character.

       char GenerateRandomCharacter(enCharType CharType)   // pass by value
       {
         switch(CharType)
         {
          case enCharType::SmallLetter:
               return char(GenerateRandomNumberInRange(97, 122));

          case enCharType::CapitalLetter:
               return char(GenerateRandomNumberInRange(65, 90));

           case enCharType::SpecialCharacter:
               return char(GenerateRandomNumberInRange(33, 47));

           case enCharType::digit:
               return char(GenerateRandomNumberInRange(48,57));

           default:
               return '\0';
           }
        }





        --------------------------------------------------------------------------------
        3- If one wants to generate more than just one character (we call it a word),

           then use, the   GenerateWord() utility   that takes 2 arguments:
            - An enum user-defined data type variable:  to determine whether the word will consist of random: small, capital, special, or digit characters.
            - Length of the word (should never be hardcoded).


            Implementation:


            string GenerateWord(enCharType CharType, short length)    // pass by value
            {
              string word = "";

               for (int i = 1; i <= length; i++)
               {
                  word = word + GenerateRandomCharacter(CharType);
               }

             return word;
            }




            -----------------------------------------------------------------------
            4- And if now, one wants to generate a key instead of just a word
                 Key example:  ETAI-HJUV-PEIP-CFRX

                 Then, use the utility:      Generatekey()



                Implementation:


                string Generatekey()            // pass by value.    //  Key example:  ETAI-HJUV-PEIP-CFRX
                {
                  string key = "";           // to initialize the declared variable.    // Concatenate four groups of 4 random uppercase letters, separated by hyphens.

                  key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
                  key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
                  key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
                  key = key + GenerateWord(enCharType::CapitalLetter, 4);

                  return key;
                }





                5- Now this generated key could be printed out in a printing procedure
                                                                  or be the argument of some function
                                                                  or sent to the backend
                                                                  or the frontend.


                                    



   

*/

// Now, THIS IS HOW TO THINK ABOUT IT: the logical order goes as follows:

// for example, to generate the following key:    TXOQ-/&*M-fmtd-7120
string GenerateKey()
{
    string key = "";   // declare and initialize first.

    key = GenerateWord(enCharType::CapitalLetter, 4) + "-"; 
    key = key + GenerateWord(enCharType::SpecialCharacter, 4) + "-";
    key = key + GenerateWord(enCharType::SmallLetter, 4) + "-";
    key = key + GenerateWord(enCharType::digit, 4);

    return key;
    // each argument is the value of the variable of the enum user defined data type that's enCharType CharType. 
    // Separate: keep in mind that enCharType CharType can only hold one value at a time.
    // 2nd argument is the length of the word
}

//Then, implement the GenerateWord() function:


string GenerateWord(enCharType CharType, int length)          
{
    string word = " ";

    for (int i = 0; i < length; i++)
    {
        word = word + GenerateRandomCharacter(CharType);        
    }

    return word;

     /* Notice how the value for example, enCharType::CapitalLetter, of the enum user - defined data type variable CharType,
        is tunneled through the GenrateWord() function,
        in order to be the argument of the switch statement (thats ALWAYS compared against the enumeration constants (enumerators)
       ,defined in the enum creation step, in the function GenerateRandomCharacter() that returns a single character.
     */
}


// Then, implement the generateRandomCharacter() function
// the purpose of this function is to simply return ONE random character:

char GenerateRandomCharacter(enCharType CharType)
{
    switch (CharType)
    { 
        case enCharType::SmallLetter:
            return char(GenerateRandomNumberInRange(97, 122)); //our CORE INEVITABLE randomness function that's implemented to ALWAYS return int. Hence, here the int returned value is casted into char and returned

        case enCharType::CapitalLetter:
            return char(GenerateRandomNumberInRange(65, 90));

        case enCharType::SpecialCharacter:
            return char(GenerateRandomNumberInRange(33, 47));

        case enCharType::digit:
            return char(GenerateRandomNumberInRange(48, 57));

        default:
            return '\0';
    }
}



// Then, implement our CORE INEVITABLE random number generator that's implemented to ALWAYS return an integer first.

int GenerateRandomNumberInRange(int from, int to)   // it's goal here is to generate
{
    int random = rand() % (to - from + 1) + from; // seeds the random number generator in C++, called only once.

    return random;
}