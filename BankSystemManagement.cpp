#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class BankAccount
{
    char Name[50]; // variable for account's holder name.
	int Account_Number; // variable for account number.
    char Account_Type; // variable for bank type.
	int Amount; // variable for bank balance.
public:
//FUNCTION DEFINITION CLASS MEMBERS

	void createBankAccount(); //for creating a bank account.
	void showBankAccount() const; //for showing the bank details.
	void balanceInquiry() const; //for showing bank balance.
	void modifyBankDetails(); // for modifying bank details
	void deposite_money(int); // for money deposition.
	void withdraw_money(int); // for withdrawing money.
	void bankReport() const; // for showing the details of all the users registered in this bank.
	int returnAccount_Number() const; // for returning Account Number.
	int returnAmount() const; // for returning Bank Balance.
	char retAccount_Type() const; // for returning Account Type
};
//FUNCTIONS DECLARATION OF CLASS MEMBERS

void BankAccount::createBankAccount() //for creating a bank account.
{
	system("CLS");
	cout<<"\n\tEnter 6 Digits Bank Account Number : ";
	cin>>Account_Number;
	cout<<"\n\tEnter Bank Account Holder Name : ";
	cin.ignore();
	cin.getline(Name,50);
	cout<<"\n\tEnter Type Of The Bank Account (C/S) : ";
	cin>>Account_Type;
	Account_Type=toupper(Account_Type);
	cout<<"\n\tEnter First Amount To Be Deposited : ";
	cin>>Amount;
	cout<<"\n\n\tBank Account Created Successfully ";
}

void BankAccount::showBankAccount() const //for showing the bank details.
{
	cout<<"\n\tBank Account Number : "<<Account_Number;
	cout<<"\n\tHolder's Name : ";
	cout<<Name;
	cout<<"\n\tBank Account Type : "<<Account_Type;
	cout<<"\n\tBank Balance : Rs."<<Amount;
}

void BankAccount::balanceInquiry() const //for showing bank balance.
{
	cout<<"\n\tHey "<<Name<<" Your Bank Balance Is : "<<"Rs."<<Amount;
}


void BankAccount::modifyBankDetails() // for modifying bank details
{
	cout<<"\n\tBank Account Number : "<<Account_Number;
	cout<<"\n\tModify Holder's Name : ";
	cin.ignore();
	cin.getline(Name,50);
	cout<<"\n\tModify Type of BankAccount (C/S): ";
	cin>>Account_Type;
	Account_Type=toupper(Account_Type);

}


void BankAccount::deposite_money(int x) // for money deposition.
{
	Amount+=x;
}

void BankAccount::withdraw_money(int x) // for withdrawing money.
{
	Amount-=x;
}

void BankAccount::bankReport() const // for showing the details of all the users registered in this bank.
{
	cout<<"\n\t"<<setw(15)<<left<<Account_Number;
	cout<<setw(22)<<left<<Name;
	cout<<setw(12)<<left<<Account_Type;
	cout<<"Rs."<<Amount<<endl;
}

int BankAccount::returnAccount_Number() const // for returning Account Number
{
	return Account_Number;
}

int BankAccount::returnAmount() const // for returning Bank Balance.
{
	return Amount;
}

char BankAccount::retAccount_Type() const // for returning Account Type
{
	return Account_Type;
}

//FUNCTION DEFINITION OF FUNCTIONS WHICH WILL EXCHANGE DATA WITH THE FILE STORED IN OUR SYSTEM
void write_BankAccount(); // for writing bank details in DAT file.
void display_sp(int); // for balance inquiry from DAT file
void modify_BankAccount(int); // for modifying bank details in DAT file.
void delete_BankAccount(int); // for deleting bank details in DAT file.
void display_all(); // for displaying all bank details from DAT file.
void deposit_withdraw(int, int); // for editing withdraw or deposit from DAT file.
void display_bankReport(int); // for displaying bank detail of a specific person.
void bank_validate(int); // for validating bank account number from our DAT file whether is exists in our bank or not.

