const topologicalSort = {
  slug: 'topological-sort',
  phaseId: '13',
  eyebrow: 'Phase 13 — Graphs',
  title: 'Topological Sort',
  lede: 'A linear arrangement of a Directed Acyclic Graph\'s vertices such that for every directed edge u→v, u appears before v in the ordering. It\'s the formal way to safely resolve dependency constraints.',

  overview: [
    { label: 'Time Complexity', value: 'O(V + E) for both Kahn\'s and DFS-based' },
    { label: 'Space Complexity', value: 'O(V) for queues/stacks and recursion depth' },
    { label: 'Prerequisites', value: 'Cycle Detection, Queue (Phase 5), DFS (Phase 7)' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        {
          type: 'p',
          text: 'A **topological order** is a linear arrangement of a DAG\'s (Directed Acyclic Graph\'s) vertices such that for **every** directed edge `u→v`, `u` appears before `v` in the ordering. It\'s the formal answer to "what order can I safely process these tasks in, given their dependency constraints?"'
        }
      ]
    },
    {
      num: '02',
      title: 'Why Do We Use It?',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Problem it solves:** given dependency constraints (course prerequisites, build steps, task ordering), find a valid processing sequence that respects every "must come before" rule simultaneously.',
            '**Why it was invented:** dependency structures are naturally graph-shaped, and a topological order is exactly the traversal order that guarantees you never process something before something it depends on.',
            '**What makes it necessary (not optional):** a topological order **only exists if the graph is acyclic** — a cycle in dependencies (A needs B, B needs A) means there\'s fundamentally no valid processing order at all. Cycle detection is inseparable from this topic.'
          ]
        }
      ]
    },
    {
      num: '03',
      title: 'When Should I Think About Using It?',
      blocks: [
        {
          type: 'p',
          text: 'Common interview trigger phrases:'
        },
        {
          type: 'ul',
          items: [
            '"course schedule" / "can you finish all courses given prerequisites"',
            '"build order" / "task scheduling with dependencies"',
            '"alien dictionary" (derive a character ordering from sorted words)',
            'Any "given these precedence constraints, find a valid order" phrasing.'
          ]
        }
      ]
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        {
          type: 'p',
          text: 'Two genuinely different mechanisms reach the same kind of answer:'
        },
        {
          type: 'ul',
          items: [
            '**Kahn\'s Algorithm (BFS-based):** repeatedly process any vertex with **zero remaining incoming edges** (in-degree 0) — it has no unprocessed dependencies, so it\'s safe right now. Processing it "removes" its outgoing edges, potentially freeing up its neighbors to reach in-degree 0 next.',
            '**DFS-based:** run DFS: only after a node\'s **entire subtree of dependents** is fully explored (postorder), push it onto a result stack. Reverse the stack (or build it via prepending) — every dependency finishes exploring (and gets pushed) before what depends on it.'
          ]
        }
      ]
    },
    {
      num: '05',
      title: 'Dry Run',
      blocks: [
        {
          type: 'p',
          text: '**Problem (Kahn\'s Algorithm):** courses `0,1,2,3`; prerequisites: `0→1, 0→2, 1→3, 2→3`.'
        },
        {
          type: 'p',
          text: '**Build in-degrees:** `0:0, 1:1, 2:1, 3:2`'
        },
        {
          type: 'table',
          headers: ['step', 'queue', 'dequeue', 'result', 'in-degree updates'],
          rows: [
            ['start', '`[0]` (only in-degree 0)', '—', '`[]`', '—'],
            ['1', '`[0]`', '0', '`[0]`', 'decrement 1→0 (enqueue), decrement 2→0 (enqueue)'],
            ['2', '`[1,2]`', '1', '`[0,1]`', 'decrement 3: 2→1 (not yet 0, don\'t enqueue)'],
            ['3', '`[2]`', '2', '`[0,1,2]`', 'decrement 3: 1→0 (enqueue)'],
            ['4', '`[3]`', '3', '`[0,1,2,3]`', 'no outgoing edges']
          ]
        },
        {
          type: 'p',
          text: '**Result:** `[0, 1, 2, 3]` — a valid topological order.'
        }
      ]
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `     0
    / \\
   1   2
    \\ /
     3

Kahn's "peels" layer by layer, by current in-degree:
layer 0 (in-degree 0):  [0]
layer 1 (freed after 0 removed): [1, 2]
layer 2 (freed after both 1,2 removed): [3]`
        }
      ]
    },
    {
      num: '07',
      title: 'Time Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(V + E)** for both Kahn\'s and the DFS-based approach — every vertex processed once, every edge examined once (when decrementing an in-degree, or during DFS\'s neighbor scan).'
        }
      ]
    },
    {
      num: '08',
      title: 'Space Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(V)** for the in-degree array and queue (Kahn\'s); **O(V)** for the color array and result stack, plus $O(h)$ recursion depth (DFS-based).'
        }
      ]
    },
    {
      num: '09',
      title: 'Cost Analysis',
      blocks: [
        {
          type: 'p',
          text: 'Kahn\'s: each vertex dequeued exactly once ($O(1)$ each), each edge examined exactly once to decrement a target\'s in-degree ($O(1)$ each) → $O(V+E)$. DFS-based: identical shape, just via recursion and postorder pushes.'
        }
      ]
    },
    {
      num: '10',
      title: 'The Catch ⭐',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Kahn\'s algorithm detects cycles as a natural side effect.** If the graph has a cycle, the vertices caught in it never reach in-degree 0, so they never get dequeued. Checking `result.size() == V` at the end is the standard, elegant way to detect "no valid topological order exists".',
            '**The DFS-based version needs the reversal step.** Forgetting to reverse the postorder result silently produces the **exact opposite**, invalid order. Using a stack naturally achieves reversal implicitly.',
            '**Multiple valid topological orders often exist.** Don\'t assume there\'s a single "correct" answer to check against; verify any produced ordering against the original edge constraints directly.',
            '**When NOT to use it:** if the graph isn\'t actually meant to represent dependencies (no inherent "must come before" semantics), forcing a topological framing onto it doesn\'t make sense.'
          ]
        }
      ]
    },
    {
      num: '11',
      title: 'Prerequisites',
      blocks: [
        {
          type: 'p',
          text: 'Cycle Detection (directly needed), Queue (Phase 5) for Kahn\'s, DFS/recursion (Phase 7) for DFS-based.'
        }
      ]
    },
    {
      num: '12',
      title: 'Variations & Examples',
      blocks: [
        {
          type: 'collapse',
          title: 'i) Kahn\'s Algorithm (BFS-based)',
          tag: 'O(V+E) | In-degree Array | Queue',
          defaultOpen: true,
          blocks: [
            {
              type: 'code',
              language: 'java',
              label: 'Kahn\'s Algorithm (Java)',
              code: {
                java: `public int[] topologicalSortKahns(int n, int[][] prerequisites) {
    Map<Integer, List<Integer>> graph = new HashMap<>();
    int[] inDegree = new int[n];
    for (int i = 0; i < n; i++) graph.put(i, new ArrayList<>());
    for (int[] edge : prerequisites) { // edge = {from, to}
        graph.get(edge[0]).add(edge[1]);
        inDegree[edge[1]]++;
    }

    Queue<Integer> queue = new LinkedList<>();
    for (int i = 0; i < n; i++) if (inDegree[i] == 0) queue.offer(i);

    int[] result = new int[n];
    int idx = 0;
    while (!queue.isEmpty()) {
        int node = queue.poll();
        result[idx++] = node;
        for (int neighbor : graph.get(node)) {
            if (--inDegree[neighbor] == 0) queue.offer(neighbor);
        }
    }
    return idx == n ? result : new int[0]; // idx < n means a CYCLE exists
}`,
                javascript: `function topologicalSortKahns(n, prerequisites) {
    Map<Integer, const graph = new Map();
    int[] inDegree = new Array(n).fill(0);
    for (let i = 0; i < n; i++) graph.set(i, []);
    for (int[] edge : prerequisites) { // edge = {from, to}
        graph[edge[0]].push(edge[1]);
        inDegree[edge[1]]++;
    }

    const queue = new Deque();
    for (let i = 0; i < n; i++) if (inDegree[i] == 0) queue.offer(i);

    int[] result = new Array(n).fill(0);
    let idx = 0;
    while (!queue.length === 0) {
        let node = queue.poll();
        result[idx++] = node;
        for (const neighbor of graph[node]) {
            if (--inDegree[neighbor] == 0) queue.offer(neighbor);
        }
    }
    return idx == n ? result : new Array(0).fill(0); // idx < n means a CYCLE exists
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'ii) DFS-based Topological Sort',
          tag: 'O(V+E) | Postorder Push | Reverse Stack',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'Postorder DFS with a result stack, reusing the exact 3-color states from Cycle Detection. A gray-neighbor encounter simultaneously means "cycle found" **and** "no valid topological order exists."'
            },
            {
              type: 'p',
              text: '**The Catch:** The result must be pushed in **postorder** (only after a node\'s entire subtree is done) and then **reversed**. Reusing the white/gray/black states gives cycle detection "for free."'
            },
            {
              type: 'code',
              language: 'java',
              label: 'DFS Topological Sort (Java)',
              code: {
                java: `public int[] topologicalSortDFS(int n, int[][] prerequisites) {
    Map<Integer, List<Integer>> graph = new HashMap<>();
    for (int i = 0; i < n; i++) graph.put(i, new ArrayList<>());
    for (int[] edge : prerequisites) graph.get(edge[0]).add(edge[1]);

    int[] color = new int[n]; // 0=white, 1=gray, 2=black
    Deque<Integer> stack = new ArrayDeque<>();
    boolean[] hasCycle = {false};

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) dfs(i, graph, color, stack, hasCycle);
    }
    if (hasCycle[0]) return new int[0]; // no valid topological order

    int[] result = new int[n];
    for (int i = 0; i < n; i++) result[i] = stack.pop(); // pop = reversed postorder
    return result;
}
private void dfs(int node, Map<Integer, List<Integer>> graph, int[] color, Deque<Integer> stack, boolean[] hasCycle) {
    color[node] = 1; // GRAY
    for (int neighbor : graph.get(node)) {
        if (color[neighbor] == 1) { hasCycle[0] = true; return; }
        if (color[neighbor] == 0) dfs(neighbor, graph, color, stack, hasCycle);
    }
    color[node] = 2; // BLACK
    stack.push(node); // POSTORDER push
}`,
                javascript: `function topologicalSortDFS(n, prerequisites) {
    Map<Integer, const graph = new Map();
    for (let i = 0; i < n; i++) graph.set(i, []);
    for (int[] edge : prerequisites) graph[edge[0]].push(edge[1]);

    int[] color = new Array(n).fill(0); // 0=white, 1=gray, 2=black
    const stack = new Deque();
    boolean[] hasCycle = {false};

    for (let i = 0; i < n; i++) {
        if (color[i] == 0) dfs(i, graph, color, stack, hasCycle);
    }
    if (hasCycle[0]) return new Array(0).fill(0); // no valid topological order

    int[] result = new Array(n).fill(0);
    for (let i = 0; i < n; i++) result[i] = stack.pop(); // pop = reversed postorder
    return result;
}
function dfs(node, Map<Integer, graph, color, stack, hasCycle) {
    color[node] = 1; //function for(graph[node]) {
        if (color[neighbor] == 1) { hasCycle[0] = true; return; }
        if (color[neighbor] == 0) dfs(neighbor, graph, color, stack, hasCycle);
    }
    color[node] = 2; // BLACK
    stack.push(node); // POSTORDER push
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'iii) Application — Alien Dictionary',
          tag: 'O(C + V+E) | Alphabet ordering | Prefix violation',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'Derive a full character ordering (a topological sort **over the alphabet itself**) from a list of words assumed to already be sorted.'
            },
            {
              type: 'p',
              text: 'Extract edges by comparing each adjacent pair, finding the FIRST differing character. `["wrt", "wrf"]` → diverges at index 2 → `t` before `f` → edge `t→f`.'
            },
            {
              type: 'p',
              text: '**The Catch:** A shorter word appearing *after* a longer word it\'s a prefix of (e.g., `"abc"` then `"ab"`) is an invalid input and must be explicitly detected and rejected.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Alien Dictionary (Java)',
              code: {
                java: `public String alienOrder(String[] words) {
    Map<Character, Set<Character>> graph = new HashMap<>();
    int[] inDegree = new int[26];
    boolean[] present = new boolean[26];
    for (String w : words) for (char c : w.toCharArray()) present[c - 'a'] = true;

    for (int i = 0; i < words.length - 1; i++) {
        String w1 = words[i], w2 = words[i + 1];
        int minLen = Math.min(w1.length(), w2.length());
        boolean foundDiff = false;
        for (int j = 0; j < minLen; j++) {
            char c1 = w1.charAt(j), c2 = w2.charAt(j);
            if (c1 != c2) {
                graph.computeIfAbsent(c1, k -> new HashSet<>());
                if (graph.get(c1).add(c2)) inDegree[c2 - 'a']++; 
                foundDiff = true;
                break; // ONLY the first differing character
            }
        }
        if (!foundDiff && w1.length() > w2.length()) return ""; // prefix violation
    }

    Queue<Character> queue = new LinkedList<>();
    for (int i = 0; i < 26; i++) if (present[i] && inDegree[i] == 0) queue.offer((char) ('a' + i));

    StringBuilder result = new StringBuilder();
    while (!queue.isEmpty()) {
        char c = queue.poll();
        result.append(c);
        for (char neighbor : graph.getOrDefault(c, Collections.emptySet())) {
            if (--inDegree[neighbor - 'a'] == 0) queue.offer(neighbor);
        }
    }
    int totalLetters = 0;
    for (boolean p : present) if (p) totalLetters++;
    return result.length() == totalLetters ? result.toString() : ""; // incomplete → cycle/invalid
}`,
                javascript: `function alienOrder(words) {
    Map<Character, const graph = new Map();
    int[] inDegree = new Array(26).fill(0);
    boolean[] present = new Array(26).fill(false);
    for (const w of words) for (const c of w.split('')) present[c - 'a'] = true;

    for (let i = 0; i < words.length - 1; i++) {
        let w1 = words[i], w2 = words[i + 1];
        let minLen = Math.min(w1.length(), w2.length());
        let foundDiff = false;
        for (let j = 0; j < minLen; j++) {
            let c1 = w1[j], c2 = w2[j];
            if (c1 != c2) {
                graph.computeIfAbsent(c1, k -> new Set());
                if (graph[c1].push(c2)) inDegree[c2 - 'a']++; 
                foundDiff = true;
                break; // ONLY the first differing character
            }
        }
        if (!foundDiff && w1.length() > w2.length()) return ""; // prefix violation
    }

    const queue = new Deque();
    for (let i = 0; i < 26; i++) if (present[i] && inDegree[i] == 0) queue.offer((char) ('a' + i));

    StringBuilder result = new StringBuilder();
    while (!queue.length === 0) {
        let c = queue.poll();
        result.append(c);
        for (const neighbor of (graph[c] ?? Collections.emptySet())) {
            if (--inDegree[neighbor - 'a'] == 0) queue.offer(neighbor);
        }
    }
    let totalLetters = 0;
    for (boolean p : present) if (p) totalLetters++;
    return result.length() == totalLetters ? result.toString() : ""; // incomplete → cycle/invalid
}`
              }
            }
          ]
        }
      ]
    },
    {
      num: '13',
      title: 'Related Patterns',
      blocks: [
        {
          type: 'chain',
          nodes: [
            { label: 'Cycle Detection (Phase 13)', desc: 'directly needed as a prerequisite check' },
            { label: 'Topological Sort', desc: 'you are here', current: true },
            { label: 'Dynamic Programming (Phase 15)', desc: 'some DP problems on DAGs process nodes in topological order' }
          ],
          arrows: [
            'prerequisite for',
            'foundation for'
          ]
        }
      ]
    },
    {
      num: '17',
      title: 'Intuition',
      blocks: [
        {
          type: 'p',
          text: 'A topological order is simply "process dependencies before dependents," and the two approaches capture that idea from opposite directions. Kahn\'s makes it literal: repeatedly process whatever currently has **zero remaining unprocessed dependencies** (safe to do right now) and removing it may free up its dependents. DFS\'s approach is more subtle: by only finishing (postorder) a node after **all** its descendants are finished, and reversing that finishing order, you guarantee every dependency was finished strictly before whatever depends on it.'
        }
      ]
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        {
          type: 'checklist',
          id: 'topo-sort-checklist',
          items: [
            'Am I confirming the graph is genuinely a DAG (no valid order exists otherwise)?',
            'Kahn\'s: am I checking result.size() == V at the end to detect a cycle?',
            'DFS-based: am I pushing in postorder and reversing (or using a stack to get reversal for free)?',
            'Is there more than one valid topological order? → don\'t check against a single hardcoded output.',
            'Alien Dictionary specifically: am I extracting only the FIRST differing character per pair, and rejecting prefix violations?'
          ]
        }
      ]
    }
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'Kahn\'s Algorithm uses BFS and in-degrees, getting cycle detection for free if it can\'t pull all nodes. DFS-based relies on postorder pushing and reversing. Both achieve the identical valid processing order for dependencies.'
  }
};

export default topologicalSort;
