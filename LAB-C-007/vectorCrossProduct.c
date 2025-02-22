#include <stdio.h>

struct vector {
    double x;
    double y;
    double z;
};

int main()
{
    struct vector vector_u;
    struct vector vector_v;

    printf("Enter u: ");
    scanf("%lf %lf %lf", &vector_u.x, &vector_u.y, &vector_u.z);

    printf("Enter v: ");
    scanf("%lf %lf %lf", &vector_v.x, &vector_v.y, &vector_v.z);

    double vector_crossProduct_x = (vector_u.y * vector_v.z) - (vector_u.z * vector_v.y); 
    double vector_crossProduct_y = (vector_u.z * vector_v.x) - (vector_u.x * vector_v.z);
    double vector_crossProduct_z = (vector_u.x * vector_v.y) - (vector_u.y * vector_v.x);

    printf("u x v = %.1lf %.1lf %.1lf\n", vector_crossProduct_x, vector_crossProduct_y, vector_crossProduct_z);

}