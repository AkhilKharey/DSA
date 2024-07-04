#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // Define the regular expression pattern
    string pattern = R"(\d{3}\.?\d{4}\.?[a-zA-Z])";
    regex regexPattern(pattern);
// check for pattern nnn.nnnn.c where . is optional
    // Test strings
    string test1 = "123.4567.a";
    string test2 = "1234567b";
    string test3 = "123.4567c";
    string test4 = "123.45678.d"; // Invalid string
    string test5="ryz.1187.c";
    // Match test strings against the pattern
    if (regex_match(test5, regexPattern)) {
        cout << test5 << " matches the pattern." << endl;
    } else {
        cout << test5 << " does not match the pattern." << endl;
    }

    if (regex_match(test2, regexPattern)) {
        cout << test2 << " matches the pattern." << endl;
    } else {
        cout << test2 << " does not match the pattern." << endl;
    }

    if (regex_match(test3, regexPattern)) {
        cout << test3 << " matches the pattern." << endl;
    } else {
        cout << test3 << " does not match the pattern." << endl;
    }

    if (regex_match(test4, regexPattern)) {
        cout << test4 << " matches the pattern." << endl;
    } else {
        cout << test4 << " does not match the pattern." << endl;
    }

    return 0;
}
