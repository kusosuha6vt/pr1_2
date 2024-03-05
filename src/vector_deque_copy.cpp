/*#include "vector_deque.h"
#include <iostream>
#include <stdexcept>
#include <utility>
#include "data.h"

void VectorDeque::swap(VectorDeque &other) {
    std::swap(vec, other.vec);
    std::swap(begin, other.begin);
    std::swap(end, other.end);
    // std::swap(other.smpl, smpl);
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
    // smpl = other.smpl;
}

VectorDeque::VectorDeque(VectorDeque &&other) {
    begin = std::exchange(other.begin, 0);
    end = std::exchange(other.end, 0);
    vec = std::move(other.vec);
    smpl = std::move(other.smpl);
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
    // smpl.push_front(data);
    // if (smpl.to_vector() != to_vector()) {
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
}

template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end();
         ++ii) {
        os << " " << *ii;
    }
    os << "]\n";
    return os;
}

void VectorDeque::push_back(const DataType &data) {
    // auto copy_this = this->to_vector();
    // auto copy_smpl = smpl.to_vector();
    if (this->isFull()) {
        throw std::runtime_error("Ошибка: дек заполнен");
    }
    new (getPosition(end)) DataType(data);
    end++;
    // smpl.push_back(data);
    // if (smpl.to_vector() != to_vector()) {
    //     std::cerr << begin << ' ' << end << '\n';
    //     std::cerr << "Add " << data << '\n';
    //     std::cerr << "Before: " << copy_this << ' ' << copy_smpl
    //               << "\nAfter:" << to_vector() << " " << smpl.to_vector()
    //               << "\n";
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
}

void VectorDeque::pop_front() {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    getPosition(begin)->~DataType();
    begin++;
    // smpl.pop_front();
    // if (smpl.to_vector() != to_vector()) {
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
}

void VectorDeque::pop_back() {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    end--;
    getPosition(end)->~DataType();
    // smpl.pop_back();
    // if (smpl.to_vector() != to_vector()) {
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
}

const DataType &VectorDeque::front() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    const DataType &res = *getPosition(begin);
    // smpl.front();
    // if (smpl.to_vector() != to_vector()) {
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
    return res;
}

const DataType &VectorDeque::back() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Ошибка: дек пуст");
    }
    const DataType &res = *getPosition(end - 1);
    // smpl.back();
    // if (smpl.to_vector() != to_vector()) {
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
    return res;
}

int VectorDeque::size() const {
    // if (smpl.to_vector() != to_vector()) {
    //     std::cerr << begin << ' ' << end << '\n';
    //     std::cerr << "\nAfter:" << to_vector() << " " << smpl.to_vector()
    //               << "\n";
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
    return end - begin;
}

bool VectorDeque::isFull() const {
    // if (size() == maxSize) {
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
    return size() == maxSize;
}

bool VectorDeque::isEmpty() const {
    // if (smpl.isEmpty() != (begin == end)) {
    //     throw std::runtime_error("line: " + std::to_string(__LINE__));
    // }
    return begin == end;
}

const DataType *VectorDeque::getPosition(int i) const {
    i = ((i % maxSize) + maxSize) % maxSize;
    return reinterpret_cast<const DataType *>(vec.data() + maxSize * i);
}

DataType *VectorDeque::getPosition(int i) {
    return const_cast<DataType *>(
        static_cast<const VectorDeque *>(this)->getPosition(i));
}
*/
