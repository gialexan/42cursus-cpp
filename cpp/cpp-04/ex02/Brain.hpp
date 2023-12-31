#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(Brain const &src);
		Brain &operator=( Brain const & rhs );
		~Brain(void);
};

#endif /* *********************************************************** BRAIN_H */