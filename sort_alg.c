
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
