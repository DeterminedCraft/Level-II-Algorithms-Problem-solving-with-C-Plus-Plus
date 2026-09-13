
#include <iostream>
#include <string>
using namespace std;


/*
    Problem #18:
    Write a program to read a text and encrypt it, decrypt it.

    Input:
    Mohammed

    Output:

    Text Before Encryption : Mohammed
    Text After Encryption  : Oqjcoogf
    Text After Decryption  : Mohammed

*/



string ReadStringValue(const string& message)    // pass by constant reference
{
    string value;   // what's returned.

    cout << message;
    getline(cin, value);
    cout << endl;

    return value;
}


bool ValidateTextLength(const string& value, size_t TextLength)   // pass by constant ref.   // Ranges ALWAYS passed by value.
{
    return (value.length() >= TextLength);
}




string ReadText(const string& message, size_t TextLength)   // pass by constant reference     // Range ALWAYS passed by value.
{
    string value;  // what's returned

    value = ReadStringValue(message);  // 'value' is to be IMMEDIATELY validated against the range, in the while condition.

    while (!ValidateTextLength(value, TextLength))
    {
        cout << "Error - Text should be at least " << TextLength << " character. ";
        value = ReadStringValue(message);
    }

    return value;
    /*The above block of code is to be sequentially composed line by line & at the end, implement the functions of:
       ReadStringValue()   &    ValidateTextLength() */
}




char EncryptLetter(string value, int i, short Encryptionkey)
{
    return char((int)value[i] + Encryptionkey);
}



string EncryptText(string value, short Encryptionkey)   // pass by value
{

    for (int i = 0; i < value.length(); i++)
    {
        value[i] =  EncryptLetter(value, i, Encryptionkey);        // char((int)value[i] + 2)   should have its own function no matter how small / simple this line is.
    }

    return value;
}

char DecryptLetter(string EncryptedText, int i, short Encryptionkey)
{
    return char((int)EncryptedText[i] - Encryptionkey);
}


string DecryptText(string EncryptedText, short Encryptionkey)  // pass by value
{
   
    for (int i = 0; i < EncryptedText.length(); i++)
    {
        EncryptedText[i] = DecryptLetter(EncryptedText, i, Encryptionkey);   // char((int)EncryptedText[i] - 2)  place it in a function no matter how small or simple this line looks like.
    }

    return EncryptedText;
}


void PrintTextAfterDecryption(const string& EncryptedText, short Encryptionkey)    // pass by constant reference.
{
    cout << "Text AFTER decryption is: " << DecryptText(EncryptedText, Encryptionkey) << endl;
}

void PrintAfterDecryption(short Encryptionkey, const string& value)    // pass by constant reference.
{
    string EncryptedText = EncryptText(value, Encryptionkey);

    cout << "Text before encryption: " << value << endl;   // do NOT wrap it in its own printing procedure as a variable(s) only is referenced.
    cout << "Text after encryption : " << EncryptedText << endl;
    PrintTextAfterDecryption(EncryptedText, Encryptionkey);

}


int main()
{
    const size_t TextLength = 1;  
    const short Encryptionkey = 2;

    PrintAfterDecryption(Encryptionkey, ReadText("Enter a text: ", TextLength)); // Range included as its value is NOT intrinsic.
    // This printing procedure contains:    TextAfterEncryption()   &  TextAfterDecryption().
    // this is a standard coding procedure
    // where as a side effect, this printing procedure will have access to the original text the user would enter.

    return 0;
}











//////////////////////////////////////////////////////// First-attempt solution ////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// First-attempt solution ////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// First-attempt solution ////////////////////////////////////////////////////////////////////////////
//
// 
// 
// 
// 
//string ReadStringValue(const string& message)    // pass by constant reference
//{
//    string value;   // what's returned.
//
//    cout << message;
//    getline(cin, value);
//    cout << endl;
//
//    return value; 
//}
//
//
//bool ValidateTextLength(const string& value, size_t TextLength)   // pass by constant ref.   // Ranges ALWAYS passed by value.
//{
//    return (value.length() >= TextLength);
//}
//
//
//
//
//string ReadText(const string& message, size_t TextLength)   // pass by constant reference     // Range ALWAYS passed by value.
//{
//    string value;  // what's returned
//
//    value = ReadStringValue(message);  // 'value' is to be IMMEDIATELY validated against the range, in the while condition.
//
//    while (!ValidateTextLength(value, TextLength))
//    {
//        cout << "Error - Text should be at least " << TextLength << " character. ";
//        value = ReadStringValue(message);
//    }
//
//    return value;
//    /*The above block of code is to be sequentially composed line by line & at the end, implement the functions of: 
//       ReadStringValue()   &    ValidateTextLength() */
//}
//
//
//
//
//char EncryptLetter(string value, int i)
//{
//    return char((int)value[i] + 2);
//}
//
//
//
//string EncryptText(string value)   // pass by value
//{
//    string encrypted = "";
//
//    for (int i = 0; i < value.length(); i++)
//    {
//        encrypted = encrypted + EncryptLetter(value, i);        // char((int)value[i] + 2)   should have its own function no matter how small / simple this line is.
//    }
//
//    return encrypted;
//}
//
//char DecryptLetter(string EncryptedText, int i)
//{
//    return char((int)EncryptedText[i] - 2);
//}
//
//
//string DecryptText(string EncryptedText)  // pass by value
//{
//    string decrypted = "";
//
//    for (int i = 0; i < EncryptedText.length(); i++)
//    {
//        decrypted = decrypted + DecryptLetter(EncryptedText, i);   // char((int)EncryptedText[i] - 2)  place it in a function no matter how small or simple this line looks like.
//    }
//
//    return decrypted;
//}
//
//
//void PrintTextAfterDecryption(const string& EncryptedText)    // pass by constant reference.
//{
//    cout << "Text AFTER decryption is: " << DecryptText(EncryptedText) << endl;
//}
//
//void PrintAfterDecryption(const string& value)    // pass by constant reference.
//{
//    string EncryptedText = EncryptText(value);
//
//    cout << "Text before encryption: " << value << endl;   // do NOT wrap it in its own printing procedure as a variable(s) only is referenced.
//    cout << "Text after encryption : " << EncryptedText << endl;
//    PrintTextAfterDecryption(EncryptedText);
//
//}
//
//
//int main()
//{
//    size_t TextLength = 1; 
//
//    PrintAfterDecryption(ReadText("Enter a text: ", TextLength)); // Range included as its value is NOT intrinsic.
//    // This printing procedure contains:    TextAfterEncryption()   &  TextAfterDecryption().
//    // this is a standard coding procedure
//    // where as a side effect, this printing procedure will have access to the original text the user would enter.
//
//    return 0;
//}


