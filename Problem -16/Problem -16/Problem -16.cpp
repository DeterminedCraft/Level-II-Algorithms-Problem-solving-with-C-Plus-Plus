

#include <iostream>
using namespace std;



/*
    Problem #16:

    Print
    Write a program to print all words from AAA to ZZZ.

    Output:

    AAA
    AAB
    AAC
    .
    .
    .
    ZZZ


*/



void PrintWordsFromAAAToZZZ()
{
    string word = "";

    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            for (int z = 1; z <= 26; z++)
            {
                word = word + char(64 + i);
                word = word + char(64 + j);
                word = word + char(64 + z);

                cout << word << endl;
                word = "";
            }
        }
    }
}






int main()
{

    PrintWordsFromAAAToZZZ();

	return 0;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*   // A faster approach: 

 void PrintWordsFromAAAToZZZ()
{
    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            for (int z = 1; z <= 26; z++)
            {
                cout << char(64 + i) << char(64 + j) << char(64 + z) << endl;
            }
        }
    }
}



*/

/*

  //////  A more readable version:

 void PrintWordsFromAAAToZZZ()
 {
     for (char first = 'A'; first <= 'Z'; first++)
     {
         for (char second = 'A'; second <= 'Z'; second++)
         {
             for (char third = 'A'; third <= 'Z'; third++)
             {
                cout << first << second << third << endl;
             }
         }
     }
 }


 }








*/