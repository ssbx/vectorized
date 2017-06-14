#include <stdio.h>

struct mat4 { float v[4][4]; };

void
multMat4(
        struct mat4* __restrict__ m1,
        struct mat4* __restrict__ m2,
        struct mat4* __restrict__ m3) {

    int x, y, z, res;

    for (x=0; x<4; x++) {
        for (y=0; y<4; y++) {
            res = 0;
            for (z=0; z<4; z++) {
                res += m1->v[x][z] * m2->v[z][y];
            }
            m3->v[x][y] = res;
        }
    }
}

int
main(int argc, char** argv) {
    int i;

    struct mat4 result;
    struct mat4 m1 = {{
        {2.0f,9.0f,8.0f,1.0f},
        {0.0f,9.0f,1.0f,0.0f},
        {0.0f,1.0f,0.0f,0.0f},
        {1.0f,0.0f,0.0f,0.0f}
    }};

    struct mat4 m2= {{
        {1.0f,0.0f,0.0f,0.0f},
        {0.0f,1.0f,0.0f,0.0f},
        {0.0f,0.0f,1.0f,0.0f},
        {0.0f,0.0f,0.0f,1.0f}
    }};

    multMat4(&m1, &m2, &result);

    for (i=0; i< 4; i++) {
        printf("%.0f %.0f %.0f %.0f\n", result.v[i][0], result.v[i][1], result.v[i][2], result.v[i][3]);
    }

    return 0;
}
