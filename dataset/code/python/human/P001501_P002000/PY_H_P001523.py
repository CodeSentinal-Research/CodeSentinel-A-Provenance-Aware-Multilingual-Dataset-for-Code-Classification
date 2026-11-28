#!/usr/bin/env python3
"""Generate the maintained self-contained question artifacts in validated batches.

The catalog is keyed by the exact canonical question text emitted by the extractor.
Generation refuses partial/ambiguous mappings before writing any selected batch.
"""
from __future__ import annotations
import argparse, csv, json, re
from pathlib import Path
from walkthroughs import WALKTHROUGHS

ROOT = Path(__file__).resolve().parent
CATALOG = json.loads((ROOT / 'question_catalog.json').read_text(encoding='utf-8'))
CSV_PATH = ROOT / 'coding_questions.csv'
QUESTIONS = ROOT / 'questions'
REFERENCES = ROOT / 'reference_solutions' / 'questions'
REFERENCES.mkdir(parents=True, exist_ok=True)

# Each value is (positional arguments, expected result), serialized as Python literals.
CASES = {
'check_palindrome': [(('A man, a plan, a canal: Panama',), True), (('python',), False), (('',), True)],
'anagrams': [(('Dormitory','Dirty room'), True), (('aab','ab'), False)],
'number_words': [((42,), 'forty-two'), ((0,), 'zero'), ((1000,), 'one thousand')],
'bst_delete': [(([5,3,7,2,4,6,8],3), [2,4,5,6,7,8])],
'cycle': [(([1,2,3],1), True), (([1,2,3],None), False)],
'primes': [((10,), [2,3,5,7]), ((1,), [])],
'two_sum': [(([2,7,11,15],9), (0,1)), (([1,2],9), None)],
'common_letters': [(('bella','label'), ['b','e','l','a']), (('abc','xyz'), [])],
'diagonal_difference': [(([[1,2,3],[4,5,6],[7,8,9]],), 0)],
'bst_distance': [(([5,3,7,2,4,6,8],2,8), 4)],
'median': [(([1,3,2,4],), 2.5), (([3],), 3)],
'strong_numbers': [((1,500), [1,2,145])],
'pivot_index': [(([1,7,3,6,5,6],), 3), (([1,2,3],), None)],
'longest_unique': [(('abcabcbb',), 'abc'), (('',), '')],
'maximum_subarray': [(([-2,1,-3,4,-1,2,1,-5,4],), (6,3,6))],
'middle_value': [(([1,2,3,4],), 3), (([],), None)],
'missing_number': [(([3,0,1],), 2), (([1,2,3],), 0)],
'nth_to_last': [(([1,2,3,4],2), 3)],
'maximum_pair': [(([4,1,7,3],), (4,7))],
'intersection': [(([1,2],[9],[8,10]), 8), (([1],[],[]), None)],
'second_largest': [(([4,1,7,7,3],), 4)],
'diagonal_sum': [(([[1,2,3],[4,5,6],[7,8,9]],), 25)],
'digital_root': [((9875,), 2), ((0,), 0)],
'top_frequencies': [(([1,1,2,2,2,3],), [2,1])],
'flatten': [(([1,[2,(3,[4])]],), [1,2,3,4]), (([],), [])],
'fibonacci': [((7,), [0,1,1,2,3,5,8]), ((0,), [])],
'merge_intervals': [(([[1,3],[2,6],[8,10]],), [[1,6],[8,10]]), (([],), [])],
'reverse_chunks': [(([1,2,3,4,5],2), [2,1,4,3,5])],
'remove_duplicates': [(([1,2,1,3,2],), [1,2,3])],
'sorted_two_sum': [(([1,2,4,7,11],9), (1,3)), (([1,2],8), None)],
'binary_search': [(([1,3,5,7],5), 2), (([1,3],4), -1)],
'mirror_center': [(('racecar',), 3), (('abc',), None)],
'coin_combinations': [((5,[1,2,5]), 4), ((0,[2,3]), 1)],
'subarray_sum': [(([1,2,3,4],5), (1,2)), (([1,-1],3), None)],
'most_frequent': [(([1,2,2,3,3],), [2,3]), (([],), [])],
'first_unique': [(('swiss',), 'w'), (('aabb',), None)],
'array_list': [(([('append',1),('append',2),('insert',1,9)],), [1,9,2])],
'merge_sorted': [(([1,3],[2,4]), [1,2,3,4]), (([],[1]), [1])],
'spiral': [(([[1,2,3],[4,5,6],[7,8,9]],), [1,2,3,6,9,8,7,4,5])],
'remove_nth': [(([1,2,3,4,5],2), [1,2,3,5]), (([1],1), [])],
'tree_height': [(((1,(2,None,None),(3,None,None)),), 2), ((None,), 0)],
'reverse_linked': [(([1,2,3],), [3,2,1]), (([],), [])],
'reverse_special': [(('ab@k,w',), 'wk@b,a')],
'reverse_array': [(([1,2,3],), [3,2,1])],
'swap_adjacent': [(([1,2,3,4,5],), [2,1,4,3,5]), (([1],), [1])],
'digit_sum': [((-123,), 6), ((0,), 0)],
'swap_numbers': [((3,5), (5,3))],
'valid_bst': [(((2,(1,None,None),(3,None,None)),), True), (((2,(3,None,None),(1,None,None)),), False)],
'target_range': [(([1,2,4,4,4,7],4), (2,4)), (([1,2],3), None)],
'inorder': [(((2,(1,None,None),(3,None,None)),), [1,2,3]), ((None,), [])],
}

