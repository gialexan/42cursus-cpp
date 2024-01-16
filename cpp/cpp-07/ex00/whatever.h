/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:51:28 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 19:02:43 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T>
T MyMin(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T>
void Swap(T &x, T &y)
{
    T tmp = x;
    
    x = y;
    y = tmp;
}





#endif // !WHATEVER_H