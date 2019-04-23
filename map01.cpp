//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

void test01(){
    map<int,int> mmap;
    //1
    mmap.insert(pair<int,int>(10,2));
    //2
    mmap.insert(make_pair(20,20));
    //3
    mmap.insert(map<int,int>::value_type(1,3));
    //4
    mmap[40] = 21;

    for(map<int,int>::iterator i=mmap.begin();i!=mmap.end();i++){
        cout << "key: " << (*i).first << " value: " << (*i).second << endl;
    }
}

void test02(){
    map<int,int> mmap;
    //1
    pair<map<int,int>::iterator,bool> p = mmap.insert(pair<int,int>(10,2));
    if(p.second){
        cout << "成功1" << endl;
    } else cout << "失败1" << endl;
    p = mmap.insert(pair<int,int>(10,2));
    if(p.second){
        cout << "成功2" << endl;
    }else cout << "失败2" << endl;
    //2同上
    mmap.insert(make_pair(20,20));
    //3同上
    mmap.insert(map<int,int>::value_type(1,3));
    //4
    mmap[40] = 21;
    mmap[10] = 20;//如果key不存在，则创建pair插入到map容器中
                    //如果key存在，则修改原先key对应的值
    for(map<int,int>::iterator i=mmap.begin();i!=mmap.end();i++){
        cout << "key: " << (*i).first << " value: " << (*i).second << endl;
    }
    //mmap[60]原本不存在，以下操作直接给mmap[60]一个默认值
    cout << mmap[60] << endl;
    for(map<int,int>::iterator i=mmap.begin();i!=mmap.end();i++){
        cout << "key: " << (*i).first << " value: " << (*i).second << endl;
    }
}

//map定义对象排序
class PM{
public:
    PM(){}
    PM(int age,int id):age(age),id(id){}
public:
    int age;
    int id;
};
struct Compare{
    bool operator()(PM p1,PM p2) const{
        return p1.age > p2.age;
    }
};
void test03(){
    map<PM,int,Compare> m;
    PM p(10,11),p1(20,22),p2(30,33),p3(40,44);
    m.insert(make_pair(p,30));
    m.insert(make_pair(p1,40));
    m.insert(make_pair(p2,50));
    m.insert(make_pair(p3,60));

    for(map<PM,int,Compare>::iterator i=m.begin();i!=m.end();i++){
        cout << i->first.age << "-" << i->first.id << "-" << i->second << endl;
    }
}

//测试equal_range()
void test04(){
    map<int,int> m;
    m.insert(make_pair(1,11));
    m.insert(make_pair(2,22));
    m.insert(make_pair(3,33));
    m.insert(make_pair(4,44));
    pair<map<int,int>::iterator,map<int,int>::iterator> pair = m.equal_range(2);
    if(pair.first->second){
        cout << "找到第一个" << endl;
    }else{
        cout << "没找到第一个" << endl;
    }
    if(pair.second->second){
        cout << "找到第二个" << endl;
    }else{
        cout << "没找到第二个" << endl;
    }
}

int main(){
    test03();
    return 0;
}