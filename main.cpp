#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    int length;
    //char * buffer;
    ifstream is(argv[1], ios::binary);
    ofstream os("test.jpg", ios::binary);

    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(is), {});
    
    for(int i(0); i < buffer.size(); i++){
        buffer[i] *= (char)1.3;
    }

    std::copy(
        buffer.begin(),
        buffer.end(),        
        std::ostreambuf_iterator<char>(os)
    );
    
    return 0;
}