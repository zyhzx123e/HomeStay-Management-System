






#pragma once

#include "targetver.h"

#include "stdafx.h"
#include "client.h"
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


client c;

string client::getClientID(){ return this->client_id; }
string client::getClientPWD(){ return this->client_pwd; }
string client::getClientNAME(){ return this->client_name; }
string client::getClientPASSPORT(){ return this->client_passport; }
string client::getClientCONTACT(){ return this->client_contact; }
string client::getClientEMAIL(){ return this->client_email; }
string client::getClientADDRESS(){ return this->client_address; }
string client::getClientBANKACCT(){ return this->client_bank_account; }

string client::getClientBANK(){ return this->client_bank; }
double client::getClientCREDIT(){ return this->client_credit; }

void client::setClientID(string clientID_){ this->client_id = clientID_; }

void client::setClientPWD(string ClientPWD){ this->client_pwd = ClientPWD; }
void client::setClientNAME(string ClientNAME){ this->client_name = ClientNAME; }
void client::setClientPASSPORT(string clientPASSPORT){ this->client_passport = clientPASSPORT; }
void client::setClientCONTACT(string clientCONTACT){ this->client_contact = clientCONTACT; }
void client::setClientEMAIL(string clientEMAIL){ this->client_email = clientEMAIL; }
void client::setClientADDRESS(string clientADDRESS){ this->client_address = clientADDRESS; }


void client::setClientBANKACCT(string acct){ this->client_bank_account = acct; }

void client::setClientBANK(string bank){ this->client_bank = bank; }
void client::setClientCREDIT(double credit){ this->client_credit = credit; }

void client::setAttributes(string clientID, string clientNAME, string clientPASSPORT, string clientCONTACT, string clientEMAIL, string clientADDRESS, string bankAcct, string bank, double credit = 0, string clientPWD = "password"){
	//initializer of obj customer
	this->client_id = clientID; this->client_name = clientNAME; this->client_passport = clientPASSPORT; this->client_contact = clientCONTACT; this->client_email = clientEMAIL; this->client_address = clientADDRESS;
	this->client_bank_account = bankAcct;
	this->client_bank = bank;

	//default value gorsetting
	this->client_credit = credit;
	this->client_pwd = clientPWD;

}


void client::setAttributes(string clientID, string clientPWD){
	this->client_id = clientID; 
	this->client_pwd = clientPWD;

}
void client::setAttributes(string clientID, string clientNAME, string clientPASSPORT, string clientCONTACT, string clientEMAIL, string clientPWD){
	this->client_id = clientID; this->client_name = clientNAME; this->client_passport = clientPASSPORT;
	this->client_contact = clientCONTACT; this->client_email = clientEMAIL;
	this->client_pwd = clientPWD;
}


void client::register_client(){

	system("cls");
	cout << "-----------Felice Client Register Panel-----------" << endl;
	cout << "==================================================" << endl;
	system("color 0f");
	
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





	bool chkIDexist = false;

	string chkId;
	string randID;
	ifstream chkID("dbclient/db_client.txt");
	string line;
	while (std::getline(chkID, line) || chkIDexist)//getline and cin are read from files
	{
		randID = c->RandomString(6);

		int strpos = line.find(" ");
		chkId = line.substr(0, strpos);
		cout << chkId << endl;
		if (chkId == randID){
			chkIDexist = true;
		}
	}
	chkID.close();

	cout << "For security Reson Your Client ID will be auto generated! and this ID Can no longer be chaged furthur more!" << endl;
	cout << "******************************************************" << endl;
	cout << "Your Client ID:" + randID + ", Please Remember it!" << endl;
	cout << "******************************************************" << endl;

	cin.ignore(1, '\n');
	client_id = randID;


	cout << "Enter Your Client Name:";

	getline(cin, client_name);
	// cin >> client_name;
	cout << "Enter Your IC/Passport Number:";
	
	getline(cin, client_ic);
	//  cin >> client_ic;
	cout << "Enter Your Client Contact Number(Prefer Malaysia Number):";
	
	getline(cin, client_contact);
	// cin >> client_contact;
	cout << "Enter Your Client Email:";
	//cin.get();
	getline(cin, client_email);
	// cin >> client_email;
	cout << "Enter Your Client Address:";
	//cin.get();
	getline(cin, client_address);

	cout << "Enter Your Client Bank:";
	//cin.get();
	getline(cin, client_bank);
	cout << "Input Your " + client_bank + "-Bank Account Number:";
	//cin.get();
	getline(cin, client_bank_account);
	//cin >> client_bank_account;
	cout << endl;
	
	string pwdConfirm;
	
	cout << "Now set your password!"; cout << endl;
	cin >> client_pwd;
	cout << "To confirm your password, please type again the password you have entered!"; cout << endl;
	cin >> pwdConfirm;
	cin.ignore(1, '\n');
	client_credit = 0;
	if (pwdConfirm==client_pwd){
	c->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_account, client_bank, client_credit, client_pwd);

	}
		
	



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
	cout << "Welcome Dear Client'" + c->getClientNAME() + "' , Remember Your ID: '" + c->getClientID() + "', (ID Can no longer change once it is set!)" << endl;
	cout << " Dear '" + c->getClientNAME() + "' , You can now start to earn money from posting your idle rooms or houses into Our Felice Home Stay System" << endl;

	cout << " Dear '" + c->getClientNAME() + "' Please Note that, by default, your credit is 0 amount, you can top up by using the bank account and can also withdraw money from this system to your bank" << endl;
	cout << "**********************************************************************************************************" << endl;
	cout << endl;
	cout << "Now Start Your Journey! Enjoy!" << endl;

	dir.close();
	system("pause");
	client_main(c->getClientID(), c->getClientNAME());
	cout << "Welcome " + c->getClientNAME() + "! This is your First Time login! Any doubt, Please contact Staff or Programmer at 0166028563" << endl;


}

