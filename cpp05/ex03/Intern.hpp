#ifndef ITRN
# define ITRN

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &i);
		~Intern();

		AForm *makeForm(std::string formName, std::string formTarget);
		Intern	&operator=(const Intern &i);

		class	FormNotFoundException : public std::exception
		{
			const char	*what(void) const throw()
			{
				return ("Form not found.");
			}
		};
};

#endif
