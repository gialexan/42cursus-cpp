/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:29:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/30 21:41:43 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define MAX 4

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j; //should not create a leak
	delete i;

	std::cout << "----------------------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << "----------------------" << std::endl;

	const Animal *array[MAX] = {new Cat(), new Dog(), new Cat(), new Dog()};

	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < MAX; i++)
	{
		delete array[i];
		std::cout << "----------------------" << std::endl;
	}

	return 0;
}