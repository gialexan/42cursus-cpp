/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:40:52 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 18:06:13 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main(void)
{
    Data data;
    
    data.value = 42;

    std::cout << "Data value before conversion: " << data.value << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
    Data *deserialized = Serializer::deserialize(serialized);

    std::string status = (deserialized == &data) ? "successful" : "failed";
    std::cout << "Serialization and deserialization " << status << "!" << std::endl;

    std::cout << "Data value after conversion: " << deserialized->value << std::endl;
}