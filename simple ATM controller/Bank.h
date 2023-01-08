//
// Created by lee jaehyun on 2023/01/08.
//

#ifndef SIMPLE_ATM_CONTROLLER_BANK_H
#define SIMPLE_ATM_CONTROLLER_BANK_H


#include <string>
#include <vector>
#include <map>

class Bank {
public:
    Bank();

    virtual ~Bank();
private:
    struct account {
        account(const std::string &cardNum, const std::string &pin, const std::map<std::string, int> &balance);

        std::string cardNum;
        std::string pin;
        std::map<std::string,int> balance;
    };
protected:
    bool isValidCard(std::string& cardNum);
    bool connectBankAccount(std::string& cardNum,std::string& pin);
    std::vector<std::string> getBankAccountList(std::string& cardNum,std::string& pin);
    int getBalance(std::string& cardNum,std::string& pin , std::string& accNum);
    int depositBalance(std::string& cardNum,std::string& pin , std::string& accNum , int& balance);
    int withdrawBalance(std::string& cardNum,std::string& pin , std::string& accNum , int& balance);

private:
    std::vector<account> mAccount;
};


#endif //SIMPLE_ATM_CONTROLLER_BANK_H
