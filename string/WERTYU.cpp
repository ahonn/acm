//WERTYU

// Description
// A common typing error is to place the hands on the keyboard one row to the right of the correct position. So "Q" is typed as "W" and "J" is typed as "K" and so on. You are to decode a message typed in this manner.


// Input
// Input consists of several lines of text. Each line may contain digits, spaces, upper case letters (except Q, A, Z), or punctuation shown above [except back-quote (`)]. Keys labelled with words [Tab, BackSp, Control, etc.] are not represented in the input.


// Output
// You are to replace each letter or punctuation symbol by the one immediately to its left on the QWERTY keyboard shown above. Spaces in the input should be echoed in the output.


// Sample Input
// O S, GOMR YPFSU/


// Sample Output
// I AM FINE TODAY.

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// freopen("input.txt", "rt", stdin);
	int i, j, len;
	char text[1000];
	char a[60] = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
	while(cin.getline(text, 1000)) {
		len = strlen(text);
		for(i = 0;i < len; ++i) {
			for(j = 0; a[j] != '\0'; ++j) {
				if(text[i] == a[j]) {
					text[i] = a[j-1];
					break;
				}
			}
			printf("%c", text[i]);
		}
		printf("\n");
	}
    return 0;
}