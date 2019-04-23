//
// Created by QYF on 2019/4/19.
//

#include <iostream>
#include <string>

using namespace std;

void test01(){
    string s1;
    string s2("aaw");
    string s3;
    s1 = "asdasd";
    cout << s1 << endl;
    s1 = s2;
    cout << s1 << endl;
    s1 = "asdasd";
    cout << s1 << endl;
    s1.assign("asdasdasdasd");
    cout << s1 << endl;


    //[] 和 at 的区别：[]方式如果访问越界，直接挂了
    //at方式访问越界抛出异常out_of_range
    cout << "[]遍历" << endl;
    for(int i=0;i<s1.size();i++){
        cout << s1[i] << endl;
    }
    cout << "at成员函数" << endl;
    for(int i=0;i<s1.size();i++){
        cout << s1.at(i) << endl;
    }

}


//[] 和 at 的区别：[]方式如果访问越界，直接挂了
//at方式访问越界抛出异常out_of_range
void test02(){
    string s1;
    s1.assign("asdasxcasx");
    try{
        cout << s1.at(100) << endl;
    }catch (...){
        cout << "越界！" << endl;
    }
}

//append(const string &s,int pos,int n) -> 将字符串s从pos位置开始第n个字符拼接到目标字符串
void test03(){
    string s1 = "as100";
    string s2 = "vsd222";
    s1.append(s2,1,2);
    cout << s1 << endl;
}

//查找操作
void test04(){
    string s = "assdasd";
    //查找第一次出现的位置
    int pos = s.find("as");
    cout << pos << endl;
    //查找最后一次出现的位置
    int pos2 = s.rfind("as");
    cout << pos2 << endl;
}

//string替换
void test05(){
    string s = "abcdefg";
    s.replace(0,2,"111");
    cout << s << endl;
}

//string比较
void test06(){
    string s = "sasdasd";
    string s1 = "sadad";
    int result = s.compare(s1);
    if(result == 0){
        cout << "s1和s相等" << endl;
    }
    else cout << "s1和s不相等" << endl;
}


//字串操作
void test07(){
    string s = "sasdasd";
    string s1 = s.substr(0,3);
    cout << s1 << endl;
}

//插入与删除
void test08(){
    string s = "sasdasd";
    s.insert(1,"111");
    cout << s << endl;
    s.erase(0,2);
    cout << s << endl;
}

int main(){
    test08();
    return 0;
}