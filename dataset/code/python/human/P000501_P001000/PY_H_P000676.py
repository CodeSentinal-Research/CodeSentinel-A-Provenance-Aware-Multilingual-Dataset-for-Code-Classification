r"""
===============================================================================
PATTERN 04 - COPY WITH RANDOM, MULTILEVEL FLATTEN, LRU NOTE
===============================================================================

These are the "advanced pointer" problems: each node has more than a single
next, or the structure is multilevel. The techniques:

  1. Hash map old_node -> new_node   (clearest for copy)
  2. Weave: insert copies in-between  (O(1) extra space copy)
  3. DFS/stack child-before-next      (flatten multilevel DLL)

LRU Cache is HashMap + doubly linked list. It is design, not a one-function
LL drill - see the note at the bottom pointing at 05_design_lld_lite/ (planned)
and AMAZON_Q_LIST (LRU x2).

===============================================================================
THE TEMPLATE
===============================================================================

VARIANT A - copy list with random pointer (hash map)

    class Node:
        def __init__(self, val, next=None, random=None): ...

    def copy_random_list(head):
        if not head:
            return None
        mp = {}                           # old -> new
        cur = head
        while cur:
            mp[cur] = Node(cur.val)
            cur = cur.next
        cur = head
        while cur:
            mp[cur].next = mp.get(cur.next)
            mp[cur].random = mp.get(cur.random)
            cur = cur.next
        return mp[head]


VARIANT B - copy with weave (O(1) extra space)

    # 1) For each node, insert copy right after it: A->A'->B->B'
    # 2) Set A'.random = A.random.next (the copy sitting after random)
    # 3) Unweave: restore original next, extract copy list

    # Step 1 weave
    cur = head
    while cur:
        nxt = cur.next
        cur.next = Node(cur.val, nxt)
        cur = nxt
    # Step 2 randoms
    cur = head
    while cur:
        if cur.random:
            cur.next.random = cur.random.next
        cur = cur.next.next
    # Step 3 unweave
    ...


VARIANT C - flatten multilevel doubly linked list (LC 430)

    # Each node: val, prev, next, child. Flatten so child chains are inlined
    # depth-first; no child pointers remain. Return head of the flat DLL.

    def flatten(head):
        cur = head
        while cur:
            if not cur.child:
                cur = cur.next
                continue
            # find tail of child list
            child = cur.child
            tail = child
            while tail.next:
                tail = tail.next
            # splice child between cur and cur.next
            tail.next = cur.next
            if cur.next:
                cur.next.prev = tail
            cur.next = child
            child.prev = cur
            cur.child = None
            cur = cur.next
        return head

    Iterative: when you see a child, splice the whole child list in, then
    continue - you will walk into the child next. No explicit stack needed.


===============================================================================
WHY IT WORKS (say this out loud)
===============================================================================

Copy needs a way to find "the clone of X" when wiring random. A hash map is
direct. Weaving makes the clone of X sit at X.next temporarily, so
X.random.next is the clone of X.random.

Flatten is DFS order of the multilevel structure: child subtree is visited
before the original next sibling. Splicing the child list in place IS that DFS
walk when you continue with cur = cur.next.


===============================================================================
HOW TO RECOGNISE IT
===============================================================================

Trigger words:

    random pointer / arbitrary pointer clone
    deep copy of a linked list with extra refs
    multilevel / nested doubly linked list / child pointer
    flatten to a single level

Anti-triggers:

    plain reverse / merge / cycle                  -> files 01-03
    LRU / LFU / O(1) get and put                   -> design (DLL + hashmap)
    clone a graph                                  -> graphs folder (hash map
                                                     of nodes, same idea)


===============================================================================
COMPLEXITY
===============================================================================

    copy (hash):     O(n) time, O(n) space for the map
    copy (weave):    O(n) time, O(1) extra (besides the new nodes)
    flatten:         O(n) time, O(1) extra iterative


===============================================================================
"""

from __future__ import annotations

from typing import Dict, Iterable, List, Optional


# -----------------------------------------------------------------------------
# Node with random (LC 138)
# -----------------------------------------------------------------------------

class Node:
    def __init__(
        self,
        val: int = 0,
        next: Optional["Node"] = None,
        random: Optional["Node"] = None,
    ):
        self.val = val
        self.next = next
        self.random = random


def build_random(
    vals: List[int], random_indices: List[Optional[int]]
) -> Optional[Node]:
    """vals[i] is value; random_indices[i] is index of random target or None."""
    if not vals:
        return None
    nodes = [Node(v) for v in vals]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    for i, ri in enumerate(random_indices):
        if ri is not None:
            nodes[i].random = nodes[ri]
    return nodes[0]


