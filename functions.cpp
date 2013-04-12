#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>

#include "functions.h"

Object add(std::vector<Object*> s){
	int total = 0;
	for(int i=0; i<s.size(); ++i){
		Object o = s[i]->exec();
		int val = atoi(o.val.c_str());
		if(val == 0) {
			std::cout << "No integer!" << std::endl;
			exit(127);
		}
		total += val;
	}
	Object obj;
	std::stringstream ss;
	ss << total;
	obj.val = ss.str();
	return obj;
}

Object mult(std::vector<Object*> s){
	int total = 1;
	for(int i=0; i<s.size(); ++i){
		Object o = s[i]->exec();
		int val = atoi(o.val.c_str());
		if(val == 0) {
			std::cout << "No integer!" << std::endl;
			exit(127);
		}
		total *= val;
	}
	Object obj;
	std::stringstream ss;
	ss << total;
	obj.val = ss.str();
	return obj;
}