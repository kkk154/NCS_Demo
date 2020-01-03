#include <iostream>
#include <opencv2/opencv.hpp>
#include <mvnc.h>

// somewhat arbitrary buffer size for the device name
#define NAME_SIZE 100

bool ncsLoadData(){
    bool ret = false;
    //load ops
    return ret;
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    mvncStatus retCode;
    void *deviceHandle;
    int cameraDevice=0;
    char devName[NAME_SIZE];
    cv::Mat capImage;

    cv::VideoCapture capture = cv::VideoCapture(cameraDevice);
    bool res = capture.open(cameraDevice);
    if(!res){
        std::cout<<"Open Camera failed"<<std::endl;
        exit(-1);
    }

    retCode = mvncGetDeviceName(0, devName, NAME_SIZE);
    if (retCode != MVNC_OK)
    {   // failed to get device name, maybe none plugged in.
        std::cout<<"Error - No NCS devices found.\n";
        std::cout<<"mvncStatus value: "<<retCode<<std::endl;
        exit(-1);
    }

    // Try to open the NCS device via the device name
    retCode = mvncOpenDevice(devName, &deviceHandle);
    if (retCode != MVNC_OK)
    {   // failed to open the device.
        std::cout<<"Error - Could not open NCS device.\n";
        std::cout<<"mvncStatus value: "<<retCode<<std::endl;
        exit(-1);
    }

    // deviceHandle is ready to use now.
    // Pass it to other NC API calls as needed and close it when finished.
    printf("Hello NCS! Device opened normally.\n");

    //load net param
    ncsLoadData();

    //capture image
    while (true)
    {
        //读取一帧图像
        capture.read(capImage);
        if(capImage.empty()){
            continue;
        }
        imshow("Win7x64",capImage);
        //Esc
        if (cv::waitKey(1) == 27){
            break;
        }
    }

    retCode = mvncCloseDevice(deviceHandle);
    deviceHandle = NULL;
    if (retCode != MVNC_OK)
    {
        std::cout<<"Error - Could not open NCS device.\n";
        std::cout<<"mvncStatus value: "<<retCode<<std::endl;
        exit(-1);
    }

    std::cout<<"Goodbye NCS!  Device Closed normally.\n";
    std::cout<<"NCS device working.\n";

    return 0;
}
