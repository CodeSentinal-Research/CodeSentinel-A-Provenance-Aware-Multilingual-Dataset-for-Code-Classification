import json
import os
import random


SUBJECTS = [
    {"name": "Data Structures", "slug": "dsa"},
    {"name": "Algorithms", "slug": "algorithms"},
    {"name": "DBMS", "slug": "dbms"},
    {"name": "Operating Systems", "slug": "os"},
    {"name": "Computer Networks", "slug": "cn"},
    {"name": "Python", "slug": "python"},
    {"name": "Java", "slug": "java"},
]


QUESTION_PATTERNS = [
    {
        "id": "sum_even",
        "input_format": "The first line contains N. The second line contains N space-separated integers.",
        "output_format": "Print the sum of all even integers.",
        "description": "Given the recorded values for {topic}, compute the sum of all even values to produce the monitoring score.",
    },
    {
        "id": "max_gap",
        "input_format": "The first line contains N. The second line contains N space-separated integers.",
        "output_format": "Print the difference between the maximum and minimum value.",
        "description": "The lab stores multiple readings for {topic}. Print the gap between the highest and lowest reading.",
    },
    {
        "id": "count_threshold",
        "input_format": "The first line contains N and X. The second line contains N space-separated integers.",
        "output_format": "Print how many values are greater than or equal to X.",
        "description": "Count how many entries in the {topic} dataset reach the safety threshold X.",
    },
    {
        "id": "reverse_words",
        "input_format": "A single line contains a phrase with lowercase words separated by spaces.",
        "output_format": "Print the words in reverse order.",
        "description": "Reverse the sequence of tokens in the {topic} message without changing the characters inside each word.",
    },
    {
        "id": "vowel_count",
        "input_format": "A single line contains a lowercase string.",
        "output_format": "Print the number of vowels in the string.",
        "description": "The {topic} logger emits a lowercase tag. Count how many vowels appear in the tag.",
    },
    {
        "id": "rotate_left",
        "input_format": "The first line contains N and K. The second line contains N space-separated integers.",
        "output_format": "Print the array after rotating it to the left by K positions.",
        "description": "Rotate the {topic} sequence to the left by K steps and print the new order.",
    },
    {
        "id": "diagonal_diff",
        "input_format": "The first line contains N. The next N lines contain N space-separated integers.",
        "output_format": "Print the absolute difference between the two diagonal sums.",
        "description": "A square matrix models the {topic} state. Compute the absolute difference between its main and secondary diagonal sums.",
    },
    {
        "id": "frequency_peak",
        "input_format": "The first line contains N. The second line contains N space-separated integers.",
        "output_format": "Print the value that appears most often. If there is a tie, print the smallest value.",
        "description": "Find the most frequent value in the {topic} trace. Break ties by printing the smallest value.",
    },
    {
        "id": "prefix_total",
        "input_format": "The first line contains N and Q. The second line contains N space-separated integers. The third line contains Q 1-based indices.",
        "output_format": "Print Q space-separated prefix sums for the requested indices.",
        "description": "A controller asks for prefix totals from the {topic} stream. Print the prefix sum at each requested index.",
    },
    {
        "id": "pair_sum",
        "input_format": "The first line contains N and X. The second line contains N space-separated integers.",
        "output_format": "Print YES if any pair sums to X, otherwise print NO.",
        "description": "Determine whether any two measurements in the {topic} list add up to X.",
    },
]


SUBJECT_TOPICS = {
    "dsa": ["arrays", "linked lists", "stacks", "queues", "trees", "binary heaps", "graphs", "hash tables", "tries", "disjoint sets"],
    "algorithms": ["sorting", "searching", "dynamic programming", "greedy methods", "backtracking", "divide and conquer", "graph traversal", "shortest path", "minimum spanning tree", "branch and bound"],
    "dbms": ["normalization", "indexing", "transactions", "concurrency control", "ER modeling", "query optimization", "B+ trees", "joins", "SQL parsing", "recovery logs"],
    "os": ["process scheduling", "deadlock handling", "paging", "memory allocation", "file systems", "disk scheduling", "threads", "mutexes", "CPU bursts", "semaphores"],
    "cn": ["routing tables", "packet switching", "subnetting", "flow control", "TCP windows", "ARP cache", "DNS caching", "firewall rules", "switch ports", "network latency"],
    "python": ["lists", "dictionaries", "functions", "classes", "strings", "file parsing", "decorators", "iterators", "exceptions", "comprehensions"],
    "java": ["arrays", "collections", "inheritance", "interfaces", "strings", "threads", "exceptions", "generics", "streams", "classes"],
}


