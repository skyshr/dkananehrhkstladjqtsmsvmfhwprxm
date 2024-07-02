/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:14:30 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/02 20:17:52 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_read_bytes(char *backup, int *is_end);
static char		*read_buffer(int fd, char *backup, char *buffer, int *is_end);
static char		*ft_strjoin(char *src1, char *src2, size_t bytesize);
static void		reset(char *backup, size_t readbytes);

char	*get_next_line(int fd)
{
	static char	backup[MAX_SIZE][BUFFER_SIZE];
	char		*buffer;
	int			is_end;
	int			len;

	is_end = 0;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup[fd][0] == '\0' && read(fd, backup[fd], BUFFER_SIZE) <= 0)
		return (NULL);
	buffer = NULL;
	while (!is_end)
		buffer = read_buffer(fd, backup[fd], buffer, &is_end);
	len = ft_strlen(buffer);
	if (buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';
	return (buffer);
}

void	reset(char *backup, size_t readbytes)
{
	size_t	idx;
	size_t	copyidx;

	if (readbytes == 0)
		return ;
	idx = 0;
	copyidx = readbytes;
	while (copyidx < BUFFER_SIZE && backup[copyidx])
		backup[idx++] = backup[copyidx++];
	while (idx < BUFFER_SIZE && backup[idx])
		backup[idx++] = '\0';
}

size_t	get_read_bytes(char *backup, int *is_end)
{
	size_t	readbytes;

	readbytes = 0;
	while (readbytes < BUFFER_SIZE)
	{
		if (backup[readbytes] == '\n')
		{
			(*is_end) = 2;
			return (readbytes + 1);
		}
		else if (backup[readbytes] == '\0')
		{
			(*is_end) = 1;
			return (readbytes);
		}
		readbytes++;
	}
	return (readbytes);
}

char	*read_buffer(int fd, char *backup, char *buffer, int *is_end)
{
	size_t	readbytes;

	readbytes = get_read_bytes(backup, is_end);
	buffer = ft_strjoin(buffer, backup, readbytes);
	if (buffer == NULL)
	{
		(*is_end) = 1;
		return (0);
	}
	reset(backup, readbytes);
	if ((*is_end) == 1)
	{
		read(fd, backup, BUFFER_SIZE);
		if (backup[0] != '\0')
			(*is_end) = 0;
	}
	return (buffer);
}

char	*ft_strjoin(char *src1, char *src2, size_t bytesize)
{
	char	*dest;
	size_t	destidx;
	size_t	srcidx;

	dest = (char *)malloc((ft_strlen(src1) + bytesize + 1) * sizeof(char));
	if (!dest)
		return (0);
	destidx = 0;
	srcidx = 0;
	while (src1 && src1[destidx])
	{
		dest[destidx] = src1[destidx];
		destidx++;
	}
	while (srcidx < bytesize)
		dest[destidx++] = src2[srcidx++];
	dest[destidx] = '\0';
	if (src1)
		free(src1);
	return (dest);
}
