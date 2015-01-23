// ********************************
// By С���㣬http://www.fishc.com
// ********************************
#include <stdio.h>

int bin_search( int str[], int n, int key )
{
        int low, high, mid;

        low = 0;
        high = n-1;

        while( low <= high )
        {
                mid = (low+high)/2;
                if( str[mid] == key )
                {
                        return mid;                // ���ҳɹ�
                }
                if( str[mid] < key )
                {
                        low = mid + 1;        // �ں�������в���
                }
                if( str[mid] > key )
                {
                        high = mid - 1;        // ��ǰ�������в���
                }
        }

        return -1;                                // ����ʧ��
}

int main()
{
        int str[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
        int n, addr;

        printf("����������ҵĹؼ���: ");
        scanf("%d", &n);

        addr = bin_search(str, 11, n);
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
