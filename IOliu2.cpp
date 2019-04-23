//
// Created by QYF on 2019/4/19.
//

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void test01(){
    cout << "hello";
    cout.flush();
}


void test02(){
    cout << "123" <<endl;
    cout.put('w').put('a').put('s') <<endl;
}


void test03(){
    cout.write("hello",strlen("hello"));
}


//格式化输出
void test04(){
    int num = 10;
    cout << num <<endl;
    cout.unsetf(ios::dec);//卸载10进制输出
    cout.setf(ios::oct);//八进制输出
    cout.setf(ios::showbase);//补全0
    //设置输出字符串宽度
    cout.width(10);
    //设置补全空格的形式为*
    cout.fill('*');
    //设置对齐方式
    cout.setf(ios::left);
    cout << num <<endl;
}


//格式化输出2
void test05(){
    int num = 10;
    cout << hex
        << setiosflags(ios::showbase)
        << setw(10)
        << setfill('~')
        << setiosflags(ios::left)
        << num
        << endl;
}

int main(){
    test05();
    return 0;
}