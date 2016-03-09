// Description
// A group of n gamblers decide to play a game:

// At the beginning of the game each of them will cover up his wager on the table and the assitant must make sure that there are no two gamblers have put the same amount. If one has no money left, one may borrow some chips and his wager amount is considered to be negative. Assume that they all bet integer amount of money.

// Then when they unveil their wagers, the winner is the one who's bet is exactly the same as the sum of that of 3 other gamblers. If there are more than one winners, the one with the largest bet wins.

// For example, suppose Tom, Bill, John, Roger and Bush bet $2, $3, $5, $7 and $12, respectively. Then the winner is Bush with $12 since $2 + $3 + $7 = $12 and it's the largest bet.

// Input

// Wagers of several groups of gamblers, each consisting of a line containing an integer 1 <= n <= 1000 indicating the number of gamblers in a group, followed by their amount of wagers, one per line. Each wager is a distinct integer between -536870912 and +536870911 inclusive. The last line of input contains 0.
// Output

// For each group, a single line containing the wager amount of the winner, or a single line containing "no solution".
// Sample Input

// 5
// 2 
// 3 
// 5 
// 7 
// 12
// 5
// 2 
// 16 
// 64 
// 256 
// 1024
// 0
// Output for Sample Input

// 12
// no solution

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
long long w[1005];

int search(int k, int wh) {
    int l, r, m;
    l = k+1;    r = n-1;
    while(l <= r) {
        m = (l + r) >> 1;
        if (w[m] == wh) {
            return m;
        }
        if(w[m] < wh) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return 0;
}

int find() {
    int i, j, k, wh, hasH;
    for (i = n-1; i > 0; --i) {
        for (j = 0; j < i; ++j) {
            for (k = j+1; k < n; ++k) {
                wh = w[i] - w[j] - w[k];
                hasH = search(k, wh);
                if (hasH &&  hasH != i && hasH != j && hasH != k) {
                    return i;
                }
            }
        }
    }
    return -1;
}

int main(){
    // freopen("../input.txt", "rt", stdin);
    while(scanf("%d", &n) && n) {
        memset(w, 0, sizeof(w));
        for(int i = 0;i < n; ++i) {
            scanf("%lld", &w[i]);
        }
        sort(w, w+n);
        int ans = find();
        if (ans != -1) {
            printf("%lld\n", w[ans]);
        }
        else {
            printf("no solution\n");
        }
    }
    return 0;
}
