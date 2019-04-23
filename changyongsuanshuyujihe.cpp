//
// Created by QYF on 2019/4/22.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

void printFunc(int x){
    cout << x << " ";
}

//accumulate()
void test01(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    int result = accumulate(v1.begin(),v1.end(),0);
    cout << result << endl;
    int result2 = accumulate(v1.begin(),v1.end(),10);
    cout << result2 << endl;
}

//fill()
void test02(){
    vector<int> v;
    v.resize(10);
    fill(v.begin(),v.end(),10);
    for_each(v.begin(),v.end(),printFunc);
}

//set_intersection()
void test03(){
    vector<int> v1,v2,v3;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    v3.resize(min(v1.size(),v2.size()));
    vector<int>::iterator i = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),i,printFunc);
}

//set_union()
void test04(){
    vector<int> v1,v2,v3;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    v3.resize(max(v1.size(),v2.size()));
    vector<int>::iterator i = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),i,printFunc);
}
//set_difference()
void test05(){
    vector<int> v1,v2,v3;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    v3.resize(v1.size());
    vector<int>::iterator i = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),i,printFunc);
}

int main(){
    test05();
    return 0;
}