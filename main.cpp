#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace cv;
using namespace std;

/*int main(int argc, char** argv)
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    image = image + (uchar)30;
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    std::cout << image.data << std::endl;
    return 0;
}*/

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