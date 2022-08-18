/*
 ** ft_has_nl:		1min
 ** ft_strlen:		2min
 ** ft_strdup:		3min
 ** ft_strjoin:		13min (because of strdup)
 ** ft_substr:		7min
 */

int	ft_has_nl(char const *str)
{
	if (str)
		while (*str && *str != '\n')
			str++;
	return (str && *str == '\n');
}

size_t	ft_strlen(char const *str)
{
	char const	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - str));
}

char	*ft_strdup(char const *s1)
{
	char	*s2;
	char	*p2;

	if (!s1)
		return (NULL);
	s2 = malloc (sizeof (*s2) * (ft_strlen (s1) + 1));
	if (!s2)
		return (NULL);
	p2 = s2;
	while (*s1)
		*p2++ = *s1++;
	return (*p2 = 0, s2); // XXX *p2 NOT p2 …
}

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	char	*s3;
	char	*p3;
	char	*p1;

	if (!s1 && s2)
		return (ft_strdup (s2));
	if (s1 && !s2)
		return (ft_strdup (s1));
	if (!s1 && !s2)
		return (ft_strdup (""));
	s3 = malloc (sizeof (*s3) + (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (!s3)
		return (free (s1), NULL);
	p3 = s3;
	p1 = s1;
	while (*p1) // XXX use p1 not s1
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	return (free (s1), *p3 = 0, s3);
}

char	*ft_substr(char const *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	if (!str)
		return (NULL);
	len = ft_strlen (str);
	if (start >= len)
		return (NULL);
	if (len - start < size)
		size = len - start;
	sub = malloc (sizeof (*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}