int main()
{
	char ch;
	do{ // Main Menu for selection of mode type.
        system("CLS");
        cout<<"\n\tBANK SYSTEM MANAGEMENT";
        cout<<"\n\t______________________\n";
		cout<<"\n\t Select the Type\n";
		cout<<"\n\t 1. Admin";
		cout<<"\n\t 2. Customer";
		cout<<"\n\t 3. Exit";
		cout<<"\n\n\t Select Your Choice (1-2): ";
		cin>>ch;
		switch(ch)
		{

		case '1': // case 1 if we select Admin type.
			int Num;
            do // Main Menu for Admin side.
            {
                system("CLS");
                cout<<"\n\tBANK SYSTEM MANAGEMENT";
                cout<<"\n\t______________________\n";
                cout<<"\n\t MAIN MENU\n";
                cout<<"\n\t 1. Open A Bank Account";
                cout<<"\n\t 2. Deposit Money";
                cout<<"\n\t 3. Balance Inquiry";
                cout<<"\n\t 4. Record Of All Bank Account Holders";
                cout<<"\n\t 5. Modify A Bank Account";
                cout<<"\n\t 6. Close A Bank Account";
                cout<<"\n\t 7. Check Account Report";
                cout<<"\n\t 8. Account Validation";
                cout<<"\n\t 9. Exit";
                cout<<"\n\n\tSelect An Option (1-9): ";
                cin>>ch;
                switch(ch)
                {
                case '1': // case 1 for opening a bank account.
                    write_BankAccount();
                    break;
                case '2': // case 2 for money deposition.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account Number : "; cin>>Num;
                    deposit_withdraw(Num, 1);
                    break;
                case '3': // case 3 for balance inquiry.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>Num;
                    display_sp(Num);
                    break;
                case '4': // case 4 for displaying all users.
                    display_all();
                    break;
                case '5': // case 5 for modifying a bank account.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>Num;
                    modify_BankAccount(Num);
                    break;
                case '6': // case 6 for closing a bank account.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>Num;
                    delete_BankAccount(Num);
                    break;
                case '7': // case 7 for specific user's account report.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>Num;
                    display_bankReport(Num);
                    break;
                case '8': // case 8 for account validation.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>Num;
                    bank_validate(Num);
                    break;
                case '9': // case 9 for exit
                    system("CLS");
                    cout<<"\n\tThank You For Using Bank System Management";
                    break;

                default :cout<<"\a";
                }
                cin.ignore();
                cin.get();
            }while(ch!='9');
			break;


		case '2': // case 2 if we select Customer type.
			int num;
            do // Main Menu for Customer side.
            {
                system("CLS");
                cout<<"\n\tBANK SYSTEM MANAGEMENT";
                cout<<"\n\t______________________\n";
                cout<<"\n\t MAIN MENU\n";
                cout<<"\n\t 1. Balance Inquiry";
                cout<<"\n\t 2. Deposit Money";
                cout<<"\n\t 3. Withdraw Money";
                cout<<"\n\t 4. Account Summary";
                cout<<"\n\t 5. EXIT";
                cout<<"\n\n\tSelect Your Option (1-5): ";
                cin>>ch;

                switch(ch)
                {
                case '1': // case 1 for balance inquiry.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>num;
                    display_sp(num);
                    break;
                case '2': // case 2 for money deposition.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>num;
                    deposit_withdraw(num, 1);
                    break;
                case '3': // case 2 for withdrawing money.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>num;
                    deposit_withdraw(num, 2);
                    break;
                case '4': // case 4 for account summary.
                    system("CLS");
                    cout<<"\n\n\tEnter Bank Account No. : "; cin>>num;
                    display_bankReport(num);
                    break;
                case '5': // case 5 for exit.
                    system("CLS");
                    cout<<"\n\tThank You For Using Bank System Management";
                    break;
                default :cout<<"\a";
                }
                cin.ignore();
                cin.get();
            }while(ch!='5');
			break;

        case '3' : // case 3 if we select Exit.
            cout<<"\n\tBank System Management Closed, Thanks";
            break;
        default :cout<<"\a";
		}
    }while(ch!='3');
    return 0;

}


