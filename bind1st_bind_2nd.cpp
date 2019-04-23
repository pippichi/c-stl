//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Func01:public binary_function<int,int,void>{
    void operator()(int v,int val) const{
        cout << v + val << " ";
    }
};

void test01(){
    vector<int> v;
    Func01 func01;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);
    for_each(v.begin(),v.end(),bind2nd(func01,100));
}

int main(){
    test01();
    return 0;
}