double calculatePercentage(double marksObtained, double totalMarks) {
    if (totalMarks == 0.0) return 0.0;
    return (marksObtained / totalMarks) * 100.0;
}
