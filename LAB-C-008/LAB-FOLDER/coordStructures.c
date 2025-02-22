#include <stdio.h>
#include <math.h>

struct Point 
{
    double point_x;
    double point_y;
};

int main()
{
    int num_Points = 0;
    printf("Number of Points: ");
    scanf("%d", &num_Points);   

    struct Point points[num_Points];

    for(int i = 0; i < num_Points; i++) {
        double cord_x = 0, cord_y = 0;

        printf("P%d.X: ", i+1);
        scanf("%lf", &cord_x);
        points[i].point_x = cord_x;
        
        printf("P%d.Y: ", i+1);
        scanf("%lf", &cord_y);
        points[i].point_y = cord_y;
    }

    printf("Length:\n");

    for(int i = 0; i < num_Points - 1; i++) {
        double dX = points[i].point_x - points[i + 1].point_x;
        double dY = points[i].point_y - points[i + 1].point_y;
        double length = sqrt((dX * dX) + (dY * dY));
        printf("Length from P%d(%.2f, %.2f) to P%d(%.2f, %.2f) is %.2f\n", i+1, points[i].point_x, points[i].point_y, i+2, points[i+1].point_x, points[i+1].point_y, length);
    }
}