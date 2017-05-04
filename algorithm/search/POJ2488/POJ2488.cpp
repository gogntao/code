#include <iostream>
#include <cstring>
#include <cstdlib>

const int SIZE = 30;
const char alp[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int visit[SIZE][SIZE];
int row, col, count;
typedef struct path_{
    char x;
    int y;
}path;
int path[SIZE*SIZE];

int travel(int i, int j){
    if(i <= 0 | j <= 0 | i > row | j > col) return false;
    if(check()) return true;
    if(visit[i][j] == 1) return false;
    else{
        visit[i][j] == 1;
        count++;
        path[count].x = alp[row-1];
        path[count].y = col;
        travel(i+2, j+1);
        travel(i+1, j+2);
        travel(i-2, j+1);
        travel(i-1, j+2);
        travel(i+2, j-1);
        travel(i+1, j-2);
        travel(i-2, j-1);
        travel(i-1, j-2);
        visit[i][j] = 0;
        path[count].x = 0;
        path[count].y = 0;
        count--;
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
    memset(path, 0, sizeof(path)*SIZE*SIZE);
    count = 0;
}

int main(){
    int testCase;
    std::cin >> testCase;
    for(int c = 1; c <= testCase; ++c){
        std::cin >> row >> col;
        init();
        printf("Scenario: #%d:\n", c);
        for(int i = 1; i <= row; ++i){
            for(int j = 1; j <=row; ++j){
                if(travel(i, j)){
                    for(int k = 0; k < count; ++k){
                        printf("%c%d", path[k].x, path[k].y);
                    }
                }
            }
        }
        if(!check()) printf("impossible");
        printf("\n\n");
    }
}