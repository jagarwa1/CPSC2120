/*
 * Name:            Jai Agarwal
 * Date Submitted:  4/10/23
 * Lab Section:     002
 * Assignment Name: nQueens problem using recursion
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int solutions;

// bool isOdd(int n){
//     if (n % 2 == 0) return true;
//     return false;
// }

// checks validity of queen placement
bool isValid(int row, int col, int n, int i){
    int left, right, offset;
    for(int j = row - 1; j >= 0; j--){
        if(board[j][i] == 1) return false;
        
        offset = (row - j); // for diagonal check
        
        right = i + offset;
        if(right < n) if(board[j][right] == 1) return false;
        
        left = i - offset; 
        if(left >= 0) if(board[j][left] == 1) return false;
    }
    return true;
}

// main recursive function 
void checkRows(int row, int n){

    int totalCol = n;

    if(row == n){
        if(n % 2 == 1 && board[0][n/2] == 1)  // if odd
            solutions++;
        else solutions += 2;    
        return;
    }

    if(row == 0)
        totalCol = (n + 1)/2;
    else totalCol = n;

    for(int i = 0; i < totalCol; i++){
        if(isValid(row, totalCol, n, i)){
            board[row][i] = 1;
            checkRows(row + 1, n);
            board[row][i] = 0;
        }
    }
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    solutions = 0;
    for (int i = 0; i < n; i++)
        board.push_back(vector<int> (n, 0));

    // call the recursive function
    checkRows(0, n);

    return solutions;
}

// int main()
// {

//     cout << "1: " << nQueens(1) << endl;
//     cout << "2: " << nQueens(2) << endl;
//     cout << "3: " << nQueens(3) << endl;
//     cout << "4: " << nQueens(4) << endl;
//     cout << "5: " << nQueens(5) << endl;
//     cout << "6: " << nQueens(6) << endl;
//     cout << "7: " << nQueens(7) << endl;
//     cout << "8: " << nQueens(8) << endl;
//     cout << "9: " << nQueens(9) << endl;
//     cout << "10: " << nQueens(10) << endl;
//     cout << "11: " << nQueens(11) << endl;
//     cout << "12: " << nQueens(12) << endl;

//     return 0;
// }