// Linear Pachinko

// Description
// This problem is inspired by Pachinko, a popular game in Japan. A traditional Pachinko machine is a cross between a vertical pinball machine and a slot machine. The player launches small steel balls to the top of the machine using a plunger as in pinball. A ball drops through a maze of pins that deflect the ball, and eventually the ball either exits at a hole in the bottom and is lost, or lands in one of many gates scattered throughout the machine which reward the player with more balls in varying amounts. Players who collect enough balls can trade them in for prizes.

// For the purposes of this problem, a linear Pachinko machine is a sequence of one or more of the following: holes ("."), floor tiles ("_"), walls ("|"), and mountains ("/\"). A wall or mountain will never be adjacent to another wall or mountain. To play the game, a ball is dropped at random over some character within a machine. A ball dropped into a hole falls through. A ball dropped onto a floor tile stops immediately. A ball dropped onto the left side of a mountain rolls to the left across any number of consecutive floor tiles until it falls into a hole, falls off the left end of the machine, or stops by hitting a wall or mountain. A ball dropped onto the right side of a mountain behaves similarly. A ball dropped onto a wall behaves as if it were dropped onto the left or right side of a mountain, with a 50% chance for each. If a ball is dropped at random over the machine, with all starting positions being equally likely, what is the probability that the ball will fall either through a hole or off an end?

// For example, consider the following machine, where the numbers just indicate character positions and are not part of the machine itself:

// 123456789
// /\.|__/\.
// The probabilities that a ball will fall through a hole or off the end of the machine are as follows, by position: 1=100%, 2=100%, 3=100%, 4=50%, 5=0%, 6=0%, 7=0%, 8=100%, 9=100%. The combined probability for the whole machine is just the average, which is approximately 61.111%.

// Input: The input consists of one or more linear Pachinko machines, each 1–79 characters long and on a line by itself, followed by a line containing only "#" that signals the end of the input.

// Output: For each machine, compute as accurately as possible the probability that a ball will fall through a hole or off the end when dropped at random, then output a single line containing that percentage truncated to an integer by dropping any fractional part.

// Example input:  
// /\.|__/\.
// _._/\_|.__/\./\_
// ...
// ___
// ./\.
// _/\_
// _|.|_|.|_|.|_
// ____|_____
// #

// Example output:
// 61
// 53
// 100
// 0
// 100
// 50
// 53
// 10

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c[100];
int len;

int left(int i) {
    for (int j = i-1; j >= 0; --j) {
        if (c[j] == '|' || c[j] == '\\' || c[j] == '/') {
            return 0;
        }
        if (c[j] == '.') {
            return 1;
        }
    }
    return 1;
}

int right(int i) {
    for (int j = i + 1; j < len; ++j) {
        if (c[j] == '|' || c[j] == '\\' || c[j] == '/') {
            return 0;
        }
        if (c[j] == '.') {
            return 1;
        }
    }
    return 1;
}

int main(){
    // freopen("../input.txt", "rt", stdin);
    int i, sum;
    while(scanf("%s", c) && c[0] != '#') {
        len = strlen(c);
        sum = 0;
        for(i = 0; i < len; ++i) {
            switch(c[i]) {
                case '_': 
                    break;
                case '.':
                    sum += 100;
                    break;
                case '/':
                    sum += left(i) * 100;
                    break;
                case '\\':
                    sum += right(i) * 100;
                    break;
                case '|':
                    sum += left(i) * 50 + right(i) * 50;
                    break;
            }
        }
        printf("%d\n", sum / len);
    }
    return 0;
}
