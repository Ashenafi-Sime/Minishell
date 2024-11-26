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
	else 
		printf(" no %s \n ", data->rl_str);
}


void	test_outfile(t_data *data)
{
	write(1, "test\n", 5);
	int k = 0;
	while (k < data->outfile_nb)
	{
		printf("outflag : %d \n appendflag : %d\n" , data->outflag, data->appendflag);
		if (data->outflag)
		{
			data->out_fd = open(data->outfile[k], O_CREAT | O_RDWR | O_TRUNC, 00700);
			if (data->out_fd > 0)
			{
				write (data->out_fd, "successfully written to the file\n", 34);
				close (data->out_fd);
			}
			else
				printf("no such  file exit and not able to create %s \n", data->outfile[k]);
		}
		else if (data->appendflag)
		{
			data->out_fd = open(data->outfile[k], O_APPEND | O_RDWR, 00700);
			if (data->out_fd > 0)
			{
				write (data->out_fd, "successfully append to the file\n", 33);
				close (data->out_fd);
			}
			else
				printf("no such  file exit  \n");
		}
		else
			//printf(" append no => %s \n ", data->rl_str);
		printf(" => %s \n ", data->rl_str);

		k++;
	}
	
}