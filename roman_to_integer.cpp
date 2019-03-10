#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class rToI {
public:
	int romanToInt(string s) {
		int stringLength = s.length(), value = 0;
		for (int i = 0; i < stringLength; i++)
		{
			if (s[i] == 'I' && s[i + 1] == 'V')
			{
				value += 4;
				i++;
			}
			else if (s[i] == 'I' && s[i + 1] == 'X') {
				value += 9;
				i++;
			}
			else if (s[i] == 'X' && s[i + 1] == 'L') {
				value += 40;
				i++;
			}
			else if (s[i] == 'X' && s[i + 1] == 'C') {
				value += 90;
				i++;
			}
			else if (s[i] == 'C' && s[i + 1] == 'D') {
				value += 400;
				i++;
			}
			else if (s[i] == 'C' && s[i + 1] == 'M') {
				value += 900;
				i++;
			}
			else if (s[i] == 'I') {
				value += 1;
			}
			else if (s[i] == 'V') {
				value += 5;
			}
			else if (s[i] == 'X') {
				value += 10;
			}
			else if (s[i] == 'L') {
				value += 50;
			}
			else if (s[i] == 'C') {
				value += 100;
			}
			else if (s[i] == 'D') {
				value += 500;
			}
			else if (s[i] == 'M') {
				value += 1000;
			}
		}
		return value;
	}
};

int main(int argc, char* argv)
{
	rToI firstTry;
	bool inputValid = false;
	bool repeat = true;
	char allowedRoman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	string roman;
	cout << "Roman to Integer (from LeetCode problem 13)\n\n";;
	cout << "Enter a roman numeral:  ";
	cin >> roman;
	while (repeat)
	{
		for (int i = 0; i < roman.length(); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (roman[i] == allowedRoman[j])
				{
					inputValid = true;
					break;
				}
				else 
					inputValid = false;
			}
			if (!inputValid)
				break;
		}

		if (inputValid)
			repeat = false;
		else {
			cout << "Invalid input.\n" << "Enter a roman numeral:  ";
			cin >> roman;
			repeat = true;
		}
	}
	cout << "Result: ";
	cout << firstTry.romanToInt(roman) << endl;
	return 0;
}
