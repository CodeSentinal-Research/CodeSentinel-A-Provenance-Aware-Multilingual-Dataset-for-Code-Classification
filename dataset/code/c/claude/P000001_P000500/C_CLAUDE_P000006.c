void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;  // write through pointer
    *b = temp;  // write through pointer
}
