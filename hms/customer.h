#ifndef CUSTOMER_H
#define CUSTOMER_H
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



class customer :public user{

private:
	string customer_id;
	string customer_pwd;//default value:password
	string customer_name;
	string customer_passport;
	string customer_contact;
	string customer_email;
	string customer_address;

	string customer_bank_account;
	string customer_bank;

	double customer_credit; //default 0 credits for all user



public:
	 string sessionID;
	 string sessionNAME;
	//get set
	string getCustomerID();// { return this->customer_id; }
	string getCustomerPWD();// { return this->customer_pwd; }
	string getCustomerNAME();// { return this->customer_name; }
	string getCustomerPASSPORT();// { return this->customer_passport; }
	string getCustomerCONTACT();// { return this->customer_contact; }
	string getCustomerEMAIL();// { return this->customer_email; }
	string getCustomerADDRESS();// { return this->customer_address; }
	string getCustomerBANKACCT();// { return this->customer_bank_account; }

	string getCustomerBANK();// { return this->customer_bank; }
	double getCustomerCREDIT();// { return this->customer_credit; }
	static void register_customer();
	static string space_underscore(std::string text);

	void setCustomerID(string customerID_);// { this->customer_id = customerID_; }

	void setCustomerPWD(string customerPWD);// { this->customer_pwd = customerPWD; }
	void setCustomerNAME(string customerNAME);// { this->customer_name = customerNAME; }
	void setCustomerPASSPORT(string customerPASSPORT);// { this->customer_passport = customerPASSPORT; }
	void setCustomerCONTACT(string customerCONTACT);// { this->customer_contact = customerCONTACT; }
	void setCustomerEMAIL(string customerEMAIL);// { this->customer_email = customerEMAIL; }
	void setCustomerADDRESS(string customerADDRESS);// { this->customer_address = customerADDRESS; }


	void setCustomerBANKACCT(string acct);// { this->customer_bank_account = acct; }

	void setCustomerBANK(string bank);// { this->customer_bank = bank; }
	void setCustomerCREDIT(double credit);// { this->customer_credit = credit; }
	
	void setAttributes(string customerID, string customerPWD);
	void setAttributes(string customerID, string customerNAME, string customerPASSPORT, string customerPWD);
	void setAttributes(string customerID, string customerNAME, string customerPASSPORT, string customerCONTACT, string customerEMAIL, string customerADDRESS, string bankAcct, string bank, double credit, string customerPWD);


	customer();// {}
	customer(string customerID, string customerNAME, string customerPASSPORT, string customerCONTACT, string customerEMAIL, string customerADDRESS, string bankAcct, string bank, double credit , string customerPWD );
	~customer();// {//destroy objects of customer to save heap memory in the RAM}
	static void manage_account(string customer_id,string customer_name);// {}
	static void book_stay();//{}
	static void view_booking();//{}
	static void comment_home();//{}

	virtual void manage_profile(string customer_id,string cusName);//inherited method @override  



	static void customer_main(string customer_id, string customer_name);
	virtual string customer::RandomString(int len);
};


#endif