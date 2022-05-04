#include <iostream>

using namespace std;

int main()
{
    string s1, s2, s3;
    s1 = "hello";
    s2 = "world";
    
    // Try entering hello. Does it match one of my strings?
    cout << "Enter a string to compare to: ";
    getline(cin, s3);
    
    // Unlike Java, strings can be compared directly with ==
    if (s1 == s3) {
        cout << "Your string matches my first string, " << s1 << endl;
    }
    else if (s2 == s3) {
        cout << "Your string matches my second string, " << s2 << endl;
    }
    else {
        cout << "Your string doesn't match either of my strings." << endl;
        cout << "My strings are " << s1 << " and " << s2 << endl;
    }
    
    return 0;
}