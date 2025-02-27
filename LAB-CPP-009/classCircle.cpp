#include <iostream>
// #include <iomanip>
#include <cmath>

using namespace std;

typedef struct _point {
    double xPosition;
    double yPosition;
} point;

class Circle 
{
    private:
        point center;
        double radius;

    public:
        // CONSTRUCTOR:
        Circle(point constructCirclePoint, double constructCircleRadius) 
        {   
            center.xPosition = constructCirclePoint.xPosition;
            center.yPosition = constructCirclePoint.yPosition;
            radius = constructCircleRadius;
        }

        // CLASS METHODS:
        double distanceFromCenter(point pt) 
        {
            return sqrt(pow(center.xPosition - pt.xPosition, 2) + pow(center.yPosition - pt.yPosition, 2));
        }

        double area()
        {
            return M_PI * pow(radius, 2);
        }

        int contains(point pt) 
        {
            if(pow((pt.xPosition - center.xPosition), 2) + pow((pt.yPosition - center.yPosition), 2) <= (radius * radius))
                return 1;
            else
                return 0; 
        }

};

int main()
{
    Circle objectTest({1, 2}, 3);
    std::cout << objectTest.area() << " " << objectTest.contains({99 , 0.1}) << " " << objectTest.distanceFromCenter({4, 5});
}