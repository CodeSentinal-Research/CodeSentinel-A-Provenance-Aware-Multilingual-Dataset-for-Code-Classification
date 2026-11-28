def search_courses_by_instructor(records, instructor):
    instructor_courses = [course for course in records if instructor in course.get('instructors', [])]
    return instructor_courses

class Course:
    def __init__(self, instructors, **kwargs):
        self.instructors = instructors

def main():
    records = [Course(instructors=['John', 'Paul']), Course(instructors=['Mary'])]
    instructor = input("Enter the instructor name: ")
    results = search_courses_by_instructor(records, instructor)
    for course in results:
        print(course.instructors)

if __name__ == "__main__":
    main()