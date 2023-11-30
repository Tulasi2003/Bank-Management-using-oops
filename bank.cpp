#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
    
    private:
        string name;
        int accNum;
        double balance;
    
    public:
        BankAccount(string n,int ac,double bal){
            name = n;
            accNum = ac;
            balance = bal;
        }
        string getName(){
            return name;
        }
        int getAccNum(){
            return accNum;
        }
        double getBalance(){
            return balance;
        }
        
        void deposit(double amount);
        void withdraw(double amount);
};

class BankManagement{
    private:
        vector<BankAccount>accounts;
    public:
        void AddAccount(string name,int accNum,double balance);
        void showAccounts();
        void searchAccount(int account);
        BankAccount* findAccount(int accNum);
};

void BankAccount :: deposit(double amount){
    balance = balance + amount;
    cout << "\t\t------------------------------" << endl;
    cout << "\t\tDeposit Successful..." << endl;
    cout << "\t\t------------------------------" << endl;
    cout << "\t\tBalance in account: " << balance << endl;
}

void BankAccount :: withdraw(double amount){
    if(balance >= amount){
        balance -= amount;
        cout << "\t\t-----------------------" << endl;
        cout << "\t\t Withdraw Successful..." << endl;
        cout << "\t\t-----------------------" << endl;
        cout << "\t\tBalance left in account: " << balance << endl;
    }
    else {
        cout << "\t\t-----------------------" << endl;
        cout << "\t\t Insufficient Balance..." << endl;
        cout << "\t\t-----------------------" << endl;
    }
}

void BankManagement :: AddAccount(string name,int accNum,double balance){
    accounts.push_back(BankAccount(name,accNum,balance));
}

void BankManagement :: showAccounts(){
    cout << "\t\t List of Account Holders" << endl;
    cout << "\t\t ----------------------" << endl;
    for(int i=0; i<accounts.size(); i++){
        cout << "\t\t " << i+1 << ". " << accounts[i].getName() << endl;
    }
    cout << "\t\t ----------------------" << endl;
}

void BankManagement :: searchAccount(int account){
    int flag = 0;
    
    for(int i=0; i<accounts.size(); i++){
        if(accounts[i].getAccNum() == account){
            flag = 1;
            cout << "\t\t-----------------------------" << endl;
            cout << "\t\tAccount Found Successfully..." << endl;
            cout << "\t\t-----------------------------" << endl;
            cout << "\t\tAccount Holder Details" << endl;
            cout << "\t\tName: " << accounts[i].getName() << endl;
            cout << "\t\tAccount Number: " << accounts[i].getAccNum() << endl;
            cout << "\t\tBalance: " << accounts[i].getBalance() << endl;
        }
    }
    if(flag == 0)
    {
        cout << "\t\t-----------------------------" << endl;
        cout << "\t\tAccount Not Found..." << endl;
        cout << "\t\t-----------------------------" << endl;
    }
}

BankAccount* BankManagement :: findAccount(int accNum){
    for(int i=0; i<accounts.size(); i++){
        if(accounts[i].getAccNum() == accNum){
            return &accounts[i];
        }
    }
    return NULL;
}

int main()
{
    BankManagement bank;
    int choice;
    char option;
    
    do{
        system("cls");
        cout << endl;
        cout << " \t\t     Bank Management System      " << endl;
        cout << "\t\t----------------------------------" << endl;
        cout << " \t\t\t1.Create Account" << endl;
        cout << " \t\t\t2.List of Account Holders" << endl;
        cout << " \t\t\t3.Account Details" << endl; 
        cout << " \t\t\t4.Deposit Amount" << endl;
        cout << " \t\t\t5.Withdraw Amount" << endl;
        cout << " \t\t\t6.Exit" << endl;
        cout << "\t\t----------------------------------" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            
            case 1:{
                string name;
                int accNum;
                double balance;
                cout << " \t\t Enter Account Holder Name: ";
                cin >> name;
                cout << " \t\t Account Number: ";
                cin >> accNum;
                cout << " \t\t Enter Initial Amount: ";
                cin >> balance;
                if(balance < 100){
                    cout<<"\t\t Invalid - Please enter minimum of 100 rupees: ";
                    cin >> balance;
                }
                bank.AddAccount(name,accNum,balance);
                cout << "\t\t------------------------------" << endl;
                cout << "\t\tAccount Created Successfully..." << endl;
                cout << "\t\t------------------------------" << endl;
                break;
            }
            
            case 2 :{
                bank.showAccounts();
                break;
            }
            
            case 3:{
                int accNum;
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.searchAccount(accNum);
                break;
            }
            
            case 4:{
                int accNum;
                double amount;
                cout << "\t\tEnter Account Number to Deposit Money: ";
                cin >> accNum;
                BankAccount* account = bank.findAccount(accNum);
                if(account != NULL){
                    cout << "\t\tEnter Amount to deposit:";
                    cin >> amount;
                    account->deposit(amount);
                    
                }
                else{
                    cout << "\t\t------------------------------" << endl;
                    cout << "\t\tAccount Not Found..." << endl;
                    cout << "\t\t------------------------------" << endl;
                }
                break;
            }
            
            case 5:{
                int accNum;
                double amount;
                cout << "\t\tEnter Account Number to Withdraw Money: ";
                cin >> accNum;
                BankAccount* account = bank.findAccount(accNum);
                if(account != NULL){
                    cout << "\t\tEnter the Amount to withdraw: ";
                    cin >> amount;
                    account -> withdraw(amount);
                }
                else{
                    cout << "\t\t------------------------------" << endl;
                    cout << "\t\tAccount not Found..." << endl;
                    cout << "\t\t------------------------------" << endl;
                }
                break;
            }
            
            case 6:{
                exit(1);
                break;
            }
        }
        cout << "Do You Want to Continue or Exit[Y/N]: ";
        cin>>option;
        
    }while(option == 'y'|| option == 'Y');
    return 0;
}
