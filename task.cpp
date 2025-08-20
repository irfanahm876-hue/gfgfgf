
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

// Keywords
string keywords[] = {"int","float","double","char","if","else","for","while","return","void","main"};

// Functions
bool isKeyword(string s) {
    for(string k: keywords)
        if(s == k) return true;
    return false;
}

bool isValidIdentifier(string s) {
    if(s.empty()) return false;
    if(!isalpha(s[0]) && s[0]!='_') return false;
    for(char c: s)
        if(!isalnum(c) && c!='_') return false;
    return true;
}

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='=' || c=='<' || c=='>';
}

bool isDelimiter(char c) {
    return c==',' || c==';' || c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']';
}

bool isInteger(string s) {
    for(char c: s) if(!isdigit(c)) return false;
    return !s.empty();
}

bool isRealNumber(string s) {
    int dot = 0;
    for(char c: s) {
        if(c=='.') dot++;
        else if(!isdigit(c)) return false;
    }
    return (dot==1);
}

int main() {
    ifstream file("program.txt"); // file to read
    if(!file) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    char ch;
    string word;
    while(file.get(ch)) {
        if(isspace(ch)) continue; // skip space

        // Operator
        if(isOperator(ch)) {
            cout << ch << " -> Operator" << endl;
        }
        // Delimiter
        else if(isDelimiter(ch)) {
            cout << ch << " -> Delimiter" << endl;
        }
        // Identifiers / Keywords
        else if(isalpha(ch) || ch=='_') {
            word = "";
            while(isalnum(ch) || ch=='_') {
                word += ch;
                file.get(ch);
            }
            file.unget();
            if(isKeyword(word)) cout << word << " -> Keyword" << endl;
            else if(isValidIdentifier(word)) cout << word << " -> Valid Identifier" << endl;
            else cout << word << " -> Invalid Identifier" << endl;
        }
        // Numbers
        else if(isdigit(ch)) {
            word = "";
            while(isdigit(ch) || ch=='.') {
                word += ch;
                file.get(ch);
            }
            file.unget();
            if(isInteger(word)) cout << word << " -> Integer" << endl;
            else if(isRealNumber(word)) cout << word << " -> Real Number" << endl;
        }
    }

    file.close();
    return 0;
}