client::client(){}
client::client(string clientID, string clientNAME, string clientPASSPORT, string clientCONTACT, string clientEMAIL, string clientADDRESS, string bankAcct, string bank, double credit = 0, string clientPWD = "password"){
	//initializer of obj customer
	this->client_id = clientID; this->client_name = clientNAME; this->client_passport = clientPASSPORT; this->client_contact = clientCONTACT; this->client_email = clientEMAIL; this->client_address = clientADDRESS;
	this->client_bank_account = bankAcct;
	this->client_bank = bank;

	//default value gorsetting
	this->client_credit = credit;
	this->client_pwd = clientPWD;

}
client::~client(){

}


void client::manage_profile(string client_id, string clientName){

	time_t now;
	time(&now);

	// 2 variable , store exchange result
	struct tm tmTmp;


	bool wrong = false;
	bool correct = true;

	time_t theTime;
	time(&theTime);
	struct tm aTime;
	localtime_s(&aTime, &theTime);

	int currentHourInt = aTime.tm_hour;//0~23
	

	string client_ID;string client_pwd;string client_name;
	string client_passport;string client_contact;string client_email;
	string client_address;string client_bank_account;
	string client_bank;double client_credit;

	string new_client_pwd; string new_client_name;
	string new_client_passport; string new_client_contact; string new_client_email;
	string new_client_address; string new_client_bank_account;
	string new_client_bank; double new_client_credit;
	
restart:
	system("cls");
	ifstream readClientProfile("dbclient/"+client_id+".txt");
	while (readClientProfile >> client_ID >> client_name >> client_passport >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd  ){
		
		if (currentHourInt >= 12 && currentHourInt<18){
			cout << "Good Afternoon " + client_name + "! Welcome to the Felice HomeStay Management System" << endl;
		}
		else if (currentHourInt >= 18 && currentHourInt <= 23){
			cout << "Good Evening " + client_name + "! Welcome to the Felice HomeStay Management System" << endl;

		}
		else{
			cout << "Good Morning " + client_name + "! Welcome to the Felice HomeStay Management System" << endl;

		}
		cout << "======================================================================================" << endl;

		cout << "Your ID: " << client_ID << endl;
		cout << "Your Name: " << client_name << endl;
		cout << "Your Passport: " << client_passport << endl;
		cout << "Your Contact: " << client_contact << endl;
		cout << "Your Email: " << client_email << endl;
		cout << "Your Address: " << client_address << endl;
		cout << "Your Bank Account: " << client_bank_account << endl;
		cout << "Your Bank is under : " << client_bank << endl;
		cout << "*************************************************************************************" << endl;

		cout << "Your Account Remaining Credit: " << client_credit << endl;
	
	}

	readClientProfile.close();
client c;
	char choice;
	cout << "Want to edit Your personal information?[Y/N]" << endl;

		cin >> choice;

		if (choice=='y' || choice=='Y'){
			cout << "Enter your New Name";
			cin >> new_client_name;
			cout << endl;

			cout << "Enter your New IC/Passport number";
			cin >> new_client_passport;
			cout << endl;

			cout << "Enter your New Contact number";
			cin >> new_client_contact;
			cout << endl;

			cout << "Enter your New Email";
			cin >> new_client_email;
			cout << endl;

			cout << "Enter your New Address";
			cin >> new_client_address;
			cout << endl;

			cout << "Enter your New Bank Name";
			cin >> new_client_bank;
			cout << endl;

			cout << "Enter your New Bank Account Number";
			cin >> new_client_bank_account;
			cout << endl;

			c.setAttributes(client_ID, new_client_name, new_client_passport, new_client_contact, new_client_email, new_client_address, new_client_bank_account, new_client_bank, client_credit, client_pwd);




			ofstream tempPofolio("dbclient/tempPofolio.txt");

			ofstream temp("dbclient/temp.txt");
			ifstream clientD("dbclient/db_client.txt");
			if (tempPofolio.is_open() && clientD.is_open() && temp.is_open()){

				string line;
				while (getline(clientD, line))
				{
					if (line.find(client_id) == string::npos) { //str.find(str2) != string::npos
						temp << line << endl;

					}
					else
					{
					/*	tempPofolio << (c.getClientID()) << ' ' << (c.getClientNAME()) << ' ' << (c.getClientPASSPORT()) << ' ' << (c.getClientCONTACT()) << ' ' << (c.getClientEMAIL()) << ' ' << (c.getClientADDRESS()) << ' ' << (c.getClientBANKACCT()) << ' ' << (c.getClientBANK()) << ' ' << (toString(c.getClientCREDIT())) << ' ' << (c.getClientPWD()) << endl;
						temp << (c.getClientID()) << ' ' << (c.getClientNAME()) << ' ' << (c.getClientPASSPORT()) << ' ' << (c.getClientCONTACT()) << ' ' << (c.getClientEMAIL()) << ' ' << (c.getClientADDRESS()) << ' ' << (c.getClientBANKACCT()) << ' ' << (c.getClientBANK()) << ' ' << (toString(c.getClientCREDIT())) << ' ' << (c.getClientPWD()) << endl;
*/
						
						tempPofolio << space_underscore(c.getClientID()) << ' ' << space_underscore(c.getClientNAME()) << ' ' << space_underscore(c.getClientPASSPORT()) << ' ' << space_underscore(c.getClientCONTACT()) << ' ' << space_underscore(c.getClientEMAIL()) << ' ' << space_underscore(c.getClientADDRESS()) << ' ' << space_underscore(c.getClientBANKACCT()) << ' ' << space_underscore(c.getClientBANK()) << ' ' << space_underscore(toString(c.getClientCREDIT())) << ' ' << space_underscore(c.getClientPWD()) << endl;
						temp << space_underscore(c.getClientID()) << ' ' << space_underscore(c.getClientNAME()) << ' ' << space_underscore(c.getClientPASSPORT()) << ' ' << space_underscore(c.getClientCONTACT()) << ' ' << space_underscore(c.getClientEMAIL()) << ' ' << space_underscore(c.getClientADDRESS()) << ' ' << space_underscore(c.getClientBANKACCT()) << ' ' << space_underscore(c.getClientBANK()) << ' ' << space_underscore(toString(c.getClientCREDIT())) << ' ' << space_underscore(c.getClientPWD()) << endl;
				
					
					}
				}

			}
			tempPofolio.close();
			//clientPort.close();
			clientD.close();

			temp.close();

			string filePortfolio = "dbclient/"+client_ID+"";
			filePortfolio.append(".txt");
			string db_old_file = "dbclient/db_client.txt";
			//system("del dbclient/db_client.txt");
			const char *data = "dbclient/db_client.txt";
			remove(db_old_file.c_str());//delete the old db file first


			//system("del dbclient/db_client.txt");
			remove(filePortfolio.c_str());

			rename("dbclient/tempPofolio.txt", filePortfolio.c_str());
			rename("dbclient/temp.txt", "dbclient/db_client.txt");
			//******
			cout << "You have successfully updated your profile" << endl;
		}
		else{
			client_main(c.sessionID, c.sessionNAME);

		}


	system("pause");
	
	client_main(c.sessionID,c.sessionNAME);

}//inherited method override


 string client::RandomString(int len)
{
	srand(time(0));
	string str_client = "client";
	string str = "0123456789abcdefghijklmnopqrstuvwxyz";
	int pos;
	while (str.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		str.erase(pos, 1);
	}
	return str_client+str;
}



