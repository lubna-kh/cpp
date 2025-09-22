#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << "\n";
    }
}
