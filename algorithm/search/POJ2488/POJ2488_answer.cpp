#include <stdio.h>

int dir[8][2] = {-2, -1, -2, 1, -1, -2, 1, -2, 1, 2, 2, -1, 2, 1};
int g, a, b;
int vist[26][26], path[26][2];

void find(int i, int j, int k){
    if(k == a*b){
        for(int i = 0; i < k; ++i)
            printf("%c%d", path[i][0]='A', path[i][1]+1);
        printf('\n');
        g = 1;
    }else{
        for(int x = 0; x < 8; x++){
            int n = dir[x][0] + i;
            int m = dir[x][1] + j;
            vist[n][m] = 1;
            find(n, m, k+1);
            path[k][0] = n, path[k][1] = m;
            vist[n][m] = 0;
        }
    }
}

int main(){
    int n ;
    scanf("%d", &n);
    for(int m = 0; m < n; ++m){
        g = 0;
        scanf("%d%d", &a, &b);
        for(int i = 0; i < a; ++i)
            for(int j = 0; j < b; ++j)
                vist[i][j] = 0;
        vist[0][0] = 1;
        path[0][0] = 0, path[0][1] = 0;
        printf("Scenario #%d:\n", m+1);
        find(0, 0, 1);
        if(!g) printf("impossible\n");
        printf("\n");
    }
    return 0;
}
