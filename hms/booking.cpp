






#pragma once

#include "targetver.h"

#include "stdafx.h"
#include "booking.h"

#include <iomanip>
#include <ctime>
#include <time.h>

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




string booking::getBookingID(){ return booking_id; }string booking::getBookingHomeID(){ return home_id; }	string booking::getBookingcustomerID(){ return customer_id; }string booking::getBookingClientID(){ return client_id; }

char booking::getBookingType(){ return type; }double booking::getBookingDuration(){ return duration; }

string booking::getBookingChkIn(){ return chk_in; }string booking::getBookingChkOut(){ return chk_out; }

double booking::getUnitPrice(){ return unit_price; }double booking::getTotalPaid(){ return total_paid; }
//

void booking::setBookingID(string bookingID){ booking_id = bookingID; }
void booking::setBookingHomeID(string homeID){ home_id = homeID; }
void booking::setBookingClientID(string clientID){ client_id = clientID; }
void booking::setBookingCustomerID(string customerID){ customer_id = customerID; }

void booking::setBookingType(char type){ type = type; }
void booking::setStayDuration(double duration){ duration = duration; }
void booking::setChkIn(string chkIn){ chk_in = chkIn; }

void booking::setChkOut(string chkOut){ chk_out = chkOut; }
void booking::setUnitPirce(double unitPrice){ unit_price = unitPrice; }

void booking::setTotalPaid(double totalPrice){ total_paid = totalPrice; }


//total 10 parameters

booking::booking(){}

booking::booking(string bookingID, string homeID, string clientID, string customerID, char type, double duration, string chk_in, string chk_out, double unitPrice, double totalPaid){
	booking_id = bookingID; home_id = homeID; client_id = clientID; customer_id = customerID; type = type; duration = duration; chk_in = chk_in;
	chk_out = chk_out; unit_price = unitPrice; total_paid = totalPaid;

}

booking::~booking(){
	//delete obj automatically , no need call delete this...or else will be recursive

}


//************8display specific based on client id

