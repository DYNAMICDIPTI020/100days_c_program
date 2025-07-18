#include <stdio.h>

// Function to find the inverse of a 2x2 matrix
int inverse2x2(float B[2][2], float Binv[2][2]) {
    float det = B[0][0]*B[1][1] - B[0][1]*B[1][0];
    if(det == 0) {
        return 0; // Inverse not possible
    }
    Binv[0][0] =  B[1][1]/det;
    Binv[0][1] = -B[0][1]/det;
    Binv[1][0] = -B[1][0]/det;
    Binv[1][1] =  B[0][0]/det;
    return 1;
}

// Function to multiply two 2x2 matrices
void multiply2x2(float A[2][2], float B[2][2], float result[2][2]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            result[i][j] = 0;
            for(int k=0;k<2;k++) {
                result[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main() {
    float A[2][2], B[2][2], Binv[2][2], result[2][2];
    printf("Enter elements of 2x2 Matrix A:\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%f", &A[i][j]);
    printf("Enter elements of 2x2 Matrix B:\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%f", &B[i][j]);
    if(!inverse2x2(B, Binv)) {
        printf("Matrix B ka inverse nahi nikal sakte (determinant zero hai), division possible nahi hai.\n");
        return 1;
    }
    multiply2x2(A, Binv, result);
    printf("Matrix Division (A / B) ka result:\n");
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            printf("%f ", result[i][j]);
        printf("\n");
    }
    return 0;
}