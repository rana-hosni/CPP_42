#include "Serializer.hpp"


// reinterpret_cast tells the compiler:
// “Don’t convert the value. Just re-interpret its raw bits as another type.”

int main() {
    Data data;
    Data* dataPtr = &data;
    data.value = 42;
    uintptr_t raw = Serializer::serialize(dataPtr);
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Original Data value: " << data.value << std::endl;
    std::cout << "Deserialized Data value: " << deserializedPtr->value << std::endl;
    std::cout << "Addresses are " << (dataPtr == deserializedPtr ? "the same." : "different.") << std::endl;
    std::cout << "Original Data address: " << dataPtr << std::endl;
    std::cout << "Deserialized Data address: " << deserializedPtr << std::endl;
    return 0;
}