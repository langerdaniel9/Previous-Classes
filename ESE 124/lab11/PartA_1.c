#include <stdio.h>

int main(void)
{
	char * str;
	int i = 0;
	printf("Input about 10 characters of string\n");
	scanf("%s", str);

	printf("\n");
	while (str[i] != '\0')
	{
		printf("%s\n", str + i);
		i++;
	}

	return (0);
}
