//
// Created by QYF on 2019/4/20.
//

#include <iostream>
#include <stack>
using namespace std;

void test01(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(2);
    s.push(19);
    cout<< s.size() << endl;
    cout << s.top() << endl;
    cout<< s.size() << endl;

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << s.size() << " " << endl;
}

int main(){
    test01();
    return 0;
}