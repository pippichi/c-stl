//
// Created by QYF on 2019/4/20.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void test01(){
    int arr[]  ={1,2,3,4,3,3,3};
    list<int> l(arr,arr+sizeof(arr)/sizeof(int));
    l.push_back(5);
    l.push_front(0);
    l.remove(3);
    for(list<int>::iterator i=l.begin();i!=l.end();i++){
        cout << *i << endl;
    }
    l.erase(l.begin(),l.end());
    cout << l.size() << endl;
    cout << l.front() << l.back() << endl;
}


//reverse() 元素反转
void test02(){
    int arr[]  ={1,2,3,4,3,3,3};
    list<int> l(arr,arr+sizeof(arr)/sizeof(int));
    l.reverse();
    for(list<int>::iterator i=l.begin();i!=l.end();i++){
        cout << *i << endl;
    }
}

//排序sort()
bool func(int x,int y){
    return x>y;
}
void test03(){
    int arr[]  ={1,2,3,4,3,3,3};
    list<int> l(arr,arr+sizeof(arr)/sizeof(int));
    l.sort();
    for(list<int>::iterator i=l.begin();i!=l.end();i++){
        cout << *i << " ";
    }
    l.sort(func);
    cout << endl;
    for(list<int>::iterator i=l.begin();i!=l.end();i++){
        cout << *i << " ";
    }
}

//查找对象
class Person{
public:
    Person(){}
    Person(int age,string name):age(age),name(name){}
    bool isExist(){
        if(this->age!=0&&!this->name.empty()){
            return true;
        }else{
            return false;
        }
    }
public:
    int age;
    string name;
};
bool find(list<Person> &l,Person& p){
    for(list<Person>::iterator i=l.begin();i!=l.end();i++){
        if(p.age==(*i).age){
            cout << "找到person: " << (*i).age << " " << (*i).name << endl;
            return true;
        }else{
            continue;
        }
    }
    return false;
}
void test04(){
    Person p1(1,"w"),p2(2,"q"),p3(3,"r"),p4(6,"x");
    list<Person> l1;
    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);

    find(l1,p2);
}

int main(){
    test04();
    return 0;
}