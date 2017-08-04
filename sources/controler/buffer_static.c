/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 23:59:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/31 23:45:44 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>

void			init_buffer_static(t_buffer_static *controler)
{
	ft_bzero(controler->buffer, BUFF_SIZE_INIT);
	controler->current = controler->buffer;
	controler->buff_size = BUFF_SIZE_INIT;
	controler->remaining_size = BUFF_SIZE_INIT;
}

void			print_buffer_static(t_buffer_static *controler)
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
	ft_putstrcolor("+--------------------------+\n", C_YELLOW);
}

static int		fill_buffer(t_buffer_static *ctrl, char *input, size_t size)
{
	if (!ctrl || !input)
		return (0);
	ft_putstrcolor("fill controler->starter_buffer\n", C_CYAN);
	ft_strcat(ctrl->current, input);
	ctrl->remaining_size -= size;
	print_buffer_static(ctrl);
	return (1);
}

int				fill_buffer_static(t_buffer_static *ctrl, char *input)
{
	ft_putstr("START fill_buffer_static\n");
	size_t		new_size;

	if (!ctrl || !input)
		return (0);
	new_size = ft_strlen(input);
	return (input && available_space(new_size, ctrl->remaining_size)) ?
			fill_buffer(ctrl, input, new_size) : 0;
}