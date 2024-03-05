#include "simple_vector_deque.h"

void SimpleVectorDeque::push_front(const DataType &data) {
    vec.insert(vec.begin(), data);
}

void SimpleVectorDeque::push_back(const DataType &data) {
    vec.push_back(data);
}

void SimpleVectorDeque::pop_front() {
    vec.erase(vec.begin());
}

void SimpleVectorDeque::pop_back() {
    vec.pop_back();
}

const DataType &SimpleVectorDeque::front() const {
    return vec.front();
}

const DataType &SimpleVectorDeque::back() const {
    return vec.back();
}

bool SimpleVectorDeque::isFull() const {
    return false;
}

bool SimpleVectorDeque::isEmpty() const {
    return vec.empty();
}
