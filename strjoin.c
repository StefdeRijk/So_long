#include "so_long.h"
static void	*ft_memmove(void *dst, void *src, size_t len);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	str = malloc(l1 + l2 + 1);
	if (!str)
		return (0);
	ft_memmove(str, (char *)s1, l1);
	ft_memmove(str + l1, (char *)s2, l2);
	str[l1 + l2] = '\0';
	free((char *)s1);
	return (str);
}

static void	*ft_memmove(void *dst, void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	i = 0;
	dst1 = (void *)dst;
	src1 = (void *)src;
	if (!dst1 && !src1)
		return (0);
	if (dst1 > src1)
	{
		while (len > 0)
		{
			len--;
			dst1[len] = src1[len];
		}
	}
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return ((void *)dst1);
}
