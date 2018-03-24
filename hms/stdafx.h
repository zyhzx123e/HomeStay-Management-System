// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <iomanip>
#include <ctime>
#include <time.h>

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <stdlib.h>
#include <string.h>
#include<algorithm>
#include<iterator>
#include <chrono>
#include <thread>


using namespace std;
string RandomString(int len);

std::string space2underscore(string text)
{

	int length = text.size();
	int x = 0;
	string fixed;

	while (x != length) {
		string letter = text.substr(x, 1);
		if (letter == " ") {
			letter = "_";
		}
		fixed = fixed + letter;
		x = x + 1;
	}

	return fixed;
}


//generic class user
//change all the space to underscore in order to store them in to txt file and easy to be read by cin
std::string space_underscore(std::string text) {
	for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
		if (*it == ' ') {
			*it = '_';
		}
	}
	return text;
}
//reference from c++ - Replace space with an underscore - Stack Overflow. 2016. c++ - Replace space with an underscore - Stack Overflow. [ONLINE] Available at: http://stackoverflow.com/questions/5252612/replace-space-with-an-underscore [show]. [Accessed 26 November 2016].
std::string space22underscore(std::string text)
{
	std::replace(text.begin(), text.end(), ' ', '_');
	return text;
}




template <typename T>
std::string toString(T Number)
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}


class app{

public:
	app(){}
	~app(){}
	int main();
	void client_ui();
	void customer_ui();
	void home_ui();
	void staff_ui();
};


// TODO: reference additional headers your program requires here
