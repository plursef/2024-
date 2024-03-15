#include<iostream>
#include<map>
#include<list>
using namespace std;

extern int now__time;// 游戏当前进行时刻
extern int full__HP;////给定生命石数	
extern pair<int,int> left__HP;//剩余生命石数
extern map<string,int> warr__HP;//怪物和其对应血量
//武器类
class Weapon
{	
	const int label;//编号
	static map<int,string> weapon_order;//编号和武器的对应
public:
	const string name;
	Weapon(int n);
};



class Warrior
{
protected:
	int ATK;//攻击力
	int HP;//生命值
	int label;///编号
	string Camp;//所属阵营
	string name;//名称
	static pair<int,int> num__condition;//红蓝双方各自兵数
	static pair<int,int> label__condition;//红蓝双方各自兵数

public:
    //构造函数,分别是所属阵营,生命值,名称,攻击力
	Warrior(const string& __Camp,const int &_HP,const string &name,const int &_ATK=0);
	
    //析构函数,需要声明为虚函数以维持总个数一致
	virtual ~Warrior();

	//序号清零,以开始下一次训练
	static void label__reset();



};

/*******************以下是许多派生类生物********************/

//派生类Dragon
class Dragon:public Warrior
{
	Weapon weapon;//武器
	double morale;//士气

	static pair<int,int> type_num;//红蓝阵营同属性名
public:
	Dragon(const string& __Camp,const int &_HP,const int &_ATK=0);
		~Dragon();


};
class Ninja:public Warrior
{
	Weapon weapon_1;//武器1
	Weapon weapon_2;//武器2

	static pair<int,int> type_num;//红蓝阵营同属性名
public:
	Ninja(const string& __Camp,const int &_HP,const int &_ATK=0);
	~Ninja();

};
class Iceman:public Warrior
{	
	Weapon weapon;//武器

	static pair<int,int> type_num;//红蓝阵营同属性名
public:
	Iceman(const string& __Camp,const int &_HP,const int &_ATK=0);
	~Iceman();

};
class Lion:public Warrior
{
	int loyalty;//忠诚度

	static pair<int,int> type_num;//红蓝阵营同属性名
public:
	Lion(const string& __Camp,const int &_HP,const int &_ATK=0);
	~Lion();

};
class Wolf:public Warrior
{
	static pair<int,int> type_num;//红蓝阵营同属性名
public:
	Wolf(const string& __Camp,const int &_HP,const int &_ATK=0);
	~Wolf();

};

/*******************以上是许多派生类生物********************/

//函数声明

//用于生成一个新的怪物,指定tribe作为阵营,指定其名称
Warrior* new__obj(const string& tribe,const string& name);
