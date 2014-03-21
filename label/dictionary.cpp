#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "dictionary.h"
using namespace std;

dictionary::dictionary(){}

void dictionary::finalize(){
	map<string,inti>::iterator itr;
	for(itr = bulk.begin(); itr != bulk.end(); ++itr){
		if(itr->second.df < 3)
			bulk.erase(itr);
	}
	
	int j = 1;
	for(itr = bulk.begin(); itr != bulk.end(); ++itr){
		itr->second.index = j;
		++j;
	}
}

dictionary::dictionary(ifstream& infile){
	string word;
	int freq;
	int index;
	while (infile >> index >> word >> freq){
		bulk[word].df = freq;
		bulk[word].index = index;
	}
}

void dictionary::output(ofstream& outfile) const{
	map<string,inti>::const_iterator itr;
	for (itr = bulk.begin(); itr != bulk.end(); ++itr){
		if (itr->second.df > 3)
			outfile<<itr->first<<" "<<itr->second.df<<endl;
	}
}

void dictionary::update(const string &str){
	istringstream iss(str);
	string cand;
	map<string,bool> uniqstr;
	while(iss >> cand){
		uniqstr[cand]=true;
	}
	map<string,bool>::const_iterator itr;
	for (itr = uniqstr.begin(); itr != uniqstr.end(); ++itr){
		if(bulk.find(itr->first) == bulk.end()){
				bulk[itr->first].df = 1;
		}else ++(bulk[itr->first].df);
	}
	//updateindex();
}
int dictionary::size()const{
	return bulk.size();
}

int dictionary::where(const string &str){
	//if unfound return -1
	if(bulk.find(str) == bulk.end()){
		return -1;
	}
	else return bulk[str].index;
}

int dictionary::getdf(const string &str){
	//if unfound return -1
	if(bulk.find(str) == bulk.end()){
		return -1;
	}
	else return bulk[str].df;
}





