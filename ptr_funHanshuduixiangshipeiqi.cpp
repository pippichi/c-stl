//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ptr_fun()
void func01(int x,int val){
    cout << x << " ";
    cout << "val: " << val << endl;
}
void test01(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(10);
    v.push_back(9);
    //把普通函数转成函数对象
    for_each(v.begin(),v.end(),bind2nd(ptr_fun(func01),100));
}

//mem_fun_ref()
class Person{
public:
    Person(){}
    Person(int age,int id):id(id),age(age){}
    void show(){
        cout << this-> age << " " << this->id << endl;
    }
public:
    int age;
    int id;
};
void test02(){
    Person p1(10,11),p2(20,22),p3(30,33),p4(40,44);
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    for_each(v.begin(),v.end(),mem_fun_ref(&Person::show));
}

//mem_fun()
void test03(){
    Person p1(10,11),p2(20,22),p3(30,33),p4(40,44);
    vector<Person*> v;
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    for_each(v.begin(),v.end(),mem_fun(&Person::show));
}

int main(){
    test03();
    return 0;
}