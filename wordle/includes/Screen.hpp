/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:55:20 by mababou           #+#    #+#             */
/*   Updated: 2022/05/15 14:55:24 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
# define SCREEN_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define GREY   "\033[90m"      /* Grey */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDGREY	"\033[1;90m"           /* Bold Grey */
#define BOLDWHITE   "\033[1m\033[37m"

#define	INCORRECT	0
#define MISPLACED	1
#define CORRECT		2

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

# include "Dico.hpp"
# include "WordFind.hpp"

using namespace std;

class Screen
{

	public:

		Screen();
		~Screen();
		void	print(void) const;
		void	printKeyboard(void) const;
		string	formatChar(char c, char format) const;
		bool	processInput(string &);
		void	processFormat(string &);
		bool	isGameOver(void) const;
		void	setGameOver(bool mode);
		void	setCurrentFormatting(string);
		void	setDico(Dico *);
		void	setChecker(WordFind *);
		void	reset(void);

	private:
		vector<string>	_screenGrid;
		int				_currentLine;
		string			_currentFormatting;
		bool			_gameOver;
		Dico*			_dico;
		WordFind*		_checker;

};

std::ostream &			operator<<( std::ostream & o, Screen const & i );

#endif /* ********************************************************** SCREEN_H */