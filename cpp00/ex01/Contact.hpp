#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <cstdlib>

class Contact
{
	private:
		std::string darkestSecret;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		
	public:
		//constructor
		Contact();

		//setters
		void setLastName(std::string lastName);
		void setFirstName(std::string lastName);
		void setNickName(std::string lastName);
		void setDarkestSecret(std::string lastName);
		void setPhoneNumber(std::string lastName);

		//getters
		std::string getPhoneNumber();
		std::string getLastName();
		std::string getFirstName();
		std::string getNickName();
		std::string getDarkestSecret();
};

#endif