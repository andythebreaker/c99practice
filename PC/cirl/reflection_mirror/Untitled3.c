#include <stdio.h>

void mirrorYLine(int point[2], int yLine) {
    // Reflection matrix for reflecting across y-axis
    int reflectionMatrix[2][2] = {{1, 0}, {0, -1}};

    // Translate the line to the origin
    point[1] -= yLine;

    // Apply the reflection transformation
    int result[2];
    result[0] = reflectionMatrix[0][0] * point[0] + reflectionMatrix[0][1] * point[1];
    result[1] = reflectionMatrix[1][0] * point[0] + reflectionMatrix[1][1] * point[1];

    // Translate the result back
    result[1] += yLine;

    printf("Original Point: (%d, %d)\n", point[0], point[1] + yLine);
    printf("Mirrored Point: (%d, %d)\n", result[0], result[1]);
}

int main() {
    int pointToMirror[2] = {30, 60};  // You can change the coordinates here
    int reflectionLine = 50;         // The reflection line y = 50

    mirrorYLine(pointToMirror, reflectionLine);

    return 0;
}
