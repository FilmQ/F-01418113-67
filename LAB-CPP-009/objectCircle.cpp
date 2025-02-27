#include <iostream>
// #include <string>
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
    point cinCirclePoint, cinPointToCheck;
    double cinRadius;

    std::cout << "Center of Circle: ";
    std::cin >> cinCirclePoint.xPosition >> cinCirclePoint.yPosition;

    std::cout << "Radius of Circle: ";
    std::cin >> cinRadius;

    std::cout << "Point to Check: ";
    std::cin >> cinPointToCheck.xPosition >> cinPointToCheck.yPosition;

    Circle circleObject(cinCirclePoint, cinRadius);
    
    std::cout << "Area of Circle is " << circleObject.area() << std::endl;
    std::cout << "Distance from Center to Point (" << cinPointToCheck.xPosition << ", " << cinPointToCheck.yPosition << ") is " << circleObject.distanceFromCenter(cinPointToCheck) << std::endl; 
    
    if(circleObject.contains(cinPointToCheck))
        std::cout << "This circle contains this point." << std::endl;
    else
        std::cout << "This point is not in this circle." << std::endl;

}

