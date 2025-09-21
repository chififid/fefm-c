#include <stdio.h>

void check_circle_intersection(float x1, float y1, float r1, float x2, float y2, float r2) {
    float distance_squared, sum_radii, diff_radii_abs;
    float epsilon = 0.00001;

    distance_squared = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    sum_radii = r1 + r2;
    diff_radii_abs = (r1 > r2) ? (r1 - r2) : (r2 - r1);

    if (distance_squared > (sum_radii * sum_radii) + epsilon) {
        printf("Do not intersect\n");
    } else if ( ( (distance_squared - (sum_radii * sum_radii)) < epsilon && (distance_squared - (sum_radii * sum_radii)) > -epsilon ) || (distance_squared < epsilon && diff_radii_abs < epsilon) ) { 
        printf("Touch\n");
    } else {
        printf("Intersect\n");
    }
}

int main() {
    check_circle_intersection(0, 0, 1, 0, 2, 1);
    check_circle_intersection(0, 0, 1, 1, 1, 1);
    check_circle_intersection(0, 0, 3, 5, 5, 4);
    check_circle_intersection(0, 0, 4, 5, 5, 4);
    check_circle_intersection(-2, 1, 4, 2, 4, 1);
    return 0;
}
