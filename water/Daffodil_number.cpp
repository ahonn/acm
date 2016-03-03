// Description
// The daffodil number is one of the famous interesting numbers in the mathematical world. A daffodil number is a three-digit number whose value is equal to the sum of cubes of each digit.

// For example. 153 is a daffodil as 153 = 13 + 53 + 33.

// Input
// There are several test cases in the input, each case contains a three-digit number.

// Output
// One line for each case. if the given number is a daffodil number, then output "Yes", otherwise "No".

// Sample Input
// 153
// 610

// Sample Output
// Yes
// No

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    // freopen("../input.txt", "rt", stdin);
    int n, a, b, c;
    while(scanf("%d", &n) != EOF) {
        a = n / 100;
        b = n % 100 / 10;
        c = n % 100 % 10;
        if (pow(a, 3) + pow(b, 3) + pow(c, 3) == n) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}