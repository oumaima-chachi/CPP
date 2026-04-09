#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.number = 41;

    std::cout << "Original pointer: " << &data << "\n";

    unsigned long raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << "\n";

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered pointer: " << recovered << "\n";

    if (recovered == &data)
        std::cout << "Serialization/deserialization successful!\n";
    else
        std::cout << "Error!\n";

    std::cout << "Recovered data: " << recovered->number << "\n";

    return 0;
}