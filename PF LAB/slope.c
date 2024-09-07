#include <stdio.h>

int main() {
    float x1, y1, x2, y2, slope;

    
    x1 = 5;
    y1 = 4;
    x2 = 3;
    y2 = 2;

    
    slope = (y2 - y1) / (x2 - x1);

  
    printf("The slope of the line passing through points (%.0f,%.0f) and (%.0f,%.0f) is %.3f.\n", x1, y1, x2, y2, slope);

    return 0;
}