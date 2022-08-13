#include "get_next_line.h"

/*
 ** @brief      Extract the first line it finds in temp.
 **
 ** @param[in]  temp can be the next line [ and more ] or NULL.
 ** @return     The next line to be print from temp content.
 */

char	*ft_newline(const char *temp)
{
	size_t	i;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	i += (temp[i] == '\n');
	return (ft_substr (temp, 0, i));
}

/*
 ** @brief      Update temp to pass to the next line it contains or NULL if
 **             there is nothing left to read.
 **
 ** @param[in]  temp can be the next line [ and more ] or NULL.
 ** @return     A new temp starting from the next line to read or NULL.
 */

char	*ft_newtemp(char *temp)
{
	char			*new;
	unsigned int	i;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		return (free (temp), NULL);
	i += (temp[i] == '\n');
	new = ft_substr (temp, i, ft_strlen (temp) - i);
	return (free (temp), new);
}

/*
 ** @brief      Get the next line of text available on a file descriptor.
 **
 ** Calling get_next_line in a loop will allow us to read the text available on
 ** the file descriptor one line at a time until the end of it.
 **
 ** A line is defined as a NUL or LF terminated string.
 **
 ** @var        temp can be:
 **              - the next line, if BUFFER_SIZE is smaller than a line.
 **              - the next line and more, if BUFFER_SIZE is bigger than a line.
 **              - NULL if there are no text left to read on the filedes.
 ** @var        line is the last read line.
 ** @var        buf is for read(2) buffer.
 ** @var        rd is for read(2) return value.
 **
 ** @param[in]  fd the file descriptor.
 ** @return     The line that has just been read or NULL.
 */

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*buf;
	long		rd;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc (sizeof (char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (rd && !ft_has_nl (temp))
	{
		rd = read (fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (free (buf), NULL);
		buf[rd] = '\0';
		temp = ft_strjoin (temp, buf);
	}
	free (buf);
	if (!temp)
		return (NULL);
	line = ft_newline (temp);
	temp = ft_newtemp (temp);
	return (line);
}
