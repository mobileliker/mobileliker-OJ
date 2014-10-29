#include <iostream>
#include <string>

using namespace std;

const int haab_day_of_year = 18 * 20 + 5;
const string name_of_month_haab[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
const int haab_num_of_month = 19;
const int haab_day_of_month = 20;

const int tzolkin_day_of_year = 13 * 20;
const int tzolkin_day_of_num = 20;
const int tzolkin_day_of_period = 13;
const string name_of_num[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben","ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int get_haab_day(const int year,const string str_month,const int day)
{
	int count = year * haab_day_of_year;

	int i = 0;
	for(i = 0; i < haab_num_of_month; ++i) if(str_month == name_of_month_haab[i]) break;
	count += i * haab_day_of_month + day;

	return count;

}

void get_tzolkin_date_of_count(const int count)
{
	int year = count / tzolkin_day_of_year;

	int l_count = count % tzolkin_day_of_year;

	int num = l_count % tzolkin_day_of_num;
	int period = l_count % tzolkin_day_of_period + 1;


	cout << period << " " << name_of_num[num] << " " << year << endl;

	return;

}

int main()
{
	//freopen("D://input.txt","r",stdin);

	int n;
	cin >> n;

	cout << n << endl;

	while(n--)
	{
		int day = 0;
		string str_month = "";
		int year = 0;

		cin >> day;
		cin.get();
		cin >> str_month >> year;

		//cout << "year= " << year << endl;
		//cout << "month= " << str_month << endl;
		//cout << "day= " << day << endl;

		int count = get_haab_day(year,str_month,day);

		//cout << count << endl;

		get_tzolkin_date_of_count(count);

	}

	return 0;
}