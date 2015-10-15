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
	State s = State(SL, name, 0, vector<int>{1, 2, 3}, out, true);
	v_s.push_back(s);
	return 0;
}

