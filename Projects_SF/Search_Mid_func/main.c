// ********************************
// By С���㣬http://www.fishc.com
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

        printf("����������ҵĹؼ���: ");
        scanf("%d", &n);

        addr = bin_search(str, 0, 10, n);
        if( -1 != addr )
        {
                printf("���ҳɹ�����ϲ�ɺأ��ɿڿ���! �ؼ��� %d ���ڵ�λ����: %d\n", n, addr);
        }
        else
        {
                printf("����ʧ��!\n");
        }

        return 0;
}
