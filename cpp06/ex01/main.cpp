#include "Serializer.hpp"

int main()
{
    Data data;
    data.age = 20;
    
    std::cout<<"Before:"<<std::endl;

    std::cout<< &data <<std::endl;
    std::cout<<"Data age: "<< data.age <<std::endl;

    uintptr_t add = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(add);


    std::cout<<"After:"<<std::endl;
    std::cout<< ptr<<std::endl;
    std::cout<<"Data age: "<< data.age <<std::endl;
    return 0;
}