/*
using bitwise operators
AIM: To check if a given number is expressed as a power of two or not
*/

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		long long int input;
		cin >> input;
		if (!(input & (input - 1))) cout << "True" << endl;
		else                     cout << "False" << endl;
	}
	return 0;
}