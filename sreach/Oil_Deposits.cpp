/* 
* @Author: ahonn
* @Date:   2016-02-07 21:33:18
* @Last Modified by:   ahonn
* @Last Modified time: 2016-02-09 14:13:23
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, ans;
char map[100][100];
int vis[100][100];
int dir[8][2] = {
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0, -1},
    { 0,  1},
    { 1, -1},
    { 1,  0},
    { 1,  1}
};

void DFS(int i, int j) {
    vis[i][j] = 1;
    for(int k= 0;k < 8;k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if(x >= 0 && x < n && y >= 0 && y < m && ! vis[x][y] && map[x][y] == '@') {
            DFS(x, y);
        }
    }
    return;
}

int main(){
    freopen("../input.txt", "rt", stdin);
    int i, j;
    while(scanf("%d %d", &n, &m)) {
        if( ! n && ! m) {
            break;
        }
        for(i = 0;i < n;i++) {
            scanf("%s", map[i]);
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for(i = 0;i < n;i++) {
            for(j = 0;j < m;j++) {
                if( ! vis[i][j] && map[i][j] == '@') {
                    ans++;
                    DFS(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}