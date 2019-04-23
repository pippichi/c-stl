//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct myFunc01{
    int num;
    myFunc01(){
        num = 0;
    }
    void operator()(int val){
        cout << val << endl;
        num++;
    }
};
void test01(){
    myFunc01 m;
    m(10);
    m(20);
    cout << m.num << endl;
}

//传函数，统计函数调用次数
int num = 0;
void myFunc01(int val){
    cout << val << " ";
    num++;
}
void test02(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    for_each(v.begin(),v.end(),myFunc01);
    cout << endl << num << endl;
}

//传函数对象
struct myFunc02{
    int num;
    myFunc02(){
        num = 0;
    }
    void operator()(int val){
        cout << val << endl;
        num++;
    }
};
void test03(){
    myFunc02 m1;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
//    for_each()返回但三个参数的类型
    myFunc02 m2 = for_each(v.begin(),v.end(),m1);
    cout << endl << m2.num << endl;
    cout << endl << m1.num << endl;
}

int main(){
    test03();
    return 0;
}