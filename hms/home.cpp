


#pragma once

#include "targetver.h"

#include "stdafx.h"
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



home::home(){}
home::home(string homeID, string home_address, int noRoom, int noBathRoom, int maxCapacity, double sqft, string facility, string desc, string ownerID, double dayPrice, double weekPrice, double monthPrice){
	this->home_id = homeID; this->home_address = home_address; this->no_room = noRoom; this->no_bath_room = noBathRoom; this->max_capacity = maxCapacity; this->sq_ft = sqft; this->facility = facility;
	this->description = desc; this->owner_id = ownerID;  this->day_price = dayPrice; this->week_price = weekPrice; this->month_price = monthPrice;
}


// c->setAll(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

home::home(client *c, string client_id, string  client_name, string  client_ic, string  client_contact, string  client_email, string  client_address, string client_bank_account, string  client_bank, double client_credit, string client_pwd, string homeID, string home_address, int noRoom, int noBathRoom, int maxCapacity, double sqft, string facility, string desc, string ownerID, double dayPrice, double weekPrice, double monthPrice){
	c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);
	this->home_id = homeID; this->home_address = home_address; this->no_room = noRoom; this->no_bath_room = noBathRoom; this->max_capacity = maxCapacity; this->sq_ft = sqft; this->facility = facility;
	this->description = desc; this->owner_id = ownerID;  this->day_price = dayPrice; this->week_price = weekPrice; this->month_price = monthPrice;

}



home::~home(){}

void home::setHome(string homeID, string home_address, int noRoom, int noBathRoom, int maxCapacity, double sqft, string facility, string desc, string ownerID, double dayPrice, double weekPrice, double monthPrice){
	this->home_id = homeID; this->home_address = home_address; this->no_room = noRoom; this->no_bath_room = noBathRoom; this->max_capacity = maxCapacity; this->sq_ft = sqft; this->facility = facility;
	this->description = desc; this->owner_id = ownerID;  this->day_price = dayPrice; this->week_price = weekPrice; this->month_price = monthPrice;

}
//composition of         ->>>>>>    booking and home


string home::getHomeID(){ return this->home_id; }
string home::getHomeAddress(){ return this->home_address; }
int home::getNoRoom(){ return this->no_room; }
int home::getNoBathRoom(){ return this->no_bath_room; }
int home::getMaxCapacity(){ return this->max_capacity; }
double home::getSizeSqFt(){ return this->sq_ft; }

void home::setHomeID(string homeID){ this->home_id = homeID; }
void home::setHomeAddress(string home_address){ this->home_address = home_address; }
void home::setNoRoom(int noRoom){ this->no_room = noRoom; }
void home::setNoBathRoom(int noBathRoom){ this->no_bath_room = noBathRoom; }
void home::setMaxCapacity(int maxCapacity){ this->max_capacity = maxCapacity; }
void home::setSize(double sqft){ this->sq_ft = sqft; }
string home::getComment(){ return this->comment; }
string home::getCommentID(){ return this->commentID; }


void home::setCommentID(string cmtID){ this->commentID = cmtID; }

void home::setComment(string cmt){ this->comment = cmt; }

