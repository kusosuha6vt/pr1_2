#ifndef DEQUE_H_
#define DEQUE_H_

#include "data.h"

// Интерфейс класса Дек
class Deque {
public:
    // вставить в начало
    virtual void push_front(const DataType &data) = 0;
    // вставить в конец
    virtual void push_back(const DataType &data) = 0;
    // удалить из начала
    virtual void pop_front() = 0;
    // удалить из конца
    virtual void pop_back() = 0;
    // получить начало
    virtual const DataType &front() const = 0;
    // получить конец
    virtual const DataType &back() const = 0;
    // полный ли Дек
    virtual bool isFull() const = 0;
    // пустой ли дек
    virtual bool isEmpty() const = 0;
    // деструктор
    virtual ~Deque(){};
};

#endif