NOTES = {
'check_palindrome':'Normalize to case-folded alphanumeric characters, then compare from both ends.',
'anagrams':'Ignore whitespace and case, but preserve multiplicity by comparing character counts.',
'number_words':'Support integers from -999,999 through 999,999; compose hundreds and thousands recursively.',
'bst_delete':'Insert the values into a BST, delete one matching node, and return the remaining values in sorted order.',
'cycle':'A cycle exists only when cycle_index names a valid node; None or an out-of-range index is acyclic.',
'primes':'Return every prime from 2 through limit inclusive; limits below 2 produce an empty list.',
'two_sum':'Scan left to right and return the first pair completed, using zero-based indexes; return None when absent.',
'common_letters':'Return characters present in both strings once each, preserving their first-string order.',
'diagonal_difference':'For a square matrix, return the absolute difference of primary and secondary diagonal sums.',
'bst_distance':'Build a BST in insertion order and count edges on the path between two present values.',
'median':'Sort a copy; choose the middle value or average the two middle values. Empty input is invalid.',
'strong_numbers':'Include endpoints and test whether the sum of digit factorials equals each non-negative candidate.',
'pivot_index':'Return the first index whose left and right sums match, or None if no such index exists.',
'longest_unique':'Use a sliding window and return the earliest longest substring when lengths tie.',
'maximum_subarray':'Return (maximum_sum, start_index, end_index), using the earliest range when sums tie.',
'middle_value':'Return the second middle value for even lengths and None for an empty list.',
'missing_number':'Input contains distinct values from 0 through n with one omitted; return the omission.',
'nth_to_last':'n is one-based from the end and must be between 1 and the list length.',
'maximum_pair':'Return the two largest values in ascending order; duplicate maxima may form the pair.',
'intersection':'The shared suffix models identity-based intersection; return its first value or None.',
'second_largest':'Return the second distinct largest value; fewer than two distinct values is invalid.',
'diagonal_sum':'Sum both diagonals of a square matrix, counting the center only once.',
'digital_root':'Use the absolute value; repeatedly sum digits until one digit remains.',
'top_frequencies':'Return up to two values ordered by descending frequency, then ascending value for ties.',
'flatten':'Recursively flatten nested lists and tuples while leaving all other values atomic.',
'fibonacci':'Return the first n values beginning 0, 1; n must be non-negative.',
'merge_intervals':'Sort by start and merge touching or overlapping closed intervals without mutating input.',
'reverse_chunks':'Reverse each complete group of n and leave an incomplete final group unchanged; n must be positive.',
'remove_duplicates':'Keep each value first occurrence and preserve order.',
'sorted_two_sum':'Use zero-based indexes and two pointers; return the first pair found or None.',
'binary_search':'Return an index containing target in ascending input, or -1 when absent.',
'mirror_center':'Return the first index whose surrounding left and right substrings mirror exactly, or None.',
'coin_combinations':'Count order-independent combinations with unlimited positive denominations; amount zero has one combination.',
'subarray_sum':'Return the first inclusive zero-based range found whose sum is target; support negative values.',
'most_frequent':'Return all modes in ascending order; empty input has no modes.',
'first_unique':'Return the first character occurring exactly once, or None.',
'array_list':'Apply append, insert, remove-by-index, and get operations; return the final stored values.',
'merge_sorted':'Merge two ascending arrays into a new ascending list, preserving duplicates.',
'spiral':'Traverse a rectangular matrix clockwise from the top-left; empty input returns empty output.',
'remove_nth':'Remove the one-based nth item from the end in a new list; invalid n raises ValueError.',
'tree_height':'Trees are (value, left, right) tuples; height counts nodes and an empty tree has height zero.',
'reverse_linked':'The list models linked-list values; return a reversed copy.',
'reverse_special':'Reverse alphabetic characters only while every non-letter remains at its original index.',
'reverse_array':'Return a reversed copy and do not mutate caller-owned input.',
'swap_adjacent':'Swap each neighboring pair and leave an unpaired final value unchanged.',
'digit_sum':'Recursively sum decimal digits of the absolute value; zero returns zero.',
'swap_numbers':'Return the inputs in reversed order as a tuple.',
'valid_bst':'Trees are (value, left, right) tuples and every descendant must satisfy strict BST bounds.',
'target_range':'In sorted input, return inclusive first and last indexes of target or None.',
'inorder':'Trees are (value, left, right) tuples; recursively return left, root, right values.',
}

