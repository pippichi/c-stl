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


    //[] �� at ������[]��ʽ�������Խ�磬ֱ�ӹ���
    //at��ʽ����Խ���׳��쳣out_of_range
    cout << "[]����" << endl;
    for(int i=0;i<s1.size();i++){
        cout << s1[i] << endl;
    }
    cout << "at��Ա����" << endl;
    for(int i=0;i<s1.size();i++){
        cout << s1.at(i) << endl;
    }

}


//[] �� at ������[]��ʽ�������Խ�磬ֱ�ӹ���
//at��ʽ����Խ���׳��쳣out_of_range
void test02(){
    string s1;
    s1.assign("asdasxcasx");
    try{
        cout << s1.at(100) << endl;
    }catch (...){
        cout << "Խ�磡" << endl;
    }
}

//append(const string &s,int pos,int n) -> ���ַ���s��posλ�ÿ�ʼ��n���ַ�ƴ�ӵ�Ŀ���ַ���
void test03(){
    string s1 = "as100";
    string s2 = "vsd222";
    s1.append(s2,1,2);
    cout << s1 << endl;
}

//���Ҳ���
void test04(){
    string s = "assdasd";
    //���ҵ�һ�γ��ֵ�λ��
    int pos = s.find("as");
    cout << pos << endl;
    //�������һ�γ��ֵ�λ��
    int pos2 = s.rfind("as");
    cout << pos2 << endl;
}

//string�滻
void test05(){
    string s = "abcdefg";
    s.replace(0,2,"111");
    cout << s << endl;
}

//string�Ƚ�
void test06(){
    string s = "sasdasd";
    string s1 = "sadad";
    int result = s.compare(s1);
    if(result == 0){
        cout << "s1��s���" << endl;
    }
    else cout << "s1��s�����" << endl;
}


//�ִ�����
void test07(){
    string s = "sasdasd";
    string s1 = s.substr(0,3);
    cout << s1 << endl;
}

//������ɾ��
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