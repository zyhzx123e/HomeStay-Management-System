

#pragma once

#include "stdafx.h"
#include "user.h"
#include "staff.h"
#include "client.h"
#include "customer.h"
#include "home.h"
#include "booking.h"


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




staff sta;

staff::staff(){}
staff::staff(string staffID, string staffPWD, string staffNAME){
	staff::staff_id = staffID;
	staff::staff_pwd = staffPWD;
	staff::staff_name = staffNAME;
														 }


staff::~staff(){}

//get set
string staff::getStaffID(){ return staff_id; }
string staff::getStaffPWD() { return staff_pwd; }
string staff::getStaffNAME() { return staff_name; }

void staff::setStaffID(string staffID){ staff_id = staffID; }
void staff::setStaffPWD(string staffPWD){ staff_pwd = staffPWD; }
void staff::setStaffNAME(string staffNAME){ staff_name = staffNAME; }





void staff::manage_profile(string id, string name){
											//get the staff id automatically and identify the staff
											app a;

											system("cls");
											cout << "-----------Welcome (" + sta.sessionID + ")staff: " + name + "-----------" << endl;
											cout << "-----------You can edit your profile Info here----------" << endl;
											system("color 0a");
											cout << "Please enter your choice" << endl;
											cout << "1.Update Your Profile(***Note: You can not change your ID)" << endl;
											cout << "2.Change my Password" << endl;
											cout << "3.View my Profile Info" << endl;
											cout << "4.<<Back" << endl;

											int choice;
											cin >> choice;

											switch (choice){
											case 1:
											update_profile(id, name);
											break;
											case 2:
											change_password(id, name);
											break;
											case 3:
											view_staff_profile(id, name);
											break;
											case 4:
											//app a;
											//a.main();
											staff_main(id, name);
											break;

											default:
											cout << "Pls choose beween interger 1 ~ 4 only" << endl;
											}



											}




											//staff profile function
	 void staff::update_profile(string id, string name){

											system("cls");
											cout << "hi dear staff (" + sta.sessionID + ") " + name + ", you will change your profile soon";
											string staff_name;
											string staff_pwd;

											string newstaff_name;
											string newstaff_pwd;

											string decision;
											string staff_id;


											stringstream ss;//stringstream ss;
											ss << id;
											string staffIdS = ss.str();
											string staffId2 = ss.str();
											// string *add_empId2=&empId2;

											staffId2.append(".txt");
											string staffId2File = "dbstaff/" + staffId2;
											std::ifstream staff(staffId2File.c_str());




											bool chk = false;
											ifstream validate("dbstaff/db_staff.txt");
											while (validate >> staff_id >> staff_pwd >> staff_name){
											stringstream chks;
											chks << staff_id;
											string sthrw = chks.str();
											if (id == sthrw){
											cout << "Your Id has found!" << endl;
											chk = true;
											}

											}
											if (!chk){
											cout << "Your Id is not exist!" << endl;

											}
											validate.close();
											//(empId2);
											while (staff >> staff_id >> staff_pwd >> staff_name)  {

											cout << "Is this the Your Profile Info?[y/n]" << endl;
											cout << "Staff ID" << '  ' << "Staff PWD" << '  ' << "Staff Name" << endl;
											cout << staff_id << ' ' << staff_pwd << ' ' << staff_name << endl;
											cin >> decision;
											if (decision == "y"){
											system("cls");
											cout << "Current information:" << endl;

											int id_length = staff_id.size();
											int pwd_length = staff_pwd.size();
											int name_length = staff_name.size();
											int lengthTotal = id_length + pwd_length + name_length;


											cout << "Staff_ID";
											for (int y = 0; y < id_length + 7; y++){
											cout << " ";
											}
											cout << "Staff_PWD";
											for (int z = 0; z < (pwd_length + 8); z++){
											cout << " ";
											}
											cout << "Staff_Name";
											for (int x = 0; x < (lengthTotal + 16); x++){
											cout << ">";
											}
											cout << ' ' << endl;

											cout << staff_id;
											for (int y = 0; y < id_length + 7; y++){
											cout << " ";
											}
											cout << staff_pwd;
											for (int z = 0; z < (pwd_length + 8); z++){
											cout << " ";
											}
											cout << staff_name << endl;

											//print out original data



											cout << "Enter your new staff name:";
											cin >> newstaff_name;
											cout << "Enter your new staff password:";
											cin >> newstaff_pwd;

											}
											if (decision == "n"){
											staff::staff_main(id, name);
											}

											//***********


											//ofstream pofolio(empId2.c_str());
											ofstream tempPofolio("dbstaff/tempPofolio.txt");

											ofstream temp("dbstaff/temp.txt");
											ifstream staffD("dbstaff/db_staff.txt");
											if (tempPofolio.is_open() && staffD.is_open() && temp.is_open()){

											string line;
											while (getline(staffD, line))
											{
											if (line.find(id) == string::npos) { //str.find(str2) != string::npos
											temp << line << endl;

											}
											else
											{

											tempPofolio << id << ' ' << newstaff_pwd << ' ' << newstaff_name << endl;
											temp << id << ' ' << newstaff_pwd << ' ' << newstaff_name << endl;
											}
											}

											}
											tempPofolio.close();
											staff.close();
											staffD.close();

											temp.close();


											string db_old_file = "dbstaff/db_staff.txt";
											system("del dbstaff/db_staff.txt");
											const char *data = "dbstaff/db_staff.txt";
											remove(data);//delete the old db file f


											//system("del dbstaff/db_staff.txt");
											remove(staffId2File.c_str());//then remove the individual staff portfolio

											rename("dbstaff/tempPofolio.txt", staffId2File.c_str());//get the new portfolio back
											rename("dbstaff/temp.txt", "dbstaff/db_staff.txt");
											//******

											//*******************take not!!!!!!!!!!!!!!

											cout << "Hi Staff " + sta.sessionNAME + ", Your Profile has been updated! it would be taken-affect upon your next login" << endl;


											}
											staff::staff_main(id, name);

											}
											


void staff::change_password(string id, string name) {


											 system("cls");
											 cout << "hi dear staff " + name + ", you will change your Password now";
											 string staff_name;
											 string staff_pwd;

											 string newstaff_name;
											 string newstaff_pwd;

											 string decision;
											 string staff_id;


											 stringstream ss;//stringstream ss;
											 ss << id;
											 string staffIdS = ss.str();
											 string staffId2 = ss.str();
											 // string *add_empId2=&empId2;

											 staffId2.append(".txt");
											 string staffId2File = "dbstaff/" + staffId2;
											 std::ifstream staff(staffId2File.c_str());




											 bool chk = false;
											 ifstream validate("dbstaff/db_staff.txt");
											 while (validate >> staff_id >> staff_pwd >> staff_name){
											 stringstream chks;
											 chks << staff_id;
											 string sthrw = chks.str();
											 if (id == sthrw){
											 cout << "Your Account has found!" << endl;
											 chk = true;
											 }

											 }
											 if (!chk){
											 cout << "Your Account is not exist!" << endl;

											 }
											 validate.close();
											 //(empId2);
											 while (staff >> staff_id >> staff_pwd >> staff_name)  {

											 cout << "Is this the Your Password ?[y/n]" << endl;
											 cout << "Staff PWD" << endl;
											 cout << staff_pwd << endl;
											 cin >> decision;
											 if (decision == "y"){
											 system("cls");
											 cout << "Current information:" << endl;

											 int id_length = staff_id.size();
											 int pwd_length = staff_pwd.size();
											 int name_length = staff_name.size();
											 int lengthTotal = id_length + pwd_length + name_length;


											 cout << "Staff_ID";
											 for (int y = 0; y < id_length + 7; y++){
											 cout << " ";
											 }
											 cout << "Staff_PWD";
											 for (int z = 0; z < (pwd_length + 8); z++){
											 cout << " ";
											 }
											 cout << "Staff_Name";
											 for (int x = 0; x < (lengthTotal + 16); x++){
											 cout << ">";
											 }
											 cout << ' ' << endl;

											 cout << staff_id;
											 for (int y = 0; y < id_length + 7; y++){
											 cout << " ";
											 }
											 cout << staff_pwd;
											 for (int z = 0; z < (pwd_length + 8); z++){
											 cout << " ";
											 }
											 cout << staff_name << endl;

											 //print out original data


											 cout << "Enter your new staff password:";
											 cin >> newstaff_pwd;

											 }
											 if (decision == "n"){
											 staff_main(id, name);
											 }

											 //***********


											 //ofstream pofolio(empId2.c_str());
											 ofstream tempPofolio("dbstaff/tempPofolio.txt");

											 ofstream temp("dbstaff/temp.txt");
											 ifstream staffD("dbstaff/db_staff.txt");
											 if (tempPofolio.is_open() && staffD.is_open() && temp.is_open()){

											 string line;
											 while (getline(staffD, line))
											 {
											 if (line.find(id) == string::npos) { //str.find(str2) != string::npos
											 temp << line << endl;

											 }
											 else
											 {
											 //here only change the password
											 tempPofolio << id << ' ' << newstaff_pwd << ' ' << staff_name << endl;
											 temp << id << ' ' << newstaff_pwd << ' ' << staff_name << endl;
											 }
											 }

											 }
											 tempPofolio.close();
											 staff.close();
											 staffD.close();

											 temp.close();


											 string db_old_file = "dbstaff/db_staff.txt";
											 //system("del dbstaff/db_staff.txt");
											 const char *data = "dbstaff/db_staff.txt";
											 remove(db_old_file.c_str());//delete the old db file first
											 //system("del dbstaff/db_staff.txt");
											 remove(staffId2File.c_str());//then remove the individual staff portfolio

											 rename("dbstaff/tempPofolio.txt", staffId2File.c_str());//get the new portfolio back
											 rename("dbstaff/temp.txt", "dbstaff/db_staff.txt");
											 //******
											 cout << "Hi Staff " + sta.sessionNAME + ", Your password has been updated! it would be taken-affect upon your next login" << endl;
											 //*******************take not!!!!!!!!!!!!!!


											 staff_main(id, name);
											 }



											 }



void staff::view_staff_profile(string id, string name) {


												system("cls");
												cout << "hi dear staff (" + sta.sessionID + ") " + name + ", This is your personal profile, you can change it later";
												string staff_name;
												string staff_pwd;

												string newstaff_name;
												string newstaff_pwd;

												string decision="y";
												string staff_id;


												stringstream ss;//stringstream ss;
												ss << id;
												string staffIdS = ss.str();
												string staffId2 = ss.str();
												// string *add_empId2=&empId2;

												staffId2.append(".txt");
												string staffId2File = "dbstaff/" + staffId2;
												std::ifstream staff(staffId2File.c_str());




												bool chk = false;
												ifstream validate("dbstaff/db_staff.txt");
												while (validate >> staff_id >> staff_pwd >> staff_name){
												stringstream chks;
												chks << staff_id;
												string sthrw = chks.str();
												if (id == sthrw){
													cout << endl;
												cout << "Your Account has found!" << endl;
												chk = true;
												}

												}
												if (!chk){
													cout << endl;
												cout << "Your Account is not exist!" << endl;

												}
												validate.close();
												//(empId2);
												while (staff >> staff_id >> staff_pwd >> staff_name) {
													cout << endl;
													cout << "Staff ID   : " + staff_id + "" << endl;
													cout << "Staff PWD  : " + staff_pwd + "" << endl;
													cout << "Staff Name : " + staff_name + "" << endl;
													cout << endl;
												
										

												//***********

												}staff.close();
												cin >> decision;
												if (decision == "y"){
													system("cls");
													cout << "Current information:" << endl;

													int id_length = staff_id.size();
													int pwd_length = staff_pwd.size();
													int name_length = staff_name.size();
													int lengthTotal = id_length + pwd_length + name_length;


													cout << "Your Staff_ID";
													for (int y = 0; y < id_length + 7; y++){
														cout << " ";
													}
													cout << "Your Staff_PWD";
													for (int z = 0; z < (pwd_length + 7); z++){
														cout << " ";
													}
													cout << "Your Name";
													for (int x = 0; x < (lengthTotal + 7); x++){
														cout << ">";
													}
													cout << endl;
													cout << "====================================================================" << endl;
													cout << ' ' << endl;

													cout << staff_id;
													for (int y = 0; y < id_length + 19; y++){
														cout << " ";
													}
													cout << staff_pwd;
													for (int z = 0; z < (pwd_length + 14); z++){
														cout << " ";
													}
													
													cout << staff_name;
														cout << endl;
													//print out original data




												}
												
												if (decision == "n"){
												staff_main(id, name);
												}
												

													system("pause");
													staff_main(id, name);
												

												}
												


//staff menu
void staff::manage_staff() {

					system("cls");
					cout << "-----------HMS Staff Management Panel-----------" << endl;
					cout << "---------------------------------------------" << endl;
					system("color 0f");
					cout << "Please enter your choice" << endl;
					cout << "1.Add new Staff" << endl;
					cout << "2.Search for a staff by ID number" << endl;
					cout << "3.Edit an existing staff's information" << endl;
					cout << "4.Display all staff" << endl;
					cout << "5.Delete staff" << endl;
					cout << "6.<<back" << endl;

					int choice;
					cin >> choice;

					switch (choice){
					case 1:
					add_staff();
					break;
					case 2:
					search_staff();
					break;
					case 3:
					edit_staff();
					break;
					case 4:
					displayAll();
					break;
					case 5:
					delete_staff();
					break;
					case 6:
					staff_main(sta.sessionID, sta.sessionNAME);
					break;
					default:
					cout << "The choice currently only valide in 1~5" << endl;
					}


					}
					
template<class TTT>
string get_TStaffID(TTT* id){
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


template<class numberOfRooms>
static int staff::get_Num_Rooms(numberOfRooms* no,string typeOfRoom){


	//*****
	int x;
	//
	bool loop = true;
	while (loop){



		std::cout << "Enter the number of " + typeOfRoom + " that are available (only integers are allowed!)." << endl;
		//std::int sgetNum;
		cin >> *no;

		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  number." << endl;

			std::cout << "Enter the number of " + typeOfRoom + " again--(Last chance to enter)" << endl;

			cin >> *no;

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  number." << endl;
			}

		}

		std::stringstream getNumStream;
		getNumStream << *no;


		if (getNumStream >> x){
			loop = false;
			break;

		}

		loop = false;
}
		return x;
	
}
 string staff::RandomString(int len){
	 srand(time(0));

	 string str = "staff0123456789abcdefghijklmnopqrstuvwxyz";
	 int pos;
	 while (str.size() != len) {
		 pos = ((rand() % (str.size() - 1)));
		 str.erase(pos, 1);
	 }
	 return str;
 }