def validate(rows):
    texts = [row['question'] for row in rows]
    if len(texts) != len(set(texts)): raise ValueError('CSV has duplicate canonical questions')
    missing = [text for text in texts if text not in CATALOG]
    unused = [text for text in CATALOG if text not in set(texts)]
    if missing: raise ValueError('unsupported CSV rows: ' + repr(missing))
    if unused: raise ValueError('unused catalog entries: ' + repr(unused))
    slugs = [CATALOG[text][0] for text in texts]
    if len(slugs) != len(set(slugs)): raise ValueError('duplicate catalog slugs')
    for text in texts:
        slug, ref_name, signature = CATALOG[text]
        if not re.fullmatch(r'[a-z][a-z0-9_]*', slug): raise ValueError(f'invalid slug: {slug}')
        if not signature.startswith('solve('): raise ValueError(f'invalid signature: {text}')
        if slug not in CASES: raise ValueError(f'missing test cases/strategy: {slug}')
        if not hasattr(__import__('reference_solutions.imported_algorithms', fromlist=[ref_name]), ref_name):
            raise ValueError(f'missing reference strategy: {ref_name}')

def write_batch(rows, start):
    for number, row in enumerate(rows, start + 1):
        text = row['question']; slug, ref_name, signature = CATALOG[text]
        directory = QUESTIONS / f'{number:02d}_{slug}'
        directory.mkdir(parents=True, exist_ok=True)
        companies = row['company_name']
        examples = '\n'.join(f'- `{args!r}` → `{expected!r}`' for args, expected in CASES[slug])
        note = NOTES[slug]
        walkthrough = WALKTHROUGHS[slug]
        (directory / 'problem.md').write_text(f'''# {text}\n\n- **Source companies:** {companies}\n- **Topic:** interview coding / algorithms\n- **Difficulty:** varies by implementation\n\n## Problem\nImplement the operation stated in the title using the exact Python contract below. Return a new value unless the contract explicitly calls for mutation.\n\n## Signature\n`{signature}`\n\n## Examples\n{examples}\n\n## Constraints and edge cases\n{note}\n\nUse ordinary standard-library Python values. Tests include empty or minimal inputs, duplicates, negative values, ties, and invalid arguments where those cases apply. Do not mutate caller-owned lists or matrices.\n\n## Approach hint\nIdentify the invariant behind the operation and state its time and space complexity before coding. Keep result ordering deterministic as specified above.\n\n## Walkthrough\n[Problem-specific walkthrough]({walkthrough})\n''', encoding='utf-8')
        (directory / 'solution.py').write_text(f'''from __future__ import annotations\n\ndef {signature}:\n    """Practice stub; implement the contract in problem.md."""\n    raise NotImplementedError("solve is not implemented yet")\n''', encoding='utf-8')
        calls = []
        for args, expected in CASES[slug]:
            call = f'solve(*{args!r})'
            calls.append(f'    assert {call} == {expected!r}')
        (directory / 'test_solution.py').write_text(f'''from __future__ import annotations\nimport importlib.util\nfrom pathlib import Path\n_spec = importlib.util.spec_from_file_location("learner_{number:02d}_{slug}", Path(__file__).with_name("solution.py"))\n_solution = importlib.util.module_from_spec(_spec)\n_spec.loader.exec_module(_solution)\nsolve = _solution.solve\n\ndef test_documented_contract():\n{chr(10).join(calls)}\n''', encoding='utf-8')
        (REFERENCES / f'{number:02d}_{slug}.py').write_text(f'''from __future__ import annotations\nfrom reference_solutions.imported_algorithms import {ref_name}\n\ndef {signature}:\n    return {ref_name}(*locals().values())\n''', encoding='utf-8')

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--start', type=int, default=0)
    parser.add_argument('--size', type=int, default=6)
    args = parser.parse_args()
    with CSV_PATH.open(newline='', encoding='utf-8') as stream: rows = list(csv.DictReader(stream))
    validate(rows)
    if args.start < 0 or args.size <= 0 or args.start >= len(rows): raise ValueError('invalid batch')
    batch = rows[args.start:args.start + args.size]
    write_batch(batch, args.start)
    print(f'validated catalog: {len(rows)} exact rows; generated batch {args.start}:{args.start + len(batch)}')

if __name__ == '__main__': main()
