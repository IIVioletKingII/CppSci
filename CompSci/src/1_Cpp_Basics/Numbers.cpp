#include <iostream>

using namespace std;

int main()
{
    // We can declare and assign a number at the same time
    int num1 = 10;
    
    // We can also declare several numbers at once
    int num2, num3, num4;
    
    // We can assign values to multiple variables at once
    num2 = num3 = num4 = 15;
    cout << "num1 + num2: " << num1 + num2 << endl;
    
    /* Beware: C++ let's us use a variable that has
     * been declared, even if we haven't assigned
     * a value yet. The value in that variable will
     * be the value last stored in that memory location,
     * which will not be a value we want to use.
     */
     
    int num5;
    
    cout << "num5: " << num5 << endl; // This will print a garbage value
    
    // C++ handles order of operations and operations with integers
    // similar to languages such as Java
    
    // Operations with two integers results in a truncated integer
    cout << "Integer division (15 / 10): " << num2 / num1 << endl;
    
    double double1;
    
    double1 = (double) num2 / num1;
    // Operations that contain a double results in a double
    cout << "Double division (15 / 10): " << double1 << endl;
    
    // If a string is a number, we can use stoi to convert to
    // and int and stod to convert to a double
    
    string str1 = "4";
    string str2 = "6.2";
    
    double sum = stoi(str1) + stod(str2);
    cout << "Sum of two converted numbers: " << sum << endl; 
    
    return 0;
}