#include "Data.hpp"
#include "Serializer.hpp"

int main(void){
    Data *inputData = new Data();
    Data *resultData;

    uintptr_t raw = Serializer::serialize(inputData);
    resultData = Serializer::deserialize(raw);
    
    std::cout << inputData << std::endl;
    std::cout << raw << std::endl;
    std::cout << resultData << std::endl;

    delete inputData;
    return 0;
}