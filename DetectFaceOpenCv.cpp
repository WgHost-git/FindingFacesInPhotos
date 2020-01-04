#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;

int main()
{
    Mat image;
    image = imread("d:/1.jpg", IMREAD_COLOR); // картинка

    //resize(image, image, cv::Size(), 0.30, 0.30); // изменение размера картинки 0.30 - это 30% от размера картинки исходной

    namedWindow("window1", 1); 
    imshow("window1", image);

    // Load Face cascade (.xml file) (Нагрузочный Каскад граней (.XML-файл))
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_alt2.xml");  // Надо скопировать из opencv\build\etc\haarcascades\ в папку с проектом!!!

    if (!face_cascade.load("haarcascade_frontalface_alt2.xml")) { cout << "--(!)Error loading face cascade\n"; return -1; }; // Проверка загрузки каскада
    //if (!eyes_cascade.load(eyes_cascade_name)) { printf("--(!)Error loading eyes cascade\n"); return -1; };

    // Детект лица
    vector<Rect> faces;
    face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(20, 30));

titled 
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;
​
int main()
{
    Mat image = imread("d:/1.jpg", IMREAD_COLOR); // картинка
​
    //resize(image, image, cv::Size(), 0.30, 0.30); // изменение размера картинки 0.30 - это 30% от размера картинки исходной
​
    namedWindow("window1", 1); 
    imshow("window1", image);
​
    // Load Face cascade (.xml file) (Нагрузочный Каскад граней (.XML-файл))
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_alt2.xml");// Надо скопировать из opencv\build\etc\haarcascades\ в папку с проектом!!!
​
    if (!face_cascade.load("haarcascade_frontalface_alt2.xml")) { cout << "--(!)Error loading face cascade\n"; return -1; }; // Проверка загрузки каскада
	
    // Детект лица
    vector<Rect> faces;
    face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	/*
	face_cascade.detectMultiScale(image, #scaleFactor=1.2, #minNeighbors=5, minSize=(30, 30))- Это функция поиска лиц.
    		scaleFactor=1.2 — Параметр, указывающий, на сколько уменьшается размер изображения при каждом масштабе изображения. 
			Он используется для создания масштабной пирамиды.
    		minNeighbors=5 — Параметр, указывающий, сколько соседей должен иметь каждый прямоугольник-кандидат для его сохранения. 
			(чем выше , тем больше точность).
    		minSize=(20, 20) — Минимально возможный размер объекта. Объекты меньшего размера игнорируются. 
	*/
​
    // Нарисовать круги на обнаруженных гранях. Можно нарисовать что угодно
    for (int i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
        ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(0, 0, 255), 1, LINE_AA, 0);
    }
    imshow("Detected Face", image);
​
    waitKey(0);
    return 0;
}

    // Нарисовать круги на обнаруженных гранях
    for (int i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
        ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(0, 0, 255), 1, LINE_AA, 0);
    }
    imshow("Detected Face", image);

    waitKey(0);
    return 0;
}