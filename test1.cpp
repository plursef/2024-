#include <iostream>
#include<iomanip>
#include "Warrior.h"

using namespace std;
int now__time=0;//游戏进行时间
int full__HP=0;//给定生命石数		
map<string,int> warr__HP;//怪物和其对应血量
pair<int,int> left__HP;//剩余生命石数


//默认生成顺序(红方)
list<string> red_order = {"iceman","lion","wolf","ninja","dragon"};
// //默认生成顺序(蓝方)
list<string> blue_order = {"lion","dragon","ninja","iceman","wolf"};

int main(){

	/**************更改输出*****************/
	freopen("output.txt","w",stdout);
    /***************************************/
	int cases;  cin>>cases;
	int which__case=0;
	while(which__case<cases){cin>>full__HP;
		now__time = 0;
		which__case += 1;
		left__HP = make_pair(full__HP,full__HP);
		cout<<"Case:"<<which__case<<endl;
		//初始化
		list<Warrior*> Red__Tribe,//红方总阵营
		Blue__Tribe;//蓝方总阵营
		//构建warr__HP的图结构
		cin>>warr__HP["dragon"]>>warr__HP["ninja"]>>warr__HP["iceman"]
		>>warr__HP["lion"]>>warr__HP["wolf"];
		//下一个要生成的红方阵营元素
		auto red_next = red_order.begin();
		//下一个要生成的蓝方阵营元素
		auto blue_next = blue_order.begin();
		//中止判断符
		bool red_stop=0,blue_stop=0;
		while(!(red_stop&&blue_stop)){//当未中止时
			/*准备迭代器*/
			auto it = red_next;int i;
			for(i=0;i<5;++it,++i){
				if(it == red_order.end())
				it = red_order.begin();//因为list无法首尾相接
				if(warr__HP[*it]<=left__HP.first){
					left__HP.first -= warr__HP[*it];
					Red__Tribe.push_back((Warrior*)(new__obj("red",*it)));//创建新对象
					red_next = ++it;
					break;
				}
			}
			//判断是否中止
			if(i==5&&!red_stop)
			{cout<<setfill('0')<<setw(3)<<now__time<<" red headquarter stops making warriors"<<endl;red_stop=1;}
			/*准备迭代器*/
			auto it2 = blue_next;
			for(i=0;i<5;it2++,i++){
				if(it2 == blue_order.end())
				it2 = blue_order.begin();
				if(warr__HP[*it2]<=left__HP.second){
					left__HP.second -= warr__HP[*it2];
					Blue__Tribe.push_back((Warrior*)(new__obj("blue",*it2)));//创建新对象
					blue_next = ++it2;
					break;
				}
			}
			//判断是否中止
			if(i==5&&!blue_stop)
			{cout<<setfill('0')<<setw(3)<<now__time<<" blue headquarter stops making warriors"<<endl;blue_stop=1;}
			now__time++;
		}
		//一轮结束后正常删除
		for(auto p:Red__Tribe){
			delete p;
		}
		for(auto p:Blue__Tribe){
			delete p;
		}
		Warrior::label__reset();
	}
	return 0;
}