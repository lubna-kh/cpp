#include "File.hpp"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments" <<std::endl;
        return 1;
    }
    File file(argv[1], argv[2], argv[3]);
    file.openFile();
    return 0;
}