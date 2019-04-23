//
// Created by QYF on 2019/4/20.
//

#include <iostream>
#include <queue>

using namespace std;

void test01(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "队尾： "<< q.back()<<endl;

    while(q.size()>0){
        cout << q.front() << endl;
        q.pop();//删除对头元素
    }
}

int main(){
    test01();
    return 0;
}