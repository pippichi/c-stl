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
    cin.get(ch2);//��ȡһ���ַ�
    cout << ch2 << endl;
}


void test03(){
    char buf[256] = {0};
    cin.get(buf,256);//�ӻ�������һ���ַ���
    cout << buf << endl;
}


void test04(){
    char buf[256] = {0};
    cin.getline(buf,256); //��ȡһ������
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
    //���Ȳ���'\n'�������5���ַ�֮���ҵ�'\n'�Ļ��ͽ�'\n'֮ǰ���ַ����ԣ��������5���ַ���δ�ҵ�'\n'��ֻʡ��5���ַ�
    cin.ignore(5,'\n');//���Ե�ǰ�ַ����ӻ�����ȡ����
    cin.get(ch);
    cout << ch << endl;
}


void test07(){
    cout << "�������ַ�: " << endl;
    char ch;
    ch = cin.peek();//��һ�»������еĵ�һ���ַ�������ɾ��
    if(ch>='0' && ch<='9'){
        int num;
        cin >> num;
        cout << "���ַ�Ϊ����: " << num << endl;
    }
    if(ch>='a' && ch<='z'){
        char c[256] = {0};
        cin >> c;
        cout << "���ַ�ΪСд��ĸ: " << c << endl;
    }
    if(ch>='A' && ch<='Z'){
        char c[256] = {0};
        cin >> c;
        cout << "���ַ�Ϊ��дд��ĸ: " << c << endl;
    }
}


void test08(){
    cout << "�������ַ��� " <<endl;
    char ch;
    cin.get(ch);
    if(ch>='0' && ch<='9'){
        cin.putback(ch);
        int num ;
        cin >> num;
        cout << "�ַ�Ϊ����: " << num << endl;
    }else{
        cin.putback(ch);
        char ch1[256] = {0};
        cin >> ch1;
        cout << "�ַ�Ϊ��ĸ�� " << ch1 << endl;
    }
}

int main(){
    test08();
    return 0;
}