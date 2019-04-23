//
// Created by QYF on 2019/4/22.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

void printFunc(int x){
    cout << x << " ";
}
class MyCompare{
public:
    bool operator()(int x,int y){
        return x > y;
    }
};

//merge,这里把容器vector换成list也可以
void test01(){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    //排序规则对象
    MyCompare myCompare;
    default_random_engine e;
    uniform_int_distribution u(0,100);
    e.seed((unsigned int)time(0));
    for(int i=0;i<10;i++){
        v1.push_back(u(e));
    }
    for(int i=0;i<10;i++){
        v2.push_back(u(e));
    }
    v3.resize(v1.size()+v2.size());
    sort(v1.begin(),v1.end(),myCompare);
    sort(v2.begin(),v2.end(),myCompare);
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin(),myCompare);
    for_each(v3.begin(),v3.end(),printFunc);
}

//random_shuffle()，这里吧vector换成list就不行了！！（因为STL考虑效率，而不支持随机访问的list使用reverse()元素移动的话效率低下所以不行）
void test02(){
    vector<int> v1;
    default_random_engine e;
    uniform_int_distribution u(0,100);
    for(int i=0;i<10;i++){
        v1.push_back(u(e));
    }
    for_each(v1.begin(),v1.end(),printFunc);
    random_shuffle(v1.begin(),v1.end()); //如果容器不支持随机访问就不能用
    for_each(v1.begin(),v1.end(),printFunc);
}

//reverse()，同上不支持随机访问的容器不能用这个函数，要自己写
void test03(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    for_each(v1.begin(),v1.end(),printFunc);
    cout << endl;
    reverse(v1.begin(),v1.end());
    for_each(v1.begin(),v1.end(),printFunc);
}

int main(){
    test03();
    return 0;
}