#include "../include/ft_printf.h"

int	ft_findaproxb(int *arr, int size, int key)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (arr[size - i - 1] < key)
			return (i);
	}
	return (-1);
}
