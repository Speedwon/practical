#include <stdio.h>
#include <math.h>
int circle_intersections(double x1, double y1, double r1, double x2, double y2, double r2) {
   
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (d == 0 && r1 == r2) {
        return -1; 
    } else if (d > r1 + r2 || d < fabs(r1 - r2)) {
        return 0; // No intersections
    } else if (d == r1 + r2 || d == fabs(r1 - r2)) {
        return 1; //
    } else {
        return 2; 
    }
}
int main() {
    double x1, y1, r1, x2, y2, r2;
    
    printf("Enter x1, y1, r1, x2, y2, r2: ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);

    int result = circle_intersections(x1, y1, r1, x2, y2, r2);

    // Output the result
    printf("Number of intersection points: %d\n", result);

    return 0;
}
