//
// Created by lee jaehyun on 2023/01/08.
//

#include "Controller.h"

Controller::Controller() : Bank() {

}

Controller::~Controller() {

}

bool Controller::InsertCard(std::string& cardNum) {
    mCardNum = cardNum;
    return isValidCard(mCardNum);
}

bool Controller::SetPinNumber(std::string &pin) {
    mPin = pin;
    return connectBankAccount(mCardNum,mPin);
}

std::vector<std::string> Controller::seeAccount() {
    return getBankAccountList(mCardNum,mPin);
}

int Controller::seeBalance(std::string &accNum) {
    mAccNum = accNum;
    return getBalance(mCardNum,mPin,mAccNum);
}

int Controller::deposit(int &num) {

    return depositBalance(mCardNum,mPin,mAccNum,num);
}

int Controller::withdraw(int &num) {

    return withdrawBalance(mCardNum,mPin,mAccNum,num);
}

void Controller::setMAccNum(const std::string &mAccNum) {
    Controller::mAccNum = mAccNum;
}

