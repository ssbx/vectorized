

int c[4][4];

void
foo() {
    int i, j;

    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            c[i][j] = i*2;
        }
    }
}

int
main(int argc, char** argv) {
    foo();
    return 0;
}
