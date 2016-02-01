// Octal Fractions

// Description
// Fractions in octal (base 8) notation can be expressed exactly in decimal notation. For example, 0.75 in octal is 0.963125 (7/8 + 5/64) in decimal. All octal numbers of n digits to the right of the octal point can be expressed in no more than 3n decimal digits to the right of the decimal point.

// Write a program to convert octal numerals between 0 and 1, inclusive, into equivalent decimal numerals. The input to your program will consist of octal numbers, one per line, to be converted. Each input number has the form 0.d1d2d3 ... dk, where the di are octal digits (0..7). There is no limit on k. Your output will consist of a sequence of lines of the form

// 0.d1d2d3 ... dk [8] = 0.D1D2D3 ... Dm [10]

// where the left side is the input (in octal), and the right hand side the decimal (base 10) equivalent. There must be no trailing zeros, i.e. Dm is not equal to 0.

// SAMPLE INPUT
// 0.75
// 0.0001
// 0.01234567

// SAMPLE OUTPUT
// 0.75 [8] = 0.953125 [10]
// 0.0001 [8] = 0.000244140625 [10]
// 0.01234567 [8] = 0.020408093929290771484375 [10]

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;

int main(){
	// freopen("../input.txt", "rt", stdin);
	char b8[N], b10[3 * N];
	double sum, f;
	int i, len, maxl;
	while(scanf("%s", b8) != EOF) {
		len = strlen(b8);

		// （5 * 125 * 125） + (7 * 125 * 1000) / 1000000
		sum = 0, f = 1;
		for(i = len-1; i > 1; --i) {
			sum = ((b8[i]-'0') * f + sum) * 125;
			f *= 1000;
		}
		sum /= f;

		b10[0] = '0', b10[1] = '.';
		maxl = (len-2) * 3 + 2;
		for(i = 2; i < maxl; ++i) {
			sum *= 10;
			b10[i] = int(sum) % 10 + '0';
			sum -= b10[i]-'0';
		}
		b10[i] = '\0';
		for(i = maxl-1; i > 2; --i) {
			if(b10[i] == '0') {
				b10[i] == '\0';
			}
			else {
				break;
			}
		}
		printf("%s [8] = %s [10]\n", b8, b10);
	}
    return 0;
}