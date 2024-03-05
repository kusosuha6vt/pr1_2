#ifndef LIST_DEQUE_H_
#define LIST_DEQUE_H_

#include <list>
#include "deque.h"

// Имплементация дека с помощью списка
class ListDeque : public Deque {
public:
    // все конструкторы и операторы= по умолчанию подходят
    ListDeque() = default;
    ListDeque(const ListDeque &other) = default;
    ListDeque(ListDeque &&other) = default;
    ListDeque &operator=(const ListDeque &other) = default;
    ListDeque &operator=(ListDeque &&other) = default;
    ~ListDeque() override = default;
    
    void push_front(const DataType &data) override;
    void push_back(const DataType &data) override;
    void pop_front() override;
    void pop_back() override;
    const DataType &front() const override;
    const DataType &back() const override;
    bool isFull() const override;
    bool isEmpty() const override;

private:
    std::list<DataType> list;
};

#endif