string client::space_underscore(std::string text) {
	for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
		if (*it == ' ') {
			*it = '_';
		}
	}
	return text;
}

void client::manage_account(string client_id,string client_name){
	cout << "Welcome Dear valued Client " + client_name + " to Our Felice Home-Stay  ";
	cout << "Select following account services -> " << endl;
	int choice;
	string filePortfolio = "dbclient/" + client_id + "";
	filePortfolio.append(".txt");


		string new_client_ID;
		string new_client_pwd; string new_client_name;
		string new_client_passport; string new_client_contact; string new_client_email;
		string new_client_address; string new_client_bank_account;
		string new_client_bank; double new_client_credit;
	cout << "1.Change Account[" + c.sessionID + "] Password->" << endl;
	cout << "2.Top up my Felice Home Stay Credits->" << endl;
	cout << "3.Bind to another bank account and bank->" << endl;
	cin >> choice;
	if (choice==1){
		string oldPwd;
		string newPwd;
		string newPwd_confirm;


	restart:
		system("cls");
		client &cPoi = *new client();
		//cout << client_id;
		ifstream readClientProfile("dbclient/" + c.sessionID + ".txt");
		while (readClientProfile >> new_client_ID >> new_client_name >> new_client_passport >> new_client_contact >> new_client_email >> new_client_address >> new_client_bank_account >> new_client_bank >> new_client_credit >> new_client_pwd){
			cPoi.setAttributes(new_client_ID, new_client_name, new_client_passport, new_client_contact, new_client_email, new_client_address, new_client_bank_account, new_client_bank, new_client_credit, new_client_pwd);
			
		}readClientProfile.close();

		cout << "Please Enter your original password...->";
		cin >> oldPwd;
		if (oldPwd==cPoi.getClientPWD()){
		startPwdSet:
			cout << " Enter the new password you want to set...->";
			cin >> newPwd;
			cout << endl;
			cout << " Enter again the new password you want to set...->";
			cin >> newPwd_confirm;

			if (newPwd==newPwd_confirm){
				cPoi.setClientPWD(newPwd);
			



				ofstream tempPofolio("dbclient/tempPofolio.txt");

				ofstream temp("dbclient/temp.txt");
				ifstream clientD("dbclient/db_client.txt");
				if (tempPofolio.is_open() && clientD.is_open() && temp.is_open()){

					string line;
					while (getline(clientD, line))
					{
						if (line.find(client_id) == string::npos) { //str.find(str2) != string::npos
							temp << line << endl;

						}
						else
						{
					/*			tempPofolio <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  cPoi.getClientPASSPORT() << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' << (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;
						temp <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  (cPoi.getClientPASSPORT()) << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' <<  (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;
						
						*/
							tempPofolio << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
							temp << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
						
							
						}
					}

				}
				tempPofolio.close();
				//clientPort.close();
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
				//change in db
				cout <<"Congrats! You have updated your password!" << endl;
			}
			else{
				cout << "Sorry! both password must be matched!";
				goto startPwdSet;
			}

		}
		else{
			cout << "Sorry! Your original password is not correct!";

		
		}



	
	}
	else if (choice==2){

		client &cPoi = *new client();
		ifstream readClientProfile("dbclient/" + client_id + ".txt");
		while (readClientProfile >> new_client_ID >> new_client_name >> new_client_passport >> new_client_contact >> new_client_email >> new_client_address >> new_client_bank_account >> new_client_bank >> new_client_credit >> new_client_pwd){
			cPoi.setAttributes(new_client_ID, new_client_name, new_client_passport, new_client_contact, new_client_email, new_client_address, new_client_bank_account, new_client_bank, new_client_credit, new_client_pwd);
		}readClientProfile.close();

		cout << "You are directing to a payment console";
		cout << "Following is your Bank Info:";
		cout << "Bank Branch Name:" << cPoi.getClientBANK() << endl;
		cout << "Your " + cPoi.getClientBANK() + "-Bank Account Number:" << cPoi.getClientBANKACCT() << endl;
		cout << "Use " + cPoi.getClientBANK() + "- " + cPoi.getClientBANKACCT() + " this bank account to top up?[Y/N]" << endl;
		double top_up_amt;
		double balance;
		char select;
		cin >> select;
		if (select=='y' || select =='Y'){
			reTypeCredit:
			cout << "How much you want to top-up to your credit?" << endl;
			cin >> top_up_amt;
			if (cin.fail()){
				cin.ignore();
				cin.clear();
				cout << "Invalid top-up amount" << endl;
				goto reTypeCredit;
			}
			cout << "Enter "+cPoi.getClientBANKACCT()+" account PIN:" << endl;
			Sleep(2000);//2seconds
			cout << "Authenticating " + cPoi.getClientBANKACCT() + " with Bank "+cPoi.getClientBANK()+"" << endl;
		Sleep(1000);//2seconds
			cout << "Validating......" << endl;

			balance = cPoi.getClientCREDIT() + top_up_amt;
			cPoi.setClientCREDIT(balance);




			ofstream tempPofolio("dbclient/tempPofolio.txt");

			ofstream temp("dbclient/temp.txt");
			ifstream clientD("dbclient/db_client.txt");
			if (tempPofolio.is_open() && clientD.is_open() && temp.is_open()){

				string line;
				while (getline(clientD, line))
				{
					if (line.find(client_id) == string::npos) { //str.find(str2) != string::npos
						temp << line << endl;

					}
					else
					{

					/*	tempPofolio <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  (cPoi.getClientPASSPORT()) << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' <<  (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;
						temp <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  (cPoi.getClientPASSPORT()) << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' <<  (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;

*/	
						
						tempPofolio << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
						temp << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
						
										
					}
				}

			}
			tempPofolio.close();
			//clientPort.close();
			clientD.close();

			temp.close();

			string filePortfolio = "dbclient/" + client_id + "";
			filePortfolio.append(".txt");
			string db_old_file = "dbclient/db_client.txt";
			//system("del dbclient/db_client.txt");
			const char *data = "dbclient/db_client.txt";
			remove(db_old_file.c_str());//delete the old db file first


			//system("del dbclient/db_client.txt");
			remove(filePortfolio.c_str());

			rename("dbclient/tempPofolio.txt", filePortfolio.c_str());
			rename("dbclient/temp.txt", "dbclient/db_client.txt");
			//change in db
			cout << "Congrats! You have toppped up " + toString(top_up_amt) + " with bank account " + cPoi.getClientBANKACCT() + "!" << endl;








		}
		else{string tempBank;
			string tempBankAcct;//bank info not in db
			cout << "You may Enter Another Bank and account to top up" << endl;
			cout << "Enter your bank name:" << endl;
			cin >> tempBank;
			cout << "Enter your " + tempBank + "-bank Account number:" << endl;
			cin >> tempBankAcct;
			cPoi.setClientBANK(tempBank);
			cPoi.setClientBANKACCT(tempBankAcct);

			cout << "How much you want to top-up to your credit?" << endl;
			cin >> top_up_amt;
			if (cin.fail()){
				cin.ignore();
				cin.clear();
				cout << "Invalid top-up amount" << endl;
				goto reTypeCredit;
			}
			cout << "Enter " + tempBankAcct + " account PIN:" << endl;
Sleep(2000);//2seconds
			cout << "Authenticating " + tempBankAcct + " with Bank " + tempBank + "" << endl;
	Sleep(1000);//2seconds
			cout << "Validating......" << endl;

			balance = cPoi.getClientCREDIT() + top_up_amt;
			cPoi.setClientCREDIT(balance);
		




			ofstream tempPofolio("dbclient/tempPofolio.txt");

			ofstream temp("dbclient/temp.txt");
			ifstream clientD("dbclient/db_client.txt");
			if (tempPofolio.is_open() && clientD.is_open() && temp.is_open()){

				string line;
				while (getline(clientD, line))
				{
					if (line.find(client_id) == string::npos) { //str.find(str2) != string::npos
						temp << line << endl;

					}
					else
					{

					/*	tempPofolio <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  (cPoi.getClientPASSPORT()) << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' <<  (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;
						temp <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  (cPoi.getClientPASSPORT()) << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' <<  (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;
*/
						
						tempPofolio << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
						temp << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
				

				
					}
				}

			}
			tempPofolio.close();
			//clientPort.close();
			clientD.close();

			temp.close();

			string filePortfolio = "dbclient/" + client_id + "";
			filePortfolio.append(".txt");
			string db_old_file = "dbclient/db_client.txt";
			//system("del dbclient/db_client.txt");
			const char *data = "dbclient/db_client.txt";
			remove(db_old_file.c_str());//delete the old db file first


			//system("del dbclient/db_client.txt");
			remove(filePortfolio.c_str());

			rename("dbclient/tempPofolio.txt", filePortfolio.c_str());
			rename("dbclient/temp.txt", "dbclient/db_client.txt");
			//change in db
			cout << "Congrats! You have toppped up " + toString(top_up_amt) + " with bank account " + tempBankAcct + "!" << endl;



		}



	}
	else if (choice==3){
	
		client &cPoi = *new client();
		ifstream readClientProfile("dbclient/" + client_id + ".txt");
		while (readClientProfile >> new_client_ID >> new_client_name >> new_client_passport >> new_client_contact >> new_client_email >> new_client_address >> new_client_bank_account >> new_client_bank >> new_client_credit >> new_client_pwd){
			cPoi.setAttributes(new_client_ID, new_client_name, new_client_passport, new_client_contact, new_client_email, new_client_address, new_client_bank_account, new_client_bank, new_client_credit, new_client_pwd);
		}readClientProfile.close();
		string tempBank;
		string tempBankAcct;//bank info not in db
		cout << "You may Enter Another Bank and account to top up" << endl;
		cout << "Enter your bank name:" << endl;
		cin >> tempBank;
		cout << "Enter your " + tempBank + "-bank Account number:" << endl;
		cin >> tempBankAcct;
		cPoi.setClientBANK(tempBank);
		cPoi.setClientBANKACCT(tempBankAcct);

	
		cout << "Enter " + tempBankAcct + " account PIN:" << endl;
Sleep(2000);//2seconds
		cout << "Authenticating " + tempBankAcct + " with Bank " + tempBank + "" << endl;
	Sleep(1000);//2seconds
		cout << "Validating......" << endl;


		ofstream tempPofolio("dbclient/tempPofolio.txt");

		ofstream temp("dbclient/temp.txt");
		ifstream clientD("dbclient/db_client.txt");
		if (tempPofolio.is_open() && clientD.is_open() && temp.is_open()){

			string line;
			while (getline(clientD, line))
			{
				if (line.find(client_id) == string::npos) { //str.find(str2) != string::npos
					temp << line << endl;

				}
				else
				{
					
					tempPofolio << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
					temp << space_underscore(cPoi.getClientID()) << ' ' << space_underscore(cPoi.getClientNAME()) << ' ' << space_underscore(cPoi.getClientPASSPORT()) << ' ' << space_underscore(cPoi.getClientCONTACT()) << ' ' << space_underscore(cPoi.getClientEMAIL()) << ' ' << space_underscore(cPoi.getClientADDRESS()) << ' ' << space_underscore(cPoi.getClientBANKACCT()) << ' ' << space_underscore(cPoi.getClientBANK()) << ' ' << space_underscore(toString(cPoi.getClientCREDIT())) << ' ' << space_underscore(cPoi.getClientPWD()) << endl;
			/*
					tempPofolio <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  (cPoi.getClientPASSPORT()) << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' << (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;
					temp <<  (cPoi.getClientID()) << ' ' <<  (cPoi.getClientNAME()) << ' ' <<  (cPoi.getClientPASSPORT()) << ' ' <<  (cPoi.getClientCONTACT()) << ' ' <<  (cPoi.getClientEMAIL()) << ' ' << (cPoi.getClientADDRESS()) << ' ' <<  (cPoi.getClientBANKACCT()) << ' ' <<  (cPoi.getClientBANK()) << ' ' <<  (toString(cPoi.getClientCREDIT())) << ' ' <<  (cPoi.getClientPWD()) << endl;
*/
				}
			}

		}
		tempPofolio.close();
		//clientPort.close();
		clientD.close();

		temp.close();

		string filePortfolio = "dbclient/" + client_id + "";
		filePortfolio.append(".txt");
		string db_old_file = "dbclient/db_client.txt";
		//system("del dbclient/db_client.txt");
		const char *data = "dbclient/db_client.txt";
		remove(db_old_file.c_str());//delete the old db file first


		//system("del dbclient/db_client.txt");
		remove(filePortfolio.c_str());

		rename("dbclient/tempPofolio.txt", filePortfolio.c_str());
		rename("dbclient/temp.txt", "dbclient/db_client.txt");
		//change in db
		cout << "Congrats! You have added bank account " + tempBankAcct + " to your account!" << endl;





	}

	system("pause");
	client_main(client_id,client_name);
}

