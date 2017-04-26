
#include "string.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class WordUnit
{
public:
    string word;
    int count;
};

class WordHistogram
{
	public: 
		WordHistogram(string filename);
	public:	

    string filename;
    WordUnit my_array [10000];
    int size;
	void makeHistogram();
	void sortAlphaHistogram();
	void sortFreqHistogram();
	void exportHistogram(string filename);
};