void home::displayComment(){

	ifstream homeRead("dbhome/db_home.txt");
	ifstream commentRead("dbhome/comment.txt");

	string home_id; string home_address; string home_facility; string owner_id;
	string home_description; string comment;

	string home_id_r = ""; string home_address_r = ""; string home_facility_r = ""; string owner_id_r = "";
	string home_description_r = ""; string comment_r = "";

	home hme[200];

	int no_room; int no_bath_room; int max_capacity; double sq_ft;
	double day_price; double month_price; double week_price;
	string commentID; string commentID_r = "";

	int count = 0;
	while (commentRead >> commentID >> home_id >> home_address >> home_facility >> home_description >> owner_id >> comment){
		if (commentID.length()>commentID_r.length()){
			commentID_r = commentID;
		}
		if (home_id.length()>home_id_r.length()){
			home_id_r = home_id;
		}
		if (home_address.length()>home_address_r.length()){
			home_address_r = home_address;
		}
		if (home_facility.length()>home_facility_r.length()){
			home_facility_r = home_facility;
		}
		if (home_description.length()>home_description_r.length()){
			home_description_r = home_description;
		}
		if (owner_id.length()>owner_id_r.length()){
			owner_id_r = owner_id;
		}
		if (comment.length()>comment_r.length()){
			comment_r = comment;
		}

		hme[count].setCommentID(commentID);
		hme[count].setHomeID(home_id); hme[count].setHomeAddress(home_address); hme[count].facility = home_facility;
		hme[count].description = home_description;   hme[count].owner_id = owner_id;
		hme[count].setComment(comment);

		++count;
	}
	homeRead.close();

	commentRead.close();

	cout << "Following are the comments about the available rooms in Felice System" << endl;
	cout << endl;
	cout << "=====================================================================" << endl;
	cout << "Comment-ID";
	for (int i = 0; i < commentID_r.length() + 3; i++){
		cout << " ";
	}
	cout << "Home-ID";
	for (int i = 0; i < home_id_r.length() + 4; i++){
		cout << " ";
	}
	cout << "Home-Address";
	for (int i = 0; i < home_address_r.length(); i++){
		cout << " ";
	}
	cout << "Home-Facility";
	for (int i = 0; i < home_facility_r.length(); i++){
		cout << " ";
	}
	cout << "Home-Description";
	for (int i = 0; i < home_description_r.length(); i++){
		cout << " ";
	}
	cout << "Home-Owner-ID";
	for (int i = 0; i < owner_id_r.length() + 8; i++){
		cout << " ";
	}
	cout << "*Comments*";
	for (int i = 0; i < comment_r.length(); i++){
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 200; i++){
		cout << "=";
	}
	cout << endl;



	for (int n = 0; n < count; n++){
		cout << hme[n].getCommentID();
		for (int i = 0; i < commentID_r.length() - (hme[n].getCommentID().length()) + 13; i++){
			cout << " ";
		}
		cout << hme[n].getHomeID();
		for (int i = 0; i < home_id_r.length() - (hme[n].getHomeID().length()) + 10; i++){
			cout << " ";
		}
		cout << hme[n].getHomeAddress();
		for (int i = 0; i < home_address_r.length() - (hme[n].getHomeAddress().length()) + 10; i++){
			cout << " ";
		}
		cout << hme[n].facility;
		for (int i = 0; i < home_facility_r.length() - (toString(hme[n].facility).length()) + 10; i++){
			cout << " ";
		}
		cout << hme[n].description;
		for (int i = 0; i < home_description_r.length() - (hme[n].description.length()) + 22; i++){
			cout << " ";
		}
		cout << hme[n].owner_id;
		for (int i = 0; i < owner_id_r.length() - (hme[n].owner_id.length()) + 13; i++){
			cout << " ";
		}
		cout << hme[n].getComment();
		cout << endl;
		cout << endl;

	}
}




