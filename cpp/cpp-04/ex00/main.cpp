/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:29:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/25 21:19:46 by gialexan         ###   ########.fr       */
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
	animal->makeSound();
	delete animal;
	std::cout << std::endl;


	
	const Animal* cat = new Cat();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	delete cat;
	std::cout << std::endl;

	
	const Animal* dog = new Dog();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	delete dog;
	std::cout << std::endl;


    std::cout << std::endl << " **** WRONG CLASSES **** " << std::endl;

	const	WrongAnimal *Worngcat = new WrongCat();
	std::cout << Worngcat->getType() << " " << std::endl;
	Worngcat->makeSound(); //will output the cat sound!
	delete Worngcat;
	std::cout << std::endl;
	
	const	WrongAnimal *Wornganimal = new WrongAnimal();
	std::cout << Wornganimal->getType() << " " << std::endl;
	Wornganimal->makeSound(); //will output the cat sound!
	delete Wornganimal;
	std::cout << std::endl;
	
	return 0;
}