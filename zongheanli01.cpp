//
// Created by QYF on 2019/4/22.
//

#include <iostream>
#include <deque>
#include <map>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>
using namespace std;

class Player{
public:
    Player(){}
    Player(string name){
        this->pName = name;
    }
public:
    string pName;
    int scores[3];
};

//添加成员
void addPlayer(map<int,Player>& m,vector<int>& v){
    string suffixName = "ABCDEFGHIJKLMNOPQRSTUVWX";
    for(int i=0;i<24;i++){
        Player p;
        p.pName = "选手: ";
        p.pName += suffixName[i];
        for(int j=0;j<size(p.scores);j++){
            p.scores[j] = 0;
        }
        v.push_back(i+1);
        m.insert(make_pair(i+1,p));
    }
}

//随手抽签
void setRandom(vector<int>& v){
    random_shuffle(v.begin(),v.end());
}

//打分
void setScore(int index,vector<int>& v,map<int,Player>& m,vector<int>& out){
    default_random_engine e;
    e.seed((unsigned int)time(0));
    uniform_int_distribution u(40,80);
    // 存放score和编号  （根据score自动排序了）
    multimap<int,int> multimap1;
    int controllNum = 0;
    for(vector<int>::iterator i=v.begin();i!=v.end();i++){
        deque<int> dScore;
        //打分
        for(int j=0;j<10;j++){
            dScore.push_back(u(e));
        }
        //排序
        sort(dScore.begin(),dScore.end());
        dScore.pop_back();
        dScore.pop_front();
        //求平均分
        int totalScore = accumulate(dScore.begin(),dScore.end(),0);
        int averageScore = totalScore / dScore.size();
        (*m.find(*i)).second.scores[index-1] = averageScore;
        multimap1.insert(make_pair(averageScore,*i));
        controllNum++;
        if(controllNum % 6 ==0){
            int controllNum2 = 0;
            for(multimap<int,int>::iterator mit=multimap1.begin();mit!=multimap1.end();mit++){
                if(controllNum2>=3){ break;}
                out.push_back((*mit).second);
                controllNum2++;
            }
            multimap1.clear();
        }
    }
}

//打印
void showPlayers(int index,vector<int>& v,map<int,Player>& m){
    cout << "第 " << index << " 轮" << endl;
    for(vector<int>::iterator vit=v.begin();vit!=v.end();vit++){
        cout << "晋级者: " << endl;
        cout << "姓名： " << (*m.find(*vit)).second.pName << endl << "该轮分数： " << (*m.find(*vit)).second.scores[index-1] << endl;
    }
}

int main(){
    //添加成员
    map<int,Player> mPlayers;
    //第一轮比赛 24->12
    vector<int> v1;
    //第二轮比赛 12->6
    vector<int> v2;
    //第三轮比赛 6->3
    vector<int> v3;
    //最终的前三名
    vector<int> v4;

    addPlayer(mPlayers,v1);

    setRandom(v1);
    setScore(1,v1,mPlayers,v2);
    showPlayers(1,v2,mPlayers);

    setRandom(v2);
    setScore(2,v2,mPlayers,v3);
    showPlayers(2,v3,mPlayers);

    setRandom(v3);
    setScore(3,v3,mPlayers,v4);
    showPlayers(3,v4,mPlayers);

    return 0;
}