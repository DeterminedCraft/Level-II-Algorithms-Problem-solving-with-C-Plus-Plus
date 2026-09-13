
#include <iostream>
using namespace std;



/*
    Problem #17:

    Write a program that reads a 3-letter uppercase input from the user.

    Generate all combinations from AAA to ZZZ,
    comparing each one to the input until a match is found.

    Stop when the input is discovered and print the result.
 

    Input:
    AAF

    Output:

    Trial [1]: AAA
    Trial [2]: AAB
    Trial [3]: AAC
    Trial [4]: AAD
    Trial [5]: AAE
    Trial [6]: AAF

    word is AAF

    Found after 6 Trial(s)
*/


string ReadStringValue(const string& message)    // pass by constant references.
{
    string value;  // what's returned

    cout << message;
    cin >> value;
    cout << endl;

    return value;
}

bool ValidateValueLength(const string& value, size_t InputLength)  // Ranges ALWAYS passed by value.
{
    return (value.length() == InputLength);
}

string ReadLettersCombination(string message, size_t InputLength)
{
    int count = 0;   // teped at the end when it was needed.

    string value;   // what's returned.

    do
    {
        count++;
        if (count > 1)
        {
            cout << "Error - Input should be a " << InputLength << " character minimum. ";
        }

        value = ReadStringValue(message);  // 'value' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateValueLength(value, InputLength));   // the argument is written so that, it evaluates to TRUE when the condition is INVALID.

    return value;

    /* This block of code is to be sequentially composed line by line, & at the end implement the functions of: ReadStringValue()   &   ValidateValue() */
}


void PrintResults(const string& value)
{
    int count = 0;
    string word = "";

    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            for (int z = 1; z <= 26; z++)
            {
                word = word + char(64 + i);
                word = word + char(64 + j);
                word = word + char( 64 + z);

                count++;
                
                cout << "Trial [" << count << "] : " << word << endl;

                if (word == value)
                {
                    cout << " \nWord is: " << word << endl;
                    cout << "Found after " << count << " trial(s). \n";
                    return;
                }

                word = "";
                
            }
        }
    }
}



int main()
{

    size_t InputLength = 3;   // as for the range, that only allows capital letters - will be discussed in Level II C++ course.

    PrintResults(ReadLettersCombination("Enter a 3-letter uppercase word: ", InputLength));


    return 0; 
}



























































































