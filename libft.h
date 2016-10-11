/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:52:04 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/07 12:23:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
# define	LIBFT_H

#include <unistd.h>
#include <stdlib.h>

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strstr(char *str, char *to_find);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int nb);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(char *src);

#endif