void client::manage_client_home(){
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




	}

	dir.close();



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
	cout << "*************************************************"<< endl;

	cout << "***Below are the list of Home that are posted by you, if you did not see any content, means you havent post any home-stay, try post one and view this panel****" << endl;



	ifstream ifRead("dbhome/db_home.txt");
	while (ifRead>>home_id>>home_address>>no_room>>no_bath_room>>max_capacity>>sq_ft>>facility>>description>>owner_id>>day_price>>week_price>>month_price){
	
		if (c.sessionID == owner_id){
		
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
	}


	ifRead.close();

	

	cout << "Select a home-id to edit with the home-stay info!(You cannot delete the home-stay once have posted, if want delete function, approach to staff...)" << endl;
	string selectedHomeId;
	cout << "Please enter the Home with Home-ID You wanted to edit with" << endl;
	cin >> selectedHomeId; cin.ignore(1, '\n');

	stringstream ss;//stringstream ss;
	ss << selectedHomeId;
	string home_idS = ss.str();
	string home_id2 = ss.str();

	home_id2.append(".txt");
	string filePortfolio = "dbhome/" + home_id2;
	std::ifstream homePort(filePortfolio.c_str());


	ifstream facility_reader("dbhome/facility.txt");
	string facility_item;
	string facilityArray[10];
	int i = 0;
	while (facility_reader >> facility_item){
		facilityArray[i] = facility_item;
		i++;
	}
	facility_reader.close();


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

	home *homePtr = new home();


	string new_home_id = home_id;
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
		//new_home_id = "home" + toString(home_number_of_lines);

		cout << "Enter the new location of the House for rent:" << endl;
		
		getline(cin, new_home_address);

		//new_home_address = space_underscore( new_home_address);







		//******************************************

		bool loop_ = true;
		while (loop_){
			std::cout << "Enter the number of bedRoom  that are available (only integers are allowed!)." << endl;
			//std::int sgetNum;
			cin >> new_no_room; cin.ignore(1, '\n');

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  number." << endl;

				std::cout << "Enter the number of bedRoom  again--(Last chance to enter)" << endl;

				cin >> new_no_room;
				cin.ignore(1, '\n');

				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "\nINVALID  number." << endl;
				}

			}

			std::stringstream getNumStream;
			getNumStream << new_no_room;


			if (getNumStream >> new_no_room){
				loop_ = false;
				break;

			}

			loop_ = false;
		}


		//get_Num_Rooms(&new_no_room, "bedroom");


		bool loop1 = true;
		while (loop1){
			std::cout << "Enter the number of bathRoom  that are available (only integers are allowed!)." << endl;
			//std::int sgetNum;
			cin >> new_no_bath_room; cin.ignore(1, '\n');

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  number." << endl;

				std::cout << "Enter the number of bathRoom  again--(Last chance to enter)" << endl;

				cin >> new_no_bath_room;
				cin.ignore(1, '\n');

				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "\nINVALID  number." << endl;
				}

			}

			std::stringstream getNumStream1;
			getNumStream1 << new_no_bath_room;


			if (getNumStream1 >> new_no_bath_room){
				loop1 = false;
				break;

			}

			loop1 = false;
		}



		//get_Num_Rooms(&new_no_bath_room, "bathroom");



		bool loop2 = true;
		while (loop2){
			std::cout << "Enter the number of maximum capacity the house can accomodate (only integers are allowed!)." << endl;
			//std::int sgetNum;
			cin >> new_max_capacity; cin.ignore(1, '\n');

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  number." << endl;

				std::cout << "Enter the number of max capacity  again--(Last chance to enter)" << endl;

				cin >> new_max_capacity;
				cin.ignore(1, '\n');

				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "\nINVALID  number." << endl;
				}

			}

			std::stringstream getNumStream2;
			getNumStream2 << new_max_capacity;


			if (getNumStream2 >> new_max_capacity){
				loop2 = false;
				break;

			}

			loop2 = false;
		}

		//get_Num_Rooms(&new_max_capacity, "max capacity of the room");


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
		while (loop && z < 5){

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
		//cin.get();
		getline(cin, new_description);
		char Fchars[50]; for (int a = 0; a <= new_description.size(); a++){ Fchars[a] = new_description[a]; }

		int size = strlen(Fchars);
		if (size >= 50)
		{
			cout << "max allowed size is 50 char" << endl;
			goto StartAgain;
		}

		//new_description =space_underscore( new_description);
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

		new_owner_id = c.sessionID;

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

			cin >> new_week_price; cin.ignore(1, '\n');


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


		homePtr->setHome(home_id, new_home_address, new_no_room, new_no_bath_room, new_max_capacity, new_sq_ft, new_facility, new_description, new_owner_id, new_day_price, new_week_price, new_month_price);
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
			/*		tempPofolio <<  (homePtr->getHomeID()) << ' ' <<  (homePtr->getHomeAddress()) << ' ' <<  (toString(homePtr->getNoRoom())) << ' ' <<  (toString(homePtr->getNoBathRoom())) << ' ' <<  (toString(homePtr->getMaxCapacity())) << ' ' <<  (toString(homePtr->getSizeSqFt())) << ' ' <<  (homePtr->facility) << ' ' <<  (homePtr->description) << ' ' <<  (toString(homePtr->owner_id)) << ' ' <<  (toString(homePtr->day_price)) << ' ' <<  (toString(homePtr->week_price)) << ' ' <<  (toString(homePtr->month_price)) << endl;
					temp <<  (homePtr->getHomeID()) << ' ' <<  (homePtr->getHomeAddress()) << ' ' <<  (toString(homePtr->getNoRoom())) << ' ' <<  (toString(homePtr->getNoBathRoom())) << ' ' <<  (toString(homePtr->getMaxCapacity())) << ' ' <<  (toString(homePtr->getSizeSqFt())) << ' ' <<  (homePtr->facility) << ' ' <<  (homePtr->description) << ' ' <<  (toString(homePtr->owner_id)) << ' ' <<  (toString(homePtr->day_price)) << ' ' <<  (toString(homePtr->week_price)) << ' ' <<  (toString(homePtr->month_price)) << endl;
*/
					
					tempPofolio << space_underscore(homePtr->getHomeID()) << ' ' << space_underscore(homePtr->getHomeAddress()) << ' ' << space_underscore(toString(homePtr->getNoRoom())) << ' ' << space_underscore(toString(homePtr->getNoBathRoom())) << ' ' << space_underscore(toString(homePtr->getMaxCapacity())) << ' ' << space_underscore(toString(homePtr->getSizeSqFt())) << ' ' << space_underscore(homePtr->facility) << ' ' << space_underscore(homePtr->description) << ' ' << space_underscore(toString(homePtr->owner_id)) << ' ' << space_underscore(toString(homePtr->day_price)) << ' ' << space_underscore(toString(homePtr->week_price)) << ' ' << space_underscore(toString(homePtr->month_price)) << endl;
					temp << space_underscore(homePtr->getHomeID()) << ' ' << space_underscore(homePtr->getHomeAddress()) << ' ' << space_underscore(toString(homePtr->getNoRoom())) << ' ' << space_underscore(toString(homePtr->getNoBathRoom())) << ' ' << space_underscore(toString(homePtr->getMaxCapacity())) << ' ' << space_underscore(toString(homePtr->getSizeSqFt())) << ' ' << space_underscore(homePtr->facility) << ' ' << space_underscore(homePtr->description) << ' ' << space_underscore(toString(homePtr->owner_id)) << ' ' << space_underscore(toString(homePtr->day_price)) << ' ' << space_underscore(toString(homePtr->week_price)) << ' ' << space_underscore(toString(homePtr->month_price)) << endl;
			
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

		cout << "You have updated the " + home_id + " ";

	}


}