void booking::displaySpecificClientID(string clientID){



	home *home_booking = new booking;
	//**********
	string booking_id;
	
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


	booking bookingP[100];
	ifstream readBooking("dbbooking/db_booking.txt");
	int counter = 0;
	while (readBooking >> booking_id >> home_booking->home_id >> client_id >> customer_id >> type >> duration >> chk_in >> chk_out >> unit_price >> total_paid){

		if (booking_id.length()>booking_id_r.length()){
			booking_id_r = booking_id;
		}
		if (home_booking->getHomeID().length()>home_id_r.length()){
			home_id_r = home_booking->getHomeID();
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


		bookingP[counter].setBookingID(booking_id);
		bookingP[counter].setHomeID(home_booking->getHomeID());
		bookingP[counter].client_id = client_id;
		bookingP[counter].customer_id = customer_id;


		bookingP[counter].type = type;
		bookingP[counter].duration = duration;
		bookingP[counter].chk_in = chk_in;
		bookingP[counter].chk_out = chk_out;
		bookingP[counter].unit_price = unit_price;
		bookingP[counter].total_paid = total_paid;
		++counter;
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
	for (int i = 0; i < chk_in_r.length(); i++){
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
	for (int i = 0; i < total_paid_r.length() + 5; i++){
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 220; i++){
		cout << "=";
	}cout << endl;

	for (int l = 0; l < counter; l++){

		if (clientID == bookingP[l].client_id){
			cout << bookingP[l].getBookingID();
			for (int i = 0; i < booking_id_r.length() - (bookingP[l].getBookingID()).length() + 15; i++){
				cout << " ";
			}
			cout << bookingP[l].getHomeID();
			for (int i = 0; i < home_id_r.length() - (bookingP[l].getHomeID()).length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].client_id;
			for (int i = 0; i < client_id_r.length() - (bookingP[l].client_id).length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].customer_id;
			for (int i = 0; i < customer_id_r.length() - (bookingP[l].customer_id).length() + 15; i++){
				cout << " ";
			}


			cout << bookingP[l].type;
			for (int i = 0; i < type_r.length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].duration;
			for (int i = 0; i < duration_r.length() - (toString(bookingP[l].duration)).length() + 10; i++){
				cout << " ";
			}

			cout << bookingP[l].chk_in;
			for (int i = 0; i < chk_in_r.length() - (bookingP[l].chk_in).length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].chk_out;
			for (int i = 0; i < chk_out_r.length() - (bookingP[l].chk_out).length() + 25; i++){
				cout << " ";
			}
			cout << bookingP[l].unit_price;
			for (int i = 0; i < unit_price_r.length() - (toString(bookingP[l].unit_price)).length() + 18; i++){
				cout << " ";
			}

			cout << bookingP[l].total_paid;
			for (int i = 0; i < (total_paid_r.length()) - (toString(bookingP[l].total_paid)).length() + 10; i++){
				cout << " ";
			}
			cout << " " << endl;
		}
	}





}

//**************display specific based on customer id

void booking::displaySpecificCustomerID(string customerID){


	home *home_booking = new booking;//implement friend keyword id
	//**********
	string booking_id;

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


	booking bookingP[100];
	ifstream readBooking("dbbooking/db_booking.txt");
	int counter = 0;
	while (readBooking >> booking_id >> home_booking->home_id >> client_id >> customer_id >> type >> duration >> chk_in >> chk_out >> unit_price >> total_paid){

		if (booking_id.length()>booking_id_r.length()){
			booking_id_r = booking_id;
		}
		if (home_booking->getHomeID().length()>home_id_r.length()){
			home_id_r = home_booking->getHomeID();
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


		bookingP[counter].setBookingID(booking_id);
		bookingP[counter].setHomeID(home_booking->getHomeID());
		bookingP[counter].client_id = client_id;
		bookingP[counter].customer_id = customer_id;


		bookingP[counter].type = type;
		bookingP[counter].duration = duration;
		bookingP[counter].chk_in = chk_in;
		bookingP[counter].chk_out = chk_out;
		bookingP[counter].unit_price = unit_price;
		bookingP[counter].total_paid = total_paid;
		++counter;
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
	for (int i = 0; i < chk_in_r.length(); i++){
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
	for (int i = 0; i < total_paid_r.length() + 5; i++){
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 220; i++){
		cout << "=";
	}cout << endl;

	for (int l = 0; l < counter; l++){

		if (customerID == bookingP[l].customer_id){
			cout << bookingP[l].getBookingID();
			for (int i = 0; i < booking_id_r.length() - (bookingP[l].getBookingID()).length() + 15; i++){
				cout << " ";
			}
			cout << bookingP[l].getHomeID();
			for (int i = 0; i < home_id_r.length() - (bookingP[l].getHomeID()).length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].client_id;
			for (int i = 0; i < client_id_r.length() - (bookingP[l].client_id).length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].customer_id;
			for (int i = 0; i < customer_id_r.length() - (bookingP[l].customer_id).length() + 15; i++){
				cout << " ";
			}


			cout << bookingP[l].type;
			for (int i = 0; i < type_r.length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].duration;
			for (int i = 0; i < duration_r.length() - (toString(bookingP[l].duration)).length() + 10; i++){
				cout << " ";
			}

			cout << bookingP[l].chk_in;
			for (int i = 0; i < chk_in_r.length() - (bookingP[l].chk_in).length() + 15; i++){
				cout << " ";
			}

			cout << bookingP[l].chk_out;
			for (int i = 0; i < chk_out_r.length() - (bookingP[l].chk_out).length() + 25; i++){
				cout << " ";
			}
			cout << bookingP[l].unit_price;
			for (int i = 0; i < unit_price_r.length() - (toString(bookingP[l].unit_price)).length() + 18; i++){
				cout << " ";
			}

			cout << bookingP[l].total_paid;
			for (int i = 0; i < (total_paid_r.length()) - (toString(bookingP[l].total_paid)).length() + 10; i++){
				cout << " ";
			}
			cout << " " << endl;
		}
	}





}


//***********************
//**************************
void booking::displayDetail(){

	//**********
	string booking_id;
	string home_id;
	string client_id;//owner id
	string customer_id;// customer who rent the room from owner
	char type;//daily:d   weekly:w    monthly:m
	double duration;//
	string chk_in;string chk_out;
	double unit_price; //
	double total_paid;

	//******

	string booking_id_r=""; 
	string home_id_r="";
	string client_id_r="";
	string customer_id_r="";
	string type_r="";
	string duration_r="";//
	string chk_in_r="";
	string chk_out_r="";
	string unit_price_r=""; //
	string total_paid_r="";


	booking bookingP[100];
	ifstream readBooking("dbbooking/db_booking.txt");
	int counter = 0;
	while (readBooking>> booking_id>> home_id>> client_id>>customer_id>>type>>duration>>chk_in>>chk_out>>unit_price>>total_paid){
	
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


		bookingP[counter].setBookingID(booking_id);
		bookingP[counter].setHomeID(home_id);
		bookingP[counter].client_id=client_id;
		bookingP[counter].customer_id=customer_id;


		bookingP[counter].type=type;
		bookingP[counter].duration=duration;
		bookingP[counter].chk_in=chk_in;
		bookingP[counter].chk_out=chk_out;
		bookingP[counter].unit_price=unit_price;
		bookingP[counter].total_paid =total_paid;
		++counter;
	}readBooking.close();

	cout << "Booking-ID";
	for (int i = 0; i < booking_id_r.length()+5;i++){
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
	for (int i = 0; i < total_paid_r.length() + 5; i++){
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 220; i++){
		cout << "=";
	}cout << endl; 

	for (int l = 0; l < counter;l++){
		cout<<bookingP[l].getBookingID();
		for (int i = 0; i < booking_id_r.length() -( bookingP[l].getBookingID()).length()+15; i++){
			cout << " ";
		}
		cout << bookingP[l].getHomeID();
		for (int i = 0; i < home_id_r.length() - (bookingP[l].getHomeID()).length()+15; i++){
			cout << " ";
		}

		cout << bookingP[l].client_id;
		for (int i = 0; i < client_id_r.length() - (bookingP[l].client_id).length()+15; i++){
			cout << " ";
		}

		cout << bookingP[l].customer_id;
		for (int i = 0; i < customer_id_r.length() - (bookingP[l].customer_id).length()+15; i++){
			cout << " ";
		}


		cout << bookingP[l].type;
		for (int i = 0; i < type_r.length()+15 ; i++){
			cout << " ";
		}

		cout << bookingP[l].duration;
		for (int i = 0; i < duration_r.length() - (toString(bookingP[l].duration)).length()+10; i++){
			cout << " ";
		}

		cout << bookingP[l].chk_in;
		for (int i = 0; i < chk_in_r.length() - (bookingP[l].chk_in).length()+15; i++){
			cout << " ";
		}

		cout << bookingP[l].chk_out;
		for (int i = 0; i < chk_out_r.length() - (bookingP[l].chk_out).length()+25; i++){
			cout << " ";
		}
		cout << bookingP[l].unit_price;
		for (int i = 0; i < unit_price_r.length() - (toString(bookingP[l].unit_price)).length()+18; i++){
			cout << " ";
		}

		cout << bookingP[l].total_paid;
		for (int i = 0; i < (total_paid_r.length()) - (toString(bookingP[l].total_paid)).length()+10; i++){
			cout << " " ;
		}
		cout << " " << endl;
	}



	

}




bool booking::isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear){
	int entryDate = (year * 10000) + (month * 100) + day;
	int startDate = (startYear * 10000) + (startMonth * 100) + startDay;
	int endDate = (endYear * 10000) + (endMonth * 100) + endDay;

	if (entryDate >= startDate && entryDate <= endDate){
		cout << "within range"<< endl;
		return false;//within range
	}
	else{
		cout << "not within range@@@@@@@@@" << endl;

		return true;//not in range
	}
}//reference from ::http://stackoverflow.com/questions/2557846/checking-if-parsed-date-is-within-a-date-range


//override parent method of display room, here display booking info
string booking::getDateTimeIn(string selected_home_id){
	
	
	reenterDate:
		int yearIn; int monthIn; int dayIn; string timeHourIn24;
		string datetimeHolder;
		cout << "Input the date in the format of dd-mm-yyyy   eg.  30-06-2016 (Format is important, eg.Febreuary has 28 days for common year and 29 days for leap year)" << endl;
		cin >> datetimeHolder;
	


		stringstream ss(datetimeHolder);
		vector<string> Dateresult;

		while (ss.good())
		{
			string substr;
			getline(ss, substr, '-');
			Dateresult.push_back(substr);
		}

		

		
		std::string tempDay = Dateresult[0];
		std::string tempMonth = Dateresult[1];
		std::string tempYear = Dateresult[2];
		cout << "" << endl;//tempDay
		cout << "" << endl;//tempMonth
		cout << "" << endl;//tempYear
		
	

		dayIn = stoi(tempDay);
		monthIn = stoi(tempMonth);
		yearIn = stoi(tempYear);

	

		if (validateDateTime(selected_home_id,yearIn, monthIn, dayIn) == true){
		reenterTime:

			cout << "Enter the hour can move in (24-hour format)  eg. 14:32" << endl;
			cin >> timeHourIn24;


			stringstream ss(timeHourIn24);
			vector<string> timeHourIn24result;

			while (ss.good())
			{
				string substr;
				getline(ss, substr, ':');
				timeHourIn24result.push_back(substr);
			}


			int h = stoi(timeHourIn24result[0]);
			int m = stoi(timeHourIn24result[1]);
	
			if (h>=1 && h<=24){
				if (m>=0 && m<=59){
				//int yearIn; int monthIn; int dayIn; string timeHourIn24;
					return datetimeHolder + "-" + timeHourIn24;
				}
				else{
					cout << "Minutes not in correct format! Please Re-enter"<< endl;
					goto reenterTime;
				}
			
			}
			else{
				cout << "Hour not in correct format! Please Re-enter" << endl;
				goto reenterTime;
			}



		}
		else if (validateDateTime(selected_home_id, yearIn, monthIn, dayIn) == false){
			
			cout << "The date you entered has problem! Normally is Date Formate Error, If Format of Date is Correct, then the date you have entered it might have been booked by other customers, Please re-enter!"<< endl;
			cout << "You can go to Customer Main Menu-5 To check the availability of each specific room/house..."<< endl;
			Sleep(5000);
			goto reenterDate;
		
		}
	


	}

void booking::chkAvailability(){


	cout <<"Here You can check the availability of certain home/room/house" << endl;
	cout << "You could view the booked period of certain house..." << endl;
	home h;
	h.displayDetail();
	cout << "Choose one from above available House/Room/Home By entering their Home-Id to check each specific availability.." << endl;
	string selected_home_id;
	cin >> selected_home_id; cin.ignore(1, '\n');


	string booking_id;string home_id;
	string client_id;string customer_id;
	char type;double duration;
	string chk_in;string chk_out;
	double unit_price; double total_paid;
	booking bookingObj[100];


	ifstream readBookAvailable("dbbooking/db_booking.txt");
	int count = 0;
	while (readBookAvailable >> booking_id >> home_id >> client_id >> customer_id >> type >> duration >> chk_in >> chk_out >> unit_price >> total_paid){

		if (selected_home_id==home_id)
		{
			bookingObj[count].setBookingID(booking_id);
			bookingObj[count].setHomeID(home_id);
			bookingObj[count].setBookingClientID(client_id);
			bookingObj[count].setBookingCustomerID(customer_id);
			bookingObj[count].setBookingType(type);

			bookingObj[count].setStayDuration(duration);
			bookingObj[count].setChkIn(chk_in);//***key
			bookingObj[count].setChkOut(chk_out);//key****
			bookingObj[count].setUnitPirce(unit_price);
			bookingObj[count].setTotalPaid(total_paid);


			++count;
		}


		
	}

	readBookAvailable.close();

	if (count > 0){

		cout << "" + toString(count) + " booking(s) info has found for home woth home-id:" + selected_home_id + "" << endl;
		cout << "The house/room/home with ID: " + selected_home_id + " has following duration which has been booked" << endl;
		cout << "|Booked Check-In DateTime|";
		for (int t = 0; t < 10; t++){ cout << " "; }
		cout << "|Booked Check-Out DateTime|";
		for (int t = 0; t < 10; t++){ cout << " "; }   cout << endl;


		for (int b = 0; b < count; b++){
			for (int t = 0; t < 5; t++){ cout << " "; }
			cout << bookingObj[b].chk_in;
			for (int t = 0; t < 10; t++){ cout << " "; }
			cout << "~";
			for (int t = 0; t < 10; t++){ cout << " "; }
			cout << bookingObj[b].chk_out;
			cout << endl;
		}
		cout << "========================================================================" << endl;

	}
	else{
		cout << "========================================================================" << endl;
		cout << "The Home/Room/House with Home-ID:"+selected_home_id+" HAS not been booked before, You can book at any time you wanted to!" << endl;

	
	
	}




}



bool booking::validateDateTime(string selected_home_id, int _year, int _month, int _day){
	
	//first get the booking info of the chkin and chk out date

	bool chk=true;


	string booking_id; string home_id;
	string client_id; string customer_id;
	char type; double duration;
	string chk_in; string chk_out;
	double unit_price; double total_paid;
	booking bookingObj[100];


	ifstream readBookAvailable("dbbooking/db_booking.txt");
	int count = 0;
	while (readBookAvailable >> booking_id >> home_id >> client_id >> customer_id >> type >> duration >> chk_in >> chk_out >> unit_price >> total_paid){

		if (selected_home_id == home_id)
		{
			bookingObj[count].setBookingID(booking_id);
			bookingObj[count].setHomeID(home_id);
			bookingObj[count].setBookingClientID(client_id);
			bookingObj[count].setBookingCustomerID(customer_id);
			bookingObj[count].setBookingType(type);

			bookingObj[count].setStayDuration(duration);
			bookingObj[count].setChkIn(chk_in);//***key
			bookingObj[count].setChkOut(chk_out);//key****
			bookingObj[count].setUnitPirce(unit_price);
			bookingObj[count].setTotalPaid(total_paid);


			++count;
		}


	
	}

	readBookAvailable.close();



	string chkin; string chkout;
	
	stringstream ssEdit;
	if (count > 0){
	
		for (int q = 0; q < count;++q){
			
			chkin = bookingObj[q].getBookingChkIn();
//	cout << chkin<< endl;
	//cout << bookingObj[q].getBookingChkIn() << endl;
			ssEdit = stringstream(chkin);
			vector<string> chk_inresult;
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

		

			chkout = bookingObj[q].getBookingChkOut();
			vector<string> chk_outresult;
			ssEdit = stringstream(chkout);
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



			//cout << chkin << endl;
			//cout << chkout << endl;

			chk=isDateInRange(_day, _month, _year, inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);
			if (!chk){ break; }
			
			//return	chk;//false -> within range -> not valide
			//true  not in range ->valide 
			chk_outresult.clear();
			chk_inresult.clear();
		
		}
	}








//#define TIME_MAX 32

	
		time_t now;
		time(&now);

		// 2 variable , store exchange result
		struct tm tmTmp;
		
	
	bool wrong = false;
	bool correct = true;

	time_t theTime;
	time(&theTime);
	struct tm aTime;
	localtime_s(&aTime,&theTime);

	int currentDayInt = aTime.tm_mday;
	int currentMonthInt = aTime.tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	int currentYearInt = aTime.tm_year + 1900; // Year is # years since 1900




	if (_year == currentYearInt){
		if (_month == currentMonthInt){
			if (_day < currentDayInt){
				return wrong;
			}
		}
		else if (_month<currentMonthInt){
			return wrong;
		}
	}

	if (_year >= currentYearInt){
	
		if (_year == currentYearInt ){

					if (_month == 1){
						//january always 31 days
						if (_day > 0 && _day <= 31){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}

					}
					else if (_month == 2){
						//Febuary if leap year : 29
						//if common year : 28 

						if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)){
							//leap year means 366 days which febuary has 29 days
							if (_day > 0 && _day <= 29){
								if (chk){
									return correct;
								}
								else{
									return wrong;
								}
							}
							else{
								return wrong;
							}

						}
						else{//common year 365 days which means february has 28 days
							if (_day > 0 && _day <= 28){
								if (chk){
									return correct;
								}
								else{
									return wrong;
								}
							}
							else{
								return wrong;
							}
						}
						

					}
					else if (_month == 3){
						//March always 31 days
						if (_day > 0 && _day <= 31){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}

					}
					else if (_month == 4){
						//April always 30 days
						if (_day > 0 && _day <= 30){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}
					}
					else if (_month == 5){
						//May always 31 days
						if (_day > 0 && _day <= 31){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}

					}
					else if (_month == 6){
						//June always 30 days
						if (_day > 0 && _day <= 30){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}

					}
					else if (_month == 7){
						//July always 31 days
						if (_day > 0 && _day <= 31){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}

					}
					else if (_month == 8){
						//Auguest always 31 days
						if (_day > 0 && _day <= 31){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}


					}
					else if (_month == 9){
						//September always 30 days

						if (_day > 0 && _day <= 30){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}
					}
					else if (_month == 10){
						//October always 31 days
						if (_day > 0 && _day <= 31){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}


					}
					else if (_month == 11){
						//November always 30 days
						if (_day > 0 && _day <= 30){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}

					}
					else if (_month == 12){
						//December always 31 days
						if (_day > 0 && _day <= 31){
							if (chk){
								return correct;
							}
							else{
								return wrong;
							}
						}
						else{
							return wrong;
						}

					}
					else{
						return wrong;//bcz month not in range of 1 ~12

					}

		}
		else{
			if (_month == 1){
				//january always 31 days
				if (_day > 0 && _day <= 31){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}

			}
			else if (_month == 2){
				//Febuary if leap year : 29
				//if common year : 28 

				if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)){
					//leap year means 366 days which febuary has 29 days
					if (_day > 0 && _day <= 29){
						if (chk){
							return correct;
						}
						else{
							return wrong;
						}
					}
					else{
						return wrong;
					}

				}
				else{//common year 365 days which means february has 28 days
					if (_day > 0 && _day <= 28){
						if (chk){
							return correct;
						}
						else{
							return wrong;
						}
					}
					else{
						return wrong;
					}
				}


			}
			else if (_month == 3){
				//March always 31 days
				if (_day > 0 && _day <= 31){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}

			}
			else if (_month == 4){
				//April always 30 days
				if (_day > 0 && _day <= 30){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}
			}
			else if (_month == 5){
				//May always 31 days
				if (_day > 0 && _day <= 31){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}

			}
			else if (_month == 6){
				//June always 30 days
				if (_day > 0 && _day <= 30){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}

			}
			else if (_month == 7){
				//July always 31 days
				if (_day > 0 && _day <= 31){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}

			}
			else if (_month == 8){
				//Auguest always 31 days
				if (_day > 0 && _day <= 31){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}


			}
			else if (_month == 9){
				//September always 30 days

				if (_day > 0 && _day <= 30){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}
			}
			else if (_month == 10){
				//October always 31 days
				if (_day > 0 && _day <= 31){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}


			}
			else if (_month == 11){
				//November always 30 days
				if (_day > 0 && _day <= 30){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}

			}
			else if (_month == 12){
				//December always 31 days
				if (_day > 0 && _day <= 31){
					if (chk){
						return correct;
					}
					else{
						return wrong;
					}
				}
				else{
					return wrong;
				}

			}
			else{
				return wrong;//bcz month not in range of 1 ~12

			}
		}

	}
	else{
		return wrong;//bcx year is behind current year
	}

	


}


double booking::outPutTotalPay_daily(double dailyPrice,int inDayInt, int inMonthInt,int inYearInt, int outDayInt, int outMonthInt, int outYearInt){
	double total_pay=0;

	if (inYearInt == outYearInt){
		//same year chk-in & chk-out
		if (inMonthInt == outMonthInt){
			if (inDayInt == outDayInt){
				//SAME DAY CHK IN CHK OUT counted as 1-day!! so fee charges from 1day
				total_pay = 1 * (dailyPrice);
				return total_pay;
			}
			else{
				//same year & month but dif day,so that bigger month should always minus smaller day
				int dayDif = outDayInt - inDayInt;
				total_pay = dayDif * (dailyPrice);
				return total_pay;
			}

		}
		else{

			if (inDayInt == outDayInt){
				int monthDif = outMonthInt - inMonthInt;
				//1 month =30 days avg
				total_pay = monthDif * 30 * (dailyPrice);
				return total_pay;
			}
			else{
				//same year & dif month  dif day,
				
				int totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - inMonthInt-1) * 30);
				total_pay = totalDay * dailyPrice;
				return total_pay;
				
				
			}
			//dif month chk-in & chk-out, here is in the same year so, the biggest month should always minus smallest month
		

		}


	}
	else{// eg 30-11-2016   to   22-01-2017
		//dif year chk-in & chk-out
		//yearDif = outYearInt = inYearInt;//
		//HERE IS Day case!!! so year convert to days  , bcz 1 year = 365 days for avg, 1 month = 30 days for avg

		//**************************************************************************************


		if (inMonthInt == 1 || inMonthInt == 3 || inMonthInt == 5 || inMonthInt == 7 || inMonthInt == 8 || inMonthInt == 10 || inMonthInt == 12){

			if (outYearInt - inYearInt == 1){
				int totalDay = (31 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
				total_pay = totalDay * dailyPrice;
				return total_pay;
			}
			else{
				int totalDay = (31 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				total_pay = totalDay * dailyPrice;
				return total_pay;
			}

		}
		else if (inMonthInt == 4 || inMonthInt == 6 || inMonthInt == 9 || inMonthInt == 30){

			if (outYearInt - inYearInt == 1){
				int totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
				total_pay = totalDay * dailyPrice;
				return total_pay;
			}
			else{
				int totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				total_pay = totalDay * dailyPrice;
				return total_pay;
			}
		}
		else{// february

			if (inYearInt % 400 == 0 || (inYearInt % 4 == 0 && inYearInt % 100 != 0)){
				//LEAP YEAR 29
				if (outYearInt - inYearInt == 1){
					int totalDay = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					total_pay = totalDay * dailyPrice;
					return total_pay;
				}
				else{
					int totalDay = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					total_pay = totalDay * dailyPrice;
					return total_pay;
				}
			}
			else{//common year 365 days which means february has 28 days
				if (outYearInt - inYearInt == 1){
					int totalDay = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					total_pay = totalDay * (dailyPrice);
					return total_pay;
				}
				else{
					int totalDay = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					total_pay = totalDay * (dailyPrice);
					return total_pay;
				}
			}

		}

	}





}

double booking::outPutTotalPay_monthly(double monthlyPrice,int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt){

	double total_pay = 0;

	if (inYearInt == outYearInt){
		//same year chk-in & chk-out
		if (inMonthInt == outMonthInt){
			
				double ratio = (outDayInt - inDayInt)/30;
				total_pay = ratio * (monthlyPrice);
				return total_pay;
			

		}
		else{

			if (inDayInt == outDayInt){
				int monthDif = outMonthInt - inMonthInt;
				//1 month =30 days avg
				total_pay = monthDif  * (monthlyPrice);
				return total_pay;
			}
			else{
				//same year & dif month  dif day,

				double ratio = ((30 - inDayInt) + outDayInt) / 30;
				double monthTotal = (outMonthInt - inMonthInt - 1) + ratio;
				total_pay = monthTotal*monthlyPrice;
				return total_pay;


			}
			

		}


	}
	else{// eg 30-11-2016   to   22-01-2017
		//dif year chk-in & chk-out
		//yearDif = outYearInt = inYearInt;//
		//HERE IS Day case!!! so year convert to days  , bcz 1 year = 365 days for avg, 1 month = 30 days for avg

		//**************************************************************************************


		if (inMonthInt == 1 || inMonthInt == 3 || inMonthInt == 5 || inMonthInt == 7 || inMonthInt == 8 || inMonthInt == 10 || inMonthInt == 12){

			if (outYearInt - inYearInt == 1){
				double totalMonth = (((31 - inDayInt) + outDayInt)/30) + (outMonthInt-1)  + (12 - inMonthInt) ;
				total_pay = totalMonth * monthlyPrice;
				return total_pay;
			}
			else{
				double totalMonth = (((31 - inDayInt) + outDayInt)/30) + (outMonthInt -1) + ((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month

				total_pay = totalMonth * monthlyPrice;
				return total_pay;
			}

		}
		else if (inMonthInt == 4 || inMonthInt == 6 || inMonthInt == 9 || inMonthInt == 30){

			if (outYearInt - inYearInt == 1){
				double totalMonth = (((30 - inDayInt) + outDayInt) / 30) + (outMonthInt-1) + (12 - inMonthInt);
				total_pay = totalMonth * monthlyPrice;
				return total_pay;
			}
			else{
				double totalMonth = (((30 - inDayInt) + outDayInt) / 30) + (outMonthInt-1)+((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month

				total_pay = totalMonth * monthlyPrice;
				return total_pay;
			}
		}
		else{// february

			if (inYearInt % 400 == 0 || (inYearInt % 4 == 0 && inYearInt % 100 != 0)){
				//LEAP YEAR 29
				if (outYearInt - inYearInt == 1){
					double totalMonth = (((29 - inDayInt) + outDayInt) / 30) + (outMonthInt-1) + (12 - inMonthInt);
					total_pay = totalMonth * monthlyPrice;
					return total_pay;
				}
				else{
					double totalMonth = (((29 - inDayInt) + outDayInt) / 30) + (outMonthInt-1)+((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month

					total_pay = totalMonth * monthlyPrice;
					return total_pay;
				}
			}
			else{//common year 365 days which means february has 28 days
				if (outYearInt - inYearInt == 1){
					double totalMonth = (((28 - inDayInt) + outDayInt) / 30) + (outMonthInt-1) + (12 - inMonthInt);
					total_pay = totalMonth * monthlyPrice;
					return total_pay;
				}
				else{
					double totalMonth = (((28 - inDayInt) + outDayInt) / 30) + (outMonthInt-1)+((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month

					total_pay = totalMonth * monthlyPrice;
					return total_pay;
				}
			}

		}

	}

}



double booking::outPutTotalPay_weekly(double weeklyPrice, int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt){
	double total_pay = 0;

	if (inYearInt == outYearInt){
		//same year chk-in & chk-out
		if (inMonthInt == outMonthInt){
			if (inDayInt == outDayInt){
				//SAME DAY CHK IN CHK OUT counted as 1-day!! so fee charges from 1day
				total_pay = (1/7 * (weeklyPrice) ); //jst use total day/7  * weeklyprice
				return total_pay;
			}
			else{
				//same year & month but dif day,so that bigger month should always minus smaller day
				int dayDif = outDayInt - inDayInt;
				total_pay = ((dayDif/7) * (weeklyPrice));
				return total_pay;
			}

		}
		else{

			if (inDayInt == outDayInt){
				int monthDif = outMonthInt - inMonthInt;
				//1 month =30 days avg
				total_pay = ((monthDif * 30)/7) * (weeklyPrice);
				return total_pay;
			}
			else{
				//same year & dif month  dif day,

				double totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - inMonthInt - 1) * 30);
				total_pay = (totalDay/7) * weeklyPrice;
				return total_pay;


			}
			//dif month chk-in & chk-out, here is in the same year so, the biggest month should always minus smallest month


		}


	}
	else{// eg 30-11-2016   to   22-01-2017
		//dif year chk-in & chk-out
		//yearDif = outYearInt = inYearInt;//
		//HERE IS Day case!!! so year convert to days  , bcz 1 year = 365 days for avg, 1 month = 30 days for avg

		//**************************************************************************************


		if (inMonthInt == 1 || inMonthInt == 3 || inMonthInt == 5 || inMonthInt == 7 || inMonthInt == 8 || inMonthInt == 10 || inMonthInt == 12){

			if (outYearInt - inYearInt == 1){
				double totalDay = (31 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
				total_pay = (totalDay/7) * weeklyPrice;
				return total_pay;
			}
			else{
				double totalDay = (31 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				total_pay = (totalDay/7) * weeklyPrice;
				return total_pay;
			}

		}
		else if (inMonthInt == 4 || inMonthInt == 6 || inMonthInt == 9 || inMonthInt == 30){

			if (outYearInt - inYearInt == 1){
				double totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
				total_pay = (totalDay/7) * weeklyPrice;
				return total_pay;
			}
			else{
				double totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				total_pay = (totalDay/7) * weeklyPrice;
				return total_pay;
			}
		}
		else{// february

			if (inYearInt % 400 == 0 || (inYearInt % 4 == 0 && inYearInt % 100 != 0)){
				//LEAP YEAR 29
				if (outYearInt - inYearInt == 1){
					double totalDay = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					total_pay = (totalDay/7) * weeklyPrice;
					return total_pay;
				}
				else{
					double totalDay = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					total_pay = (totalDay/7) * weeklyPrice;
					return total_pay;
				}
			}
			else{//common year 365 days which means february has 28 days
				if (outYearInt - inYearInt == 1){
					double totalDay = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					total_pay = (totalDay/7) * (weeklyPrice);
					return total_pay;
				}
				else{
					double totalDay = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					total_pay = (totalDay/7) * (weeklyPrice);
					return total_pay;
				}
			}

		}

	}



}



double booking::getTotalDay(int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt){
	double total_Day;
	if (inYearInt == outYearInt){
		//same year chk-in & chk-out
		if (inMonthInt == outMonthInt){
			if (inDayInt == outDayInt){
				//SAME DAY CHK IN CHK OUT counted as 1-day!! so fee charges from 1day
				total_Day = 1; //jst use total day/7  * weeklyprice
				return total_Day;
			}
			else{
				//same year & month but dif day,so that bigger month should always minus smaller day
				
				total_Day = outDayInt - inDayInt;//we count the night stay, one night counted as one day
				return total_Day;
			}

		}
		else{

			if (inDayInt == outDayInt){
				int monthDif = outMonthInt - inMonthInt;
				//1 month =30 days avg
				total_Day = (monthDif * 30);
				return total_Day;
			}
			else{
				//same year & dif month  dif day,

				total_Day = (30 - inDayInt) + outDayInt + ((outMonthInt - inMonthInt - 1) * 30);
				
				return total_Day;


			}
			//dif month chk-in & chk-out, here is in the same year so, the biggest month should always minus smallest month


		}


	}
	else{// eg 30-11-2016   to   22-01-2017
		//dif year chk-in & chk-out
		//yearDif = outYearInt = inYearInt;//
		//HERE IS Day case!!! so year convert to days  , bcz 1 year = 365 days for avg, 1 month = 30 days for avg

		//**************************************************************************************


		if (inMonthInt == 1 || inMonthInt == 3 || inMonthInt == 5 || inMonthInt == 7 || inMonthInt == 8 || inMonthInt == 10 || inMonthInt == 12){

			if (outYearInt - inYearInt == 1){//eg 11-Nov-2017 & 20-Feb-2016
				total_Day = (31 - inDayInt) + outDayInt + ((outMonthInt-1) * 30) + ((12 - inMonthInt) * 30);
				
				return total_Day;
			}
			else{
				total_Day = (31 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				
				return total_Day;
			}

		}
		else if (inMonthInt == 4 || inMonthInt == 6 || inMonthInt == 9 || inMonthInt == 30){

			if (outYearInt - inYearInt == 1){
				total_Day = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
				
				return total_Day;
			}
			else{
				total_Day = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				return total_Day;
			}
		}
		else{// february

			if (inYearInt % 400 == 0 || (inYearInt % 4 == 0 && inYearInt % 100 != 0)){
				//LEAP YEAR 29
				if (outYearInt - inYearInt == 1){
					total_Day = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					
					return total_Day;
				}
				else{
					total_Day = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					return total_Day;
				}
			}
			else{//common year 365 days which means february has 28 days
				if (outYearInt - inYearInt == 1){
					total_Day = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					
					return total_Day;
				}
				else{
					total_Day = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					
					return total_Day;
				}
			}

		}

	}


}
double booking::getTotalMonth(int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt){
	double total_Month;
	if (inYearInt == outYearInt){
		//same year chk-in & chk-out
		if (inMonthInt == outMonthInt){

			total_Month = (outDayInt - inDayInt) / 30;
			
			return total_Month;


		}
		else{

			if (inDayInt == outDayInt){
				total_Month = outMonthInt - inMonthInt;
				
				return total_Month;
			}
			else{
				//same year & dif month  dif day,

				double ratio = ((30 - inDayInt) + outDayInt) / 30;
				double monthTotal = (outMonthInt - inMonthInt-1) + ratio;
				
				return monthTotal;


			}


		}


	}
	else{// eg 30-11-2016   to   22-01-2017
		//dif year chk-in & chk-out
		//yearDif = outYearInt = inYearInt;//
		//HERE IS Day case!!! so year convert to days  , bcz 1 year = 365 days for avg, 1 month = 30 days for avg

		//**************************************************************************************


		if (inMonthInt == 1 || inMonthInt == 3 || inMonthInt == 5 || inMonthInt == 7 || inMonthInt == 8 || inMonthInt == 10 || inMonthInt == 12){

			if (outYearInt - inYearInt == 1){
				double totalMonth = (((31 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + (12 - inMonthInt);
				
				return totalMonth;
			}
			else{
				double totalMonth = (((31 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + ((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month

				return totalMonth;
			}

		}
		else if (inMonthInt == 4 || inMonthInt == 6 || inMonthInt == 9 || inMonthInt == 30){

			if (outYearInt - inYearInt == 1){
				double totalMonth = (((30 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + (12 - inMonthInt);
				
				return totalMonth;
			}
			else{
				double totalMonth = (((30 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + ((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month

				return totalMonth;
			}
		}
		else{// february

			if (inYearInt % 400 == 0 || (inYearInt % 4 == 0 && inYearInt % 100 != 0)){
				//LEAP YEAR 29
				if (outYearInt - inYearInt == 1){
					double totalMonth = (((29 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + (12 - inMonthInt);
					
					return totalMonth;
				}
				else{
					double totalMonth = (((29 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + ((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month


					return totalMonth;
				}
			}
			else{//common year 365 days which means february has 28 days
				if (outYearInt - inYearInt == 1){
					double totalMonth = (((28 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + (12 - inMonthInt);
					
					return totalMonth;
				}
				else{
					double totalMonth = (((28 - inDayInt) + outDayInt) / 30) + (outMonthInt - 1) + ((12 - inMonthInt)) + ((outYearInt - inYearInt - 1) * 12);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *12 month

					return totalMonth;
				}
			}

		}

	}


}
double booking::getTotalWeek(int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt){


	double total_Week;


	if (inYearInt == outYearInt){
		//same year chk-in & chk-out
		if (inMonthInt == outMonthInt){
			if (inDayInt == outDayInt){
				//SAME DAY CHK IN CHK OUT counted as 1-day!! so fee charges from 1day
				total_Week = (1 / 7 ); //jst use total day/7  * weeklyprice
				return total_Week;
			}
			else{
				//same year & month but dif day,so that bigger month should always minus smaller day
				double dayDif = outDayInt - inDayInt;
				total_Week = ((dayDif / 7) );
				return total_Week;
			}

		}
		else{

			if (inDayInt == outDayInt){
				double monthDif = outMonthInt - inMonthInt;
				//1 month =30 days avg
				total_Week = ((monthDif * 30) / 7);
				return total_Week;
			}
			else{
				//same year & dif month  dif day,

				double totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - inMonthInt - 1) * 30);
				total_Week = (totalDay / 7) ;
				return total_Week;


			}
			//dif month chk-in & chk-out, here is in the same year so, the biggest month should always minus smallest month


		}


	}
	else{// eg 30-11-2016   to   22-01-2017
		//dif year chk-in & chk-out
		//yearDif = outYearInt = inYearInt;//
		//HERE IS Day case!!! so year convert to days  , bcz 1 year = 365 days for avg, 1 month = 30 days for avg

		//**************************************************************************************


		if (inMonthInt == 1 || inMonthInt == 3 || inMonthInt == 5 || inMonthInt == 7 || inMonthInt == 8 || inMonthInt == 10 || inMonthInt == 12){

			if (outYearInt - inYearInt == 1){
				double totalDay = (31 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
				total_Week = (totalDay / 7) ;
				return total_Week;
			}
			else{
				double totalDay = (31 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				total_Week = (totalDay / 7) ;
				return total_Week;
			}

		}
		else if (inMonthInt == 4 || inMonthInt == 6 || inMonthInt == 9 || inMonthInt == 30){

			if (outYearInt - inYearInt == 1){
				double totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
				total_Week = (totalDay / 7);
				return total_Week;
			}
			else{
				double totalDay = (30 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

				total_Week = (totalDay / 7);
				return total_Week;
			}
		}
		else{// february

			if (inYearInt % 400 == 0 || (inYearInt % 4 == 0 && inYearInt % 100 != 0)){
				//LEAP YEAR 29
				if (outYearInt - inYearInt == 1){
					double totalDay = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					total_Week = (totalDay / 7);
					return total_Week;
				}
				else{
					double totalDay = (29 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					total_Week = (totalDay / 7);
					return total_Week;
				}
			}
			else{//common year 365 days which means february has 28 days
				if (outYearInt - inYearInt == 1){
					double totalDay = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30);
					total_Week = (totalDay / 7);
					return total_Week;
				}
				else{
					double totalDay = (28 - inDayInt) + outDayInt + ((outMonthInt - 1) * 30) + ((12 - inMonthInt) * 30) + ((outYearInt - inYearInt - 1) * 365);//if 2017 & 2016  2017-2016=1 which is not the case so we minus one so that 2018-2016-1=2-1=1 -> only 2017 whole year *365, bcz 2018 and 2016 month can be calculate from month

					total_Week = (totalDay / 7);
					return total_Week;
				}
			}

		}

	}




}




