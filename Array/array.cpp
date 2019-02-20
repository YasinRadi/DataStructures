#include <iostream>

template<typename T, int size>
class Array {
    private:
        // Pointer to base position of array
        T* head;
    
    public:
        // Constructor
        Array() {
            this->head = (T*)malloc(sizeof(T) * size);
            for (int i = 0; i < size; i++)
                *(head+i) = T();
        };

        // [] Operator overloading
        T& operator [](int idx) {
            return *(head+idx);
        };

        // [] Operator overloading
        T operator [](int idx) const {
            return *(head+idx);
        };
};

