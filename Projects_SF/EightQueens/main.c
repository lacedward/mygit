#include <stdio.h>
#include <stdlib.h>

int count = 1;

int Danger(int m, int n, int(*chess)[8])
{

    int i, j, k, g, flag1=0, flag2=0, flag3=0;

    k = m+n;
    g = m-n;

    for(i=0; i<8; i++)
    {
        if(*(*(chess+i)+n) != 0)
        {
            flag1 = 1;
            break;
        }
    }
    if(flag1 == 1)
    {
        return 1;
    }


//判断对角线
    for(i=0; i<8; i++)  //i<m or i<8 ???
    {
        for(j=0; j<n; j++)
        {

            if((i+j) == k || (i-j) == g )
            {

                if(*(*(chess+i)+j) == 1)
                {
                    flag2 = 1;
                    break;
                }

            }

        }

        if(flag2)
        {
            break;
        }
    }
    if(flag1 || flag2)
    {
        return 1;
    }



    for(i=0; i<8; i++)   //i<m or i<8 ???
    {
        for(j=n+1; j<8; j++)
        {

            if((i+j) == k || (i-j) == g )
            {

                if(*(*(chess+i)+j) == 1)
                {
                    flag3 = 1;
                    break;
                }

            }

        }

        if(flag3)
        {
            break;
        }
    }

    if(flag1 || flag2 || flag3)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void EightQueens(int m,  int n, int (*chess)[8] )
{
    int chessplan[8][8];
    int i, j;

    for( i=0; i<8; i++)
    {
        for( j=0; j<8; j++)
        {

            chessplan[i][j] = chess[i][j];

        }
    }

    if(8 == m)
    {
//        printf("第 %d 种解决方法"， count);


        for(i=0; i<8; i++)
        {

            for(j=0; j<8; j++)
            {
                printf("%d ",*(*(chessplan+i)+j));

            }
            printf("\n");
        }

        printf("\n\n");

        count++;

    }

    else
    {
        for(j=0; j<n; j++)
        {
            if(!Danger(m, j, chess))
            {
               for(i=0; i<n; i++)
                {
                    *(*(chessplan+m)+i) = 0;
                }

                *(*(chessplan+m)+j) = 1;
                EightQueens(m+1, n, chessplan);
            }
        }
//这是不是应该加一句，把这一行都重置为0？？？


    }



}



int main()
{
    int chess[8][8];
    int i,j;

    for(i=0; i<8; i++)
    {
        for( j=0; j<8; j++)
        {
            chess[i][j] = 0;
        }
    }

    EightQueens(0, 8, chess);

    printf("总共有 %d 种解决方法", count);


    return 0;
}
