#include <iostream>
#include <fstream>
#include <sstream>      // std::stringstream

using namespace std;

int main(int argc, const char * argv[]) {    
    long long keys[21];
    int i,j;
    char c;
    string line;
    
    /******testing**********/
    //data input
    ifstream infile("/Users/haneen/Downloads/kaust/CS245/project2/data-c20.txt");
    // binary data input
    const char* FILENAM = "/Users/haneen/Downloads/kaust/CS245/project2/binary_data.dat";
    ofstream outfile(FILENAM,ios::binary);
    
    // while (!infile.eof()) {
    for (j = 0; j < 50000000; j++) {
        if (!getline(infile, line) ) break;
        istringstream ss(line);
        // read line from file
        for (i = 0; i < 21; i++) {
            ss >>  keys[i] >> c;
            outfile.write((char*)&keys[i], sizeof(long long));
        }
    }
    //   }
    
    outfile.close();
    
    return 0;
} 