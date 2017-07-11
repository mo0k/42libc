/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_controler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:21:54 by jmoucade          #+#    #+#             */
/*   Updated: 2017/07/11 18:06:54 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>

void		init_buffer_controler(t_buffer_controler *controler)
{
	ft_bzero(controler->starter_buffer, BUFF_SIZE_INIT);
	controler->buffer = controler->starter_buffer;
	controler->buff_size = BUFF_SIZE_INIT;
	controler->remaining_size = BUFF_SIZE_INIT;
	controler->increm = 2;
	controler->malloc = 0;
}

void		print_buffer_controler(t_buffer_controler *controler)
{
	ft_putstrcolor("+--------------------------+\n", C_YELLOW);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buffer:", C_GREEN);
	ft_putendl(controler->buffer);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->len:", C_GREEN);
	ft_putnbr((int)ft_strlen(controler->buffer));
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buff_size:", C_GREEN);
	ft_putnbr((int)controler->buff_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->remaining_size:", C_GREEN);
	ft_putnbr((int)controler->remaining_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->increm:", C_GREEN);
	ft_putnbr((int)controler->increm);
	write(1, "\n", 1);
	ft_putstrcolor("+--------------------------+\n", C_YELLOW);
}

static int		available_space(size_t new_size, size_t remaining_size)
{
	return ((new_size <= remaining_size) ? 1 : 0);
}

int		fill_buffer(t_buffer_controler *controler, char *input)
{
	size_t		new_size = ft_strlen(input);
	char		*new_buffer;

	if (!controler || !input)
		return (0);
	if (input && available_space(new_size, controler->remaining_size))
	{
		ft_putstrcolor("fill controler->starter_buffer\n", C_CYAN);
		ft_strcat(controler->buffer, input);
		controler->remaining_size -= new_size;
		print_buffer_controler(controler);
	}
	else
	{
		ft_putstrcolor("fill controler->buffer\n", C_LBLUE);
		while ((controler->buff_size = controler->increm * BUFF_SIZE_INIT) < new_size + ft_strlen(controler->buffer))
			++controler->increm;
		if (!(new_buffer = ft_strnew(controler->buff_size)))
			return (0);
		ft_strcpy(new_buffer, controler->buffer);
		ft_strcat(new_buffer, input);
		controler->remaining_size = controler->buff_size - ft_strlen(controler->buffer) - new_size;
		if (controler->malloc)
		{
			ft_putstrcolor("free(controler->buffer)\n", C_MAGENTA);
			free(controler->buffer);
		}
		controler->malloc = 1;
		controler->buffer = new_buffer;
		print_buffer_controler(controler);
	}
	return (1);
}
