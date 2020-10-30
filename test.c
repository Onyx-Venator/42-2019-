#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = -1;
	while (str[++i])
		;
	return (i);
}

int main()
{
	int i;
	i = ft_strlen("");
	printf("%d\n", i);
	return;
}
