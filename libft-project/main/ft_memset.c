#include <stdio.h>
#include <stddef.h>
#include <string.h>
int main()
{

	char str[6] = "hello";
	char str2[6] = "hello";

	printf("%s\n", str);

	memset(str, 'a', 4);
	ft_memset(str2, 'a', 4);

	printf("%s\t", str);
	printf("%s\t", str2);

}