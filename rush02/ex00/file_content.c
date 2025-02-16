
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZE 4096

int	file_size(char *path)
{
	int	fd;
	int	byte;
	int	tmp[BUFSIZE];
	int	result;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	byte = 1;
	result = 0;
	while (byte > 0)
	{
		byte = read(fd, tmp, BUFSIZE);
		result += byte;
	}
	close(fd);
	return (result);
}

char	*file_content(char *path)
{
	int		size;
	char	*content;
	int		fd;
	int		buf_read;

	size = file_size(path);
	fd = open(path, O_RDONLY);
	if (size == -1 || fd == -1)
	{
		write(2, "Error: Can't open file\n", 23);
		return (0x00);
	}
	content = (char *)malloc(sizeof(char) * (size + 1));
	buf_read = read(fd, content, size);
	close(fd);
	if (buf_read != size)
	{
		write(2, "Error while reading file\n", 25);
		return (0x00);
	}
	content[size] = 0;
	return (content);
}
//
//#include <stdio.h>
//int main(void) {
//	char *content = file_content("main.c");
//	printf("--------\n%s$\n--------\n", content);
//	free(content);
//	return 0;
//}
