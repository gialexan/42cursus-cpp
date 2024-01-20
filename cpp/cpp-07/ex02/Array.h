/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:16:03 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/20 18:20:21 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

template <typename T>
class Array
{
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &rhs);
        ~Array();
        Array &operator=(const Array &rhs);

        T& operator[](unsigned int index) const;
        unsigned int size(void) const;

    private:
        T *_array;
        unsigned int _arraySize;
};

template <typename T>
Array<T>::Array() : _array(0), _arraySize(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _arraySize(n)
{
    _array = new T[n];
}

template <typename T>
Array<T>::Array(const Array &rhs) : _arraySize(rhs._arraySize)
{
    *this = rhs;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
    if (this != &rhs)
    {
        delete[] _array;

        _arraySize = rhs._arraySize;
        _array = new T[_arraySize];
        for (unsigned int i = 0; i < _arraySize; ++i)
        {
            _array[i] = rhs._array[i];
        }
    }

    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _arraySize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return _arraySize;
}

#endif // !ARRAY_H