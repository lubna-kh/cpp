#include "Serializer.hpp"

int main()
{
    Data data;
    data.age = 20;
    Serializer ser;
    
    std::cout<< &data <<std::endl;
    uintptr_t add = ser.serialize(&data);
    Data* ptr = ser.deserialize(add);
    std::cout<< ptr<<std::endl;

    return 0;
}

// int main()
// {
//     Data data(20, "lubna");
//     Serializer ser;

//     std::cout<<"____________before____________"<<std::endl;
//     uintptr_t add = ser.serialize(&data);
//     std::cout<< add <<std::endl;
//     std::cout<< &data <<std::endl;

//     std::cout<<"____________after____________"<<std::endl;
//     std::cout<< ser.deserialize(&data)<<std::endl;
//     std::cout<< &data <<std::endl;

//     return 0;
// }