def to_random_pairs(head: Optional[Node]) -> List[List[Optional[int]]]:
    """LC-style [[val, random_index], ...] for asserts."""
    nodes: List[Node] = []
    cur = head
    while cur:
        nodes.append(cur)
        cur = cur.next
    index = {id(n): i for i, n in enumerate(nodes)}
    out: List[List[Optional[int]]] = []
    for n in nodes:
        ri = index[id(n.random)] if n.random is not None else None
        out.append([n.val, ri])
    return out


# -----------------------------------------------------------------------------
# Multilevel DLL node (LC 430)
# -----------------------------------------------------------------------------

class DLLNode:
    def __init__(
        self,
        val: int = 0,
        prev: Optional["DLLNode"] = None,
        next: Optional["DLLNode"] = None,
        child: Optional["DLLNode"] = None,
    ):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


def build_dll_linear(vals: Iterable[int]) -> Optional[DLLNode]:
    dummy = DLLNode(0)
    cur = dummy
    for v in vals:
        nxt = DLLNode(v)
        cur.next = nxt
        nxt.prev = cur
        cur = nxt
    head = dummy.next
    if head:
        head.prev = None
    return head


def to_dll_list(head: Optional[DLLNode]) -> List[int]:
    out: List[int] = []
    while head:
        out.append(head.val)
        assert head.child is None, "flatten must clear child pointers"
        if head.next:
            assert head.next.prev is head
        head = head.next
    return out


# =============================================================================
# MEDIUM - LC 138: COPY LIST WITH RANDOM POINTER
# =============================================================================
"""
A linked list of length n where each node has an additional random pointer
which could point to any node in the list, or null. Construct a deep copy of
the list - brand new nodes, same next/random structure.

CLARIFY
- Q: Deep copy - new nodes, not aliases?
  A: Yes. Mutating the copy must not change the original.
- Q: random may be null or point to any node (including self)?
  A: Yes.
- Q: O(1) extra space required?
  A: Ask. Hash map is the clean default; weave is the O(1) follow-up.

REJECT
- Shallow copy / copy only next, leave random pointing at originals. REJECT.
- Only hash map never mentioned as follow-up: fine as primary. ACCEPT map.
- Weave for O(1) space. ACCEPT as upgrade.

MAGIC Q
I'll make a hash map from each original node to its clone while walking next.
Then a second pass wires each clone's next and random through the map. O(n)
time and O(n) space. If you want O(1) extra space I can weave clones next to
originals instead.
"""


def copy_random_list(head: Optional[Node]) -> Optional[Node]:
    if not head:
        return None
    mp: Dict[Node, Node] = {}
    cur: Optional[Node] = head
    while cur:
        mp[cur] = Node(cur.val)
        cur = cur.next
    cur = head
    while cur:
        mp[cur].next = mp.get(cur.next)  # type: ignore[arg-type]
        mp[cur].random = mp.get(cur.random)  # type: ignore[arg-type]
        cur = cur.next
    return mp[head]


def copy_random_list_weave(head: Optional[Node]) -> Optional[Node]:
    """O(1) extra space: weave, assign randoms, unweave."""
    if not head:
        return None
    cur: Optional[Node] = head
    while cur:
        nxt = cur.next
        cur.next = Node(cur.val, nxt)
        cur = nxt
    cur = head
    while cur:
        copy = cur.next
        if cur.random and copy:
            copy.random = cur.random.next
        cur = cur.next.next if cur.next else None  # type: ignore[assignment]
    # unweave
    dummy = Node(0)
    copy_tail = dummy
    cur = head
    while cur:
        copy = cur.next
        nxt_orig = copy.next if copy else None
        copy_tail.next = copy
        copy_tail = copy  # type: ignore[assignment]
        cur.next = nxt_orig
        if copy:
            copy.next = None
        cur = nxt_orig
    return dummy.next


"""
AMAZON TWIST
- "O(1) extra space." -> weave version above. Say the three passes out loud.
- "Random can form cycles / point backwards." -> map and weave both handle it;
  you are copying structure, not traversing only via next for visited.
- "Clone a graph." -> same old->new map idea; see graphs folder.
"""


# =============================================================================
# MEDIUM - LC 430: FLATTEN A MULTILEVEL DOUBLY LINKED LIST
# =============================================================================
"""
You are given a doubly linked list which in addition to the next and prev
pointers, has a child pointer which may or may not point to a separate
doubly linked list. Flatten the list so that all nodes appear in a single-
level doubly linked list. Child pointers must become null. DFS order: process
child before the original next.

CLARIFY
- Q: Child lists may themselves have children (multi-level)?
  A: Yes - recursive nesting.
- Q: Order is DFS - child chain before the old next?
  A: Yes. Example in LC: 1-2-3-7-8-11-12-9-10-4-5-6 style.
- Q: Must fix prev links both ways?
  A: Yes - valid DLL when done.

REJECT
- Recursion with O(n) stack building a new list of values: works but rebuilds.
  Prefer in-place splice. Soft REJECT.
- BFS level-order flatten: wrong order vs LC. REJECT.
- Iterative splice child between cur and cur.next. ACCEPT.

MAGIC Q
I'll walk the list. Whenever a node has a child, I'll find the child's tail,
splice that whole child list between the node and its next, clear child, and
continue - the next iteration walks into the spliced child. O(n) time, O(1)
extra space.
"""