void home::delete_home_compositionBooking(string bookingV[], home &selectedHome){



	string home_id; string home_address;
	int no_room; int no_bath_room; int max_capacity;

	double sq_ft;

	string facility;
	string description;
	string owner_id;

	double day_price; double week_price; double month_price;


	string decision;

	stringstream ss;//stringstream ss;
	ss << selectedHome.getHomeID();
	//cout << this->getHomeID() << endl;

	string home_idS = ss.str();
	string home_id2 = ss.str();

	home_id2.append(".txt");

	string portfolioFile = "dbhome/" + home_id2;
	//composition logic
	cout << "!!**Warning, This is operation is dangerous! delete the home, all realated booking would  also be deleted!";
	cout << "==========================================================================================================";

	//*******************
	bool chkBooking = false;
	int countBooking = 0;

	string bookingID;
	string homeID;
	string clientID; string customerID; char type; double duration; string chk_in; string chk_out; double unitPrice; double  totalPaid;

	ifstream validateB("dbbooking/db_booking.txt");
	while (validateB >> bookingID >> homeID >> clientID >> customerID >> type >> duration >> chk_in >> chk_out >> unitPrice >> totalPaid){
		stringstream chks;
		chks << homeID;
		string sthrw = chks.str();
		if (home_idS == sthrw){

			chkBooking = true;
			//cout << "888" << endl;
			bookingV[countBooking] = bookingID;
			++countBooking;
		}

	}validateB.close();


	cout << endl;
	cout << "" + toString(countBooking) + " amount of booking records have found that was booked with home-id " + home_idS + ", all those related booking would be deleted";
	cout << endl;
	cout << "===========================================================================================================================================================================";

	cout << endl;
	cout << "=======The following booking info would be deleted=======";

	cout << endl;
	ifstream validateBooking("dbbooking/db_booking.txt");
	int c = 0;
	while (validateBooking >> bookingID >> homeID >> clientID >> customerID >> type >> duration >> chk_in >> chk_out >> unitPrice >> totalPaid){
		stringstream chks;
		chks << bookingID;
		string sthrw = chks.str();
		if (sthrw == bookingV[c]){

			cout << bookingID << "  " << homeID << "  " << clientID << "  " << customerID << "  " << type << "  " << duration << "  " << chk_in << "  " << chk_out << "  " << unitPrice << "  " << totalPaid << endl;
			++c;
		}

	}validateBooking.close();

	cout << endl;

	cout << "=========================================================================================================================" << endl;;


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
	validateBooking.close();
	validateB.close();
	//cout << home_id << endl;

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

	home hObj;

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

			hObj.setHomeID(home_id);


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
			for (int z = 0; z < (home_max_capacity_r.length() + 16); z++){
				cout << " ";
			}
			cout << sq_ft;
			for (int z = 0; z < (home_sq_ft_r.length() + 22); z++){
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
			for (int z = 0; z < (home_day_price_r.length() + 4); z++){
				cout << " ";
			}
			cout << week_price;
			for (int z = 0; z < (home_week_price_r.length() + 4); z++){
				cout << " ";
			}
			cout << month_price;
			for (int z = 0; z < (home_month_price_r.length()); z++){
				cout << " ";
			}

			cout << endl;



			//print out original data

		}
		if (decision == "n"){
			//	staff::manage_home();
		}





		cout << "Do you wish to delete this home data and related booking from the database?[y/n]" << endl;
		cin >> decision;
		if (decision == "y" || decision == "Y"){



			ofstream tempBook("dbbooking/booking.txt");
			ifstream bookD("dbbooking/db_booking.txt");
			if (bookD.is_open() && tempBook.is_open()){

				string line;

				while (getline(bookD, line))
				{

					int checker = 0;
					cout << countBooking << endl;;
					for (int q = 0; q < countBooking; ++q){
						//	cout << bookingV[q] << endl;
						if (line.find(bookingV[q]) == string::npos) { //str.find(str2) != string::npos =-1  means not found
							++checker;//not found record, copy to new db
						}
						else if (line.find(bookingV[q]) != string::npos){
							//found record, but dothing to the new db
						}
					}


					if (checker == (countBooking)) { //str.find(str2) != string::npos =-1  means not found
						//only copy data that is not the key have entered!
						tempBook << line << endl;//copy&write to temp

					}
					else if(checker == false){

						//do nothing
					}




				}

			}




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
					else if (line.find(home_idS) != string::npos)
					{

						//do nothing , and not copy to the new database file so that we deleted the intended row in our new db
					}
				}

			}

		
		homeD.close();


		temp.close();

		bookD.close();


		tempBook.close();

		dir.close();
		string db_old_file = "dbhome/db_home.txt";
		//system("del dbstaff/db_staff.txt");
		const char *data_home = "dbhome/db_home.txt";
		remove(data_home);//delete the old db file first



		string db_old_file_book = "dbbooking/db_booking.txt";
		//system("del dbstaff/db_staff.txt");
		// const char *data = "dbhome/db_home.txt";
		remove(db_old_file_book.c_str());//delete the old db file first
		//system("del dbstaff/db_staff");



		const char *data = portfolioFile.c_str();
		remove(data);


		for (int w = 0; w < countBooking; ++w){
			string bookingFile = "dbbooking/" + bookingV[w] + ".txt";
			const char *dataB = bookingFile.c_str();
			remove(dataB);
		}



		//portfolioFile
		rename("dbhome/temp.txt", "dbhome/db_home.txt");
		rename("dbbooking/booking.txt", "dbbooking/db_booking.txt");


	}


	//system("pause");
	//manage_home();
}
}

  void home::displayDetail(){
	 // system("cls");
	  string home_id;
	  string home_address;
	  int no_room; int no_bath_room; int max_capacity;

	  double sq_ft;

	  string facility;
	  string description;
	  string owner_id;

	  double day_price; double week_price; double month_price;

	  cout << "Available Home Stay List" << endl;
	  cout << "------------------------" << endl;
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
  }




  void home::displaySpecificRoom(string house_id){
	  system("cls");
	  string home_id = house_id;
	  string home_address;
	  int no_room; int no_bath_room; int max_capacity;

	  double sq_ft;

	  string facility;
	  string description;
	  string owner_id;

	  double day_price; double week_price; double month_price;

	  cout << "Available Home Stay List" << endl;
	  cout << "------------------------" << endl;
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


	  ifstream dir1("dbhome/" + house_id + ".txt");

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
  }
