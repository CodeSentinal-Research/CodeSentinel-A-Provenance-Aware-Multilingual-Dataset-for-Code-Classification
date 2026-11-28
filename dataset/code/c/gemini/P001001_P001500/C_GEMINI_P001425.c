char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    for (int i = 0; i < pathsSize; i++) {
        char* dest = paths[i][1];
        int hasNext = 0;
        for (int j = 0; j < pathsSize; j++) {
            int match = 1;
            for (int k = 0; dest[k] || paths[j][0][k]; k++) {
                if (dest[k] != paths[j][0][k]) { match = 0; break; }
            }
            if (match) { hasNext = 1; break; }
        }
        if (!hasNext) return dest;
    }
    return "";
}