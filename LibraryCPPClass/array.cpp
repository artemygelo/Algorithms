#include "array.h"
#include <utility>

Array::Array(size_t size)
    : data(new Data[size]{}), length(size)
{
}

Array::Array(const Array &a)
    : data(new Data[a.length]), length(a.length)
{
    for (size_t i = 0; i < length; ++i)
        data[i] = a.data[i];
}

Array &Array::operator=(const Array &a)
{
    if (this == &a)
        return *this;

    Array copy(a);

    std::swap(data, copy.data);
    std::swap(length, copy.length);

    return *this;
}

Array::~Array()
{
    delete[] data;
}

Data Array::get(size_t index) const
{
    return data[index];
}

void Array::set(size_t index, Data value)
{
    data[index] = value;
}

size_t Array::size() const
{
    return length;
}