// N Queens Problem via (Backtracking, which is implemented by) Recursion
// Referenced by Ramavarapu Sreenivas 
////IE523_PS1_YITIAN FU_NetId:yitianf2

#include <iostream>
#include "N_queens.h"
#include<stdio.h>


/*int main ()
{
    Board x;
    
    int board_size;
    cin>>board_size;
    x.nQueens(board_size);
    return 0;
}*/

int main (int argc, char * const argv[])
{
    Board x;
    
    int board_size;
    sscanf (argv[1], "%d", &board_size);
    
    x.nQueens(board_size);
    
    return 0;
}
