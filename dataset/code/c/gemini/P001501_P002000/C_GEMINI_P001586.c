#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpTiles2(const void* a, const void* b) {
    int* t1 = *(int**)a;
    int* t2 = *(int**)b;
    return t1[0] - t2[0];
}

int maximumWhiteTiles(int** tiles, int tilesSize, int* tilesColSize, int carpetLen) {
    qsort(tiles, tilesSize, sizeof(int*), cmpTiles2);
    int ans = 0, cover = 0, r = 0;

    for (int l = 0; l < tilesSize; l++) {
        while (r < tilesSize && tiles[l][0] + carpetLen > tiles[r][1]) {
            cover += tiles[r][1] - tiles[r][0] + 1;
            r++;
        }
        if (r < tilesSize && tiles[l][0] + carpetLen > tiles[r][0]) {
            ans = MAX(ans, cover + (tiles[l][0] + carpetLen - tiles[r][0]));
        } else {
            ans = MAX(ans, cover);
        }
        cover -= (tiles[l][1] - tiles[l][0] + 1);
    }
    return ans;
}