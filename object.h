#ifndef INTER_OBJECT
#define INTER_OBJECT

class Object{
public:
	virtual Object exec(){ return *this; }
	std::string val;
};

typedef Object (*FuncPtr) (std::vector<Object*>);

class Func: public Object{
public:
	Func(): pt(0) {}
	FuncPtr pt;
	Object exec(){
		if(pt != 0){
			return pt(args);
		}else{
			Object ret = args[0]->exec();
			for(int i=1; i<args.size(); ++i){
				args[i]->exec();
			}
			return ret;
		}
	}
	std::vector<Object*> args;
};
#endif