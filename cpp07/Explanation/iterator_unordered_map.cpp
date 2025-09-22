#include <unordered_map>
#include <iostream>

int main()
{
    std::unordered_map<std::string, int> people;

    people["Nick"] = 41;
    people["Dora"] = 4;
    people["Charlie"] = 22;
    people["David"] = 35;
    people["Eve"] = 28;

    // std::unordered_map<std::string, int>::iterator it;
    //i can comment this line and write auto word before it
    //so the compiler will know that its an iterator

    for (auto it = people.begin();it != people.end();it++)
    {
        std::cout<< "Name: "<< it->first<<", Age: "<<it->second<<std::endl;
    }
}