#ifndef SIMPLE_VECTOR_DEQUE_H_
#define SIMPLE_VECTOR_DEQUE_H_

#include <vector>
#include "deque.h"

// простейшая имплементация, используя std::vector
class SimpleVectorDeque : public Deque {
public:
    SimpleVectorDeque() = default;
    SimpleVectorDeque(const SimpleVectorDeque &other) = default;
    SimpleVectorDeque(SimpleVectorDeque &&other) = default;
    SimpleVectorDeque &operator=(const SimpleVectorDeque &other) = default;
    SimpleVectorDeque &operator=(SimpleVectorDeque &&other) = default;
    ~SimpleVectorDeque() override = default;
    // все дефолтные конструкторы и операторы= подходят
    void push_front(const DataType &data) override;

    void push_back(const DataType &data) override;

    void pop_front() override;

    void pop_back() override;

    const DataType &front() const override;

    const DataType &back() const override;

    bool isFull() const override;

    bool isEmpty() const override;

private:
    std::vector<DataType> vec;
};

#endif
