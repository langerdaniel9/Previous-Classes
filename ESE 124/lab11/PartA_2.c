#include <stdio.h>
#include <string.h>

int main(void)
{
	char * str;
	int i;
	printf("Input about 10 characters of string\n");
	scanf("%s", str);

	printf("\n");
	for (i=strlen(str); i>=0; i--)
	{
		printf("%.1s\n", str + i);

	}

	return (0);
}
