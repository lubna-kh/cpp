#include "File.hpp"

File::File(const std::string& fileName, const std::string& s1, const std::string& s2)
	: filenName(fileName), s1(s1), s2(s2) {}


int	File::findPos(std::string tmp, size_t pos)
{
	size_t start = 0;
	size_t len = 0;
	while (pos < tmp.length())
	{
		len = 0;
		if ((pos == 0 || tmp[pos - 1] == ' ') && tmp[pos] == s1[len])
		{
			start = pos;
			while (pos < tmp.length() && len < s1.length() && tmp[pos] == s1[len])
			{
				pos++;
				len++;
			}
			if (!(len < s1.length()) && (tmp[pos] == ' ' || pos == tmp.length()))
			{
				return start;
			}
		}
		else
			pos++;
		
	}
	return -1;
} 

std::string	File::replaceStr(std::string tmp, std::string& newStr)
{
	size_t pos = 0;
	size_t oldPos = 0;

	while ((pos = findPos(tmp, pos)) != -1) 
	{
		newStr += tmp.substr(oldPos, pos - oldPos) + s2;
		pos += s1.length();
		oldPos = pos;
	}
	newStr += tmp.substr(oldPos);
	return newStr;
}

void File::openFile()
{
	std::string	newStr;
	std::string	tmp;
	std::ifstream file(filenName.c_str());
	if (!file.is_open())
	{
		std::cout << "Error opening the file" << std::endl;
	}
	std::ofstream newFile((filenName + ".replace").c_str());
	while (std::getline(file, tmp))
	{
		replaceStr(tmp, newStr);
		newFile << newStr;
		if (!file.eof())
			newFile << std::endl;
	}
	file.close();
	newFile.close();
}
