#include<iostream>
#include <map>
#include <list>

using namespace std;

double EPSIRON = 1E-15;

class LargeNumber
{
	public:
		
	LargeNumber ()
	{
	}
	LargeNumber (const unsigned para_1, const unsigned para_2, const unsigned dist = 0);
	LargeNumber (const double para_in);
//	拷贝函数还是用默认的吧
//	LargeNumber (const map<int, unsigned short> & para_in);
	
	
	LargeNumber& MultipledByOther(const LargNumber othNum);
	LargeNumber& AddedByOther (const LargeNumber othNum);
	
	private:
		
		map<pair<int, unsigned short>> ChangeFormat(const unsigned para);
		map<int, unsigned short> m_TempSpace;
		map<int, list<unsigned short>>m_mNums;
};

map<int, unsigned short> ChangeFormat (const unsigned para)
{
	unsigned curNum = para;
	map<int, unsigned short> ret_m;
	int xbase = 0;
	while (curNum)
	{
		unsigned short x = curNum % 10;
		if (x)	ret_m[xbase] = x;
		curNum = curNum / 10;
		xbase ++;
	}
	return ret_m;
}


LargeNumber::LargeNumber(const unsigned para_1, const unsigned para_2, const unsigned dist)
{
	 m_mNums = ChangeFormat(para_1);
	map<int, unsigned short> ret_m2 = ChangeFormat (para_2);
	int highest = ret_m2.rbegin()->first;
	int diff = highest + dist +1;
	
	for (auto it=ret_m2.begin(); it!= ret_m2.end(); it ++)
	{
		ret_m1.insert( pair<int, unsigned short>(it->first-diff, it->second);
	}
	
}

LargeNumber::LargeNumber (const double para_1)
{
	if (para_1 < 0)
	{
		return;
	}
	unsigned inte_part = (int) para_1;
	double suf_part = para_1 - inte_part;
	unsigned suf_inte=0;
	unsigned offset =0;
	unsigen dist = 0;
	bool unpassed = true;
	while (abs(suf_inte-suf_part)>EPSIRON)
	{
		offset ++;
		suf_part *=dist*10;
		suf_inte = (int)suf_part;
		if (suf_inte != 0) unpassed = false;
		if (suf_inte == 0 && unpassed) dist ++;
		
	}
	LargeNumber (inte_part, suf_inte, dist);
}