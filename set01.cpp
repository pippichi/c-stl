//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

void test01(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    set<int>::iterator i = s.find(3);
    if(i == s.end()){
        cout << "没找到！" <<endl;
    }else{
        cout << *i << endl;
    }

    //lower_bound() 找 >=key的值
    set<int>::iterator i1 = s.lower_bound(3);
    if(i == s.end()){
        cout << "没找到！" <<endl;
    }else{
        cout << *i1 << endl;
    }
    //upper_bound() 找 >key的值
    set<int>::iterator i2 = s.upper_bound(3);
    if(i == s.end()){
        cout << "没找到！" <<endl;
    }else{
        cout << *i2 << endl;
    }

    //equal_range
    pair<set<int>::iterator,set<int>::iterator> p = s.equal_range(3);
    if(p.first == s.end()){
        cout << "没找到" << endl;
    }else{
        cout << *(p.first) << endl;
    }
    if(p.second == s.end()){
        cout << "没找到" << endl;
    }
    else{
        cout << *(p.second) << endl;
    }
}

//防函数（让set倒序）
class Func{
public:
    bool operator()(int x,int y) const{
        return x > y;
    }
};
void test02(){
    set<int,Func> set1;
    set1.insert(2);
    set1.insert(1);
    set1.insert(20);
    set1.insert(3);
    for(set<int,Func>::iterator i=set1.begin();i!=set1.end();i++){
        cout << *i << " ";
    }
    cout << endl;
}



//set的奇葩特性
class Person{
public:
    Person(){}
    Person(int age,string name):age(age),name(name){}
public:
    int age;
    string name;
};
//仿函数
class Func01{
public:
    bool operator()(Person p1,Person p2) const{
        return p1.age<p2.age;
    }
};
void test03(){
    Person p1(1,"ss"),p2(10,"asd"),p3(5,"yy");
    set<Person,Func01> set1;
    set1.insert(p1);
    set1.insert(p2);
    set1.insert(p3);
    for(set<Person,Func01>::iterator i=set1.begin();i!=set1.end();i++){
        cout << (*i).age << " " << (*i).name << endl;
    }

    //查找  p4没有放入set，但是是可以被找到的！
    Person p4(1,"qwe");
    set<Person,Func01>::iterator iterator = set1.find(p4);
    cout << (*iterator).age << " " << (*iterator).name << endl;
}

int main(){
    test03();
    return 0;
}