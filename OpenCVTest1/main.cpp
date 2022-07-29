#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void main()
{
     //读取图片（使用图片的绝对路径，参考自己的图所在目录）
    string path = "C:\\Users\\Administrator\\Desktop\\1.jpg";
    Mat srcImg = imread(path);

    if (srcImg.empty()) {
        cout << "could not load image..." << endl;
    }

    imshow("Test2", srcImg);
    cout << srcImg.size() << endl;

    /////////////////////////////绘图////////////////////////////
    
    //背景
    Mat BackImg(512, 512, CV_8UC3, Scalar(255, 255, 255));
    //圆形（圆心，半径，颜色，（是否填充））
    circle(BackImg, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);
    //矩形(左上，右下，颜色，粗细）
    rectangle(BackImg, Point(130, 266), Point(382, 286), Scalar(255, 0, 0), 2);
    //线(左上，右下，颜色，粗细）
    line(BackImg, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 4);
    //文字(左下，字体，字号，颜色）
    putText(BackImg, "Knell", Point(130, 296), FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 0, 0));
    imshow("Img", BackImg);

    ////调整大小
    Mat resizeImg;
    resize(srcImg, resizeImg, Size(), 0.5, 0.5);
    imshow("resize", resizeImg);

    ////裁剪大小
    Mat ImgCrop;
    Rect roi(100, 100, 300, 250);
    ImgCrop = srcImg(roi);
    imshow("ROI", ImgCrop);

    //////////////////////// 显示灰度图////////////////////////////
    Mat Gray;
    cvtColor(srcImg, Gray, COLOR_RGB2GRAY);
    imshow("G", Gray);

    ////模糊
    Mat dst1, dst2, dst3;
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));//模糊度

        //腐蚀
    erode(srcImg, dst1, element);
    imshow("erode", dst1);

        //膨胀
    dilate(srcImg, dst2, element);
    imshow("dilate", dst2);

        //滤波
    blur(srcImg, dst3, Size(7,7));
    imshow("blur", dst3);

    //边缘检测
    Mat dst4,dst5;
    blur(srcImg, dst4, Size(12, 12));
    Canny(dst4, dst5, 7, 10, 3);//最小阀值/最大阀值/sobel算子
    imshow("canny", dst5);

    //////////////////////////Video///////////////////////////
    string path1 = "d:\\jianpiandownload\\某科学的超电磁炮第4集.mp4";
    VideoCapture cap(path1);
    Mat Img;

    while (true) {
        cap.read(Img);
        imshow("image", Img);
        waitKey(5);
    }

    // 等待任意按键按下，不添加此语句图片会一闪而过
    waitKey(0);
}
