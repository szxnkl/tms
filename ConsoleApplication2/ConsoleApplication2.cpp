// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
enum Type{
	SL,
	NOGOOD
};
class State {
public:
	string name;
	Type type;
	int n;
	vector<int> in;
	vector<int> out;
	bool st;
	State(Type type_, string name_, int n_, vector<int> in_, vector<int> out_, bool st_){
		type = type_;
		name = name_;
		n = n_;
		in = in_;
		out = out_;
		st = st_;
	}

};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<State> v_s;
	vector<int> in = { 1, 2, 3 };
	vector<int> out = { 1, 2, 3 };
	string name = "aaa";
	v_s.push_back(State(NOGOOD, "tragedy", 0, vector<int>{}, vector<int>{}, false));
	v_s.push_back(State(SL, "loves_0000", 1, vector<int>{}, vector<int>{}, true));
	v_s.push_back(State(SL, "loves_0001", 2, vector<int>{}, vector<int>{}, true));
	v_s.push_back(State(SL, "assume_0000", 3, vector<int>{}, vector<int>{}, true));
	v_s.push_back(State(SL, "not_0000", 4, vector<int>{}, vector<int>{5}, false));
	v_s.push_back(State(SL, "loves_0002", 5, vector<int>{3}, vector<int>{4}, true));
	v_s.push_back(State(SL, "assume_0001", 6, vector<int>{}, vector<int>{}, true));
	v_s.push_back(State(SL, "not_0001", 7, vector<int>{}, vector<int>{8}, false));
	v_s.push_back(State(SL, "loves_0003", 8, vector<int>{6}, vector<int>{7}, true));
	v_s.push_back(State(SL, "jealous_0000", 9, vector<int>{}, vector<int>{}, true));


	cout << (v_s[0].name) << endl;
	return 0;
}

