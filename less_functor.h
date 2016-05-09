//
// Created by nando2496 on 5/8/2016.
//

#ifndef UCD_CSCI2312_PA5_LESS_FUNCTOR_H
#define UCD_CSCI2312_PA5_LESS_FUNCTOR_H


#include <iostream>
#include <cstring>

namespace CS2312 {

    template < class T >
    class less {
    public:
        bool operator() (T lhs, T rhs) {return lhs < rhs;}
    };

    template <>
    class less < std::string > {

    public:

        bool operator() (std::string lhs, std::string rhs) {return lhs < rhs;}
    };

    template <>
    class less < const char * > {

    public:

        bool operator () (const char *lhs, const char *rhs) {return strcmp(lhs,rhs) < 0;}
    };
}

#endif //UCD_CSCI2312_PA5_LESS_FUNCTOR1_H
