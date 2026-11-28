/**
 * Condensed refreshers for the pre-exam review packets: formulas and algorithm
 * skeletons only, no re-teaching. Each links back to the full lecture page.
 *
 * These follow the posted lecture notes at
 * https://faculty.cc.gatech.edu/~ladha/algo/ section by section.
 */
export const refreshers = {
  "divide-conquer": [
    "Runtime is a function of the SIZE of the input. A number x takes log x bits, so \"linear in x\" is exponential.",
    "f1 naive recursion: T(n) = T(n-1) + T(n-2) + 3 > 2^(n/2). Exponential because subproblems overlap.",
    "f2 iterative table: n additions, T(n) < n². f3 matrix powers: log n matrix mults by repeated squaring. f4 diagonalization: A^n = PD^nP⁻¹, constant many ops.",
    "O ≤, Ω ≥, Θ =, o <, ω >. Big-O is a property of f, not an equation. f is never o(f).",
    "Log base does not matter (change of base is a constant factor). Most algorithms are Ω(n) since reading the input costs that; binary search is the classic exception."
  ],
  "master-theorem": [
    "T(n) = a·T(n/b) + O(n^d). Compare d with log_b a: d > log_b a ⇒ O(n^d); d = log_b a ⇒ O(n^d log n); d < log_b a ⇒ O(n^(log_b a)).",
    "Level i costs n^d·(a/b^d)^i, so the three cases are just whether that geometric ratio is <, =, or > 1.",
    "The gap must be POLYNOMIAL — n/log n falls in a gap the theorem cannot decide.",
    "Merge sort: a=2, b=2, d=1, tie ⇒ O(n log n). Worst case, always; stable; Θ(n) extra space.",
    "Binary search: a=1, b=2, d=0, tie ⇒ O(log n). Does not apply to T(n−1)-style or unequal-split recurrences."
  ],
  "arithmetic": [
    "A number x needs n = log x bits. Log base is irrelevant asymptotically.",
    "Addition is Θ(n) — O(n) by grade school, Ω(n) to read and write. Provably optimal.",
    "Multiplication: grade school O(n²); Al-Khwarizmi recursive O(n²); 4-way split T(n)=4T(n/2)+O(n)=O(n²); Karatsuba T(n)=3T(n/2)+O(n)=O(n^log₂3 ≈ n^1.59).",
    "Karatsuba trick: x_L y_R + x_R y_L = (x_L+x_R)(y_L+y_R) − x_L y_L − x_R y_R.",
    "Exponentiation by repeated squaring: log x multiplications. modexp is n calls × O(n²) mult = O(n³).",
    "Matrix mult: naive O(n³); 8-way block split T(n)=8T(n/2)+O(n²)=O(n³); Strassen 7 products = O(n^log₂7 ≈ n^2.81). Best known O(n^2.37286)."
  ],
  "quicksort": [
    "Partition (Lomuto, pivot A[u]): invariant is l..i ≤ pivot and i+1..j−1 > pivot; the final swap puts the pivot at i+1, its sorted position. O(n).",
    "Best case: balanced split, T(n) = 2T(n/2) + O(n) = O(n log n).",
    "Worst case: split n−1 and 0 (pivot is min or max — happens on SORTED input), T(n) = T(n−1) + O(n) = O(n²).",
    "Average intuition: even a 999:1 split gives log_(1000/999) n = O(log n) levels ⇒ O(n log n). A constant FRACTION matters, not a constant distance.",
    "Average derivation: T(n) = (1/n)Σ[T(i)+T(n−i+1)] + n; the two sums are permutations of each other; telescope to T(n)/(n+1) = T(n−1)/n + 2/(n+1); harmonic sum ⇒ O(n log n).",
    "P[max pivot every time] = 1/n!. Randomizing the pivot makes the average case hold on any input. Not stable, in place.",
    "Quickselect (videos, not L4.pdf): recurse on ONE side ⇒ O(n) expected; median-of-medians gives O(n) worst case."
  ],
  "dfs-scc": [
    "Adjacency matrix: O(1) edge lookup, Θ(V²) space, good when dense. Adjacency list: O(V+E) space, good when sparse — which real graphs are.",
    "explore(G,v) covers ONE component; dfs(G) loops over all vertices. Counting top-level explore calls counts components.",
    "pre/post intervals nest or are disjoint. Back edge ⇔ cycle. Detect with a t-marked (on-stack) set, not just marked.",
    "Topological order = decreasing post number (DAGs only).",
    "SCC lemma: an edge from C to C-prime forces max post in C > max post in C-prime. Algorithm: DFS on G for post labels, then explore G^R in decreasing post order. Θ(V+E).",
    "The metagraph (condensation) of the SCCs is always a DAG."
  ],
  "bfs-dijkstra": [
    "Relax(u,v): if dist[u] + l(u,v) < dist[v], update. BFS, Dijkstra, and Bellman-Ford differ only in the ORDER of relaxations.",
    "BFS: FIFO queue, Θ(V+E), unit weights only. Dijkstra is weighted BFS with a priority queue.",
    "Dijkstra: deleteMin finalizes a vertex; needs all weights ≥ 0. |V| deleteMins and |E| decreaseKeys.",
    "PQ costs: array O(V²) (best when dense); binary heap O((V+E) log V); d-ary heap O((Vd+E)·logV/logd); Fibonacci heap O(E + V log V).",
    "Adding a constant to all weights does NOT fix negative edges — it penalizes longer paths."
  ],
  "kruskal": [
    "Greedy: take the local best and solve the rest. Often wrong (luggage sizes 35,40,40,70 into 100), but provably right for MST.",
    "MST T is Minimum (least total weight), Spanning (touches every vertex), and a Tree (|V|−1 edges, no cycle).",
    "Kruskal: sort edges by weight, accept an edge if find(u) ≠ find(v), then union. O(E log E) = O(E log V), dominated by the sort.",
    "Cut property: the lightest edge across any cut is in some MST (in every MST if weights are distinct). Proved by an exchange argument.",
    "Cycle property: the unique heaviest edge on a cycle is in no MST.",
    "Union by rank + path compression ⇒ O(α(n)) amortized. MST ≠ shortest-path tree."
  ],
  "bellman-floyd": [
    "Negative edges break Dijkstra invariant. Negative CYCLES make shortest path ill-defined (−∞).",
    "Bellman-Ford: |V|−1 rounds relaxing every edge, O(VE). After round i, all shortest paths using ≤ i edges are correct.",
    "Negative cycle detection: run one extra round; if any distance still decreases, a negative cycle is reachable.",
    "DAG shortest path: relax in topological order. Θ(V+E), negatives fine, faster than Dijkstra. This is the DP sneak peek.",
    "Floyd-Warshall: dist(i,j,k) = shortest i to j using only v1..vk as intermediates; dist(i,j) = min(dist(i,j), dist(i,k)+dist(k,j)) with k OUTERMOST. Θ(V³). Negative cycle ⇔ d[i][i] < 0.",
    "All-pairs needs Ω(V²) just to output. Dijkstra run V times is O((V²+VE) log V) — worse than Θ(V³) when dense."
  ],
  "kirchhoff": [
    "L = D − A. Every row sums to 0, so det(L) = 0 always.",
    "Matrix Tree Theorem: the number of spanning trees equals any cofactor of L (delete row i and column i, take the determinant).",
    "All cofactors are equal. Computable in O(n³) by Gaussian elimination.",
    "Cayley: K_n has n^(n−2) spanning trees. C_n has n. A tree has 1. A disconnected graph has 0.",
    "The number of zero eigenvalues of L equals the number of connected components."
  ],
  "dp-intro": [
    "Bottom up (iteration) is emphasized. DP vs D&C: DP subproblems OVERLAP, so recomputing them is wasteful.",
    "Every DP: a memory structure, base cases on it, and a recurrence filling it. Runtime = (table size) × (work per cell).",
    "Stairs (leap 1/2/3): T[i] = T[i−1]+T[i−2]+T[i−3]; base 1,1,2 ⇒ 1,1,2,4,7,13,24,44,81,149.",
    "Min ops from 0 to k (+1, ×2): d(i) = d(i−1)+1 if odd, min(d(i−1)+1, d(i/2)+1) if even. NOT monotonic — 8 is cheaper than 7.",
    "House robber: T[i] = max(T[i−2]+H[i], T[i−1]); base T[0]=H[0], T[1]=max(H[0],H[1]). On [2,7,9,3,1] the table is [2,7,11,11,12].",
    "Grid paths: T[i][j] = T[i−1][j] + T[i][j−1], first row and column all 1. With bombs T=0 on a bomb cell — the closed form dies, the recurrence barely changes.",
    "Optimal substructure, proved by cut-and-paste. Longest simple path lacks it (and is NP-hard)."
  ],
  "subsequences": [
    "Substring = contiguous. Subsequence = order preserved, gaps allowed.",
    "Longest common SUBSTRING: solve longest common SUFFIX. T[i][j] = T[i−1][j−1]+1 if x_i=y_j, else 0. Answer = table MAXIMUM. O(nm).",
    "Longest common SUBSEQUENCE: T[i][j] = T[i−1][j−1]+1 if x_i=y_j, else max(T[i−1][j], T[i][j−1]). Answer = T[m][n]. O(nm).",
    "The two differ ONLY in the mismatch case: reset to 0 versus take the max.",
    "Longest palindromic subsequence = LCS(x, reverse(x)); or directly T[i][j] = 2+T[i+1][j−1] if x_i=x_j, else max(T[i+1][j], T[i][j−1]), base T[i][i]=1. Fill by increasing interval length. O(n²).",
    "Backtracking arrows: diagonal on a match (emits a character), left/up record which neighbor won the max."
  ],
  "chain-matrix": [
    "A p×q times a q×r matrix costs p·q·r scalar multiplications.",
    "C[i][j] = min over i ≤ k < j of C[i][k] + C[k+1][j] + m_(i−1)·m_k·m_j. Choose where the LAST multiplication happens.",
    "Fill by increasing interval length. Θ(n³) time, Θ(n²) space.",
    "n matrices are described by n+1 dimensions. Store the argmin split S[i][j] for traceback.",
    "(AB)C = 4500 vs A(BC) = 27000 for 10×30, 30×5, 5×60. Same result, 6x the work. Greedy fails."
  ],
  "knapsack": [
    "0/1: K[i][w] = max(K[i−1][w], v_i + K[i−1][w−w_i]). The take branch uses row i−1, which is what forbids reuse.",
    "Unbounded (repetition): the take branch uses row i, or collapse the whole table to K[w].",
    "Θ(nW) is PSEUDO-polynomial — W takes only log W bits, so the table is exponential in the input size.",
    "Linear space: keep one array and iterate capacity DOWNWARD (upward turns it into the unbounded version).",
    "The ratio greedy is optimal for FRACTIONAL knapsack only. An FPTAS exists via value rounding."
  ],
  "tree-dp": [
    "Root the tree; the subproblem is a subtree, evaluated in POST-order (children before parents).",
    "Max-weight independent set: in[v] = w(v) + Σ out[c]; out[v] = Σ max(in[c], out[c]).",
    "Min vertex cover: in[v] = 1 + Σ min(in[c], out[c]); out[v] = Σ in[c].",
    "MIS + MVC = n in any graph, so solving one solves the other.",
    "Θ(n) — one pass per edge. NP-hard on general graphs; generalizes to bounded treewidth."
  ],
  "np-completeness": [
    "Reductions prove lower bounds: sorting-indices is Ω(n log n), because indices plus O(n) work would give an o(n log n) sort.",
    "Decision problems only. P = solvable in poly time; NP = VERIFIABLE in poly time (witness plus poly-time verifier). P ⊆ NP, since a verifier can ignore the witness and just solve.",
    "Examples: PATH in P (BFS), RELPRIME in P (GCD), COMPOSITES in NP (witness = the factors).",
    "L ⊆ P ⊆ NP ⊆ PSPACE ⊆ EXP, and P ⊊ EXP is provable, so at least one containment is strict.",
    "A ≤p B: a poly-time f with x in A ⇔ f(x) in B. It means B is HARDER. To prove B hard, reduce FROM known-hard TO B.",
    "NP-complete = in NP AND NP-hard. Cook-Levin: SAT is NP-complete. Any NP-complete problem in P ⇒ P = NP."
  ],
  "hard-graph": [
    "Template for all three: (1) show membership in NP with a verifier, (2) show NP-hardness by reduction.",
    "INDEPENDENT-SET = {<G,g> | G has an independent set of size g}. Verifier: check the size is g and no edge lies inside.",
    "3SAT ≤p IS: one triangle per clause (a vertex per literal), an edge between every pair of contradictory literals, and g = the number of clauses.",
    "IS ≤p CLIQUE: the complement graph, <G,g> maps to <Gbar,g>. The converse is free because the complement of Gbar is G.",
    "IS ≤p VERTEX-COVER: <G,g> maps to <G, |V|−g>. The graph is unchanged. S is a cover ⇔ V\\S is independent, so MIS + MVC = n.",
    "Complementary but NOT equally approximable: VC has a 2-approximation, IS has essentially none.",
    "Easy cases: trees (Θ(n) DP), bipartite (Koenig plus max-flow), bounded treewidth, VC with small k (FPT).",
    "Graph coloring (video L13A): 2-coloring is in P (bipartite \u21d4 no odd cycle, BFS); 3-coloring is NP-complete. \u03c7(G) \u2265 \u03c9(G) and \u03c7(G) \u2264 \u0394(G)+1; greedy is order-dependent with no guarantee."
  ],
  "hard-constraint": [
    "Literal = a variable or its negation; clause = an OR of literals; CNF = an AND of clauses. SAT is NP-complete by Cook-Levin.",
    "SAT ≤p 3SAT: (x1 v ... v x_(k−1) v x_k) becomes (x1 v ... v x_(k−2) v z) AND (x_(k−1) v x_k v NOT z) with a fresh z. Repeat until every clause has size 3. Extends to kSAT for k ≥ 3.",
    "2SAT is in P: (a v b) is the pair of implications NOT a implies b, NOT b implies a. Unsatisfiable exactly when some x and NOT x share an SCC of the implication graph.",
    "3SAT ≤p circuitSAT: an OR sub-circuit per clause, all ANDed at a root gate; the verifier just runs the circuit.",
    "3SAT ≤p SubsetSum: a column per variable and per clause, in a base high enough to prevent carrying; literal rows give the assignment (variable target 1); TWO slack rows per clause, with clause target 3.",
    "SubsetSum ≤p Knapsack: make the item (s_i, s_i) with weight = value, and set W = V = t.",
    "O(nt) is PSEUDO-polynomial — t is written in log t bits. Both problems are only weakly NP-hard."
  ],
  "tsp": [
    "The decision version (cost ≤ B) is NP-complete; the certificate is the tour.",
    "Hamiltonian Cycle ≤p TSP: existing edges cost 1, non-edges cost 2, ask for a tour of cost ≤ n. Those weights are metric, so metric TSP is NP-hard too.",
    "Held-Karp: C[S][j], O(2^n n²) time and O(2^n n) space. Brute force is (n−1)!.",
    "Metric TSP: MST doubling gives 2 (MST ≤ OPT, and shortcutting is free by the triangle inequality); Christofides gives 3/2.",
    "General TSP: no constant-factor approximation unless P = NP."
  ],
  "matroids": [
    "A matroid is hereditary plus the exchange property. All bases have the same size (the rank).",
    "Rado-Edmonds: greedy is optimal for every weight function exactly when the system is a matroid.",
    "The graphic matroid (forests) gives Kruskal. Knapsack fails exchange, so greedy fails there.",
    "Submodular: f(A + x) − f(A) ≥ f(B + x) − f(B) whenever A is a subset of B. Diminishing returns.",
    "Submodular minimization is in P; monotone maximization under a cardinality constraint: greedy gives 1 − 1/e, and that is tight."
  ],
  "max-flow": [
    "A flow network has a single source s, a single sink t, and capacities c(u,v) ≥ 0. A valid flow obeys capacity and conservation.",
    "A cut (L,R) has s in L and t in R; its capacity is the total capacity of the L-to-R edges. Every flow ≤ every cut, so max flow ≤ min cut.",
    "Residual graph: forward c−f, backward f. The backward edges are what let the algorithm undo an earlier decision.",
    "Ford-Fulkerson is an approach, not a fixed algorithm — the path choice is unspecified, so runtimes vary. Edmonds-Karp (BFS) is O(VE²); Dinic is O(V²E).",
    "Max-Flow Min-Cut: at termination, L = the vertices reachable from s in the residual graph. Edges out of L are saturated and edges into L are empty, so the cut capacity equals the flow value.",
    "Integrality theorem with integer capacities gives bipartite matching, edge-disjoint paths, and baseball elimination.",
    "Baseball elimination: s to game nodes (capacity = games left between that pair), game nodes to both team nodes (infinite), team node j to t (capacity = w_i + r_i − w_j). Team i survives exactly when every edge out of s saturates."
  ],
  "linear-programming": [
    "max c^T x subject to Ax ≤ b, x ≥ 0. A is m×n (m constraints, n variables), b is m×1, c is n×1.",
    "The feasible region is a convex polytope, and an optimum always occurs at a VERTEX because the objective is linear.",
    "Three outcomes: optimal, infeasible, unbounded.",
    "Simplex: start at a corner, move to any better neighboring corner, stop when none is better. Convexity makes that local check global.",
    "Shortest path as an LP: max d_t subject to d_v ≤ d_u + w(u,v) and d_s = 0. Maximize, or d_t = 0 satisfies everything.",
    "Max flow as an LP: maximize the net outflow of s subject to f ≤ c, f ≥ 0, and conservation. An equality splits into two inequalities.",
    "Knapsack is an ILP, not an LP. ILP is NP-complete: reduce from Vertex Cover with x_u + x_v ≥ 1 per edge and 0/1 variables.",
    "LP is in P (ellipsoid, interior point); simplex is exponential in the worst case. Total unimodularity gives integral vertices, so LP = IP."
  ],
  "lp-duality": [
    "Primal max c^T x s.t. Ax ≤ b, x ≥ 0. Dual min b^T y s.t. A^T y ≥ c, y ≥ 0. m primal constraints give m dual variables. The dual of the dual is the primal.",
    "Weak duality: c^T x ≤ b^T y for any feasible pair. So equal values prove both optimal, and an unbounded primal forces an infeasible dual.",
    "Strong duality: the optima are equal for LPs. No duality gap, unlike integer programs.",
    "Simplex in slack form: s = b − Ax; basic (left) versus nonbasic (right) variables, with nonbasic set to 0. Pivot: the entering variable has the largest positive coefficient in z, the leaving variable owns the tightest constraint. Substitute and repeat until every z coefficient is negative.",
    "Simplex solves the dual at the same time: from the final z = v + sum of c_j x_j, set y_i = −c_(n+i) when x_(n+i) is nonbasic, and 0 otherwise.",
    "Certifying optimality by hand: add constraints with non-negative multipliers until the left side dominates the objective. Those multipliers ARE a feasible dual solution.",
    "Simplex runtime: polynomial on average, but up to C(m+n, n) iterations of O(mn) work in the worst case."
  ],
  "randomized": [
    "Las Vegas: always correct, random running time. Monte Carlo: bounded time, sometimes wrong.",
    "Linearity of expectation holds without independence — the workhorse of these analyses.",
    "Karger: contract random edges; success probability at least 2/(n(n−1)) per run; amplify with O(n² log n) runs.",
    "Amplification: the failure probability (1−p)^k ≤ e^(−pk) decays exponentially in the number of trials.",
    "Markov ≤ Chebyshev ≤ Chernoff in strength and in the assumptions each needs."
  ],
  "approximation": [
    "An alpha-approximation runs in polynomial time AND has a proven ratio on EVERY input.",
    "Always compare against a computable lower bound, never against OPT itself.",
    "Vertex cover: take both endpoints of each uncovered edge; the picked edges form a matching, so OPT ≥ |M| and |C| = 2|M| ≤ 2·OPT. The bound is tight.",
    "Set cover: greedy gives H_n ≈ ln n, and that is optimal unless P = NP.",
    "Hierarchy: FPTAS (knapsack), PTAS (Euclidean TSP), constant factor (VC, metric TSP), logarithmic (set cover), inapproximable (general TSP, max independent set)."
  ]
};
