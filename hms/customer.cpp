 

#pragma once

#include "targetver.h"

#include "stdafx.h"
#include "customer.h"
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


customer cus;


string customer::getCustomerID(){ return customer_id; }
string customer::getCustomerPWD(){ return customer_pwd; }
string customer::getCustomerNAME(){ return customer_name; }
string customer::getCustomerPASSPORT(){ return customer_passport; }
string customer::getCustomerCONTACT(){ return customer_contact; }
string customer::getCustomerEMAIL(){ return customer_email; }
string customer::getCustomerADDRESS(){ return customer_address; }
string customer::getCustomerBANKACCT(){ return customer_bank_account; }

string customer::getCustomerBANK(){ return customer_bank; }
double customer::getCustomerCREDIT(){ return customer_credit; }

void customer::setCustomerID(string customerID_){ customer_id = customerID_; }

void customer::setCustomerPWD(string customerPWD){ customer_pwd = customerPWD; }
void customer::setCustomerNAME(string customerNAME){ customer_name = customerNAME; }
void customer::setCustomerPASSPORT(string customerPASSPORT){ customer_passport = customerPASSPORT; }
void customer::setCustomerCONTACT(string customerCONTACT){ customer_contact = customerCONTACT; }
void customer::setCustomerEMAIL(string customerEMAIL){ customer_email = customerEMAIL; }
void customer::setCustomerADDRESS(string customerADDRESS){ customer_address = customerADDRESS; }


void customer::setCustomerBANKACCT(string acct){ customer_bank_account = acct; }

void customer::setCustomerBANK(string bank){ customer_bank = bank; }
void customer::setCustomerCREDIT(double credit){ customer_credit = credit; }


void customer::setAttributes(string customerID, string customerPWD){
	customer_id = customerID; customer_pwd = customerPWD;
}
void customer::setAttributes(string customerID, string customerNAME, string customerPASSPORT, string customerPWD){
	customer_id = customerID; 
	customer_name = customerNAME; customer_passport = customerPASSPORT;
	
	customer_pwd = customerPWD;
}



void customer::setAttributes(string customerID, string customerNAME, string customerPASSPORT, string customerCONTACT, string customerEMAIL, string customerADDRESS, string bankAcct, string bank, double credit, string customerPWD){
	customer_id = customerID; customer_name = customerNAME; customer_passport = customerPASSPORT; customer_contact = customerCONTACT; customer_email = customerEMAIL; customer_address = customerADDRESS;
	customer_bank_account = bankAcct;
	customer_bank = bank;

	//default value gorsetting
	customer_credit = credit;
	customer_pwd = customerPWD;

}
string customer::space_underscore(std::string text) {
	for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
		if (*it == ' ') {
			*it = '_';
		}
	}
	return text;
}

