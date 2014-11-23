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
				cout << "Çë" << name << "ÊäÈë³öÈ­ÐÅÏ¢£¬1´ú±írock£¬2´ú±íscissor£¬3´ú±ípaper£¬°´»Ø³µ¼üÈ·ÈÏ£¡" << endl; 
				cin >> n;
				if(n != 1 && n != 2 && n != 3)
				{
					cout << "²»ÄÜË£ÀµÅ¶,ÇëÖØÐÂ³öÈ­£¡";
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
			cout << "×Ü¹²½øÐÐÁË" << totalNum << "³¡±ÈÈü" << endl;
			cout << "ÆäÖÐ£º" << endl;
			for(int i=0;i<AINum;i++)
			{
				cout << i+1 << "ºÅµçÄÔÍæ¼Ò»ñÊ¤" << win[i] << "³¡£»" << "Ê¤ÂÊÎª£º" << win[i]/totalNum << endl; 
			}
			for(int i=AINum;i<win.size();i++)
			{
				cout << i+1-AINum << "ºÅÍæ¼Ò»ñÊ¤" << win[i] << "³¡£»" << "Ê¤ÂÊÎª£º" << win[i]/totalNum << endl; 
			}	
		}
		
		int  Judge(vector<int> z,int n)
		{
			for(int i=0;i<AINum;i++)
			{
				cout << i+1 <<"ºÅµçÄÔÍæ¼Ò--" << state(z[i]) << "  ";
			} 
			for(int i=AINum;i<n;i++)
			{
				cout << i+1-AINum <<"ºÅÍæ¼Ò--" << state(z[i]) << "  ";
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
				cout << "»ñÊ¤ÕßÎª£º" << endl; 
				
				for(int i=0;i<AINum;i++) 
				{
					if(z[i]==1)
					{
						win[i] ++;
						cout << i+1 << "ºÅµçÄÔÍæ¼Ò "; 
					}
				}
				
				for(int i=AINum;i<n;i++) 
				{
					if(z[i]==1)
					{
						win[i] ++;
						cout << i+1-AINum << "ºÅÍæ¼Ò "; 
					}
				}
				cout << endl;
				totalNum ++;
				return 0;
			}
		
			if(!z1.empty() && z2.empty() && !z3.empty())
			{  
				cout << "»ñÊ¤Íæ¼ÒÎª£º" << endl; 
				for(int i=0;i<AINum;i++) 
				{
					if(z[i]==3)
					{
						win[i] ++;
						cout << i+1 << "ºÅµçÄÔÍæ¼Ò "; 
					}
				}
				for(int i=AINum;i<n;i++) 
				{
					if(z[i]==3)
					{
						win[i] ++;
						cout << i+1-AINum << "ºÅÍæ¼Ò "; 
					}
				}
				cout << endl;
				totalNum ++;
				return 0;
			}
			
			if(z1.empty() && !z2.empty() && !z3.empty())
			{  
				cout << "»ñÊ¤Íæ¼ÒÎª£º" << endl; 
				for(int i=0;i<AINum;i++) 
				{
					if(z[i]==2)
					{
						win[i] ++;
						cout << i+1 << "ºÅµçÄÔÍæ¼Ò "; 
					}
				}
				for(int i=AINum;i<n;i++) 
				{
					if(z[i]==2)
					{
						win[i] ++;
						cout << i+1-AINum << "ºÅÍæ¼Ò "; 
					}
				}
				cout << endl;
				totalNum ++;
				return 0;
			}
			cout << "Æ½¾Ö£¡" << endl;
			totalNum ++;
			return 1;
		}
		
}; 

int main()
{
	cout <<"**********************************************" << endl;
	cout <<"*                                            *" << endl;
	cout <<"*             ²ÂÈ­ÓÎÏ·                       *" << endl;
	cout <<"*             ----Designed by Liu Dingdong   *" << endl;
	cout <<"*                                            *" << endl;
	cout <<"**********************************************" << endl;
	srand(time(0));
	while(true)
	{
		cout << endl;
		cout << "ÇëÑ¡ÔñÒª½øÐÐµÄ²Ù×÷£º" << endl;
		cout << "1.ÓÎÏ·½éÉÜ" << endl;
		cout << "2.¿ªÊ¼ÓÎÏ·" << endl;
		cout << "°´ÆäËû¼üÍË³ö" << endl;
		int n;
		cin >> n;
		if(n == 1)
		{
			cout <<"1.±¾ÓÎÏ·²ÉÓÃµçÄÔ´¿Ëæ»ú³öÈ­²ßÂÔÓë¶àÃûÍæ¼Ò½øÐÐ²ÂÈ­ÓÎÏ·¡£" << endl;
			cout <<"2.Ñ¡Ôñ¿ªÊ¼ÓÎÏ·£¬Íæ¼Ò±ØÐëÎª×Ô¼ºÃüÃû¡£" << endl;
			continue;
		}
		if(n == 2)
		{
			vector<int> v;
			vector<Person> person;
			person.clear(); 
			vector<Computer> AI;
			AI.clear();
			cout << "ÇëÊäÈëµçÄÔÍæ¼Ò¸öÊý£º" << endl;
			int a; 
			cin >> a;
			while(a!=0)
			{
				Computer c;
				AI.push_back(c);
				a --;
			}
			cout << "ÇëÊäÈëÍæ¼Ò¸öÊý£º" << endl;
			int q;
			cin >> q;
			GameJudge j(AI.size(),q);
			while(q!=0)
			{
				string s;
				cout << "ÇëÊäÈëÍæ¼ÒÐÕÃû£º" << endl;
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
