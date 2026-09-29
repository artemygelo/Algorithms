#include "array.h"

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

    Data* newData = new Data[a.length];

    for (size_t i = 0; i < a.length; ++i)
        newData[i] = a.data[i];

    delete[] data;
    data = newData;
    length = a.length;

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