#ifndef WORDFIND_HPP
#define WORDFIND_HPP
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <time.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define GREY	"\033[90m"           /* Bold Grey */

#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"   
#define BOLDGREY	"\033[1;90m"           /* Bold Grey */

class WordFind
{

	public:
		WordFind ( void );
		WordFind (std::string toFind);
		~WordFind( void );
		std::string check(std::string userInput);
		void setFile(std::string newToFind);
		std::string getToFind( void ) const;
		std::string getKeyboard( void ) const;
		void updateValue(char letter, int value);
		void printKeyboard( void );
	private:
		std::string toFind;
		std::vector<int> v1;
		static std::string alphaB;
		static std::string keyBoard;
		bool is_in(char userInput, std::string toFind) const;
		size_t convert_key(char c);
};

#endif