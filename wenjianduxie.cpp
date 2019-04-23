//
// Created by QYF on 2019/4/19.
//

#include <iostream>
#include <fstream>
using namespace std;

//文本文件操作
void test01(){

    char* filename = "C:\\Users\\Administrator\\Desktop\\source.txt";
    char* filename2 = "C:\\Users\\Administrator\\Desktop\\target.txt";
//    方式1
//    ifstream is;
//    is.open(filename,ios::in);

    //方式2
    ifstream is(filename,ios::in);//只读方式打开文件
    ofstream os(filename2,ios::out | ios::app);
    if(!is){
        cout << "打开失败" <<endl;
    }
    //读取内容
    char ch;
    while(is.get(ch)){
        cout << ch;
        os.put(ch);
    }
    //关闭文件
    os.close();
    is.close();
}


//二进制文件操作  对象序列化
class Person{
public:
    Person(){}
    Person(int age,int id):age(age),id(id){}
    void show(){
        cout << "Age: "<<age<<"id: "<<id<<endl;
    }
public:
    int age;
    int id;
};
void test02(){
    Person p1(10,20),p2(40,30);
    char* filename2 = "C:\\Users\\Administrator\\Desktop\\target.txt";
    ofstream os(filename2,ios::out|ios::binary);
    os.write((char*)&p1,sizeof(Person));//二进制方式写文件
    os.write((char*)&p2,sizeof(Person));
    os.flush();
    os.close();
}

//读取test02写入文件中的类
void test03(){
    Person p1,p2;
    char* filename2 = "C:\\Users\\Administrator\\Desktop\\target.txt";
    ifstream is(filename2,ios::in|ios::binary);
    is.read((char*)&p1,sizeof(Person));
    is.read((char*)&p2,sizeof(Person));

    p1.show();
    p2.show();

}

int main (){
    test03();
    return 0;
}