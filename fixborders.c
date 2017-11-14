#include <stdio.h>
#include <stdlib.h>

void printArray(int pixels[], int stride) {
    printf("%d \n", (sizeof(&pixels)/sizeof(int)));
    for (int i=0; i<(sizeof(pixels)/sizeof(int)); i+=stride) {
        for (int j=0; j<stride; j++) {
            printf("%4d", pixels[i+j]);
        }
        printf("\n");
    }
}

int main () {
    float tweaks[] = {1.1, 0.9};
    int pixels[100];
    int stride = 10;
    for (int i=0; i<100; i++) {
        pixels[i] = rand() % 256;
    }
    printf("Before\n");
    printArray(pixels, stride);
    for (int i=0; i<sizeof(tweaks)/sizeof(float); i++) {
        for (int j=0; j<100; j+=10) {
            pixels[j+i] *= tweaks[i];
        }
    }
    printf("\nAfter\n");
    printArray(pixels, stride);
    return 0;
}