void client::manage_booked_home(){

	string booking_id;
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


	booking bookingP[100];
	ifstream readBooking("dbbooking/db_booking.txt");
	int counter = 0;
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


		bookingP[counter].setBookingID(booking_id);
		bookingP[counter].setHomeID(home_id);
		bookingP[counter].setBookingClientID(client_id) ;
		bookingP[counter].setBookingCustomerID(customer_id)  ;


		bookingP[counter].setBookingType(type);
		bookingP[counter].setStayDuration(duration) ;
		bookingP[counter].setChkIn(chk_in);
		bookingP[counter].setChkOut(chk_out) ;
		bookingP[counter].setUnitPirce(unit_price);
		bookingP[counter].setTotalPaid(total_paid) ;
		++counter;
	}readBooking.close();

	cout << "Below are the room that you have posted and customer have booked "<<endl;
	cout << "=========================================================================================================================================================================" << endl;
	cout << "If did not see any content below, means you havent post any room/house, or your rooms/houses are pending for people to book, be patient, you will start earn money soon!" << endl;
	cout << "=========================================================================================================================================================================" << endl;
	booking::displaySpecificClientID(c.sessionID);


}

void client::add_home(){
	cout << "Welcome "+c.sessionNAME+"! You can post a new house/home/room now..."<< endl;
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
	}facility_reader.ignore(1,'\n');
	facility_reader.close();
	cin.ignore(1, '\n');
	for (int q = 0; q < 10; ++q){
		cout << facility[q] << endl;
	}



	string facility_need_store;
	string description;
	string owner_id;

	double day_price; double week_price; double month_price;


	system("cls");
	cout << "-----------Welcome Dear Valued Clinet: " + c.sessionNAME + "-----------" << endl;
	cout << "-------------------Felice Home Stay Posting Platform-------------------" << endl;
	system("color 0f");

	cout << "Where is the location of the House for rent?" << endl;
	
	getline(cin, home_address);



	bool loop_ = true;
	while (loop_){
		std::cout << "Enter the number of bedRoom  that are available (only integers are allowed!)." << endl;
		//std::int sgetNum;
		cin >> no_room;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  number." << endl;

			std::cout << "Enter the number of bedRoom  again--(Last chance to enter)" << endl;

			cin >> no_room;

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  number." << endl;
			}

		}

		std::stringstream getNumStream;
		getNumStream << no_room;


		if (getNumStream >> no_room){
			loop_ = false;
			break;

		}

		loop_ = false;
	}


	//get_Num_Rooms(&new_no_room, "bedroom");


	bool loop1 = true;
	while (loop1){
		std::cout << "Enter the number of bathRoom  that are available (only integers are allowed!)." << endl;
		//std::int sgetNum;
		cin >> no_bath_room;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  number." << endl;

			std::cout << "Enter the number of bathRoom  again--(Last chance to enter)" << endl;

			cin >> no_bath_room;
			cin.ignore(1,'\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  number." << endl;
			}

		}

		std::stringstream getNumStream1;
		getNumStream1 << no_bath_room;


		if (getNumStream1 >> no_bath_room){
			loop1 = false;
			break;

		}

		loop1 = false;
	}



	//get_Num_Rooms(&new_no_bath_room, "bathroom");



	bool loop2 = true;
	while (loop2){
		std::cout << "Enter the max number of people the house can accomodate(only integers are allowed!)." << endl;
		//std::int sgetNum;
		cin >> max_capacity; cin.ignore(1, '\n');

		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nINVALID  number." << endl;

			std::cout << "Enter the number of max capacity  again--(Last chance to enter)" << endl;

			cin >> max_capacity;
			cin.ignore(1, '\n');

			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "\nINVALID  number." << endl;
			}

		}

		std::stringstream getNumStream2;
		getNumStream2 << max_capacity;


		if (getNumStream2 >> max_capacity){
			loop2 = false;
			break;

		}

		loop2 = false;
	}

	//get_Num_Rooms(&new_max_capacity, "max capacity of the room");



	cout << "How big is the room? (in square feet) sq.ft." << endl;
	cin >> sq_ft; cin.ignore(1, '\n');

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\nINVALID  number." << endl;

		std::cout << "Enter the size of room in squre.feet again--(Last chance to enter)" << endl;

		cin >> sq_ft; cin.ignore(1, '\n');


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
		--switchCase; cin.ignore(1, '\n');

		chosenFacility[z] = facility[switchCase];

		//getline(cin, chosenFacility[z]);


		cout << "Enough?[Y/N], Maximum 5, if want more, contact staff...(0166028563)" << endl;
		cin >> choice;
		cin.ignore(1, '\n');


		if (choice == 'y' || choice == 'Y' || z >= 5){
			break;
			loop = false;
		}
		else if (z < 5 || choice == 'n' || choice == 'N'){
			loop = true;
			++z;

		}

	}



	for (int w = 0; w < chosenFacility[w].length(); w++){
		facility_need_store = facility_need_store + "+" + chosenFacility[w];
	}


