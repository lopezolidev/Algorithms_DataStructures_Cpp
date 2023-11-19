/*
Escape from a labyrinth using backtracking progamming
*/

#include <iostream>

using namespace std;

bool validCell(char C){
    if(C == '.' || C == 'PS') return true;
    if(C == '*' || C == 'X') return false;
}

void movePlayer(char p, char m){
    p = m;
}

bool escape(char **A, int posX, int posY, int N){
    if(A[posX][posY] == 'PS'){
        return true;
    }
    
    int i = 0;
    while(i < N){
        char m = '.';
        if(validCell(A[posX+1][posY])){
            m = 'R';
            movePlayer(A[posX+1][posY], m);
            escape(A, posX, posY, N);
        }

        i++;
    }
    return false;
}

int main(){



    return 0;
}