# include "PhoneBook.hpp"

void	PhoneBook::loop()
{
	std::string command;
	count = 0;
	while (1)
	{
		std::cout <<  "Enter the Command(ADD/SEARCH/EXIT): ";
		std::cin >> command;
		if (std::cin.eof())
			exit(1);
		if (command.compare("ADD") == 0)
			addContact();
		else if (command.compare("SEARCH") == 0)
			searchContact();
		else if (command.compare("EXIT") == 0)
			return;
		else
			std::cout << "Invalid Command" << std::endl;
	}
};

void	PhoneBook::displayContact(int index)
{
	std::cout << "First Name: " << contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contact[index].getLastName() << std::endl;
	std::cout << "Nick Name: " << contact[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::allContact()
{
	int index;

	if (count > 8)
		index = 8;
	else
		index = count;
	std::cout << std::setw(10);
	std::cout << "index";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "firstName";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "lastName";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "nickName"<<std::endl;
	for (int i = 0;i < index; i++)
	{
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setw(10);
		if (contact[i].getFirstName().length() > 10)
			std::cout << contact[i].getFirstName().substr(0, 9) + '.' <<  "|";
		else
			std::cout << contact[i].getFirstName()<< "|";
		std::cout << std::setw(10);
		if (contact[i].getLastName().length() > 10)
			std::cout << contact[i].getLastName().substr(0, 9) + '.' <<  "|";
		else
			std::cout<< contact[i].getLastName()<< "|";
		std::cout << std::setw(10);
		if (contact[i].getNickName().length() > 10)
			std::cout << contact[i].getNickName().substr(0, 9) + '.' <<  "|";
		else
			std::cout<< contact[i].getNickName();
		std::cout << std::endl;
	}
}

void	PhoneBook::searchContact()
{
	if (count == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	allContact();
	std::cout<<"Enter Index: ";
	int index;
	std::cin>>index;
	if (std::cin.fail())
	{
		std::cout<<"You should enter a number!"<<std::endl;
		exit(1);
	}
	if (index >= 0 && index < 8 && index < count)
		displayContact(index);
	else
		std::cout<<"Invalid Index" << std::endl;
}

void	PhoneBook::enterData(std::string &data, std::string prompt)
{
	std::cout<<prompt;
	std::cin>>data;
	if (std::cin.eof())
			exit(1);
}

void	PhoneBook::addContact()
{
	int index = 0;
	std::string darkestSecret;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;

	index = count % 8;
	enterData(firstName, "Enter First Name: ");
	enterData(lastName, "Enter Last Name: ");
	enterData(nickName, "Enter Nick Name: ");
	enterData(phoneNumber, "Enter Phone Number: ");
	if (phoneNumber.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid Phone Number. It should contain only digits." << std::endl;
		return;
	}
	if (phoneNumber.length() != 10)
	{
		std::cout << "Invalid Phone Number, it must consist of 10 digits" << std::endl;
		return;
	}
	enterData(darkestSecret, "Enter Darkest Secret: ");
	count++;
	contact[index].setFirstName(firstName);
	contact[index].setLastName(lastName);
	contact[index].setNickName(nickName);
	contact[index].setPhoneNumber(phoneNumber);
	contact[index].setDarkestSecret(darkestSecret);
}