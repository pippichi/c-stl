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

    cout << "��β�� "<< q.back()<<endl;

    while(q.size()>0){
        cout << q.front() << endl;
        q.pop();//ɾ����ͷԪ��
    }
}

int main(){
    test01();
    return 0;
}