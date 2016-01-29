
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	// freopen("../input.txt", "rt", stdin);
	int i ,n, sum,len;
	char a[40];
	while(scanf("%s", a)) {
		if(a[0] == '0') {
			break;
		}
		n = 2;
		sum = 0;
		len = strlen(a);
		for(i = len-1; i >= 0; --i) {
			sum += (n-1) * (a[i] - '0');
			n *= 2;
		}
		printf("%d\n", sum);
	}
    return 0;
}