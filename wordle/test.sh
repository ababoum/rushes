#!/bin/bash

TEST_NUMBER="0"
DIFF_STDOUT=""

chmod 000 dico/test/noread
function test_str()
{
	(( TEST_NUMBER++ ))
	echo -e "Testing"  "'$1'" "'$2'""ref : $TEST_NUMBER"
	./wordle "$1" "$2"
	echo "return value $?"
	echo " "
}

test_str 'dico/test/empty1' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/empty1'
test_str 'dico/test/noalpha' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/noalpha'
test_str 'dico/test/noalpha2' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/noalpha2'
test_str 'dico/test/noalpha3' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/noalpha3'
test_str 'dico/test/noalpha4' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/noalpha4'
test_str 'dico/test/solong' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/solong'
test_str 'dico/test/dir' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/dir'
test_str '' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' ''
test_str ' ' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' ' '
test_str 'dico/test/noread' 'dico/possible_words.txt'
test_str 'dico/possible_words.txt' 'dico/test/noread'
test_str 'dico/test/notsamewords' 'dico/test/notsamewords2'
test_str 'dico/test/notsamewords2' 'dico/test/notsamewords'

chmod 777 dico/test/noread
