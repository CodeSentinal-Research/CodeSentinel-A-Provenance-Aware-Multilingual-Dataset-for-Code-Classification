function calculatePercentage(marksObtained, totalMarks) {
    if (totalMarks === 0) return 0.0;
    return (marksObtained / totalMarks) * 100.0;
}

module.exports = { calculatePercentage };
