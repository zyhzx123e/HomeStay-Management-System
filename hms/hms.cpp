// hms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "booking.h"
#include "client.h"
#include "staff.h"
#include "customer.h"
#include "home.h"
#include "user.h"


void client_ui();
void customer_ui();
void home_ui();
void staff_ui();
int main();

int app::main(){

	system("cls");
	cout << "-----------Felice Homestay Management System(HMS)-----------" << endl;
	cout << "------------------------------------------------------------" << endl;
	system("color 0f");
	cout << "Please enter your choice" << endl;
	cout << "1.I am owner, I owns units and houses/apartments to rent" << endl;
	cout << "2.I am customer, I am finding room/houses/apartments to rent" << endl;
	cout << "3.View all available homestays" << endl;
	cout << "4.Exit" << endl;


	int choice;
	cin >> choice;

	switch (choice){
	case 1:
		client_ui();
		break;
	case 2:
		customer_ui();
		break;
	case 3:
		home_ui();
		break;
	case 4:
		exit(0);
		break;
	case 8:
		staff_ui();//secret key -> 8 for staff
		break;
	}

	system("pause");
	main();
	return 0;
}

void app::client_ui(){
	
	system("cls");
	cout << "-----------HMS Owner Panel-----------" << endl;
	cout << "-------------------------------------" << endl;
	system("color 0f");


string selection;
	string client_id; string client_pwd;string client_name;string client_passport;
	string client_contact;string client_email;string client_address;string client_bank_account;
	string client_bank;double client_credit;
Sleep(1500);
	cout << "Dont have an Client account? You can register now!! then you can earn money from renting your idle rooms and houses at this platform! " << endl;
	cout << "You will know how amazing it is when you try it!" << endl;
	cout << "Key in [1] for Register =>>" << endl;
	cout << "Key in [2] for Login =>>" << endl;
	cin >> selection;
	if (selection=="1"){
	client::register_client();
	}
	else{ goto login; }
login:
	ifstream readIn("dbclient/db_client.txt");

	
	client c[100];
	int i = 0;

	cout << "Please Enter Your Client ID" << endl;
	string enteredID;
	cin >> enteredID;

	

	bool found = false;

	while (readIn >> client_id >> client_name >> client_passport >> client_contact >> client_email >> client_address >> client_bank_account >> client_bank >> client_credit >> client_pwd){
		c[i].setClientID(client_id);
		c[i].setClientNAME(client_name);
		c[i].setClientPASSPORT(client_passport);
		c[i].setClientCONTACT(client_contact);
		c[i].setClientEMAIL(client_email);
		c[i].setClientADDRESS(client_address);
		c[i].setClientBANKACCT(client_bank_account);
		c[i].setClientBANK(client_bank);
		c[i].setClientCREDIT(client_credit);
		c[i].setClientPWD(client_pwd);



		if (c[i].getClientID() == enteredID){
			found = true;

			break;
		}
		else{
			continue;
		}

		i++;
	}


	if (found == false){

		cout << "sorry, client[owner] id does not exist!  try again? typo?" << endl;

	}
	else {

		cout << "Hi " + c[i].getClientNAME() + " Please Enter Your Client Password" << endl;
		string enteredPWD;
		cin >> enteredPWD;

		if (enteredPWD == c[i].getClientPWD()){

			readIn.close();
			c[i].client_main(c[i].getClientID(), c[i].getClientNAME());
		}
		else{
			cout << "sorry, Access denied! Client password is not correct!" << endl;


		}

	}



	readIn.close();

	system("pause");
	main();
}
void app::customer_ui(){


	system("cls");
	cout << "-----------HMS Customer Panel-----------" << endl;
	cout << "-------------------------------------" << endl;
	system("color 0f");



	string customer_id; string customer_pwd; string customer_name; string customer_passport;
	string customer_contact; string customer_email; string customer_address; string customer_bank_account;
	string customer_bank; double customer_credit;
string selection;
	Sleep(1500);
	cout << "Dont have an Customer account? You can register now!! then you can Rent other's idle rooms or houses at cheap price! " << endl;
	cout << "You will know how amazing it is when you try it!" << endl;
	cout << "Key in [1] for Register =>>" << endl;
	cout << "Key in [2] for Login =>>" << endl;
	cin >> selection;
	if (selection == "1"){
		customer::register_customer();
	}
	else{ goto login; }
login:
	ifstream readIn("dbcustomer/db_customer.txt");

	customer c[100];
	int i = 0;
	
	cout << "Please Enter Your customer ID" << endl;
	string enteredID;
	cin >> enteredID;

	

	bool found = false;

	while (readIn >> customer_id >> customer_name >> customer_passport >> customer_contact >> customer_email >> customer_address >> customer_bank_account >> customer_bank >> customer_credit >> customer_pwd){
		c[i].setCustomerID(customer_id);
		c[i].setCustomerNAME(customer_name);
		c[i].setCustomerPASSPORT(customer_passport);
		c[i].setCustomerCONTACT(customer_contact);
		c[i].setCustomerEMAIL(customer_email);
		c[i].setCustomerADDRESS(customer_address);
		c[i].setCustomerBANKACCT(customer_bank_account);
		c[i].setCustomerBANK(customer_bank);
		c[i].setCustomerCREDIT(customer_credit);
		c[i].setCustomerPWD(customer_pwd);



		if (c[i].getCustomerID() == enteredID){
			found = true;

			break;
		}
		else{
			continue;
		}

		i++;
	}


	if (found == false){

		cout << "sorry, customer id does not exist!  try again? typo?" << endl;

	}
	else {

		cout << "Hi " + c[i].getCustomerNAME() + " Please Enter Your customer Password" << endl;
		string enteredPWD;
		cin >> enteredPWD;

		if (enteredPWD == c[i].getCustomerPWD()){

			readIn.close();
			c[i].customer_main(c[i].getCustomerID(), c[i].getCustomerNAME());
		}
		else{
			cout << "sorry, Access denied! customer password is not correct!" << endl;


		}

	}



	readIn.close();

	system("pause");
	main();
}
void app::home_ui(){
	user *u = new staff;
	u->view_home();//cannot create obj of abstract class, but can refence it by make it as pointer


}
void app::staff_ui(){

	system("cls");
	cout << "-----------HMS Staff Control Panel-----------" << endl;
	cout << "---------------------------------------------" << endl;
	system("color 0a");

	

	string id;
	string pwd;
	string name;

	
	/*string l = "";
	int number_of_lines = 0;
	ifstream readLine("dbstaff/db_staff.txt");
	if (readLine.is_open()){
		while (!readLine.eof()){
			getline(readLine, l);
		
			cout << l << endl;
			number_of_lines++;
		}
		// myfile.close();
	}readLine.close();
	cout << number_of_lines << endl;
	*/
	

	ifstream readIn("dbstaff/db_staff.txt");
	int i = 0;
	staff s[100];
	
	cout << "Please Enter Your Staff ID" << endl;
	string enteredID;
	cin >> enteredID;

	bool found = false;
	
			while (readIn >> id >> pwd >> name){

				s[i].setStaffID(id);
				s[i].setStaffPWD(pwd);
				s[i].setStaffNAME(name);
				if (s[i].getStaffID()==enteredID){
					found = true;

					break;
				}
				else{
					continue;
				}

				i++;
			}
	

	if(found==false){
	
		cout << "sorry, staff id does not exist!" << endl;
	
	}else {
	
		cout << "Hi "+s[i].getStaffNAME()+" Please Enter Your Staff Password" << endl;
		string enteredPWD;
		cin >> enteredPWD;

		if (enteredPWD == s[i].getStaffPWD()){
		
			readIn.close();
			s[i].staff_main(s[i].getStaffID(),s[i].getStaffNAME());
		}
		else{
			cout << "sorry, staff password is not correct!" << endl;

		
		}
	
	}
	readIn.close();




	system("pause");
	main();
}
int _tmain(int argc, _TCHAR* argv[])
{
	app a;
	a.main();
	system("pause");
	return 0;
}