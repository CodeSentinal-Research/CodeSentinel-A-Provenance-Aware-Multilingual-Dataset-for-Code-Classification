#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int grow, plant;
} Flower;

int cmpFlower(const void* a, const void* b) {
    return ((Flower*)b)->grow - ((Flower*)a)->grow;
}

int earliestFullBloom(int* plantTime, int plantTimeSize, int* growTime, int growTimeSize) {
    Flower* flowers = (Flower*)malloc(plantTimeSize * sizeof(Flower));
    for (int i = 0; i < plantTimeSize; i++) {
        flowers[i].grow = growTime[i];
        flowers[i].plant = plantTime[i];
    }
    qsort(flowers, plantTimeSize, sizeof(Flower), cmpFlower);

    int curPlantTime = 0, maxBloomTime = 0;
    for (int i = 0; i < plantTimeSize; i++) {
        curPlantTime += flowers[i].plant;
        maxBloomTime = MAX(maxBloomTime, curPlantTime + flowers[i].grow);
    }

    free(flowers);
    return maxBloomTime;
}