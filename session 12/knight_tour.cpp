#include <iostream>
using namespace std;

int n = 8;
int board[8][8];

int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

bool isSafe(int x, int y){
    return (x>=0 && y>=0 && x<n && y<n && board[x][y]==-1);
}

void printBoard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << board[i][j] << "\t";
        cout << endl;
    }
}

bool solveKnight(int x, int y, int move){
    if(move == n*n)
        return true;

    for(int i=0;i<8;i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(isSafe(nextX,nextY)){
            board[nextX][nextY] = move;
            if(solveKnight(nextX,nextY,move+1))
                return true;
            board[nextX][nextY] = -1; // backtrack
        }
    }
    return false;
}

int main(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j] = -1;

    board[0][0] = 0;

    if(solveKnight(0,0,1))
        printBoard();
    else
        cout << "No solution";
}
