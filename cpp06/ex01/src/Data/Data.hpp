#pragma once

class Data
{
	private:
		int		data;

	public:
		Data();
		Data(const Data &data);

		int	getData();

		Data	&operator=(const Data &data);

		~Data();
};
