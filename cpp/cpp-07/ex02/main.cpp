/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:11:39 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/20 18:20:39 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"

#include <iostream>

int main(void)
{
   try
   {
      // Test default constructor
      Array<int> arr1;
      std::cout << "arr1 size: " << arr1.size() << std::endl;

      // Test constructor with size parameter
      Array<int> arr2(5);
      std::cout << "arr2 size: " << arr2.size() << std::endl;

      // Test copy constructor and assignment operator
      Array<int> arr3 = arr2;
      Array<int> arr4;
      arr4 = arr2;

      // Modify arr2, arr3 and arr4 should remain unchanged
      arr2[1] = 100;
      std::cout << "arr2[0]: " << arr2[0] << ", arr3[0]: " << arr3[0] << ", arr4[0]: " << arr4[0] << std::endl;

      // Test out-of-bounds access
      // Uncomment the line below to test the out-of-bounds exception
      // std::cout << arr2[10] << std::endl;
   }
   catch (const std::exception& e)
   {
      std::cerr << "Exception: " << e.what() << std::endl;
   }
}