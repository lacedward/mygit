#include <stdio.h>
 
void Hanoi(int n, char X, char Y, char Z)
{
	if(1 == n)
	{
		printf("%c--->%c\n", X, Z);
		return;
	}
	else
	{
		Hanoi(n-1, X, Z, Y);

		printf("%c--->%c\n", X, Z);

		Hanoi(n-1, Y, X, Z);
	}
}

int main()
 {
	int n;
	char x, y, z;

	printf("�����뺺ŵ������\n");
	scanf("%d", &n);
	printf("�ƶ���������\n");

	Hanoi(n, 'x', 'y', 'z');
	system("pause");
	 
	 return 0;
 }