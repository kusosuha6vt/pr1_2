#ifndef VECTOR_DEQUE_H_
#define VECTOR_DEQUE_H_

#include <cstddef>
#include <vector>
#include "deque.h"

// имплементация, используя циклический std::vector
class VectorDeque : public Deque {
public:
    explicit VectorDeque(int maxSize = 0);
    ~VectorDeque();
    VectorDeque(const VectorDeque &other);
    VectorDeque(VectorDeque &&other);
    VectorDeque &operator=(VectorDeque other);

    int size() const;

    void push_front(const DataType &data) override;

    void push_back(const DataType &data) override;

    void pop_front() override;

    void pop_back() override;

    const DataType &front() const override;

    const DataType &back() const override;

    bool isFull() const override;

    bool isEmpty() const override;

    // помеять местами два vector. Нужно для copy-swap идиомы
    void swap(VectorDeque &other);

    std::vector<DataType> to_vector() const {
        std::vector<DataType> res;
        for (int i = begin; i < end; ++i) {
            res.push_back(*getPosition(i));
        }
        return res;
    }
    
private:
    // хранит память под данные
    std::vector<std::byte> vec;
    // индекс начала (включительно)
    int begin = 0;
    // индекс конца (не включительно)
    int end = 0;
    int maxSize = 0;

    const DataType *getPosition(int i) const;
    DataType *getPosition(int i);
};

#endif