template<class uniqueCusID>
string get_TCustomerID(uniqueCusID* id){
	string customer_id;
	string customer_name;
	string customer_ic;
	string customer_contact;
	string customer_email;
	string customer_address;
	string customer_bank_account;
	string customer_bank;
	double customer_credit;//default=0
	string customer_pwd;//default=password

	string fileName;

	bool isExist = false;
	//*****
	string x;
	string y = "";
	bool loop = true;
	while (loop){



		std::cout << "Enter the Customer Id ,any alphaneumeric format eg. zyhzx123e, jordan789, etc." << endl;
		std::string sgetStaffId;
		cin >> *id;

		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  ID." << endl;

			std::cout << "Enter the Customer Id again--(Last chance to enter)" << endl;

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
		ifstream chkID("dbcustomer/db_customer.txt");

		while (chkID >> customer_id >> customer_name >> customer_ic >> customer_contact >> customer_email >> customer_address>> customer_bank_account>> customer_bank >> customer_credit >> customer_pwd){

			stringstream streamChkID;
			streamChkID << customer_id;
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


void staff::add_staff(){
				 system("cls");
				 string staff_id;
				 string staff_pwd;
				 string staff_name;

				 string fileName;
				 
				 cin.ignore(1, '\n');

				 cout << "Input Staff ID:";
				 cout << get_TStaffID(&staff_id) << endl;

				 cout << "Input Staff Password:";
				// cin.get();
				 getline(cin, staff_pwd);
				// cin >> staff_pwd;
				 cout << "Input Staff Name:";
				 //cin.get();
				 getline(cin,staff_name);
				// cin >> staff_name;



				 stringstream ss;//stringstream ss;
				 ss << staff_id;
				 string staff_id2 = ss.str();
				 // string *add_empId2=&empId2;
				 staff_id2.append(".txt");
				 string newPortfolio = "dbstaff/" + staff_id2;

				 ofstream newStaff(newPortfolio.c_str());
				 newStaff << staff_id << ' ' << space_underscore(staff_pwd) << ' ' << space_underscore(staff_name) << endl;
				 newStaff.close();
				 ofstream dir("dbstaff/db_staff.txt", ios::app);
				 dir << staff_id << ' ' << space_underscore(staff_pwd) << ' ' << space_underscore(staff_name) << endl;

				 dir.close();
				 cout << "You have just added '" + staff_name + "' with ID: '" + staff_id + "'" << endl;

				 system("pause");
				 manage_staff();
				 }


void staff::search_staff()
					{
					system("cls");

					staff s;
				
					user *user_sta = new staff;

					cout << "Enter staff ID number:";
					cin >> user_sta->id;

					stringstream ss;//stringstream ss;
					ss << user_sta->getID();
					string staff_id2 = ss.str();
					string staff_idS = ss.str();

					staff_id2.append(".txt");

					string filePortfolio = "dbstaff/" + staff_id2;


					std::ifstream staffStream(filePortfolio.c_str());

					bool chk = false;
					ifstream validate("dbstaff/db_staff.txt");
					while (validate >> user_sta->id >> user_sta->pwd >> user_sta->name){
					stringstream chks;
					chks << user_sta->getID();
					string sthrw = chks.str();
					if (staff_idS == sthrw){
					cout << "The Staff Id has found!" << endl;
					chk = true;
					}

					}
					if (!chk){
					cout << "The Id is not exist!" << endl;

					}
					validate.close();

					string staff_id_r = "";
					string staff_pwd_r = "";
					string staff_name_r = "";
					while (staffStream >> user_sta->id >> user_sta->pwd >> user_sta->name){

						if (user_sta->getID().length() > staff_id_r.length()){ staff_id_r = user_sta->getID(); }
						if (user_sta->getID().length() > staff_id_r.length()){ staff_id_r = user_sta->getID(); }

						if (user_sta->getID().length() > staff_id_r.length()){ staff_id_r = user_sta->getID(); }



					string answer;
					cout << "Is this the correct staff?[y/n]" << endl;
					cout << user_sta->id << ' ' << user_sta->pwd << ' ' << user_sta->name << endl;
					cin >> answer;

					if (answer == "y"){
					system("cls");



					cout << "Staff ID";
					
					cout << " ";
					
					cout << "Staff PWD";
					
					cout << " ";
					
					cout << "Staff Name";
					for (int z = 0; z<(staff_name_r.length()); z++){
					cout << " " << endl;
					}
					for (int z = 0; z<(staff_id_r.length() + staff_pwd_r.length() + staff_name_r.length()); z++){
					cout << "-";
					}

					cout << ' ' << endl;

					cout << user_sta->id;
					for (int y = 0; y<(staff_id_r.length()); y++){
					cout << " ";
					}
					cout << user_sta->pwd;
					for (int z = 0; z<(staff_pwd_r.length()); z++){
					cout << " ";
					}
					cout << user_sta->name;


					//print out original data

					}

					}
					staffStream.close();
					system("pause");
					staff_main(sta.sessionID, sta.sessionNAME);
					}
					


void staff::edit_staff(){

				  system("cls");
				  string staff_id;
				  string staff_pwd;
				  string staff_name;


				  string new_staff_pwd;
				  string new_staff_name;


				  cout << "Enter the Staff-Id of the Staff whose data you wish to edit:";
				  cin >> staff_id;
				  stringstream ss;//stringstream ss;
				  ss << staff_id;
				  string staff_idS = ss.str();
				  string staff_id2 = ss.str();
				  // string *add_empId2=&empId2;

				  staff_id2.append(".txt");
				  string filePortfolio = "dbstaff/" + staff_id2;
				  std::ifstream staffPort(filePortfolio.c_str());



				  string staff_id_r = "";
				  string staff_pwd_r = "";
				  string staff_name_r = "";
				  bool chk = false;
				  ifstream validate("dbstaff/db_staff.txt");
				  while (validate >> staff_id >> staff_pwd >> staff_name){
				  if (staff_id.length() > staff_id_r.length()){ staff_id_r = staff_id; }
				  if (staff_pwd.length() > staff_pwd_r.length()){ staff_pwd_r = staff_pwd; }

				  if (staff_name.length() > staff_name_r.length()){ staff_name_r = staff_name; }

				  stringstream chks;
				  chks << staff_id;
				  string sthrw = chks.str();
				  if (staff_idS == sthrw){
				  cout << "The Id " + sthrw + " has found!" << endl;
				  chk = true;
				  }

				  }
				  if (!chk){
				  cout << "The Id is not exist!" << endl;

				  }
				  validate.close();
				  string decision;

				  while (staffPort >> staff_id >> staff_pwd >> staff_name)  {


				  cout << "Is this the staff that you wish to edit?[y/n]" << endl;
				  cout << staff_id << ' ' << staff_pwd << ' ' << staff_name << endl;
				  cin >> decision;
				  if (decision == "y"){
				  system("cls");
				  cout << "Current information:" << endl;


				  cout << "Staff_Id";
				  for (int y = 0; y<staff_id_r.length(); y++){
				  cout << " ";
				  }
				  cout << "Staff PWD";
				  for (int z = 0; z<(staff_pwd_r.length()); z++){
				  cout << " ";
				  }
				  cout << "Staff Name";
				  for (int z = 0; z<(staff_name_r.length()); z++){
				  cout << " ";
				  }

				  for (int x = 0; x<(staff_id_r.length() + staff_pwd_r.length() + staff_name_r.length()); x++){
				  cout << "-";
				  }
				  cout << ' ' << endl;

				  cout << staff_id;
				  for (int y = 0; y<staff_id_r.length(); y++){
				  cout << " ";
				  }

				  cout << staff_pwd;
				  for (int z = 0; z<(staff_pwd_r.length()); z++){
				  cout << " ";
				  }
				  cout << staff_name << endl;

				  //print out original data



				  cout << "Enter new staff password:" << endl;
				  cin.get();
				  getline(cin, new_staff_pwd);
				 // cin >> new_staff_pwd;
				  cout << "Enter new staff name:" << endl;
				  cin.get();
				  getline(cin, new_staff_name);
				 // cin >> new_staff_name;


				  }
				  if (decision == "n"){
				  manage_staff();
				  }

				  //ofstream pofolio(empId2.c_str());
				  ofstream tempPofolio("dbstaff/tempPofolio.txt");

				  ofstream temp("dbstaff/temp.txt");
				  ifstream staffD("dbstaff/db_staff.txt");
				  if (tempPofolio.is_open() && staffD.is_open() && temp.is_open()){

				  string line;
				  while (getline(staffD, line))
				  {
				  if (line.find(staff_idS) == string::npos) { //str.find(str2) != string::npos
				  temp << line << endl;

				  }
				  else
				  {

					  tempPofolio << staff_id << ' ' << space_underscore(new_staff_pwd) << ' ' << space_underscore(new_staff_name) << endl;
					  temp << staff_id << ' ' << space_underscore(new_staff_pwd) << ' ' << space_underscore(new_staff_name) << endl;
				  }
				  }

				  }
				  tempPofolio.close();
				  staffPort.close();
				  staffD.close();

				  temp.close();


				  string db_old_file = "dbstaff/db_staff.txt";
				  //system("del dbstaff/db_staff.txt");
				  const char *data = "dbstaff/db_staff.txt";
				  remove(db_old_file.c_str());//delete the old db file first


				  //system("del dbstaff/db_staff.txt");
				  remove(filePortfolio.c_str());

				  rename("dbstaff/tempPofolio.txt", filePortfolio.c_str());
				  rename("dbstaff/temp.txt", "dbstaff/db_staff.txt");
				  //******


				  }

				  manage_staff();

				  }


void staff::displayAll(){


				  system("cls");
				  string staff_id;
				  string staff_pwd;
				  string staff_name;


				  cout << "Entire Staff database" << endl;
				  cout << "------------------------" << endl;
				  ifstream dir("dbstaff/db_staff.txt");



				  // std::string Names[number_of_lines];
				  std::string staff_idResult = "";  //
				  std::string staff_pwdResult = "";
				  std::string staff_nameResult = "";



				  while (dir >> staff_id >> staff_pwd >> staff_name){

				  if (staff_id.length()>staff_idResult.length()){
				  staff_idResult = staff_id;
				  }
				  if (staff_pwd.length()>staff_pwdResult.length()){
				  staff_pwdResult = staff_pwd;
				  }
				  if (staff_name.length()>staff_nameResult.length()){
				  staff_nameResult = staff_name;
				  }


				  }


				  cout << "Staff ID";
				  for (int y = 0; y<staff_idResult.length(); y++){
				  cout << " ";
				  }
				  cout << "Staff PWD";
				  for (int z = 0; z<(staff_pwdResult.length()); z++){
				  cout << " ";
				  }
				  cout << "Staff Name" << endl;

				  for (int x = 0; x<(8 + staff_idResult.length() + staff_pwdResult.length() + staff_nameResult.length()); x++){
				  cout << "-";
				  }
				  cout << ' ' << endl;







				  ifstream dir1("dbstaff/db_staff.txt");
				  while (dir1 >> staff_id >> staff_pwd >> staff_name){

				  cout << staff_id;
				  for (int y = 0; y<staff_idResult.length() + 5; y++){
				  cout << " ";
				  }
				  cout << staff_pwd;
				  for (int z = 0; z<(staff_pwdResult.length() + 5); z++){
				  cout << " ";
				  }
				  cout << staff_name << endl;






				  //print out original data
				  }
				  dir.close();
				  dir1.close();
				  system("pause");
				  manage_staff();

				  }
				  


void staff::delete_staff() {
					system("cls"); system("cls");
					//system("pause");
					string staff_id;
					string staff_pwd;
					string staff_name;
					string decision;
					user *u = new staff;


					cout << "Enter staff ID :";
					cin >> u->id;
					stringstream ss;//stringstream ss;
					ss << u->getID();
					string staff_idS = ss.str();
					string staff_id2 = ss.str();
					// string *add_empId2=&empId2;
					staff_id2.append(".txt");

					string portfolioFile = "dbstaff/" + staff_id2;

					bool chk = false;
					ifstream validate("dbstaff/db_staff.txt");
					while (validate >> staff_id >> staff_pwd >> staff_name){
					stringstream chks;
					chks << staff_id;
					string sthrw = chks.str();
					if (staff_idS == sthrw){
					cout << "The Id has found!" << endl;
					chk = true;
					}

					}
					if (!chk){
					cout << "The Id is not exist!" << endl;

					}
					validate.close();


					ifstream dir(portfolioFile.c_str());
					//(empId2);



					std::string staff_idResult = "";  //
					std::string staff_pwdResult = "";
					std::string staff_nameResult = "";



					while (dir >> staff_id >> staff_pwd >> staff_name){

					if (staff_id.length()>staff_idResult.length()){
					staff_idResult = staff_id;
					}
					if (staff_pwd.length()>staff_pwdResult.length()){
					staff_pwdResult = staff_pwd;
					}
					if (staff_name.length()>staff_nameResult.length()){
					staff_nameResult = staff_name;
					}




					string answer;
					cout << "Is this the correct staff?[y/n]" << endl;
					cout << staff_id << ' ' << staff_pwd << ' ' << staff_name << endl;
					cin >> answer;

					if (answer == "y"){
					system("cls");

					cout << "Staff ID";
					for (int y = 0; y<staff_idResult.length(); y++){
					cout << " ";
					}
					cout << "Staff PWD";
					for (int z = 0; z<(staff_pwdResult.length()); z++){
					cout << " ";
					}
					cout << "Staff Name";

					for (int x = 0; x<(staff_idResult.length() + staff_pwdResult.length() + staff_nameResult.length()); x++){
					cout << "-";
					}
					cout << ' ' << endl;
					cout << staff_id;
					for (int y = 0; y<staff_idResult.length() - staff_id.length(); y++){
					cout << " ";
					}
					cout << staff_pwd;
					for (int z = 0; z<(staff_pwdResult.length() - staff_pwd.length()); z++){
					cout << " ";
					}
					cout << staff_name;


					//print out original data	}

					cout << "Do you wish to delete this employee from the database?" << endl;
					cin >> decision;
					}
					dir.close();

					if (decision == "y"){



					ofstream temp("dbstaff/temp.txt");
					ifstream staffD("dbstaff/db_staff.txt");
					if (staffD.is_open() && temp.is_open()){

					string line;
					while (getline(staffD, line))
					{
					if (line.find(staff_idS) == string::npos) { //str.find(str2) != string::npos =-1  means not found

					temp << line << endl;//copy&write to temp

					}
					else if (line.find(staff_id) != string::npos)
					{


					}
					}

					}


					staffD.close();


					temp.close();


					string db_old_file = "dbstaff/db_staff.txt";
					//system("del dbstaff/db_staff.txt");
					const char *data = "dbstaff/db_staff.txt";
					remove(db_old_file.c_str());//delete the old db file first
					//system("del dbstaff/db_staff");
					remove(portfolioFile.c_str());
					rename("dbstaff/temp.txt", "dbstaff/db_staff.txt");


					}


					system("pause");
					manage_staff();
					}

					}

//manage staff





void staff::manage_client() {

					 system("cls");
					 cout << "-----------HMS Client Management Panel-----------" << endl;
					 cout << "---------------------------------------------" << endl;
					 system("color 0f");
					 cout << "Please enter your choice" << endl;
					 cout << "1.Add new Client" << endl;
					 cout << "2.Search for a Client by ID number" << endl;
					 cout << "3.Edit an existing client's information" << endl;
					 cout << "4.Display all Clients" << endl;
					 cout << "5.Delete Client" << endl;
					 cout << "6.<<back" << endl;

					 int choice;
					 cin >> choice;

					 switch (choice){
					 case 1:
					 add_client();
					 break;
					 case 2:
					 search_client();
					 break;
					 case 3:
					 edit_client();
					 break;
					 case 4:
					 displayAllClient();
					 break;
					 case 5:
					 delete_client();
					 break;
					 case 6:
					 staff_main(sta.sessionID, sta.sessionNAME);
					 break;
					 default:
					 cout << "The choice currently only valite in 1~6" << endl;
					 }



					 }





void staff::add_client(){
				  system("cls");
				  client *c=new client();
				  string client_id;
				  string client_name;
				  string client_ic;
				  string client_contact;
				  string client_email;
				  string client_address;
				  string client_bank_account;
				  string client_bank;
				  double client_credit;//default=0
				  string client_pwd;//default=password
				  //!!!!!!!!!!!!!pending, add locatio nad sdtomer_od
				  string choiceCREDIT;
				  string choicePWD;
				  string fileName;


				  cout << "Input Client ID:";
				  cin >> client_id;
				  cout << "Input Client Name:";

				  cin.get();
				  getline(cin, client_name);
				 // cin >> client_name;
				  cout << "Input Client IC:";
				  cin.get();
				  getline(cin, client_ic);
				//  cin >> client_ic;
				  cout << "Input Client Contact:";
				  cin.get();
				  getline(cin, client_contact);
				 // cin >> client_contact;
				  cout << "Input Client Email:";
				  cin.get();
				  getline(cin, client_email);
				 // cin >> client_email;
				  cout << "Input Client Address:";
				  cin.get();
				  getline(cin,client_address);
				  
				  cout << "Input Client Bank:";
				  cin.get();
				  getline(cin, client_bank);
				  cout << "Input " + client_bank + "-Bank Account Number:";
				  cin.get();
				  getline(cin, client_bank_account);
				  //cin >> client_bank_account;
				  cout << "Want Give This Client credits? [Y/N]";
				  cout << endl;
				  cin >> choiceCREDIT;
				  if (choiceCREDIT == "Y" || choiceCREDIT == "y"){
				  cout << "Now give amount of credits to this Client(RM)";

				  cin >> client_credit;
				  }
				  else {
				  cout << "The default 0 Credit would give to this client."; cout << endl;
				  client_credit = 0;
				  }


				  cout << "Want specify a password for this Client? [Y/N]"; cout << endl;
				  cin >> choicePWD;
				  if (choicePWD == "Y" || choicePWD == "y"){
				  cout << "Now enter the password of this Client...";
				  cin >> client_pwd;
				  }
				  else {
				  cout << "The default 'password' would be set as password for this client, later on the client may change it by themselves"; cout << endl;
				  client_pwd = "password";
				  }


				  if ((choicePWD == "Y" || choicePWD == "y") && (choiceCREDIT == "Y" || choiceCREDIT == "y")){
					  c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

				  }
				  else if ((choicePWD == "Y" || choicePWD == "y") && (choiceCREDIT != "Y" || choiceCREDIT != "y")){
				  client_credit = 0;
				  c->setAttributes(client_id,client_name,client_ic,client_contact,client_email,client_address,client_bank_account,client_bank,client_credit,client_pwd);
				  }
				  else if ((choicePWD != "Y" || choicePWD != "y") && (choiceCREDIT == "Y" || choiceCREDIT == "y")){
				  client_pwd = "password";
				  c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

				  }
				  else {//if (choicePWD != "Y" && choiceCREDIT != "Y"){
				  client_credit = 0;
				  client_pwd = "password";
				  c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

				  }



				  stringstream ss;//stringstream ss;
				  ss << client_id;
				  string client_id2 = ss.str();
				  // string *add_empId2=&empId2;
				  client_id2.append(".txt");
				  string newPortfolio = "dbclient/" + client_id2;

				  ofstream newClient(newPortfolio.c_str());
				  newClient << space_underscore(c->getClientID()) << ' ' << space_underscore(c->getClientNAME()) << ' ' << space_underscore(c->getClientPASSPORT()) << ' ' << space_underscore(c->getClientCONTACT()) << ' ' << space_underscore(c->getClientEMAIL()) << ' ' << space_underscore(c->getClientADDRESS()) << ' ' << space_underscore(c->getClientBANKACCT()) << ' ' << space_underscore(c->getClientBANK()) << ' ' << space_underscore(toString( c->getClientCREDIT())) << ' ' << space_underscore(c->getClientPWD()) << endl;
				  newClient.close();
				  ofstream dir("dbclient/db_client.txt", ios::app);
				  dir << space_underscore(c->getClientID()) << ' ' << space_underscore(c->getClientNAME()) << ' ' << space_underscore(c->getClientPASSPORT()) << ' ' << space_underscore(c->getClientCONTACT()) << ' ' << space_underscore(c->getClientEMAIL()) << ' ' << space_underscore(c->getClientADDRESS()) << ' ' << space_underscore(c->getClientBANKACCT()) << ' ' << space_underscore(c->getClientBANK()) << ' ' << space_underscore(toString(c->getClientCREDIT())) << ' ' << space_underscore(c->getClientPWD()) << endl; dir.close();
				  cout << "You have just added '" + c->getClientNAME() + "' with ID: '" + c->getClientID() + "'" << endl;

				  dir.close();
				  system("pause");
				  staff::manage_client();
				  }
				  


void staff::search_client()
					 {
					 system("cls");
					 system("color 0a");

					
					 string client_id;
					 string client_name;
					 string client_ic;
					 string client_contact;
					 string client_email;
					 string client_address;
					 string client_bank_account;
					 string client_bank;
					 double client_credit;//default=0
					 string client_pwd;//default=password

					 user *cli = new client;

					 cout << "Enter Client ID number:";
					 cin >> cli->id;//friend access

					 stringstream ss;//stringstream ss;
					 ss << cli->getID();
					 string client_id2 = ss.str();
					 string client_idS = ss.str();

					 client_id2.append(".txt");

					 string filePortfolio = "dbclient/" + client_id2;


					 std::ifstream clientStream(filePortfolio.c_str());

					 string client_id_r = "";
					 string client_name_r = "";
					 string client_ic_r = "";
					 string client_contact_r = "";
					 string client_email_r = "";
					 string client_address_r = "";
					 string client_bank_account_r = "";
					 string client_bank_r = "";
					 string client_credit_r = "";
					 string client_pwd_r = "";
					 bool chk = false;
					 ifstream validate("dbclient/db_client.txt");
					 while (validate >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){
					 if (client_id.length() > client_id_r.length()){ client_id_r = client_id; }
					 if (client_name.length() > client_name_r.length()){ client_name_r = client_name; }

					 if (client_ic.length() > client_ic_r.length()){ client_ic_r = client_ic; }
					 if (client_contact.length() > client_contact_r.length()){ client_contact_r = client_contact; }
					 if (client_email.length() > client_email_r.length()){ client_email_r = client_email; }
					 if (client_address.length() > client_address_r.length()){ client_address_r = client_address; }
					 if (client_bank_account.length() > client_bank_account_r.length()){ client_bank_account_r = client_bank_account; }
					 if (client_bank.length() > client_bank_r.length()){ client_bank_r = client_bank; }
					 //if (client_credit.length() > client_credit_r.length()){ client_credit_r = client_credit; }
					 if (client_pwd.length() > client_pwd_r.length()){ client_pwd_r = client_pwd; }


					 //c =  client(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);
					 stringstream chks;
					 chks << client_id;
					 string sthrw = chks.str();
					 if (client_idS == sthrw){
					 cout << "The Client Id has found!" << endl;
					 chk = true;
					 }

					 }
					 if (!chk){
					 cout << "The Id is not exist!" << endl;

					 }
					 validate.close();



					 while (clientStream >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){


					 cout << client_id << "  " << client_name << "  " << client_ic << "  " << client_contact << "  " << client_email << "  " << client_address << "  " << client_bank_account << "  " << client_bank << "  " << client_credit << "  " << client_pwd << endl;
					 string answer;
					 cout << "Is this the correct client?[y/n] " << endl;

					 cin >> answer;

					 if (answer == "y"){
					 system("cls");


					 cout << "Client ID";
					 for (int y = 0; y<(client_id_r.length() + 5); y++){
					 cout << " ";
					 }
					 cout << "Client Name";
					 for (int z = 0; z<(client_name_r.length() + 8); z++){
					 cout << " ";
					 }
					 cout << "Client IC/Passport";
					 for (int z = 0; z<(client_ic_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Contact";
					 for (int z = 0; z<(client_contact_r.length() + 5); z++){
					 cout << " ";
					 }
					 cout << "Client Email";
					 for (int z = 0; z<(client_email_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Address";
					 for (int z = 0; z<(client_address_r.length() + 4); z++){
					 cout << " ";
					 }
					 cout << "Client Bank Account";
					 for (int z = 0; z<(client_bank_account_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Bank ";
					 for (int z = 0; z<(client_bank_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Credit ";
					 for (int z = 0; z<(client_credit_r.length() + 4); z++){
					 cout << " ";
					 }
					 cout << "Client Password ";
					 for (int z = 0; z<(client_pwd_r.length()); z++){
					 cout << " ";
					 }
					 cout << endl;

					 for (int z = 0; z<250; z++){
					 cout << "-";
					 }

					 cout << ' ' << endl;

					 cout << client_id;
					 for (int y = 0; y<((client_id_r.length() - client_id.length()) + +16); y++){
					 cout << " ";
					 }
					 cout << client_name;
					 for (int z = 0; z<(client_name_r.length() - client_name.length() + 20); z++){
					 cout << " ";
					 }
					 cout << client_ic;
					 for (int z = 0; z<(client_ic_r.length() - client_ic.length() + 16); z++){
					 cout << " ";
					 }
					 cout << client_contact;
					 for (int z = 0; z<(client_contact_r.length() + 8); z++){
					 cout << " ";
					 }
					 cout << client_email;
					 for (int z = 0; z<(client_email_r.length() - client_email.length() + 16); z++){
					 cout << " ";
					 }
					 cout << client_address;
					 for (int z = 0; z<(client_address_r.length() - client_address.length() + 22); z++){
					 cout << " ";
					 }

					 cout << client_bank_account;
					 for (int z = 0; z<(client_bank_account_r.length() - client_bank_account.length() + 14); z++){
					 cout << " ";
					 }
					 cout << client_bank;
					 for (int z = 0; z<(client_bank_r.length() - client_bank.length() + 14); z++){
					 cout << " ";
					 }

					 cout << client_credit;
					 for (int z = 0; z<(client_credit_r.length() + 16); z++){
					 cout << " ";
					 }

					 cout << client_pwd;
					 for (int z = 0; z<(client_pwd_r.length() - client_pwd.length()); z++){
					 cout << " ";
					 }
					 cout << endl;



					 //print out original data

					 }

					 }
					 clientStream.close();
					 system("pause");
					 manage_client();
					 //staff_main(sta.sessionID, sta.sessionNAME);
					 }
					

void staff::edit_client() {


				   system("cls");
				   //client c;


				   client &oldc = *new client();
				   client *newc = new client();


				   string client_id;
				   string client_name;
				   string client_ic;
				   string client_contact;
				   string client_email;
				   string client_address;
				   string client_bank_account;
				   string client_bank;
				   double client_credit;//default=0
				   string client_pwd;//default=password

				   //new record except id
				   string new_client_name;
				   string new_client_ic;
				   string new_client_contact;
				   string new_client_email;
				   string new_client_address;
				   string new_client_bank_account;
				   string new_client_bank;
				   double new_client_credit;//default=0
				   string new_client_pwd;//default=password


				   cout << "Enter the Client-Id of the Client whose data you wish to update:";
				   cin >> client_id;
				   stringstream ss;//stringstream ss;
				   ss << client_id;
				   string client_idS = ss.str();
				   string client_id2 = ss.str();

				   client_id2.append(".txt");
				   string filePortfolio = "dbclient/" + client_id2;
				   std::ifstream clientPort(filePortfolio.c_str());

				   bool chk = false;
				   ifstream validate("dbclient/db_client.txt");
				   string client_id_r = "";
				   string client_name_r = "";
				   string client_ic_r = "";
				   string client_contact_r = "";
				   string client_email_r = "";
				   string client_address_r = "";
				   string client_bank_account_r = "";
				   string client_bank_r = "";
				   string client_credit_r = "";
				   string client_pwd_r = "";


				   while (validate >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){

				   if (client_id.length() > client_id_r.length()){ client_id_r = client_id; }
				   if (client_name.length() > client_name_r.length()){ client_name_r = client_name; }

				   if (client_ic.length() > client_ic_r.length()){ client_ic_r = client_ic; }
				   if (client_contact.length() > client_contact_r.length()){ client_contact_r = client_contact; }
				   if (client_email.length() > client_email_r.length()){ client_email_r = client_email; }
				   if (client_address.length() > client_address_r.length()){ client_address_r = client_address; }
				   if (client_bank_account.length() > client_bank_account_r.length()){ client_bank_account_r = client_bank_account; }
				   if (client_bank.length() > client_bank_r.length()){ client_bank_r = client_bank; }
				   //if (client_credit.length() > client_credit_r.length()){ client_credit_r = client_credit; }
				   if (client_pwd.length() > client_pwd_r.length()){ client_pwd_r = client_pwd; }

				   //cout << client_id << " " << client_name << " " << client_ic << " " << client_contact << " " << client_email << " " << client_address << " " << client_bank_account << " " << client_bank << " " << client_credit << " " << client_pwd;

				   stringstream chks;
				   chks << client_id;
				   string sthrw = chks.str();
				   if (client_idS == sthrw){
				   cout << "The Id " + sthrw + " has found!" << endl;
				   chk = true;
				   }

				   }
				   if (!chk){
				   cout << "The Id is not exist!" << endl;

				   }
				   validate.close();
				   string decision;
				   //			client newClient;
				   //		client newClientPointer;// = &newClient;

				   while (clientPort >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){

				   oldc.setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

				   cout << "Is this the client that you wish to edit?[y/n]" << endl;
				   cout << oldc.getClientID() << " " << oldc.getClientNAME() << " " << oldc.getClientPASSPORT() << " " << oldc.getClientCONTACT() << " " << oldc.getClientEMAIL() << " " << oldc.getClientADDRESS() << " " << oldc.getClientBANKACCT() << " " << oldc.getClientBANK() << " " << oldc.getClientCREDIT() << " " << oldc.getClientPWD();
				   cin >> decision;
				   if (decision == "y"){
				   system("cls");
				   cout << "Current information:" << endl;


				   cout << "Client ID";
				   for (int y = 0; y<(client_id_r.length() + 5); y++){
				   cout << " ";
				   }
				   cout << "Client Name";
				   for (int z = 0; z<(client_name_r.length() + 8); z++){
				   cout << " ";
				   }
				   cout << "Client IC/Passport";
				   for (int z = 0; z<(client_ic_r.length()); z++){
				   cout << " ";
				   }
				   cout << "Client Contact";
				   for (int z = 0; z<(client_contact_r.length() + 5); z++){
				   cout << " ";
				   }
				   cout << "Client Email";
				   for (int z = 0; z<(client_email_r.length()); z++){
				   cout << " ";
				   }
				   cout << "Client Address";
				   for (int z = 0; z<(client_address_r.length() + 4); z++){
				   cout << " ";
				   }
				   cout << "Client Bank Account";
				   for (int z = 0; z<(client_bank_account_r.length()); z++){
				   cout << " ";
				   }
				   cout << "Client Bank ";
				   for (int z = 0; z<(client_bank_r.length()); z++){
				   cout << " ";
				   }
				   cout << "Client Credit ";
				   for (int z = 0; z<(client_credit_r.length() + 4); z++){
				   cout << " ";
				   }
				   cout << "Client Password ";
				   for (int z = 0; z<(client_pwd_r.length()); z++){
				   cout << " ";
				   }
				   cout << endl;

				   for (int z = 0; z<250; z++){
				   cout << "-";
				   }

				   cout << ' ' << endl;

				   cout << client_id;
				   for (int y = 0; y<((client_id_r.length() - client_id.length()) + +16); y++){
				   cout << " ";
				   }
				   cout << client_name;
				   for (int z = 0; z<(client_name_r.length() - client_name.length() + 20); z++){
				   cout << " ";
				   }
				   cout << client_ic;
				   for (int z = 0; z<(client_ic_r.length() - client_ic.length() + 16); z++){
				   cout << " ";
				   }
				   cout << client_contact;
				   for (int z = 0; z<(client_contact_r.length() + 8); z++){
				   cout << " ";
				   }
				   cout << client_email;
				   for (int z = 0; z<(client_email_r.length() - client_email.length() + 16); z++){
				   cout << " ";
				   }
				   cout << client_address;
				   for (int z = 0; z<(client_address_r.length() - client_address.length() + 22); z++){
				   cout << " ";
				   }

				   cout << client_bank_account;
				   for (int z = 0; z<(client_bank_account_r.length() - client_bank_account.length() + 14); z++){
				   cout << " ";
				   }
				   cout << client_bank;
				   for (int z = 0; z<(client_bank_r.length() - client_bank.length() + 14); z++){
				   cout << " ";
				   }

				   cout << client_credit;
				   for (int z = 0; z<(client_credit_r.length() + 16); z++){
				   cout << " ";
				   }

				   cout << client_pwd;
				   for (int z = 0; z<(client_pwd_r.length() - client_pwd.length()); z++){
				   cout << " ";
				   }
				   cout << endl;



				   //print out original data



				   cout << "Enter client name want to replace:" << endl;
				   cin.get();
				   getline(cin, new_client_name);
				//   cin >> new_client_name;
				   cout << "Enter new Client IC/Passport:" << endl;
				   cin.get();
				   getline(cin, new_client_ic);
				 //  cin >> new_client_ic;
				   cout << "Enter new Client Contact Number:" << endl;
				   cin.get();
				   getline(cin, new_client_contact);
				  // cin >> new_client_contact;
				   cout << "Enter new Client Email:" << endl;
				   cin.get();
				   getline(cin, new_client_email);
				  // cin >> new_client_email;
				   cout << "Enter new Client Address:" << endl;
				   cin.get();
				   getline(cin, new_client_address);
				// cin >> new_client_address;
				   

				   cout << "Enter new Client Bank:" << endl;
				   cin.get();
				   getline(cin, new_client_bank);
				   
				   // cin >> new_client_bank;
				   cout << "Enter new client " + new_client_bank + " Bank Account:" << endl;
				   cin.get();
				   getline(cin, new_client_bank_account);
				  // cin >> new_client_bank_account;
				   cout << "Enter new Client Credit:" << endl;
				   cin >> new_client_credit;
				   cout << "Enter new Client Password:" << endl;
				   cin >> new_client_pwd;

				   newc->setAttributes(client_id, new_client_name, new_client_ic, new_client_contact, new_client_email, new_client_address, new_client_bank_account, new_client_bank, new_client_credit, new_client_pwd);

				   }
				   if (decision == "n"){
				   manage_client();
				   }


				   ofstream tempPofolio("dbclient/tempPofolio.txt");

				   ofstream temp("dbclient/temp.txt");
				   ifstream clientD("dbclient/db_client.txt");
				   if (tempPofolio.is_open() && clientD.is_open() && temp.is_open()){

				   string line;
				   while (getline(clientD, line))
				   {
				   if (line.find(client_idS) == string::npos) { //str.find(str2) != string::npos
				   temp << line << endl;

				   }
				   else
				   {

					   tempPofolio << space_underscore(newc->getClientID()) << ' ' << space_underscore(newc->getClientNAME()) << ' ' << space_underscore(newc->getClientPASSPORT()) << ' ' << space_underscore(newc->getClientCONTACT()) << ' ' << space_underscore(newc->getClientEMAIL()) << ' ' << space_underscore(newc->getClientADDRESS()) << ' ' << space_underscore(newc->getClientBANKACCT()) << ' ' << space_underscore(newc->getClientBANK()) << ' ' << space_underscore(toString(newc->getClientCREDIT())) << ' ' << space_underscore(newc->getClientPWD()) << endl;
					   temp << space_underscore(newc->getClientID()) << ' ' << space_underscore(newc->getClientNAME()) << ' ' << space_underscore(newc->getClientPASSPORT()) << ' ' << space_underscore(newc->getClientCONTACT()) << ' ' << space_underscore(newc->getClientEMAIL()) << ' ' << space_underscore(newc->getClientADDRESS()) << ' ' << space_underscore(newc->getClientBANKACCT()) << ' ' << space_underscore(newc->getClientBANK()) << ' ' << space_underscore(toString(newc->getClientCREDIT())) << ' ' << space_underscore(newc->getClientPWD()) << endl;
				   }
				   }

				   }
				   tempPofolio.close();
				   clientPort.close();
				   clientD.close();

				   temp.close();


				   string db_old_file = "dbclient/db_client.txt";
				   //system("del dbclient/db_client.txt");
				   const char *data = "dbclient/db_client.txt";
				   remove(db_old_file.c_str());//delete the old db file first


				   //system("del dbclient/db_client.txt");
				   remove(filePortfolio.c_str());

				   rename("dbclient/tempPofolio.txt", filePortfolio.c_str());
				   rename("dbclient/temp.txt", "dbclient/db_client.txt");
				   //******


				   }

				   staff::manage_client();

				   }

void staff::displayAllClient(){


						//.....
						system("cls");
						//client c;

						string client_id;
						string client_name;
						string client_ic;
						string client_contact;
						string client_email;
						string client_address;
						string client_bank_account;
						string client_bank;
						double client_credit;//default=0
						string client_pwd;//default=password


						cout << "Entire Client database" << endl;
						cout << "------------------------" << endl;
						ifstream dir("dbclient/db_client.txt");
						string client_id_r = "";
						string client_name_r = "";
						string client_ic_r = "";
						string client_contact_r = "";
						string client_email_r = "";
						string client_address_r = "";
						string client_bank_account_r = "";
						string client_bank_r = "";
						string client_credit_r = "";
						string client_pwd_r = "";


						while (dir >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){

						if (client_id.length() > client_id_r.length()){ client_id_r = client_id; }
						if (client_name.length() > client_name_r.length()){ client_name_r = client_name; }

						if (client_ic.length() > client_ic_r.length()){ client_ic_r = client_ic; }
						if (client_contact.length() > client_contact_r.length()){ client_contact_r = client_contact; }
						if (client_email.length() > client_email_r.length()){ client_email_r = client_email; }
						if (client_address.length() > client_address_r.length()){ client_address_r = client_address; }
						if (client_bank_account.length() > client_bank_account_r.length()){ client_bank_account_r = client_bank_account; }
						if (client_bank.length() > client_bank_r.length()){ client_bank_r = client_bank; }
						//if (client_credit.length() > client_credit_r.length()){ client_credit_r = client_credit; }
						if (client_pwd.length() > client_pwd_r.length()){ client_pwd_r = client_pwd; }



						}

						cout << "Current Client Information:" << endl;


						cout << "Client ID";
						for (int y = 0; y<(client_id_r.length() + 5); y++){
						cout << " ";
						}
						cout << "Client Name";
						for (int z = 0; z<(client_name_r.length() + 8); z++){
						cout << " ";
						}
						cout << "Client IC/Passport";
						for (int z = 0; z<(client_ic_r.length()); z++){
						cout << " ";
						}
						cout << "Client Contact";
						for (int z = 0; z<(client_contact_r.length() + 5); z++){
						cout << " ";
						}
						cout << "Client Email";
						for (int z = 0; z<(client_email_r.length()); z++){
						cout << " ";
						}
						cout << "Client Address";
						for (int z = 0; z<(client_address_r.length() + 4); z++){
						cout << " ";
						}
						cout << "Client Bank Account";
						for (int z = 0; z<(client_bank_account_r.length()); z++){
						cout << " ";
						}
						cout << "Client Bank ";
						for (int z = 0; z<(client_bank_r.length()); z++){
						cout << " ";
						}
						cout << "Client Credit ";
						for (int z = 0; z<(client_credit_r.length() + 4); z++){
						cout << " ";
						}
						cout << "Client Password ";
						for (int z = 0; z<(client_pwd_r.length()); z++){
						cout << " ";
						}
						cout << endl;

						for (int z = 0; z<250; z++){
						cout << "-";
						}

						cout << ' ' << endl;




						ifstream dir1("dbclient/db_client.txt");
						while (dir1 >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){


						cout << client_id;
						for (int y = 0; y<((client_id_r.length() - client_id.length()) + +16); y++){
						cout << " ";
						}
						cout << client_name;
						for (int z = 0; z<(client_name_r.length() - client_name.length() + 20); z++){
						cout << " ";
						}
						cout << client_ic;
						for (int z = 0; z<(client_ic_r.length() - client_ic.length() + 16); z++){
						cout << " ";
						}
						cout << client_contact;
						for (int z = 0; z<(client_contact_r.length() + 8); z++){
						cout << " ";
						}
						cout << client_email;
						for (int z = 0; z<(client_email_r.length() - client_email.length() + 16); z++){
						cout << " ";
						}
						cout << client_address;
						for (int z = 0; z<(client_address_r.length() - client_address.length() + 22); z++){
						cout << " ";
						}

						cout << client_bank_account;
						for (int z = 0; z<(client_bank_account_r.length() - client_bank_account.length() + 14); z++){
						cout << " ";
						}
						cout << client_bank;
						for (int z = 0; z<(client_bank_r.length() - client_bank.length() + 14); z++){
						cout << " ";
						}

						cout << client_credit;
						for (int z = 0; z<(client_credit_r.length() + 16); z++){
						cout << " ";
						}

						cout << client_pwd;
						for (int z = 0; z<(client_pwd_r.length() - client_pwd.length()); z++){
						cout << " ";
						}
						cout << endl;



						//print out original data
						}
						dir.close();
						dir1.close();
						system("pause");
						staff::manage_client();


						}

void staff::delete_client() {



					 system("cls"); system("cls");
					 //system("pause");

					 //	client cpointer ;// = &c;
					 string client_id;
					 string client_name;
					 string client_ic;
					 string client_contact;
					 string client_email;
					 string client_address;
					 string client_bank_account;
					 string client_bank;
					 double client_credit;//default=0
					 string client_pwd;//default=password


					 string decision;

					 cout << "Enter Client ID :";
					 cin >> client_id;
					 stringstream ss;//stringstream ss;
					 ss << client_id;
					 string client_idS = ss.str();
					 string client_id2 = ss.str();
					 // string *add_empId2=&empId2;
					 client_id2.append(".txt");

					 string portfolioFile = "dbclient/" + client_id2;

					 bool chk = false;
					 ifstream validate("dbclient/db_client.txt");
					 while (validate >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){
					 stringstream chks;
					 chks << client_id;
					 string sthrw = chks.str();
					 if (client_idS == sthrw){
					 cout << "The Id has found!" << endl;
					 chk = true;
					 }

					 }
					 if (!chk){
					 cout << "The Id is not exist!" << endl;

					 }
					 validate.close();


					 ifstream dir(portfolioFile.c_str());


					 string client_id_r = "";
					 string client_name_r = "";
					 string client_ic_r = "";
					 string client_contact_r = "";
					 string client_email_r = "";
					 string client_address_r = "";
					 string client_bank_account_r = "";
					 string client_bank_r = "";
					 string client_credit_r = "";
					 string client_pwd_r = "";


					 while (dir >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){

					 if (client_id.length() > client_id_r.length()){ client_id_r = client_id; }
					 if (client_name.length() > client_name_r.length()){ client_name_r = client_name; }

					 if (client_ic.length() > client_ic_r.length()){ client_ic_r = client_ic; }
					 if (client_contact.length() > client_contact_r.length()){ client_contact_r = client_contact; }
					 if (client_email.length() > client_email_r.length()){ client_email_r = client_email; }
					 if (client_address.length() > client_address_r.length()){ client_address_r = client_address; }
					 if (client_bank_account.length() > client_bank_account_r.length()){ client_bank_account_r = client_bank_account; }
					 if (client_bank.length() > client_bank_r.length()){ client_bank_r = client_bank; }
					 //if (client_credit.length() > client_credit_r.length()){ client_credit_r = client_credit; }
					 if (client_pwd.length() > client_pwd_r.length()){ client_pwd_r = client_pwd; }


					 //cpointer =  client(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

					 cout << "Is this the client that you wish to delete?[y/n]" << endl;
					 cout << client_id << " " << client_name << " " << client_ic << " " << client_contact << " " << client_email << " " << client_address << " " << client_bank_account << " " << client_bank << " " << client_credit << " " << client_pwd;
					 cin >> decision;
					 if (decision == "y"){
					 system("cls");
					 cout << "Current information:" << endl;



					 cout << "Client ID";
					 for (int y = 0; y<(client_id_r.length() + 5); y++){
					 cout << " ";
					 }
					 cout << "Client Name";
					 for (int z = 0; z<(client_name_r.length() + 8); z++){
					 cout << " ";
					 }
					 cout << "Client IC/Passport";
					 for (int z = 0; z<(client_ic_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Contact";
					 for (int z = 0; z<(client_contact_r.length() + 5); z++){
					 cout << " ";
					 }
					 cout << "Client Email";
					 for (int z = 0; z<(client_email_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Address";
					 for (int z = 0; z<(client_address_r.length() + 4); z++){
					 cout << " ";
					 }
					 cout << "Client Bank Account";
					 for (int z = 0; z<(client_bank_account_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Bank ";
					 for (int z = 0; z<(client_bank_r.length()); z++){
					 cout << " ";
					 }
					 cout << "Client Credit ";
					 for (int z = 0; z<(client_credit_r.length() + 4); z++){
					 cout << " ";
					 }
					 cout << "Client Password ";
					 for (int z = 0; z<(client_pwd_r.length()); z++){
					 cout << " ";
					 }
					 cout << endl;

					 for (int z = 0; z<250; z++){
					 cout << "-";
					 }

					 cout << ' ' << endl;



					 cout << client_id;
					 for (int y = 0; y<((client_id_r.length() - client_id.length()) + +16); y++){
					 cout << " ";
					 }
					 cout << client_name;
					 for (int z = 0; z<(client_name_r.length() - client_name.length() + 20); z++){
					 cout << " ";
					 }
					 cout << client_ic;
					 for (int z = 0; z<(client_ic_r.length() - client_ic.length() + 16); z++){
					 cout << " ";
					 }
					 cout << client_contact;
					 for (int z = 0; z<(client_contact_r.length() + 8); z++){
					 cout << " ";
					 }
					 cout << client_email;
					 for (int z = 0; z<(client_email_r.length() - client_email.length() + 16); z++){
					 cout << " ";
					 }
					 cout << client_address;
					 for (int z = 0; z<(client_address_r.length() - client_address.length() + 22); z++){
					 cout << " ";
					 }

					 cout << client_bank_account;
					 for (int z = 0; z<(client_bank_account_r.length() - client_bank_account.length() + 14); z++){
					 cout << " ";
					 }
					 cout << client_bank;
					 for (int z = 0; z<(client_bank_r.length() - client_bank.length() + 14); z++){
					 cout << " ";
					 }

					 cout << client_credit;
					 for (int z = 0; z<(client_credit_r.length() + 16); z++){
					 cout << " ";
					 }

					 cout << client_pwd;
					 for (int z = 0; z<(client_pwd_r.length() - client_pwd.length()); z++){
					 cout << " ";
					 }
					 cout << endl;



					 //print out original data

					 }
					 if (decision == "n"){
					 staff::manage_client();
					 }
					 cout << "Do you wish to delete this client from the database?" << endl;
					 cin >> decision;

					 dir.close();

					 if (decision == "y"){



					 ofstream temp("dbclient/temp.txt");
					 ifstream clientD("dbclient/db_client.txt");
					 if (clientD.is_open() && temp.is_open()){

					 string line;
					 while (getline(clientD, line))
					 {
					 if (line.find(client_idS) == string::npos) { //str.find(str2) != string::npos =-1  means not found
					 //only copy data that is not the key have entered!
					 temp << line << endl;//copy&write to temp

					 }
					 else if (line.find(client_id) != string::npos)
					 {

					 //do nothing , and not copy to the new database file so that we deleted the intended row in our new db
					 }
					 }

					 }


					 clientD.close();


					 temp.close();


					 string db_old_file = "dbclient/db_client.txt";
					 //system("del dbstaff/db_staff.txt");
					 const char *data = "dbclient/db_client.txt";
					 remove(db_old_file.c_str());//delete the old db file first
					 //system("del dbstaff/db_staff");
					 remove(portfolioFile.c_str());
					 rename("dbclient/temp.txt", "dbclient/db_client.txt");


					 }


					 system("pause");
					 staff::manage_staff();
					 }

					 }
					 

void staff::manage_customer(){

	system("cls");
	cout << "-----------HMS Customer Management Panel-----------" << endl;
	cout << "---------------------------------------------" << endl;
	system("color 0f");
	cout << "Please enter your choice" << endl;
	cout << "1.Add new Customer" << endl;
	cout << "2.Search for a Customer by ID number" << endl;
	cout << "3.Edit an existing Customer's information" << endl;
	cout << "4.Display all Customers" << endl;
	cout << "5.Delete a Customer" << endl;
	cout << "6.<<back" << endl;

	int choice;
	cin >> choice;

	switch (choice){
	case 1:
		add_customer();
		break;
	case 2:
		search_customer();
		break;
	case 3:
		edit_customer();
		break;
	case 4:
		displayAllCustomer();
		break;
	case 5:
		delete_customer();
		break;
	case 6:
		staff_main(sta.sessionID, sta.sessionNAME);
		break;
	default:
		cout << "The choice currently only valite in 1~6" << endl;
	}





}


void staff::add_customer(){

	system("cls");
	customer *cus = new customer();
	string customer_id;
	string customer_name;
	string customer_ic;
	string customer_contact;
	string customer_email;
	string customer_address;
	string customer_bank_account;
	string customer_bank;
	double customer_credit;//default=0
	string customer_pwd;//default=password
	//!!!!!!!!!!!!!pending, add locatio nad sdtomer_od
	string choiceCREDIT;
	string choicePWD;
	string fileName;


	get_TCustomerID(&customer_id);
	cout << "Input customer Name:";
	cin.get();
	getline(cin, customer_name);
	cout << "Input customer IC:";
	cin.get();
	getline(cin, customer_ic);
	cout << "Input customer Contact:";
	cin.get();
	getline(cin, customer_contact);
	cout << "Input customer Email:";
	cin.get();
	getline(cin, customer_email);
	cout << "Input customer Address:" << endl;
	//cin.getline(cin, customer_address);
	//cin >> customer_address;
	cin.get();
	getline(cin, customer_address); //!!! note thie two line are to get the line and not exit
	
	
	
	
	cout << "Input customer Bank:";
	cin.get();
	getline(cin, customer_bank);
	cout << "Input " + customer_bank + "-Bank Account Number:";
	cin.get();
	getline(cin, customer_bank_account);
	cout << "Want Give This customer credits? [Y/N]";
	cout << endl;
	cin >> choiceCREDIT;

	
	 if (choiceCREDIT == "Y" || choiceCREDIT == "y"){
		cout << "Now give amount of credits to this customer(RM)";

		cin >> customer_credit;
	}
	else {
		cout << "The default 0 Credit would give to this customer."; cout << endl;
		customer_credit = 0;
	}


	cout << "Want specify a password for this customer? [Y/N]"; cout << endl;
	cin >> choicePWD;
	if (choicePWD == "Y" || choicePWD == "y"){
		cout << "Now enter the password of this customer...";
		cin >> customer_pwd;
	}
	else {
		cout << "The default 'password' would be set as password for this customer, later on the customer may change it by themselves"; cout << endl;
		customer_pwd = "password";
	}
	cin.get();
	cin.ignore();


	if ((choicePWD == "Y" || choicePWD == "y") && (choiceCREDIT == "Y" || choiceCREDIT == "y")){
		cus->setAttributes(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);

	}
	else if ((choicePWD == "Y" || choicePWD == "y") && (choiceCREDIT != "Y" || choiceCREDIT != "y")){
		customer_credit = 0;
		cus->setAttributes(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);
	}
	else if ((choicePWD != "Y" || choicePWD != "y") && (choiceCREDIT == "Y" || choiceCREDIT == "y")){
		customer_pwd = "password";
		cus->setAttributes(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);

	}
	else {//if (choicePWD != "Y" && choiceCREDIT != "Y"){
		customer_credit = 0;
		customer_pwd = "password";
		cus->setAttributes(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);

	}


	stringstream ss;//stringstream ss;
	ss << customer_id;
	string customer_id2 = ss.str();
	// string *add_empId2=&empId2;
	customer_id2.append(".txt");
	string newPortfolio = "dbcustomer/" + customer_id2;

	ofstream newCustomer(newPortfolio.c_str());
	newCustomer << space_underscore(cus->getCustomerID()) << ' ' << space_underscore(cus->getCustomerNAME()) << ' ' << space_underscore(cus->getCustomerPASSPORT()) << ' ' << space_underscore(cus->getCustomerCONTACT()) << ' ' << space_underscore(cus->getCustomerEMAIL()) << ' ' << space_underscore(cus->getCustomerADDRESS()) << ' ' << space_underscore(cus->getCustomerBANKACCT()) << ' ' << space_underscore(cus->getCustomerBANK()) << ' ' << space_underscore(toString((cus->getCustomerCREDIT()))) << ' ' << space_underscore(cus->getCustomerPWD()) << endl;
	newCustomer.close();
	ofstream dir("dbcustomer/db_customer.txt", ios::app);
	dir << space_underscore(cus->getCustomerID()) << ' ' << space_underscore(cus->getCustomerNAME()) << ' ' << space_underscore(cus->getCustomerPASSPORT()) << ' ' << space_underscore(cus->getCustomerCONTACT()) << ' ' << space_underscore(cus->getCustomerEMAIL()) << ' ' << space_underscore(cus->getCustomerADDRESS()) << ' ' << space_underscore(cus->getCustomerBANKACCT()) << ' ' << space_underscore(cus->getCustomerBANK()) << ' ' << space_underscore(toString((cus->getCustomerCREDIT()))) << ' ' << space_underscore(cus->getCustomerPWD()) << endl;
	dir.close();
	cout << "You have just added ONE Customer: '" + cus->getCustomerNAME() + "' with ID: '" + cus->getCustomerID() + "'" << endl;

	system("pause");
	staff::manage_customer();


}


void staff::search_customer(){

	system("cls");
	system("color 0a");

	customer &cus = *new customer();
	//string customer_id;
	//string customer_name;
	//string customer_pwd;//default=password


	string customer_ic;
	string customer_contact;
	string customer_email;
	string customer_address;
	string customer_bank_account;
	string customer_bank;
	double customer_credit;//default=0
	

	user *user_cus = new customer;

	cout << "Enter customer ID number:";
	cin >> user_cus->id;

	stringstream ss;//stringstream ss;
	ss << user_cus->id;
	string customer_id2 = ss.str();
	string customer_idS = ss.str();

	customer_id2.append(".txt");

	string filePortfolio = "dbcustomer/" + customer_id2;


	std::ifstream customerStream(filePortfolio.c_str());

	string customer_id_r = "";
	string customer_name_r = "";
	string customer_ic_r = "";
	string customer_contact_r = "";
	string customer_email_r = "";
	string customer_address_r = "";
	string customer_bank_account_r = "";
	string customer_bank_r = "";
	string customer_credit_r = "";
	string customer_pwd_r = "";
	bool chk = false;
	ifstream validate("dbcustomer/db_customer.txt");
	while (validate >> user_cus->id >> user_cus->name >> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> user_cus->pwd){
		if (user_cus->getID().length() > customer_id_r.length()){ customer_id_r = user_cus->getID(); }
		if (user_cus->getName().length() > customer_name_r.length()){ customer_name_r = user_cus->getName(); }

		if (customer_ic.length() > customer_ic_r.length()){ customer_ic_r = customer_ic; }
		if (customer_contact.length() > customer_contact_r.length()){ customer_contact_r = customer_contact; }
		if (customer_email.length() > customer_email_r.length()){ customer_email_r = customer_email; }
		if (customer_address.length() > customer_address_r.length()){ customer_address_r = customer_address; }
		if (customer_bank_account.length() > customer_bank_account_r.length()){ customer_bank_account_r = customer_bank_account; }
		if (customer_bank.length() > customer_bank_r.length()){ customer_bank_r = customer_bank; }
		//if (customer_credit.length() > customer_credit_r.length()){ customer_credit_r = customer_credit; }
		if (user_cus->getPwd().length() > customer_pwd_r.length()){ customer_pwd_r = user_cus->getPwd(); }


		//c =  customer(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);
		stringstream chks;
		chks << user_cus->getID();
		string sthrw = chks.str();
		if (customer_idS == sthrw){
			cout << "The customer Id has found!" << endl;
			chk = true;
		}

	}
	if (!chk){
		cout << "The Id is not exist!" << endl;

	}
	validate.close();



	while (customerStream >> user_cus->id >> user_cus->name>> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> user_cus->pwd){

		cus.setAttributes(user_cus->getID(), user_cus->getName(), customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, user_cus->getPwd());
		cout << cus.getCustomerID() << "  " << cus.getCustomerNAME() << "  " << cus.getCustomerPASSPORT() << "  " << cus.getCustomerCONTACT() << "  " << cus.getCustomerEMAIL() << "  " << cus.getCustomerADDRESS() << "  " << cus.getCustomerBANKACCT() << "  " << cus.getCustomerBANK() << "  " << cus.getCustomerCREDIT() << "  " << cus.getCustomerPWD() << endl;
		string answer;
		cout << "Is this the correct customer?[y/n] " << endl;

		cin >> answer;

		if (answer == "y"){
			system("cls");


			cout << "customer ID";
			for (int y = 0; y<(customer_id_r.length() + 5); y++){
				cout << " ";
			}
			cout << "customer Name";
			for (int z = 0; z<(customer_name_r.length() + 8); z++){
				cout << " ";
			}
			cout << "customer IC/Passport";
			for (int z = 0; z<(customer_ic_r.length()); z++){
				cout << " ";
			}
			cout << "customer Contact";
			for (int z = 0; z<(customer_contact_r.length() + 5); z++){
				cout << " ";
			}
			cout << "customer Email";
			for (int z = 0; z<(customer_email_r.length()); z++){
				cout << " ";
			}
			cout << "customer Address";
			for (int z = 0; z<(customer_address_r.length() + 4); z++){
				cout << " ";
			}
			cout << "customer Bank Account";
			for (int z = 0; z<(customer_bank_account_r.length()); z++){
				cout << " ";
			}
			cout << "customer Bank ";
			for (int z = 0; z<(customer_bank_r.length()); z++){
				cout << " ";
			}
			cout << "customer Credit ";
			for (int z = 0; z<(customer_credit_r.length() + 4); z++){
				cout << " ";
			}
			cout << "customer Password ";
			for (int z = 0; z<(customer_pwd_r.length()); z++){
				cout << " ";
			}
			cout << endl;

			for (int z = 0; z<250; z++){
				cout << "-";
			}

			cout << ' ' << endl;

			cout << cus.getCustomerID();
			for (int y = 0; y<((customer_id_r.length() - user_cus->getID().length()) + +16); y++){
				cout << " ";
			}
			cout << cus.getCustomerNAME();
			for (int z = 0; z<(customer_name_r.length() - user_cus->getName().length() + 20); z++){
				cout << " ";
			}
			cout << cus.getCustomerPASSPORT();
			for (int z = 0; z<(customer_ic_r.length() - customer_ic.length() + 16); z++){
				cout << " ";
			}
			cout << cus.getCustomerCONTACT();
			for (int z = 0; z<(customer_contact_r.length() + 8); z++){
				cout << " ";
			}
			cout << cus.getCustomerEMAIL();
			for (int z = 0; z<(customer_email_r.length() - customer_email.length() + 16); z++){
				cout << " ";
			}
			cout << cus.getCustomerADDRESS();
			for (int z = 0; z<(customer_address_r.length() - customer_address.length() + 22); z++){
				cout << " ";
			}

			cout << cus.getCustomerBANKACCT();
			for (int z = 0; z<(customer_bank_account_r.length() - customer_bank_account.length() + 14); z++){
				cout << " ";
			}
			cout << cus.getCustomerBANK();
			for (int z = 0; z<(customer_bank_r.length() - customer_bank.length() + 14); z++){
				cout << " ";
			}

			cout << cus.getCustomerCREDIT();
			for (int z = 0; z<(customer_credit_r.length() + 16); z++){
				cout << " ";
			}

			cout << cus.getCustomerPWD();
			for (int z = 0; z<(customer_pwd_r.length() - cus.getCustomerPWD().length()); z++){
				cout << " ";
			}
			cout << endl;



			//print out original data

		}

	}
	customerStream.close();
	system("pause");
	manage_customer();
	//staff_main(sta.sessionID, sta.sessionNAME);



}


void staff::edit_customer(){

	system("cls");
	//customer c;


	customer &oldc = *new customer();
	customer *newc = new customer();


	string customer_id;
	string customer_name;
	string customer_ic;
	string customer_contact;
	string customer_email;
	string customer_address;
	string customer_bank_account;
	string customer_bank;
	double customer_credit;//default=0
	string customer_pwd;//default=password

	//new record except id
	string new_customer_name;
	string new_customer_ic;
	string new_customer_contact;
	string new_customer_email;
	string new_customer_address;
	string new_customer_bank_account;
	string new_customer_bank;
	double new_customer_credit;//default=0
	string new_customer_pwd;//default=password


	cout << "Enter the customer-Id of the customer whose data you wish to update:";
	cin >> customer_id;
	stringstream ss;//stringstream ss;
	ss << customer_id;
	string customer_idS = ss.str();
	string customer_id2 = ss.str();

	customer_id2.append(".txt");
	string filePortfolio = "dbcustomer/" + customer_id2;
	std::ifstream customerPort(filePortfolio.c_str());

	bool chk = false;
	ifstream validate("dbcustomer/db_customer.txt");
	string customer_id_r = "";
	string customer_name_r = "";
	string customer_ic_r = "";
	string customer_contact_r = "";
	string customer_email_r = "";
	string customer_address_r = "";
	string customer_bank_account_r = "";
	string customer_bank_r = "";
	string customer_credit_r = "";
	string customer_pwd_r = "";


	while (validate >> customer_id >> customer_name >> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){

		if (customer_id.length() > customer_id_r.length()){ customer_id_r = customer_id; }
		if (customer_name.length() > customer_name_r.length()){ customer_name_r = customer_name; }

		if (customer_ic.length() > customer_ic_r.length()){ customer_ic_r = customer_ic; }
		if (customer_contact.length() > customer_contact_r.length()){ customer_contact_r = customer_contact; }
		if (customer_email.length() > customer_email_r.length()){ customer_email_r = customer_email; }
		if (customer_address.length() > customer_address_r.length()){ customer_address_r = customer_address; }
		if (customer_bank_account.length() > customer_bank_account_r.length()){ customer_bank_account_r = customer_bank_account; }
		if (customer_bank.length() > customer_bank_r.length()){ customer_bank_r = customer_bank; }
		//if (customer_credit.length() > customer_credit_r.length()){ customer_credit_r = customer_credit; }
		if (customer_pwd.length() > customer_pwd_r.length()){ customer_pwd_r = customer_pwd; }

		//cout << customer_id << " " << customer_name << " " << customer_ic << " " << customer_contact << " " << customer_email << " " << customer_address << " " << customer_bank_account << " " << customer_bank << " " << customer_credit << " " << customer_pwd;

		stringstream chks;
		chks << customer_id;
		string sthrw = chks.str();
		if (customer_idS == sthrw){
			cout << "The Id " + sthrw + " has found!" << endl;
			chk = true;
		}

	}
	if (!chk){
		cout << "The Id is not exist!" << endl;

	}
	validate.close();
	string decision;
	//			customer newcustomer;
	//		customer newcustomerPointer;// = &newcustomer;

	while (customerPort >> customer_id >> customer_name >> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){

		oldc.setAttributes(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);

		cout << "Is this the customer that you wish to edit?[y/n]" << endl;
		cout << oldc.getCustomerID() << " " << oldc.getCustomerNAME() << " " << oldc.getCustomerPASSPORT() << " " << oldc.getCustomerCONTACT() << " " << oldc.getCustomerEMAIL() << " " << oldc.getCustomerADDRESS() << " " << oldc.getCustomerBANKACCT() << " " << oldc.getCustomerBANK() << " " << oldc.getCustomerCREDIT() << " " << oldc.getCustomerPWD();
		cin >> decision;
		if (decision == "y"){
			system("cls");
			cout << "Current information:" << endl;


			cout << "customer ID";
			for (int y = 0; y<(customer_id_r.length() + 5); y++){
				cout << " ";
			}
			cout << "customer Name";
			for (int z = 0; z<(customer_name_r.length() + 8); z++){
				cout << " ";
			}
			cout << "customer IC/Passport";
			for (int z = 0; z<(customer_ic_r.length()); z++){
				cout << " ";
			}
			cout << "customer Contact";
			for (int z = 0; z<(customer_contact_r.length() + 5); z++){
				cout << " ";
			}
			cout << "customer Email";
			for (int z = 0; z<(customer_email_r.length()); z++){
				cout << " ";
			}
			cout << "customer Address";
			for (int z = 0; z<(customer_address_r.length() + 4); z++){
				cout << " ";
			}
			cout << "customer Bank Account";
			for (int z = 0; z<(customer_bank_account_r.length()); z++){
				cout << " ";
			}
			cout << "customer Bank ";
			for (int z = 0; z<(customer_bank_r.length()); z++){
				cout << " ";
			}
			cout << "customer Credit ";
			for (int z = 0; z<(customer_credit_r.length() + 4); z++){
				cout << " ";
			}
			cout << "customer Password ";
			for (int z = 0; z<(customer_pwd_r.length()); z++){
				cout << " ";
			}
			cout << endl;

			for (int z = 0; z<250; z++){
				cout << "-";
			}

			cout << ' ' << endl;

			cout << customer_id;
			for (int y = 0; y<((customer_id_r.length() - customer_id.length()) + +16); y++){
				cout << " ";
			}
			cout << customer_name;
			for (int z = 0; z<(customer_name_r.length() - customer_name.length() + 20); z++){
				cout << " ";
			}
			cout << customer_ic;
			for (int z = 0; z<(customer_ic_r.length() - customer_ic.length() + 16); z++){
				cout << " ";
			}
			cout << customer_contact;
			for (int z = 0; z<(customer_contact_r.length() + 8); z++){
				cout << " ";
			}
			cout << customer_email;
			for (int z = 0; z<(customer_email_r.length() - customer_email.length() + 16); z++){
				cout << " ";
			}
			cout << customer_address;
			for (int z = 0; z<(customer_address_r.length() - customer_address.length() + 22); z++){
				cout << " ";
			}

			cout << customer_bank_account;
			for (int z = 0; z<(customer_bank_account_r.length() - customer_bank_account.length() + 14); z++){
				cout << " ";
			}
			cout << customer_bank;
			for (int z = 0; z<(customer_bank_r.length() - customer_bank.length() + 14); z++){
				cout << " ";
			}

			cout << customer_credit;
			for (int z = 0; z<(customer_credit_r.length() + 16); z++){
				cout << " ";
			}

			cout << customer_pwd;
			for (int z = 0; z<(customer_pwd_r.length() - customer_pwd.length()); z++){
				cout << " ";
			}
			cout << endl;



			//print out original data



			cout << "Enter customer name want to replace:" << endl;
			cin.get();
			getline(cin, new_customer_name);//
			//cin >> new_customer_name;
			cout << "Enter new customer IC/Passport:" << endl;
			cin.get();
			getline(cin, new_customer_ic);//
			//cin >> (new_customer_ic);
			cout << "Enter new customer Contact Number:" << endl;
			cin.get();
			getline(cin, new_customer_contact);//
			//cin >> (new_customer_contact);
			cout << "Enter new customer Email:" << endl;
			cin.get();
			getline(cin, new_customer_email);//
			//cin >> (new_customer_email);
			cout << "Enter new customer Address:" << endl;

			cin.get();
			getline(cin, new_customer_address);//


			cout << "Enter new customer Bank:" << endl;
			cin.get();
			getline(cin, new_customer_bank);//

			//cin >> (new_customer_bank);
			cout << "Enter new customer " + new_customer_bank + " Bank Account:" << endl;
			cin.get();
			getline(cin, new_customer_bank_account);//
			//cin >> (new_customer_bank_account) ;
			cout << "Enter new customer Credit:" << endl;

			cin >> new_customer_credit;
			cout << "Enter new customer Password:" << endl;
			cin >> new_customer_pwd;

			newc->setAttributes(customer_id, new_customer_name, new_customer_ic, new_customer_contact, new_customer_email, new_customer_address, new_customer_bank_account, new_customer_bank, new_customer_credit, new_customer_pwd);

		}
		if (decision == "n"){
			manage_customer();
		}


		ofstream tempPofolio("dbcustomer/tempPofolio.txt");

		ofstream temp("dbcustomer/temp.txt");
		ifstream customerD("dbcustomer/db_customer.txt");
		if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

			string line;
			while (getline(customerD, line))
			{
				if (line.find(customer_idS) == string::npos) { //str.find(str2) != string::npos
					temp << line << endl;

				}
				else
				{

					tempPofolio << space_underscore(newc->getCustomerID()) << ' ' << space_underscore(newc->getCustomerNAME()) << ' ' << space_underscore(newc->getCustomerPASSPORT()) << ' ' << space_underscore(newc->getCustomerCONTACT()) << ' ' << space_underscore(newc->getCustomerEMAIL()) << ' ' << space_underscore(newc->getCustomerADDRESS()) << ' ' << space_underscore(newc->getCustomerBANKACCT()) << ' ' << space_underscore(newc->getCustomerBANK()) << ' ' << space_underscore(toString(newc->getCustomerCREDIT())) << ' ' << space_underscore(newc->getCustomerPWD()) << endl;
					temp << space_underscore(newc->getCustomerID()) << ' ' << space_underscore(newc->getCustomerNAME()) << ' ' << space_underscore(newc->getCustomerPASSPORT()) << ' ' << space_underscore(newc->getCustomerCONTACT()) << ' ' << space_underscore(newc->getCustomerEMAIL()) << ' ' << space_underscore(newc->getCustomerADDRESS()) << ' ' << space_underscore(newc->getCustomerBANKACCT()) << ' ' << space_underscore(newc->getCustomerBANK()) << ' ' << space_underscore(toString(newc->getCustomerCREDIT())) << ' ' << space_underscore(newc->getCustomerPWD()) << endl;
				}
			}

		}
		tempPofolio.close();
		customerPort.close();
		customerD.close();

		temp.close();


		string db_old_file = "dbcustomer/db_customer.txt";
		//system("del dbcustomer/db_customer.txt");
		const char *data = "dbcustomer/db_customer.txt";
		remove(db_old_file.c_str());//delete the old db file first


		//system("del dbcustomer/db_customer.txt");
		remove(filePortfolio.c_str());

		rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
		rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
		//******


	}

	staff::manage_customer();


}

 string staff::space_underscore(string text) {
	for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
		if (*it == ' ') {
			*it = '_';
		}
	}
	return text;
}

void staff::displayAllCustomer(){

	//.....
	system("cls");
	//customer c;

	string customer_id;
	string customer_name;
	string customer_ic;
	string customer_contact;
	string customer_email;
	string customer_address;
	string customer_bank_account;
	string customer_bank;
	double customer_credit;//default=0
	string customer_pwd;//default=password


	cout << "Entire customer database" << endl;
	cout << "------------------------" << endl;
	ifstream dir("dbcustomer/db_customer.txt");
	string customer_id_r = "";
	string customer_name_r = "";
	string customer_ic_r = "";
	string customer_contact_r = "";
	string customer_email_r = "";
	string customer_address_r = "";
	string customer_bank_account_r = "";
	string customer_bank_r = "";
	string customer_credit_r = "";
	string customer_pwd_r = "";


	while (dir >> customer_id >> customer_name >> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){

		if (customer_id.length() > customer_id_r.length()){ customer_id_r = customer_id; }
		if (customer_name.length() > customer_name_r.length()){ customer_name_r = customer_name; }

		if (customer_ic.length() > customer_ic_r.length()){ customer_ic_r = customer_ic; }
		if (customer_contact.length() > customer_contact_r.length()){ customer_contact_r = customer_contact; }
		if (customer_email.length() > customer_email_r.length()){ customer_email_r = customer_email; }
		if (customer_address.length() > customer_address_r.length()){ customer_address_r = customer_address; }
		if (customer_bank_account.length() > customer_bank_account_r.length()){ customer_bank_account_r = customer_bank_account; }
		if (customer_bank.length() > customer_bank_r.length()){ customer_bank_r = customer_bank; }
		//if (customer_credit.length() > customer_credit_r.length()){ customer_credit_r = customer_credit; }
		if (customer_pwd.length() > customer_pwd_r.length()){ customer_pwd_r = customer_pwd; }



	}

	cout << "Current customer Information:" << endl;


	cout << "customer ID";
	for (int y = 0; y<(customer_id_r.length() + 5); y++){
		cout << " ";
	}
	cout << "customer Name";
	for (int z = 0; z<(customer_name_r.length() + 8); z++){
		cout << " ";
	}
	cout << "customer IC/Passport";
	for (int z = 0; z<(customer_ic_r.length()); z++){
		cout << " ";
	}
	cout << "customer Contact";
	for (int z = 0; z<(customer_contact_r.length() + 5); z++){
		cout << " ";
	}
	cout << "customer Email";
	for (int z = 0; z<(customer_email_r.length()); z++){
		cout << " ";
	}
	cout << "customer Address";
	for (int z = 0; z<(customer_address_r.length() + 4); z++){
		cout << " ";
	}
	cout << "customer Bank Account";
	for (int z = 0; z<(customer_bank_account_r.length()); z++){
		cout << " ";
	}
	cout << "customer Bank ";
	for (int z = 0; z<(customer_bank_r.length()+3); z++){
		cout << " ";
	}
	cout << "customer Credit ";
	for (int z = 0; z<(customer_credit_r.length() + 4); z++){
		cout << " ";
	}
	cout << "customer Password ";
	for (int z = 0; z<(customer_pwd_r.length()); z++){
		cout << " ";
	}
	cout << endl;

	for (int z = 0; z<300; z++){
		cout << "-";
	}

	cout << ' ' << endl;




	ifstream dir1("dbcustomer/db_customer.txt");
	while (dir1 >> customer_id >> customer_name >> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){


		cout << customer_id;
		for (int y = 0; y<((customer_id_r.length() - customer_id.length()) + +18); y++){
			cout << " ";
		}
		cout << customer_name;
		for (int z = 0; z<(customer_name_r.length() - customer_name.length() + 22); z++){
			cout << " ";
		}
		cout << customer_ic;
		for (int z = 0; z<(customer_ic_r.length() - customer_ic.length() + 20); z++){
			cout << " ";
		}
		cout << customer_contact;
		for (int z = 0; z<(customer_contact_r.length() - customer_contact.length() + 12); z++){
			cout << " ";
		}
		cout << customer_email;
		for (int z = 0; z<(customer_email_r.length() - customer_email.length() + 22); z++){
			cout << " ";
		}
		cout << customer_address;
		for (int z = 0; z<(customer_address_r.length() - customer_address.length() + 26); z++){
			cout << " ";
		}

		cout << customer_bank_account;
		for (int z = 0; z<(customer_bank_account_r.length() - customer_bank_account.length() + 17); z++){
			cout << " ";
		}
		cout << customer_bank;
		for (int z = 0; z<(customer_bank_r.length() - customer_bank.length() + 20); z++){
			cout << " ";
		}

		cout << customer_credit;
		for (int z = 0; z<(customer_credit_r.length() + 18); z++){
			cout << " ";
		}

		cout << customer_pwd;
		for (int z = 0; z<(customer_pwd_r.length() - customer_pwd.length()); z++){
			cout << " ";
		}
		cout << endl;



		//print out original data
	}
	dir.close();
	dir1.close();
	system("pause");
	staff::manage_customer();


}
void staff::delete_customer(){

	system("cls"); system("cls");
	//system("pause");

		customer *cpointer = new customer();// = &c;
	string customer_id;
	string customer_name;
	string customer_ic;
	string customer_contact;
	string customer_email;
	string customer_address;
	string customer_bank_account;
	string customer_bank;
	double customer_credit;//default=0
	string customer_pwd;//default=password


	string decision;

	cout << "Enter customer ID :";
	cin >> customer_id;
	stringstream ss;//stringstream ss;
	ss << customer_id;
	string customer_idS = ss.str();
	string customer_id2 = ss.str();
	// string *add_empId2=&empId2;
	customer_id2.append(".txt");

	string portfolioFile = "dbcustomer/" + customer_id2;

	bool chk = false;
	ifstream validate("dbcustomer/db_customer.txt");
	while (validate >> customer_id >> customer_name >> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){
		stringstream chks;
		chks << customer_id;
		string sthrw = chks.str();
		if (customer_idS == sthrw){
			cout << "The Id has found!" << endl;
			chk = true;
		}

	}
	if (!chk){
		cout << "The Id is not exist!" << endl;

	}
	validate.close();


	ifstream dir(portfolioFile.c_str());


	string customer_id_r = "";
	string customer_name_r = "";
	string customer_ic_r = "";
	string customer_contact_r = "";
	string customer_email_r = "";
	string customer_address_r = "";
	string customer_bank_account_r = "";
	string customer_bank_r = "";
	string customer_credit_r = "";
	string customer_pwd_r = "";


	while (dir >> customer_id >> customer_name >> customer_ic >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){

		if (customer_id.length() > customer_id_r.length()){ customer_id_r = customer_id; }
		if (customer_name.length() > customer_name_r.length()){ customer_name_r = customer_name; }

		if (customer_ic.length() > customer_ic_r.length()){ customer_ic_r = customer_ic; }
		if (customer_contact.length() > customer_contact_r.length()){ customer_contact_r = customer_contact; }
		if (customer_email.length() > customer_email_r.length()){ customer_email_r = customer_email; }
		if (customer_address.length() > customer_address_r.length()){ customer_address_r = customer_address; }
		if (customer_bank_account.length() > customer_bank_account_r.length()){ customer_bank_account_r = customer_bank_account; }
		if (customer_bank.length() > customer_bank_r.length()){ customer_bank_r = customer_bank; }
		//if (customer_credit.length() > customer_credit_r.length()){ customer_credit_r = customer_credit; }
		if (customer_pwd.length() > customer_pwd_r.length()){ customer_pwd_r = customer_pwd; }


		cpointer->setAttributes(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);

		cout << "Is this the customer that you wish to edit?[y/n]" << endl;
		cout << cpointer->getCustomerID() << " " << cpointer->getCustomerNAME() << " " << cpointer->getCustomerPASSPORT() << " " << cpointer->getCustomerCONTACT() << " " << cpointer->getCustomerEMAIL() << " " << cpointer->getCustomerADDRESS() << " " << cpointer->getCustomerBANKACCT() << " " << cpointer->getCustomerBANK() << " " << cpointer->getCustomerCREDIT() << " " << cpointer->getCustomerPWD();
		cin >> decision;
		if (decision == "y"){
			system("cls");
			cout << "Current information:" << endl;


			cout << "customer ID";
			for (int y = 0; y<(customer_id_r.length() + 5); y++){
				cout << " ";
			}
			cout << "customer Name";
			for (int z = 0; z<(customer_name_r.length() + 8); z++){
				cout << " ";
			}
			cout << "customer IC/Passport";
			for (int z = 0; z<(customer_ic_r.length()); z++){
				cout << " ";
			}
			cout << "customer Contact";
			for (int z = 0; z<(customer_contact_r.length() + 5); z++){
				cout << " ";
			}
			cout << "customer Email";
			for (int z = 0; z<(customer_email_r.length()); z++){
				cout << " ";
			}
			cout << "customer Address";
			for (int z = 0; z<(customer_address_r.length() + 4); z++){
				cout << " ";
			}
			cout << "customer Bank Account";
			for (int z = 0; z<(customer_bank_account_r.length()); z++){
				cout << " ";
			}
			cout << "customer Bank ";
			for (int z = 0; z<(customer_bank_r.length()); z++){
				cout << " ";
			}
			cout << "customer Credit ";
			for (int z = 0; z<(customer_credit_r.length() + 4); z++){
				cout << " ";
			}
			cout << "customer Password ";
			for (int z = 0; z<(customer_pwd_r.length()); z++){
				cout << " ";
			}
			cout << endl;

			for (int z = 0; z<250; z++){
				cout << "-";
			}

			cout << ' ' << endl;

		

			cout << cpointer->getCustomerID();
			for (int y = 0; y<((customer_id_r.length() - customer_id.length()) + +16); y++){
				cout << " ";
			}
			cout << cpointer->getCustomerNAME();
			for (int z = 0; z<(customer_name_r.length() - customer_name.length() + 20); z++){
				cout << " ";
			}
			cout << cpointer->getCustomerPASSPORT();
			for (int z = 0; z<(customer_ic_r.length() - customer_ic.length() + 16); z++){
				cout << " ";
			}
			cout << cpointer->getCustomerCONTACT();
			for (int z = 0; z<(customer_contact_r.length() + 8); z++){
				cout << " ";
			}
			cout << cpointer->getCustomerEMAIL();
			for (int z = 0; z<(customer_email_r.length() - customer_email.length() + 16); z++){
				cout << " ";
			}
			cout << cpointer->getCustomerADDRESS();
			for (int z = 0; z<(customer_address_r.length() - customer_address.length() + 22); z++){
				cout << " ";
			}

			cout << cpointer->getCustomerBANKACCT();
			for (int z = 0; z<(customer_bank_account_r.length() - customer_bank_account.length() + 14); z++){
				cout << " ";
			}
			cout << cpointer->getCustomerBANK();
			for (int z = 0; z<(customer_bank_r.length() - customer_bank.length() + 14); z++){
				cout << " ";
			}

			cout << cpointer->getCustomerCREDIT();
			for (int z = 0; z<(customer_credit_r.length() + 16); z++){
				cout << " ";
			}

			cout << cpointer->getCustomerPWD();
			for (int z = 0; z<(customer_pwd_r.length() - customer_pwd.length()); z++){
				cout << " ";
			}
			cout << endl;



			//print out original data

		}
		if (decision == "n"){
			staff::manage_customer();
		}
		cout << "Do you wish to delete this customer from the database?" << endl;
		cin >> decision;

		dir.close();

		if (decision == "y"){



			ofstream temp("dbcustomer/temp.txt");
			ifstream customerD("dbcustomer/db_customer.txt");
			if (customerD.is_open() && temp.is_open()){

				string line;
				while (getline(customerD, line))
				{
					if (line.find(customer_idS) == string::npos) { //str.find(str2) != string::npos =-1  means not found
						//only copy data that is not the key have entered!
						temp << line << endl;//copy&write to temp

					}
					else if (line.find(customer_id) != string::npos)
					{

						//do nothing , and not copy to the new database file so that we deleted the intended row in our new db
					}
				}

			}


			customerD.close();


			temp.close();


			string db_old_file = "dbcustomer/db_customer.txt";
			//system("del dbstaff/db_staff.txt");
			const char *data = "dbcustomer/db_customer.txt";
			remove(db_old_file.c_str());//delete the old db file first
			//system("del dbstaff/db_staff");
			remove(portfolioFile.c_str());
			rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");


		}


		system("pause");
		staff::manage_staff();
	}



}


void staff::manage_home(){
	app a;
	

	system("cls");
	cout << "-----------Welcome staff: " + sta.sessionNAME + "-----------" << endl;
	cout << "-----------Home-Stay Management Console----------" << endl;
	system("color 0f");
	cout << "Please enter your choice" << endl;
	cout << "1.Add a New Home" << endl;
	cout << "2.Edit existing Home" << endl;
	cout << "3.View All Home Info" << endl;
	cout << "4.Delete existing Home" << endl;
	cout << "5.Add New home with new Client" << endl;

	cout << "6.<<Back" << endl;

	int choice;
	cin >> choice;

	switch (choice){
	case 1:
		new_home();
		break;
	case 2:
		edit_home();
		break;
	case 3:
		list_home();
		break;
	case 4:
		delete_home();
		break;
	case 5:
		new_home_new_client();
		break;

	case 6:
		//a.main();
		staff_main(sta.sessionID,sta.sessionNAME);
		break;

	default:
		cout << "Pls choose beween interger 1 ~ 6 only" << endl;
	}

}

//home manage

void staff::new_home(){

	ifstream aFile("dbhome/db_home.txt");
	size_t lines_count = std::count(istreambuf_iterator<char>(aFile),
		std::istreambuf_iterator<char>(), '\n');
	int current_row = lines_count;//
	int new_home_row = ++current_row;

	string newHomeID = "home" + toString(new_home_row);//set the new home id
	aFile.close();
	//prompt menu to user
	string home_id; string home_address;
	int no_room; int no_bath_room; int max_capacity;

	double sq_ft;

	ifstream facility_reader("dbhome/facility.txt");
	string facility_item;
	string facility[10];
	int i = 0;
	while (facility_reader >> facility_item){
		facility[i]=facility_item;
		i++;
	}facility_reader.ignore(1,'\n');
	facility_reader.close();

	for (int q = 0; q < 10;++q){
		cout << facility[q] << endl;
	}
	


	string facility_need_store;
	string description;
	string owner_id;

	double day_price; double week_price; double month_price;


	system("cls");
	cout << "-----------Welcome staff: " + sta.sessionNAME + "-----------" << endl;
	cout << "-----------Home Management Console----------" << endl;
	system("color 0f");

	cout << "Where is the location of the House for rent?" << endl;
	//cin.get();
	getline(cin, home_address);

	
	get_Num_Rooms(&no_room,"bedroom");
	get_Num_Rooms(&no_bath_room,"bathroom");
	get_Num_Rooms(&max_capacity, "max capacity of the room");


	cout << "How big is the room? (in square feet) sq.ft." << endl;
	cin >> sq_ft; cin.ignore(1, '\n');

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\nINVALID  number." << endl;

		std::cout << "Enter the size of room in squre.feet again--(Last chance to enter)" << endl;

		cin >> sq_ft;
		cin.ignore(1, '\n');

		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  number." << endl;
		}

	}
	

	bool loop = true;
	char choice;
	int switchCase;
	int z=0;
	string chosenFacility[5];
	while (loop && z<5){
	
		cout << "What facilities the house owns? Choose at the menu below...(choose 5(max))" << endl;
		cout << "1." + facility[0] << ' ' << "2." + facility[1] << ' ' << "3." + facility[2] << ' ' << "4." + facility[3] << ' ' << "5." + facility[4] << ' ' << "6." + facility[5] << ' ' << "7." + facility[6] << ' ' << "8." + facility[7] << ' ' << "9." + facility[8] << ' ' << "10." + facility[9] << endl;

		cin >> switchCase; cin.ignore(1, '\n');

			--switchCase;
		chosenFacility[z] = facility[switchCase];
			
		//getline(cin, chosenFacility[z]);


			cout << "Enough?[Y/N], Maximum 5, if want more, contact staff...(0166028563)" << endl;
			cin >> choice;
	
			cin.ignore(1, '\n');

		if (choice == 'y' || choice == 'Y' || z>=5){
			break; loop = false;
		}
		else if (z < 5 || choice == 'n' || choice == 'N'){
			loop = true;
			++z;
		
		}

	}
	


	for (int w = 0; w < chosenFacility[w].length();w++){
		facility_need_store = facility_need_store+"+"+chosenFacility[w];
	}


StartAgain:

	cout << "Write a description about the house/room (Max 50 words)" << endl;
	//cin.get();
	getline(cin, description); 
	char Fchars[50]; for (int a = 0; a <= description.size(); a++){ Fchars[a] = description[a]; }

	int size = strlen(Fchars);
	if (size >= 50)
	{
		cout << "max allowed size is 50 char" << endl;
		goto StartAgain;
	}

	owner_id = sta.sessionID;

	
	cout << "How much the room/house would be cost for daily-renting(cost per day in RM) [?RM/day]" << endl;
	cin >> day_price; cin.ignore(1, '\n');

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\nINVALID  cost." << endl;

		std::cout << "Enter the price of daily rental in RM--(Last chance to enter)" << endl;

		cin >> day_price; cin.ignore(1, '\n');


		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  cost value." << endl;
		}

	}

	cout << "How much the room/house would be cost for weekly-renting(cost per day in RM) [?RM/week]" << endl;
	cin >> week_price; cin.ignore(1, '\n');

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\nINVALID  cost." << endl;

		std::cout << "Enter the price of weekly rental in RM--(Last chance to enter)" << endl;

		cin >> week_price; cin.ignore(1, '\n');


		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  cost value." << endl;
		}

	}


	cout << "How much the room/house would be cost for monthly-renting(cost per day in RM) [?RM/month]" << endl;
	cin >> month_price; cin.ignore(1, '\n');

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\nINVALID  cost." << endl;

		std::cout << "Enter the price of monthly rental in RM--(Last chance to enter)" << endl;

		cin >> month_price; cin.ignore(1, '\n');


		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  cost value." << endl;
		}

	}


	home *homeObj = new home(newHomeID,home_address,no_room,no_bath_room,max_capacity,sq_ft,facility_need_store,description,owner_id,day_price,week_price,month_price);

	string homeDB = newHomeID.append(".txt");
	
	string newHomePortfolio = "dbhome/" + homeDB;


	ofstream newHome(newHomePortfolio.c_str());
	newHome << homeObj->getHomeID() << ' ' << space_underscore(homeObj->getHomeAddress()) << ' ' << homeObj->getNoRoom() << ' ' << homeObj->getNoBathRoom() << ' ' << homeObj->getMaxCapacity() << ' ' << homeObj->getSizeSqFt() << ' ' << space_underscore(homeObj->facility) << ' ' << space_underscore(homeObj->description) << ' ' << homeObj->owner_id << ' ' << homeObj->day_price << ' ' << homeObj->week_price << ' ' << homeObj->month_price << endl;
	newHome.close();

	ofstream dir("dbhome/db_home.txt", ios::app);
	dir << homeObj->getHomeID() << ' ' << space_underscore(homeObj->getHomeAddress()) << ' ' << homeObj->getNoRoom() << ' ' << homeObj->getNoBathRoom() << ' ' << homeObj->getMaxCapacity() << ' ' << homeObj->getSizeSqFt() << ' ' << space_underscore( homeObj->facility) << ' ' << space_underscore( homeObj->description) << ' ' << homeObj->owner_id << ' ' << homeObj->day_price << ' ' << homeObj->week_price << ' ' << homeObj->month_price << endl;
	dir.close();
	cout << "You have just added a home at '" + homeObj->getHomeAddress() + "' with home ID: '" + newHomeID + "'" << endl;



	system("pause");
	manage_home();
}
 void staff::edit_home(){

	// ifstream aFile("dbhome/db_home.txt");
	 home *homePtr=new home();
	 homePtr->displayDetail();
	 string home_id; 
	 string home_address;
	 int no_room; 
	 int no_bath_room;
	 int max_capacity;

	 double sq_ft;
	 string facility;
	 string description;
	 string owner_id;

	 double day_price; 
	 double week_price; 
	 double month_price;

	 cout << "*************************************************************" << endl;
	 cout << "--------------Available Home Stay were posted----------------" << endl;
	 cout << "*************************************************************" << endl;
	//user *user_view;
	 //user_view->view_home();
	
	 ifstream dir("dbhome/db_home.txt");


	 string home_idResult = "";
	 string home_addressResult = "";
	 string no_roomResult = ""; string no_bath_roomResult = ""; string max_capacityResult = "";

	 string sq_ftResult = "";

	 string facilityResult = "";
	 string descriptionResult = "";
	 string owner_idResult = "";

	 string day_priceResult = ""; string week_priceResult = ""; string month_priceResult = "";


	 while (dir >> home_id >> home_address >> no_room >> no_bath_room >> max_capacity >> sq_ft >> facility >> description >> owner_id >> day_price >> week_price >> month_price){

		 //these approach make sure the length are the longest
		 if (home_id.length() > home_idResult.length()){
			 home_idResult = home_id;
		 }

		 if (home_address.length() > home_addressResult.length()){
			 home_addressResult = home_address;
		 }


		 stringstream sss;
		 sss << no_room;
		 string no_rooms = sss.str();
		 if (no_rooms.length()>no_roomResult.length()){
			 no_roomResult = no_rooms;
		 }

		 stringstream sbath;
		 sbath << no_bath_room;
		 string no_bath_rooms = sbath.str();
		 if (no_bath_rooms.length()>no_bath_roomResult.length()){
			 no_bath_roomResult = no_bath_rooms;
		 }

		 stringstream scapacity;
		 scapacity << max_capacity;
		 string max_capacitys = scapacity.str();
		 if (max_capacitys.length()>max_capacityResult.length()){
			 max_capacityResult = max_capacitys;
		 }

		 stringstream ssqft;
		 ssqft << sq_ft;
		 string sq_fts = ssqft.str();
		 if (sq_fts.length()>sq_ftResult.length()){
			 sq_ftResult = sq_fts;
		 }


		 if (facility.length() > facilityResult.length()){
			 facilityResult = facility;
		 }


		 if (description.length() > descriptionResult.length()){
			 descriptionResult = description;
		 }
		 if (owner_id.length() > owner_idResult.length()){
			 owner_idResult = owner_id;
		 }

		 stringstream sss_day_price;
		 sss_day_price << day_price;
		 string day_prices = sss_day_price.str();
		 if (day_prices.length()>day_priceResult.length()){
			 day_priceResult = day_prices;
		 }

		 stringstream sss_week_price;
		 sss_week_price << week_price;
		 string week_prices = sss_week_price.str();
		 if (week_prices.length()>week_priceResult.length()){
			 week_priceResult = week_prices;
		 }

		 stringstream sss_month_price;
		 sss_month_price << month_price;
		 string month_prices = sss_month_price.str();
		 if (month_prices.length()>month_priceResult.length()){
			 month_priceResult = month_prices;
		 }




	 }dir.close();



	 int homeIDLength = home_idResult.size();
	 int home_addressLength = home_addressResult.size();
	 int no_roomLength = no_roomResult.size();
	 int no_bath_roomLength = no_bath_roomResult.size();
	 int max_capacityLength = max_capacityResult.size();

	 int sq_ftLength = sq_ftResult.size();
	 int facilityLength = facilityResult.size();
	 int descriptionLength = descriptionResult.size();
	 int owner_idLength = owner_idResult.size();
	 int day_priceLength = day_priceResult.size();
	 int week_priceLength = week_priceResult.size();

	 int month_priceLength = month_priceResult.size();

	 int totalLength = homeIDLength + home_addressLength + no_roomLength + no_bath_roomLength + max_capacityLength + sq_ftLength + facilityLength + descriptionLength + owner_idLength + day_priceLength + week_priceLength + month_priceLength;


	 
	 
	 //above are display code
//*************

	 home &oldh = *new home();
	 home *newh = new home();




	 ifstream facility_reader("dbhome/facility.txt");
	 string facility_item;
	 string facilityArray[10];
	 int i = 0;
	 while (facility_reader >> facility_item){
		 facilityArray[i] = facility_item;
		 i++;
	 }
	 facility_reader.close();

	 for (int q = 0; q < 10; ++q){
		// cout << facilityArray[q] << endl;
	 }

	 string new_home_id=home_id;
	 string new_home_address;
	 int new_no_room;
	 int new_no_bath_room;
	 int new_max_capacity;

	 double new_sq_ft;
	 string new_facility;
	 string new_description;
	 string new_owner_id;

	 double new_day_price;
	 double new_week_price;
	 double new_month_price;


	 cout << "Please enter the Home with Home-ID You wanted to edit with" << endl;
	 cin >> home_id; cin.ignore(1, '\n');

	 stringstream ss;//stringstream ss;
	 ss << home_id;
	 string home_idS = ss.str();
	 string home_id2 = ss.str();

	 home_id2.append(".txt");
	 string filePortfolio = "dbhome/" + home_id2;
	 std::ifstream homePort(filePortfolio.c_str());

	 bool chk = false;
	

	 cout << "Home-ID";
	 for (int y = 0; y < homeIDLength + 1; y++){
		 cout << " ";
	 }

	 cout << "Home-Address";
	 for (int z = 0; z < (home_addressLength - 8); z++){
		 cout << " ";
	 }
	 cout << "No. of Room";
	 for (int z = 0; z < (no_roomLength + 2); z++){
		 cout << "  ";
	 }
	 cout << "No. of BathRoom";
	 for (int z = 0; z < (no_bath_roomLength + 2); z++){
		 cout << "  ";
	 }
	 cout << "Max Capacity";
	 for (int z = 0; z < (max_capacityLength + 4); z++){
		 cout << "  ";
	 }

	 cout << "Size(Sq ft.)";
	 for (int z = 0; z < (sq_ftLength + 23); z++){
		 cout << " ";
	 }
	 cout << "Facilities";
	 for (int z = 0; z < (facilityLength)+16; z++){
		 cout << " ";
	 }
	 cout << "Description";
	 for (int z = 0; z < (descriptionLength)+2; z++){
		 cout << " ";
	 }
	 cout << "Owner";
	 for (int z = 0; z < (owner_idLength)+4; z++){
		 cout << " ";
	 }

	 cout << "Daily-Price";
	 for (int z = 0; z < (day_priceLength)+4; z++){
		 cout << " ";
	 }
	 cout << "Weekly-Price";
	 for (int z = 0; z < (week_priceLength)+4; z++){
		 cout << " ";
	 }
	 cout << "Monthly-Price";
	 for (int z = 0; z < (month_priceLength); z++){
		 cout << " ";
	 }
	 cout << endl;
	 for (int x = 0; x < (totalLength + 193); x++){
		 cout << "-";
	 }
	 cout << ' ' << endl;


	 
	// ifstream dir1("dbhome/db_home.txt");
	
	 while (homePort >> home_id >> home_address >> no_room >> no_bath_room >> max_capacity >> sq_ft >> facility >> description >> owner_id >> day_price >> week_price >> month_price){



		 cout << home_id;
		 int countid = home_id.size();
		 for (int z = 0; z < (homeIDLength + 2); z++){
			 cout << " ";
		 }

		 cout << home_address;
		 int countAddress = home_address.size();
		 for (int z = 0; z < (home_addressLength - countAddress) + 9; z++){
			 cout << " ";
		 }

		 cout << no_room;
		 stringstream sromcount;
		 sromcount << no_room;
		 string sromcountTemp = sromcount.str();
		 int countroom = sromcountTemp.size();

		 for (int z = 0; z < (no_roomLength)+17; z++){
			 cout << " ";
		 }


		 cout << no_bath_room;
		 stringstream sbathcount;
		 sbathcount << no_bath_room;
		 string sno_bath_roomcountTemp = sbathcount.str();
		 int countBath = sno_bath_roomcountTemp.size();

		 for (int z = 0; z < (no_bath_roomLength)+17; z++){
			 cout << " ";
		 }


		 cout << max_capacity;
		 stringstream smax_capacitycount;
		 smax_capacitycount << max_capacity;
		 string smax_capacitycountTemp = smax_capacitycount.str();
		 int countMaxCapacity = smax_capacitycountTemp.size();

		 for (int z = 0; z < (max_capacityLength)+17; z++){
			 cout << " ";
		 }


		 cout << sq_ft;
		 stringstream ssq_ftcount;
		 ssq_ftcount << sq_ft;
		 string ssq_ftcountTemp = ssq_ftcount.str();
		 int countsq_ft = ssq_ftcountTemp.size();

		 for (int z = 0; z < (sq_ftLength)+20; z++){
			 cout << " ";
		 }



		 cout << facility;
		 int countFacility = facility.size();
		 for (int z = 0; z < (facilityLength - countFacility) + 22; z++){
			 cout << " ";
		 }


		 cout << description;
		 int countDesc = description.size();
		 for (int z = 0; z < (descriptionLength - countDesc) + 28; z++){
			 cout << " ";
		 }

		 cout << owner_id;
		 int countOwner = owner_id.size();
		 for (int z = 0; z < (owner_idLength - countOwner) + 14; z++){
			 cout << " ";
		 }cout << " ";


		 cout << day_price;
		 stringstream sday_pricecount;
		 sday_pricecount << day_price;
		 string sday_pricecountTemp = sday_pricecount.str();
		 int countday_price = sday_pricecountTemp.size();

		 for (int z = 0; z < (day_priceLength - countday_price) + 14; z++){
			 cout << " ";
		 }cout << " ";

		 cout << week_price;
		 stringstream sweek_pricecount;
		 sweek_pricecount << week_price;
		 string sweek_pricecountTemp = sweek_pricecount.str();
		 int countweek_price = sweek_pricecountTemp.size();

		 for (int z = 0; z < (week_priceLength - countweek_price) + 14; z++){
			 cout << " ";
		 }cout << " ";



		 cout << month_price << endl;
		 stringstream smonth_pricecount;
		 smonth_pricecount << month_price;
		 string smonth_pricecountTemp = smonth_pricecount.str();
		 int countmonth_price = smonth_pricecountTemp.size();


	 }
	 homePort.close();
	 string decision;
	 //			client newClient;
	 //		client newClientPointer;// = &newClient;


	 cout << "Update this homestay info...[y/n]" << endl;
	 cin >> decision;
	 cin.ignore(1, '\n');

	 if (decision == "y" || decision == "Y"){

		 string l_home = "";
		 int home_number_of_lines = 0;
		 ifstream readLineHome("dbhome/db_home.txt");
		 if (readLineHome.is_open()){
			 while (!readLineHome.eof()){
				 getline(readLineHome, l_home);
				 // cout << l << endl;
				 home_number_of_lines++;
			 }
			 // myfile.close();
		 }readLineHome.close();
		 new_home_id = "home" + toString(home_number_of_lines);

		 cout << "Enter the new location of the House for rent:" << endl;
		// cin.get();
		 getline(cin, new_home_address);


		 get_Num_Rooms(&new_no_room, "bedroom");
		 get_Num_Rooms(&new_no_bath_room, "bathroom");
		 get_Num_Rooms(&new_max_capacity, "max capacity of the room");


		 cout << "How big is the room? (in square feet) sq.ft." << endl;
		 cin >> new_sq_ft; cin.ignore(1, '\n');

		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  number." << endl;

			 std::cout << "Enter the size of room in squre.feet again--(Last chance to enter)" << endl;

			 cin >> new_sq_ft; cin.ignore(1, '\n');


			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  number." << endl;
			 }

		 }


		 bool loop = true;
		 char choice;
		 int switchCase;
		 int z = 0;
		 string chosenFacility[5];
		 while (loop && z<5){

			 cout << "What facilities the house owns? Choose at the menu below...(choose 5(max))" << endl;
			 cout << "1." + facility[0] << ' ' << "2." + facility[1] << ' ' << "3." + facility[2] << ' ' << "4." + facility[3] << ' ' << "5." + facility[4] << ' ' << "6." + facility[5] << ' ' << "7." + facility[6] << ' ' << "8." + facility[7] << ' ' << "9." + facility[8] << ' ' << "10." + facility[9] << endl;

			 cin >> switchCase; cin.ignore(1, '\n');

			 --switchCase;
			 chosenFacility[z] = facility[switchCase];

			 //getline(cin, chosenFacility[z]);


			 cout << "Enough?[Y/N], Maximum 5, if want more, contact staff...(0166028563)" << endl;
			 cin >> choice;
			 cin.ignore(1, '\n');


			 if (choice == 'y' || choice == 'Y' || z >= 5){
				 loop = false;
			 }
			 else if (z < 5 || choice == 'n' || choice == 'N'){
				 loop = true;
				 ++z;

			 }

		 }








		 for (int w = 0; w < chosenFacility[w].length(); w++){
			 new_facility = new_facility + "+" + chosenFacility[w];
		 }


	 StartAgain:

		 cout << "Write a description about the house/room (Max 50 words)" << endl;
		 cin.get();
		 getline(cin, new_description);
		 char Fchars[50]; for (int a = 0; a <= new_description.size(); a++){ Fchars[a] = new_description[a]; }

		 int size = strlen(Fchars);
		 if (size >= 50)
		 {
			 cout << "max allowed size is 50 char" << endl;
			 goto StartAgain;
		 }


			//select owner id
		 //*************
		 string l = "";
		 int number_of_lines = 0;
		 ifstream readLine("dbclient/db_client.txt");
		 if (readLine.is_open()){
			 while (!readLine.eof()){
				 getline(readLine, l);
				 // cout << l << endl;
				 number_of_lines++;
			 }
			 // myfile.close();
		 }readLine.close();

		 // cout << number_of_lines << endl;

		 cout << endl; cout << endl;


		 //now ask staff to choose the owner id
		 ifstream readOwnerId("dbclient/db_client.txt");
		 client c[100];
		 string ownerID;
		 string ownerName; string ownerIC; string ownerContact; string ownerEmail; string ownerAddress;
		 string ownerBankAcct; string ownerBank; string ownerCredit; string ownerPwd;
		 int m = 0;
		 while (readOwnerId >> ownerID >> ownerName >> ownerIC >> ownerContact >> ownerEmail >> ownerAddress >> ownerBankAcct >> ownerBank >> ownerCredit >> ownerPwd){
			 //cout << ownerID << endl;
			 c[m].setClientID(ownerID);
			 m++;
		 }readOwnerId.close();
		 cout << "Following are the list of Owner's ID, select  one to update this home of post..." << endl;
		 cout << "Please Choose one by entering number of specific..." << endl;
		 int iterator = 0;
		 int countChoice;
		 while (iterator < number_of_lines){
			 cout << iterator << " : " << c[iterator].getClientID() << endl;
			 ++iterator;
		 }
		 cin >> countChoice;
		 cout << "So you have chosen the owner ID:" + c[countChoice].getClientID() +" for this home post"<< endl;
		 new_owner_id = c[countChoice].getClientID();

		 cout << endl; cout << endl;
		 //**************
		

		// new_owner_id = sta.sessionID;


		 cout << "How much the room/house would be cost for daily-renting(cost per day in RM) [?RM/day]" << endl;
		 cin >> new_day_price; cin.ignore(1, '\n');

		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of daily rental in RM--(Last chance to enter)" << endl;

			 cin >> new_day_price; cin.ignore(1, '\n');


			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }

		 cout << "How much the room/house would be cost for weekly-renting(cost per day in RM) [?RM/week]" << endl;
		 cin >> new_week_price; cin.ignore(1, '\n');

		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of weekly rental in RM--(Last chance to enter)" << endl;

			 cin >> new_week_price;
			 cin.ignore(1, '\n');

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }


		 cout << "How much the room/house would be cost for monthly-renting(cost per day in RM) [?RM/month]" << endl;
		 cin >> new_month_price; cin.ignore(1, '\n');

		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of monthly rental in RM--(Last chance to enter)" << endl;

			 cin >> new_month_price; cin.ignore(1, '\n');


			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }


		 newh->setHome(home_id, new_home_address, new_no_room, new_no_bath_room, new_max_capacity, new_sq_ft, new_facility,new_description,new_owner_id,new_day_price,new_week_price,new_month_price );
		//home_id not change!

		 ofstream tempPofolio("dbhome/tempPofolio.txt");

		 ofstream temp("dbhome/temp.txt");
		 ifstream homeD("dbhome/db_home.txt");
		 if (tempPofolio.is_open() && homeD.is_open() && temp.is_open()){

			 string line;
			 while (getline(homeD, line))
			 {
				 if (line.find(home_idS) == string::npos) { //str.find(str2) != string::npos
					 temp << line << endl;

				 }
				 else
				 {

					 tempPofolio << space_underscore(newh->getHomeID()) << ' ' << space_underscore(newh->getHomeAddress()) << ' ' << space_underscore(toString(newh->getNoRoom())) << ' ' << space_underscore(toString(newh->getNoBathRoom())) << ' ' << space_underscore(toString(newh->getMaxCapacity())) << ' ' << space_underscore(toString(newh->getSizeSqFt())) << ' ' << space_underscore(newh->facility) << ' ' << space_underscore(newh->description) << ' ' << space_underscore(toString(newh->owner_id)) << ' ' << space_underscore(toString(newh->day_price)) << ' ' << space_underscore(toString(newh->week_price)) << ' ' << space_underscore(toString(newh->month_price)) << endl;
					 temp << space_underscore(newh->getHomeID()) << ' ' << space_underscore(newh->getHomeAddress()) << ' ' << space_underscore(toString(newh->getNoRoom())) << ' ' << space_underscore(toString(newh->getNoBathRoom())) << ' ' << space_underscore(toString(newh->getMaxCapacity())) << ' ' << space_underscore(toString(newh->getSizeSqFt())) << ' ' << space_underscore(newh->facility) << ' ' << space_underscore(newh->description) << ' ' << space_underscore(toString(newh->owner_id)) << ' ' << space_underscore(toString(newh->day_price)) << ' ' << space_underscore(toString(newh->week_price)) << ' ' << space_underscore(toString(newh->month_price)) << endl;
				 }
			 }

		 }
		 tempPofolio.close();
		 homePort.close();
		 homeD.close();

		 temp.close();


		 string db_old_file = "dbhome/db_home.txt";

		// const char *data = "dbhome/db_home.txt";
		 remove(db_old_file.c_str());//delete the old db file first


		 //system("del dbclient/db_client.txt");
		 remove(filePortfolio.c_str());

		 rename("dbhome/tempPofolio.txt", filePortfolio.c_str());
		 rename("dbhome/temp.txt", "dbhome/db_home.txt");
		 //******

		 cout << "You have updated the "+home_id+" ";
	 }
	 else{
		 manage_home();
	 }



	 system("pause");
	 manage_home();
 }
 void staff::list_home(){

	 string home_id;
	 string home_address;
	 int no_room;
	 int no_bath_room;
	 int max_capacity;

	 double sq_ft;
	 string facility;
	 string description;
	 string owner_id;

	 double day_price;
	 double week_price;
	 double month_price;

	 cout << "*************************************************************" << endl;
	 cout << "-------------Felice HomeStay Renting Platform----------------" << endl;
	 cout << "*************************************************************" << endl;
	 //user *user_view;
	 //user_view->view_home();

	 ifstream dir("dbhome/db_home.txt");


	 string home_idResult = "";
	 string home_addressResult = "";
	 string no_roomResult = ""; string no_bath_roomResult = ""; string max_capacityResult = "";

	 string sq_ftResult = "";

	 string facilityResult = "";
	 string descriptionResult = "";
	 string owner_idResult = "";

	 string day_priceResult = ""; string week_priceResult = ""; string month_priceResult = "";


	 while (dir >> home_id >> home_address >> no_room >> no_bath_room >> max_capacity >> sq_ft >> facility >> description >> owner_id >> day_price >> week_price >> month_price){

		 //these approach make sure the length are the longest
		 if (home_id.length() > home_idResult.length()){
			 home_idResult = home_id;
		 }

		 if (home_address.length() > home_addressResult.length()){
			 home_addressResult = home_address;
		 }


		 stringstream sss;
		 sss << no_room;
		 string no_rooms = sss.str();
		 if (no_rooms.length()>no_roomResult.length()){
			 no_roomResult = no_rooms;
		 }

		 stringstream sbath;
		 sbath << no_bath_room;
		 string no_bath_rooms = sbath.str();
		 if (no_bath_rooms.length()>no_bath_roomResult.length()){
			 no_bath_roomResult = no_bath_rooms;
		 }

		 stringstream scapacity;
		 scapacity << max_capacity;
		 string max_capacitys = scapacity.str();
		 if (max_capacitys.length()>max_capacityResult.length()){
			 max_capacityResult = max_capacitys;
		 }

		 stringstream ssqft;
		 ssqft << sq_ft;
		 string sq_fts = ssqft.str();
		 if (sq_fts.length()>sq_ftResult.length()){
			 sq_ftResult = sq_fts;
		 }


		 if (facility.length() > facilityResult.length()){
			 facilityResult = facility;
		 }


		 if (description.length() > descriptionResult.length()){
			 descriptionResult = description;
		 }
		 if (owner_id.length() > owner_idResult.length()){
			 owner_idResult = owner_id;
		 }

		 stringstream sss_day_price;
		 sss_day_price << day_price;
		 string day_prices = sss_day_price.str();
		 if (day_prices.length()>day_priceResult.length()){
			 day_priceResult = day_prices;
		 }

		 stringstream sss_week_price;
		 sss_week_price << week_price;
		 string week_prices = sss_week_price.str();
		 if (week_prices.length()>week_priceResult.length()){
			 week_priceResult = week_prices;
		 }

		 stringstream sss_month_price;
		 sss_month_price << month_price;
		 string month_prices = sss_month_price.str();
		 if (month_prices.length()>month_priceResult.length()){
			 month_priceResult = month_prices;
		 }




	 }dir.close();



	 int homeIDLength = home_idResult.size();
	 int home_addressLength = home_addressResult.size();
	 int no_roomLength = no_roomResult.size();
	 int no_bath_roomLength = no_bath_roomResult.size();
	 int max_capacityLength = max_capacityResult.size();

	 int sq_ftLength = sq_ftResult.size();
	 int facilityLength = facilityResult.size();
	 int descriptionLength = descriptionResult.size();
	 int owner_idLength = owner_idResult.size();
	 int day_priceLength = day_priceResult.size();
	 int week_priceLength = week_priceResult.size();

	 int month_priceLength = month_priceResult.size();

	 int totalLength = homeIDLength + home_addressLength + no_roomLength + no_bath_roomLength + max_capacityLength + sq_ftLength + facilityLength + descriptionLength + owner_idLength + day_priceLength + week_priceLength + month_priceLength;


	 cout << "Home-ID";
	 for (int y = 0; y < homeIDLength + 1; y++){
		 cout << " ";
	 }

	 cout << "Home-Address";
	 for (int z = 0; z < (home_addressLength - 8); z++){
		 cout << " ";
	 }
	 cout << "No. of Room";
	 for (int z = 0; z < (no_roomLength + 2); z++){
		 cout << "  ";
	 }
	 cout << "No. of BathRoom";
	 for (int z = 0; z < (no_bath_roomLength + 2); z++){
		 cout << "  ";
	 }
	 cout << "Max Capacity";
	 for (int z = 0; z < (max_capacityLength + 4); z++){
		 cout << "  ";
	 }

	 cout << "Size(Sq ft.)";
	 for (int z = 0; z < (sq_ftLength + 23); z++){
		 cout << " ";
	 }
	 cout << "Facilities";
	 for (int z = 0; z < (facilityLength)+16; z++){
		 cout << " ";
	 }
	 cout << "Description";
	 for (int z = 0; z < (descriptionLength)+2; z++){
		 cout << " ";
	 }
	 cout << "Owner";
	 for (int z = 0; z < (owner_idLength)+4; z++){
		 cout << " ";
	 }

	 cout << "Daily-Price";
	 for (int z = 0; z < (day_priceLength)+4; z++){
		 cout << " ";
	 }
	 cout << "Weekly-Price";
	 for (int z = 0; z < (week_priceLength)+4; z++){
		 cout << " ";
	 }
	 cout << "Monthly-Price";
	 for (int z = 0; z < (month_priceLength); z++){
		 cout << " ";
	 }
	 cout << endl;
	 for (int x = 0; x < (totalLength + 193); x++){
		 cout << "-";
	 }
	 cout << ' ' << endl;


	 ifstream dir1("dbhome/db_home.txt");

	 while (dir1 >> home_id >> home_address >> no_room >> no_bath_room >> max_capacity >> sq_ft >> facility >> description >> owner_id >> day_price >> week_price >> month_price){



		 cout << home_id;
		 int countid = home_id.size();
		 for (int z = 0; z < (homeIDLength + 2); z++){
			 cout << " ";
		 }

		 cout << home_address;
		 int countAddress = home_address.size();
		 for (int z = 0; z < (home_addressLength - countAddress) + 9; z++){
			 cout << " ";
		 }

		 cout << no_room;
		 stringstream sromcount;
		 sromcount << no_room;
		 string sromcountTemp = sromcount.str();
		 int countroom = sromcountTemp.size();

		 for (int z = 0; z < (no_roomLength)+17; z++){
			 cout << " ";
		 }


		 cout << no_bath_room;
		 stringstream sbathcount;
		 sbathcount << no_bath_room;
		 string sno_bath_roomcountTemp = sbathcount.str();
		 int countBath = sno_bath_roomcountTemp.size();

		 for (int z = 0; z < (no_bath_roomLength)+17; z++){
			 cout << " ";
		 }


		 cout << max_capacity;
		 stringstream smax_capacitycount;
		 smax_capacitycount << max_capacity;
		 string smax_capacitycountTemp = smax_capacitycount.str();
		 int countMaxCapacity = smax_capacitycountTemp.size();

		 for (int z = 0; z < (max_capacityLength)+17; z++){
			 cout << " ";
		 }


		 cout << sq_ft;
		 stringstream ssq_ftcount;
		 ssq_ftcount << sq_ft;
		 string ssq_ftcountTemp = ssq_ftcount.str();
		 int countsq_ft = ssq_ftcountTemp.size();

		 for (int z = 0; z < (sq_ftLength)+20; z++){
			 cout << " ";
		 }



		 cout << facility;
		 int countFacility = facility.size();
		 for (int z = 0; z < (facilityLength - countFacility) + 22; z++){
			 cout << " ";
		 }


		 cout << description;
		 int countDesc = description.size();
		 for (int z = 0; z < (descriptionLength - countDesc) + 28; z++){
			 cout << " ";
		 }

		 cout << owner_id;
		 int countOwner = owner_id.size();
		 for (int z = 0; z < (owner_idLength - countOwner) + 14; z++){
			 cout << " ";
		 }cout << " ";


		 cout << day_price;
		 stringstream sday_pricecount;
		 sday_pricecount << day_price;
		 string sday_pricecountTemp = sday_pricecount.str();
		 int countday_price = sday_pricecountTemp.size();

		 for (int z = 0; z < (day_priceLength - countday_price) + 14; z++){
			 cout << " ";
		 }cout << " ";

		 cout << week_price;
		 stringstream sweek_pricecount;
		 sweek_pricecount << week_price;
		 string sweek_pricecountTemp = sweek_pricecount.str();
		 int countweek_price = sweek_pricecountTemp.size();

		 for (int z = 0; z < (week_priceLength - countweek_price) + 14; z++){
			 cout << " ";
		 }cout << " ";



		 cout << month_price << endl;
		 stringstream smonth_pricecount;
		 smonth_pricecount << month_price;
		 string smonth_pricecountTemp = smonth_pricecount.str();
		 int countmonth_price = smonth_pricecountTemp.size();




	 }

	 dir1.close();




	 system("pause");
	 manage_home();
 
 }
 void staff::delete_home(){

	 system("cls");
	 //system("pause");



	 string home_id; string home_address;
	 int no_room; int no_bath_room; int max_capacity;

	 double sq_ft;

	 string facility;
	 string description;
	 string owner_id;

	 double day_price; double week_price; double month_price;



	 string decision;

	 cout << "Enter Home ID need to be deleted:";
	 cin >> home_id;
	 stringstream ss;//stringstream ss;
	 ss << home_id;
	 string home_idS = ss.str();
	 string home_id2 = ss.str();



	 home *homeObj = new home();
	 homeObj->setHomeID(home_id);


	 // booking *vectorBooking = new booking[100];
	 string BookingObj[100];
	 // string &list[100]= *new string()[];
	 home::delete_home_compositionBooking(BookingObj, *homeObj);//composition logic

	 /*
	 home_id2.append(".txt");

	 string portfolioFile = "dbhome/" + home_id2;

	 bool chk = false;
	 ifstream validate("dbhome/db_home.txt");
	 while (validate >> home_id >> home_address >> no_room >> no_bath_room >> max_capacity >> sq_ft >> facility >> description >> owner_id >> day_price >> week_price >> month_price){
		 stringstream chks;
		 chks << home_id;
		 string sthrw = chks.str();
		 if (home_idS == sthrw){
			 cout << "The Home Id has found!" << endl;
			 chk = true;
		 }

	 }
	 if (!chk){
		 cout << "The Home Id is not exist!" << endl;

	 }
	 validate.close();


	 ifstream dir(portfolioFile.c_str());


	 string home_id_r = "";
	 string home_address_r = "";
	 string home_no_room_r = "";
	 string home_no_bath_room_r = "";
	 string home_max_capacity_r = "";
	 string home_sq_ft_r = "";
	 string home_facility_r = "";
	 string home_description_r = "";
	 string home_owner_id_r = "";
	 string home_day_price_r = "";
	 string home_week_price_r = "";
	 string home_month_price_r = "";


	 while (dir >> home_id >> home_address >> no_room >> no_bath_room >> max_capacity >> sq_ft >> facility >> description >> owner_id >> day_price >> week_price >> month_price){

		 if (home_id.length() > home_id_r.length()){ home_id_r = home_id; }
		 if (home_address.length() > home_address_r.length()){ home_address_r = home_address; }

		// if (toString(no_room).length() > home_no_room_r.length()){ home_no_room_r = no_room; }
		// if (toString(no_bath_room).length() > home_no_bath_room_r.length()){ home_no_bath_room_r = no_bath_room; }
		// if (toString(max_capacity).length() > home_max_capacity_r.length()){ home_max_capacity_r = max_capacity; }
		// if (toString(sq_ft).length() > home_sq_ft_r.length()){ home_sq_ft_r = sq_ft; }
		 if (facility.length() > home_facility_r.length()){ home_facility_r = facility; }
		 if (description.length() > home_description_r.length()){ home_description_r = description; }
		 //if (client_credit.length() > client_credit_r.length()){ client_credit_r = client_credit; }
		 if (owner_id.length() > home_owner_id_r.length()){ home_owner_id_r = owner_id; }

		// if (toString(day_price).length() > home_day_price_r.length()){ home_day_price_r = day_price; }

		// if (toString(week_price).length() > home_week_price_r.length()){ home_week_price_r = week_price; }

		// if (toString(month_price).length() > home_month_price_r.length()){ home_month_price_r = month_price; }


		 //cpointer =  client(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

		 cout << "Is this the Home Info that you wish to delete?[y/n]" << endl;
		 cout << home_id << " " << home_address << " " << no_room << " " << no_bath_room << " " << max_capacity << " " << sq_ft << " " << facility << " " << description << " " << day_price << " " << week_price << " " << month_price << endl;
		 cin >> decision;
		 if (decision == "y" || decision == "Y"){
			 system("cls");
			 cout << "Current information:" << endl;

			 cout << "Home-ID";
			 for (int y = 0; y < home_id_r.length() + 1; y++){
				 cout << " ";
			 }

			 cout << "Home-Address";
			 for (int z = 0; z < (home_address_r.length() - 8); z++){
				 cout << " ";
			 }
			 cout << "No. of Room";
			 for (int z = 0; z < (home_no_room_r.length() + 2); z++){
				 cout << "  ";
			 }
			 cout << "No. of BathRoom";
			 for (int z = 0; z < (home_no_bath_room_r.length() + 2); z++){
				 cout << "  ";
			 }
			 cout << "Max Capacity";
			 for (int z = 0; z < (home_max_capacity_r.length() + 4); z++){
				 cout << "  ";
			 }

			 cout << "Size(Sq ft.)";
			 for (int z = 0; z < (home_sq_ft_r.length() + 23); z++){
				 cout << " ";
			 }
			 cout << "Facilities";
			 for (int z = 0; z < (home_facility_r.length()) + 16; z++){
				 cout << " ";
			 }
			 cout << "Description";
			 for (int z = 0; z < (home_description_r.length()) + 2; z++){
				 cout << " ";
			 }
			 cout << "Owner";
			 for (int z = 0; z < (home_owner_id_r.length()) + 4; z++){
				 cout << " ";
			 }

			 cout << "Daily-Price";
			 for (int z = 0; z < (home_day_price_r.length()) + 4; z++){
				 cout << " ";
			 }
			 cout << "Weekly-Price";
			 for (int z = 0; z < (home_week_price_r.length()) + 4; z++){
				 cout << " ";
			 }
			 cout << "Monthly-Price";
			 for (int z = 0; z < (home_month_price_r.length()); z++){
				 cout << " ";
			 }
			 int totalLength = home_month_price_r.length() + home_week_price_r.length() + home_day_price_r.length() + home_owner_id_r.length() + home_description_r.length() + home_facility_r.length() + home_sq_ft_r.length() + home_max_capacity_r.length() + home_no_bath_room_r.length() + home_no_room_r.length();
			 cout << endl;
			 for (int x = 0; x < (totalLength + 193); x++){
				 cout << "-";
			 }
			 cout << ' ' << endl;


			 cout << home_id;
			 for (int y = 0; y < ((home_id_r.length() - home_id.length()) + 16); y++){
				 cout << " ";
			 }
			 cout << home_address;
			 for (int z = 0; z < (home_address_r.length() - home_address.length() + 20); z++){
				 cout << " ";
			 }
			 cout << no_room;
			 for (int z = 0; z < (home_no_room_r.length() + 16); z++){
				 cout << " ";
			 }
			 cout << no_bath_room;
			 for (int z = 0; z < (home_no_bath_room_r.length() + 8); z++){
				 cout << " ";
			 }
			 cout << max_capacity;
			 for (int z = 0; z < (home_max_capacity_r.length()  + 16); z++){
				 cout << " ";
			 }
			 cout << sq_ft;
			 for (int z = 0; z < (home_sq_ft_r.length()+ 22); z++){
				 cout << " ";
			 }

			 cout << facility;
			 for (int z = 0; z < (home_facility_r.length() - facility.length() + 14); z++){
				 cout << " ";
			 }
			 cout << description;
			 for (int z = 0; z < (home_description_r.length() - description.length() + 14); z++){
				 cout << " ";
			 }

			 cout << owner_id;
			 for (int z = 0; z < (home_owner_id_r.length() + 16); z++){
				 cout << " ";
			 }

			 cout << day_price;
			 for (int z = 0; z < (home_day_price_r.length() +4); z++){
				 cout << " ";
			 }
			 cout << week_price;
			 for (int z = 0; z < (home_week_price_r.length() +4); z++){
				 cout << " ";
			 }
			 cout << month_price;
			 for (int z = 0; z < (home_month_price_r.length() ); z++){
				 cout << " ";
			 }

			 cout << endl;



			 //print out original data

		 }
		 if (decision == "n"){
			 staff::manage_home();
		 }


		 cout << "Do you wish to delete this home data from the database?[y/n]" << endl;
		 cin >> decision;
		 if (decision == "y" || decision == "Y"){



			 ofstream temp("dbhome/temp.txt");
			 ifstream homeD("dbhome/db_home.txt");
			 if (homeD.is_open() && temp.is_open()){

				 string line;
				 while (getline(homeD, line))
				 {
					 if (line.find(home_idS) == string::npos) { //str.find(str2) != string::npos =-1  means not found
						 //only copy data that is not the key have entered!
						 temp << line << endl;//copy&write to temp

					 }
					 else if (line.find(home_id) != string::npos)
					 {

						 //do nothing , and not copy to the new database file so that we deleted the intended row in our new db
					 }
				 }

			 }


			 homeD.close();


			 temp.close();

			 dir.close();
			 string db_old_file = "dbhome/db_home.txt";
			 //system("del dbstaff/db_staff.txt");
			// const char *data = "dbhome/db_home.txt";
			 remove(db_old_file.c_str());//delete the old db file first
			 //system("del dbstaff/db_staff");



			 const char *data = portfolioFile.c_str();
			 remove(data);
			 //portfolioFile
			 rename("dbhome/temp.txt", "dbhome/db_home.txt");


		 }


		 system("pause");
		 manage_home();
	 }		


	 */


		
	 system("pause");
	 manage_home();

 }
 void staff::new_home_new_client(){
 
	 
	 system("cls");
	 cout << "-----------Welcome staff: " + sta.sessionNAME + "-----------" << endl;
	 cout << "-----------Home Management Console----------" << endl;
	 system("color 0f");
	 cout << "Please enter your choice" << endl;
	 cout << "1.Add a New Home with existing client" << endl;
	 cout << "2.Add new home with new client" << endl;


	 cout << "3.<<Back" << endl;

	 int choice;
	 cin >> choice;

	 switch (choice){
	 case 1:
		 new_home_existing_client();
		 break;
	 case 2:
		 new_homw_newOwner();
		 break;
	 case 3:
		 manage_home();
		 break;
	 default:
		 manage_home();
		 break;
	 }


	 system("pause");
	 manage_home();
 }



	 void staff::new_home_existing_client(){
		 
		 ifstream aFile("dbhome/db_home.txt");
		 size_t lines_count = std::count(istreambuf_iterator<char>(aFile),
			 std::istreambuf_iterator<char>(), '\n');
		 int current_row = lines_count;//
		 int new_home_row = ++current_row;

		 string newHomeID = "home" + toString(new_home_row);//set the new home id
		 aFile.close();
		 //prompt menu to user
		 string home_id; string home_address;
		 int no_room; int no_bath_room; int max_capacity;

		 double sq_ft;

		 ifstream facility_reader("dbhome/facility.txt");
		 string facility_item;
		 string facility[10];
		 int i = 0;
		 while (facility_reader >> facility_item){
			 facility[i] = facility_item;
			 i++;
		 }
		 facility_reader.close();

		 for (int q = 0; q < 10; ++q){
			 cout << facility[q] << endl;
		 }

		 string facility_need_store;
		 string description;
		 string owner_id;

		 double day_price; double week_price; double month_price;


		 system("cls");
		 cout << "-----------Welcome staff: " + sta.sessionNAME + "-----------" << endl;
		 cout << "-----------Home Management Console----------" << endl;
		 system("color 0f");

		 cout << "Where is the location of the House for rent?" << endl;
		 cin.get();
		 getline(cin, home_address);


		 get_Num_Rooms(&no_room, "bedroom");
		 get_Num_Rooms(&no_bath_room, "bathroom");
		 get_Num_Rooms(&max_capacity, "max capacity of the room");


		 cout << "How big is the room? (in square feet) sq.ft." << endl;
		 cin >> sq_ft;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  number." << endl;

			 std::cout << "Enter the size of room in squre.feet again--(Last chance to enter)" << endl;

			 cin >> sq_ft;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  number." << endl;
			 }

		 }

		 bool loop = true;
		 char choice;
		 int switchCase;
		 int z = 0;
		 string chosenFacility[5];
		 while (loop && z<5){

			 cout << "What facilities the house owns? Choose at the menu below...(choose 5(max))" << endl;
			 cout << "1." + facility[0] << ' ' << "2." + facility[1] << ' ' << "3." + facility[2] << ' ' << "4." + facility[3] << ' ' << "5." + facility[4] << ' ' << "6." + facility[5] << ' ' << "7." + facility[6] << ' ' << "8." + facility[7] << ' ' << "9." + facility[8] << ' ' << "10." + facility[9] << endl;

			 cin >> switchCase;
			 --switchCase;
			 chosenFacility[z] = facility[switchCase];

			 //getline(cin, chosenFacility[z]);


			 cout << "Enough?[Y/N], Maximum 5, if want more, contact staff...(0166028563)" << endl;
			 cin >> choice;


			 if (choice == 'y' || choice == 'Y' || z >= 5){
				 loop = false;
			 }
			 else if (z < 5 || choice == 'n' || choice == 'N'){
				 loop = true;
				 ++z;

			 }

		 }




		 cout << endl; cout << endl;



		 for (int w = 0; w < chosenFacility[w].length(); w++){
			 facility_need_store = facility_need_store + "+" + chosenFacility[w];
		 }


	 StartAgain:

		 cout << "Write a description about the house/room (Max 50 words)" << endl;
		 cin.get();
		 getline(cin, description);
		 char Fchars[50]; for (int a = 0; a <= description.size(); a++){ Fchars[a] = description[a]; }

		 int size = strlen(Fchars);
		 if (size >= 50)
		 {
			 cout << "max allowed size is 50 char" << endl;
			 goto StartAgain;
		 }

	 enterAgain:

		 
		 string l = "";
		 int number_of_lines = 0;
		 ifstream readLine("dbclient/db_client.txt");
		 if (readLine.is_open()){
			 while (!readLine.eof()){
				 getline(readLine, l);
				// cout << l << endl;
				 number_of_lines++;
			 }
			 // myfile.close();
		 }readLine.close();

		// cout << number_of_lines << endl;
		 
		 cout << endl; cout << endl;


		 //now ask staff to choose the owner id
		 ifstream readOwnerId("dbclient/db_client.txt");
		 client c[100];
		 string ownerID;
		 string ownerName; string ownerIC; string ownerContact; string ownerEmail; string ownerAddress;
		 string ownerBankAcct; string ownerBank; string ownerCredit; string ownerPwd;
		 int m=0;
		 while (readOwnerId >> ownerID >> ownerName >> ownerIC >> ownerContact >> ownerEmail >> ownerAddress >> ownerBankAcct >> ownerBank >> ownerCredit >> ownerPwd){
			// cout << ownerID << endl;
			 c[m].setClientID(ownerID);
			 m++;
		 }readOwnerId.close();
		 cout << "Following are the list of Owner's ID, You must set one to this home of post..." << endl;
		 cout << "Please Choose one by entering number of specific..." << endl;
		 int iterator = 1;
		 int countChoice;
		 --number_of_lines;
		 while (iterator<=number_of_lines){
			 cout << iterator << " : ";
			 cout<< c[--iterator].getClientID() << endl; ++iterator;
			 ++iterator;
		 }
		 cin >> countChoice;
		 bool ok=true;
		 if (cin.fail()){
			 cin.clear();
			 cin.ignore();
			 cout << "Please reenter Client ID Again" << endl;
			 cin >> countChoice;
			 if (cin.fail()){
				 ok = false;
				 cin.clear();
				 cin.ignore();
				 cout << "Please reenter Client ID Again! only the displayed ID are accepted!(last chance)" << endl;
				 cin >> countChoice;
			 }
		 }
		 if (!ok){ 
			 goto enterAgain;
		 }
		 --countChoice;
		 cout << "So you have chosen the owner ID:" + c[countChoice].getClientID() << endl;
		 owner_id = c[countChoice].getClientID();

		 cout << endl; cout << endl;


		 cout << "How much the room/house would be cost for daily-renting(cost per day in RM) [?RM/day]" << endl;
		 cin >> day_price;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of daily rental in RM--(Last chance to enter)" << endl;

			 cin >> day_price;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }
		 cout << endl; 


		 cout << "How much the room/house would be cost for weekly-renting(cost per day in RM) [?RM/week]" << endl;
		 cin >> week_price;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of weekly rental in RM--(Last chance to enter)" << endl;

			 cin >> week_price;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }
		 cout << endl; 


		 cout << "How much the room/house would be cost for monthly-renting(cost per day in RM) [?RM/month]" << endl;
		 cin >> month_price;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of monthly rental in RM--(Last chance to enter)" << endl;

			 cin >> month_price;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }


		 home *homeObj = new home(newHomeID, home_address, no_room, no_bath_room, max_capacity, sq_ft, facility_need_store, description, owner_id, day_price, week_price, month_price);

		 string homeDB = newHomeID.append(".txt");

		 string newHomePortfolio = "dbhome/" + homeDB;


		 ofstream newHome(newHomePortfolio.c_str());
		 newHome << homeObj->getHomeID() << ' ' << space_underscore(homeObj->getHomeAddress()) << ' ' << homeObj->getNoRoom() << ' ' << homeObj->getNoBathRoom() << ' ' << homeObj->getMaxCapacity() << ' ' << homeObj->getSizeSqFt() << ' ' << space_underscore(homeObj->facility) << ' ' << space_underscore(homeObj->description) << ' ' << homeObj->owner_id << ' ' << homeObj->day_price << ' ' << homeObj->week_price << ' ' << homeObj->month_price << endl;
		 newHome.close();

		 ofstream dir("dbhome/db_home.txt", ios::app);
		 dir << homeObj->getHomeID() << ' ' << space_underscore(homeObj->getHomeAddress()) << ' ' << homeObj->getNoRoom() << ' ' << homeObj->getNoBathRoom() << ' ' << homeObj->getMaxCapacity() << ' ' << homeObj->getSizeSqFt() << ' ' << space_underscore(homeObj->facility) << ' ' << space_underscore(homeObj->description) << ' ' << homeObj->owner_id << ' ' << homeObj->day_price << ' ' << homeObj->week_price << ' ' << homeObj->month_price << endl;
		 dir.close();
		 cout << "You have just added a home at '" + homeObj->getHomeAddress() + "' with home ID: '" + newHomeID + "'" << endl;





	 
	 }


	 void staff::new_homw_newOwner(){

		 //here is the aggregation came in, the home it belongs to an owner, but the relationship is not strong like composition
		 //the owner still exists even the home is not there

		 //here the instatiation of home will instantiate a new obj of owner(client)


		 ifstream aFile("dbhome/db_home.txt");
		 size_t lines_count = std::count(istreambuf_iterator<char>(aFile),
			 std::istreambuf_iterator<char>(), '\n');
		 int current_row = lines_count;//
		 int new_home_row = ++current_row;

		 string newHomeID = "home" + toString(new_home_row);//set the new home id
		 aFile.close();
		 //prompt menu to user
		 string home_id; string home_address;
		 int no_room; int no_bath_room; int max_capacity;

		 double sq_ft;

		 ifstream facility_reader("dbhome/facility.txt");
		 string facility_item;
		 string facility[10];
		 int i = 0;
		 while (facility_reader >> facility_item){
			 facility[i] = facility_item;
			 i++;
		 }
		 facility_reader.close();

		 for (int q = 0; q < 10; ++q){
			 cout << facility[q] << endl;
		 }

		 string facility_need_store;
		 string description;
		 string owner_id;

		 double day_price; double week_price; double month_price;


		 system("cls");
		 cout << "-----------Welcome staff: " + sta.sessionNAME + "-----------" << endl;
		 cout << "-----------Home Management Console----------" << endl;
		 system("color 0f");




		 //*******user creation

		 client *c = new client();
		 string client_id;
		 string client_name;
		 string client_ic;
		 string client_contact;
		 string client_email;
		 string client_address;
		 string client_bank_account;
		 string client_bank;
		 double client_credit;//default=0
		 string client_pwd;//default=password
		 //!!!!!!!!!!!!!pending, add locatio nad sdtomer_od
		 string choiceCREDIT;
		 string choicePWD;
		 string fileName;

		 cout << "Now enter the Owner information for the room"<<endl;
		 cout << "Input Client ID:";
		 cin >> client_id;
		 cout << "Input Client Name:";
		 cin.get();
		 getline(cin, client_name);
		
		 cout << "Input Client IC:";
	
		 getline(cin, client_ic);
		


		 cout << client_ic << endl;
		 cout << "Input Client Contact:";
		 getline(cin, client_contact);
		 // cin >> client_contact;
		 cout << "Input Client Email:";
		 getline(cin, client_email);
		 // cin >> client_email;
		 cout << "Input Client Address:";
		 getline(cin, client_address);



		 cout << "Input Client Bank:";
		 getline(cin, client_bank);
		 cout << "Input " + client_bank + "-Bank Account Number:";
		 getline(cin, client_bank_account);
		 //cin >> client_bank_account;
		 cout << "Want Give This Client credits? [Y/N]";
		 cout << endl;
		 cin >> choiceCREDIT;
		 if (choiceCREDIT == "Y" || choiceCREDIT == "y"){
			 cout << "Now give amount of credits to this Client(RM)";

			 cin >> client_credit;
		 }
		 else {
			 cout << "The default 0 Credit would give to this client."; cout << endl;
			 client_credit = 0;
		 }


		 cout << "Want specify a password for this Client? [Y/N]"; cout << endl;
		 cin >> choicePWD;
		 if (choicePWD == "Y" || choicePWD == "y"){
			 cout << "Now enter the password of this Client...";
			 cin >> client_pwd;
		 }
		 else {
			 cout << "The default 'password' would be set as password for this client, later on the client may change it by themselves"; cout << endl;
			 client_pwd = "password";
		 }


		 //

		 //construct these in the constructor of home obj
		 if ((choicePWD == "Y" || choicePWD == "y") && (choiceCREDIT == "Y" || choiceCREDIT == "y")){
			// c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

		 }
		 else if ((choicePWD == "Y" || choicePWD == "y") && (choiceCREDIT != "Y" || choiceCREDIT != "y")){
			 client_credit = 0;
		//	 c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);
		 }
		 else if ((choicePWD != "Y" || choicePWD != "y") && (choiceCREDIT == "Y" || choiceCREDIT == "y")){
			 client_pwd = "password";
			// c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

		 }
		 else {//if (choicePWD != "Y" && choiceCREDIT != "Y"){
			 client_credit = 0;
			 client_pwd = "password";
			// c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

		 }

		 cout << " Congrats! the owner info. for client:" + client_name + " has been set up" << endl;
		 cout << endl;
		/* stringstream ss;//stringstream ss;
		 ss << client_id;
		 string client_id2 = ss.str();
		 // string *add_empId2=&empId2;
		 client_id2.append(".txt");
		 string newPortfolio = "dbclient/" + client_id2;

		 ofstream newClient(newPortfolio.c_str());
		 newClient << space_underscore(c->getClientID()) << ' ' << space_underscore(c->getClientNAME()) << ' ' << space_underscore(c->getClientPASSPORT()) << ' ' << space_underscore(c->getClientCONTACT()) << ' ' << space_underscore(c->getClientEMAIL()) << ' ' << space_underscore(c->getClientADDRESS()) << ' ' << space_underscore(c->getClientBANKACCT()) << ' ' << space_underscore(c->getClientBANK()) << ' ' << space_underscore(toString(c->getClientCREDIT())) << ' ' << space_underscore(c->getClientPWD()) << endl;
		 newClient.close();
		 ofstream dir("dbclient/db_client.txt", ios::app);
		 dir << space_underscore(c->getClientID()) << ' ' << space_underscore(c->getClientNAME()) << ' ' << space_underscore(c->getClientPASSPORT()) << ' ' << space_underscore(c->getClientCONTACT()) << ' ' << space_underscore(c->getClientEMAIL()) << ' ' << space_underscore(c->getClientADDRESS()) << ' ' << space_underscore(c->getClientBANKACCT()) << ' ' << space_underscore(c->getClientBANK()) << ' ' << space_underscore(toString(c->getClientCREDIT())) << ' ' << space_underscore(c->getClientPWD()) << endl; dir.close();
		 cout << "You have just added '" + c->getClientNAME() + "' with ID: '" + c->getClientID() + "' to attach to the home later on" << endl;
		 */

		 //cout << endl;
		 cout << "Now set up the home which "+client_name+" owns for rent... "<<endl;
		 cout << "---------------------------------------------------------- " << endl;
		 cout << "------"+client_name+"'s Home-Stay Posting Info------------ " << endl;

		 ////first construct a owner obj info
		 cout << "Where is the location of " + client_name + "'s House for rent?" << endl;
		 cin.get();
		 getline(cin, home_address);


		 get_Num_Rooms(&no_room, "bedroom");
		 get_Num_Rooms(&no_bath_room, "bathroom");
		 get_Num_Rooms(&max_capacity, "max capacity of the room");


		 cout << "How big is the room? (in square feet) sq.ft." << endl;
		 cin >> sq_ft;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  number." << endl;

			 std::cout << "Enter the size of room in square.feet again--(Last chance to enter)" << endl;

			 cin >> sq_ft;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  number." << endl;
			 }

		 }


		 bool loop = true;
		 char choice;
		 int switchCase;
		 int z = 0;
		 string chosenFacility[5];
		 while (loop && z<5){

			 cout << "What facilities the house owns? Choose at the menu below...(choose 5(max))" << endl;
			 cout << "1." + facility[0] << ' ' << "2." + facility[1] << ' ' << "3." + facility[2] << ' ' << "4." + facility[3] << ' ' << "5." + facility[4] << ' ' << "6." + facility[5] << ' ' << "7." + facility[6] << ' ' << "8." + facility[7] << ' ' << "9." + facility[8] << ' ' << "10." + facility[9] << endl;

			 cin >> switchCase;
			 --switchCase;
			 chosenFacility[z] = facility[switchCase];

			 //getline(cin, chosenFacility[z]);


			 cout << "Enough?[Y/N], Maximum 5, if want more, contact staff...(0166028563)" << endl;
			 cin >> choice;


			 if (choice == 'y' || choice == 'Y' || z >= 5){
				 loop = false;
			 }
			 else if (z < 5 || choice == 'n' || choice == 'N'){
				 loop = true;
				 ++z;

			 }

		 }



		 cout << endl; cout << endl;



		 for (int w = 0; w < chosenFacility[w].length(); w++){
			 facility_need_store = facility_need_store + "+" + chosenFacility[w];
		 }


	 StartAgain:

		 cout << "Write a description about " + client_name + "'s house/room (Max 50 words)" << endl;
		 cin.get();
		 getline(cin, description);
		 cout << description << endl;
		 char Fchars[50]; for (int a = 0; a <= description.size(); a++){ Fchars[a] = description[a]; }

		 int size = strlen(Fchars);
		 if (size >= 50)
		 {
			 cout << "max allowed size is 50 char" << endl;
			 goto StartAgain;
		 }



		 string l = "";
		 int number_of_lines = 0;
		 ifstream readLine("dbclient/db_client.txt");
		 if (readLine.is_open()){
			 while (!readLine.eof()){
				 getline(readLine, l);
				 // cout << l << endl;
				 number_of_lines++;
			 }
			 // myfile.close();
		 }readLine.close();
		 // cout << number_of_lines << endl;

		 cout << endl; cout << endl;


		 //now ask staff to choose the owner id
		
	//	 owner_id = c[countChoice].getClientID();

		 cout << endl; cout << endl;


		 cout << "How much " + client_name + "'s room/house would be cost for daily-renting(cost per day in RM) [?RM/day]" << endl;
		 cin >> day_price;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of daily rental in RM--(Last chance to enter)" << endl;

			 cin >> day_price;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }
		 cout << endl;


		 cout << "How much " + client_name + "'s room/house would be cost for weekly-renting(cost per day in RM) [?RM/week]" << endl;
		 cin >> week_price;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of weekly rental in RM--(Last chance to enter)" << endl;

			 cin >> week_price;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }
		 cout << endl;


		 cout << "How much " + client_name + "'s room/house would be cost for monthly-renting(cost per day in RM) [?RM/month]" << endl;
		 cin >> month_price;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore();
			 cout << "\nINVALID  cost." << endl;

			 std::cout << "Enter the price of monthly rental in RM--(Last chance to enter)" << endl;

			 cin >> month_price;

			 if (cin.fail()) {
				 cin.clear();
				 cin.ignore();
				 cout << "\nINVALID  cost value." << endl;
			 }

		 }
		 // c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

		 home *homeObj_with_Owner_aggregation = new home(c, client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd, newHomeID, home_address, no_room, no_bath_room, max_capacity, sq_ft, facility_need_store, description, client_id, day_price, week_price, month_price);





		 cout << " Congrats! the owner info. for client:" + client_name + " has been set up" << endl;
		 cout << endl;
		 stringstream ss;//stringstream ss;
		 ss << client_id;
		 string client_id2 = ss.str();
		 // string *add_empId2=&empId2;
		 client_id2.append(".txt");
		 string newPortfolio = "dbclient/" + client_id2;

		 ofstream newClient(newPortfolio.c_str());
		 newClient << space_underscore(c->getClientID()) << ' ' << space_underscore(c->getClientNAME()) << ' ' << space_underscore(c->getClientPASSPORT()) << ' ' << space_underscore(c->getClientCONTACT()) << ' ' << space_underscore(c->getClientEMAIL()) << ' ' << space_underscore(c->getClientADDRESS()) << ' ' << space_underscore(c->getClientBANKACCT()) << ' ' << space_underscore(c->getClientBANK()) << ' ' << space_underscore(toString(c->getClientCREDIT())) << ' ' << space_underscore(c->getClientPWD()) << endl;
		 newClient.close();
		 ofstream dir("dbclient/db_client.txt", ios::app);
		 dir << space_underscore(c->getClientID()) << ' ' << space_underscore(c->getClientNAME()) << ' ' << space_underscore(c->getClientPASSPORT()) << ' ' << space_underscore(c->getClientCONTACT()) << ' ' << space_underscore(c->getClientEMAIL()) << ' ' << space_underscore(c->getClientADDRESS()) << ' ' << space_underscore(c->getClientBANKACCT()) << ' ' << space_underscore(c->getClientBANK()) << ' ' << space_underscore(toString(c->getClientCREDIT())) << ' ' << space_underscore(c->getClientPWD()) << endl; dir.close();
		 cout << "You have just added '" + c->getClientNAME() + "' with ID: '" + c->getClientID() + "' to attach to the home later on" << endl;






		 string homeDB = newHomeID.append(".txt");

		 string newHomePortfolio = "dbhome/" + homeDB;


		 ofstream newHome(newHomePortfolio.c_str());
		 newHome << homeObj_with_Owner_aggregation->getHomeID() << ' ' << space_underscore(homeObj_with_Owner_aggregation->getHomeAddress()) << ' ' << homeObj_with_Owner_aggregation->getNoRoom() << ' ' << homeObj_with_Owner_aggregation->getNoBathRoom() << ' ' << homeObj_with_Owner_aggregation->getMaxCapacity() << ' ' << homeObj_with_Owner_aggregation->getSizeSqFt() << ' ' << space_underscore(homeObj_with_Owner_aggregation->facility) << ' ' << space_underscore(homeObj_with_Owner_aggregation->description) << ' ' << homeObj_with_Owner_aggregation->owner_id << ' ' << homeObj_with_Owner_aggregation->day_price << ' ' << homeObj_with_Owner_aggregation->week_price << ' ' << homeObj_with_Owner_aggregation->month_price << endl; newHome.close();

		 ofstream dirH("dbhome/db_home.txt", ios::app);
		 dirH << homeObj_with_Owner_aggregation->getHomeID() << ' ' << space_underscore(homeObj_with_Owner_aggregation->getHomeAddress()) << ' ' << homeObj_with_Owner_aggregation->getNoRoom() << ' ' << homeObj_with_Owner_aggregation->getNoBathRoom() << ' ' << homeObj_with_Owner_aggregation->getMaxCapacity() << ' ' << homeObj_with_Owner_aggregation->getSizeSqFt() << ' ' << space_underscore(homeObj_with_Owner_aggregation->facility) << ' ' << space_underscore(homeObj_with_Owner_aggregation->description) << ' ' << homeObj_with_Owner_aggregation->owner_id << ' ' << homeObj_with_Owner_aggregation->day_price << ' ' << homeObj_with_Owner_aggregation->week_price << ' ' << homeObj_with_Owner_aggregation->month_price << endl;
		 dirH.close();
		 cout << "You have just added a home at '" + homeObj_with_Owner_aggregation->getHomeAddress() + "' with home ID: '" + home_id + "' which belongs to "+c->getClientNAME()+" with client-ID "+c->getClientID()+"" << endl;










		 system("pause");
		 new_home();
	 
	 }











