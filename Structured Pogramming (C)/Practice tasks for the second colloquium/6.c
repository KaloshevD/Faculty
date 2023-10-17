/*Да се напише програма која вчитува матрица со димензии MxN (макс. 100x100). На почетокот се внесуваат димензиите на матрицата, а потоа и елементите на матрицата кои се само вредностите 1 и 0. Програмата треба да изброи и отпечати на СИ во колку од редиците и колоните има барем 3 последователни елементи со вредност 1.

Пример:

1 1 1 0
1 0 1 1
1 0 0 1
 
1 ред + 1 колона = 2
*
#include <stdio.h>
int main()
{
    int n,m,Red=0,Kolona=0;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    //lista red
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n-2; j++)
        {
            if(matrix[i][j] == 1 && matrix[i][j+1] == 1 && matrix[i][j+2] == 1)
            {
                Red++;
                break;
            }
        }
    }
    
    //lista koloni
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<m; i++)
        {
            if(matrix[i][j] == 1 && matrix[i+1][j] == 1 && matrix[i+2][j] == 1)
            {
                Kolona++;
                break;
            }
        }
    }
    
    printf("%d", Kolona+Red);
    
    return 0;
}