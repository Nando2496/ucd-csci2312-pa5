//
// Created by Ivo Georgiev on 5/3/16.
//

#ifndef UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
#define UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H

// Naive partial implementation of a custom iterator.
// After Jeet Sukumaran https://github.com/jeetsukumaran

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>

namespace CS2312 {

    template <typename T>
    class fixed_array {

    public:

        typedef std::size_t size_type;

        class iterator {

        public:

            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            iterator(pointer ptr) {
                __ptr = ptr;
            }
            self_type operator++(){
                __ptr++;
                return *this;
            }
            self_type operator++(int junk){
                self_type tempInc = *this;
                __ptr++;
                return tempInc;
            }
            reference operator*(){
                return *__ptr;
            }
            pointer operator->(){
                return __ptr;
            }
            bool operator==(const self_type& rhs) const{
                return __ptr == rhs.__ptr;

            }
            bool operator!=(const self_type& rhs) const{
                return !(*this == rhs);
            }

        private:

            pointer __ptr;

        };

        class const_iterator {

        public:

            typedef const_iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            const_iterator(pointer ptr) {__ptr = ptr;}

            self_type operator++(){
                __ptr = __ptr++;
                return *this;
            }

            self_type operator++(int junk){
                self_type tempInc = *this;
                __ptr++;
                return tempInc;
            }

            const value_type& operator*() const {return *__ptr;}

            const value_type* operator->() const {return __ptr;}

            bool operator==(const self_type& rhs) const {return __ptr == rhs.__ptr;}

            bool operator!=(const self_type& rhs) const {return *this == rhs;}

        private:

            pointer __ptr;

        };


        fixed_array(size_type size){
            __size = size;
            __data = new T[size];
        }

        fixed_array(std::initializer_list<T> list){
            __size = list.size();
            __data = new T[list.size()];
            for(int i = 0; i < list.size(); i++) {
                __data[i] = *list.begin() + i;
            }
        }

        ~fixed_array() {delete __data;}

        size_type size() const {return __size;}

        T& operator[](size_type index) {return __data[index];}

        const T& operator[](size_type index) const{
            return __data[index];
        }

        iterator begin(){
            iterator *tempIt = new iterator(__data);
            return *tempIt;
        }

        iterator end(){
            iterator *tempIt = new iterator(__data+(size()));
            return *tempIt;
        }

        const_iterator begin() const{
            const_iterator *tempConstIt = new const_iterator(__data);
            return *tempConstIt;
        }

        const_iterator end() const{
            const_iterator *tempConstIt = new const_iterator(__data+(size()));
            return *tempConstIt;
        }

    private:

        T* __data;
        size_type __size;

    };

}

#endif //UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
