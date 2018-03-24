#ifndef STAFF_H
#define STAFF_H
#pragma once

#include "targetver.h"
#include "stdafx.h"
#include "user.h"

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



//class staff
class staff :public user{

private:
	string staff_id ;
	string staff_pwd;
	string staff_name;
public:

	 string sessionID;
	 string sessionNAME;

	staff();//{}
	staff(string staffID, string staffPWD, string staffNAME);/* {
		this->staff_id = staffID;
		this->staff_pwd = staffPWD;
		this->staff_name = staffNAME;
	}*/
	~staff();// {}

	//get set
	string getStaffID();// { return this->staff_id; }
	string getStaffPWD();// { return this->staff_pwd; }
	string getStaffNAME();// { return this->staff_name; }

	void setStaffID(string staffID);// { this->staff_id = staffID; }
	void setStaffPWD(string staffPWD);// { this->staff_pwd = staffPWD; }
	void setStaffNAME(string staffNAME);// { this->staff_name = staffNAME; }

	virtual void manage_profile(string id, string name);


	//staff profile function
	static void update_profile(string id, string name);
static void change_password(string id, string name);

static void view_staff_profile(string id, string name);

	//staff menu
static void manage_staff();
virtual string staff::RandomString(int len);

template<class numberOfRooms>
static int get_Num_Rooms(numberOfRooms* no, string typeOfRoom);

	template<class TTT>
	static string get_TStaffID(TTT* id){
		string staff_id;
		string staff_pwd;
		string staff_name;
		string fileName;

		bool isExist = false;
		//*****
		string x;
		string y = "";
		bool loop = true;
		while (loop){



			std::cout << "Enter the Staff Id ,any alphaneumeric format eg. zyhzx123e, jordan789, etc." << endl;
			std::string sgetStaffId;
			cin >> *id;

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  ID." << endl;

				std::cout << "Enter the Staff Id again--(Last chance to enter)" << endl;

				cin >> *id;

				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "\nINVALID  ID." << endl;
				}

			}

			std::stringstream getIDStream;
			getIDStream << *id;


			string passedID = getIDStream.str();
			ifstream chkID("dbstaff/db_staff.txt");

			while (chkID >> staff_id >> staff_pwd >> staff_name){

				stringstream streamChkID;
				streamChkID << staff_id;
				string foundID = streamChkID.str();

				stringstream skid;
				skid << *id;
				// string passedID=skid.str();
				if (foundID == passedID){
					isExist = true;
					break;
				}
				else{
					isExist = false;
				}
			}

			if (isExist){
				cout << "The Id is already existed! pls change another one ..";
				loop = true;

			}
			else if (!isExist){
				if (getIDStream >> x){
					loop = false;
					break;

				}

				loop = false;


			}


		}
		return x;
	}


	static void add_staff();
	static void search_staff();
	static void edit_staff();
	static void displayAll();
	static void delete_staff();
	//manage staff



static void manage_client();
static void add_client();
static void search_client();
static void edit_client();
static void displayAllClient();
static void delete_client();


//manage customer functions
static void manage_customer();// {}
static void add_customer();
static void search_customer();
static void edit_customer();
static void displayAllCustomer();
static void delete_customer();

//manage home functions
static void new_home();
static void edit_home();
static void list_home();
static void delete_home();
static void new_home_new_client();

static void new_home_existing_client();
static void new_homw_newOwner();

//manage booking functions

static void new_booking();

static void edit_booking();

static void list_booking();

static void delete_booking();





static string space_underscore(string text);

static void manage_home();// {}
static void manage_booking();// {}
static void update_facility();

static void staff_main(string staff_id, string staff_name);

};

#endif