void staff::manage_booking(){

	system("cls");
	cout << "-----------Welcome staff: " + sta.sessionNAME + "-----------" << endl;
	cout << "-----------Home-Stay Management Console----------" << endl;
	system("color 0f");
	cout << "Please enter your choice" << endl;
	cout << "1.Make a new booking for customer" << endl;
	cout << "2.Edit existing booking" << endl;
	cout << "3.View All booking Info" << endl;
	cout << "4.Delete booking info" << endl;
	cout << "5.<<Back" << endl;

	int choice;
	cin >> choice;

	switch (choice){
	case 1:
		new_booking();
		break;
	case 2:
		edit_booking();
		break;
	case 3:
		list_booking();
		break;
	case 4:
		delete_booking();
		break;
	
	case 5:
		//a.main();
		staff_main(sta.sessionID, sta.sessionNAME);
		break;

	default:
		cout << "Pls choose beween interger 1 ~ 6 only" << endl;
	}





}
//staff booking management function

void staff::new_booking(){

	ifstream aFile("dbbooking/db_booking.txt");
	size_t lines_count = std::count(istreambuf_iterator<char>(aFile),
		std::istreambuf_iterator<char>(), '\n');
	int current_row = lines_count;//
	int new_booking_row = ++current_row;

	string newBookingID = "booking" + toString(new_booking_row);//set the new home id
	aFile.close();

	//home attributues
	string home_address;
	int no_room;
	int no_bath_room;
	int max_capacity;
	double  sq_ft;
	string home_facility;
	string home_description;
	double home_day_price;
	double home_week_price;
	double home_month_price;






	//booking attrib;
	string booking_id;
	string home_id;
	string client_id;//owner id
	string customer_id;// customer who rent the room from owner
	char type;//daily:d   weekly:w    monthly:m
	double duration;//specifies how many days,weeks,months
	string chk_in;
	string chk_out;
	double unit_price; //unit_price * duration = total how much customer need pay
	double total_pay;




	int howManyDay;
	int howManyWeek;
	int howManyMonth;

	booking *bookingPtr = new booking();

	system("cls");
	cout << "-----------Welcome staff: " + sta.sessionNAME + "-----------" << endl;
	cout << "-----------Home-Stay Booking Management Console-------------" << endl;
	home *homePtr = new home();
	homePtr->displayDetail();
	system("color 0f");
	cout << "************************************************************" << endl;
	cout << "Above are the available home-stay rooms/houses can be booked" << endl;
	cout << "************************************************************" << endl;
	cout << "What kind of booking is this? [Monthly booking?] [Weekly Booking?] [Daily Booking?] Please select " << endl;
	int choice;
	cout << ">> 1.Daily Rent" << endl;
	cout << ">> 2.Weekly Rent" << endl;
	cout << ">> 3.Monthly Rent" << endl;
	cin >> choice;
	if (choice == 1){
		type = 'd';
	}
	else if (choice == 2){
		type = 'w';

	}
	else if (choice == 3){
		type = 'm';
	}

	cout << "Who is booking this? ->Please choose one customer id from below" << endl;

	string l = "";
	int number_of_lines = 0;
	ifstream readLine("dbcustomer/db_customer.txt");
	if (readLine.is_open()){
		while (!readLine.eof()){
			getline(readLine, l);
			// cout << l << endl;
			number_of_lines++;
		}
		// myfile.close();
	}readLine.close();


enterAgain:
	ifstream readcustomerId("dbcustomer/db_customer.txt");
	customer cus[100];
	string customerID;
	string customerName; string customerIC; string customerContact; string customerEmail; string customerAddress;
	string customerBankAcct; string customerBank; double customerCredit; string customerPwd;
	int m = 0;
	while (readcustomerId >> customerID >> customerName >> customerIC >> customerContact >> customerEmail >> customerAddress >> customerBankAcct >> customerBank >> customerCredit >> customerPwd){
		// cout << customerID << endl;
		cus[m].setCustomerID(customerID);
		cus[m].setCustomerNAME(customerName);
		cus[m].setCustomerPASSPORT(customerIC);
		cus[m].setCustomerCONTACT(customerContact);
		cus[m].setCustomerEMAIL(customerEmail);
		cus[m].setCustomerADDRESS(customerAddress);
		cus[m].setCustomerBANKACCT(customerBankAcct);

		cus[m].setCustomerBANK(customerBank);
		cus[m].setCustomerCREDIT(customerCredit);

		cus[m].setCustomerPWD(customerPwd);

		m++;
	}readcustomerId.close();
	cout << "Following are the list of customer's ID, You must set one to this home of post..." << endl;
	cout << "Please Choose one by entering number of specific..." << endl;
	int iterator = 1;
	int countChoice;
	--number_of_lines;
	while (iterator <= number_of_lines){
		cout << iterator << " : ";
		cout << cus[--iterator].getCustomerID() << endl; ++iterator;
		++iterator;
	}
	cin >> countChoice;
	bool ok = true;
	if (cin.fail()){
		cin.clear();
		cin.ignore();
		cout << "Please reenter Client ID Again" << endl;
		cin >> countChoice;
		if (cin.fail()){
			ok = false;
			cin.clear();
			cin.ignore();
			cout << "Please re-enter Client ID Again! only the displayed ID are accepted!(last chance)" << endl;
			cin >> countChoice;
		}
	}
	if (!ok){
		goto enterAgain;
	}
	--countChoice;
	cout << "So you have chosen the customer ID for booking:" + cus[countChoice].getCustomerID() << endl;
	customer_id = cus[countChoice].getCustomerID();

	cout << endl; cout << endl;

	cout << "Which home-stay " + cus[countChoice].getCustomerNAME() + " would like to book?" << endl;
	cout << "Select the Home ID for booking?" << endl;
	string home_id_for_book;
	cin >> home_id_for_book;
	ifstream readHome("dbhome/db_home.txt");
	while (readHome >> home_id >> home_address >> no_room >> no_bath_room >> max_capacity >> sq_ft >> home_facility >> home_description >> client_id >> home_day_price >> home_week_price >> home_month_price){
		if (home_id_for_book == home_id || home_id == home_id_for_book){
			homePtr->setHomeID(home_id);
			homePtr->setHomeAddress(home_address);
			homePtr->setNoRoom(no_room);
			homePtr->setNoBathRoom(no_bath_room);

			homePtr->setMaxCapacity(max_capacity);
			homePtr->setSize(sq_ft);
			homePtr->facility = home_facility;
			homePtr->description = home_description;
			homePtr->owner_id = client_id;
			homePtr->day_price = home_day_price;
			homePtr->week_price = home_week_price;
			homePtr->month_price = home_month_price;
		}
}
		cout << " " << endl;
		cout << "*******************************************************" << endl;
		cout << " " << endl;
		cout << "Below are the room have selected for customer " + cus[countChoice].getCustomerNAME() + " to book: " << endl;
		homePtr->displaySpecificRoom(home_id_for_book);
		cout << " " << endl;
		cout << "*******************************************************" << endl;
		cout << " " << endl;
	

		string inYear; string inMonth; string inDay; int inYearInt; int inMonthInt; int inDayInt;


		string outYear; string outMonth; string outDay; int outYearInt; int outMonthInt; int outDayInt;
		string tempDayMonthYearIn;
		string tempDayMonthIn;

		int yearDif; int monthDif; int dayDif;

		string tempDayMonthYearOut;
		string tempDayMonthOut;


		client_id = homePtr->owner_id;
		string clientFileRead = "dbclient/" + client_id  ;
		clientFileRead.append(".txt");
		ifstream readClient(clientFileRead.c_str());
		//client attribs need save to client obj ptr
		 string client_name; string client_ic; string client_contact; string client_email;
		string client_address; string client_bank_acct; string client_bank; double client_credit; string client_pwd;
		client *clientPtr = new client();

		while (readClient >> client_id >> client_name >> client_ic >>  client_contact >> client_email >> client_address >> client_bank_acct >> client_bank >> client_credit >> client_pwd){
			clientPtr->setAttributes(client_id , client_name , client_ic , client_contact , client_email , client_address , client_bank_acct , client_bank , client_credit , client_pwd);
		}readClient.close();

		//int firstIdx; int secondIdx; int thirdIdx; int forthIdx; int fifthIdx; int sixthIdx;
		double customer_balance;


		double client_money = clientPtr->getClientCREDIT();
		double customer_money = cus[countChoice].getCustomerCREDIT();
		stringstream ss;
		vector<string> chk_outresult; 
		vector<string> chk_inresult;
		string strTempTime;
		switch (type){

		case 'd':
			cout << "Daily Rent Category-> " << endl;

			cout << "Input the Move-in Date: " << endl;
			chk_in = bookingPtr->getDateTimeIn(home_id_for_book);//dd-mm-yyyy-hh:mm
			cout << "Input the Move-Out Date: " << endl;
			chk_out = bookingPtr->getDateTimeIn(home_id_for_book); //dd-mm-yyyy-hh:mm
			


			 ss=stringstream(chk_out);
			//vector<string> chk_outresult;

			while (ss.good())
			{
				string substr;
				getline(ss, substr, '-');
				chk_outresult.push_back(substr);
			}
			//20-12-2016-14:00
			outDay = chk_outresult[0];//20  
			outMonth = chk_outresult[1];//12
			outYear = chk_outresult[2];//2016
			 strTempTime = chk_outresult[3];//14:00
			cout << "test time " + strTempTime + "" << endl;

			outDayInt = stoi(outDay);
			outMonthInt = stoi(outMonth);
			outYearInt = stoi(outYear);





			ss = stringstream(chk_in);
			

			while (ss.good())
			{
				string substr;
				getline(ss, substr, '-');
				chk_inresult.push_back(substr);
			}
			//20-12-2016-14:00
		inDay=	chk_inresult[0];//20  
		inMonth=	chk_inresult[1];//12
		inYear=	chk_inresult[2];//2016
		  strTempTime=chk_inresult[3];//14:00
		 cout << "test time "+strTempTime+"" << endl;

		inDayInt = stoi(inDay);
		inMonthInt = stoi(inMonth);
		inYearInt = stoi(inYear);


		total_pay=	bookingPtr->outPutTotalPay_daily(homePtr->day_price, inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);
		duration = bookingPtr->getTotalDay(inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);

		//now check the customer have enough balance to pay
		if (customer_money >=total_pay){
		
			customer_balance = customer_money - total_pay;
			cus[countChoice].setCustomerCREDIT(customer_balance);//minus the credit of customer


			stringstream ss;//stringstream ss;
			ss << cus[countChoice].getCustomerID();
			string customer_idS = ss.str();
			string customer_id2 = ss.str();

			customer_id2.append(".txt");
			string filePortfolio = "dbcustomer/" + customer_id2;
			std::ifstream customerPort(filePortfolio.c_str());


			ofstream tempPofolio("dbcustomer/tempPofolio.txt");

			ofstream temp("dbcustomer/temp.txt");
			ifstream customerD("dbcustomer/db_customer.txt");
			if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

				string line;
				while (getline(customerD, line))
				{
					if (line.find(customer_idS) == string::npos) { //str.find(str2) != string::npos
						temp << line << endl;

					}
					else
					{

						tempPofolio << space_underscore(cus[countChoice].getCustomerID()) << ' ' << space_underscore(cus[countChoice].getCustomerNAME()) << ' ' << space_underscore(cus[countChoice].getCustomerPASSPORT()) << ' ' << space_underscore(cus[countChoice].getCustomerCONTACT()) << ' ' << space_underscore(cus[countChoice].getCustomerEMAIL()) << ' ' << space_underscore(cus[countChoice].getCustomerADDRESS()) << ' ' << space_underscore(cus[countChoice].getCustomerBANKACCT()) << ' ' << space_underscore(cus[countChoice].getCustomerBANK()) << ' ' << cus[countChoice].getCustomerCREDIT() << ' ' << space_underscore(cus[countChoice].getCustomerPWD()) << endl;
						temp << space_underscore(cus[countChoice].getCustomerID()) << ' ' << space_underscore(cus[countChoice].getCustomerNAME()) << ' ' << space_underscore(cus[countChoice].getCustomerPASSPORT()) << ' ' << space_underscore(cus[countChoice].getCustomerCONTACT()) << ' ' << space_underscore(cus[countChoice].getCustomerEMAIL()) << ' ' << space_underscore(cus[countChoice].getCustomerADDRESS()) << ' ' << space_underscore(cus[countChoice].getCustomerBANKACCT()) << ' ' << space_underscore(cus[countChoice].getCustomerBANK()) << ' ' << cus[countChoice].getCustomerCREDIT() << ' ' << space_underscore(cus[countChoice].getCustomerPWD()) << endl;
					}
				}

			}
			tempPofolio.close();
			customerPort.close();
			customerD.close();

			temp.close();


			string db_old_file = "dbcustomer/db_customer.txt";
			//system("del dbcustomer/db_customer.txt");
			const char *data = "dbcustomer/db_customer.txt";
			remove(db_old_file.c_str());//delete the old db file first


			//system("del dbcustomer/db_customer.txt");
			remove(filePortfolio.c_str());

			rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
			rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
			//******


			//********************8save into customer db*********************


			double client_balance = (client_money)+total_pay;
			clientPtr->setClientCREDIT(client_balance);//add the credit to the owner


			stringstream ss1;//stringstream ss;
			ss1 << clientPtr->getClientID();
			string client_idS = ss1.str();
			string client_id2 = ss1.str();

			client_id2.append(".txt");
			string filePortfolio_C = "dbclient/" + client_id2;
			std::ifstream clientPort(filePortfolio_C.c_str());


			ofstream tempPofoliocc("dbclient/tempPofolio.txt");

			ofstream tempF("dbclient/temp.txt");
			ifstream clientD("dbclient/db_client.txt");
			if (tempPofoliocc.is_open() && clientD.is_open() && tempF.is_open()){

				string line;
				while (getline(clientD, line))
				{
					if (line.find(client_idS) == string::npos) { //str.find(str2) != string::npos
						tempF << line << endl;

					}
					else
					{

						tempPofoliocc << space_underscore(clientPtr->getClientID()) << ' ' << space_underscore(clientPtr->getClientNAME()) << ' ' << space_underscore(clientPtr->getClientPASSPORT()) << ' ' << space_underscore(clientPtr->getClientCONTACT()) << ' ' << space_underscore(clientPtr->getClientEMAIL()) << ' ' << space_underscore(clientPtr->getClientADDRESS()) << ' ' << space_underscore(clientPtr->getClientBANKACCT()) << ' ' << space_underscore(clientPtr->getClientBANK()) << ' ' << clientPtr->getClientCREDIT() << ' ' << space_underscore(clientPtr->getClientPWD()) << endl;
						tempF << space_underscore(clientPtr->getClientID()) << ' ' << space_underscore(clientPtr->getClientNAME()) << ' ' << space_underscore(clientPtr->getClientPASSPORT()) << ' ' << space_underscore(clientPtr->getClientCONTACT()) << ' ' << space_underscore(clientPtr->getClientEMAIL()) << ' ' << space_underscore(clientPtr->getClientADDRESS()) << ' ' << space_underscore(clientPtr->getClientBANKACCT()) << ' ' << space_underscore(clientPtr->getClientBANK()) << ' ' << clientPtr->getClientCREDIT() << ' ' << space_underscore(clientPtr->getClientPWD()) << endl;
					}
				}

			}
			tempPofoliocc.close();
			clientPort.close();
			clientD.close();

			tempF.close();


			string db_old_file0 = "dbclient/db_client.txt";
			//system("del dbcustomer/db_customer.txt");
			const char *dataC = "dbclient/db_client.txt";
			remove(db_old_file0.c_str());//delete the old db file first


			//system("del dbcustomer/db_customer.txt");
			remove(filePortfolio_C.c_str());

			rename("dbclient/tempPofolio.txt", filePortfolio_C.c_str());
			rename("dbclient/temp.txt", "dbclient/db_client.txt");
			//******


			//********************8save into customer db*********************







			bookingPtr->setBookingID(newBookingID);bookingPtr->setBookingHomeID(homePtr->getHomeID()); 
			bookingPtr->setBookingClientID(homePtr->owner_id); bookingPtr->setBookingCustomerID(cus[countChoice].getCustomerID());
			bookingPtr->setBookingType('d'); bookingPtr->setStayDuration(duration);
			bookingPtr->setChkIn(chk_in); bookingPtr->setChkOut(chk_out);
			bookingPtr->setUnitPirce(homePtr->day_price); bookingPtr->setTotalPaid(total_pay);
			//new booking info save into db

			string newBookingPortfolio = "dbbooking/" + newBookingID + ".txt";


			ofstream newBooking(newBookingPortfolio.c_str());
			newBooking << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << type << ' ' << duration << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl;
			newBooking.close();

			ofstream dir("dbbooking/db_booking.txt", ios::app);
			dir << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << type << ' ' << duration << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl; dir.close();
			cout << "You have just added a Booking at '" + homePtr->getHomeAddress() + "' which owned by " + clientPtr->getClientNAME() + " with home ID: '" + homePtr->getHomeID() + "' with Booking Id: " + newBookingID + " for customer " + cus[countChoice].getCustomerNAME() + " with " + toString(duration) + " days stay" << endl;

			cout << "Client " + clientPtr->getClientNAME() + " has successfully received RM" + toString(total_pay) + " from customer " + cus[countChoice].getCustomerNAME() + " with booking Id: " + newBookingID + " " << endl;




			
		}
		else{
			cout << "Sorry, Customer "+cus[countChoice].getCustomerNAME()+" does not have enough balance to pay the rental RM"+toString(total_pay)+" for the homestay at "+homePtr->getHomeAddress()+" for "+toString(duration)+" days stay"<< endl;

		}



			break;
		case 'w':
			
			cout << "Weekly Rent Category-> " << endl;
			cout << "Input the Move-in Date: " << endl;
			chk_in = bookingPtr->getDateTimeIn(home_id_for_book);//dd-mm-yyyy-hh:mm
			cout << "Input the Move-Out Date: " << endl;
			chk_out = bookingPtr->getDateTimeIn(home_id_for_book); //dd-mm-yyyy-hh:mm


			//get in day month year by splitting from '-'



			ss = stringstream(chk_out);
			//vector<string> chk_outresult;

			while (ss.good())
			{
				string substr;
				getline(ss, substr, '-');
				chk_outresult.push_back(substr);
			}
			//20-12-2016-14:00
			outDay = chk_outresult[0];//20  
			outMonth = chk_outresult[1];//12
			outYear = chk_outresult[2];//2016
			 strTempTime = chk_outresult[3];//14:00
			cout << "test time " + strTempTime + "" << endl;

			outDayInt = stoi(outDay);
			outMonthInt = stoi(outMonth);
			outYearInt = stoi(outYear);





			ss = stringstream(chk_in);
			//vector<string> chk_inresult;

			while (ss.good())
			{
				string substr;
				getline(ss, substr, '-');
				chk_inresult.push_back(substr);
			}
			//20-12-2016-14:00
			inDay = chk_inresult[0];//20  
			inMonth = chk_inresult[1];//12
			inYear = chk_inresult[2];//2016
			 strTempTime = chk_inresult[3];//14:00
			cout << "test time " + strTempTime + "" << endl;

			inDayInt = stoi(inDay);
			inMonthInt = stoi(inMonth);
			inYearInt = stoi(inYear);

			total_pay = bookingPtr->outPutTotalPay_weekly(homePtr->week_price, inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);
			duration = bookingPtr->getTotalWeek(inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);

			//now check the customer have enough balance to pay
			if (customer_money >= total_pay){

				double customer_balance = customer_money- total_pay;
				cus[countChoice].setCustomerCREDIT(customer_balance);//minus the credit of customer


				stringstream ss;//stringstream ss;
				ss << cus[countChoice].getCustomerID();
				string customer_idS = ss.str();
				string customer_id2 = ss.str();

				customer_id2.append(".txt");
				string filePortfolio = "dbcustomer/" + customer_id2;
				std::ifstream customerPort(filePortfolio.c_str());


				ofstream tempPofolio("dbcustomer/tempPofolio.txt");

				ofstream temp("dbcustomer/temp.txt");
				ifstream customerD("dbcustomer/db_customer.txt");
				if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

					string line;
					while (getline(customerD, line))
					{
						if (line.find(customer_idS) == string::npos) { //str.find(str2) != string::npos
							temp << line << endl;

						}
						else
						{

							tempPofolio << space_underscore(cus[countChoice].getCustomerID()) << ' ' << space_underscore(cus[countChoice].getCustomerNAME()) << ' ' << space_underscore(cus[countChoice].getCustomerPASSPORT()) << ' ' << space_underscore(cus[countChoice].getCustomerCONTACT()) << ' ' << space_underscore(cus[countChoice].getCustomerEMAIL()) << ' ' << space_underscore(cus[countChoice].getCustomerADDRESS()) << ' ' << space_underscore(cus[countChoice].getCustomerBANKACCT()) << ' ' << space_underscore(cus[countChoice].getCustomerBANK()) << ' ' << cus[countChoice].getCustomerCREDIT() << ' ' << space_underscore(cus[countChoice].getCustomerPWD()) << endl;
							temp << space_underscore(cus[countChoice].getCustomerID()) << ' ' << space_underscore(cus[countChoice].getCustomerNAME()) << ' ' << space_underscore(cus[countChoice].getCustomerPASSPORT()) << ' ' << space_underscore(cus[countChoice].getCustomerCONTACT()) << ' ' << space_underscore(cus[countChoice].getCustomerEMAIL()) << ' ' << space_underscore(cus[countChoice].getCustomerADDRESS()) << ' ' << space_underscore(cus[countChoice].getCustomerBANKACCT()) << ' ' << space_underscore(cus[countChoice].getCustomerBANK()) << ' ' << cus[countChoice].getCustomerCREDIT() << ' ' << space_underscore(cus[countChoice].getCustomerPWD()) << endl;
						}
					}

				}
				tempPofolio.close();
				customerPort.close();
				customerD.close();

				temp.close();


				string db_old_file = "dbcustomer/db_customer.txt";
				//system("del dbcustomer/db_customer.txt");
				const char *data = "dbcustomer/db_customer.txt";
				remove(db_old_file.c_str());//delete the old db file first


				//system("del dbcustomer/db_customer.txt");
				remove(filePortfolio.c_str());

				rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
				rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
				//******


				//********************8save into customer db*********************


				double client_balance = (client_money) + total_pay;
				clientPtr->setClientCREDIT(client_balance);//add the credit to the owner


				stringstream ssa;//stringstream ss;
				ssa << clientPtr->getClientID();
				string client_idS = ssa.str();
				string client_id2 = ssa.str();

				client_id2.append(".txt");
				string filePortfolioC = "dbclient/" + client_id2;
				std::ifstream clientPort(filePortfolioC.c_str());


				ofstream tempPofolioC("dbclient/tempPofolio.txt");

				ofstream tempC("dbclient/temp.txt");
				ifstream clientD("dbclient/db_client.txt");
				if (tempPofolioC.is_open() && clientD.is_open() && tempC.is_open()){

					string line;
					while (getline(clientD, line))
					{
						if (line.find(client_idS) == string::npos) { //str.find(str2) != string::npos
							temp << line << endl;

						}
						else
						{

							tempPofolio << space_underscore(clientPtr->getClientID()) << ' ' << space_underscore(clientPtr->getClientNAME()) << ' ' << space_underscore(clientPtr->getClientPASSPORT()) << ' ' << space_underscore(clientPtr->getClientCONTACT()) << ' ' << space_underscore(clientPtr->getClientEMAIL()) << ' ' << space_underscore(clientPtr->getClientADDRESS()) << ' ' << space_underscore(clientPtr->getClientBANKACCT()) << ' ' << space_underscore(clientPtr->getClientBANK()) << ' ' << clientPtr->getClientCREDIT() << ' ' << space_underscore(clientPtr->getClientPWD()) << endl;
							temp << space_underscore(clientPtr->getClientID()) << ' ' << space_underscore(clientPtr->getClientNAME()) << ' ' << space_underscore(clientPtr->getClientPASSPORT()) << ' ' << space_underscore(clientPtr->getClientCONTACT()) << ' ' << space_underscore(clientPtr->getClientEMAIL()) << ' ' << space_underscore(clientPtr->getClientADDRESS()) << ' ' << space_underscore(clientPtr->getClientBANKACCT()) << ' ' << space_underscore(clientPtr->getClientBANK()) << ' ' << clientPtr->getClientCREDIT() << ' ' << space_underscore(clientPtr->getClientPWD()) << endl;
						}
					}

				}
				tempPofolioC.close();
				clientPort.close();
				clientD.close();

				tempC.close();


				string db_old_filex = "dbclient/db_client.txt";
				//system("del dbcustomer/db_customer.txt");
				const char *data1 = "dbclient/db_client.txt";
				remove(db_old_filex.c_str());//delete the old db file first


				//system("del dbcustomer/db_customer.txt");
				remove(filePortfolioC.c_str());

				rename("dbclient/tempPofolio.txt", filePortfolioC.c_str());
				rename("dbclient/temp.txt", "dbclient/db_client.txt");
				//******


				//********************8save into customer db*********************




				client_id = homePtr->owner_id;


				bookingPtr->setBookingID(newBookingID); bookingPtr->setBookingHomeID(homePtr->getHomeID());
				bookingPtr->setBookingClientID(homePtr->owner_id); bookingPtr->setBookingCustomerID(cus[countChoice].getCustomerID());
				bookingPtr->setBookingType('w'); bookingPtr->setStayDuration(duration);
				bookingPtr->setChkIn(chk_in); bookingPtr->setChkOut(chk_out);
				bookingPtr->setUnitPirce(homePtr->week_price); bookingPtr->setTotalPaid(total_pay);
				//new booking info save into db

				string newBookingPortfolio = "dbbooking/" + newBookingID + ".txt";


				ofstream newBooking(newBookingPortfolio.c_str());
				newBooking << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << bookingPtr->getBookingType() << ' ' << bookingPtr->getBookingDuration() << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl;
				newBooking.close();

				ofstream dir("dbbooking/db_booking.txt", ios::app);
				dir << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << bookingPtr->getBookingType() << ' ' << bookingPtr->getBookingDuration() << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl; dir.close();
				cout << "You have just added a Booking at '" + homePtr->getHomeAddress() + "' which owned by " + clientPtr->getClientNAME() + " with home ID: '" + homePtr->getHomeID() + "' with Booking Id: " + newBookingID + " for customer " + cus[countChoice].getCustomerNAME() + "  with "+toString(duration)+" weeks stay" << endl;

				cout << "Client " + clientPtr->getClientNAME() + " has successfully received RM" + toString(total_pay) + " from customer " + cus[countChoice].getCustomerNAME() + " with booking Id: " + newBookingID + " " << endl;





			}
			else{
				cout << "Sorry, Customer " + cus[countChoice].getCustomerNAME() + " does not have enough balance to pay the rental RM" + toString(total_pay) + " for the homestay at " + homePtr->getHomeAddress() + " for " + toString(duration) + " weeks stay" << endl;

			}



			break;

		case 'm':
			cout << "Monthly Rent Category-> " << endl;

			cout << "Input the Move-in Date: " << endl;
			chk_in = bookingPtr->getDateTimeIn(home_id_for_book);//dd-mm-yyyy-hh:mm
			cout << "Input the Move-Out Date: " << endl;
			chk_out = bookingPtr->getDateTimeIn(home_id_for_book); //dd-mm-yyyy-hh:mm


			//get in day month year by splitting from '-'



			stringstream ss(chk_out);
