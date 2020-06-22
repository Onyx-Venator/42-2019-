#include "printf.h"

int main()
{
	int 	ret;
	static char *s_hidden = "hi low\0don't print me lol\0";
	printf("le mien :\n");
	ret = ft_printf("%3.s", s_hidden);
	printf("\nret : %d\n", ret);
	printf("l original :\n");
	ret = printf("%3.s", s_hidden);
	printf("\nret : %d\n", ret);

}
/*stock->count_format -= 6;
ft_apply_width(stock);
dump_buffer(stock);
write(1, "(null)", 6);
stock->count_print += 6;*/
