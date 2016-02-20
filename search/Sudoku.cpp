/* 
* @Author: ahonn
* @Date:   2016-02-12 14:51:35
* @Last Modified by:   ahonn
* @Last Modified time: 2016-02-12 17:49:43
*/

#include <iostream>
#include <cstdio>
using namespace std;

char str[90];
int map[10][10];
int x[10][10];
int y[10][10];
int g[10][10];

int DFS(int i, int j) {
    int k, n, flag;
    if(i == 9) {
        return 1;
    }
    else {
        flag = 0;
        if(map[i][j]) {
            if(j == 8) {
                flag = DFS(i+1, 0);
            }
            else {
                flag = DFS(i, j+1);
            }

            return flag;
        }
        else {
            k = 3 * (i / 3) + j / 3;

            for(n = 1; n <= 9; ++n) {
                if( ! x[i][n] && ! y[j][n] && ! g[k][n]) {
                    map[i][j] = n;
                    x[i][n] = y[j][n] = g[k][n] = 1;
                
                    if(j == 8) {
                        flag = DFS(i+1, 0);
                    }
                    else {
                        flag = DFS(i, j+1);
                    }

                    if( ! flag) {
                        map[i][j] = 0;

                        x[i][n] = y[j][n] = g[k][n] = 0;
                    }
                    else {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
}

int main(){
    freopen("../input.txt", "rt", stdin);
    int n, i, j, k;
    while(scanf("%s", str) && str[0] != 'e') {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(g, 0, sizeof(g));
        for(i = 0;i < 9; ++i) {
            for(j = 0;j < 9; ++j) {
                n = str[i * 9 + j];
                if(n == '.') {
                    map[i][j] = 0;
                }
                else {
                    map[i][j] = n -'0';
                }

                if(map[i][j]) {
                    k = 3 * (i / 3) + j / 3;

                    x[i][map[i][j]] = y[j][map[i][j]] = g[k][map[i][j]] = 1;
                }
            }
        }
       DFS(0, 0);
       for(i = 0; i < 9; ++i) {
            for(j = 0; j < 9; ++j) {
                printf("%d", map[i][j]);
            }
       }
       printf("\n");
    }
    return 0;
}