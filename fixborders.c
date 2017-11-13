#include <stdio.h>
#include <stdlib.h>

void printArray(int pixels[]) {
    // only prints arrays with exactly 100 elements because I’m lazy
    for (int i=0; i<100; i+=10) {
    printf("%3d, %3d, %3d, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", pixels[i], pixels[i+1], pixels[i+2], 
            pixels[i+3], pixels[i+4], pixels[i+5], pixels[i+6], pixels[i+7], pixels[i+8], pixels[i+9]);
    }
}

int main () {
    float tweaks[] = {1.1, 0.9};
    int pixels[100];
    for (int i=0; i<100; i++) {
        pixels[i] = rand() % 256;
    }
    printf("Before\n");
    printArray(pixels);
    for (int i=0; i<sizeof(tweaks)/sizeof(float); i++) {
        for (int j=0; j<100; j+=10) {
            pixels[j+i] *= tweaks[i];
        }
    }
    printf("\nAfter\n");
    printArray(pixels);
    return 0;
}
