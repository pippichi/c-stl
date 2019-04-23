//
// Created by QYF on 2019/4/19.
//
#include <iostream>
#include <cstring>


using namespace std;

class MyException{
public:
    MyException(char* str){
        error = new char[strlen(str)+1];
        strcpy(error,str);
    }
    //在抛异常的时候由于MyException会被复制构造，这里需要重载等号以及加上复制构造函数
    MyException(const MyException& mx){
        this->error = new char[strlen(mx.error)+1];
        strcpy(this->error,mx.error);
    }
    MyException&operator =(const MyException& mx){
        if(this->error!=NULL){
            delete[] this->error;
            this->error = NULL;
            this->error = new char[strlen(mx.error)+1];
            strcpy(this->error,mx.error);
        }
    }
    void what(){
        cout << error << endl;
    }
    ~MyException(){
        delete[] error;
    }
public:
    char* error;
};
void test01(){
    throw MyException("asd");
}

void test02(){
    try{
        test01();
    }catch (MyException e){
        e.what();
    }
}

int main(){
    test02();
    return 0;
}