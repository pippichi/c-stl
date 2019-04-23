//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(12);
    v.push_back(13);
    v.push_back(4);
    v.push_back(7);
    vector<int>::iterator i = find(v.begin(),v.end(),7);
    cout << *i << endl;
}

//find()    find_if()
class Person{
public:
    Person(){}
    bool operator==(const Person& p) const{
        return this->id == p.id && this->age == p.age;
    }
    Person(int age,int id):age(age),id(id){}
public:
    int age;
    int id;
};
bool func(Person p){
    return p.id<3;
}
void test02(){
    vector<Person> v;
    Person p(10,2),p2(20,3),p3(30,4),p4(22,1);
    v.push_back(p);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    vector<Person>::iterator i = find(v.begin(),v.end(),p);
    if(i == v.end()){
        cout << "没找到" << endl;
    }else{
        cout <<  (*i).age << endl;
    }
    i = find_if(v.begin(),v.end(),func);
    if(i == v.end()){
        cout << "没找到" << endl;
    }else{
        cout <<  (*i).id << endl;
    }
}

//binary_search()
void test03(){
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(7);
    v.push_back(7);
    v.push_back(12);
    v.push_back(13);
    bool i1 = binary_search(v.begin(),v.end(),7);
    if(i1){
        cout << "ok" << endl;
    }else {
        cout << "no" << endl;
    }
}

//adjacent_find()     count()     count_if()
bool func01(int val){
    return val > 5;
}
void test04(){
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(7);
    v.push_back(7);
    v.push_back(12);
    v.push_back(13);
    vector<int>::iterator i1 = adjacent_find(v.begin(),v.end());
    if(i1!=v.end()){
        cout << *i1 << endl;
    }else {
        cout << "no" << endl;
    }
    int num = count(v.begin(),v.end(),7);
    cout << num << endl;

    int num2 = count_if(v.begin(),v.end(),func01);
    cout << num2 << endl;
}

int main(){
    test04();
    return 0;
}