//FUNCTION DECLARATION OF FUNCTIONS WHICH WILL EXCHANGE DATA WITH THE FILE STORED IN OUR SYSTEM

void write_BankAccount()  // for writing bank details in DAT file.
{
	BankAccount ac;
	ofstream outFile;
	outFile.open("BankAccount.dat",ios::binary|ios::app);
	ac.createBankAccount();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
	outFile.close();
}

void display_sp(int acc_no) // for balance inquiry from DAT file
{
	BankAccount ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\tNo Bank Account Holders ";
		return;
	}
	cout<<"\n\tBalance Details : \n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		if(ac.returnAccount_Number()==acc_no)
		{
			ac.balanceInquiry();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tSorry, Account Number "<<acc_no<<" Not Found ";
}
void bank_validate(int acc_no) // for validating bank account number from our DAT file whether is exists in our bank or not.
{
	BankAccount ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\tNo Bank Account Holders ";
		return;
	}
	 	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		if(ac.returnAccount_Number()==acc_no)
		{
			cout<<"\n\tYes Account Number "<<acc_no<<" Exists In Our System";
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\tAccount Number "<<acc_no<<" Is Not Registered In Our System ";
}
void display_bankReport(int acc_no) // for displaying bank detail of a specific person.
{
	BankAccount ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\tNo Bank Account Holders ";
		return;
	}
	cout<<"\n\tAccount Details : \n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		if(ac.returnAccount_Number()==acc_no)
		{
			ac.showBankAccount();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tSorry, Account Number "<<acc_no<<" Not Found ";
}

void modify_BankAccount(int acc_no) // for modifying bank details in DAT file.
{
	bool found=false;
	BankAccount ac;
	fstream File;
    File.open("BankAccount.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\tNo Bank Account Holders ";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		if(ac.returnAccount_Number()==acc_no)
		{
			ac.showBankAccount();
			cout<<"\n\n\tEnter New Details "<<endl;
			ac.modifyBankDetails();
			int pos=(-1)*static_cast<int>(sizeof(BankAccount));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		    cout<<"\n\n\tAccount Number "<<acc_no<<" Modified Successfully";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\tSorry, Account Number "<<acc_no<<" Not Found ";
}

void delete_BankAccount(int acc_no) // for deleting bank details in DAT file.
{
	BankAccount ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\tNo Bank Account Holders ";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		if(ac.returnAccount_Number()!=acc_no)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		}
	}
    inFile.close();
	outFile.close();
	remove("BankAccount.dat");
	rename("Temp.dat","BankAccount.dat");
	cout<<"\n\n\tAccount Number "<<acc_no<<" Deleted Successfully. ";
}

void display_all() // for displaying all bank details from DAT file.
{
	system("CLS");
	BankAccount ac;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\tNo Bank Account Holders ";
		return;
	}
	cout<<"\n\n\tBank Account Users List:\n\n";
	cout<<"\tAccount No.      Name           Account Type   Bank Balance\n";
	cout<<"\t-----------------------------------------------------------\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		ac.bankReport();
	}
	inFile.close();
}


void deposit_withdraw(int acc_no, int option) // for editing withdraw or deposit from DAT file.
{
	int amt;
	bool found=false;
	BankAccount ac;
	fstream File;
    File.open("BankAccount.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\tNo Bank Account Holders ";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		if(ac.returnAccount_Number()==acc_no)
		{
			ac.showBankAccount();
			if(option==1)
			{
				cout<<"\n\n\tEnter The Amount You Want To Deposit ";
				cin>>amt;
				ac.deposite_money(amt);
				cout<<"\n\n\tRs."<<amt<<" Deposited Successfully ";
			}
		    if(option==2)
			{
				cout<<"\n\n\tEnter The Amount You Want To Withdraw ";
				cin>>amt;
				int bal=ac.returnAmount()-amt;
				if(bal<0)
					cout<<"\n\tInsufficient balance, Can't Withdraw ";
				else{
                    ac.withdraw_money(amt);
                    cout<<"\n\tSuccessfully Withdrawn Rs."<<amt<<" ";
				}

		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\tSorry, Account Number "<<acc_no<<" Not Found ";
}

