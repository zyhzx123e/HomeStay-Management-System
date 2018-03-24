#ifndef HOME_H 
#define HOME_H


#pragma once

#include "targetver.h"
#include "client.h"
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


//class home
class home{

	friend class booking;
private:
	string home_id; string home_address;
	int no_room; int no_bath_room; int max_capacity;

	double sq_ft;

public:
	string facility;
	string description;
	string owner_id;
	string comment;
	string commentID;

	double day_price; double week_price; double month_price;
	//total 12 parameters
	// c->setAll(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

	home();// {}
	home(string homeID, string home_address, int noRoom, int noBathRoom, int maxCapacity, double sqft, string facility, string desc, string ownerID, double dayPrice, double weekPrice, double monthPrice);
	//aggreagation constructor

	home(client *c, string client_id, string  client_name, string  client_ic, string  client_contact, string  client_email, string  client_address, string client_bank_account, string  client_bank, double client_credit, string client_pwd, string homeID, string home_address, int noRoom, int noBathRoom, int maxCapacity, double sqft, string facility, string desc, string ownerID, double dayPrice, double weekPrice, double monthPrice);

	~home();// {}


	string getHomeID();// { return this->home_id; }
	string getHomeAddress();// { return this->home_address; }
	int getNoRoom();// { return this->no_room; }
	int getNoBathRoom();// { return this->no_bath_room; }
	int getMaxCapacity();// { return this->max_capacity; }
	double getSizeSqFt();// { return this->sq_ft; }
	string getComment();
	string getCommentID();


	void setCommentID(string cmtID);

	void setComment(string cmt);
	void setHomeID(string homeID);// { this->home_id = homeID; }
	void setHomeAddress(string home_address);// { this->home_address = home_address; }
	void setNoRoom(int noRoom);// { this->no_room = noRoom; }
	void setNoBathRoom(int noBathRoom);// { this->no_bath_room = noBathRoom; }
	void setMaxCapacity(int maxCapacity);// { this->max_capacity = maxCapacity; }
	void setSize(double sqft);// { this->sq_ft = sqft; }
	void setHome(string homeID, string home_address, int noRoom, int noBathRoom, int maxCapacity, double sqft, string facility, string desc, string ownerID, double dayPrice, double weekPrice, double monthPrice);

	void displaySpecificRoom(string id);
	virtual  void displayDetail();// {}

	void displayComment();


	static void delete_home_compositionBooking(string arr[], home &selectedHome);//composition implementation






};

#endif