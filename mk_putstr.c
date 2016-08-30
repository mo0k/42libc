void		mk_putchar(char c);

void		mk_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		mk_putchar(str[i]);
		i++;
	}
}