customer::customer(){}
customer::customer(string customerID, string customerNAME, string customerPASSPORT, string customerCONTACT, string customerEMAIL, string customerADDRESS, string bankAcct, string bank, double credit = 0, string customerPWD = "password"){
	//initializer of obj customer
	customer_id = customerID; customer_name = customerNAME; customer_passport = customerPASSPORT; customer_contact = customerCONTACT; customer_email = customerEMAIL; customer_address = customerADDRESS;
	customer_bank_account = bankAcct;
	customer_bank = bank;

	//default value gorsetting
	customer_credit = credit;
	customer_pwd = customerPWD;


}
customer::~customer(){
	//destroy objects of customer to save heap memory in the RAM
}
void customer::manage_account(string customer_id, string customer_name){
	cout << "Welcome Dear valued customer " + customer_name + " to Our Felice Home-Stay  ";
	cout << "Select following account services -> " << endl;
	int choice;
	string filePortfolio = "dbcustomer/" + customer_id + "";
	filePortfolio.append(".txt");


	string new_customer_ID;
	string new_customer_pwd; string new_customer_name;
	string new_customer_passport; string new_customer_contact; string new_customer_email;
	string new_customer_address; string new_customer_bank_account;
	string new_customer_bank; double new_customer_credit;
	cout << "1.Change Account[" + customer_id + "] Password->" << endl;
	cout << "2.Top up my Felice Home Stay Credits->" << endl;
	cout << "3.Bind to another bank account and bank->" << endl;
	cin >> choice;
	if (choice == 1){
		string oldPwd;
		string newPwd;
		string newPwd_confirm;


	restart:
		system("cls");
		customer &cPoi = *new customer();
		//cout << customer_id;
		ifstream readcustomerProfile("dbcustomer/" + customer_id + ".txt");
		while (readcustomerProfile >> new_customer_ID >> new_customer_name >> new_customer_passport >> new_customer_contact >> new_customer_email >> new_customer_address >> new_customer_bank_account >> new_customer_bank >> new_customer_credit >> new_customer_pwd){
			cPoi.setAttributes(new_customer_ID, new_customer_name, new_customer_passport, new_customer_contact, new_customer_email, new_customer_address, new_customer_bank_account, new_customer_bank, new_customer_credit, new_customer_pwd);

		}readcustomerProfile.close();

		cout << "Please Enter your original password...->";
		cin >> oldPwd;
		if (oldPwd == cPoi.getCustomerPWD()){
		startPwdSet:
			cout << " Enter the new password you want to set...->";
			cin >> newPwd;
			cout << endl;
			cout << " Enter again the new password you want to set...->";
			cin >> newPwd_confirm;

			if (newPwd == newPwd_confirm){
				cPoi.setCustomerPWD(newPwd);




				ofstream tempPofolio("dbcustomer/tempPofolio.txt");

				ofstream temp("dbcustomer/temp.txt");
				ifstream customerD("dbcustomer/db_customer.txt");
				if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

					string line;
					while (getline(customerD, line))
					{
						if (line.find(customer_id) == string::npos) { //str.find(str2) != string::npos
							temp << line << endl;

						}
						else
						{
							/*			tempPofolio <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  cPoi.getCustomerPASSPORT() << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' << (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;
							temp <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  (cPoi.getCustomerPASSPORT()) << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' <<  (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;

							*/
							tempPofolio << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;
							temp << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;


						}
					}

				}
				tempPofolio.close();
				//customerPort.close();
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
				//change in db
				cout << "Congrats! You have updated your password!" << endl;
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
	else if (choice == 2){

		customer &cPoi = *new customer();
		ifstream readcustomerProfile("dbcustomer/" + customer_id + ".txt");
		while (readcustomerProfile >> new_customer_ID >> new_customer_name >> new_customer_passport >> new_customer_contact >> new_customer_email >> new_customer_address >> new_customer_bank_account >> new_customer_bank >> new_customer_credit >> new_customer_pwd){
			cPoi.setAttributes(new_customer_ID, new_customer_name, new_customer_passport, new_customer_contact, new_customer_email, new_customer_address, new_customer_bank_account, new_customer_bank, new_customer_credit, new_customer_pwd);
		}readcustomerProfile.close();

		cout << "You are directing to a payment console";
		cout << "Following is your Bank Info:";
		cout << "Bank Branch Name:" << cPoi.getCustomerBANK() << endl;
		cout << "Your " + cPoi.getCustomerBANK() + "-Bank Account Number:" << cPoi.getCustomerBANKACCT() << endl;
		cout << "Use " + cPoi.getCustomerBANK() + "- " + cPoi.getCustomerBANKACCT() + " this bank account to top up?[Y/N]" << endl;
		double top_up_amt;
		double balance;
		char select;
		cin >> select;
		if (select == 'y' || select == 'Y'){
		reTypeCredit:
			cout << "How much you want to top-up to your credit?" << endl;
			cin >> top_up_amt;
			if (cin.fail()){
				cin.ignore();
				cin.clear();
				cout << "Invalid top-up amount" << endl;
				goto reTypeCredit;
			}
			cout << "Enter " + cPoi.getCustomerBANKACCT() + " account PIN:" << endl;
			Sleep(5000);//2seconds
			cout << "Authenticating " + cPoi.getCustomerBANKACCT() + " with Bank " + cPoi.getCustomerBANK() + "" << endl;
			Sleep(3000);//2seconds
			cout << "Validating......" << endl;

			balance = cPoi.getCustomerCREDIT() + top_up_amt;
			cPoi.setCustomerCREDIT(balance);




			ofstream tempPofolio("dbcustomer/tempPofolio.txt");

			ofstream temp("dbcustomer/temp.txt");
			ifstream customerD("dbcustomer/db_customer.txt");
			if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

				string line;
				while (getline(customerD, line))
				{
					if (line.find(customer_id) == string::npos) { //str.find(str2) != string::npos
						temp << line << endl;

					}
					else
					{

						/*	tempPofolio <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  (cPoi.getCustomerPASSPORT()) << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' <<  (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;
						temp <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  (cPoi.getCustomerPASSPORT()) << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' <<  (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;

						*/

						tempPofolio << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;
						temp << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;


					}
				}

			}
			tempPofolio.close();
			//customerPort.close();
			customerD.close();

			temp.close();

			string filePortfolio = "dbcustomer/" + customer_id + "";
			filePortfolio.append(".txt");
			string db_old_file = "dbcustomer/db_customer.txt";
			//system("del dbcustomer/db_customer.txt");
			const char *data = "dbcustomer/db_customer.txt";
			remove(db_old_file.c_str());//delete the old db file first


			//system("del dbcustomer/db_customer.txt");
			remove(filePortfolio.c_str());

			rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
			rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
			//change in db
			cout << "Congrats! You have toppped up " + toString(top_up_amt) + " with bank account " + cPoi.getCustomerBANKACCT() + "!" << endl;








		}
		else{
			string tempBank;
			string tempBankAcct;//bank info not in db
			cout << "You may Enter Another Bank and account to top up" << endl;
			cout << "Enter your bank name:" << endl;
			cin >> tempBank;
			cout << "Enter your " + tempBank + "-bank Account number:" << endl;
			cin >> tempBankAcct;
			cPoi.setCustomerBANK(tempBank);
			cPoi.setCustomerBANKACCT(tempBankAcct);

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

			balance = cPoi.getCustomerCREDIT() + top_up_amt;
			cPoi.setCustomerCREDIT(balance);





			ofstream tempPofolio("dbcustomer/tempPofolio.txt");

			ofstream temp("dbcustomer/temp.txt");
			ifstream customerD("dbcustomer/db_customer.txt");
			if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

				string line;
				while (getline(customerD, line))
				{
					if (line.find(customer_id) == string::npos) { //str.find(str2) != string::npos
						temp << line << endl;

					}
					else
					{

						/*	tempPofolio <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  (cPoi.getCustomerPASSPORT()) << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' <<  (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;
						temp <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  (cPoi.getCustomerPASSPORT()) << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' <<  (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;
						*/

						tempPofolio << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;
						temp << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;



					}
				}

			}
			tempPofolio.close();
			//customerPort.close();
			customerD.close();

			temp.close();

			string filePortfolio = "dbcustomer/" + customer_id + "";
			filePortfolio.append(".txt");
			string db_old_file = "dbcustomer/db_customer.txt";
			//system("del dbcustomer/db_customer.txt");
			const char *data = "dbcustomer/db_customer.txt";
			remove(db_old_file.c_str());//delete the old db file first


			//system("del dbcustomer/db_customer.txt");
			remove(filePortfolio.c_str());

			rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
			rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
			//change in db
			cout << "Congrats! You have toppped up " + toString(top_up_amt) + " with bank account " + tempBankAcct + "!" << endl;



		}



	}
	else if (choice == 3){

		customer &cPoi = *new customer();
		ifstream readcustomerProfile("dbcustomer/" + customer_id + ".txt");
		while (readcustomerProfile >> new_customer_ID >> new_customer_name >> new_customer_passport >> new_customer_contact >> new_customer_email >> new_customer_address >> new_customer_bank_account >> new_customer_bank >> new_customer_credit >> new_customer_pwd){
			cPoi.setAttributes(new_customer_ID, new_customer_name, new_customer_passport, new_customer_contact, new_customer_email, new_customer_address, new_customer_bank_account, new_customer_bank, new_customer_credit, new_customer_pwd);
		}readcustomerProfile.close();
		string tempBank;
		string tempBankAcct;//bank info not in db
		cout << "You may Enter Another Bank and account to top up" << endl;
		cout << "Enter your bank name:" << endl;
		cin >> tempBank;
		cout << "Enter your " + tempBank + "-bank Account number:" << endl;
		cin >> tempBankAcct;
		cPoi.setCustomerBANK(tempBank);
		cPoi.setCustomerBANKACCT(tempBankAcct);


		cout << "Enter " + tempBankAcct + " account PIN:" << endl;
		Sleep(2000);//2seconds
		cout << "Authenticating " + tempBankAcct + " with Bank " + tempBank + "" << endl;
		Sleep(1000);//2seconds
		cout << "Validating......" << endl;


		ofstream tempPofolio("dbcustomer/tempPofolio.txt");

		ofstream temp("dbcustomer/temp.txt");
		ifstream customerD("dbcustomer/db_customer.txt");
		if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

			string line;
			while (getline(customerD, line))
			{
				if (line.find(customer_id) == string::npos) { //str.find(str2) != string::npos
					temp << line << endl;

				}
				else
				{

					tempPofolio << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;
					temp << space_underscore(cPoi.getCustomerID()) << ' ' << space_underscore(cPoi.getCustomerNAME()) << ' ' << space_underscore(cPoi.getCustomerPASSPORT()) << ' ' << space_underscore(cPoi.getCustomerCONTACT()) << ' ' << space_underscore(cPoi.getCustomerEMAIL()) << ' ' << space_underscore(cPoi.getCustomerADDRESS()) << ' ' << space_underscore(cPoi.getCustomerBANKACCT()) << ' ' << space_underscore(cPoi.getCustomerBANK()) << ' ' << space_underscore(toString(cPoi.getCustomerCREDIT())) << ' ' << space_underscore(cPoi.getCustomerPWD()) << endl;
					/*
					tempPofolio <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  (cPoi.getCustomerPASSPORT()) << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' << (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;
					temp <<  (cPoi.getCustomerID()) << ' ' <<  (cPoi.getCustomerNAME()) << ' ' <<  (cPoi.getCustomerPASSPORT()) << ' ' <<  (cPoi.getCustomerCONTACT()) << ' ' <<  (cPoi.getCustomerEMAIL()) << ' ' << (cPoi.getCustomerADDRESS()) << ' ' <<  (cPoi.getCustomerBANKACCT()) << ' ' <<  (cPoi.getCustomerBANK()) << ' ' <<  (toString(cPoi.getCustomerCREDIT())) << ' ' <<  (cPoi.getCustomerPWD()) << endl;
					*/
				}
			}

		}
		tempPofolio.close();
		//customerPort.close();
		customerD.close();

		temp.close();

		string filePortfolio = "dbcustomer/" + customer_id + "";
		filePortfolio.append(".txt");
		string db_old_file = "dbcustomer/db_customer.txt";
		//system("del dbcustomer/db_customer.txt");
		const char *data = "dbcustomer/db_customer.txt";
		remove(db_old_file.c_str());//delete the old db file first


		//system("del dbcustomer/db_customer.txt");
		remove(filePortfolio.c_str());

		rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
		rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
		//change in db
		cout << "Congrats! You have added bank account " + tempBankAcct + " to your account!" << endl;





	}

	system("pause");
	customer_main(customer_id, customer_name);

}
void customer::book_stay(){
	//********


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
	cout << "-----------Welcome Customer: " + cus.sessionNAME + "-----------" << endl;
	cout << "--------------Felice Home-Stay Booking System------------------" << endl;
	home *homePtr = new home();
	homePtr->displayDetail();
	system("color 0f");
	cout << "************************************************************" << endl;
	cout << "Above are the available home-stay rooms/houses can be booked" << endl;
	cout << "************************************************************" << endl;
	cout << "What kind of booking you are looking for? [Monthly booking?] [Weekly Booking?] [Daily Booking?] Please select " << endl;
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


customer_id = cus.sessionID;
string customerID; string customerName; string customerIC; string customerContact; string customerEmail; 
string customerAddress; string customerBankAcct; string customerBank; double customerCredit; string customerPwd;


ifstream readcustomerId("dbcustomer/"+customer_id+".txt");

	while (readcustomerId >> customerID >> customerName >> customerIC >> customerContact >> customerEmail >> customerAddress >> customerBankAcct >> customerBank >> customerCredit >> customerPwd){
		// cout << customerID << endl;
		cus.setCustomerID(customerID);
		cus.setCustomerNAME(customerName);
		cus.setCustomerPASSPORT(customerIC);
		cus.setCustomerCONTACT(customerContact);
		cus.setCustomerEMAIL(customerEmail);
		cus.setCustomerADDRESS(customerAddress);
		cus.setCustomerBANKACCT(customerBankAcct);

		cus.setCustomerBANK(customerBank);
		cus.setCustomerCREDIT(customerCredit);

		cus.setCustomerPWD(customerPwd);

	}readcustomerId.close();
	

	cout << endl; cout << endl;

	cout << "Which home-stay you would like to book?" << endl;
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
	}readHome.close();
	cout << " " << endl;
	cout << "*******************************************************" << endl;
	cout << " " << endl;
	cout << "Below are the room have selected for you to book: " << endl;
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
	string clientFileRead = "dbclient/" + client_id;
	clientFileRead.append(".txt");
	ifstream readClient(clientFileRead.c_str());
	//client attribs need save to client obj ptr
	string client_name; string client_ic; string client_contact; string client_email;
	string client_address; string client_bank_acct; string client_bank; double client_credit; string client_pwd;
	client *clientPtr = new client();

	while (readClient >> client_id >> client_name >> client_ic >> client_contact >> client_email >> client_address >> client_bank_acct >> client_bank >> client_credit >> client_pwd){
		clientPtr->setAttributes(client_id, client_name, client_ic, client_contact, client_email, client_address, client_bank_acct, client_bank, client_credit, client_pwd);
	}readClient.close();

	//int firstIdx; int secondIdx; int thirdIdx; int forthIdx; int fifthIdx; int sixthIdx;
	double customer_balance;


	double client_money = clientPtr->getClientCREDIT();
	double customer_money = cus.getCustomerCREDIT();
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
		cout << "So your Move out Date will be " + chk_out + "" << endl;
		cout << endl;
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
		inDay = chk_inresult[0];//20  
		inMonth = chk_inresult[1];//12
		inYear = chk_inresult[2];//2016
		strTempTime = chk_inresult[3];//14:00
		cout << "So your Move in Date will be "+chk_in+""<< endl;
		cout << endl;
		inDayInt = stoi(inDay);
		inMonthInt = stoi(inMonth);
		inYearInt = stoi(inYear);


		total_pay = bookingPtr->outPutTotalPay_daily(homePtr->day_price, inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);
		duration = bookingPtr->getTotalDay(inDayInt, inMonthInt, inYearInt, outDayInt, outMonthInt, outYearInt);

		//now check the customer have enough balance to pay
		if (customer_money >= total_pay){

			customer_balance = customer_money - total_pay;
			cus.setCustomerCREDIT(customer_balance);//minus the credit of customer


			stringstream ss;//stringstream ss;
			ss << cus.getCustomerID();
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

						tempPofolio << space_underscore(cus.getCustomerID()) << ' ' << space_underscore(cus.getCustomerNAME()) << ' ' << space_underscore(cus.getCustomerPASSPORT()) << ' ' << space_underscore(cus.getCustomerCONTACT()) << ' ' << space_underscore(cus.getCustomerEMAIL()) << ' ' << space_underscore(cus.getCustomerADDRESS()) << ' ' << space_underscore(cus.getCustomerBANKACCT()) << ' ' << space_underscore(cus.getCustomerBANK()) << ' ' << cus.getCustomerCREDIT() << ' ' << space_underscore(cus.getCustomerPWD()) << endl;
						temp << space_underscore(cus.getCustomerID()) << ' ' << space_underscore(cus.getCustomerNAME()) << ' ' << space_underscore(cus.getCustomerPASSPORT()) << ' ' << space_underscore(cus.getCustomerCONTACT()) << ' ' << space_underscore(cus.getCustomerEMAIL()) << ' ' << space_underscore(cus.getCustomerADDRESS()) << ' ' << space_underscore(cus.getCustomerBANKACCT()) << ' ' << space_underscore(cus.getCustomerBANK()) << ' ' << cus.getCustomerCREDIT() << ' ' << space_underscore(cus.getCustomerPWD()) << endl;
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







			bookingPtr->setBookingID(newBookingID); bookingPtr->setBookingHomeID(homePtr->getHomeID());
			bookingPtr->setBookingClientID(homePtr->owner_id); bookingPtr->setBookingCustomerID(cus.getCustomerID());
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
			cout << "You have just added a Booking at '" + homePtr->getHomeAddress() + "' which owned by " + clientPtr->getClientNAME() + " with home ID: '" + homePtr->getHomeID() + "' with Booking Id: " + newBookingID + " for customer " + cus.getCustomerNAME() + " with " + toString(duration) + " days stay" << endl;

			cout << "Client " + clientPtr->getClientNAME() + " has successfully received RM" + toString(total_pay) + " from customer " + cus.getCustomerNAME() + " with booking Id: " + newBookingID + " " << endl;





		}
		else{
			cout << "Sorry, Customer " + cus.getCustomerNAME() + " does not have enough balance to pay the rental RM" + toString(total_pay) + " for the homestay at " + homePtr->getHomeAddress() + " for " + toString(duration) + " days stay" << endl;

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

			double customer_balance = customer_money - total_pay;
			cus.setCustomerCREDIT(customer_balance);//minus the credit of customer


			stringstream ss;//stringstream ss;
			ss << cus.getCustomerID();
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

						tempPofolio << space_underscore(cus.getCustomerID()) << ' ' << space_underscore(cus.getCustomerNAME()) << ' ' << space_underscore(cus.getCustomerPASSPORT()) << ' ' << space_underscore(cus.getCustomerCONTACT()) << ' ' << space_underscore(cus.getCustomerEMAIL()) << ' ' << space_underscore(cus.getCustomerADDRESS()) << ' ' << space_underscore(cus.getCustomerBANKACCT()) << ' ' << space_underscore(cus.getCustomerBANK()) << ' ' << cus.getCustomerCREDIT() << ' ' << space_underscore(cus.getCustomerPWD()) << endl;
						temp << space_underscore(cus.getCustomerID()) << ' ' << space_underscore(cus.getCustomerNAME()) << ' ' << space_underscore(cus.getCustomerPASSPORT()) << ' ' << space_underscore(cus.getCustomerCONTACT()) << ' ' << space_underscore(cus.getCustomerEMAIL()) << ' ' << space_underscore(cus.getCustomerADDRESS()) << ' ' << space_underscore(cus.getCustomerBANKACCT()) << ' ' << space_underscore(cus.getCustomerBANK()) << ' ' << cus.getCustomerCREDIT() << ' ' << space_underscore(cus.getCustomerPWD()) << endl;
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
			bookingPtr->setBookingClientID(homePtr->owner_id); bookingPtr->setBookingCustomerID(cus.getCustomerID());
			bookingPtr->setBookingType('w'); bookingPtr->setStayDuration(duration);
			bookingPtr->setChkIn(chk_in); bookingPtr->setChkOut(chk_out);
			bookingPtr->setUnitPirce(homePtr->week_price); bookingPtr->setTotalPaid(total_pay);
			//new booking info save into db

			string newBookingPortfolio = "dbbooking/" + newBookingID + ".txt";


			ofstream newBooking(newBookingPortfolio.c_str());
			newBooking << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << "w" << ' ' << toString(duration) << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl;
			newBooking.close();

			ofstream dir("dbbooking/db_booking.txt", ios::app);
			dir << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << "w" << ' ' << toString(duration) << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl; dir.close();
			cout << "You have just added a Booking at '" + homePtr->getHomeAddress() + "' which owned by " + clientPtr->getClientNAME() + " with home ID: '" + homePtr->getHomeID() + "' with Booking Id: " + newBookingID + " for customer " + cus.getCustomerNAME() + "  with " + toString(duration) + " weeks stay" << endl;

			cout << "Client " + clientPtr->getClientNAME() + " has successfully received RM" + toString(total_pay) + " from you with booking Id: " + newBookingID + " " << endl;





		}
		else{
			cout << "Sorry, you do not have enough balance to pay the rental RM" + toString(total_pay) + " for the homestay at " + homePtr->getHomeAddress() + " for " + toString(duration) + " weeks stay, you can top up the credit then come to purchase" << endl;

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
			cus.setCustomerCREDIT(customer_balance);//minus the credit of customer


			stringstream ss;//stringstream ss;
			ss << cus.getCustomerID();
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

						tempPofolio << space_underscore(cus.getCustomerID()) << ' ' << space_underscore(cus.getCustomerNAME()) << ' ' << space_underscore(cus.getCustomerPASSPORT()) << ' ' << space_underscore(cus.getCustomerCONTACT()) << ' ' << space_underscore(cus.getCustomerEMAIL()) << ' ' << space_underscore(cus.getCustomerADDRESS()) << ' ' << space_underscore(cus.getCustomerBANKACCT()) << ' ' << space_underscore(cus.getCustomerBANK()) << ' ' << cus.getCustomerCREDIT() << ' ' << space_underscore(cus.getCustomerPWD()) << endl;
						temp << space_underscore(cus.getCustomerID()) << ' ' << space_underscore(cus.getCustomerNAME()) << ' ' << space_underscore(cus.getCustomerPASSPORT()) << ' ' << space_underscore(cus.getCustomerCONTACT()) << ' ' << space_underscore(cus.getCustomerEMAIL()) << ' ' << space_underscore(cus.getCustomerADDRESS()) << ' ' << space_underscore(cus.getCustomerBANKACCT()) << ' ' << space_underscore(cus.getCustomerBANK()) << ' ' << cus.getCustomerCREDIT() << ' ' << space_underscore(cus.getCustomerPWD()) << endl;
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
			bookingPtr->setBookingClientID(homePtr->owner_id); bookingPtr->setBookingCustomerID(cus.getCustomerID());
			bookingPtr->setBookingType('m'); bookingPtr->setStayDuration(duration);
			bookingPtr->setChkIn(chk_in); bookingPtr->setChkOut(chk_out);
			bookingPtr->setUnitPirce(homePtr->month_price); bookingPtr->setTotalPaid(total_pay);
			//new booking info save into db

			string newBookingPortfolio = "dbbooking/" + newBookingID + ".txt";


			ofstream newBooking(newBookingPortfolio.c_str());
			newBooking << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << type << ' ' << toString(duration) << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl;
			newBooking.close();

			ofstream dir("dbbooking/db_booking.txt", ios::app);
			dir << bookingPtr->getBookingID() << ' ' << space_underscore(bookingPtr->getBookingHomeID()) << ' ' << bookingPtr->getBookingClientID() << ' ' << bookingPtr->getBookingcustomerID() << ' ' << type << ' ' << toString(duration) << ' ' << space_underscore(bookingPtr->getBookingChkIn()) << ' ' << space_underscore(bookingPtr->getBookingChkOut()) << ' ' << bookingPtr->getUnitPrice() << ' ' << bookingPtr->getTotalPaid() << endl; dir.close();
			cout << "You have just added a Booking at '" + homePtr->getHomeAddress() + "' which owned by " + clientPtr->getClientNAME() + " with home ID: '" + homePtr->getHomeID() + "' with Booking Id: " + newBookingID + "  with " + toString(duration) + " months stay" << endl;

			cout << "Client " + clientPtr->getClientNAME() + " has successfully received RM" + toString(total_pay) + " from with booking Id: " + newBookingID + " " << endl;





		}
		else{
			cout << "Sorry, Customer you do not have enough balance to pay the rental RM" + toString(total_pay) + " for the homestay at " + homePtr->getHomeAddress() + " for " + toString(duration) + " months stay, Please top up first" << endl;

		}

		break;

	}

	system("pause");
	customer_main(cus.sessionID,cus.sessionNAME);

	//********
}
void customer::view_booking(){
	cout <<"Welcome "+cus.sessionNAME+" , here you can view the booking you have made in Felice Home-Stay System" << endl;
	cout << "***************************************************************************************************" << endl;

	booking::displaySpecificCustomerID(cus.sessionID);

	system("pause");
	customer_main(cus.sessionID,cus.sessionNAME);
}
void customer::comment_home(){

	ifstream homeRead("dbhome/db_home.txt");
	ifstream commentRead("dbhome/comment.txt");
	
	string home_id; string home_address; string home_facility; string owner_id;
	string home_description; string comment;

	string home_id_r=""; string home_address_r=""; string home_facility_r=""; string owner_id_r="";
	string home_description_r=""; string comment_r="";

	home hme[200];

	int no_room; int no_bath_room; int max_capacity; double sq_ft; 
	double day_price; double month_price; double week_price;
	string commentID; string commentID_r = "";

	int count = 0;
	while (commentRead>>commentID>>home_id>>home_address>>home_facility>>home_description>>owner_id>>comment){
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
		hme[count].setHomeID(home_id); hme[count].setHomeAddress(home_address); hme[count].facility=home_facility;
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
	for (int i = 0; i < commentID_r.length()+3; i++){
		cout << " ";
	}
	cout << "Home-ID";
	for (int i = 0; i < home_id_r.length()+4; i++){
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
	for (int i = 0; i < owner_id_r.length()+8; i++){
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
	cout <<  endl;



	for (int n = 0; n < count;n++){
		cout << hme[n].getCommentID();
		for (int i = 0; i < commentID_r.length() - (hme[n].getCommentID().length())+13; i++){
			cout << " ";
		}
		cout<<hme[n].getHomeID(); 
		for (int i = 0; i < home_id_r.length() - (hme[n].getHomeID().length())+10; i++){
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
		cout << hme[n].owner_id ;
		for (int i = 0; i < owner_id_r.length() - (hme[n].owner_id.length()) + 13; i++){
			cout << " ";
		}
		cout << hme[n].getComment();
		cout << endl;
		cout << endl;

	}
	string commentID_comment;
	string home_address_comment; string home_facility_comment; string owner_id_comment;
	string home_description_comment; string comment_comment;

	string select;
	cout << endl;
	cout <<"==========================================================================================="<< endl;
	cout << "===Add a comment? [Y/N] ===" << endl;
	cin >> select;
	if (select=="y" || select=="Y"){
		cout << "Following are list of Home available , you can pick one and enter the home ID , then you can comment about it!"<< endl;
		cout << "--------------------------------------------------------------------------------------------------------------" << endl;
		cout << "We appreciate Your Comments! Because your comments help other customer's selection on the renting" << endl;
		cout << "Thank you for your support!" << endl;
		
commentLoop:
		cout << "Following are all the rooms/houses in Felice System available for rent, You can comment any one of them..."<< endl;
		home homeDiaplay;
		homeDiaplay.displayDetail();


		string response;
		home commentObj; string commentHomeID;


		cout << "=========================================================================================================="<< endl;
		cout << "====Please Enter a home ID that you wanted to make comment about!=====" << endl;
		cin >> commentHomeID;
homeDiaplay.displaySpecificRoom(commentHomeID);
		
		cout << "==========================================================================================================" << endl;
		cout << "====Is this the one You want to comment with? [Y/N]=====" << endl;
		
		cin >> response;
		if (response=="y" || response=="Y"){
		
			ifstream homeCommentStream("dbhome/" + commentHomeID + ".txt");
			while (homeCommentStream >> home_id >> home_address_comment >> no_room >> no_bath_room >> max_capacity >> sq_ft >> home_facility_comment >> home_description_comment >> owner_id_comment >> day_price >> week_price >> month_price){
			
				/*
				string home_address_comment; string home_facility_comment; string owner_id_comment;
				string home_description_comment; string comment_comment;

				*/
				commentObj.setHomeID(home_id);commentObj.setHomeAddress(home_address_comment);
				commentObj.facility = home_facility_comment; commentObj.description = home_description_comment;
				commentObj.owner_id = owner_id_comment;

			}
			homeCommentStream.close();
			cout << "Now enter the comments about the house/room with Home ID " + commentHomeID + " located at "+commentObj.getHomeAddress()+"" << endl;
			cin.get();
			getline(cin,comment_comment);
			comment_comment.append("--"+cus.sessionID+"");
			commentObj.setComment(space_underscore(comment_comment));

			string l_comment = "";
			int hcomment_number_of_lines = 0;
			ifstream readLineComment("dbhome/comment.txt");
			if (readLineComment.is_open()){
				while (!readLineComment.eof()){
					getline(readLineComment, l_comment);
					// cout << l << endl;
					hcomment_number_of_lines++;
				}
				// myfile.close();
			}readLineComment.close();

			commentID_comment = "comment" + toString(hcomment_number_of_lines);
			commentObj.setCommentID(commentID_comment);


			ofstream dirComment("dbhome/comment.txt", ios::app);
			dirComment << commentObj.getCommentID()<< ' ' << commentObj.getHomeID() << ' ' << space_underscore(commentObj.getHomeAddress()) << ' ' << space_underscore(commentObj.facility) << ' ' << space_underscore(commentObj.description) << ' ' << commentObj.owner_id << ' ' << commentObj.getComment() << endl;
			dirComment.close();
			cout << "You have just added a comment for '" + commentObj.getHomeAddress() + "' with home ID: '" + commentHomeID + "'" << endl;




		}
		else{
			goto commentLoop;
		}


	}
	



	system("pause");
	customer_main(cus.sessionID,cus.sessionNAME);

}

void customer::manage_profile(string customer_id, string cusName){

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


	string customer_ID; string customer_pwd; string customer_name;
	string customer_passport; string customer_contact; string customer_email;
	string customer_address; string customer_bank_account;
	string customer_bank; double customer_credit;

	string new_customer_pwd; string new_customer_name;
	string new_customer_passport; string new_customer_contact; string new_customer_email;
	string new_customer_address; string new_customer_bank_account;
	string new_customer_bank; double new_customer_credit;

restart:
	system("cls");
	ifstream readcustomerProfile("dbcustomer/" + customer_id + ".txt");
	while (readcustomerProfile >> customer_ID >> customer_name >> customer_passport >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){

		if (currentHourInt >= 12 && currentHourInt<18){
			cout << "Good Afternoon " + customer_name + "! Welcome to the Felice HomeStay Management System" << endl;
		}
		else if (currentHourInt >= 18 && currentHourInt <= 23){
			cout << "Good Evening " + customer_name + "! Welcome to the Felice HomeStay Management System" << endl;

		}
		else{
			cout << "Good Morning " + customer_name + "! Welcome to the Felice HomeStay Management System" << endl;

		}
		cout << "======================================================================================" << endl;

		cout << "Your ID: " << customer_ID << endl;
		cout << "Your Name: " << customer_name << endl;
		cout << "Your Passport: " << customer_passport << endl;
		cout << "Your Contact: " << customer_contact << endl;
		cout << "Your Email: " << customer_email << endl;
		cout << "Your Address: " << customer_address << endl;
		cout << "Your Bank Account: " << customer_bank_account << endl;
		cout << "Your Bank is under : " << customer_bank << endl;
		cout << "*************************************************************************************" << endl;

		cout << "Your Account Remaining Credit: " << customer_credit << endl;

	}

	readcustomerProfile.close();
	customer c;
	char choice;
	cout << "Want to edit Your personal information?[Y/N]" << endl;

	cin >> choice;

	if (choice == 'y' || choice == 'Y'){
		cout << "Enter your New Name";
		cin >> new_customer_name;
		cout << endl;

		cout << "Enter your New IC/Passport number";
		cin >> new_customer_passport;
		cout << endl;

		cout << "Enter your New Contact number";
		cin >> new_customer_contact;
		cout << endl;

		cout << "Enter your New Email";
		cin >> new_customer_email;
		cout << endl;

		cout << "Enter your New Address";
		cin >> new_customer_address;
		cout << endl;

		cout << "Enter your New Bank Name";
		cin >> new_customer_bank;
		cout << endl;

		cout << "Enter your New Bank Account Number";
		cin >> new_customer_bank_account;
		cout << endl;

		c.setAttributes(customer_ID, new_customer_name, new_customer_passport, new_customer_contact, new_customer_email, new_customer_address, new_customer_bank_account, new_customer_bank, customer_credit, customer_pwd);




		ofstream tempPofolio("dbcustomer/tempPofolio.txt");

		ofstream temp("dbcustomer/temp.txt");
		ifstream customerD("dbcustomer/db_customer.txt");
		if (tempPofolio.is_open() && customerD.is_open() && temp.is_open()){

			string line;
			while (getline(customerD, line))
			{
				if (line.find(customer_id) == string::npos) { //str.find(str2) != string::npos
					temp << line << endl;

				}
				else
				{
					/*	tempPofolio << (c.getCustomerID()) << ' ' << (c.getCustomerNAME()) << ' ' << (c.getCustomerPASSPORT()) << ' ' << (c.getCustomerCONTACT()) << ' ' << (c.getCustomerEMAIL()) << ' ' << (c.getCustomerADDRESS()) << ' ' << (c.getCustomerBANKACCT()) << ' ' << (c.getCustomerBANK()) << ' ' << (toString(c.getCustomerCREDIT())) << ' ' << (c.getCustomerPWD()) << endl;
					temp << (c.getCustomerID()) << ' ' << (c.getCustomerNAME()) << ' ' << (c.getCustomerPASSPORT()) << ' ' << (c.getCustomerCONTACT()) << ' ' << (c.getCustomerEMAIL()) << ' ' << (c.getCustomerADDRESS()) << ' ' << (c.getCustomerBANKACCT()) << ' ' << (c.getCustomerBANK()) << ' ' << (toString(c.getCustomerCREDIT())) << ' ' << (c.getCustomerPWD()) << endl;
					*/

					tempPofolio << space_underscore(c.getCustomerID()) << ' ' << space_underscore(c.getCustomerNAME()) << ' ' << space_underscore(c.getCustomerPASSPORT()) << ' ' << space_underscore(c.getCustomerCONTACT()) << ' ' << space_underscore(c.getCustomerEMAIL()) << ' ' << space_underscore(c.getCustomerADDRESS()) << ' ' << space_underscore(c.getCustomerBANKACCT()) << ' ' << space_underscore(c.getCustomerBANK()) << ' ' << space_underscore(toString(c.getCustomerCREDIT())) << ' ' << space_underscore(c.getCustomerPWD()) << endl;
					temp << space_underscore(c.getCustomerID()) << ' ' << space_underscore(c.getCustomerNAME()) << ' ' << space_underscore(c.getCustomerPASSPORT()) << ' ' << space_underscore(c.getCustomerCONTACT()) << ' ' << space_underscore(c.getCustomerEMAIL()) << ' ' << space_underscore(c.getCustomerADDRESS()) << ' ' << space_underscore(c.getCustomerBANKACCT()) << ' ' << space_underscore(c.getCustomerBANK()) << ' ' << space_underscore(toString(c.getCustomerCREDIT())) << ' ' << space_underscore(c.getCustomerPWD()) << endl;


				}
			}

		}
		tempPofolio.close();
		//customerPort.close();
		customerD.close();

		temp.close();

		string filePortfolio = "dbcustomer/" + customer_ID + "";
		filePortfolio.append(".txt");
		string db_old_file = "dbcustomer/db_customer.txt";
		//system("del dbcustomer/db_customer.txt");
		const char *data = "dbcustomer/db_customer.txt";
		remove(db_old_file.c_str());//delete the old db file first


		//system("del dbcustomer/db_customer.txt");
		remove(filePortfolio.c_str());

		rename("dbcustomer/tempPofolio.txt", filePortfolio.c_str());
		rename("dbcustomer/temp.txt", "dbcustomer/db_customer.txt");
		//******
		cout << "You have successfully updated your profile" << endl;
	}
	else{
		customer_main(cus.sessionID, cus.sessionNAME);

	}


	system("pause");
	
	customer_main(cus.sessionID, cus.sessionNAME);

}//inherited method @override


string customer::RandomString(int len)
{
	srand(time(0));
	string str_customer = "customer";
	string str = "0123456789abcdefghijklmnopqrstuvwxyz";
	int pos;
	while (str.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		str.erase(pos, 1);
	}
	return str_customer+str;
}



void customer::register_customer(){

	system("cls");
	cout << "----------Felice Customer Register Panel----------" << endl;
	cout << "==================================================" << endl;
	system("color 0f");

	customer *c = new customer();
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
	
	string fileName;

	bool chkIDexist=false;
	
	string chkId;
	string randID;
	ifstream chkID("dbcustomer/db_customer.txt");
	string line;
	while (std::getline(chkID, line) || chkIDexist)
	{ randID =cus.RandomString(6); 

	int strpos = line.find(" ");
	chkId = line.substr(0, strpos);
	//cout << chkId << endl;
	if (chkId == randID){
			chkIDexist = true;
		}
	}
	chkID.close();

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	cout << "For security Reson Your customer ID will be auto generated! and this ID Can no longer be chaged furthur more!" << endl;
	
	cout << "Your Customer ID:" + randID + ", Please Remember it!" << endl;
	cin.ignore(1, '\n');
	customer_id = randID;






	cout << "Now Enter Your customer Name:";

	//cin.get();
	getline(cin, customer_name);
	// cin >> customer_name;
	cout << "Enter Your IC/Passport Number:";
	//cin.get();
	getline(cin, customer_ic);
	cout << "Enter Your customer Contact Number(Prefer Malaysia Number):";
	//cin.get();
	getline(cin, customer_contact);
	cout << "Enter Your customer Email:";
	//cin.get();
	getline(cin, customer_email);
cout << "Enter Your customer Address:";
	//cin.get();
	getline(cin, customer_address);

	cout << "Enter Your customer Bank:";
//	cin.get();
	getline(cin, customer_bank);
	cout << "Input Your " + customer_bank + "-Bank Account Number:";
	//cin.get();
	getline(cin, customer_bank_account);
	//cin >> customer_bank_account;
	cout << endl;

	string pwdConfirm;

	cout << "Now set your password!"; cout << endl;
	cin >> customer_pwd;
	cout << "To confirm your password, please type again the password you have entered!"; cout << endl;
	cin >> pwdConfirm;
	cin.ignore(1, '\n');

	customer_credit = 0;
	if (pwdConfirm == customer_pwd){
		c->setAttributes(customer_id, customer_name, customer_ic, customer_contact, customer_email, customer_address, customer_bank_account, customer_bank, customer_credit, customer_pwd);

	}





	stringstream ss;//stringstream ss;
	ss << customer_id;
	string customer_id2 = ss.str();
	// string *add_empId2=&empId2;
	customer_id2.append(".txt");
	string newPortfolio = "dbcustomer/" + customer_id2;

	ofstream newcustomer(newPortfolio.c_str());
	newcustomer << space_underscore(c->getCustomerID()) << ' ' << space_underscore(c->getCustomerNAME()) << ' ' << space_underscore(c->getCustomerPASSPORT()) << ' ' << space_underscore(c->getCustomerCONTACT()) << ' ' << space_underscore(c->getCustomerEMAIL()) << ' ' << space_underscore(c->getCustomerADDRESS()) << ' ' << space_underscore(c->getCustomerBANKACCT()) << ' ' << space_underscore(c->getCustomerBANK()) << ' ' << space_underscore(toString(c->getCustomerCREDIT())) << ' ' << space_underscore(c->getCustomerPWD()) << endl;
	newcustomer.close();
	ofstream dir("dbcustomer/db_customer.txt", ios::app);
	dir << space_underscore(c->getCustomerID()) << ' ' << space_underscore(c->getCustomerNAME()) << ' ' << space_underscore(c->getCustomerPASSPORT()) << ' ' << space_underscore(c->getCustomerCONTACT()) << ' ' << space_underscore(c->getCustomerEMAIL()) << ' ' << space_underscore(c->getCustomerADDRESS()) << ' ' << space_underscore(c->getCustomerBANKACCT()) << ' ' << space_underscore(c->getCustomerBANK()) << ' ' << space_underscore(toString(c->getCustomerCREDIT())) << ' ' << space_underscore(c->getCustomerPWD()) << endl; dir.close();
	cout << "Welcome Dear customer'" + c->getCustomerNAME() + "' , Remember Your ID: '" + c->getCustomerID() + "', (ID Can no longer change once it is set!)" << endl;
	cout << " Dear '" + c->getCustomerNAME() + "' , You can now start to earn money from posting your idle rooms or houses into Our Felice Home Stay System" << endl;

	cout << " Dear '" + c->getCustomerNAME() + "' Please Note that, by default, your credit is 0 amount, you can top up by using the bank account and can also withdraw money from this system to your bank" << endl;
	cout << "**********************************************************************************************************" << endl;
	cout << endl;
	cout << "Now Start Your Journey! Enjoy!" << endl;

	dir.close();
	system("pause");
	customer_main(c->getCustomerID(), c->getCustomerNAME());
	cout << "Welcome " + c->getCustomerNAME() + "! This is your First Time login! Any doubt, Please contact Staff or Programmer at 0166028563" << endl;


}



void customer::customer_main(string customer_id, string customer_name){
	app a;
	cus.sessionID = customer_id;
	cus.sessionNAME = customer_name;
	system("cls");
	cout << "-----------Welcome Dear Customer: " + customer_name + "-----------" << endl;
	cout << "-----------You can book a room in this system around Penang Area--" << endl;
	system("color 0f");
	cout << "Enter number to specific Menu" << endl;
	cout << "-> 1.Manage Your Prfile Info" << endl;
	cout << "-> 2.Manage Your Account Details" << endl;
	cout << "-> 3.Book a Home to stay!" << endl;//create
	cout << "-> 4.View my booked Home Stay" << endl;//retrieve
	cout << "-> 5.Check Room/House Availability" << endl;//update
	cout << "-> 6.Make a comment for the Home Stay" << endl;//update
	cout << "-> 7.<<Log Out from Customer Panel" << endl;
	//delete no delte function as specified by assignment

	int choice;
	cin >> choice;

	switch (choice){
	case 1:
		cus.manage_profile(customer_id, customer_name);
		break;
	case 2:
		manage_account(customer_id,customer_name);
		break;
	case 3:
		book_stay();
		break;
	case 4:
		view_booking();//view room which have booked by people
		break;
	case 5:
		booking::chkAvailability();//
		system("pause");
		customer_main(cus.sessionID, cus.sessionNAME);
		break;
	case 6:
		comment_home();//
		break;


	case 7:
		a.main();
		//customer_main(sessionID,sessionNAME);
		break;

	default:
		cout << "Pls choose beween interger 1 ~ 6 only" << endl;
	}
}
