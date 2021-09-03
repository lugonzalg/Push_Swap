
	/*GARBAGE
	while (data->head_a || data->head_b)
	{
		if (data->head_b && data->head_b->next)
		{
			if (data->tail_b->content > data->head_b->content
					&& data->tail_b->content >= data->head_b->next->content)
				reverse_rotate_b(&data);
			else if (data->head_b->content < data->head_b->next->content
					&& data->head_b->content > data->tail_b->content)
			{
				if (data->head_b->content - data->head_b->next->content
					< data->head_b->content - data->tail_b->content)
					rotate_b(&data);
				else
					swap_b(&data);
			}
			else if (data->head_b->content < data->head_b->next->content
					&& data->head_b->content < data->tail_b->content)
				rotate_b(&data);

		}
		if (data->head_a != NULL && data->head_a->next == NULL)
		{
			push_to_b(&data);
			continue ;
		}
		else if (data->head_a == NULL)
			break ;
		if (data->head_a->content < data->head_a->next->content
				&& data->head_a->content > data->tail_a->content)
			swap_a(&data);
		else if (data->head_a->content > data->tail_a->content 
			&& data->head_a->content > data->head_a->next->content)
			push_to_b(&data);
		else if (data->tail_a->content > data->head_a->content
				&& data->tail_a->content > data->head_a->next->content)
			reverse_rotate_a(&data);
		else if (data->head_a->content < data->head_a->next->content
				&& data->head_a->content < data->tail_a->content)
			rotate_a(&data);
	}
	printf_list(*data, "I'M IN DA LOOOOOOOOOOOP, YAY", &data->processes);
	data->tail_a = NULL;
	while (data->head_b)
	{
		if (data->head_b->next == NULL)
		{
			push_to_a(&data);
			break ;
		}
		if (data->head_a && data->head_a->next)
		{
			if (data->head_a->content > data->head_a->next->content
					&& data->head_a->content < data->tail_a->content)
				swap_a(&data);
		}
		if (data->head_b->content > data->head_b->next->content
				&& data->head_b->content > data->tail_b->content)
			push_to_a(&data);
		else if (data->head_b->content < data->head_b->next->content
				&& data->head_b->content > data->tail_b->content)
			swap_b(&data);

	}*/
/*
int	check_digit_a(t_data data, int i)
{
	int j;
	char * str;
	int	pos;

	j = 0;
	while (data.head_a)
	{
		pos = ft_strlen(data.head_a->content) - data.digit;
		str = data.head_a->content;
		if (pos == 0)
			return (0);
		if (str[pos] == i + 48)
		{
		ft_printf("\nDISCOVERED: %d", i);
			return (0);
		}
		data.head_a = data.head_a->next;
	}
	ft_printf("\nCHECKED: %d", i);
	return (1);
}

void	sort_list_a(t_data *data)
{
	int	pos;
	int	i;
	char	*ref;
	char	*check;

	ref = (char *)data->head_a->content;
	i = 0;
	ft_printf("DIGIT: %d", data->digit);
	while (i < 9 && data->head_a)
	{
		pos = ft_strlen(data->head_a->content) - data->digit;
		if (pos < 0)
			pos += data->digit;
		check = (char *)data->head_a->content;
		ft_printf("\nPOS: %d -- %c -- I: %d -- REF: %s\n", pos, check[pos], i, ref);
		if (check_digit_a(*data, i))
		{
			ft_printf("AUXILIAR\n");
			if (data->head_a->next)
				ref = (char *)data->head_a->next->content;
			i++;
		}
		if (check[pos] == (i + 48)) || !check[pos])
		{
			if (data->head_a->next && ref == data->head_a->content)
				ref = (char *)data->head_a->next->content;
			push_to_b(&data);
			continue ;
		}
		else if (data->head_a->next)
			rotate_a(&data);
	}
	data->digit++;
}

void	sort_list_b(t_data *data)
{
	while (data->head_b)
		push_to_a(&data);
}*/
/*
	int	moved;

	data->pivot = data->tail_a;	
	while (data->head_a != data->pivot)
	{
		moved = 0;
		if (data->head_a->content < data->pivot->content)
		{
			push_to_b(&data);
			moved = 1;
		}
		else
		{
			if (data->head_a->content > data->tail_a->content
				&& data->head_a->content < data->head_a->next->content)
				&& data->head_a->next->content > data->pivot->content)
			if (data->head_a->content > data->pivot->content)
				{
					rotate_a(&data);
					moved = 1;
				}
			else if (data->head_a->content > data->head_a->next->content
					&& data->head_a->next->content < data->pivot->content)
				{
					rotate_a(&data);
					moved = 1;
				}*/
			/*else if (data->head_a->content > data->tail_a->content
				   && data->head_a->content > data->head_a->next->content)
				   && data->head_a->next->content > data->pivot->content)
				{
					swap_a(&data);
					moved = 1;
				}*/
			/*else if (data->head_a->content < data->tail_a->content
					&& data->head_a->content < data->head_a->next->content)
			{
				reverse_rotate_a(&data);
				swap_a(&data);
				moved = 1;
			}*/
			/*else if (data->head_a->next->content == data->pivot->content)
			{
				moved = 1;
				rotate_a(&data);
			}*/
			/*else if (data->head_a->content < data->tail_a->content)
			{
				reverse_rotate_a(&data);
				swap_a(&data);
				moved = 1;
			}
		}
		if (!moved)
			exit (0);
		*/
