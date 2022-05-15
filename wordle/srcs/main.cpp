/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:29:24 by jremy             #+#    #+#             */
/*   Updated: 2022/05/15 16:45:47 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dico.hpp"
#include "../includes/WordFind.hpp"
#include "../includes/Screen.hpp"

using namespace std;

bool initDico(Dico &dico, std::string limitsWords)
{
	if (dico.openFile() == false)
		return false;
	if (dico.openFilelimitsWords(limitsWords) == false)
		return false;
	if (dico.loadDico() == false)
		return false;
	if (dico.loadLimitsWords() == false)
		return false;
	return true;
};

int main (int ac, char **av)
{
	srand (time(NULL));
	std::string allWords;
	std::string limitsWords;
	if (ac == 2 || ac > 3)
		return (std::cerr << "wordle help : ./wordle [dico all words] [dico words to fin]" << std::endl, false);
	if (ac == 3)
	{
		allWords = av[1];
		limitsWords = av[2];
	}
	else
	{
		allWords = "dico/words.txt";
		limitsWords = "dico/possible_words.txt";
	}
	// create a dictionary instance
	Dico dico(allWords); 
	if (initDico(dico, limitsWords) == false)
		return (1);
	Screen	screen;
	string	input;
	
	while (42)
	{
		// create a checker instance
		WordFind toFind(dico.wordToFind());
		screen.setDico(&dico);
		screen.setChecker(&toFind);
		screen.print();
		toFind.printKeyboard();
		while (!screen.isGameOver())
		{
			while (42)
			{
				cout << "\n  ➡️  ";
				getline(cin, input, '\n');
				if (cin.eof() == 1 || cin.fail()) {
					cout << endl 
						<< BOLDGREEN << "Thanks for playing Wordle, bye!" 
						<< RESET << endl;
					return (EXIT_SUCCESS);
				}
				else {
					break ;
				}
			}
			if (!screen.processInput(input))
			{
				toFind.printKeyboard();
				continue ;
			}
			screen.setCurrentFormatting(toFind.check(input));
			screen.processFormat(input);
			toFind.printKeyboard();
			//cout << toFind.getToFind() << std::endl;
		}
		cout << endl << "Do you want to play again? (y/n)" << endl;
		while (42) {
			getline(cin, input, '\n');
			if (cin.eof() == 1 || cin.fail() || input == "N" || input == "n") {
				cout << endl 
					<< BOLDGREEN << "Thanks for playing Wordle, bye!" 
					<< RESET << endl;
				return (EXIT_SUCCESS);
			}
			else if (input == "Y" || input == "y")
			{
				screen.reset();
				input.clear();
				break ;
			}
			else
			{
				cout << "try again (y/n)" << endl;
		
				continue ;
			}
		}
	
	}
	return (EXIT_SUCCESS);
}
