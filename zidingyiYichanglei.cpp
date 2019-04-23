//
// Created by QYF on 2019/4/19.
//

#include <iostream>
#include <cstring>

using namespace std;

class MyException :public exception{
public:
    MyException(char* error){
        this->pError = new char[strlen(error)+1];
        strcpy(this->pError,error);
    }
    MyException(const MyException& mex){
        this->pError = new char[strlen(mex.pError)+1];
        strcpy(this->pError,mex.pError);
    }
    MyException&operator=(const MyException& mex){
        if(this->pError!=NULL){
            delete[] pError;
            this->pError = NULL;
        }
        this->pError = new char[strlen(mex.pError)+1];
        strcpy(this->pError,mex.pError);
    }

    ~MyException(){
        delete[] pError;
    }

    const char *what() const noexcept override {
        return pError;
    }

public:
    char* pError;
};

void fun01() {
    throw MyException("÷ÿ–¥Exception");
}

void test01(){
    try{
        fun01();
    }catch (MyException e){
        cout << e.what() << endl;
    }
}

int main(){
    test01();
    return 0;
}