//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//transform将一个容器的元素搬运到另一个容器中
struct Func{
    int operator()(int val){
        return val + 100;
    }
};
void printVector(int val){
    cout << val << endl;
}

void test01(){
    vector<int> v;
    vector<int> v2;

    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    v2.resize(v.size()); //必须先开辟空间

    transform(v.begin(),v.end(),v2.begin(),Func());
    for_each(v2.begin(),v2.end(),printVector);
}

int main(){
    test01();
    return 0;
}