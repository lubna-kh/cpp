#include "Serializer.hpp"

int main()
{
    Data data;
    data.age = 20;
    Serializer ser;
    
    std::cout<<"Before:"<<std::endl;
    std::cout<< &data <<std::endl;
    uintptr_t add = ser.serialize(&data);
    Data* ptr = ser.deserialize(add);
    std::cout<<"After:"<<std::endl;
    std::cout<< ptr<<std::endl;

    return 0;
}