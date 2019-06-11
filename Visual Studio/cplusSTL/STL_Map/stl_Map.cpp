#include <iostream>
#include <map>
#include <string>

using namespace std;


template <typename K, typename V>
void Print_map(map<K, V>& m)
{
	for (auto itr = m.begin(); itr != m.end(); ++itr)
	{
		cout << itr->first << " : " << itr->second << endl;
	}
}

template <typename K, typename V>
void Range_Bassed_Print_Map(map<K, V>& m)
{
	for (const auto& kv : m)
	{
		cout << kv.first << " : " << kv.second << endl;
	}
}



int main()
{
	map<string, double> pitcher_list;
	pitcher_list.insert(pair<string, double>("·ùÇöÁø", 1.36));
	pitcher_list.insert(make_pair("±è±¤Çö", 2.66));
	pitcher_list.insert(make_pair("Ã¤µå", 3.38));
	pitcher_list["À¯Èñ°ü"] = 2.77;
	cout << "##################### itr" << endl;
	Print_map(pitcher_list);
	cout << "##################### for each" << endl;
	Range_Bassed_Print_Map(pitcher_list);

	//cout << pitcher_list["unkown"] << endl;

	if (pitcher_list.find("unkown") != pitcher_list.end())
		cout << pitcher_list["unkown"] << endl;

	pitcher_list.insert(make_pair("±è±¤Çö", 1.11));
	pitcher_list["±è±¤Çö"] = 1.11;

	Print_map(pitcher_list);

	return 0;


}