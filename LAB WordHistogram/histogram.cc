#include "histogram.h"

using namespace std;

void WordHistogram::makeHistogram() {
        int moveon=0;
        ifstream InputFileObject(filename,ios::in);
        string temp;
        while(InputFileObject >> temp) {
            moveon=0;
            if (size==0) {
                my_array[0].word = temp;
                my_array[0].count=1;
                size =1;
            } else {
                for (int i = 0; i < size; ++i) {
                    if (my_array[i].word==temp) {
                        my_array[i].count++;
                        moveon =1;
                        break;
                    } 
                }
                if (moveon==0)
                {
                size++;
                my_array[size-1].word=temp;
                my_array[size-1].count=1;
                }
            }
        }
    };
    void WordHistogram::sortAlphaHistogram() {
        WordUnit temp;
        for (int i = 1; i < size; i++) {
            for (int j = i; j > 0; j--) {
                if (my_array[j].word<my_array[j-1].word) {
                    temp = my_array[j];
                    my_array[j] = my_array[j - 1];
                    my_array[j - 1] = temp;
                } else {
                    j = -1;
                }
            }
        }
    };
    void WordHistogram::sortFreqHistogram() {
        WordUnit temp;
        for (int i = 1; i < size; i++) {
            for (int j = i; j > 0; j--) {
                if (my_array[j].count<my_array[j-1].count) {
                    temp = my_array[j];
                    my_array[j] = my_array[j - 1];
                    my_array[j - 1] = temp;
                } else {
                    j = -1;
                }
            }
        }
    };
    void WordHistogram::exportHistogram(string filename) {
        ofstream YourOutputFileObject(filename, ios::out);
        for (int i = 0; i < size; ++i) {
            YourOutputFileObject<<my_array[i].word<<"  ";
            YourOutputFileObject<<my_array[i].count<<endl;
        }
    };

WordHistogram::WordHistogram(string name)
{
    size=0;
    filename = name;
}


}