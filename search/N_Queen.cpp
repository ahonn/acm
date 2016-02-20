// N 皇后问题

// Description
// 在N*N的方格棋盘放置了N个皇后，使得它们不相互攻击（即任意2个皇后不允许处在同一排，同一列，也不允许处在与棋盘边框成45角的斜线上。
// 你的任务是，对于给定的N，求出有多少种合法的放置方法。

// Input
// 共有若干行，每行一个正整数N≤10，表示棋盘和皇后的数量；如果N=0，表示结束。

// Output
// 共有若干行，每行一个正整数，表示对应输入行的皇后的不同放置数量。

// Sample Input
// 1
// 8
// 5
// 0

// Sample Output
// 1
// 92
// 10

#include <iostream>
#include <cstdio>
using namespace std;

int n;
int x[100];
int ans[11];

bool vaild(int k) {
    for (int i = 1; i < k; ++i) {
        if (x[i] == x[k] || abs(x[i]-x[k]) == abs(i-k)) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("../input.txt", "rt", stdin);
    int k;
    memset(ans, 0, sizeof(ans));
    while (scanf("%d", &n) && n) {
        if (ans[n]>0) {
            printf("%d\n", ans[n]);
            continue;
        }

        x[1] = 0;
        ans[n] = 0;
        k = 1;
        while (k > 0) {
            x[k]++;
            while (x[k] <= n && ! vaild(k)) {
                x[k]++;
            }
            if (x[k] <= n) {
                if (k == n) {
                    ans[n]++;
                }
                else {
                    k++;
                    x[k] = 0;
                }
            }
            else {
                k--;
            }
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}
