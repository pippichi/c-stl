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


//��ʽ�����
void test04(){
    int num = 10;
    cout << num <<endl;
    cout.unsetf(ios::dec);//ж��10�������
    cout.setf(ios::oct);//�˽������
    cout.setf(ios::showbase);//��ȫ0
    //��������ַ������
    cout.width(10);
    //���ò�ȫ�ո����ʽΪ*
    cout.fill('*');
    //���ö��뷽ʽ
    cout.setf(ios::left);
    cout << num <<endl;
}


//��ʽ�����2
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