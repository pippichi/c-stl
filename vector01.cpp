//
// Created by QYF on 2019/4/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using  namespace std;

void func01(int x){
    cout << x << endl;
}

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();
    for_each(begin,end,func01);
}


class Person{
public:
    Person(){}
    Person(int age,int id):age(age),id(id){}
public:
    int age;
    int id;
};
void test02(){
    Person p1(10,11),p2(22,23),p3(3,42);
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for(vector<Person>::iterator i=v.begin();i!=v.end();i++){
        cout << (*i).id << " " << (*i).age << endl;
    }
}


//调用for_each遍历Person
void func02(Person p){
    cout <<  p.age << " " << p.id << endl;
}
void test03(){
    vector<Person> v;
    Person p1(0,12),p2(12,23),p3(31,20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.pop_back();
    v.insert(v.begin(),p3);
    vector<Person>::iterator begin = v.begin();
    vector<Person>::iterator end = v.end();
    for_each(begin,end,func02);
}

//swap()
void func(int &i){
    cout << i <<" ";
}
void test04(){
    int arr[] = {1,12,3,3,4};
    vector<int> v;
    v.assign(arr,arr+sizeof(arr)/sizeof(int));

    vector<int> v2(v.begin(),v.end());
    vector<int> v3;
    int arr2[] = {0b10,012,0x03,30,040};
    v3.assign(arr2,arr2+sizeof(arr2)/sizeof(int));
    for_each(v2.begin(),v2.end(),func);
    cout << endl << "-----------------------------"<<endl;
    for_each(v3.begin(),v3.end(),func);
    cout << endl << "-----------------------------"<<endl;
    v2.swap(v3);
    for_each(v2.begin(),v2.end(),func);
    cout << endl << "-----------------------------"<<endl;
    for_each(v3.begin(),v3.end(),func);
}


//resize()
void test05(){
    int arr[] = {1,12,3,3,4};
    vector<int> v;
    v.assign(arr,arr+sizeof(arr)/sizeof(int));
    cout << v.capacity() << endl;
    cout << endl;
    v.resize(2);
    for_each(v.begin(),v.end(),func);
    cout << v.capacity() << endl;
    cout << endl;
    v.resize(6,3);
    for_each(v.begin(),v.end(),func);
    cout << v.capacity() << endl;
}

//巧用swap收缩空间
void test06(){
    vector<int> v;
    for(int i=0;i<100000;i++){
        v.push_back(i);
    }
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.resize(10);
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    //收缩空间
    vector<int>(v).swap(v);
    cout << v.size() << endl;
    cout << v.capacity() << endl;

}

//reserve预留空间（如果知道容器大概要存储多少元素，则可以预先reserve，这样可以减少容器拷贝的次数，增加效率）
void test07(){
    vector<int> v;
    int num = 0;
    int *address = NULL;
    //预留100000个元素位置
    v.reserve(100000);
    for(int i=0;i<100000;i++){
        v.push_back(i);
        if(address!=&(v[0])){
            address = &(v[0]);
            num++;
        }
    }
    cout << num << endl;
}

int main(){
    test07();
    return 0;
}