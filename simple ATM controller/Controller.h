//
// Created by lee jaehyun on 2023/01/08.
//

#ifndef SIMPLE_ATM_CONTROLLER_CONTROLLER_H
#define SIMPLE_ATM_CONTROLLER_CONTROLLER_H

#include <string>

#include "Bank.h"

class Controller : public Bank{
public:
    Controller();

    virtual ~Controller();

public:
    bool InsertCard(std::string& cardNum);
    bool SetPinNumber(std::string& pin);
    std::vector<std::string> seeAccount();

    void setMAccNum(const std::string &mAccNum);

    int seeBalance(std::string& accNum);
    int deposit(int& num);
    int withdraw(int& num);

private:
    std::string mCardNum;
    std::string mPin;
    std::string mAccNum;
};


#endif //SIMPLE_ATM_CONTROLLER_CONTROLLER_H
