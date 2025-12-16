#include "Harl.hpp"

//Function pointer used to call the function
int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	Harl	harl;

	harl.complain(argv[1]);
	return 0;
}