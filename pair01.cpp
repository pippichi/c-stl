//
// Created by QYF on 2019/4/20.
//

#include <iostream>
#include <string>

using namespace std;


void test01(){
    pair<string,int> p1("qyf",12);
    cout << p1.first << " " << p1.second << endl;
    pair<string,int> p2 = make_pair("ing",13);
    cout << p2.first << " " << p2.second << endl;
    pair<string,int> p3 = p2;
    cout << p3.first << " " << p3.second << endl;
}

typedef void(*FUNC)(void);

int main(){
    FUNC f;
    f = test01;
    f();
    return 0;

}