//			vector<string> chk_outresult;

			while (ss.good())
			{
				string substr;
				getline(ss, substr, '-');
				chk_outresult.push_back(substr);
			}
			//20-12-2016-14:00
			outDay = chk_outresult[0];//20  
			outMonth = chk_outresult[1];//12
			outYear = chk_outresult[2];//2016
			string strTempTime = chk_outresult[3];//14:00
			cout << "test time " + strTempTime + "" << endl;

			outDayInt = stoi(outDay);
			outMonthInt = stoi(outMonth);
			outYearInt = stoi(outYear);





			ss = stringstream(chk_in);
			//vector<string> chk_inresult;

			while (ss.good())
			{
				string substr;
				getline(ss, substr, '-');
				chk_inresult.push_back(substr);
			}
			//20-12-2016-14:00
			inDay = chk_inresult[0];//20  
			inMonth = chk_inresult[1];//12
			inYear = chk_inresult[2];//2016
			 strTempTime = chk_inresult[3];//14:00
			cout << "test time " + strTempTime + "" << endl;

			inDayInt = stoi(inDay);
			inMonthInt = stoi(inMonth);
			inYearInt = stoi(inYear);


			total_pay = bookingPtr->outPutTotalPay_monthly(homePtr->month_price, inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);
			duration = bookingPtr->getTotalMonth(inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);

			//now check the customer have enough balance to pay
			if (customer_money >= total_pay){

				 customer_balance = customer_money - total_pay;
				cus[countChoice].setCustomerCREDIT(customer_balance);//minus the credit of customer


				stringstream ss;//stringstream ss;
				ss << cus[countChoice].getCustomerID();
				string customer_idS = ss.str();
				string customer_id2 = ss.str();

				customer_id2.append(".txt");
				string filePortfolio = "dbcustomer/" + customer_id2;
				std::ifstream customerPort(filePortfolio.c_str());


				ofstream tempPofolio("dbcustomer/tempPofolio.txt");

				ofstream temp("dbcustomer/temp.txt");
				ifstream customerD("dbcustomer/db_customer.txt");
				if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

					string line;
					while (getline(customerD, line))
					{
						if (line.find(customer_idS) == string::npos) { //str.find(str2) != string::npos
							temp << line << endl;

						}
						else
						{

							tempPofolio << space_underscore(cus[countChoice].getCustomerID()) << ' ' << space_underscore(cus[countChoice].getCustomerNAME()) << ' ' << space_underscore(cus[countChoice].getCustomerPASSPORT()) << ' ' << space_underscore(cus[countChoice].getCustomerCONTACT()) << ' ' << space_underscore(cus[countChoice].getCustomerEMAIL()) << ' ' << space_underscore(cus[countChoice].getCustomerADDRESS()) << ' ' << space_underscore(cus[countChoice].getCustomerBANKACCT()) << ' ' << space_underscore(cus[countChoice].getCustomerBANK()) << ' ' << cus[countChoice].getCustomerCREDIT() << ' ' << space_underscore(cus[countChoice].getCustomerPWD()) << endl;
							temp << space_underscore(cus[countChoice].getCustomerID()) << ' ' << space_underscore(cus[countChoice].getCustomerNAME()) << ' ' << space_underscore(cus[countChoice].getCustomerPASSPORT()) << ' ' << space_underscore(cus[countChoice].getCustomerCONTACT()) << ' ' << space_underscore(cus[countChoice].getCustomerEMAIL()) << ' ' << space_underscore(cus[countChoice].getCustomerADDRESS()) << ' ' << space_underscore(cus[countChoice].getCustomerBANKACCT()) << ' ' << space_underscore(cus[countChoice].getCustomerBANK()) << ' ' << cus[countChoice].getCustomerCREDIT() << ' ' << space_underscore(cus[countChoice].getCustomerPWD()) << endl;
						}
					}

				}
				tempPofolio.close();
				customerPort.close();
				customerD.close();

				temp.close();


				string db_old_file = "dbcustomer/db_customer.txt";
				//system("del dbcustomer/db_customer.txt");
				const char *data = "dbcustomer/db_customer.txt";
				remove(db_old_file.c_str());//delete the old db file first


				//system("del dbcustomer/db_customer.txt");
				remove(filePortfolio.c_str());

				rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
				rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
				//******


				//********************8save into customer db*********************


				double client_balance = (client_money) + total_pay;
				clientPtr->setClientCREDIT(client_balance);//add the credit to the owner


				client_id = clientPtr->getClientID();
				stringstream ss2;//stringstream ss;
				ss2 << client_id;
				string client_idS = ss2.str();
				string client_id2 = ss2.str();

				client_id2.append(".txt");
				string filePortfolioClient = "dbclient/" + client_id2;
				std::ifstream clientPort(filePortfolioClient.c_str());


				ofstream tempPofolio_client_db("dbclient/tempPofolio.txt");

				ofstream tempClient("dbclient/temp.txt");
				ifstream clientD("dbclient/db_client.txt");
				if (tempPofolio_client_db.is_open() && clientD.is_open() && tempClient.is_open()){

					string line;
					while (getline(clientD, line))
					{
						if (line.find(client_idS) == string::npos) { //str.find(str2) != string::npos
							tempClient << line << endl;

						}
						else
						{

							tempPofolio_client_db << space_underscore(clientPtr->getClientID()) << ' ' << space_underscore(clientPtr->getClientNAME()) << ' ' << space_underscore(clientPtr->getClientPASSPORT()) << ' ' << space_underscore(clientPtr->getClientCONTACT()) << ' ' << space_underscore(clientPtr->getClientEMAIL()) << ' ' << space_underscore(clientPtr->getClientADDRESS()) << ' ' << space_underscore(clientPtr->getClientBANKACCT()) << ' ' << space_underscore(clientPtr->getClientBANK()) << ' ' << clientPtr->getClientCREDIT() << ' ' << space_underscore(clientPtr->getClientPWD()) << endl;
							tempClient << space_underscore(clientPtr->getClientID()) << ' ' << space_underscore(clientPtr->getClientNAME()) << ' ' << space_underscore(clientPtr->getClientPASSPORT()) << ' ' << space_underscore(clientPtr->getClientCONTACT()) << ' ' << space_underscore(clientPtr->getClientEMAIL()) << ' ' << space_underscore(clientPtr->getClientADDRESS()) << ' ' << space_underscore(clientPtr->getClientBANKACCT()) << ' ' << space_underscore(clientPtr->getClientBANK()) << ' ' << clientPtr->getClientCREDIT() << ' ' << space_underscore(clientPtr->getClientPWD()) << endl;
						}
					}

				}
				tempPofolio_client_db.close();
				clientPort.close();
				clientD.close();

				tempClient.close();


				string db_old_fileC = "dbclient/db_client.txt";
				//system("del dbcustomer/db_customer.txt");
				//const char *data = "dbclient/db_client.txt";
				remove(db_old_fileC.c_str());//delete the old db file first


				//system("del dbcustomer/db_customer.txt");
				remove(filePortfolioClient.c_str());
				
				rename("dbclient/tempPofolio.txt", filePortfolioClient.c_str());
				rename("dbclient/temp.txt", "dbclient/db_client.txt");
				//******


				//********************8save into customer db*********************







				bookingPtr->setBookingID(newBookingID); bookingPtr->setBookingHomeID(homePtr->getHomeID());
				bookingPtr->setBookingClientID(homePtr->owner_id); bookingPtr->setBookingCustomerID(cus[countChoice].getCustomerID());
				bookingPtr->setBookingType('m'); bookingPtr->setStayDuration(duration);
				bookingPtr->setChkIn(chk_in); bookingPtr->setChkOut(chk_out);
				bookingPtr->setUnitPirce(homePtr->month_price); bookingPtr->setTotalPaid(total_pay);
				//new booking info save into db

				string newBookingPortfolio = "dbbooking/" + newBookingID + ".txt";


				ofstream newBooking(newBookingPortfolio.c_str());
				newBooking << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << bookingPtr->getBookingType() << ' ' << bookingPtr->getBookingDuration() << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl;
				newBooking.close();

				ofstream dir("dbbooking/db_booking.txt", ios::app);
				dir << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << bookingPtr->getBookingType() << ' ' << bookingPtr->getBookingDuration() << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl; dir.close();
				cout << "You have just added a Booking at '" + homePtr->getHomeAddress() + "' which owned by " + clientPtr->getClientNAME() + " with home ID: '" + homePtr->getHomeID() + "' with Booking Id: " + newBookingID + " for customer " + cus[countChoice].getCustomerNAME() + "  with " + toString(duration) + " months stay" << endl;

				cout << "Client " + clientPtr->getClientNAME() + " has successfully received RM" + toString(total_pay) + " from customer " + cus[countChoice].getCustomerNAME() + " with booking Id: " + newBookingID + " " << endl;





			}
			else{
				cout << "Sorry, Customer " + cus[countChoice].getCustomerNAME() + " does not have enough balance to pay the rental RM" + toString(total_pay) + " for the homestay at " + homePtr->getHomeAddress() + " for " + toString(duration) + " months stay" << endl;

			}
			
			break;
		
		}




	
	system("pause");
	manage_booking();

}

