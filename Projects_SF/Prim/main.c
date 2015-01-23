#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Infinity 50
#define N 11

 int lowcost[N], visited[N];
 int n = N;
 int map[N][N];
 int prim()
 {
     int i, j, pose, min, sum;
     visited[1] = 1;
     pose = 1;

     for(i=1; i<=n; i++)
     {
         if(i!= pose)
         {
             lowcost[i] = map[pose][i];
         }
     }

     for(i=1; i< n; i++)
     {
         min = Infinity;

         for(j=1; j<=n; j++)
         {
             if(visited[j] == 0 && min > lowcost[j])
             {
                 min = lowcost[j];
                 pose = j;

             }
            sum += min;
            printf("%d\n", j);
            visited[pose] = 1;
         }

         for(j=1; j<=n; j++)
         {
             if(visited[j] == 0 && lowcost[j] > map[pose][j])
             {
                 lowcost[j] = map[pose][j];
             }
         }

     }

     return sum;
 }






int main()
{
    int i,j,v,ans;


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&v);
            map[i][j] = map[j][i] = v;
        }

    }
    ans = prim();
    printf("%d\n", ans);


    return 0;
}
