#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>

#define ONE "1."
#define TWO "2."
#define THREE "3."
#define FOUR "4."
#define FIVE "5."
#define SIX "6."
#define SEVEN "7."
#define EIGHT "8."
#define NINE "9."
#define TEN "10."

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

void	print_num(int cnt)
{
	int	remainder;

	remainder = cnt % 10;
	write(1, "\033[0m", 4);
	if (remainder == 1)
		write(1, ONE, 2);
	else if (remainder == 2)
		write(1, TWO, 2);
	else if (remainder == 3)
		write(1, THREE, 2);
	else if (remainder == 4)
		write(1, FOUR, 2);
	else if (remainder == 5)
		write(1, FIVE, 2);
	else if (remainder == 6)
		write(1, SIX, 2);
	else if (remainder == 7)
		write(1, SEVEN, 2);
	else if (remainder == 8)
		write(1, EIGHT, 2);
	else if (remainder == 9)
		write(1, NINE, 2);
	else
		write(1, TEN, 3);
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
	char	*line;
	char	buffer[1000];
	int		len;
	int		fd;
	int		cnt;
	FILE	*pf;

	pf = popen("clear", "w");
	if (pf == NULL)
	{
		perror("popen");
		exit(1);
	}
	pclose(pf);
	printf("────────────────────────────────────────────────────────────────────────────────\n");
    printf("|                                                                              |\n");
    printf("|  / \\__                                                                __/ \\  |\n");
    printf("| (    @\\___           -       -           -       -      -         ___/@    ) |\n");
    printf("| /         O       oooooooooooooooooooooooooooooooooooooooo       O         \\ |\n");
    printf("|/   (_____ /       o  ######   ##   ##   ######  ##   ##  o       \\ _____)   \\|\n");
    printf("|_/_____/ U         o  #######  ##   ##  #######  ##   ##  o         U \\_____\\_|\n");
    printf("|           |       o  ##   ##  ##   ##  ##       ##   ##  o   |               |\n");
    printf("|                   o  ######   ##   ##   #####   #### ##  o                   |\n");
    printf("|                   o  ##   ##  ##   ##       ##  ##   ##  o                   |\n");
    printf("|  / \\__            o  ##   ##  #######  #######  ##   ##  o            __/ \\  |\n");
    printf("| (    @\\___     -  o  ##   ##   #####   ######   ##   ##  o   -    ___/@    ) |\n");
    printf("| /         O       oooooooooooooooooooooooooooooooooooooooo       O         \\ |\n");
    printf("|/   (_____ /    -       -                 -       -      -        \\ _____)   \\|\n");
    printf("|_/_____/ U                                                          U \\_____\\_|\n");
    printf("|                                                                              |\n");
    printf("───────────────────────────────────────────────────────────────────────────────\n");
	fd = open("testfile", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	int	j;
	int	i;
	cnt = 1;
	j = 3;
	while (j++ < 9)
	{
		i = 0;
		int	correct = 0;
		if (j == 3)
			printf(" --Error--\n");
		else
			printf(" --%d * %d--\n", j, j);
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
						if (get_time() - start_time >= 500) {
							kill(child_pid, SIGKILL);
							t = 1;
							print_num(cnt);
							write(1, "\033[1;33m", 7);
							write(1, "[TO] ", 5);
							break;
						}
						usleep(300000);
					} else if (result > 0) {
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
						{
							print_num(cnt);
							write(1, "\033[1;32m", 7);
							write(1, "[OK] ", 5);
							correct++;
						}
						else
						{
							print_num(cnt);
							write(1, "\033[1;31m", 7);
							write(1, "[KO] ", 5);
						}
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
								print_num(cnt);
								write(1, "\033[1;32m", 7);
								write(1, "[OK] ", 5);
								correct++;
								break ;
							}
						}
						if (!sign)
						{
							print_num(cnt);
							write(1, "\033[1;31m", 7);
							write(1, "[KO] ", 5);
						}
					}
				}
				free(line);
				cnt++;
			}
		}
		line = get_next_line(fd);
		free(line);
		write(1, "\033[0m", 4);
		printf("\n%68d/10\n", correct);
	}
	return (0);
}
