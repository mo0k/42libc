/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 06:38:16 by jmoucade          #+#    #+#             */
/*   Updated: 2017/11/20 11:20:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdio.h>

static t_file		*check_fd(int fd, t_file **f)
{
	char			*buff;
	t_file			*new;

	buff = NULL;
	if (fd < 0 || read(fd, buff, 0) == -1)
		return (NULL);
	if (!*f)
	{
		if (!(new = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		new->fd = fd;
		new->data = NULL;
		new->eof = 0;
		new->next = NULL;
		*f = new;
		return (new);
	}
	new = *f;
	if (!new)
		return (NULL);
	if (new->fd == fd)
		return (new);
	return (check_fd(fd, &new->next));
}

static int			eol_found(t_file *f, char **line, char *addr_eol)
{
	dprintf(2, "start function oel_found\n");
	char			*tmp;

	*addr_eol = 0;
	tmp = NULL;
	if (!(tmp = ft_strdup(addr_eol + 1)))
		return (ERROR);
	if (!(*line = ft_strdup(f->data)))
	{
		(tmp) ? ft_memdel((void*)(&tmp)) : 0;
		return (ERROR);
	}
	dprintf(2, "stracat f->data(%p):'%s'\n", *line, *line);
	ft_memdel((void*)(&f->data));
	if (dprintf(2, "test0\n") && tmp && dprintf(2, "test1\n") && ft_strlen(tmp) > 0 && dprintf(2, "test2\n") && !(f->data = ft_strdup(tmp)))
	{
		(*line) ? ft_memdel((void*)(line)) : 0;
		(tmp) ? ft_memdel((void*)(&tmp)) : 0;
		return (ERROR);
	}
	(tmp) ? ft_memdel((void*)(&tmp)) : 0;
	return (EOL);
}

static int			is_endline(t_file *f, char **line, int ret)
{
	char			*r;

	if ((r = ft_strchr(f->data, 0x0a)))
		return (eol_found(f, line, r));
	else if (ret == 0 && (int)ft_strlen(f->data) == 0)
		f->eof = 1;
	else if (ret == 0 && (int)ft_strlen(f->data) > 0)
	{
		if (!(*line = ft_strdup(f->data)))
			return (ERROR);
		(f->eof = 1) ? ft_memdel((void*)(&f->data)) : NULL;
		return (EOL);
	}
	return (0);
}

static int			read_line(t_file *f, char **line, char *buff)
{
	int				ret;
	int				endline;

	if (!f)
		return (ERROR);
	dprintf(2, "avant boucle read\n");
	while ((ret = read(f->fd, buff, BUFF_SIZE)) > 0 || (f->data && f->eof == 0))
	{
		buff[ret] = 0;
		dprintf(2, "ret:%d,buff:'%s' f->data(%p):'%s' eof:%d\n", ret, buff, f->data, f->data, f->eof);
		if (!f->data)
		{
			if (!(f->data = ft_strdup(buff)))
				return (ERROR);
		}
		else if (ret > 0)
		{
			if (!ft_stracat(&f->data, buff))
				return (ERROR);
			dprintf(2, "stracat f->data(%p):'%s'\n", f->data, f->data);
		}
		if ((endline = is_endline(f, line, ret)) == EOL)
			return (EOL);
		else if (endline == ERROR)
			return (ERROR);
	}
	*line = NULL;
	return (END_OF_FILE);
}

int					gnl(const int fd, char **line)
{
	dprintf(2, "start function get_next_line\n");
	static t_file	*f;
	t_file			*tmp;
	int				ret;
	char			*buff;

	if (!(buff = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (ERROR);
	if (!(tmp = check_fd(fd, &f)))
		return (ERROR);
	ret = read_line(tmp, line, buff);
	free(buff);
	if (ret == EOL)
		return (EOL);
	else if (ret == ERROR)
		return (ERROR);
	else
		return (END_OF_FILE);
}
