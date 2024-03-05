#include "vector_deque.h"
#include <iostream>
#include <stdexcept>
#include <utility>
#include "data.h"

void VectorDeque::swap(VectorDeque &other) {
    std::swap(vec, other.vec);
    std::swap(begin, other.begin);
    std::swap(end, other.end);
    std::swap(maxSize, other.maxSize);
}

VectorDeque::VectorDeque(int maxSize) : maxSize(maxSize) {
    vec.resize(maxSize * sizeof(DataType));
}

VectorDeque::~VectorDeque() {
    for (int i = begin; i < end; ++i) {
        getPosition(i)->~DataType();
    }
}

VectorDeque::VectorDeque(const VectorDeque &other) {
    vec.resize(other.vec.size());
    begin = 0;
    end = other.size();
    for (int i = 0; i < end; ++i) {
        new (getPosition(i)) DataType(*other.getPosition(i));
    }
}

VectorDeque::VectorDeque(VectorDeque &&other) {
    begin = std::exchange(other.begin, 0);
    end = std::exchange(other.end, 0);
    vec = std::move(other.vec);
}

VectorDeque &VectorDeque::operator=(VectorDeque other) {
    this->swap(other);
    return *this;
}

void VectorDeque::push_front(const DataType &data) {
    if (this->isFull()) {
        throw std::runtime_error("Ошибка: дек заполнен");
    }
    begin--;
    new (getPosition(begin)) DataType(data);
}

// template <class T>
// std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
//     os << "[";
//     for (typename std::vector<T>::const_iterator ii = v.begin(); ii !=
//     v.end();
//          ++ii) {
//         os << " " << *ii;
//     }
//     os << "]\n";
//     return os;
// }

void VectorDeque::push_back(const DataType &data) {
    if (this->isFull()) {
        throw std::runtime_error("Ошибка: дек заполнен");
    }
    new (getPosition(end)) DataType(data);
    end++;
}

void VectorDeque::pop_front() {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    getPosition(begin)->~DataType();
    begin++;
}

void VectorDeque::pop_back() {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    end--;
    getPosition(end)->~DataType();
}

const DataType &VectorDeque::front() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    const DataType &res = *getPosition(begin);
    return res;
}

const DataType &VectorDeque::back() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    const DataType &res = *getPosition(end - 1);
    return res;
}

int VectorDeque::size() const {
    return end - begin;
}

bool VectorDeque::isFull() const {
    return size() == maxSize;
}

bool VectorDeque::isEmpty() const {
    return begin == end;
}

const DataType *VectorDeque::getPosition(int i) const {
    i = ((i % maxSize) + maxSize) % maxSize;
    return reinterpret_cast<const DataType *>(vec.data() +
                                              sizeof(DataType) * i);
}

DataType *VectorDeque::getPosition(int i) {
    return const_cast<DataType *>(
        static_cast<const VectorDeque *>(this)->getPosition(i));
}
