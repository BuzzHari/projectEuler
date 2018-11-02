#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int grid[20][20];
    for(int grid_i = 0; grid_i < 20; grid_i++){
       for(int grid_j = 0; grid_j < 20; grid_j++){
          scanf("%d",&grid[grid_i][grid_j]);
       }
    }
    unsigned long long int row_pdt,col_pdt,dia,max_pdt=0;
    for(int i = 0; i < 20; i++){
        row_pdt = 1;
        for(int j = i; j < i+4 && j < 20; j++)
            row_pdt = row_pdt * grid[i][j];
        if(row_pdt > max_pdt)
            max_pdt = row_pdt;
    }
    
    for(int i = 0; i < 20; i++){
        col_pdt= 1;
        for(int j = i; j < i+4 && j < 20; j++)
            col_pdt = col_pdt * grid[j][i];
        if(col_pdt > max_pdt)
            max_pdt = col_pdt;
    }

    int j;
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 17; j++)
            dia = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
        
        if(dia> max_pdt)
            max_pdt = dia;
    }

    for(int i = 0; i < 17; i++){
        for(int j = 3; j < 20; j++)
            dia = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
        
        if(dia> max_pdt)
            max_pdt = dia;
    }
    printf("%d", max_pdt);
    return 0;
}

