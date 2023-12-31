/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:29:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/31 07:01:21 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define MAX 4

int main(void)
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	delete j; //should not create a leak
	delete i;

	std::cout << "----------------------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << "----------------------" << std::endl;

	const AAnimal *array[MAX] = {new Cat(), new Dog(), new Cat(), new Dog()};

	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < MAX; i++)
	{
		delete array[i];
		std::cout << "----------------------" << std::endl;
	}

	return 0;
}