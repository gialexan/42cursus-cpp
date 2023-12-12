/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:33:43 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 12:34:32 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <iostream>
# include <string>
# include <fstream>

class FileReplacer
{
    private:
        std::string _filename;
        std::string _removeString;
        std::string _insertString;

        std::string _readFile(const std::string &filename);
        void _writeFile(const std::string &text, const std::string &filename, const std::string &suffix);
        void _replaceText(std::string &text, const std::string &insertString, const std::string &removeString);

    public:
        FileReplacer(const std::string &filename, const std::string &insertString, const std::string &removeString);
        
        FileReplacer(void);
        ~FileReplacer(void);
};

#endif
