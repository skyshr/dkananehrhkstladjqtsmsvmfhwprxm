#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);

jmp_buf env;

void	timeout_handler(int sig) {
	// 알람 신호를 받으면 프로그램을 종료합니다.
	longjmp(env, 1);
}

void	print_1d(int data[40], int size)
{
	for (int i = 0; i < 4 * size; i++)
		printf("%d ", data[i]);
	printf("\n");
}

void	print_2d(int arr[10][10], int size)
{
	for (int i = 0; i < size; i++)
		print_1d(arr[i], size / 4);
}


int	check(int arr[10][10], int data[40], int size)
{
	int	see;
	int	idx;
	int	high;
	int	i;
	int	j;

	idx = 0;
	j = -1;
	while (++j < size)
	{
		i = -1;
		high = 0;
		see = 0;
		while (++i < size)
		{
			if (arr[i][j] > high)
			{
				see++;
				high = arr[i][j];
			}
		}
		if (see != data[idx++])
			return (0);
	}
	j = -1;
	while (++j < size)
	{
		i = size;
		high = 0;
		see = 0;
		while (--i >= 0)
		{
			if (arr[i][j] > high)
			{
				see++;
				high = arr[i][j];
			}
		}
		if (see != data[idx++])
			return (0);
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		high = 0;
		see = 0;
		while (++j < size)
		{
			if (arr[i][j] > high)
			{
				see++;
				high = arr[i][j];
			}
		}
		if (see != data[idx++])
			return (0);
	}
	i = -1;
	while (++i < size)
	{
		j = size;
		high = 0;
		see = 0;
		while (--j >= 0)
		{
			if (arr[i][j] > high)
			{
				see++;
				high = arr[i][j];
			}
		}
		if (see != data[idx++])
			return (0);
	}
	return (1);
}

int	checker(char buffer[1000], char *line, int size)
{
	int	data[40];
	int	arr[10][10];
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (line[i])
	{
		data[j++] = line[i++] - '0';
		if (line[i])
			i++;
	}
	i = 0;
	j = -1;
	while (++j < size)
	{
		k = -1;
		while (++k < size)
		{
			arr[j][k] = buffer[i++] - '0';
			i++;
		}
		i++;
	}
	return (check(arr, data, size));
}

char	*ft_strjoin(char *exe_cmd, char *arg)
{
	char	*dest;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(exe_cmd) + ft_strlen(arg) + 2;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		exit(1);
	i = 0;
	while (exe_cmd[i])
		dest[j++] = exe_cmd[i++];
	dest[j++] = 34;
	i = 0;
	while (arg[i])
		dest[j++] = arg[i++];
	dest[j++] = 34;
	dest[j] = 0;
	return (dest);
}

int	main()
{
	char	*bash_cmd;
	char	*line;
	char	buffer[1000];
	FILE	*pipe;
	int		len;
	int		fd;

	fd = open("testfile", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	int	j;
	int	i;
	j = 2;
	while (j++ < 9)
	{
		i = 0;
		if (j == 3)
			printf("-------------------------------------------------\n");
		else
			printf("----------------------%d * %d----------------------\n", j, j);
		while (i++ < 10)
		{
			line = get_next_line(fd);
			if (!line)
			{
				printf("get_next_line error\n");
				exit(1);
			}
			bash_cmd = ft_strjoin("./rush-01 ", line);
			signal(SIGALRM, timeout_handler);
			if (setjmp(env) == 0)
			{
				alarm(1);
				pipe = popen(bash_cmd, "r");
				if (NULL == pipe) 
				{
					perror("pipe");
					pclose(pipe);
					exit(1);
				}
				len = fread(buffer, 1, 2048, pipe);
				if (!len)
				{
					printf("read error\n");
					pclose(pipe);
					exit(1);
				}
				buffer[len-1] = '\0'; 
				if (j > 3)
				{
					if (checker(buffer, line, j))
						printf("[OK] ");
					else
						printf("[KO] ");
				}
				free(bash_cmd);
				free(line);
				pclose(pipe);
				alarm(0);
			}
			else
			{
				printf("[TO] ");
				free(line);
				free(bash_cmd);
				pclose(pipe);
			}
		}
		line = get_next_line(fd);
		free(line);
		printf("\n-------------------------------------------------\n");
	}
	return (0);
}
