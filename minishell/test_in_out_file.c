#include "minishell.h"

void	test_infile(t_data *data)
{
	if (data->inflag)
	{
		printf("file name -> %s \n" , data->infile);
		data->in_fd = open(data->infile, O_RDONLY);
		if (data->in_fd > 0)
		{
			printf(" file is successfully opened \n");
			close (data->in_fd);
		}
		else
			printf("no such  file exit  \n");
	}
}


void	test_outfile(t_data *data)
{
	int k = 0;
	while (k < data->outfile_nb)
	{
		if (check_bit (data->out[k].flag, NEW_FILE))
		{
			write(data->out[k].fd, "This is new file", 17);
		}
		else if (check_bit (data->out[k].flag, APPEND))
		{
			write(data->out[k].fd, "This is existing file", 22);
		}
		k++;
	}
}