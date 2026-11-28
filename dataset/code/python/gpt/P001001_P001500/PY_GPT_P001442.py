# problem title : Find Duplicate Files by Content
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        content_map = defaultdict(list)
        for p in paths:
            parts = p.split(' ')
            dir_path = parts[0]
            for file_info in parts[1:]:
                open_idx = file_info.find('(')
                file_name = file_info[:open_idx]
                content = file_info[open_idx + 1:-1]
                content_map[content].append(f"{dir_path}/{file_name}")

        return [files for files in content_map.values() if len(files) > 1]
