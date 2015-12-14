#include <iostream>
#include <vector>
#include <queue> // std::priority_queue
#include <fstream>
#include <sstream>      // std::stringstream
#include <sys/mman.h>
#include <string.h>
#include <map>
#include <algorithm>

#define FACTOR 5000
#define SIZE FACTOR*21

using namespace std;

struct comparator {
    bool operator()(pair<long long, unsigned int> i, pair<long long, unsigned int> j) {
        return i.first > j.first;
    }
};

int main(int argc, const char * argv[]) {
    priority_queue< pair<long long, unsigned int>, vector< pair<long long, unsigned int> >, comparator > mypq;
    int k = 10;
    long long mySum;
    unsigned int keys[SIZE];
    string line;
    multimap<long long, unsigned int, greater<long long> > result;
    int columns[] = {1, 2};
    int n = 2;
    /****** processing **********/
    const char* FILENAM = "/Users/haneen/Downloads/kaust/CS245/project2/binary_data_int.dat";
    ifstream ss(FILENAM,ios::binary);
    int m = 0;
    for (int j = 0; j < 50000000; j++) {
        mySum = 0;
        if (j%FACTOR == 0) {
            m = 0; // the line offset, wrap up every time we read chunk from file
            ss.read((char*)&keys, SIZE*sizeof(unsigned int));
        }
        // get the specified columns (i, j)
        // sum them up
        for (int i = 0; i < n; i++) {
            mySum += keys[columns[i] + m*21];
        }
        
        // add them to the min heap
        if (mypq.size() < k ) {
            mypq.push( make_pair(mySum, keys[0 + m*21]) );
        }
        
        if (mypq.size() >= k && mypq.top().first < mySum) {
            mypq.pop();
            mypq.push( make_pair(mySum, keys[0 + m*21]));
        }
        m++;
    }

    // Sort the output in descending order
    while (!mypq.empty()) {
        result.insert( mypq.top() );
        mypq.pop();
    }
    
    // Output the results 
    cout << "Key\t\t" << "mySum" << endl;
    for (auto &p : result ) {

        cout << p.second << "\t" << p.first << endl;
    }
    return 0;
}
