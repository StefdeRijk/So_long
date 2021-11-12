#include "so_long_bonus.h"
static void	*ft_memset(void *str, int val, size_t len);

void	*ft_calloc(size_t count, size_t size, t_assets assets)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		ft_error(assets, "Error\nMalloc failed");
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

static void	*ft_memset(void *str, int val, size_t len)
{
	int		i;
	char	*str1;

	i = 0;
	str1 = (void *)str;
	while (len > 0)
	{
		len--;
		str1[i] = val;
		i++;
	}
	return ((void *)str1);
}
