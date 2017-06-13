#include <stdio.h>

int mat1[4][4] = {
    {2,0,0,1},
    {0,9,1,0},
    {0,1,0,0},
    {1,0,0,0}
};

int mat2[4][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
};

int result[4][4];

void
foo() {
    int x, y, z, res;

    for (x=0; x<4; x++) {
        for (y=0; y<4; y++) {
            res = 0;
            for (z=0; z<4; z++) {
                res += mat1[x][z] * mat2[z][y];
            }
            result[x][y] = res;
        }
    }
}

int
main(int argc, char** argv) {
    int i;

    foo();

    for (i=0; i< 4; i++) {
        printf("%d %d %d %d\n", result[i][0],result[i][1], result[i][2], result[i][3]);
    }
    return 0;
}