def flatten(head: Optional[DLLNode]) -> Optional[DLLNode]:
    cur = head
    while cur:
        if not cur.child:
            cur = cur.next
            continue
        child = cur.child
        tail = child
        while tail.next:
            tail = tail.next
        tail.next = cur.next
        if cur.next:
            cur.next.prev = tail
        cur.next = child
        child.prev = cur
        cur.child = None
        cur = cur.next
    return head


"""
AMAZON TWIST
- "Unflatten / restore child structure." -> need extra bookkeeping of splice
  points; usually not asked - clarify.
- "Flatten to an array." -> trivial walk after flatten, or DFS collect.
- "Singled linked with child (no prev)." -> same splice without prev fixes.
"""


# =============================================================================
# LRU CACHE - NOTE ONLY (design folder)
# =============================================================================
"""
LRU Cache (LC 146) showed up twice in your Amazon dump. The data structure is:

    HashMap[key] -> DLL node
    Doubly linked list of nodes in recency order (head = most recent, or the
    opposite convention - pick one and stick to it)
    get / put both O(1): map lookup + move-to-front + evict tail if over capacity

This is NOT a one-shot linked-list algorithm problem. It is a design problem
(API + O(1) constraints + edge cases on capacity 0 / update vs insert).

Where it lives in this corpus:
  - AMAZON_Q_LIST.md  -> Design section, LRU x2
  - Planned:          DSA/05_design_lld_lite/  (LRU / LFU / streams / TTL)
  - Heaps amazon file also points here for "not a heap" contrast

Do not force an LRU implementation into a reverse/merge drill. When the
interviewer says "design LRU", open the design folder (or implement DLL+map
from memory using the sketch above). The linked-list skill you need is
O(1) splice: remove a node from the middle of a DLL, insert at head.
"""


# =============================================================================
# THE FULL PROBLEM LIST FOR THIS PATTERN
# =============================================================================
"""
CORE (do these)
  138   Copy List with Random Pointer            medium
  430   Flatten a Multilevel Doubly Linked List  medium
  146   LRU Cache                                medium  -> design folder
                                                         <- IN YOUR DUMP x2

RELATED
  460   LFU Cache                                hard    -> design
  708   Insert into a Sorted Circular
        Linked List                              medium
  369   Plus One Linked List                     medium
  426   Convert Binary Search Tree to Sorted
        Doubly Linked List                       medium

CONTRAST
  133   Clone Graph                              medium  -> graphs (same map)
  148   Sort List                                medium  -> file 03
  160   Intersection                             easy    -> file 02 dump
"""


# =============================================================================
# TESTS
# =============================================================================

if __name__ == "__main__":
    # --- LC 138 hash ---
    h = build_random([7, 13, 11, 10, 1], [None, 0, 4, 2, 0])
    c = copy_random_list(h)
    assert to_random_pairs(c) == [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]]
    # deep copy: mutating copy must not change original structure identity
    assert c is not h
    assert c.next is not h.next  # type: ignore
    assert copy_random_list(None) is None
    one = Node(1)
    one.random = one
    c1 = copy_random_list(one)
    assert c1 is not None and c1.val == 1 and c1.random is c1 and c1 is not one

    # --- LC 138 weave ---
    h2 = build_random([7, 13, 11, 10, 1], [None, 0, 4, 2, 0])
    c2 = copy_random_list_weave(h2)
    assert to_random_pairs(c2) == [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]]
    # original restored (no weave left)
    assert to_random_pairs(h2) == [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]]
    assert copy_random_list_weave(None) is None

    # --- LC 430 ---
    # Build: 1-2-3-4-5-6 with 3.child = 7-8-9-10 and 8.child = 11-12
    n = {i: DLLNode(i) for i in range(1, 13)}
    for a, b in [(1, 2), (2, 3), (3, 4), (4, 5), (5, 6)]:
        n[a].next, n[b].prev = n[b], n[a]
    for a, b in [(7, 8), (8, 9), (9, 10)]:
        n[a].next, n[b].prev = n[b], n[a]
    n[11].next, n[12].prev = n[12], n[11]
    n[3].child = n[7]
    n[8].child = n[11]
    flat = flatten(n[1])
    assert to_dll_list(flat) == [1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6]

    # no children
    linear = build_dll_linear([1, 2, 3])
    assert to_dll_list(flatten(linear)) == [1, 2, 3]
    assert flatten(None) is None

    # child on last node
    a, b, c = DLLNode(1), DLLNode(2), DLLNode(3)
    a.next, b.prev = b, a
    a.child = c
    assert to_dll_list(flatten(a)) == [1, 3, 2]

    print("04_copy_and_advanced: all tests passed")
