

#include <iostream>
#include <string>
#include "GeneralHash/GeneralHashFunctions.h"
#include <stdlib.h>
#include <map>

using namespace std;


int analyze_file(FILE* fp, std::map <string, unsigned int> &labelCount);
int count_min_insert(unsigned int** hashMatrix, std::string* word, unsigned int d, unsigned int m);
unsigned int count_min_query(unsigned int** hashMatrix, std::string* word, unsigned int d, unsigned int m);
unsigned hash_function(int i, std::string const keyPtr);
int improved_count_min_insert(unsigned int** hashMatrix, std::string* word, unsigned int d, unsigned int m);
int space_saving_insert(std::map<string, unsigned int>* labelCount, std::string* label, unsigned int listSize);

