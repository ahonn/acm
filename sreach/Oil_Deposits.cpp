// Oil Deposits

// Description
// The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil. A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid.
// Input
// The input contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100. Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either `*', representing the absence of oil, or `@', representing an oil pocket. 

// Output
// are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets.

// Sample Input
// 1 1
// *
// 3 5
// *@*@*
// **@**
// *@*@*
// 1 8
// @@****@*
// 5 5 
// ****@
// *@@*@
// *@**@
// @@@*@
// @@**@
// 0 0

// Sample Output
// 0
// 1
// 2
// 2

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
    // freopen("../input.txt", "rt", stdin);
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