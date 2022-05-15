/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:55:20 by mababou           #+#    #+#             */
/*   Updated: 2022/05/15 17:00:55 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Screen.hpp"

# define INTRO	\
" .       __   ___   .___  .___   .     .____\n\
 /       |  .'   `. /   \\ /   `  /     /     \n\
 |       |  |     | |__-' |    | |     |__.  \n\
 |  /\\   /  |     | |  \\  |    | |     |     \n\
 |,'  \\,'    `.__.' /   \\ /---/  /---/ /----\n"

# define EMPTY_LINE	"\t\t_ _ _ _ _ \n"


/*
** ------------------------------- UTILS --------------------------------
*/

bool isAlphaNumeric(const std::string &str)
{
    auto it = std::find_if_not(str.begin(), str.end(), [](char const &c) {
            return isalpha(c);
        });
 
    return it == str.end();
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Screen::Screen()
{
	_screenGrid.push_back(INTRO);
	
	for (int i = 0; i < 6; i++)
		_screenGrid.push_back(EMPTY_LINE);

	_currentLine = 1;
	_gameOver = 0;
	_dico = 0;
	_checker = 0;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Screen::~Screen()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Screen::print(void) const
{
	system("clear");

	for (auto it = _screenGrid.begin(); it != _screenGrid.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;
}

string	Screen::formatChar(char c, char format) const
{
	string	formattedChar;
	int		check;

	c = toupper(c);
	check = atoi(&format);

	switch (check)
	{
	case INCORRECT:
		formattedChar += BOLDGREY;
		formattedChar += c;
		formattedChar += RESET;
		formattedChar += " ";
		break;
		
	case MISPLACED:
		formattedChar += BOLDYELLOW;
		formattedChar += c;
		formattedChar += RESET;
		formattedChar += " ";
		break;

	case CORRECT:
		formattedChar += BOLDGREEN;
		formattedChar += c;
		formattedChar += RESET;
		formattedChar += " ";
		break;
	
	default:
		break;
	}
	return (formattedChar);
}

bool	Screen::processInput(string & str)
{
	if (str.length() != 5)
	{
		print();
		cout << BOLDRED << "Your word must be 5-letter long!" 
			<< RESET << endl << endl;;
		return false;
	}

	if (!isAlphaNumeric(str))
	{
		print();
		cout << BOLDRED << "Your word must contain only letters!" 
			<< RESET << endl << endl;;
		return false;
	}

	for_each(str.begin(), str.end(), [](char & c) {
        c = ::tolower(c);
    });

	// check here if the word exists
	if (!_dico->isValidWord(str))
	{
		print();
		cout << BOLDRED << "Your word does not exist in the dictionary!" 
			<< RESET << endl << endl;;
		return false;
	}
	return true;
}

void	Screen::processFormat(string & str)
{
	// get the word formatted by the checker
	_screenGrid[_currentLine] = "";
	_screenGrid[_currentLine] += "\t\t";
	
	for (int i = 0; i < 5; ++i)
	{
		_screenGrid[_currentLine] += formatChar(str[i], _currentFormatting[i]);
	}
	_screenGrid[_currentLine] += "\n";

	print();

	if (!_currentFormatting.compare("22222")) {
		_gameOver = 1;
		cout << BOLDGREEN << "\t    Congratulations!\n"
			<< RESET << endl;
		return ;
	}
	if (_currentLine++ == 6)
	{
		// display end of game screen (loss)
		_gameOver = 1;
		cout << BOLDCYAN << "Game over! The word to find was "
			<< _checker->getToFind() << RESET << endl << endl;
		return ;
	}
}

void	Screen::reset(void)
{
	for (int i = 1; i < 7; i++)
		_screenGrid[i] = EMPTY_LINE;

	_currentLine = 1;
	_gameOver = 0;
	_dico = 0;
	_checker = 0;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool	Screen::isGameOver(void) const
{
	return (_gameOver);
}

void	Screen::setGameOver(bool mode)
{
	_gameOver = mode;
}

void	Screen::setCurrentFormatting(string format)
{
	_currentFormatting = format;
}

void	Screen::setDico(Dico * dico)
{
	string str;

	_dico = dico;
	str += INTRO;
	str += "\n\t Total words available: ";
	str += to_string(_dico->getDicoSize());
	str += "\n";

	_screenGrid[0] = str;
}

void	Screen::setChecker(WordFind * checker)
{
	_checker = checker;
}

/* ************************************************************************** */