#include <stdio.h>

struct point {
    double x;
    double y;
};

typedef struct point Point;


double SquaredDist(Point p1, Point p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}


int isPointInRectangle(Point p, double x1, double y1, double x2, double y2) {
    return (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2);
}

int main() {
    
    Point p1 = {3.5, 4.0};
    Point p2 = {7.4, 1.0};

   
    double squaredDistance = SquaredDist(p1, p2);
    printf("Squared distance between points: %.2f\n", squaredDistance);

    
    if (isPointInRectangle(p1, 2.0, 2.0, 5.0, 5.0)) {
        printf("Point p1 is within the rectangle.\n");
    } else {
        printf("Point p1 is outside the rectangle.\n");
    }

    
    if (isPointInRectangle(p2, 2.0, 2.0, 5.0, 5.0)) {
        printf("Point p2 is within the rectangle.\n");
    } else {
        printf("Point p2 is outside the rectangle.\n");
    }

    return 0;
}