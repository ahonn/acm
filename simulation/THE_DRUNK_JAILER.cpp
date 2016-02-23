// THE DRUNK JAILER

// Description
// A certain prison contains a long hall of n cells, each right next to each other. Each cell has a prisoner in it, and each cell is locked.
// One night, the jailer gets bored and decides to play a game. For round 1 of the game, he takes a drink of whiskey, and then runs down the hall unlocking each cell. For round 2, he takes a drink of whiskey, and then runs down the hall locking every other cell (cells 2, 4, 6, ...). For round 3, he takes a drink of whiskey, and then runs down the hall. He visits every third cell (cells 3, 6, 9, ...). If the cell is locked, he unlocks it; if it is unlocked, he locks it. He repeats this for n rounds, takes a final drink, and passes out.
// Some number of prisoners, possibly zero, realizes that their cells are unlocked and the jailer is incapacitated. They immediately escape.
// Given the number of cells, determine how many prisoners escape jail.

// Input
// The first line of input contains a single positive integer. This is the number of lines that follow. Each of the following lines contains a single integer between 5 and 100, inclusive, which is the number of cells n.

// Output
// For each line, you must print out the number of prisoners that escape when the prison has n cells.

// Sample Input
// 2
// 5
// 100

// Sample Output
// 2
// 10

#include <cstdio>
#include <iostream>

using namespace std;

int cell[105];

int main(){
    // freopen("../input.txt", "rt", stdin);
    int t, n, i, j, sum;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        sum = 0;
        for (i = 1; i <= n; ++i) {
            cell[i] = 1;
        }
        for (j = 2;j <= n; ++j) {
            for (i = 1;i <= n; ++i) {
                if (i % j == 0) {
                    cell[i] = ! cell[i];
                }
            }
        }
        for (i = 1;i <= n; ++i) {
            if (cell[i]) {
                sum ++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}