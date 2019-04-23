//
// Created by QYF on 2019/4/22.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

void printFunc(int x){
    cout << x << " ";
}

//copy()
void test01(){
    vector<int> v1,v2;
    default_random_engine e;
    uniform_int_distribution u(0,100);
    e.seed((unsigned int)time(0));
    for(int i=0;i<10;i++){
        v1.push_back(u(e));
    }
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());
    for_each(v2.begin(),v2.end(),printFunc);
}

//swap()
void test02(){
    vector<int> v1,v2;
    default_random_engine e;
    uniform_int_distribution u(0,100);
    e.seed((unsigned int)time(0));
    for(int i=0;i<10;i++){
        v1.push_back(u(e));
        v2.push_back(u(e));
    }
    cout << "swap()之前: " << endl;
    for_each(v1.begin(),v1.end(),printFunc);
    cout << endl;
    for_each(v2.begin(),v2.end(),printFunc);
    cout << endl;

    swap(v1,v2);
    cout << "swap()之后: " << endl;
    for_each(v1.begin(),v1.end(),printFunc);
    cout << endl;
    for_each(v2.begin(),v2.end(),printFunc);
}

//replace() replace_if()
struct MyCondition{
    bool operator()(int val){
        return val > 7;
    }
};
void test03(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    for_each(v1.begin(),v1.end(),printFunc);
    cout << endl << "replace()之后： " << endl;
    replace(v1.begin(),v1.end(),5,100);
    for_each(v1.begin(),v1.end(),printFunc);
    cout << endl << "replace_if()之后： " << endl;

    //replace_if()
    replace_if(v1.begin(),v1.end(),MyCondition(),200);
    for_each(v1.begin(),v1.end(),printFunc);
    cout << endl << endl;
}
int main(){
    test03();
    return 0;
}