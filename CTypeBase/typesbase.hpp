#ifndef TYPESBASE_HPP
#define TYPESBASE_HPP

#include <cstdint>

namespace std {

typedef int8_t Short;
typedef int32_t Integer;
typedef uint8_t Character;


    template <class T>
    class TypeBase {
        private:
            T myVal;
        public:
            explicit TypeBase(const T & Val){
                myVal = Val;
            }
    };

    typedef int T;
    T i = 1;
    TypeBase<T> mytype (i);
}


#endif // TYPESBASE_HPP
