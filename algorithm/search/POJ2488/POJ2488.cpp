#include <iostream>
#include <cstring>
#include <cstdlib>

const int MAX_SIZE = 30;
const char alp[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int visit[MAX_SIZE][MAX_SIZE];
int row, col, count, mode = 0;
typedef struct path_{
    char x;
    int y;
}path_;
path_ path[MAX_SIZE*MAX_SIZE];

int check(){
    int sum = 0;
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j < col; ++j)
            sum += visit[i][j];
    }
    // std::cout << sum << std::endl;
    if(sum == row * col) return true;
    else return false;
}


int travel(int i, int j){
    // if(i <= 0 | j <= 0 | i > row | j > col) return false;
    // if(visit[i][j] != 1) visit[i][j] = 1;
    // else return false;
    if(check()) {
        std::cout << i + 'A' << j;
        mode = 1;
        return true;
    }
    
    if(i > 0 && j > 0 && i <= row && j <=col && visit[i][j] != 1){
        visit[i][j] = 1;
        count++;
        path[count].x = alp[i-1];
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
    }
}

int init(){
    for(int i = 0; i <= row; ++i){
        for(int j = 0; j <= col; ++j){
            visit[i][j] = 0;
        }
    }
    memset(path, 0, sizeof(path_)*MAX_SIZE*MAX_SIZE);
    count = 0;
    return 0;
}

int main(){
    int testCase;
    std::cin >> testCase;
    for(int c = 1; c <= testCase; ++c){
        std::cin >> row >> col;
        init();
        // printf("Scenario: #%d:\n", c);
        std::cout << "Scenario: #:" << c <<std::endl;
        for(int i = 1; i <= row; ++i){
            for(int j = 1; j <=col; ++j){
                travel(i, j);
            }
        }
        if(mode == 0) std::cout << "impossible";
        std::cout << std::endl << std::endl;
    }
}