#include <map>
#include <string>
using namespace std;
#ifndef DICTIONARY_H
#define DICTIONARY_H
struct inti{
	int df;
	int index;
};
class dictionary{
public:	
	//document frequency threhold
//	static const int thre = 3;
	
	map<string,inti> bulk;
	//default constructor
	dictionary();
	
	//take a file and initialize the dictionary
	//the file contains two columns word and df
	dictionary(ifstream& infile);
	
	//output dictionary to a file
	// same format as input file used in initilization
	void output(ofstream& outfile) const;
	
	//str contains a document
	//indices are NOT updated
	//            ^^^ ^^^^^^^
	void update(const string &str);
	
	// Will remove terms occurs in thre or more documents
	//update the index of the dictionary
	void finalize();
	
	//return the size of the dictionary
	int size() const;
	
	// return the index of a searching term
	int where(const string &str);
	
	//return the df of a searching term
	int getdf(const string &str);
};
#endif		//DICTIONARY_H
