
#include <iostream>
#include <cmath>
using namespace std;


/*
 Problem #50

 Write a program to print Sqrt of numbers, don't use built in
 sqrt function.


 Input:
 25


 Output:

 My MySqrt Result: 5
 C++ sqrt Result: 5


*/


float ReadNumber(const string& message)   // chose not to range validate user input.
{
    float number;  // waht's returned

    cout << message;
    cin >> number;
    cout << endl;
    
    return number;
}



double CustomSqrt(float number)   // pass by value
{
    return pow(number, 0.5);
}



int main()
{
    
   float number =  ReadNumber("Enter number: ");

   cout << "MySqrt Result: " << CustomSqrt(number) << endl;
   cout << "C++ sqrt Result: " << sqrt(number) << endl << endl;

   return 0;
}


