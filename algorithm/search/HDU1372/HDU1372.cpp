#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

const int MAX_NUM = 9;
int dir[8][2] = {{-2, -1},{-2, 1},{-1, -2},{-1, 2},{1, -2},{1, 2},{2, -1},{2, 1}};
int visit[MAX_NUM][MAX_NUM];
int ans = 0;

int search(int row, char col, int des_row, char des_col, int step){
    col -= 'a';
    if(visit[row][col-'a'] == 1 && row < 0 && col < 'a' && row > 7 && col > 'h'){
        return step;
    }
    if(row == des_row && col == des_col){
        ans = step > ans ? ans : step;
        return ans;
    }
    for(int i = 0; i < 8; ++i){
        int t_r = row + dir[i][0];
        int t_c = col + dir[i][1];
        if(visit[t_r][t_c] != 1 || step > 8)
            search(t_r, t_c+'a', des_row, des_col, step);
        visit[t_r][t_c] = 0;
    }
    return ans;
}

void init(){
    memset(visit, 0, sizeof(int)*MAX_NUM*MAX_NUM);
    ans = 0;
}

int main(){
    int s_r, s_c, d_r, d_c;
    while(~scanf("%c%d %c%d",s_c, s_d, d_r, d_c)){
        
    }
}