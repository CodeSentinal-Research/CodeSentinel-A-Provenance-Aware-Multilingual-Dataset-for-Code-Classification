
class Solution:
    def calculatePercentage(self, marks_obtained: float, total_marks: float) -> float:
        if total_marks == 0:
            return 0.0
        return (marks_obtained / total_marks) * 100.0
