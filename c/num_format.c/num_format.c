/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maikittitee <maikittitee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:15:56 by maikittitee       #+#    #+#             */
/*   Updated: 2023/02/08 15:16:07 by maikittitee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void	ft_putchar_fd(char c, int fb)
{
	write(fb, &c, 1);
}
void	ft_putnbr_fd(int n, int fd)
{
	
	if (n == -2147483648)
	{
		ft_putnbr_fd(-1 * 214748364, fd);
		ft_putchar_fd('8', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-1 * n, fd);
	}
	else if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	put_format(size_t n)
{
	if (n < 1000){
		ft_putnbr_fd(n,1);	
	}
	else
	{
		ft_putnbr_fd(n / 1000,1);
		write(1,",",1);
		put_format(n % 1000);
	}
}

int	main(int ac, char **av)
{
	//size_t n = atoi(av[1]);
	put_format(12345);
	//printf("%#2d",100000000);
}