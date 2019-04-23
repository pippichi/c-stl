//
// Created by QYF on 2019/4/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

class Person{
public:
    Person(){}
    Person(string name,int score):name(name),score(score){}
public:
    string name;
    int score;
};

//创建选手
void createPerson(vector<Person>& v){
    string nameSffix = "ABCDE";
    for(int i=0;i<5;i++){
        Person p;
        p.name += nameSffix.at(i);
        p.score = 0;
        v.push_back(p);
    }
}

//打分
void scoring(vector<Person>& v){
    default_random_engine e;
    e.seed((int)time(0));
    uniform_int_distribution<unsigned> u(60,100);
    for(vector<Person>::iterator i=v.begin();i!=v.end();i++){
        vector<int> v1;
        for(int i=0;i<10;i++){
            v1.push_back(u(e));
        }
        sort(v1.begin(),v1.end());
        deque<int> deque1;
        deque1.assign(v1.begin(),v1.end());
        deque1.pop_front();
        deque1.pop_back();
        int result = 0;
        for(deque<int>::iterator j=deque1.begin();j!=deque1.end();j++){
            result += *j;
        }
        result /= deque1.size();
        (*i).score = result;
    }
}

//排名
bool func02(Person &p1,Person &p2){
    return p1.score > p2.score;
}
void rank2(vector<Person>& v){
    sort(v.begin(),v.end(),func02);
    for(vector<Person>::iterator i=v.begin();i!=v.end();i++){
        cout << (*i).name << ": " << (*i).score << endl;
    }
}

int main(){
    vector<Person> v;
    createPerson(v);
    scoring(v);
    rank2(v);

    return 0;
}