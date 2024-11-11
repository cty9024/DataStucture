#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>

using namespace std;
using std::string;

typedef pair<string,int> psi;

class node
{
public:
    int num;
    string alphabet;
    node *leftnode;
    node *rightnode;
    /*node (string x,int y){
    	num = y;
    	alphabet = x;
    	leftnode = NULL;
    	rightnode = NULL;
    }*/
    node()
    {
    	num = 0;
    	alphabet = " ";
    	leftnode = NULL;
    	rightnode = NULL;
    }
};

void visit(node *root, string w, map<string, psi> &m){
	if(root){
		visit(root->leftnode, w + "0", m);
		visit(root->rightnode, w + "1",m);
		if(root->alphabet != "*"){
			psi p1= make_pair(w, root->num);
			m[root->alphabet] = p1;
		}
	}
}

void splitString1(string s, vector<string>& buf){
	int current = 0; //最初由 0 的位置開始找
	int next;
	while (1)
	{
		next = s.find_first_of(" |=", current);
		if (next != current)
		{
			string tmp = s.substr(current, next - current);
			if (tmp.size() != 0) //忽略空字串
				buf.push_back(tmp);
		}
		if (next == string::npos) break;
		current = next + 1; //下次由 next + 1 的位置開始找起。
	}
}

void splitString2(string s, vector<string>& buf){
	int current = 0; //最初由 0 的位置開始找
	int next;
	while (1)
	{
		next = s.find_first_of(" ", current);
		if (next != current)
		{
			string tmp = s.substr(current, next - current);
			if (tmp.size() != 0) //忽略空字串
				buf.push_back(tmp);
		}
		if (next == string::npos) break;
		current = next + 1; //下次由 next + 1 的位置開始找起。
	}
}

struct cmp {
    bool operator()(node* a, node* b) {
        return a->num > b->num;
    }
};

void buildtree(priority_queue <node*, vector<node*>, cmp> &q){
	node *temp = new node();
	temp-> leftnode = q.top();
	temp->num += q.top()->num;
	q.pop();
	temp-> rightnode = q.top();
	temp->num += q.top()->num;
	temp->alphabet = "*";
	q.pop();
	q.push(temp); 
}


int main (){
	char c = cin.get();
	string input = "";
	while(c != '\n'){
			input += c; 
			c = cin.get();
	}
	if(input == "./tree"){
		cout << "DSOO-Program2-Demo : " << input << endl;
		priority_queue <node*, vector<node*>, cmp> q;
		string s = "A = 11 | B =  5 | C =  2 | D =  3 | E = 12 | F =  3 | G =  5 | H =  6 | I =  8 | J =  1 | K =  2 | L =  4 | M =  8 | N =  7 | O =  2 | P =  2 | Q =  1 | R =  9 | S =  6 | T =  2 | U =  4 | V =  1 | W = 10 | X = 10 | Y =  1 | Z =  1 | ";
		vector<string> buf;
		splitString1(s, buf);
		for (int i = 0; i < 52; i+=2){
				node *temp = new node();
				temp-> alphabet = buf[i];
				temp->num = atoi(buf[i + 1].c_str());
				q.push(temp);
			}
		while(q.size() > 1){
			buildtree(q);
		}
		node *root = q.top();

		cout << endl;
	
		cout << "A = 11 | B =  5 | C =  2 | D =  3 | E = 12 | F =  3 | G =  5 | H =  6 | I =  8 | J =  1 |" << endl;
		cout << "K =  2 | L =  4 | M =  8 | N =  7 | O =  2 | P =  2 | Q =  1 | R =  9 | S =  6 | T =  2 |" << endl;
		cout << "U =  4 | V =  1 | W = 10 | X = 10 | Y =  1 | Z =  1 |" << endl;
	
		cout << endl;
	
		int sum = 0;
		map<string, psi> route;
		string w = "";
		visit(root, w, route);
		map<string, psi>::iterator i;
		for(i = route.begin(); i != route.end(); i++)
		{
			cout << i->first << " : " << i->second.first << endl;
			sum += i->second.first.length() * i->second.second;
		}
	
		cout << endl;
		cout << "WEPL : " << sum << endl;
	}else{
		cout << "DSOO-Program2-Demo : " << input << endl;
		ifstream ifs(input, ios::in);
    	if (!ifs.is_open()) {
    	    return 1;
    	}
    	stringstream ss;
    	ss << ifs.rdbuf();
    	string str(ss.str());
    	ifs.close();

    	vector<string> buf;
		splitString2(str, buf);
		//cout << "" << input << endl;
		cout << "characters : " << buf[0] << endl;
		cout << endl;
		map<char, int>g;
		string k = buf[0];
		for(int i = 0; i < k.length(); i++){
			if(g.count(k[i]) != 0){
				g[k[i]]++;
			}else{
				g[k[i]] = 1;
			}
		}
		map<char, int>::iterator i;
		int cc = 0;
		string tt = "";
		for(i = g.begin(); i != g.end(); i++)
		{
			cc++;
			cout << i->first << " = " << i->second << " | ";

			stringstream sss;
			sss << i->second;
			if(cc == 10){
				cout << endl;
				cc = 0;
			}
			tt = tt + i->first + " = " + sss.str() + " | ";
		}
		cout << endl;

		priority_queue <node*, vector<node*>, cmp> q;

		vector<string> buff;
		splitString1(tt, buff);
		for (int i = 0; i < buff.size(); i += 2){
				node *temp = new node();
				temp-> alphabet = buff[i];
				temp->num = atoi(buff[i + 1].c_str());
				q.push(temp);
			}
		while(q.size() > 1){
			buildtree(q);
		}
		node *root = q.top();

		int sum = 0;
		map<string, psi> route;
		string w = "";
		visit(root, w, route);
		map<string, psi>::iterator it;
		for(it = route.begin(); it != route.end(); it++)
		{
			cout << it->first << " : " << it->second.first << endl;
			sum += it->second.first.length() * it->second.second;
		}
	
		cout << endl;
		
		//cout << tt << endl;
		cout << "Huffman code : " << buf[1] << endl;
		cout << "decode : ";
		string b = buf[1];
		for(int i = 0; i < b.length(); i++){
			if(b[i] == '0'){
				if(root->leftnode != NULL){
					root = root->leftnode;
					//cout  <<  i << ":" << b[i] << endl;
				}else{
					cout << root->alphabet;
					i--;
					root = q.top();
				}
			}else{
				if(root->rightnode != NULL){
					root = root->rightnode;
					//cout  <<  i << ":" << b[i] << endl;
				}else{
					cout << root->alphabet;
					i--;
					root = q.top();
				}
			}
			if(i == b.length() - 1 && root->alphabet == "*"){
				cout << "-wrong decode-" << endl;
			}
		}

		cout << endl;
		cout << "WEPL : " << sum << endl;
	}
	
	









	/*while(!q.empty())
	{
		cout << q.top()-> alphabet << q.top()->num << endl;
		q.pop();
	}*/
	//cout << tmp <<endl;	
	//num = stoi(str);
	//cout << num << endl;

	return 0;
}