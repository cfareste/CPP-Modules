#pragma once

#define MAX_IDEAS 100

#include <string>

class Brain {
	private:
		int			last_idea_index;
		std::string	ideas[MAX_IDEAS];

	public:
		Brain();
		Brain(const Brain &brain);

		void	addIdea(std::string &idea);
		std::string	getIdea(int index);

		Brain	&operator=(const Brain &brain);

		~Brain();
};
