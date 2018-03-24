

#ifndef CLIENT_H
#define CLIENT_H
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


//class client
class client :public user{


private:
	string client_id;
	string client_pwd;
	string client_name;
	string client_passport;
	string client_contact;
	string client_email;
	string client_address;

	string client_bank_account;
	string client_bank;

	double client_credit;

public:
	string sessionID;
	string sessionNAME;


	//get set
	string getClientID();// { return this->client_id; }
	string getClientPWD();//{ return this->client_pwd; }
	string getClientNAME();//{ return this->client_name; }
	string getClientPASSPORT();//{ return this->client_passport; }
	string getClientCONTACT();//{ return this->client_contact; }
	string getClientEMAIL();//{ return this->client_email; }
	string getClientADDRESS();//{ return this->client_address; }
	string getClientBANKACCT();//{ return this->client_bank_account; }

	string getClientBANK();//{ return this->client_bank; }
	double getClientCREDIT();//{ return this->client_credit; }


	void setAttributes(string clientID, string clientPWD);//overload
	void setAttributes(string clientID, string clientNAME, string clientPASSPORT, string clientCONTACT, string clientEMAIL, string clientPWD);
	void setAttributes(string clientID, string clientNAME, string clientPASSPORT, string clientCONTACT, string clientEMAIL, string clientADDRESS, string bankAcct, string bank, double credit, string clientPWD);
	
	void setClientID(string clientID_);//{ this->client_id = clientID_; }

	void setClientPWD(string ClientPWD);//{ this->client_pwd = ClientPWD; }
	void setClientNAME(string ClientNAME);//{ this->client_name = ClientNAME; }
	void setClientPASSPORT(string clientPASSPORT);//{ this->client_passport = clientPASSPORT; }
	void setClientCONTACT(string clientCONTACT);//{ this->client_contact = clientCONTACT; }
	void setClientEMAIL(string clientEMAIL);//{ this->client_email = clientEMAIL; }
	void setClientADDRESS(string clientADDRESS);//{ this->client_address = clientADDRESS; }


	void setClientBANKACCT(string acct);//{ this->client_bank_account = acct; }

	void setClientBANK(string bank);//{ this->client_bank = bank; }
	void setClientCREDIT(double credit);//{ this->client_credit = credit; }

	client();// {}
	client(string clientID, string clientNAME, string clientPASSPORT, string clientCONTACT, string clientEMAIL, string clientADDRESS, string bankAcct, string bank, double credit, string clientPWD);
	~client();//{}

	static string space_underscore(std::string text);
	 virtual void manage_profile(string client_id,string clientName);

	static void register_client();

	static void manage_account(string client_id,string client_name);
	static void manage_client_home();
	static void manage_booked_home();
	static void add_home();
	static void client_main(string client_id, string client_name);

	virtual string client::RandomString(int len);
	




};


#endif