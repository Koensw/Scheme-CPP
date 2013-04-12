#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include "functions.h"

std::istream &in(std::cin);

std::map<std::string, FuncPtr> fp;

Func *r;

void append(Func *p, std::string r){
	if(r=="") return;
	if(p->pt == 0){
		if(fp.count(r) == 0){
			std::cout << "Method not found: " << r << std::endl;
			exit(127);
		}
		p->pt = fp[r];
	}else{
		Object *o = new Object;
		o->val = r;
		p->args.push_back(o);
	}
}

void parse(Func *p, int level = 0){
	Func *el = new Func;
	std::string r;
	while(true){
		char c;
		in >> std::noskipws >> c;
		if(in.eof()) {
			p->args.push_back(el);
			return;
		}
		//read special
		if(c==' '){
			append(el, r);
			r = "";
			continue;
		}else if(c=='(') {
			parse(el, level+1);
		}else if(c==')') {
			append(el, r);
			r = "";
			p->args.push_back(el);
			return;
		}else r.push_back(c);
	}
	std::cout << "Unexpected end" << std::endl;
	exit(127);
}

void init(){
	fp["+"] = add;
	fp["*"] = mult;
}

int main(int argc, char **argv){
	r = new Func;
	//init function table
	init();
	//parse
	while(!in.eof()){
		parse(r);
	}
	//execute
	std::cout << r->exec().val << std::endl;;
	return 0;
}