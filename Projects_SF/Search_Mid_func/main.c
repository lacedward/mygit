// ********************************
// By 小甲鱼，http://www.fishc.com
// ********************************
#include <stdio.h>

int bin_search( int str[], int start, int end, int key )
{
        int  mid;
		mid = (start + end)/2;
		if(key == str[mid])
		{
			return mid;
		}
		if(key < str[mid] && start <= end)
		{
			return bin_search(str, start, mid-1, key);

		}
		if(key > str[mid] && start <= end)
		{
			return bin_search(str, mid+1, end, key);
		}

        return -1;
}

int main()
{
        int str[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
        int n, addr;

        printf("请输入待查找的关键字: ");
        scanf("%d", &n);

        addr = bin_search(str, 0, 10, n);
        if( -1 != addr )
        {
                printf("查找成功，可喜可贺，可口可乐! 关键字 %d 所在的位置是: %d\n", n, addr);
        }
        else
        {
                printf("查找失败!\n");
        }

        return 0;
}
