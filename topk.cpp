#include <iostream>
#include <vector>
#include <queue> // std::priority_queue
#include <fstream>
#include <sstream>      // std::stringstream

using namespace std;

struct comparator {
    bool operator()(pair<long long,long long> i, pair<long long,long long> j) {
        return i.second > j.second;
    }
};

int main(int argc, const char * argv[]) {
    priority_queue< pair<long long,long long>, vector<pair<long long,long long> >, comparator> mypq;
    int k = 10;
    long long mySum;
    long long keys[21];
    string line;
    
    /****** processing **********/
    const char* FILENAM = "/Users/haneen/Downloads/kaust/CS245/project2/binary_data.dat";
    ifstream ss(FILENAM,ios::binary);
   
     for (int j = 0; j < 50000000; j++) {
         ss.read((char*)&keys, 21*sizeof(long long));
        // get the specified columns (i, j)
        // sum them up
        mySum = keys[1];
        mySum += keys[4];
        mySum += keys[10];
        mySum += keys[17];

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
 
    return 0;
}
