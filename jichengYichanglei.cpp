//
// Created by QYF on 2019/4/19.
//
#include <iostream>
#include <cstring>
using namespace std;

class BaseException{
public:
    virtual void what() = 0;
    virtual ~BaseException(){}
};

class SourceNotfoundException:public BaseException{
public:
    void what() override {
        cout << "source not found!" << endl;
    }
    ~SourceNotfoundException(){}
};

class TargetNotfoundException:public BaseException{
public:
    void what() override {
        cout << "target not found!" << endl;
    }
    ~TargetNotfoundException(){}
};

void copyStr(char* source,char* target){
    if(source == NULL){
        throw SourceNotfoundException();
    }
    if(target == NULL){
        throw TargetNotfoundException();
    }

    while(*source!='\0'){
        *target = *source;
        target++;
        source++;
    }
}

int main(){
    char source[20] = {'a','v','b','s'};
    char buf[1024];
    try {
        copyStr(source, buf);
    }catch (BaseException& e){
        e.what();
    }
    cout << buf << endl;
}