#ifndef BOOKING_H
#define BOOKING_H






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





//class booking
class booking : public home{

private:
	string booking_id;
	string home_id;
	string client_id;//owner id
	string customer_id;// customer who rent the room from owner
	char type;//daily:d   weekly:w    monthly:m
	double duration;//specifies how many days,weeks,months
	string chk_in;
	string chk_out;
	double unit_price; //unit_price * duration = total how much customer need pay
	double total_paid;

public:
	//get 
	string getBookingID();//{ return this->booking_id; }
	string getBookingHomeID();//{ return this->home_id; }
	string getBookingcustomerID();//{ return this->customer_id; }
	string getBookingClientID();//{ return this->client_id; }

	char getBookingType();//{ return this->type; }
	double getBookingDuration();//{ return this->duration; }

	string getBookingChkIn();//{ return this->chk_in; }
	string getBookingChkOut();//{ return this->chk_out; }

	double getUnitPrice();//{ return this->unit_price; }
	double getTotalPaid();// { return this->total_paid; }
	//

	void setBookingID(string bookingID);//{ this->booking_id = bookingID; }
	void setBookingHomeID(string homeID);//{ this->home_id = homeID; }
	void setBookingClientID(string clientID);//{ this->client_id = clientID; }
	void setBookingCustomerID(string customerID);//{ this->customer_id = customerID; }

	void setBookingType(char type);//{ this->type = type; }
	void setStayDuration(double duration);//{ this->duration = duration; }
	void setChkIn(string chkIn);//{ this->chk_in = chkIn; }

	void setChkOut(string chkOut);//{ this->chk_out = chkOut; }
	void setUnitPirce(double unitPrice);//{ this->unit_price = unitPrice; }

	void setTotalPaid(double totalPrice);//{ this->total_paid = totalPrice; }
	string getDateTimeIn(string selected_home_id);
	//string getDateTimeOut();
	bool validateDateTime(string selected_home_id, int _year, int _month, int _day);
	//total 10 parameters

booking();//{}
booking(string bookingID, string homeID, string clientID, string customerID, char type, double duration, string chk_in, string chk_out, double unitPrice, double totalPaid);
~booking();//{}//delete obj automatically , no need call delete this...or else will be recursive

static void chkAvailability();//chk each room/house the period which have booked .

static bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);


static void displaySpecificCustomerID(string customerID);
static void displaySpecificClientID(string clientID);
	static void displayDetail();// {}//override parent method of display room, here display booking info

	double outPutTotalPay_daily(double dailyPrice, int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt);
	double outPutTotalPay_monthly(double monthlyPrice, int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt);
	double outPutTotalPay_weekly(double weeklyPrice, int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt);


	double getTotalDay(int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt);
	double getTotalMonth(int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt);
	double getTotalWeek(int inDayInt, int inMonthInt, int inYearInt, int outDayInt, int outMonthInt, int outYearInt);

};


#endif