void staff::edit_booking(){
	cout << "**********************************************************" << endl;
	cout << "-----------Below are all the booking information----------" << endl;
	cout <<"**********************************************************" << endl;
	booking bObj;
	bObj.displayDetail();


	string booking_id;
	string home_id;
	string client_id;//owner id
	string customer_id;// customer who rent the room from owner
	char type;//daily:d   weekly:w    monthly:m
	double duration;//
	string chk_in; string chk_out;
	double unit_price; //
	double total_paid;



	cout << "Key in Booking ID to edit..."<< endl;
	cin >> booking_id;


	cout << "Now choose the new home-ID ..." << endl;
	cout << "*****************************" << endl;
	home h;
	h.displayDetail();
	cout << "*Enter the new Home ID->*" << endl;
	cin >> home_id;
	h.displaySpecificRoom(home_id);

	string home_address; int no_room; int no_bath_room; int max_capacity; double sq_ft; string facility; string description; string owner_id;
	double day_price; double week_price; double month_price;

	ifstream readHomeEdit("dbhome/"+home_id+".txt");
	while (readHomeEdit>>home_id>>home_address>>no_room>>no_bath_room>>max_capacity>>sq_ft>>facility>>description>>owner_id>>day_price>>week_price>>month_price){
		h.setHomeID(home_id); h.setHomeAddress(home_address); h.setNoRoom(no_room); h.setNoBathRoom(no_bath_room); h.setMaxCapacity(max_capacity); h.setSize(sq_ft); h.facility = facility; h.description = description; h.owner_id = owner_id; h.day_price = day_price; h.week_price = week_price; h.month_price = month_price;


	}
	readHomeEdit.close();

	cout << "Now enter the new Owner-ID of the new home book based on list above.." << endl;
	cout << "*********************************************************************" << endl;
	cin >> client_id;
	

	cout << "Who is booking this? ->Please choose one customer id from below" << endl;

	string l = "";
	int number_of_lines = 0;
	ifstream readLine("dbcustomer/db_customer.txt");
	if (readLine.is_open()){
		while (!readLine.eof()){
			getline(readLine, l);
			// cout << l << endl;
			number_of_lines++;
		}
		// myfile.close();
	}readLine.close();


enterAgain:
	ifstream readcustomerId("dbcustomer/db_customer.txt");
	customer cus[100];
	string customerID;
	string customerName; string customerIC; string customerContact; string customerEmail; string customerAddress;
	string customerBankAcct; string customerBank; double customerCredit; string customerPwd;
	int m = 0;
	while (readcustomerId >> customerID >> customerName >> customerIC >> customerContact >> customerEmail >> customerAddress >> customerBankAcct >> customerBank >> customerCredit >> customerPwd){
		// cout << customerID << endl;
		cus[m].setCustomerID(customerID);
		cus[m].setCustomerNAME(customerName);
		cus[m].setCustomerPASSPORT(customerIC);
		cus[m].setCustomerCONTACT(customerContact);
		cus[m].setCustomerEMAIL(customerEmail);
		cus[m].setCustomerADDRESS(customerAddress);
		cus[m].setCustomerBANKACCT(customerBankAcct);

		cus[m].setCustomerBANK(customerBank);
		cus[m].setCustomerCREDIT(customerCredit);

		cus[m].setCustomerPWD(customerPwd);

		m++;
	}readcustomerId.close();
	cout << "Following are the list of customer's ID, You must set one to this home of post..." << endl;
	cout << "Please Choose one by entering number of specific..." << endl;
	int iterator = 1;
	int countChoice;
	--number_of_lines;
	while (iterator <= number_of_lines){
		cout << iterator << " : ";
		cout << cus[--iterator].getCustomerID() << endl; ++iterator;
		++iterator;
	}
	cin >> countChoice;
	bool ok = true;
	if (cin.fail()){
		cin.clear();
		cin.ignore();
		cout << "Please reenter Client ID Again" << endl;
		cin >> countChoice;
		if (cin.fail()){
			ok = false;
			cin.clear();
			cin.ignore();
			cout << "Please re-enter Client ID Again! only the displayed ID are accepted!(last chance)" << endl;
			cin >> countChoice;
		}
	}
	if (!ok){
		goto enterAgain;
	}
	--countChoice;
	cout << "So you have chosen the customer ID for booking:" + cus[countChoice].getCustomerID() << endl;
	customer_id = cus[countChoice].getCustomerID();

	cout << endl; cout << endl;
	
	booking book;
	stringstream ssEdit; vector<string> chk_outresult; vector<string> chk_inresult;

	int choiceType;
	cout << "Now select type of home-rent: 1.Daily-Rent,   2.Weekly-Rent,  3.Monthly-Rent" << endl;
	cin >> choiceType;
	if (choiceType==1){
		type = 'd';

		cout << "Input the Move-in Date: " << endl;
		chk_in = book.getDateTimeIn(home_id);//dd-mm-yyyy-hh:mm
		cout << "Input the Move-Out Date: " << endl;
		chk_out = book.getDateTimeIn(home_id); //dd-mm-yyyy-hh:mm


		ssEdit = stringstream(chk_out);
		

		while (ssEdit.good())
		{
			string substr;
			getline(ssEdit, substr, '-');
			chk_outresult.push_back(substr);
		}
		//20-12-2016-14:00
		string outDay = chk_outresult[0];//20  
		string outMonth = chk_outresult[1];//12
		string outYear = chk_outresult[2];//2016
		string strTempTime = chk_outresult[3];//14:00
		

	int	outDayInt = stoi(outDay);
	int	outMonthInt = stoi(outMonth);
	int	outYearInt = stoi(outYear);





		ssEdit = stringstream(chk_in);


		while (ssEdit.good())
		{
			string substr;
			getline(ssEdit, substr, '-');
			chk_inresult.push_back(substr);
		}
		//20-12-2016-14:00
		string inDay = chk_inresult[0];//20  
		string inMonth = chk_inresult[1];//12
		string inYear = chk_inresult[2];//2016
		string strTempTime_ = chk_inresult[3];//14:00
		
		int inDayInt = stoi(inDay);
		int inMonthInt = stoi(inMonth);
		int inYearInt = stoi(inYear);


		total_paid= book.outPutTotalPay_daily(h.day_price,inDayInt,inMonthInt,inYearInt,outDayInt,outMonthInt,outYearInt);
		duration = book.getTotalDay(inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);

		book.setBookingID(booking_id); book.setHomeID(home_id); book.setBookingClientID(owner_id); book.setBookingCustomerID(customer_id);
		book.setBookingType('d'); book.setStayDuration(duration); book.setChkIn(chk_in); book.setChkOut(chk_out); book.setUnitPirce(h.day_price);
		book.setTotalPaid(total_paid);





		ofstream tempPofolio("dbbooking/tempPofolio.txt");

		ofstream temp("dbbooking/temp.txt");
		ifstream bookingD("dbbooking/db_booking.txt");
		if (tempPofolio.is_open() && bookingD.is_open() && temp.is_open()){

			string line;
			while (getline(bookingD, line))
			{
				if (line.find(booking_id) == string::npos) { //str.find(str2) != string::npos
					temp << line << endl;

				}
				else
				{

					tempPofolio << booking_id << ' ' << space_underscore(book.getHomeID()) << ' ' << space_underscore(book.getBookingClientID()) << ' ' << space_underscore(book.getBookingcustomerID()) << ' ' << type << ' ' << duration << ' ' << book.getBookingChkIn() << ' ' << book.getBookingChkOut() << ' ' << book.getUnitPrice()<< ' ' << book.getTotalPaid() << endl;
					temp << booking_id << ' ' << space_underscore(book.getHomeID()) << ' ' << space_underscore(book.getBookingClientID()) << ' ' << space_underscore(book.getBookingcustomerID()) << ' ' << type << ' ' << duration << ' ' << book.getBookingChkIn() << ' ' << book.getBookingChkOut() << ' ' << book.getUnitPrice() << ' ' << book.getTotalPaid() << endl;
				}
			}

		}
		tempPofolio.close();
		//bookingPort.close();
		bookingD.close();

		temp.close();




		string db_old_file = "dbbooking/db_booking.txt";

		remove(db_old_file.c_str());//delete the old db file first

		string filePortfolio = "dbbooking/"+booking_id+".txt";
		//system("del dbclient/db_client.txt");
		remove(filePortfolio.c_str());

		rename("dbbooking/tempPofolio.txt", filePortfolio.c_str());
		rename("dbbooking/temp.txt", "dbbooking/db_booking.txt");
		//******

		cout << "You have updated the booking with " + booking_id + " ";





	}
	else if (choiceType == 2){
		type = 'w';
		chk_in = book.getDateTimeIn(home_id);
		chk_out = book.getDateTimeIn(home_id);


		ssEdit = stringstream(chk_out);


		while (ssEdit.good())
		{
			string substr;
			getline(ssEdit, substr, '-');
			chk_outresult.push_back(substr);
		}
		//20-12-2016-14:00
		string outDay = chk_outresult[0];//20  
		string outMonth = chk_outresult[1];//12
		string outYear = chk_outresult[2];//2016
		string strTempTime = chk_outresult[3];//14:00


		int	outDayInt = stoi(outDay);
		int	outMonthInt = stoi(outMonth);
		int	outYearInt = stoi(outYear);





		ssEdit = stringstream(chk_in);


		while (ssEdit.good())
		{
			string substr;
			getline(ssEdit, substr, '-');
			chk_inresult.push_back(substr);
		}
		//20-12-2016-14:00
		string inDay = chk_inresult[0];//20  
		string inMonth = chk_inresult[1];//12
		string inYear = chk_inresult[2];//2016
		string strTempTime1 = chk_inresult[3];//14:00

		int inDayInt = stoi(inDay);
		int inMonthInt = stoi(inMonth);
		int inYearInt = stoi(inYear);


		total_paid = book.outPutTotalPay_weekly(h.week_price, inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);
		duration = book.getTotalWeek(inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);

		book.setBookingID(booking_id); book.setHomeID(home_id); book.setBookingClientID(owner_id); book.setBookingCustomerID(customer_id);
		book.setBookingType('w'); book.setStayDuration(duration); book.setChkIn(chk_in); book.setChkOut(chk_out); book.setUnitPirce(h.week_price);
		book.setTotalPaid(total_paid);





		ofstream tempPofolio("dbbooking/tempPofolio.txt");

		ofstream temp("dbbooking/temp.txt");
		ifstream bookingD("dbbooking/db_booking.txt");
		if (tempPofolio.is_open() && bookingD.is_open() && temp.is_open()){

			string line;
			while (getline(bookingD, line))
			{
				if (line.find(booking_id) == string::npos) { //str.find(str2) != string::npos
					temp << line << endl;

				}
				else
				{

					tempPofolio << booking_id << ' ' << space_underscore(book.getHomeID()) << ' ' << space_underscore(book.getBookingClientID()) << ' ' << space_underscore(book.getBookingcustomerID()) << ' ' << type << ' ' << duration << ' ' << book.getBookingChkIn() << ' ' << book.getBookingChkOut() << ' ' << book.getUnitPrice() << ' ' << book.getTotalPaid() << endl;
					temp << booking_id << ' ' << space_underscore(book.getHomeID()) << ' ' << space_underscore(book.getBookingClientID()) << ' ' << space_underscore(book.getBookingcustomerID()) << ' ' << type << ' ' << duration << ' ' << book.getBookingChkIn() << ' ' << book.getBookingChkOut() << ' ' << book.getUnitPrice() << ' ' << book.getTotalPaid() << endl;
				}
			}

		}
		tempPofolio.close();
		//bookingPort.close();
		bookingD.close();

		temp.close();




		string db_old_file = "dbbooking/db_booking.txt";

		remove(db_old_file.c_str());//delete the old db file first

		string filePortfolio = "dbbooking/" + booking_id + ".txt";
		//system("del dbclient/db_client.txt");
		remove(filePortfolio.c_str());

		rename("dbbooking/tempPofolio.txt", filePortfolio.c_str());
		rename("dbbooking/temp.txt", "dbbooking/db_booking.txt");
		//******

		cout << "You have updated the booking with " + booking_id + " ";




	}
	else{
		type = 'm';
		chk_in = book.getDateTimeIn(home_id);
		chk_out = book.getDateTimeIn(home_id);


		ssEdit = stringstream(chk_out);


		while (ssEdit.good())
		{
			string substr;
			getline(ssEdit, substr, '-');
			chk_outresult.push_back(substr);
		}
		//20-12-2016-14:00
		string outDay = chk_outresult[0];//20  
		string outMonth = chk_outresult[1];//12
		string outYear = chk_outresult[2];//2016
		string strTempTime = chk_outresult[3];//14:00


		int	outDayInt = stoi(outDay);
		int	outMonthInt = stoi(outMonth);
		int	outYearInt = stoi(outYear);





		ssEdit = stringstream(chk_in);


		while (ssEdit.good())
		{
			string substr;
			getline(ssEdit, substr, '-');
			chk_inresult.push_back(substr);
		}
		//20-12-2016-14:00
		string inDay = chk_inresult[0];//20  
		string inMonth = chk_inresult[1];//12
		string inYear = chk_inresult[2];//2016
		string str_TempTime = chk_inresult[3];//14:00

		int inDayInt = stoi(inDay);
		int inMonthInt = stoi(inMonth);
		int inYearInt = stoi(inYear);


		total_paid = book.outPutTotalPay_monthly(h.month_price, inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);
		duration = book.getTotalMonth(inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);

		book.setBookingID(booking_id); book.setHomeID(home_id); book.setBookingClientID(owner_id); book.setBookingCustomerID(customer_id);
		book.setBookingType('m'); book.setStayDuration(duration); book.setChkIn(chk_in); book.setChkOut(chk_out); book.setUnitPirce(h.month_price);
		book.setTotalPaid(total_paid);





		ofstream tempPofolio("dbbooking/tempPofolio.txt");

		ofstream temp("dbbooking/temp.txt");
		ifstream bookingD("dbbooking/db_booking.txt");
		if (tempPofolio.is_open() && bookingD.is_open() && temp.is_open()){

			string line;
			while (getline(bookingD, line))
			{
				if (line.find(booking_id) == string::npos) { //str.find(str2) != string::npos
					temp << line << endl;

				}
				else
				{

					tempPofolio << booking_id << ' ' << space_underscore(book.getHomeID()) << ' ' << space_underscore(book.getBookingClientID()) << ' ' << space_underscore(book.getBookingcustomerID()) << ' ' << type << ' ' << duration << ' ' << book.getBookingChkIn() << ' ' << book.getBookingChkOut() << ' ' << book.getUnitPrice() << ' ' << book.getTotalPaid() << endl;
					temp << booking_id << ' ' << space_underscore(book.getHomeID()) << ' ' << space_underscore(book.getBookingClientID()) << ' ' << space_underscore(book.getBookingcustomerID()) << ' ' << type << ' ' << duration << ' ' << book.getBookingChkIn() << ' ' << book.getBookingChkOut() << ' ' << book.getUnitPrice() << ' ' << book.getTotalPaid() << endl;
				}
			}

		}
		tempPofolio.close();
		//bookingPort.close();
		bookingD.close();

		temp.close();




		string db_old_file = "dbbooking/db_booking.txt";

		remove(db_old_file.c_str());//delete the old db file first

		string filePortfolio = "dbbooking/" + booking_id + ".txt";
		//system("del dbclient/db_client.txt");
		remove(filePortfolio.c_str());

		rename("dbbooking/tempPofolio.txt", filePortfolio.c_str());
		rename("dbbooking/temp.txt", "dbbooking/db_booking.txt");
		//******

		cout << "You have updated the booking with " + booking_id + " ";










	}






}