StartAgain:

	cout << "Write a description about the house/room (Max 50 words)" << endl;
	getline(cin, description);
	char Fchars[50]; for (int a = 0; a <= description.size(); a++){ Fchars[a] = description[a]; }

	int size = strlen(Fchars);
	if (size >= 50)
	{
		cout << "max allowed size is 50 char" << endl;
		goto StartAgain;
	}

	owner_id = c.sessionID;


	cout << "How much the room/house would be cost for daily-renting(cost per day in RM) [?RM/day]" << endl;
	cin >> day_price; cin.ignore(1, '\n');

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\nINVALID  cost." << endl;

		std::cout << "Enter the price of daily rental in RM--(Last chance to enter)" << endl;

		cin >> day_price;
		cin.ignore(1, '\n');

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


	home *homeObj = new home(newHomeID, home_address, no_room, no_bath_room, max_capacity, sq_ft, facility_need_store, description, owner_id, day_price, week_price, month_price);

	string homeDB = newHomeID.append(".txt");

	string newHomePortfolio = "dbhome/" + homeDB;


	ofstream newHome(newHomePortfolio.c_str());
	//newHome.write((char*)&homeObj, sizeof(homeObj));//write obj into file


	newHome << homeObj->getHomeID() << ' ' << space_underscore(homeObj->getHomeAddress()) << ' ' << homeObj->getNoRoom() << ' ' << homeObj->getNoBathRoom() << ' ' << homeObj->getMaxCapacity() << ' ' << homeObj->getSizeSqFt() << ' ' << space_underscore(homeObj->facility) << ' ' << space_underscore(homeObj->description) << ' ' << homeObj->owner_id << ' ' << homeObj->day_price << ' ' << homeObj->week_price << ' ' << homeObj->month_price << endl;
	newHome.close();

	ofstream dir("dbhome/db_home.txt", ios::app);
	dir << homeObj->getHomeID() << ' ' << space_underscore(homeObj->getHomeAddress()) << ' ' << homeObj->getNoRoom() << ' ' << homeObj->getNoBathRoom() << ' ' << homeObj->getMaxCapacity() << ' ' << homeObj->getSizeSqFt() << ' ' << space_underscore(homeObj->facility) << ' ' << space_underscore(homeObj->description) << ' ' << homeObj->owner_id << ' ' << homeObj->day_price << ' ' << homeObj->week_price << ' ' << homeObj->month_price << endl;
	dir.close();
	cout << "You have just added a home at '" + homeObj->getHomeAddress() + "' with home ID: '" + newHomeID + "'" << endl;

	system("pause");
	client_main(c.sessionID,c.sessionNAME);
}


void client::client_main(string client_id, string client_name){
	app a;
	
	c.sessionID = client_id;
	c.sessionNAME = client_name;

	system("cls");
	cout << "-----------Welcome Dear Owner: " + client_name + "-----------" << endl;
	cout << "----------------Owner Management Console---------------" << endl;
	system("color 0f");
	cout << "Please enter your choice" << endl;
	cout << "1.Manage Your Prfile Info" << endl;
	cout << "2.Manage Your Account Details" << endl;
	cout << "3.Manage Your owned home" << endl;
	cout << "4.Manage  Home have ordered by customers" << endl;
	cout << "5.Post my new home/House/Room" << endl;
	cout << "6.<<Log Out from Client Panel" << endl;


	int choice;
	cin >> choice;

	switch (choice){
	case 1:
		c.manage_profile(client_id, client_name);
		break;
	case 2:
		manage_account(client_id,client_name);
		break;
	case 3:
		manage_client_home();
		break;
	case 4:
		manage_booked_home();//view room which have booked by people
		break;
	case 5:
		add_home();//add new home
		break;


	case 6:
		a.main();
		//client_main(c.sessionID, c.sessionNAME);
		break;

	default:
		cout << "Pls choose beween interger 1 ~ 5 only" << endl;
	}
}