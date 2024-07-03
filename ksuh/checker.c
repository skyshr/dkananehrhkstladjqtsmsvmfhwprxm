#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);

pid_t	child_pid;

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
			if (buffer[i] == '\0')
				return (0);
			arr[j][k] = buffer[i++] - '0';
			if (arr[j][k] < 0 || arr[j][k] > 9)
				return (0);
			i++;
		}
		if (j < size - 1 && buffer[i] == '\0')
			return (0);
		if (buffer[i] == '\n')
			i++;
	}
	if (buffer[i] != '\0')
		return (0);
	return (check(arr, data, size));
}

long 	get_time(void)
{
	struct timeval	time;
	long			new_time;

	gettimeofday(&time, NULL);
	new_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (new_time);
}

int	main()
{
    int 	status;
	char	*line;
	char	buffer[1000];
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
			printf("----------------------Error----------------------\n");
		else
			printf("----------------------%d * %d----------------------\n", j, j);
		while (i++ < 10)
		{
			int	fds[2];
			line = get_next_line(fd);
			if (!line)
			{
				printf("get_next_line error\n");
				exit(1);
			}
			if (pipe(fds) == -1)
			{
				printf("pipe error\n");
				exit(1);
			}
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork");
				exit(1);
			}
			if (child_pid == 0)
			{
				dup2(fds[1], STDOUT_FILENO);
				if (execl("./rush-01", "./rush-01", line, NULL) == -1)
				{
					free(line);
					exit(1);
				}
			}
			else
			{
				int status;
				int	t = 0;
				time_t start_time = get_time();
				while (1) {
					pid_t result = waitpid(child_pid, &status, WNOHANG);
					if (result == 0) {
						// 자식 프로세스가 아직 종료되지 않음
						if (get_time() - start_time >= 500) {
							// 타임아웃 발생
							kill(child_pid, SIGKILL);
							t = 1;
							write(1, "[TO] ", 5);
							break;
						}
						// 100ms 대기 후 다시 확인
						usleep(100000);
					} else if (result > 0) {
						// 자식 프로세스가 종료됨
						if (WIFEXITED(status)) 
						{
						} 
						else if (WIFSIGNALED(status)) 
						{
						}
						break;
					} else {
						perror("waitpid failed");
						break;
					}
				}
				if (t == 0)
				{
					len = read(fds[0], buffer, 2048);
					if (!len)
					{
						printf("read error\n");
						exit(1);
					}
					buffer[len] = '\0'; 
					if (j > 3)
					{
						if (checker(buffer, line, j))
							write(1, "[OK] ", 5);
						else
							write(1, "[KO] ", 5);
					}
					else
					{
						int sign;
						sign = 0;
						for (int i = 0; i < len; i++)
						{
							if ((buffer[i] >= 'a' && buffer[i] <= 'z') \
								|| (buffer[i] >= 'A' && buffer[i] <= 'Z'))
							{
								sign = 1;
								write(1, "[OK] ", 5);
								break ;
							}
						}
						if (!sign)
							write(1, "[KO] ", 5);
					}
				}
				free(line);
			}
		}
		line = get_next_line(fd);
		free(line);
		printf("\n-------------------------------------------------\n");
	}
	return (0);
}
