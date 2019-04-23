//
// Created by QYF on 2019/4/21.
//

#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

#define SALE_DEPARTMENT 1
#define DEVELOP_DEPARTMENT 2
#define FINACIAL_DEPARTMENT 3

class Worker{
public:
    Worker(){}
    Worker(string name, int age,string tel,double salary):wName(name),wAge(age),wTel(tel),wSalary(salary){}
public:
    string wName;
    int wAge;
    string wTel;
    double wSalary;
};

void addWorkers(vector<Worker>& v){
    string suffixName = "ABCDE";
    default_random_engine e;
    e.seed(time(0));
    uniform_int_distribution u(20,30);
    uniform_real_distribution<double> u1(3000.0,4000.0);
    uniform_int_distribution u2(0,9);
    for(int i=0;i<size(suffixName);i++){
        Worker worker;
        worker.wName = "员工";
        worker.wName += suffixName[i];
        worker.wAge = u(e);
        worker.wSalary = u1(e);
        worker.wTel = "010-21312";
        worker.wTel += to_string(u2(e));
        v.push_back(worker);
    }
}

void groupWorkers(vector<Worker>& v,multimap<int,Worker>& m){
    default_random_engine e;
    e.seed(time(0));
    uniform_int_distribution u(0,3);
    for(vector<Worker>::iterator i=v.begin();i!=v.end();i++){
        switch (u(e)){
            case 1:
                m.insert(multimap<int,Worker>::value_type(SALE_DEPARTMENT,*i));
                break;
            case 2:
                m.insert(multimap<int,Worker>::value_type(DEVELOP_DEPARTMENT,*i));
                break;
            case 3:
                m.insert(multimap<int,Worker>::value_type(FINACIAL_DEPARTMENT,*i));
                break;
            default:
                break;
        }
    }
}

//实现方法1
//void printWorkers(multimap<int,Worker>& m){
//    for(multimap<int,Worker>::iterator i=m.begin();i!=m.end();i++){
//        switch((*i).first){
//            case 1:
//                cout << "销售部门: " << (*i).second.wName << " " << (*i).second.wAge << " " << (*i).second.wSalary << " " << (*i).second.wTel << endl;
//                break;
//            case 2:
//                cout << "研发部门: " << (*i).second.wName << " " << (*i).second.wAge << " " << (*i).second.wSalary << " " << (*i).second.wTel << endl;
//                break;
//            case 3:
//                cout << "财务部门: " << (*i).second.wName << " " << (*i).second.wAge << " " << (*i).second.wSalary << " " << (*i).second.wTel << endl;
//                break;
//            default:
//                break;
//        }
//    }
//}
//实现方法2
void showGroupWorkers(multimap<int,Worker>& m,int departId){
    multimap<int,Worker>::iterator i = m.find(departId);
    int departWorkerNum = m.count(departId);
    int num = 0;
    for(multimap<int,Worker>::iterator j=i;i!=m.end() && num<departWorkerNum;j++,num++){
        cout << (*j).second.wName << " " << (*j).second.wAge << " " << (*j).second.wSalary << " " << (*j).second.wTel << endl;
    }
    cout << "当前部门总人数: " << num << endl;
}
void printWorkers(multimap<int,Worker>& m){
    //销售部门
    cout << "销售部门: " << endl;
    showGroupWorkers(m,SALE_DEPARTMENT);
    //研发部门
    cout << "研发部门: " << endl;
    showGroupWorkers(m,DEVELOP_DEPARTMENT);
    //财务部门
    cout << "财务部门: " << endl;
    showGroupWorkers(m,FINACIAL_DEPARTMENT);
}

int main(){
    vector<Worker> workers;
    multimap<int,Worker> map;
    //添加员工
    addWorkers(workers);
    //员工分组
    groupWorkers(workers,map);
    //打印信息
    printWorkers(map);
    return 0;
}