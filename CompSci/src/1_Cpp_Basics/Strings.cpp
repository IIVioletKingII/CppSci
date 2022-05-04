/* String needs to be included, but
 * it is included as part of the 
 * iostream package
 */
#include <iostream>

using namespace std;

int main()
{
    // Strings in C++ use a lowercase s
    string str = "Hello!";
    
    // C++ strings are mutable, so we can modify 
    // an existing string
    
    str.insert(5, " World");
    
    cout << str << endl;
    
    // We can find the length of a string using length
    cout << "String Length: " << str.length() << endl;
    
    // Substrings work similar than Java, using substr
    
    // Start at position 6 and go to the end (same as Java)
    cout << str.substr(6) << endl;
    
    // Start at 6 and take next 3 numbers (different than Java)
    cout << str.substr(6,3) << endl;
    
    // Get a character at a position
    char c = str[0];
    
    cout << "Character at position 1: " << c << endl;
    
    /* Note that .at and [ ] work the same if the index
     * is valid, but work different for an invalid index.
     * Try each of these statements out one at a time.
     */
     
    // cout << "Character at position 100: " << str.at(100) << endl;
    cout << "Character at position 100: " << str[100] << endl;

    return 0;
}