#include "histogram.h"

using namespace std;
    
int main()
{
    string filename;
    cout << "Please input the file name" <<endl;
    //cin >> filename;
    //I will try to open the file to see if it exists


    //You will need to open this in your member functions
    //later to read in the data
    //ifstream InputFileObject(filename,ios::in);

    //if (!InputFileObject) { //i.e. if not valid
      //  cout << "The file you specified does not exist!!" << endl;
    //} else { // if successful opened the file
      //  InputFileObject.close(); //close the file so other M.F. can open

        WordHistogram bookHistogram("ru");

        bookHistogram.makeHistogram();

        bookHistogram.sortAlphaHistogram();

        bookHistogram.exportHistogram("histo_alpha_"+filename);

        bookHistogram.sortFreqHistogram();

        bookHistogram.exportHistogram("histo_freq_"+filename);

    //}
}
