#include "rt.h"
#include "pthread.h"

void	pthread(t_data *data)
{
	t_data	*tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
    while (i < THREAD_NUMBER)
	{
		 tab[i] = (t_data *)malloc(sizeof(t_data));
		 ft_memcpy((void*)tab[i], (void*)data, sizeof(t_data));
		 i++;
	}
	i = 0;

	while (i < THREAD_NUMBER)
	{
        //ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_data));
		tab[i]->start_line = THREAD_WIDTH * i;
		tab[i]->finish_line = THREAD_WIDTH * (i + 1);
		if (pthread_create(&t[i], NULL,
			(void *(*)(void *))draw, (void *)tab[i]))
			exit(1);
		i++;
		
	}
	while (i--)
	{	
		pthread_join(t[i], NULL);
		free(tab[i]);
	}
	//mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}