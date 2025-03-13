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

		void	addIdea(const std::string &idea);
		std::string	getIdea(int index);
		int	getNumOfIdeas();

		Brain	&operator=(const Brain &brain);

		~Brain();
};
