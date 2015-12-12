#include <iostream>
#include <vector>
#include <queue> // std::priority_queue
#include <fstream>
#include <sstream>      // std::stringstream
#include <sys/mman.h>
#include <string.h>

#define SIZE 50000000*21

using namespace std;

struct comparator {
    bool operator()(pair<unsigned int,long long> i, pair<unsigned int,long long> j) {
        return i.second > j.second;
    }
};

int main(int argc, const char * argv[]) {
    priority_queue< pair<unsigned int,long long>, vector< pair<unsigned int,long long> >, comparator > mypq;
    int k = 10;
    long long mySum;
    unsigned int keys[21];
    // unsigned int *keys = (unsigned int*)calloc(SIZE,sizeof(unsigned int));
    string line;
    
    /****** processing **********/
    const char* FILENAM = "/Users/haneen/Downloads/kaust/CS245/project2/binary_data_int.dat";
    ifstream ss(FILENAM,ios::binary);
    /*FILE* in = fopen(FILENAM, "rb");
    unsigned int *keys = (unsigned int*)mmap(
                                             0,
                                             SIZE * sizeof(unsigned int),
                                             PROT_READ,
                                             MAP_FILE | MAP_PRIVATE,
                                             fileno(in),
                                             0
                                             );
    fclose(in);
    */
    //   ss.read((char*)keys, SIZE*sizeof(unsigned int));
    
    for (int j = 0; j < 50000000; j++) {
        //    memcpy(keys, buf+j*21, 21 * sizeof(unsigned int));
        
        mySum = 0;
        ss.read((char*)&keys, 21*sizeof(unsigned int));
        
        // get the specified columns (i, j)
        // sum them up
        for (int i = 1; i < 3; i++) {
          //  mySum += keys[i+j*21];
            mySum += keys[i];
        }
        
        // add them to the min heap
        if (mypq.size() < k ) {
            mypq.push( make_pair(keys[0], mySum) );
        }
        
        if (mypq.size() >= k && mypq.top().second < mySum) {
            mypq.pop();
            mypq.push( make_pair(keys[0], mySum));
        }
    }
    
    while (!mypq.empty()) {
        cout << "key " << mypq.top().first << " mySum " << mypq.top().second << endl;
        mypq.pop();
    }
    
    // delete[] memblock;
    //munmap(keys, SIZE * sizeof(unsigned int));
    
    
    return 0;
}
