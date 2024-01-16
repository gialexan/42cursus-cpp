/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:10:48 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 18:39:14 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>

#include "Base.hpp"

Base *generate(void);

void identify(Base *p);

void identify(Base &p);

int main(void)
{
    Base *basePtr = generate();

    identify(basePtr);
    
    Base &baseRef = *basePtr;
    
    identify(baseRef);

    delete basePtr;
}


Base *generate(void)
{
    srand(time(NULL));
    
    switch (std::rand() % 3)
    {
        case 0:
            return new A();
            
        case 1:
            return new B();
            
        case 2:
            return new C();
    }
    
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Object Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object Type B" << std::endl;
    else
        std::cout << "Object Type C" << std::endl;
}

void identify(Base &p)
{
    Base base;
    
    try
    {
        base = dynamic_cast<A&>(p);
        std::cout << "Object Type A" << std::endl;
        
        return ;
    }
    catch(...) {}

    try
    {
        base = dynamic_cast<B&>(p);
        std::cout << "Object Type B" << std::endl;
        
        return ;
    }
    catch(...) {}

    try
    {
        base = dynamic_cast<C&>(p);
        std::cout << "Object Type C" << std::endl;
        
        return ;
    }
    catch(...) {}

    
}