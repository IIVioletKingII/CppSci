#include <iostream>

using namespace std;

int main()
{
    int temp;
    string raining;
    cout << "Please enter a temperature: ";
    cin >> temp;
    cout << "Is it raining? (yes or no) ";
    cin >>raining;
    
    // Remember, we need to state the variable each time
    // we cannot do this: 60 <= temp <= 95
    if (temp >= 60 && temp <= 95 && raining != "yes") {
        cout << "It is a good day to be outside!" << endl;
    }
    else {
        cout << "You may want to stay in." << endl;
    }
    return 0;
}