#include <iostream>
#include <string>

const int SIZE = 30;
int visit[SIZE][SIZE];
int row, col;

int travel(int i, int j){
    if(i <= 0 | j <= 0 | i > row | j > col) return false;
    if(check()) return true;
    if(visit[i][j] == 1) return false;
    else{
        visit[i][j] == 1;
        travel(i+2, j+1);
        travel(i+1, j+2);
        travel(i-2, j+1);
        travel(i-1, j+2);
        travel(i+2, j-1);
        travel(i+1, j-2);
        travel(i-2, j-1);
        travel(i-1, j-2);
    }
}

int check(){
    int sum = 0;
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j < col; ++j)
            sum += visit[i][j];
        }
    }
    if(sum == row * col) return true;
    else return false;
}

int init(){
    for(int i = 0; i <= row; ++i){
        for(int j = 0; j <= col; ++j){
            visit[i][j] = 0;
        }
    }
}