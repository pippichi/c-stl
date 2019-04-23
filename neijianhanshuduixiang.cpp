//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <functional>
using namespace std;

void test01(){
    plus<int> p;
    cout << p(10,20) << endl;
}

int main(){
    test01();
    return 0;
}