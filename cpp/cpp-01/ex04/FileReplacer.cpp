/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:33:51 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:52:48 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(void) {}

FileReplacer::~FileReplacer(void) {}

FileReplacer::FileReplacer(const std::string &filename, const std::string &removeString, const std::string &insertString) : 
    _filename(filename), _removeString(removeString), _insertString(insertString)
{
    if (removeString.empty() || insertString.empty())
    {
        std::cout << "Error: empty string" << std::endl;
        return;
    }
    std::string textFile  = _readFile(_filename);
    if (textFile.empty())
        return ;
    _replaceText(textFile, _removeString, _insertString);
    _writeFile(textFile, _filename, ".replace");
}

std::string FileReplacer::_readFile(const std::string &filename)
{
    std::string textFile("");
    std::ifstream inFile;
    std::string lineFile;
    
    inFile.open("test.txt");
    if (!inFile.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return std::string();
    }
    while (std::getline(inFile, lineFile))
        textFile += lineFile;
    return textFile;
}

void FileReplacer::_replaceText(std::string &text, const std::string &removeString, const std::string &insertString)
{
    size_t position;

    while ((position = text.find(removeString, position)) != std::string::npos)
    {
        text.erase(position, removeString.length());
        text.insert(position, insertString);
        position += insertString.length();
    }
}

void FileReplacer::_writeFile(const std::string &text, const std::string &filename, const std::string &suffix)
{
    std::ofstream output(filename + suffix);
    output << text;
    output.close();
}
