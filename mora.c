#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;


string state(int n)
{
	if(n == 1)
	{
		return "rock";
	}
	
	if(n == 2)
	{
		return "scissor";
	}
	
	if(n == 3)
	{
		return "paper";
	}
}

class Computer
{
	private :
		string name;
	public :
		Computer(string m = "Dingdong")
		{
			name = m;
		}
		
		string getName()
		{
			return name;
		}
		
		int punch()
		{
			int n = rand()%3+1;
			return n;
		}
		
};

class Person
{
	private :
		string name;
	public :
		Person(string m)
		{
			name = m;
		}
		
		string getName()
		{
			return name;
		}
		
		int punch()
		{
			int n;
			while(true)
			{
				cout << "请" << name << "输入出拳信息，1代表rock，2代表scissor，3代表paper，按回车键确认！" << endl; 
				cin >> n;
				if(n != 1 && n != 2 && n != 3)
				{
					cout << "不能耍赖哦,请重新出拳！";
				}
				else break; 
			}
			return n;
		}
		
};

class GameJudge
{
	private :
		float totalNum;
		int AINum;
		vector<float> win;
	public :
		GameJudge(int m,int n)
		{
			win.clear();
			AINum = m;
			totalNum = 0;
			int i = m + n;
			while(i)
			{
				win.push_back(0);
				i --;
			}
		}
		void showGameInf()
		{
			cout << "总共进行了" << totalNum << "场比赛" << endl;
			cout << "其中：" << endl;
			for(int i=0;i<AINum;i++)
			{
				cout << i+1 << "号电脑玩家获胜" << win[i] << "场；" << "胜率为：" << win[i]/totalNum << endl; 
			}
			for(int i=AINum;i<win.size();i++)
			{
				cout << i+1-AINum << "号玩家获胜" << win[i] << "场；" << "胜率为：" << win[i]/totalNum << endl; 
			}	
		}
		
		int  Judge(vector<int> z,int n)
		{
			for(int i=0;i<AINum;i++)
			{
				cout << i+1 <<"号电脑玩家--" << state(z[i]) << "  ";
			} 
			for(int i=AINum;i<n;i++)
			{
				cout << i+1-AINum <<"号玩家--" << state(z[i]) << "  ";
			} 
			cout << endl;
			vector<int> z1,z2,z3;
			for(int i=0;i<n;i++)
			{
				if(z[i] == 1)
				{
					z1.push_back(z[i]);
				}
				if(z[i] == 2)
				{
					z2.push_back(z[i]);
				}
				if(z[i] == 3)
				{
					z3.push_back(z[i]);
				}
			}
			
			if(!z1.empty() && !z2.empty() && z3.empty())
			{  
				cout << "获胜者为：" << endl; 
				
				for(int i=0;i<AINum;i++) 
				{
					if(z[i]==1)
					{
						win[i] ++;
						cout << i+1 << "号电脑玩家 "; 
					}
				}
				
				for(int i=AINum;i<n;i++) 
				{
					if(z[i]==1)
					{
						win[i] ++;
						cout << i+1-AINum << "号玩家 "; 
					}
				}
				cout << endl;
				totalNum ++;
				return 0;
			}
		
			if(!z1.empty() && z2.empty() && !z3.empty())
			{  
				cout << "获胜玩家为：" << endl; 
				for(int i=0;i<AINum;i++) 
				{
					if(z[i]==3)
					{
						win[i] ++;
						cout << i+1 << "号电脑玩家 "; 
					}
				}
				for(int i=AINum;i<n;i++) 
				{
					if(z[i]==3)
					{
						win[i] ++;
						cout << i+1-AINum << "号玩家 "; 
					}
				}
				cout << endl;
				totalNum ++;
				return 0;
			}
			
			if(z1.empty() && !z2.empty() && !z3.empty())
			{  
				cout << "获胜玩家为：" << endl; 
				for(int i=0;i<AINum;i++) 
				{
					if(z[i]==2)
					{
						win[i] ++;
						cout << i+1 << "号电脑玩家 "; 
					}
				}
				for(int i=AINum;i<n;i++) 
				{
					if(z[i]==2)
					{
						win[i] ++;
						cout << i+1-AINum << "号玩家 "; 
					}
				}
				cout << endl;
				totalNum ++;
				return 0;
			}
			cout << "平局！" << endl;
			totalNum ++;
			return 1;
		}
		
}; 

int main()
{
	cout <<"**********************************************" << endl;
	cout <<"*                                            *" << endl;
	cout <<"*             猜拳游戏                       *" << endl;
	cout <<"*             ----Designed by Liu Wenbin     *" << endl;
	cout <<"*                                            *" << endl;
	cout <<"**********************************************" << endl;
	srand(time(0));
	while(true)
	{
		cout << endl;
		cout << "请选择要进行的操作：" << endl;
		cout << "1.游戏介绍" << endl;
		cout << "2.开始游戏" << endl;
		cout << "按其他键退出" << endl;
		int n;
		cin >> n;
		if(n == 1)
		{
			cout <<"1.本游戏采用电脑纯随机出拳策略与多名玩家进行猜拳游戏。" << endl;
			cout <<"2.选择开始游戏，玩家必须为自己命名。" << endl;
			continue;
		}
		if(n == 2)
		{
			vector<int> v;
			vector<Person> person;
			person.clear(); 
			vector<Computer> AI;
			AI.clear();
			cout << "请输入电脑玩家个数：" << endl;
			int a; 
			cin >> a;
			while(a!=0)
			{
				Computer c;
				AI.push_back(c);
				a --;
			}
			cout << "请输入玩家个数：" << endl;
			int q;
			cin >> q;
			GameJudge j(AI.size(),q);
			while(q!=0)
			{
				string s;
				cout << "请输入玩家姓名：" << endl;
				cin >> s;
				Person p(s);
				person.push_back(p);
				q --;
			}
			int i = 1;
			while(i)
			{
				v.clear();
				for(int k=0;k<AI.size();k++)
				{
					v.push_back(AI[k].punch());
				}
				for(int k=0;k<person.size();k++)
				{
					v.push_back(person[k].punch());
				}
				i = j.Judge(v,person.size()+AI.size());
			}
			j.showGameInf();
			continue;
		}
		
		if(n != 1 && n != 2)
		{
			break;
		}
	}
	return 0;
}
