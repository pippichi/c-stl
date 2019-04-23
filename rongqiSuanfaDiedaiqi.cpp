//
// Created by QYF on 2019/4/19.
//
#include <iostream>
using namespace std;

//统计数字出现次数
int alg(int* begin,int* end,int val){
    int num = 0;
    while(begin!=end){
        if(*begin == val){
            num++;
        }
        begin++;
    }
    return num;
}

int main(){
    //数组 容器
    int arr[]  = {1,26,543,212,3,1,0};
    int* aBegin = arr;
    int* aEnd = &arr[size(arr)];
    cout << alg(aBegin,aEnd,1) << endl;
    return 0;
}
