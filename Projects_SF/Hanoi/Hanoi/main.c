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

	printf("请输入汉诺塔层数\n");
	scanf("%d", &n);
	printf("移动步骤如下\n");

	Hanoi(n, 'x', 'y', 'z');
	system("pause");
	 
	 return 0;
 }