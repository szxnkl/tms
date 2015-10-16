// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;
enum Type{
	SL,
	NOGOOD,
    PREMICE,
    ASSUMPTION
};
class State {
public:
	string name;
	Type type;
	int n;
	vector<int> in;
	vector<int> out;
	bool st;
    string description;
	State(Type type_, string name_, int n_, vector<int> in_, vector<int> out_, bool st_, string description_){
		type = type_;
		name = name_;
		n = n_;
		in = in_;
		out = out_;
		st = st_;
        description = description_;
	}

};
bool is_tragedy = true;
vector<State> update(vector<State> v_s) {

    vector<State> ret_v_s = v_s;
    bool is_changed = false;
    for (int i = 1; i < v_s.size(); i++) {
        if (v_s[i].st == true) {
            if (v_s[i].type == SL || v_s[i].type == NOGOOD){
            for (int j = 0; j < v_s[i].in.size(); j++) {
                if (v_s[v_s[i].in[j]].st == false) {
                    ret_v_s[i].st = false;
                    is_changed = true;
                }
            }
            for (int j = 0; j < v_s[i].out.size(); j++) {
                if (v_s[v_s[i].out[j]].st == true) {
                    ret_v_s[i].st = false;
                    is_changed = true;
                }
            }
            }

        }
        if (v_s[i].st == false) {
            int flag = 1;
            if (v_s[i].type == SL || v_s[i].type == NOGOOD){
            for (int j = 0; j < v_s[i].in.size(); j++) {
                if (v_s[v_s[i].in[j]].st == false) {
                    flag = 0;
                }
            }
            for (int j = 0; j < v_s[i].out.size(); j++) {
                if (v_s[v_s[i].out[j]].st == true) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                ret_v_s[i].st = true;
                is_changed = true;
            }
            }

        }
    }
    if (!is_changed) {
        cout << "not changed" << endl << endl;
        for (int i = 1; i < v_s.size(); i++) {
            if (v_s[i].type == NOGOOD && v_s[i].st == true && rand() % 3 == 0) {
                for (int j = 0; j < v_s[i].in.size(); j++) {
                    if (v_s[v_s[i].in[j]].type == SL || v_s[v_s[i].in[j]].type == ASSUMPTION) {
                        if (v_s[v_s[i].in[j]].out.size() == 0) {
//                            cout << "v_s[" << v_s[i].in[j] << "].out.size()==0" << endl; 
//                            ret_v_s[v_s[i].in[j]].st = false;
//                            goto end;
                        }
                        else {
                            int r = rand() % v_s[v_s[i].in[j]].out.size();
                            cout << "r=" << r << ", sl=" << v_s[v_s[v_s[i].in[j]].out[r]].n << endl;
                            ret_v_s[v_s[v_s[v_s[i].in[j]].out[r]].n].st = true;
                            goto end;
                        }
                        //ret_v_s[v_s[i].in[j]].st = false;
                    }
                    

                }
                /*
                for (int j = 0; j < v_s[i].out.size(); j++) {
                    if (v_s[v_s[i].out[j]].type == ASSUMPTION) {
                         cout << "v_s[" << v_s[i].out[j] << "].out.size()==0" << endl; 
                         ret_v_s[v_s[i].in[j]].st = false;
                         goto end;
                    }
                    else {
                        int r = rand() % v_s[v_s[i].in[j]].out.size();
                        cout << "r=" << r << endl;
                        ret_v_s[v_s[v_s[i].in[j]].out[r]].st = false;
                        goto end;
                    }
                }
                }
                */

            }
        }
end:;
        is_tragedy = false;
        for (int i = 1; i < v_s.size(); i++) {
            if (v_s[i].type == NOGOOD && v_s[i].st == true) {
                is_tragedy = true;
            }
        }
     if (is_tragedy) {
        ret_v_s[0].st = true;
    }
    else {
        ret_v_s[0].st = false;
    }
            
    }
    else {
        cout << "changed" <<endl<<endl;
    }
    
    return ret_v_s;
}
void print_s(State s)
{
    ostringstream oss;
    oss << s.name << " " << (s.st==true?"true":"false") << " " << (s.st==true?s.description:"") << endl;
    cout << oss.str();
        
}
void print_v_s(vector<State> v_s)
{
    for (int i = 0; i < v_s.size(); i++) {
        print_s(v_s[i]);
    }
}

int main(int argc, char* argv[])
{
	vector<State> v_s;
	vector<int> in = { 1, 2, 3 };
	vector<int> out = { 1, 2, 3 };
	string name = "aaa";
    srand(time(NULL));
	v_s.push_back(State(NOGOOD, "tragedy", 0, vector<int>{}, vector<int>{}, true,"tragedy"));
	v_s.push_back(State(PREMICE, "loves_0000", 1, vector<int>{}, vector<int>{}, true,"Hermia -> Lysander"));;
	v_s.push_back(State(PREMICE, "loves_0001", 2, vector<int>{}, vector<int>{}, true,"Helena -> Demitrius"));
	v_s.push_back(State(ASSUMPTION, "assume_0000", 3, vector<int>{}, vector<int>{}, false,"Lysander -> Hermia"));
	v_s.push_back(State(SL, "not_0000", 4, vector<int>{}, vector<int>{3}, false,":"));
	v_s.push_back(State(SL, "loves_0002", 5, vector<int>{4}, vector<int>{3}, false,"Lysander -> Helena"));
	v_s.push_back(State(ASSUMPTION, "assume_0001", 6, vector<int>{}, vector<int>{}, false,"Demitrius -> Hermia"));
	v_s.push_back(State(SL, "not_0001", 7, vector<int>{}, vector<int>{6}, false,":"));
	v_s.push_back(State(SL, "loves_0003", 8, vector<int>{7}, vector<int>{6}, false,"Demitrius -> Helena"));
	v_s.push_back(State(PREMICE, "jealous_0000", 9, vector<int>{}, vector<int>{}, true,"Jealous Lysander"));
	v_s.push_back(State(NOGOOD, "kill", 10, vector<int>{6,5,9}, vector<int>{}, true,"Lysander -> Hermia , Demitrius -> Hermia"));
	v_s.push_back(State(NOGOOD, "kill", 11, vector<int>{5,2}, vector<int>{}, true,"Lysander -> Helena -> Demitrius"));
	v_s.push_back(State(NOGOOD, "kill", 12, vector<int>{6,1}, vector<int>{}, true,"Demitrius -> Hermia -> Lysander"));
	v_s.push_back(State(NOGOOD, "kill", 13, vector<int>{5,7,9}, vector<int>{}, true,"Lysander -> Helena, Demitrius -> Helena"));
	v_s.push_back(State(NOGOOD, "kill", 14, vector<int>{1,5}, vector<int>{}, true,"Hermia -> Lysander -> Helena"));
	v_s.push_back(State(NOGOOD, "kill", 15, vector<int>{2,6}, vector<int>{}, true,"Helena -> Demitrius -> Hermia "));
    for (int i = 0; i < 100; i++) {
        cout << i << endl;
    print_v_s(v_s);
    v_s = update(v_s);
    if (!is_tragedy){
        break;
    }
    getchar();
    }

    print_v_s(v_s);
	return 0;
}
