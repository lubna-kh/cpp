#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <iostream>
# include <fstream>
class File
{
	private:
		const std::string	filenName;
		const std::string	s1;
		const std::string	s2;

	public:
		File(const std::string& fileName, const std::string& s1, const std::string& s2);
		std::string	replaceStr(std::string tmp, std::string& newStr);
		int		findPos(std::string tmp, size_t pos);
		void	openFile();
};


#endif