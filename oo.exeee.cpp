
#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;


    if (s.empty()) {
        cout << "Not a valid Identifier" << endl;
        return 0;
    }


    if (!(isalpha(s[0]) || s[0] == '_')) {
        cout << "Not a valid Identifier" << endl;
        return 0;
    }


    for (int i = 1; i < s.size(); i++) {
        if (!(isalnum(s[i]) || s[i] == '_')) {
            cout << "Not a valid Identifier" << endl;
            return 0;
        }
    }

    cout << "Valid Identifier" << endl;
    return 0;
}
