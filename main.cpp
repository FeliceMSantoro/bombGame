//
//  main.cpp
//  Asgn5BBombBoard
//
//  Created by Felice Santoro on 2/24/16.
//  Copyright © 2016 Felice Santoro. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));
    
    const int numRows = 5, numCols = 5;
    char board[numRows][numCols];
    int numBombs = (rand() % 5) + 3;
    int movesToWin = (rand() % 8) + 5;
    int URow = rand() % numRows;
    int UCol = rand() % numCols;
    int BRow;
    int BCol;
    char move;
    
    //initialize board
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            board[row][col] = '_';
        }
    }
    //bomb placement
    for (int i = 0; i < numBombs; i++) {
        BRow = rand() % numRows ;
        BCol = rand() % numCols;
        if ((board[BRow][BCol] != 'U') && (board[BRow][BCol] != '*')) board[BRow][BCol] = '*';
        else i--;
    }
    
    do {
    
        while (board[URow][UCol] == '*') {
            URow = rand() % numRows;
            UCol = rand() % numCols;
        }
        
        board[URow][UCol] = 'U';
    
        cout << "SURVIVE " << movesToWin << " MORE MOVES!" << endl;
 
        //display board
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                cout << board[row][col] << " | ";
            }
            cout << endl;
        }
    
        cout << "Enter a direction (N/S/E/W): ";
        cin >> move;
        cout << endl;
    
    
        board[URow][UCol] = '*';
        if (move == 'N') URow--;
        else if (move == 'S') URow++;
        else if (move == 'W') UCol--;
        else if (move == 'E') UCol++;
        
        movesToWin--;
        
        if (board[URow][UCol] == '*') movesToWin = -1;
        if (URow < 0 || UCol < 0 || URow >= numRows || UCol >= numCols) movesToWin = -2;
        
    } while (movesToWin > 0);
    
    if (movesToWin == 0) cout << "*** YOU WIN! ***";
    else if (movesToWin == -1) cout << "BANG! You're dead!\n*** YOU LOSE! ***";
    else if (movesToWin == -2) cout << "YOU FELL OFF THE BOARD!\n*** YOU LOSE! ***";
    
    return 0;
}
