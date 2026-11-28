void convertSeconds(int totalSeconds, int* hours, int* minutes, int* seconds) {
    *hours = totalSeconds / 3600;  // write through pointer
    int rem = totalSeconds % 3600;
    *minutes = rem / 60;  // write through pointer
    *seconds = rem % 60;  // write through pointer
}
