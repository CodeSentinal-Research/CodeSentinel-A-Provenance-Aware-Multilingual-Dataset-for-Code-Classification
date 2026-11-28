def check_attendance(student_records):
    if 'A' in student_records or 'L' in student_records:
        print('Yes')
    else:
        print('No')

if __name__ == "__main__":
    student_records = input()
    check_attendance(student_records)