DIFFICULTY_LEVELS = ["Easy", "Medium", "Hard", "Medium"]


def _frequency_peak(numbers):
    counts = {}
    for num in numbers:
        counts[num] = counts.get(num, 0) + 1
    best_frequency = max(counts.values())
    return min(key for key, value in counts.items() if value == best_frequency)


def _prefix_total(numbers, indices):
    prefix = []
    running = 0
    for number in numbers:
        running += number
        prefix.append(running)
    return " ".join(str(prefix[index - 1]) for index in indices)


def _pair_sum(numbers, target):
    seen = set()
    for number in numbers:
        if target - number in seen:
            return "YES"
        seen.add(number)
    return "NO"


def _generate_numeric_list(seed_value, size=6):
    rng = random.Random(seed_value)
    return [rng.randint(1, 20) for _ in range(size)]


def _pattern_cases(pattern_id, subject_slug, topic, offset):
    seed_value = f"{subject_slug}-{topic}-{offset}"
    numbers = _generate_numeric_list(seed_value, size=6 + (offset % 3))
    threshold = 8 + (offset % 7)
    shift = (offset % len(numbers)) or 1
    target = numbers[0] + numbers[-1]
    matrix_size = 3 + (offset % 2)
    matrix_numbers = _generate_numeric_list(seed_value + "-matrix", size=matrix_size * matrix_size)
    matrix = []
    for row_index in range(matrix_size):
        start = row_index * matrix_size
        matrix.append(matrix_numbers[start : start + matrix_size])
    phrase = f"{topic.replace(' ', '_')} signal trace"
    text = f"{topic.replace(' ', '')}monitor"
    indices = [1, min(3, len(numbers)), len(numbers)]

    if pattern_id == "sum_even":
        sample = {"input": f"{len(numbers)}\n{' '.join(map(str, numbers))}\n", "output": str(sum(num for num in numbers if num % 2 == 0))}
        hidden_numbers = _generate_numeric_list(seed_value + "-hidden")
        hidden = {"input": f"{len(hidden_numbers)}\n{' '.join(map(str, hidden_numbers))}\n", "output": str(sum(num for num in hidden_numbers if num % 2 == 0))}
        return [sample], [hidden]
    if pattern_id == "max_gap":
        sample = {"input": f"{len(numbers)}\n{' '.join(map(str, numbers))}\n", "output": str(max(numbers) - min(numbers))}
        hidden_numbers = sorted(_generate_numeric_list(seed_value + "-hidden", size=8), reverse=True)
        hidden = {"input": f"{len(hidden_numbers)}\n{' '.join(map(str, hidden_numbers))}\n", "output": str(max(hidden_numbers) - min(hidden_numbers))}
        return [sample], [hidden]
    if pattern_id == "count_threshold":
        sample = {"input": f"{len(numbers)} {threshold}\n{' '.join(map(str, numbers))}\n", "output": str(sum(1 for num in numbers if num >= threshold))}
        hidden_numbers = _generate_numeric_list(seed_value + "-hidden", size=7)
        hidden_threshold = threshold + 1
        hidden = {"input": f"{len(hidden_numbers)} {hidden_threshold}\n{' '.join(map(str, hidden_numbers))}\n", "output": str(sum(1 for num in hidden_numbers if num >= hidden_threshold))}
        return [sample], [hidden]
    if pattern_id == "reverse_words":
        sample = {"input": f"{phrase}\n", "output": "trace signal " + topic.replace(" ", "_")}
        hidden_phrase = f"{subject_slug} secure lab"
        hidden = {"input": f"{hidden_phrase}\n", "output": "lab secure " + subject_slug}
        return [sample], [hidden]
    if pattern_id == "vowel_count":
        sample = {"input": f"{text}\n", "output": str(sum(1 for ch in text if ch in 'aeiou'))}
        hidden_text = f"{subject_slug}{topic.replace(' ', '')}"
        hidden = {"input": f"{hidden_text}\n", "output": str(sum(1 for ch in hidden_text if ch in 'aeiou'))}
        return [sample], [hidden]
    if pattern_id == "rotate_left":
        sample = {"input": f"{len(numbers)} {shift}\n{' '.join(map(str, numbers))}\n", "output": " ".join(map(str, numbers[shift:] + numbers[:shift]))}
        hidden_numbers = _generate_numeric_list(seed_value + "-hidden", size=5)
        hidden_shift = 2
        hidden = {"input": f"{len(hidden_numbers)} {hidden_shift}\n{' '.join(map(str, hidden_numbers))}\n", "output": " ".join(map(str, hidden_numbers[hidden_shift:] + hidden_numbers[:hidden_shift]))}
        return [sample], [hidden]
    if pattern_id == "diagonal_diff":
        matrix_input = "\n".join(" ".join(map(str, row)) for row in matrix)
        primary = sum(matrix[i][i] for i in range(matrix_size))
        secondary = sum(matrix[i][matrix_size - i - 1] for i in range(matrix_size))
        hidden_matrix = [[2, 5, 1], [7, 4, 3], [9, 8, 6]]
        hidden_input = "\n".join(" ".join(map(str, row)) for row in hidden_matrix)
        sample = {"input": f"{matrix_size}\n{matrix_input}\n", "output": str(abs(primary - secondary))}
        hidden = {"input": f"3\n{hidden_input}\n", "output": str(abs((2 + 4 + 6) - (1 + 4 + 9)))}
        return [sample], [hidden]
    if pattern_id == "frequency_peak":
        sample = {"input": f"{len(numbers)}\n{' '.join(map(str, numbers))}\n", "output": str(_frequency_peak(numbers))}
        hidden_numbers = [4, 4, 2, 2, 2, 7, 7]
        hidden = {"input": f"{len(hidden_numbers)}\n{' '.join(map(str, hidden_numbers))}\n", "output": "2"}
        return [sample], [hidden]
    if pattern_id == "prefix_total":
        sample = {"input": f"{len(numbers)} {len(indices)}\n{' '.join(map(str, numbers))}\n{' '.join(map(str, indices))}\n", "output": _prefix_total(numbers, indices)}
        hidden_numbers = _generate_numeric_list(seed_value + "-hidden", size=6)
        hidden_indices = [2, 4, 6]
        hidden = {"input": f"{len(hidden_numbers)} {len(hidden_indices)}\n{' '.join(map(str, hidden_numbers))}\n{' '.join(map(str, hidden_indices))}\n", "output": _prefix_total(hidden_numbers, hidden_indices)}
        return [sample], [hidden]
    if pattern_id == "pair_sum":
        sample = {"input": f"{len(numbers)} {target}\n{' '.join(map(str, numbers))}\n", "output": _pair_sum(numbers, target)}
        hidden_numbers = [3, 9, 11, 17, 21]
        hidden_target = 40
        hidden = {"input": f"{len(hidden_numbers)} {hidden_target}\n{' '.join(map(str, hidden_numbers))}\n", "output": _pair_sum(hidden_numbers, hidden_target)}
        return [sample], [hidden]
    raise ValueError(f"Unknown pattern: {pattern_id}")


