#include "list_deque.h"

void ListDeque::push_front(const DataType &data) {
    list.push_front(data);
}

void ListDeque::push_back(const DataType &data) {
    list.push_back(data);
}

void ListDeque::pop_front() {
    list.pop_front();
}

void ListDeque::pop_back() {
    list.pop_back();
}

const DataType &ListDeque::front() const {
    return list.front();
}

const DataType &ListDeque::back() const {
    return list.back();
}

bool ListDeque::isFull() const {
    return false;
}

bool ListDeque::isEmpty() const {
    return list.empty();
}
