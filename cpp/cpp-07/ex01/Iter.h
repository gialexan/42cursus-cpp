/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:07:14 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 19:13:29 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <iostream>

template <typename T, typename Func>
void Iter(T *array, size_t length, Func func)
{
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template<typename T>
void PrintElement(const T& element) {
    std::cout << element << " ";
}

#endif // !ITER_H