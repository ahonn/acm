// Palindromes

// Description
// A regular palindrome is a string of numbers or letters that is the same forward as backward. For example, the string "ABCDEDCBA" is a palindrome because it is the same when the string is read from left to right as when the string is read from right to left.
// A mirrored string is a string for which when each of the elements of the string is changed to its reverse (if it has a reverse) and the string is read backwards the result is the same as the original string. For example, the string "3AIAE" is a mirrored string because "A" and "I" are their own reverses, and "3" and "E" are each others' reverses.

// A mirrored palindrome is a string that meets the criteria of a regular palindrome and the criteria of a mirrored string. The string "ATOYOTA" is a mirrored palindrome because if the string is read backwards, the string is the same as the original and because if each of the characters is replaced by its reverse and the result is read backwards, the result is the same as the original string. Of course, "A", "T", "O", and "Y" are all their own reverses.
// 
// A list of all valid characters and their reverses is as follows.

// Character  Reverse  Character  Reverse  Character  Reverse  
//     A         A         M         M         Y         Y
//     B                   N                   Z         5
//     C                   O         O         1         1
//     D                   P                   2         S
//     E         3         Q                   3         E
//     F                   R                   4
//     G                   S         2         5         Z
//     H         H         T         T         6
//     I         I         U         U         7
//     J         L         V         V         8         8
//     K                   W         W         9
//     L         J         X         X
// Note that O (zero) and 0 (the letter) are considered the same character and therefore ONLY the letter "0" is a valid character.


// Input
// Input consists of strings (one per line) each of which will consist of one to twenty valid characters. There will be no invalid characters in any of the strings. Your program should read to the end of file.

// Output
// For each input string, you should print the string starting in column 1 immediately followed by exactly one of the following strings.
// " -- is not a palindrome." 
// if the string is not a palindrome and is not a mirrored string 
// " -- is a regular palindrome." 
// if the string is a palindrome and is not a mirrored string
// " -- is a mirrored string." 
// if the string is not a palindrome and is a mirrored string
// " -- is a mirrored palindrome." 
// if the string is a palindrome and is a mirrored string 
// Note that the output line is to include the -'s and spacing exactly as shown in the table above and demonstrated in the Sample Output below.
// In addition, after each output line, you must print an empty line.

// Sample Input 
// NOTAPALINDROME 
// ISAPALINILAPASI 
// 2A3MEAS 
// ATOYOTA

// Sample Output 
// NOTAPALINDROME -- is not a palindrome.

// ISAPALINILAPASI -- is a regular palindrome.

// 2A3MEAS -- is a mirrored string.

// ATOYOTA -- is a mirrored palindrome.

// T-T 有毒，因为一个小细节 WA 了 4 次

#include <cstdio>
#include <cstring>
using namespace std;

int i, j;
char d[10] = "1SE Z  8 ";
char a[27] = "A   3  HIL JM O   2TUVWXY5";

int isPalindromes(char str[]) {
	for(i = 0, j = strlen(str)-1; i < j; ++i, --j) {
		if((str[i] == '0' && str[j] == 'O') || (str[i] == 'O' && str[j] == '0')) {
				continue;
		}
		if(str[i] != str[j]) {
			return 0;
		}
	}
	return 1;
}

int isMirrored(char str[]) {
	char tmp[21];
	int len = strlen(str);
	for(i = 0,j = len-1;i < len ; ++i, --j) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			tmp[i] = a[str[i] - 'A'];
		}
		else {
			tmp[i] = d[str[i] - '1'];
		}

		if((tmp[i] == '0' && str[j] == 'O') || (tmp[i] == 'O' && str[j] == '0')) {
			continue;
		}
		if(tmp[i] != str[j]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	// freopen("input.txt", "rt", stdin);
	int p, m;
	char str[21];
	while(scanf("%s", str) != EOF) {
		p = isPalindromes(str);
		m = isMirrored(str);	
	
		if(p) {
			if(m) {
				printf("%s -- is a mirrored palindrome.\n\n", str);
			}
			else {
				printf("%s -- is a regular palindrome.\n\n", str);
			}
		}
		else {
			if(m) {
				printf("%s -- is a mirrored string.\n\n", str);
			}
			else {
				printf("%s -- is not a palindrome.\n\n", str);
			}
		}
	}
    return 0;
}