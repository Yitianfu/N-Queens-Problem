//
//  N_queens.cpp
//  PS1NQUEEN
//  Referenced by Ramavarapu Sreenivas
//  Created by Yitian Fu on 9/4/17.
//  Copyright © 2017 Yitian Fu. All rights reserved.
//  IE523_PS1_YITIAN FU_NetId:yitianf2

#include<iostream>

#ifndef N_queens
#define N_queens
using namespace std;

class Board
{
    int a=0;
    // private data member: size of the board
    int size;
    
    // pointer-to-pointer initialization of the board
    char **chess_board;
    
    // private member function:  returns 'false' if
    // the (row, col) position is not safe.
    bool is_this_position_safe(int row, int col)
    {
        // write the appropriate code on your own that returns
        // "true" if the (row,col) position is safe.  If it is
        // unsafe (i.e. some other queen can threaten this position)
        // return "false"
        int i,j;
        for(i=0;i<col;i++)
            if(chess_board[row][i]=='Q')
                return false;
        for(i=row,j=col;i>=0&&j>=0;i--,j--)
            if(chess_board[i][j]=='Q')
                return false;
        for(i=row,j=col;i<size&&j>=0;i++,j--)
            if(chess_board[i][j]=='Q')
                return false;
        return true;
        
    }
    
    // private member function: initializes the (n x n) chessboard
    void initialize(int n)
    {
        size = n;
        int i,j;
        // write the appropriate code that uses the pointer-to-pointer
        // method to initialize the (n x n) chessboard.  Once initialized,
        // put zeros in all entries.  Later on, if you placed a queen in
        // the (i,j)-th position, then chessboard[i][j] will be 1.
        chess_board=new char*[n];
        for(i=0;i<n;i++)
            chess_board[i]=new char[n];
        
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                chess_board[i][j]='-';
    }
    
    // private member function: prints the board position
    void print_board()
    {
        
        std::cout << size << "-Queens Problem Solution" <<std::endl;
        // write the appropriate code here to print out the solved
        // board as shown in the assignment description
        for(int i=0;i<size;i++)
         {for(int j=0;j<size;j++)
            cout<<chess_board[i][j];
            cout<<endl;
         }
        
    }
    
    // private member function: recursive backtracking
    bool solve(int col)
    {
        // implement the recursive backtracking procedure described in
        // pseudocode format in figure 1 of the description of the first
        // programming assignment
        
        if(col>=size)
        {
            print_board();
            a++;
            cout<<"solution "<<a<<endl;
        }
        
        else
        {
            for(int row=0;row<size;row++)
            {
                if(is_this_position_safe(row, col))
                {
                chess_board[row][col]='Q';
                if(solve(col+1))
                return true;
                else chess_board[row][col]='-';

                }
                                //do nothing and jump to the new row
            }
        
        //no queen can be placed on this column then return false because there is no solution to place n queens on n*n chessborad
        }
        return false;

       }
    
public:
    // Solves the n-Queens problem by (recursive) backtracking
    void nQueens(int n)
    {
        initialize(n);
        solve(0);
        cout<<"There are "<<a<<"solutions "<<" for"<<size<<"*"<<size<<endl;
           }
};
#endif

