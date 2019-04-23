//
// Created by QYF on 2019/4/19.
//
#include <iostream>
using namespace std;

void test01(){
    char ch;
    while((ch=cin.get())!=EOF){
        cout << ch << endl;
    }
}


void test02(){
    char ch2;
    cin.get(ch2);//读取一个字符
    cout << ch2 << endl;
}


void test03(){
    char buf[256] = {0};
    cin.get(buf,256);//从缓冲区读一个字符串
    cout << buf << endl;
}


void test04(){
    char buf[256] = {0};
    cin.getline(buf,256); //读取一行数据
    cout << buf << endl;
}


void test05(){
    char ch;
    cin.get(ch);
    cout << ch << endl;
    cin.ignore();
    cin.get(ch);
    cout << ch <<endl;
}


void test06(){
    char ch;
    cin.get(ch);
    cout << ch << endl;
    //优先查找'\n'，如果在5个字符之内找到'\n'的话就将'\n'之前的字符忽略，如果超过5个字符还未找到'\n'则只省略5个字符
    cin.ignore(5,'\n');//忽略当前字符，从缓冲区取走了
    cin.get(ch);
    cout << ch << endl;
}


void test07(){
    cout << "请输入字符: " << endl;
    char ch;
    ch = cin.peek();//看一下缓冲区中的第一个字符，但不删除
    if(ch>='0' && ch<='9'){
        int num;
        cin >> num;
        cout << "首字符为数字: " << num << endl;
    }
    if(ch>='a' && ch<='z'){
        char c[256] = {0};
        cin >> c;
        cout << "首字符为小写字母: " << c << endl;
    }
    if(ch>='A' && ch<='Z'){
        char c[256] = {0};
        cin >> c;
        cout << "首字符为大写写字母: " << c << endl;
    }
}


void test08(){
    cout << "请输入字符： " <<endl;
    char ch;
    cin.get(ch);
    if(ch>='0' && ch<='9'){
        cin.putback(ch);
        int num ;
        cin >> num;
        cout << "字符为数字: " << num << endl;
    }else{
        cin.putback(ch);
        char ch1[256] = {0};
        cin >> ch1;
        cout << "字符为字母： " << ch1 << endl;
    }
}

int main(){
    test08();
    return 0;
}