/**
 * @file Task7.cpp
 * @author Kjetil K. Indrehus
 * @brief Find groups on a NxN board 
 * @version 0.1
 * @date 2022-09-10
 * 
 */

#include <iostream>

using namespace std; 

const int N = 8; //Size of the board.

int board[N][N] = {
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,1,1,0,0},
    {0,0,0,0,0,0,0,0},
};


///SOLVE HERE

void display(){
    for(int i = 0; i<N;i++){
        for(int j = 0; j<N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    } 
}


int main(){
    display();
    return 0; 
}