function calculateGrade(marks) {
    if (marks >= 90) return 'A';
    if (marks >= 80) return 'B';
    if (marks >= 70) return 'C';
    if (marks >= 60) return 'D';
    if (marks >= 50) return 'E';
    return 'F';
}

module.exports = { calculateGrade };