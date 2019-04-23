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

//��ӳ�Ա
void addPlayer(map<int,Player>& m,vector<int>& v){
    string suffixName = "ABCDEFGHIJKLMNOPQRSTUVWX";
    for(int i=0;i<24;i++){
        Player p;
        p.pName = "ѡ��: ";
        p.pName += suffixName[i];
        for(int j=0;j<size(p.scores);j++){
            p.scores[j] = 0;
        }
        v.push_back(i+1);
        m.insert(make_pair(i+1,p));
    }
}

//���ֳ�ǩ
void setRandom(vector<int>& v){
    random_shuffle(v.begin(),v.end());
}

//���
void setScore(int index,vector<int>& v,map<int,Player>& m,vector<int>& out){
    default_random_engine e;
    e.seed((unsigned int)time(0));
    uniform_int_distribution u(40,80);
    // ���score�ͱ��  ������score�Զ������ˣ�
    multimap<int,int> multimap1;
    int controllNum = 0;
    for(vector<int>::iterator i=v.begin();i!=v.end();i++){
        deque<int> dScore;
        //���
        for(int j=0;j<10;j++){
            dScore.push_back(u(e));
        }
        //����
        sort(dScore.begin(),dScore.end());
        dScore.pop_back();
        dScore.pop_front();
        //��ƽ����
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

//��ӡ
void showPlayers(int index,vector<int>& v,map<int,Player>& m){
    cout << "�� " << index << " ��" << endl;
    for(vector<int>::iterator vit=v.begin();vit!=v.end();vit++){
        cout << "������: " << endl;
        cout << "������ " << (*m.find(*vit)).second.pName << endl << "���ַ����� " << (*m.find(*vit)).second.scores[index-1] << endl;
    }
}

int main(){
    //��ӳ�Ա
    map<int,Player> mPlayers;
    //��һ�ֱ��� 24->12
    vector<int> v1;
    //�ڶ��ֱ��� 12->6
    vector<int> v2;
    //�����ֱ��� 6->3
    vector<int> v3;
    //���յ�ǰ����
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