def build_question(subject, topic, pattern, index):
    sample_cases, hidden_cases = _pattern_cases(pattern["id"], subject["slug"], topic, index)
    return {
        "subject_name": subject["name"],
        "subject_slug": subject["slug"],
        "question_code": f"{subject['slug'].upper()}-{index:03d}",
        "title": f"{topic.title()} Challenge {index:03d}",
        "description": pattern["description"].format(topic=topic),
        "difficulty": DIFFICULTY_LEVELS[(index - 1) % len(DIFFICULTY_LEVELS)],
        "input_format": pattern["input_format"],
        "output_format": pattern["output_format"],
        "sample_test_cases": sample_cases,
        "hidden_test_cases": hidden_cases,
        "tags": [topic, pattern["id"], subject["slug"]],
        "starter_code": "def solve():\n    pass\n\n\nif __name__ == '__main__':\n    solve()\n",
        "max_score": 20,
    }


def generate_question_bank():
    question_bank = []
    for subject in SUBJECTS:
        topics = SUBJECT_TOPICS[subject["slug"]]
        for index in range(100):
            topic = topics[index % len(topics)]
            pattern = QUESTION_PATTERNS[index % len(QUESTION_PATTERNS)]
            question_bank.append(build_question(subject, topic, pattern, index + 1))
    return question_bank


def export_question_bank(export_directory, question_bank=None):
    os.makedirs(export_directory, exist_ok=True)
    question_bank = question_bank or generate_question_bank()
    target_path = os.path.join(export_directory, "question_bank.json")
    with open(target_path, "w", encoding="utf-8") as handle:
        json.dump(question_bank, handle, indent=2)
    return target_path
