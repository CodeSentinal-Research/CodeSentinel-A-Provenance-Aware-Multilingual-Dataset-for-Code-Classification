function calculateGrade(marks) {
    if (marks < 0 || marks > 100) {
        return "Invalid input. Marks should be between 0 and 100.";
    } else if (marks >= 90) {
        return "A";
    } else if (marks >= 80) {
        return "B";
    } else if (marks >= 70) {
        return "C";
    } else if (marks >= 60) {
        return "D";
    } else {
        return "F";
    }
}