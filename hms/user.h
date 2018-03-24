#ifndef USER_H
#define USER_H
#pragma once

#include "targetver.h"
#include "stdafx.h"

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
using namespace std;

 class user{

	 friend class staff;
	 friend class customer;
	 friend class client;

protected:
	string id;
	string pwd;
	string name;
public:
	//getter
	string getID();// { return this->id; }
	string getName();// { return this->name; }
	string getPwd();// { return this->pwd; }
	//setter
	 void setID(string _id);// { this->id = _id; }
	 void setName(string _name);// { this->name = _name; }
	 void setPwd(string _pwd);// { this->pwd = _pwd; }



	static void view_home();

	/*static string RandomString(int len);*/
	virtual string RandomString(int len)=0;//complete virtual function make the user class became an abstract class

	virtual void manage_profile(string id,string name)=0;// {}
user();//{}
~user();// {}

};

#endif