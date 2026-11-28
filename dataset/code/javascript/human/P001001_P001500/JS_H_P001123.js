const floydWarshall = {
  slug: 'floyd-warshall',
  phaseId: '13',
  eyebrow: 'Phase 13 — Graphs',
  title: 'Shortest Path — Floyd-Warshall',
  lede: 'Computes shortest paths between every pair of nodes simultaneously using dynamic programming on a distance matrix, processing intermediate waypoints one by one.',

  overview: [
    { label: 'Time Complexity', value: 'O(V³) — a triple nested loop' },
    { label: 'Space Complexity', value: 'O(V²) for the distance matrix (updated in-place)' },
    { label: 'Prerequisites', value: 'Dijkstra (Phase 13), DP Intuition (Phase 15 preview)' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        {
          type: 'p',
          text: 'Floyd-Warshall computes shortest paths between **every pair** of nodes simultaneously, using dynamic programming directly on a distance matrix: it asks, incrementally, "am I now **allowed** to route through node `k`? Does that help any pair `(i,j)`?" — considering nodes `0, 1, 2, ...` as allowed intermediate waypoints one at a time, until every node has been considered.'
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
            '**Problem it solves:** when you need shortest paths between **all** pairs (not just from one source), running Dijkstra `V` separate times costs $O(V \\cdot (V+E) \\log V)$. Floyd-Warshall achieves the same result in one unified $O(V^3)$ pass.',
            '**Why it was invented:** for **dense** graphs (where $E \\approx V^2$), running Dijkstra $V$ times costs roughly $O(V^3 \\log V)$ — *worse* than Floyd-Warshall\'s clean $O(V^3)$. It also handles negative edges correctly without modification.',
            '**What makes it appealing:** genuine implementation simplicity — a triple nested loop, no heap, no edge-list bookkeeping.'
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
            '"all pairs shortest path"',
            '"shortest path between every pair of cities"',
            '"transitive closure of a graph"',
            '"find the city with the smallest number of neighbors within a threshold distance"'
          ]
        }
      ]
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        {
          type: 'ol',
          items: [
            'Initialize `dist[i][j] =` direct edge weight `i→j` (or infinity if no edge), and `dist[i][i] = 0`.',
            'For each possible intermediate node `k` (0 to V−1): for **every** pair `(i,j)`, check `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])` — "is routing through `k` better than what I currently know?"',
            'After considering **all** nodes as potential intermediates, `dist[i][j]` holds the true shortest path for every pair.'
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
          text: '**Problem:** 4 nodes, directed weighted edges: `0→1(3), 0→3(7), 1→0(8), 1→2(2), 2→0(5), 2→3(1), 3→0(2)`.'
        },
        {
          type: 'ascii',
          content: `Initial matrix (inf = no direct edge):
   0 [  0,   3,  inf,  7 ]
   1 [  8,   0,   2,  inf]
   2 [  5,  inf,  0,   1 ]
   3 [  2,  inf, inf,  0 ]

k=0: dist[1][3]: via 0 → 8+7=15 < inf → update to 15.
     dist[2][1]: via 0 → 5+3=8 < inf → update to 8.
     dist[3][1]: via 0 → 2+3=5 < inf → update to 5.

k=2: dist[0][3]: via 2 → 5+1=6 < 7 → update to 6.
     dist[1][0]: via 2 → 2+5=7 < 8 → update to 7.
     dist[1][3]: via 2 → 2+1=3 < 15 → update to 3.

Final matrix:
   0 [  0,   3,   5,   6 ]
   1 [  5,   0,   2,   3 ]
   2 [  3,   6,   0,   1 ]
   3 [  2,   5,   7,   0 ]`
        },
        {
          type: 'p',
          text: 'Verify `dist[2][1]=6`: path `2→3→0→1 = 1+2+3 = 6` ✓ (beats the direct `2→0→1=5+3=8` found earlier).'
        }
      ]
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `"Am I allowed to route through node k yet?" — asked once per k, for every pair:

k=0: unlocks routes through 0    → some pairs improve
k=1: ALSO unlocks routes through 1    → more pairs improve (may chain with k=0's updates)
k=2: ALSO unlocks routes through 2    → more improve
k=3: ALSO unlocks routes through 3    → final answer

By the end, every possible routing combination has been considered exactly once.`
        }
      ]
    },
    {
      num: '07',
      title: 'Time Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(V³)** — a triple nested loop (`k`, then `i`, then `j`), $O(1)$ work per cell.'
        }
      ]
    },
    {
      num: '08',
      title: 'Space Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(V²)** for the distance matrix — can be updated **in-place**, no extra copy needed per `k`. This works correctly because `dist[i][k]` and `dist[k][j]` cannot themselves change during the processing of this same `k`.'
        }
      ]
    },
    {
      num: '09',
      title: 'Cost Analysis',
      blocks: [
        {
          type: 'p',
          text: 'Straightforward triple loop, $O(1)$ per cell update, $V^3$ total operations — no amortized analysis needed. This predictability is part of its appeal, especially for smaller/moderate $V$ or dense graphs.'
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
            '**The loop order is critical: `k` must be the OUTERMOST loop**, not innermost. Swapping the loop order breaks correctness **silently** — it produces a plausible-looking but wrong matrix.',
            '**O(V³) becomes genuinely expensive for large V** (roughly V > 500-1000) — for sparse graphs with many nodes, running Dijkstra V times is often faster in practice.',
            '**Still cannot handle negative cycles correctly on its own** — but it provides a natural detection signal: a negative cycle causes a **diagonal** entry `dist[i][i]` to go negative.',
            '**`dist[i][i] = 0` must be initialized correctly**, not left as infinity — the trivial "path from a node to itself" is the baseline everything else is compared against.'
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
          text: 'Basic DP intuition (previews Phase 15), matrix manipulation, understanding why "Dijkstra run V times" is the natural alternative.'
        }
      ]
    },
    {
      num: '12',
      title: 'Examples',
      blocks: [
        {
          type: 'collapse',
          title: 'i) All-Pairs Shortest Path (basic)',
          tag: 'O(V³) | In-place Matrix Update | k is outermost',
          defaultOpen: true,
          blocks: [
            {
              type: 'code',
              language: 'java',
              label: 'Floyd-Warshall (Java)',
              code: {
                java: `public int[][] floydWarshall(int[][] graph, int V) {
    int[][] dist = new int[V][V];
    for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE / 2); // avoid overflow
    for (int i = 0; i < V; i++) dist[i][i] = 0;
    for (int[] edge : graph) dist[edge[0]][edge[1]] = edge[2]; // {from, to, weight}

    for (int k = 0; k < V; k++) {           // MUST be outermost
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}`,
                javascript: `function floydWarshall(graph, V) {
    int[][] dist = Array.from({length: V}, () => new Array(V).fill(0));
    for (int[] row : dist) Arrays.fill(row, Infinity / 2); // avoid overflow
    for (let i = 0; i < V; i++) dist[i][i] = 0;
    for (int[] edge : graph) dist[edge[0]][edge[1]] = edge[2]; // {from, to, weight}

    for (let k = 0; k < V; k++) {           // MUST befunction for(i++) {
            for (let j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'ii) Negative Cycle Detection via Floyd-Warshall',
          tag: 'O(V³) | Negative Diagonal = Cycle',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'The diagonal-check parallel to Bellman-Ford\'s extra-round detection — after running Floyd-Warshall, if **any** `dist[i][i] < 0`, a negative cycle involving node `i` exists.'
            },
            {
              type: 'p',
              text: '**The Catch:** A graph with NO negative cycles will always have `dist[i][i] = 0` for every `i`. Any negative diagonal entry is unambiguous proof of a cycle. Unlike Bellman-Ford\'s single yes/no answer, this directly reveals **which specific nodes** are affected.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Negative Cycle Check (Java)',
              code: {
                java: `public boolean hasNegativeCycleFW(int[][] dist, int V) {
    // run standard Floyd-Warshall first, then:
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) return true; // any negative diagonal → negative cycle
    }
    return false;
}`,
                javascript: `function hasNegativeCycleFW(dist, V) {
    // run standard Floyd-Warshall first, then:
    for (let i = 0; i < V; i++) {
        if (dist[i][i] < 0) return true; // any negative diagonal → negative cycle
    }
    return false;
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'iii) Find City with Smallest Number of Neighbors at a Threshold Distance',
          tag: 'O(V³) | Post-process | Tie-break specific',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'Run Floyd-Warshall to get the complete all-pairs matrix, then do a simple counting pass for each city. Return the city with the fewest reachable neighbors.'
            },
            {
              type: 'p',
              text: '**The Catch:** The tie-breaking rule (**prefer the higher index**) is an easy-to-miss spec detail. Always read the exact tie-breaking requirement.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'City with Smallest Neighbors (Java)',
              code: {
                java: `public int findTheCity(int n, int[][] edges, int distanceThreshold) {
    int[][] dist = new int[n][n];
    for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE / 2);
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int[] edge : edges) {
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2]; // undirected
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];

    int bestCity = -1, minCount = Integer.MAX_VALUE;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) count++;
        }
        if (count <= minCount) { // <= naturally favors the HIGHER index on ties (later i overwrites)
            minCount = count;
            bestCity = i;
        }
    }
    return bestCity;
}`,
                javascript: `function findTheCity(n, edges, distanceThreshold) {
    int[][] dist = Array.from({length: n}, () => new Array(n).fill(0));
    for (int[] row : dist) Arrays.fill(row, Infinity / 2);
    for (let i = 0; i < n; i++) dist[i][i] = 0;
    for (int[] edge : edges) {
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2]; // undirected
    }

    for (let k = 0; k < n; k++)
        for (let i = 0; i < n; i++)
            for (let j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];

    let bestCity = -1, minCount = Infinity;
    for (let i = 0; i < n; i++) {
        let count = 0;
        for (let j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) count++;
        }
        if (count <= minCount) { // <= naturally favors the HIGHER index on ties (later i overwrites)
            minCount = count;
            bestCity = i;
        }
    }
    return bestCity;
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
            { label: 'Dijkstra (Phase 13)', desc: 'faster per-source, but needs V runs for all-pairs' },
            { label: 'Floyd-Warshall', desc: 'you are here', current: true },
            { label: 'Dynamic Programming (Phase 15)', desc: 'Floyd-Warshall is a DP directly on a 2D table' }
          ],
          arrows: [
            'alternative to',
            'previews'
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
          text: 'Floyd-Warshall asks a beautifully simple incremental question: "if I\'m now **allowed** to route through node 0, does that help? Now node 1 too?..." By the time every node has been considered as a potential waypoint, every possible routing combination has been examined. It\'s one giant, unified relaxation applied to the **entire** distance matrix at once.'
        }
      ]
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        {
          type: 'checklist',
          id: 'floyd-warshall-checklist',
          items: [
            'Do I genuinely need all-pairs distances, or just a single source?',
            'Is `k` the OUTERMOST loop?',
            'Is V small/moderate enough that O(V³) is acceptable?',
            'Have I initialized `dist[i][i] = 0` correctly?',
            'Negative cycle concern? → check the diagonal after completion.',
            'Any post-processing spec details (like tie-breaking rules) I need to get exactly right?'
          ]
        }
      ]
    }
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'Floyd-Warshall is the definitive answer for all-pairs shortest paths on moderate-sized graphs. Its triple loop is beautifully simple, provided you remember that `k` MUST be the outermost loop.'
  }
};

export default floydWarshall;
