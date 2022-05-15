#include "../includes/WordFind.hpp"

std::string	WordFind::alphaB = "abcdefghijklmnopqrstuvwxyz";
std::string	WordFind::keyBoard = "qwertyuiopasdfghjklzxcvbnm";

WordFind::WordFind ( void ): v1(26, 0)
{
}

WordFind::WordFind (std::string newToFind): v1(26, 0)
{
	this->toFind = newToFind;
}

WordFind::~WordFind( void )
{
}

void WordFind::setFile(std::string newToFind)
{
	this->toFind = newToFind;
}


std::string WordFind::getToFind( void ) const
{
	return (this->toFind);
}

std::string WordFind::getKeyboard( void ) const
{
	return (this->alphaB);
}

bool WordFind::is_in(char userInput, std::string toFind) const
{
	for(size_t i = 0; i < toFind.length(); i++)
	{	
		if(userInput == toFind[i])
				return true;
	}
	return false;
}

void WordFind::updateValue(char letter, int value)
{
	for (size_t i = 0; i < alphaB.length(); i++)
	{
		if (alphaB[i] == letter && v1[i] < 1)
			v1[i] = value;
		if (alphaB[i] == letter && v1[i] < 2 && value == 2)
			v1[i] = value;
	}
}

size_t WordFind::convert_key(char c)
{
	for (size_t i = 0; i < alphaB.length(); i++ )
	{
		if (alphaB[i] == c)
			return i;
	}
	return 0;
}

void WordFind::printKeyboard( void )
{
	std::cout <<"     ";
	for(size_t i = 0; i < keyBoard.length() ; i++)
	{
		std::cout << "|";
		if(v1[WordFind::convert_key(keyBoard[i])] == 0)
			std::cout << BOLDWHITE;
		if(v1[WordFind::convert_key(keyBoard[i])] == -1)
			std::cout << BOLDGREY;
		if(v1[WordFind::convert_key(keyBoard[i])] == 1)
			std::cout << BOLDYELLOW;
		if(v1[WordFind::convert_key(keyBoard[i])] == 2)
			std::cout << BOLDGREEN;
		std::cout << keyBoard[i];
		std::cout << RESET;
		std::cout << "|";
		if (i == 9)
			std::cout << std::endl << "       ";
		if (i == 18)
			std::cout << std::endl << "         ";
	}
	std::cout << std::endl;
}

std::string WordFind::check(std::string userInput)
{
	std::string result;
	std::string last = toFind;
	for(size_t i = 0; i < toFind.length(); i++)
	{
		if(userInput[i] == last[i])
		{
			result += '2';
			WordFind::updateValue(userInput[i], 2);
			last[i] = '.';
		}
		else
			result += '0';
	}
	for(size_t i = 0; i < toFind.length(); i++)
	{
		if (result[i] == '2')
			continue;
		if(WordFind::is_in(userInput[i], last) == true)
		{
			result[i] = '1';
			WordFind::updateValue(userInput[i], 1);
			for (size_t j = 0; j < toFind.length() ; j++)
			{
				if(userInput[i] == last[j])
				{
					last[j] = '.';
					break;
				}
			}
		}
		else
			WordFind::updateValue(userInput[i], -1);	
	}
	return result;
}
