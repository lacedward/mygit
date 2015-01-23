#include <stdio.h>


void InsertSort(int k[], int n)
{
	int i, j, key;
	for(i=1; i<n; i++)
	{
		key = k[i];

		for(j=i-1; j>=0; j--)
		{
			if(k[j] > key)
			{
				k[j+1] = k[j];
			}
			else
				break;
		}
		k[j+1] = key;
	}
}
int main()
{
	int a[10] = {5,2,6,0,3,9,1,7,4,8};
	int i;

	InsertSort(a, 10);

	for(i=0; i<10; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
}