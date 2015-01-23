#include <stdio.h>

void Reverse_Output()
{
	char a;
	scanf("%c", &a);
	
	if('#' == a)
	{
		return;
	}

	Reverse_Output(); //   '#' != a

	printf("%c", a);
}