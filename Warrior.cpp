#include"Warrior.h"
#include<iomanip>

Weapon::Weapon(int n):label(n),name(weapon_order[n]){
	}

Warrior::Warrior(const string& __Camp,const int &_HP,const string &name,const int &_ATK):HP(_HP),ATK(_ATK)
	{	Camp = __Camp;

		int* MyCamp__numbers= &num__condition.second;
		if(Camp == "red")
		{MyCamp__numbers = &num__condition.first;
		(*MyCamp__numbers)++;}
		else
		(*MyCamp__numbers)++;
		
		int* MyLabel_numbers= &label__condition.second;
		if(Camp == "red")
		{MyLabel_numbers = &label__condition.first;
		(*MyLabel_numbers)++;}
		else
		(*MyLabel_numbers)++;
		label = *MyLabel_numbers;
		
		cout<<setfill('0')<<setw(3)<<now__time<<' '
		<<Camp<<' '<<name<<' '<<*MyLabel_numbers<<' '
		<<"born with strength "<<HP<<',';
	}
Warrior::~Warrior(){
		if(Camp=="red")
		num__condition.first--;
		else
		num__condition.second--;
	}

void Warrior::label__reset(){
	label__condition.first = 0;
	label__condition.second = 0;
}

//三个属性, 阵营,生命值,攻击力
Dragon::Dragon(const string& __Camp,const int &_HP,const int &_ATK):Warrior(__Camp,_HP,"dragon",_ATK),weapon(label%3){
		morale = (double)(__Camp=="red" ?left__HP.first:left__HP.second)/(double)(warr__HP["dragon"]);		
		int zhibiao=1;
		if(__Camp=="red")
		cout<<++type_num.first;
		else
		cout<<++type_num.second;
		cout<<' '<<"dragon"<<' '
		<<"in "<<Camp<<" headquarter"<<endl;

		cout<<"It has a "<<weapon.name<<",and it's morale is "<<setiosflags(ios::fixed)<<setprecision(2)<<morale<<endl;
		
	}
Dragon::~Dragon(){
			if(Camp=="red")
			type_num.first--;
			else
			type_num.second--;
		}


//三个属性, 阵营,生命值,攻击力

Ninja::Ninja(const string& __Camp,const int &_HP,const int &_ATK):Warrior(__Camp,_HP,"ninja",_ATK),
		weapon_1(label%3),weapon_2((label+1)%3){
		int zhibiao=1;
		if(__Camp=="red")
		cout<<++type_num.first;
		else
		cout<<++type_num.second;
		cout<<' '<<"ninja"<<' '
		<<"in "<<Camp<<" headquarter"<<endl;
		cout<<"It has a "<<weapon_1.name<<" and a "<<weapon_2.name<<endl;
	}
Ninja::~Ninja(){
		if(Camp=="red")
		type_num.first--;
		else
		type_num.second--;
	}

//三个属性, 阵营,生命值,攻击力

Iceman::Iceman(const string& __Camp,const int &_HP,const int &_ATK):Warrior(__Camp,_HP,"iceman",_ATK),
		weapon(label%3){
		int zhibiao=1;
		if(__Camp=="red")
		cout<<++type_num.first;
		else
		cout<<++type_num.second;
		cout<<' '<<"iceman"<<' '
		<<"in "<<Camp<<" headquarter"<<endl;
		cout<<"It has a "<<weapon.name<<endl;
	}
Iceman::~Iceman(){
		if(Camp=="red")
		type_num.first--;
		else
		type_num.second--;
	}

//三个属性, 阵营,生命值,攻击力
Lion::Lion(const string& __Camp,const int &_HP,const int &_ATK):Warrior(__Camp,_HP,"lion",_ATK),
		loyalty(__Camp =="red"?left__HP.first:left__HP.second){
		int zhibiao=1;
		if(__Camp=="red")
		cout<<++type_num.first;
		else
		cout<<++type_num.second;
		cout<<' '<<"lion"<<' '
		<<"in "<<Camp<<" headquarter"<<endl;
		cout<<"It's loyalty is "<<loyalty<<endl;
	}
Lion::~Lion(){
		if(Camp=="red")
		type_num.first--;
		else
		type_num.second--;
	}

//三个属性, 阵营,生命值,攻击力
Wolf::Wolf(const string& __Camp,const int &_HP,const int &_ATK): Warrior(__Camp,_HP,"wolf",_ATK){
		int zhibiao=1;
		if(__Camp=="red")
		cout<<++type_num.first;
		else
		cout<<++type_num.second;
		cout<<' '<<"wolf"<<' '
		<<"in "<<Camp<<" headquarter"<<endl;
	}
Wolf::	~Wolf(){
		if(Camp=="red")
		type_num.first--;
		else
		type_num.second--;
	}

Warrior* new__obj(const string& tribe,const string& name){
	Warrior* p=nullptr;
	if(name=="dragon")
	p=new Dragon(tribe,warr__HP[name]);
	if(name=="ninja")
	p=new Ninja(tribe,warr__HP[name]);
	if(name=="iceman")
	p=new Iceman(tribe,warr__HP[name]);
	if(name=="lion")
	p=new Lion(tribe,warr__HP[name]);
	if(name=="wolf")
	p=new Wolf(tribe,warr__HP[name]);
	return p;
}

/****************统一归零*******************/

pair<int,int> Warrior::num__condition=make_pair(0,0);
pair<int,int> Warrior::label__condition=make_pair(0,0);
pair<int,int> Dragon::type_num=make_pair(0,0);
pair<int,int> Ninja::type_num=make_pair(0,0);
pair<int,int> Iceman::type_num=make_pair(0,0);
pair<int,int> Lion::type_num=make_pair(0,0);
pair<int,int> Wolf::type_num=make_pair(0,0);

map<int,string> Weapon::weapon_order={{0,"sword"},{1,"bomb"},{2,"arrow"}};
/********************结束********************/