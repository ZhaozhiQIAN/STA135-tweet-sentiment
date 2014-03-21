#include <fstream>
#include <string>
#include <algorithm>
#include "dictionary.h"
using namespace std;

namespace{
	string ctext(string& raw){
		transform(raw.begin(), raw.end(), raw.begin(), ::tolower);
		string result(raw);
		//remove all the symbols and numbers
		char symbols [] = {'!', '?', ',', '\'','.','@','(',')','+','-','/',':','\\','"','=','$','%',
							'*','&',';','|','[',']','^','_','`','~','#','0','1','2','3','4','5',
							'6','7','8','9','<','>'};
		int symbols_size = sizeof(symbols) / sizeof(char);  
		for (int j = 0; j < symbols_size; j++)
   		 replace(result.begin(), result.end(), symbols[j], ' ');
		return result;
	}
}

int main(){
	//initialization
	dictionary dict;
 	ifstream infile;
 	infile.open("labtraining");
 	string str;
 	while(infile >> str){
 		unsigned found = str.find_last_of(",");
 		str = str.substr(found + 1);
 		string text;
 		text = ctext(str);
 		dict.update(text);
 	}
 	dict.finalize();
 	ofstream ofile;
 	ofile.open("dictionary");
 	dict.output(ofile);
 	return 0;
}
