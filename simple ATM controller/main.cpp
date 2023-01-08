#include <iostream>
#include "Controller.h"
using namespace std;
enum {
    SeeBalance = 1, Deposit = 2, Withdraw = 3
};
int main() {
    Controller control;
    do {

        string card = "";
        string pin = "";
        string accNum = "";
        int balance =0;
        char mode = '0';
        cout << "Enter Insert Card Event" << endl;
        getline(cin,card);

        if (control.InsertCard(card)) {
            cout << "This Card is validation" << endl;
        }else {
            cout << "wrong Card Inserted" << endl;
            continue;
        }
        cout << "Enter Your Pin Number Event" << endl;
        getline(cin,pin);
        if (control.SetPinNumber(pin)) {
            cout << "Pin Number is correct" << endl;
        }
        else {
            cout << "wrong Pin Number Input" << endl;
            continue;
        }
        auto v = control.seeAccount();
        for (auto itr:v) {
            cout << itr << endl;
        }
        cout << "Enter Account " << endl;
        getline(cin,accNum);
        control.setMAccNum(accNum);
        cout << "Please select 1.See Balance/ 2.Deposit/ 3. Withdraw" << endl;
        cin >> mode;
        int evt = (int)mode - '0';
        switch(evt) {
            case SeeBalance: {
                cout << control.seeBalance(accNum) << endl;
            }
                break;
            case Deposit: {
                cout << "Enter your Deposit" << endl;
                cin >> balance;
                cout << "total amount : " << control.deposit(balance) << endl;
            }
                break;
            case Withdraw: {
                cout << "Enter your Withdraw" << endl;
                cin >> balance;
                cout << "total amount : " << control.withdraw(balance) << endl;
            }
                break;
            default: {
                cout << "Wrong Input" << endl;
            }
                break;
        }


    }while(1);

    return 0;
}
