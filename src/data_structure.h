#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H
#include "pch.hpp"
template<typename T>
class Deque : public std::deque<T> {
public:
    Deque() : std::deque<T>() {
    }
    typename std::deque<T>::iterator find(const T &value) {
        auto it = this->end();
        toy::enumerate(
            *this,
            [this, &value, &it](const auto i, const auto &_value) {
                if (_value == value) {
                    it = this->begin() + i;
                    return true;
                }
                return false;
            });
        return it;
    }
};


#endif // DATA_STRUCTURE_H
