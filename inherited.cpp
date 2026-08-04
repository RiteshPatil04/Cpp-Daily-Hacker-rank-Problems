// You inherited a piece of code that performs username validation for your company's website. The existing function works reasonably well, but it throws an exception when the username is too short. Upon review, you realize that nobody ever defined the exception.

// The inherited code is provided for you in the locked section of your editor. Complete the code so that, when an exception is thrown, it prints Too short: n (where  is the length of the given username).

// Input Format

// The first line contains an integer, , the number of test cases.
// Each of the  subsequent lines describes a test case as a single username string, .

// Constraints

// The username consists only of uppercase and lowercase letters.
// Output Format

// You are not responsible for directly printing anything to stdout. If your code is correct, the locked stub code in your editor will print either Valid (if the username is valid), Invalid (if the username is invalid), or Too short: n (where  is the length of the too-short username) on a new line for each test case.

// Sample Input

// 3
// Peter
// Me
// Arxwwz
// Sample Output

// Valid
// Too short: 2
// Invalid
// Explanation

// Username Me is too short because it only contains  characters, so your exception prints .
// All other validation is handled by the locked code in your editor.

// Language
// C++11
// More
// 2827262425212223820761910111213141516171819

//     int what() {
//         return len;
//     }
// };

// bool checkUsername(string username) {
// 	bool isValid = true;
// 	int n = username.length();
// 	if(n < 5) {

// Line: 15 Col: 1

// Test against custom input
// CPP
// You have earned 30.00 points!
// 17/44 challenges solved.
// 39%
// Congratulations
// You solved this challenge. Would you like to challenge your friends?Share on FacebookShare on TwitterShare on LinkedIn

// Test case 0

// Test case 1

// Test case 2

// Test case 3

// Test case 4

// Test case 5

// Test case 6

// Test case 7

// Test case 8

// Test case 9
// Compiler Message
// Success
// Input (stdin)
// 3
// Peter
// Me
// Arxwwz
// Expected Output
// Valid
// Too short: 2
// Invalid
// Blog

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException {
    int len;

public:
    BadLengthException(int n) {
        len = n;
    }

    int what() {
        return len;
    }
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}