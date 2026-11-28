# problem title : Student Attendance Record
# A valid attendance record has fewer than two absences and no three consecutive lates.
s=input(); print("Yes" if s.count('A')<2 and 'LLL' not in s else "No")
