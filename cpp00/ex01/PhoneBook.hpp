#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];
		int	count;
	public:
		void	loop();
		void	addContact();
		void	searchContact();
		void	displayContact(int index);
		void	allContact();
		void	enterData(std::string &data, std::string prompt);
};

#endif