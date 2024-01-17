
#include <stdio.h>

void mirrorXAxis(int matrix[2][2], int point[2]) {
    int result[2];

    result[0] = matrix[0][0] * point[0] + matrix[0][1] * point[1];
    result[1] = matrix[1][0] * point[0] + matrix[1][1] * point[1];

    printf("Original Point: (%d, %d)\n", point[0], point[1]);
    printf("Mirrored Point: (%d, %d)\n", result[0], result[1]);
}

int main() {
    int reflectionMatrix[2][2] = {{1, 0}, {0, -1}};
    int pointToMirror[2] = {3, 4};  // You can change the coordinates here

    mirrorXAxis(reflectionMatrix, pointToMirror);

    return 0;
}
