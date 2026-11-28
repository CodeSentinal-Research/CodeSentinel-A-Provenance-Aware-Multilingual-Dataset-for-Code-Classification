int totalFruit(int* fruits, int fruitsSize) {
    int count[100005] = {0};
    int distinct = 0, l = 0;

    for (int r = 0; r < fruitsSize; r++) {
        if (count[fruits[r]]++ == 0) distinct++;
        if (distinct > 2) {
            if (--count[fruits[l]] == 0) distinct--;
            l++;
        }
    }
    return fruitsSize - l;
}