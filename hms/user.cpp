#pragma once

#include "targetver.h"
#include "stdafx.h"
#include "user.h"
#include "home.h"

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

string user::getID(){ return id; }
string user::getName() { return name; }
string user::getPwd(){ return pwd; }
//setter
void user::setID(string _id) { id = _id; }
void user::setName(string _name){ name = _name; }
void user::setPwd(string _pwd) { pwd = _pwd; }

void user::view_home(){
	
	home *homePtr=new home();
	
	homePtr->displayDetail();
				
				 system("pause");

				  app a;

				 a.main();
 }



void user::manage_profile(string id, string name) {}
user::user(){}
user::~user(){}

