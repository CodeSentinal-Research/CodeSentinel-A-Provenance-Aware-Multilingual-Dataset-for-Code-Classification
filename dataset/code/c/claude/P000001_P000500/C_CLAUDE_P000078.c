void convertDays(int totalDays, int* years, int* weeks, int* days) {
    *years = totalDays / 365;  // write through pointer
    int rem = totalDays % 365;
    *weeks = rem / 7;  // write through pointer
    *days = rem % 7;  // write through pointer
}
