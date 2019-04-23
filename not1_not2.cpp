//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//二元谓词取反用 not2
class Func:public binary_function<int,int,bool>{
public:
    bool operator()(int x,int y) const{
        return x < y;
    }
};
void func(int x){
    cout << x << " ";
}
void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);
    sort(v.begin(),v.end(),not2(Func()));
    for_each(v.begin(),v.end(),func);
}

//一元谓词取反用not1
struct Func02:public unary_function<int,bool>{
    bool operator()(int val) const{
        return val < 5;
    }
};
void test02(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);

    vector<int>::iterator i = find_if(v.begin(),v.end(),not1(Func02()));
    if(i == v.end()){
        cout << "没找到" << endl;
    }else{
        cout << *i << endl;
    }
}

int main(){
    test01();
    return 0;
}