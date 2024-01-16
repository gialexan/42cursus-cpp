#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &name, int gradeSign, int gradeExec);
		~ShrubberyCreationForm(void);
	
	private:
		void executeAction(void) const;
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */