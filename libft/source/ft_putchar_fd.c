/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilmaz <emreyilmaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:32:51 by emreyilmaz        #+#    #+#             */
/*   Updated: 2022/04/07 03:12:59 by emreyilmaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char a, int fd)
{
	write(fd, &a, 1);
}

/*
int main()
{
    int fd;

    fd = open("deneme", O_RDWR);
    ft_putchar_fd('m', fd);    
}
*/