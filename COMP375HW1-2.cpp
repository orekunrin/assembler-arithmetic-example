// COMP375HW1-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program's purpose is to do some arithmetic (see below)

#include <iostream>

using namespace std;

int main()
{
	int seed, i, numMult = 16807, numDiv = 2147483647;
	cout << "Enter the random number seed>";
	cin >> seed;
	for (i = 0; i < 10000; i++) {
		_asm {// write the followingin assembler
			// seed = (16807 * seed) % 2147483647;
			mov eax, seed		// move the value of seed to the eax register
			mov ebx, numMult	// move the value of numMult to the ebx register
			mov ecx, numDiv		// move the value of numDiv to the ecx register
			imul ebx			// multiply the value in the ebx register by the value in the eax register
			idiv ecx
			mov seed, edx
		}
	}
	cout << "The 10,000th random number is " << seed << endl;
	if (seed != 1043618065) cout << "incorrect";
	else cout << "correct";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