void staff::list_booking(){
	booking book;
	cout << "**********************************************"<< endl;
	cout << "***Following are the entire list of Booking***" << endl;
	cout << "**********************************************" << endl;

	book.displayDetail();
}
	
void staff::delete_booking(){
	list_booking();
	cout << "Enter the Booking ID Wanted to delete..." << endl;
	string booking_id;
	cin >> booking_id;



	string home_id;
	string client_id;//owner id
	string customer_id;// customer who rent the room from owner
	char type;//daily:d   weekly:w    monthly:m
	double duration;//
	string chk_in; string chk_out;
	double unit_price; //
	double total_paid;

	//******

	string booking_id_r = "";
	string home_id_r = "";
	string client_id_r = "";
	string customer_id_r = "";
	string type_r = "";
	string duration_r = "";//
	string chk_in_r = "";
	string chk_out_r = "";
	string unit_price_r = ""; //
	string total_paid_r = "";


	
	ifstream readBooking("dbbooking/db_booking.txt");
	
	while (readBooking >> booking_id >> home_id >> client_id >> customer_id >> type >> duration >> chk_in >> chk_out >> unit_price >> total_paid){

		if (booking_id.length()>booking_id_r.length()){
			booking_id_r = booking_id;
		}
		if (home_id.length()>home_id_r.length()){
			home_id_r = home_id;
		}
		if (client_id.length()>client_id_r.length()){
			client_id_r = client_id;
		}
		if (customer_id.length()>customer_id_r.length()){
			customer_id_r = customer_id;
		}

		stringstream ssType;
		ssType << type;
		string str_type = ssType.str();
		if (str_type.length()>type_r.length()){
			type_r = str_type;
		}

		stringstream ssDuration;
		ssDuration << duration;
		string str_duration = ssDuration.str();
		if (str_duration.length()>duration_r.length()){
			duration_r = str_duration;
		}


		if (chk_in.length()>chk_in_r.length()){
			chk_in_r = chk_in;
		}
		if (chk_out.length()>chk_out_r.length()){
			chk_out_r = chk_out;
		}

		stringstream ssUnitPrice;
		ssUnitPrice << unit_price;
		string str_unitPrice = ssUnitPrice.str();
		if (str_unitPrice.length()>unit_price_r.length()){
			unit_price_r = str_unitPrice;
		}

		stringstream ssTotalPay;
		ssTotalPay << total_paid;
		string str_total_paid = ssTotalPay.str();
		if (str_total_paid.length()>total_paid_r.length()){
			total_paid_r = str_total_paid;
		}

	}readBooking.close();

	cout << "Booking-ID";
	for (int i = 0; i < booking_id_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Home-ID";
	for (int i = 0; i < home_id_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Client-ID";
	for (int i = 0; i < client_id_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Customer-ID";
	for (int i = 0; i < customer_id_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Booking-Type";
	for (int i = 0; i < type_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Duration";
	for (int i = 0; i < duration_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Chk_in_DateTime";
	for (int i = 0; i < chk_in_r.length() ; i++){
		cout << " ";
	}
	cout << "Chk_out_DateTime";
	for (int i = 0; i < chk_out_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Unit-Price";
	for (int i = 0; i < unit_price_r.length() + 5; i++){
		cout << " ";
	}
	cout << "Total-Paid";
	for (int i = 0; i < total_paid_r.length()+5; i++){
		cout << " ";
	}cout << endl;
	for (int i = 0; i < 200; i++){
		cout << "*";
	}
	cout << endl;


	ifstream deleteStream("dbbooking/"+booking_id+".txt");
	while (deleteStream >> booking_id >> home_id >> client_id >> customer_id >> type >> duration >> chk_in >> chk_out >> unit_price >> total_paid){
		cout << booking_id;
		for (int i = 0; i < booking_id_r.length()-booking_id.length()+15; i++){
			cout << " ";
		}
		cout << home_id;
		for (int i = 0; i < home_id_r.length()-home_id.length()+15; i++){
			cout << " ";
		}
		cout << client_id;
		for (int i = 0; i < client_id_r.length()-client_id.length()+15; i++){
			cout << " ";
		}
		cout << customer_id;
		for (int i = 0; i < customer_id_r.length() - customer_id.length()+15; i++){
			cout << " ";
		}
		cout << type;
		for (int i = 0; i < type_r.length() - (toString(type)).length()+15; i++){
			cout << " ";
		}

		cout << duration;
		for (int i = 0; i < duration_r.length() - (toString(duration)).length()+15; i++){
			cout << " ";
		}
		cout << chk_in;
		for (int i = 0; i < chk_in_r.length() - chk_in.length()+15; i++){
			cout << " ";
		}
		cout << chk_out;
		for (int i = 0; i < chk_out_r.length() - chk_out.length()+20; i++){
			cout << " ";
		}

		cout << unit_price;
		for (int i = 0; i < unit_price_r.length() - (toString(unit_price)).length()+15; i++){
			cout << " ";
		}

		cout << total_paid;
		for (int i = 0; i < total_paid_r.length() - (toString(total_paid)).length()+5; i++){
			cout << " ";
		}
		cout << endl;

	}
	deleteStream.close();

	char choice;
	cout <<"Are you sure want to delete this? this process would not be revert back anymore![Y/N]" << endl;
	cin >> choice;
	if (choice =='y' || choice=='Y'){
	


		ofstream temp("dbbooking/temp.txt");
		ifstream bookingD("dbbooking/db_booking.txt");
		if (bookingD.is_open() && temp.is_open()){

			string line;
			while (getline(bookingD, line))
			{
				if (line.find(booking_id) == string::npos) { //str.find(str2) != string::npos =-1  means not found
					//only copy data that is not the key have entered!
					temp << line << endl;//copy&write to temp

				}
				else if (line.find(booking_id) != string::npos)
				{

					//do nothing , and not copy to the new database file so that we deleted the intended row in our new db
				}
			}

		}


		bookingD.close();


		temp.close();

		//dir.close();
		string db_old_file = "dbbooking/db_booking.txt";
		
		// const char *data = "dbhome/db_home.txt";
		remove(db_old_file.c_str());//delete the old db file first
	

		string portfolioFile = "dbbooking/"+booking_id+".txt";

		const char *data = portfolioFile.c_str();
		remove(data);
		//portfolioFile
		rename("dbbooking/temp.txt", "dbbooking/db_booking.txt");


		cout << "You have successfully deleted this booking record." << endl;




	
	}
	else{
		manage_booking();
	
	}



}
void staff::update_facility(){
	string facilityItem;
	string facility[100];
	ifstream readFacility("dbhome/facility.txt");
	int count = 0;
	while (readFacility>>facilityItem){
		facility[count] = facilityItem;
		++count;
	}
	readFacility.close();

	cout << "Hi Staff "+sta.sessionNAME+"" << endl;
	cout << "This is the facility items management panel" << endl;
	cout << "===========================================" << endl;
	cout << "(Note*** : You can edit the items in this facility items list, so that people who post their house/room, they could include these facility into.)" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Note that current Facility Item are limited to 10 items, user can maximumly include only 5 in their posting" << endl;
	cout << "The current Facility Item list are:" << endl;

	for (int r = 0; r < 10;r++){
		int show = r + 1;
		cout << show;
		cout << ".";
		cout<< ' ' << facility[r] << endl;
	
	}

	string option;
	cout << "Do you want to update these facility list into a new one? [Y/N]"<< endl;
	cin >> option; cin.ignore(1, '\n');//solution of getline skip the first input
	if (option=="y" || option=="Y"){
		ofstream temp("dbhome/temp.txt");
		ifstream facilityD("dbhome/facility.txt");
		string newFacility[10];
		for (int w = 0; w < 10;w++){
			int show = w + 1;
			string tem;
			cout << "Enter New Facility Item Number " + toString(show) + "";
			cout << ":" << endl;
			//cin.get();
			getline(cin, newFacility[w]);
			temp << space_underscore(newFacility[w]) <<endl;
		}

		facilityD.close();

		temp.close();


		string db_old_file = "dbhome/facility.txt";

		// const char *data = "dbhome/db_home.txt";
		remove(db_old_file.c_str());//delete the old db file first

		rename("dbhome/temp.txt", "dbhome/facility.txt");
		//******


		cout << "You have updated the facility list." << endl;

	}
	else{
		cout << "The original facility list remains intact."<< endl;
	
	}

	system("pause");
	staff_main(sta.sessionID,sta.sessionNAME);

}



void staff::staff_main(string staff_id, string staff_name){

													app a;
													sta.sessionID = staff_id;
													sta.sessionNAME = staff_name;

													system("cls");
													cout << "-----------Welcome staff: " + staff_name + "-----------" << endl;
													cout << "-----------Staff Management Console----------" << endl;
													system("color 0a");
													cout << "Please enter your choice" << endl;
													cout << "1.Manage Your Own Profile" << endl;
													cout << "2.Manage Staff" << endl;
													cout << "3.Manage Client" << endl;
													cout << "4.Manage Customer" << endl;
													cout << "5.Manage Home Stay" << endl;
													cout << "6.Manage Booking" << endl;
													cout << "7.Update Facility List" << endl;
													cout << "8.<<Log out" << endl;

													int choice;
													cin >> choice;

													switch (choice){
													case 1:
												sta.manage_profile(staff_id, staff_name);
													break;
													case 2:
													manage_staff();
													break;
													case 3:
													manage_client();
													break;
													case 4:
													manage_customer();
													break;
													case 5:
													manage_home();
													break;

													case 6:
													manage_booking();
													break;
													case 7:
														update_facility();
														break;
													case 8:
													a.main();
													//staff_main(sta.sessionID,sta.sessionNAME);
													break;

													default:
													cout << "Pls choose beween interger 1 ~ 7 only" << endl;
													}
													}
