void	mk_putchar(char c);

void	mk_putnbr(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		mk_putchar('-');
	}
	if (nb > 9)
	{
		mk_putnbr(nb / 10);
		mk_putnbr(nb % 10);
	}
	else
		mk_putchar(nb + 48);
}