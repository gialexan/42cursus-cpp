/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:29:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/30 10:49:28 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* animal = new Animal();
	std::cout << animal->getType() << " " << std::endl;
	animal->makeSound(); //will output the animal sound!
	delete animal;
	std::cout << "----------------------" << std::endl;

	const Animal* cat = new Cat();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	delete cat;
	std::cout << "----------------------" << std::endl;

	const Animal* dog = new Dog();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound(); //will output the dog sound!
	delete dog;
	std::cout << "----------------------" << std::endl;

    std::cout << " **** WRONG CLASSES **** " << std::endl;
	
	const	WrongAnimal *Worngcat = new WrongCat();
	std::cout << Worngcat->getType() << " " << std::endl;
	Worngcat->makeSound(); //will output the wrong cat sound!
	delete Worngcat;
	std::cout << "----------------------" << std::endl;
	
	const	WrongAnimal *Wornganimal = new WrongAnimal();
	std::cout << Wornganimal->getType() << " " << std::endl;
	Wornganimal->makeSound(); //will output the wrong animal sound!
	delete Wornganimal;
	
	return 0;
}