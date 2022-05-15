/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dico.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:24:01 by jremy             #+#    #+#             */
/*   Updated: 2022/05/15 15:57:55 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dico.hpp"

Dico::Dico ( void )
{
}

Dico::Dico (std::string fileName)
{
	this->file = fileName;
}

Dico::~Dico( void )
{	
}

void Dico::setFile(std::string fileName)
{
	this->file = fileName;
}

bool Dico::openFile( void )
{
	if (this->allWords.is_open())
		this->allWords.close();
	if (file.length() == 0)
	{
		std::cerr << "wordle : fileName can't be empty" << std::endl;
		return (false);
	}
	this->allWords.open(file.c_str());
	if (!this->allWords.is_open())
		return (std::cout << "wordle : open error" << std::endl, false);
	return (true);
}

bool Dico::openFilelimitsWords( std::string fileName)
{
	if (fileName.length() == 0)
	{
		std::cerr << "wordle : fileName can't be empty" << std::endl;
		return (false);
	}
	this->limitsWords.open(fileName.c_str());
	if (!this->limitsWords.is_open())
		return (std::cout << "wordle : open error" << std::endl, false);
	return (true);
}

std::string Dico::getFile( void ) const
{
	return (this->file);
}

std::set<std::string> Dico::getSet( void ) const
{
	return (this->s1);
}

size_t Dico::getDicoSize( void ) const
{
	return (s1.size());
}

bool Dico::validWord(std::string buff)
{
	if (buff.length() != 5)
		return (false);
	for (size_t i = 0; i < buff.length(); i++)
	{
		if (isalpha(buff[i]) == false)
			return (false);
	}
	for (size_t i = 0; i < buff.length(); i++)
	{
		if (islower(buff[i]) == false)
			return (false);
	}
	return true;
}

bool Dico::loadDico(void)
{
	std::string buff;
	
	while (std::getline(this->allWords, buff))
	{
		if(validWord(buff) == false)
			return (std::cerr<<"wordle : " << buff << " is invalid" << std::endl, false);
		else
			this->s1.insert(buff);
	}
	if (s1.size() == 0)
		return (std::cerr<<"wordle : all words is empty" << std::endl, false);
	return (true);
}

bool Dico::loadLimitsWords(void)
{
	std::string buff;
	
	while (std::getline(this->limitsWords, buff))
	{
		if(validWord(buff) == false || isValidWord(buff) == false)
			return (std::cerr<<"wordle : " << buff << " is invalid" << std::endl, false);
		else
			this->s2.insert(buff);
	}
	if (s2.size() == 0)
		return (std::cerr<<"wordle : words to finds is empty" << std::endl, false);
	return (true);
}

bool Dico::isValidWord(std::string userInput)
{
	const bool is_in = s1.find(userInput) != s1.end();
	return is_in;
}

void Dico::printSet( void ) const
{
	std::cout << "filename [" << file << "]" << std::endl;
	
	for(auto it = s1.begin(); it != s1.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

void Dico::printLimitsWords( void ) const
{
	
	for(auto it = s2.begin(); it != s2.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

std::string Dico::wordToFind( void ) const
{
	std::string result;
	auto iter = s2.begin();
	size_t rand = std::rand() % s2.size();
	for (size_t i = 0; i < rand; i++)
		iter++;
	result = *iter;
	return (result);
}