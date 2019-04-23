//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Person{
public:
    Person(){}
    Person(char* name,int id){
        this->name = new char(strlen(name)+1);
        strcpy(this->name,name);
        this->id = id;
    }
    Person(const Person& p){
        this->name = new char(strlen(p.name)+1);
        strcpy(this->name,p.name);
        this->id = p.id;
    }
    Person& operator=(const Person& p){
        if(this->name!=NULL){
            delete[] this->name;
            this->name = NULL;
        }
        this->name = new char(strlen(p.name)+1);
        strcpy(this->name,p.name);
        this->id = p.id;
        return *this;
    }
    ~Person(){
        delete[] name;
    }
public:
    char* name; //指针 容易引发浅拷贝问题（将对象放入容器时会发生拷贝复制，由于两个对象指向同一个char*，因此不能进行两次析构）
    int id;
};

void test01(){
    Person p("aaa",1);
    vector<Person> v;
    v.push_back(p);
}

int main(){
    test01();
    return 0;
}