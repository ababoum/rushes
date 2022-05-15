#ifndef DICO_HPP
#define DICO_HPP
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"   

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <limits.h>

class Dico
{

	public:
		Dico ( void );
		Dico (Dico const &src);
		Dico (std::string fileName);
		~Dico( void );
		Dico& operator=(Dico const &rhs);
		void setFile(std::string fileName);		
		bool loadDico( void );
		bool searchWord(std::string word);
		bool openFile( void );
		bool openFilelimitsWords(std::string findFile);
		bool loadLimitsWords( void );
		bool isValidWord( std::string userInput );
		std::string getFile( void ) const;
		std::set<std::string> getSet( void ) const;
		void printSet( void ) const;
		void printLimitsWords( void ) const;
		std::string wordToFind( void ) const;
		size_t getDicoSize( void ) const;

	private:
		std::string file;
		std::set<std::string> s1;
		std::set<std::string> s2;
		std::ifstream allWords;
		std::ifstream limitsWords;
		bool validWord(std::string buff);
};

#endif