#include <iostream>

int fNum = 6;
int sNum = 7;

int sumOfTwoNum(int fNum, int sNum);
void greaterValue(int fNum, int sNum);
bool twoBoolean(int Num1, int Num2);

int main(){

    std::cout << "The sum of two numbers is: " << sumOfTwoNum(67,67) << std::endl;
    greaterValue(fNum,sNum);
    twoBoolean(true, false);
    twoBoolean(true, 5);
    return 0;
}

int sumOfTwoNum(int fNum, int sNum){
    int sum = fNum + sNum;
    return sum;
}


void greaterValue(int fNum, int sNum){
    if (fNum > sNum){
        std::cout << "The "<< fNum << " is greater than the " << sNum << std::endl;
    } else{
        std::cout << "The "<< sNum <<" is greater than the " << fNum << std::endl;
    }
}

bool twoBoolean(int Num1, int Num2){

    if (Num1 != 0 && Num1 != 1){
        std::cout << "The checking was unsuccessful, please input a valid boolean value.\n";
        return false;
    }
    else if (Num2 != 0 && Num2 != 1){
        std::cout << "The checking was unsuccessful, please input a valid boolean value.\n";
        return false;
    }
        
    std::cout << "\nTrue(1) and False(0)" << std::endl;
    std::cout << "True or False: " << (Num1 && Num2) << std::endl;
    std::cout << "True or False: " << (Num1 || Num2) << std::endl;
    std::cout << "True or False: " << (!Num1) << std::endl;
    std::cout << "True or False: " << (!Num2) << std::endl;


    std::cout << "The checking was successful" << std::endl;

    return true;
}