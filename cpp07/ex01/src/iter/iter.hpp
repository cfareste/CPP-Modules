#include <cstddef>

template<typename T, typename F>
void	iter(T *array, std::size_t size, F callback)
{
	if (!array) return ;

	for (std::size_t i = 0; i < size; i++)
	{
		callback(array[i]);
	}
}
