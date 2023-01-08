//
// Created by lee jaehyun on 2023/01/08.
//

#include "Bank.h"

Bank::Bank() {

    mAccount.push_back(account("1111 1111 1111 1111","1111"
                               ,{{"4354-1234-123",150}
                               ,{"4354-1234-321",10}
                               ,{"4354-4321-321",20}}));
    mAccount.push_back(account("2222 2222 2222 2222","2222"
            ,{{"4234-3443-534",333}
                                       ,{"4532-1234-321",10}
                                       ,{"5871-4342-321",20}}));
}

Bank::~Bank() {

}

bool Bank::isValidCard(std::string &cardNum) {
    bool ret = false;
    for (auto itr : mAccount) {
        if (itr.cardNum.compare(cardNum) == 0)
            ret = true;
    }
    return ret;
}


bool Bank::connectBankAccount(std::string &cardNum, std::string &pin) {
    for (auto itr :mAccount) {
        if(itr.cardNum.compare(cardNum) == 0 && itr.pin.compare(pin) == 0)
            return true;
    }
    return false;
}

std::vector<std::string> Bank::getBankAccountList(std::string &cardNum, std::string &pin) {
    std::vector<std::string> v;
    for (auto itr :mAccount) {

        if(itr.cardNum.compare(cardNum) == 0 && itr.pin.compare(pin) == 0) {
            for (auto it:itr.balance) {
                v.push_back(it.first);
            }
        }

    }

    return v;
}

int Bank::getBalance(std::string &cardNum, std::string &pin , std::string& accNum) {
    int balance = 0;
    for (auto itr :mAccount) {
        if(itr.cardNum.compare(cardNum) == 0 && itr.pin.compare(pin) == 0) {
            balance = itr.balance[accNum];
        }
    }
    return balance;
}

int Bank::withdrawBalance(std::string &cardNum, std::string &pin, std::string &accNum, int &balance) {
    int remain = 0;
    for (auto itr :mAccount) {
        if(itr.cardNum.compare(cardNum) == 0 && itr.pin.compare(pin) == 0) {
//            itr.balance[accNum] += balance;
//            remain = itr.balance[accNum];
                if(balance > itr.balance[accNum]) {
                    remain = -1;
                }else {
                    itr.balance[accNum] -= balance;
                    remain = itr.balance[accNum];
                }
        }
    }
    return remain;
}

int Bank::depositBalance(std::string &cardNum, std::string &pin, std::string &accNum, int &balance) {
    int remain = 0;
    for (auto itr :mAccount) {
        if(itr.cardNum.compare(cardNum) == 0 && itr.pin.compare(pin) == 0) {
            itr.balance[accNum] += balance;
            remain = itr.balance[accNum];
        }
    }
    return remain;
}




Bank::account::account(const std::string &cardNum, const std::string &pin, const std::map<std::string, int> &balance)
        : cardNum(cardNum), pin(pin), balance(balance) {}
