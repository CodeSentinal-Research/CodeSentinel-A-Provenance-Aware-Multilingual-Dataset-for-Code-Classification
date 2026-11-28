export const mockOutline = [
  {
    unit: 'Graph Theory Fundamentals',
    topics: [
      {
        id: '1',
        name: 'Eulerian Paths & Circuits',
        description:
          'Konigsberg bridge problem, Eulerian paths, circuits, and Fleury algorithm conditions.',
        selected: true,
      },
      {
        id: '2',
        name: 'Hamiltonian Cycles & TSP',
        description:
          'Hamiltonian cycles, Diracs and Ore theorems, and the Traveling Salesperson Problem.',
        selected: true,
      },
    ],
  },
  {
    unit: 'Linear Data Structures',
    topics: [
      {
        id: '3',
        name: 'Singly & Doubly Linked Lists',
        description: 'Pointers, node insertion, deletion, and traversal algorithms.',
        selected: true,
      },
      {
        id: '4',
        name: 'Stack & Queue Implementations',
        description: 'Stack and queue ADTs using arrays and linked lists, plus applications.',
        selected: true,
      },
    ],
  },
];

export const mockNotesData = {
  'Eulerian Paths & Circuits': {
    topicName: 'Eulerian Paths & Circuits',
    priority: {
      level: 'VERY HIGH',
      reason: 'Asked almost every semester in Graph Theory exams across both theory and application problems.',
    },
    sourceLocation: 'Slides 12-19, Unit 1',
    definitions: [
      'An Eulerian circuit is a closed walk that uses every edge of a graph exactly once.',
      'An Eulerian trail is a walk that uses every edge exactly once but is allowed to start and end at different vertices.',
    ],
    sourceContent: {
      heading: 'What the source says',
      content:
        'The lecture introduces the Konigsberg bridge problem, proves the existence conditions for Eulerian trails, and demonstrates Fleury algorithm for constructing them.',
    },
    easyExplanation: {
      heading: 'In very easy words',
      content:
        'Imagine drawing a figure without lifting your pen and without retracing a line. If you end where you started, it is an Eulerian circuit; if you end somewhere else, it is an Eulerian trail.',
    },
    analogy:
      'Think of a postman who must cover every street exactly once to deliver mail. A single postman can do the route without doubling back only if the street map has at most two dead ends.',
    keyPoints: [
      'A connected graph has an Eulerian circuit iff every vertex has even degree.',
      'A connected graph has an Eulerian trail iff exactly zero or two vertices have odd degree.',
      'Fleury algorithm avoids bridges until no other choice remains.',
      'The Konigsberg bridge network has four odd vertices, so it cannot be walked exactly once.',
    ],
    diagram: {
      title: 'Eulerian condition checklist',
      caption: 'Decision tree for selecting Eulerian circuit, trail, or neither.',
      svg:
        '<svg viewBox="0 0 400 220" xmlns="http://www.w3.org/2000/svg"><rect x="1" y="1" width="398" height="218" rx="10" fill="none" stroke="#5b6b7c" stroke-width="1.5" stroke-dasharray="4 3"/><circle cx="80" cy="110" r="46" fill="none" stroke="#2f6ca3" stroke-width="2"/><circle cx="80" cy="110" r="5" fill="#2f6ca3"/><text x="80" y="113" font-family="Verdana" font-size="11" text-anchor="middle" fill="#334155">Start</text><path d="M130 100 C 190 82, 210 82, 270 98" fill="none" stroke="#334155" stroke-width="1.5"/><text x="200" y="80" font-family="Verdana" font-size="10" text-anchor="middle" fill="#334155">all degrees even?</text><circle cx="320" cy="110" r="46" fill="none" stroke="#0d9488" stroke-width="2"/><circle cx="320" cy="110" r="5" fill="#0d9488"/><text x="320" y="113" font-family="Verdana" font-size="11" text-anchor="middle" fill="#334155">Circuit</text></svg>',
      examDrawingSteps: [
        'Draw a connected graph with all even degree vertices and label them.',
        'Mark one vertex as the start and trace a closed trail covering every edge.',
        'Circle the start vertex to show the walk returns home.',
      ],
    },
    codeExample: {
      language: 'Python',
      code:
        'def is_eulerian(g):\n    if not is_connected(g):\n        return "neither"\n    odd = sum(1 for v in g if len(g[v]) % 2 == 1)\n    if odd == 0:\n        return "circuit"\n    if odd == 2:\n        return "trail"\n    return "neither"',
      explanation:
        'The function first checks connectivity, then counts odd-degree vertices to classify the graph.',
    },
    workedExample: {
      title: 'Verify the Konigsberg graph',
      given: 'Four landmasses with seven bridges as a multigraph.',
      required: 'Decide whether a route covering every bridge exactly once exists.',
      formula: 'Count the degree of every vertex; Euler requires 0 or 2 odd.',
      substitution: 'Degrees: 3, 3, 3, 5.',
      calculation: 'Four odd-degree vertices, so neither trail nor circuit exists.',
      answer: 'No such route exists.',
      interpretation:
        'Any solution must walk some bridge twice, which is exactly what the townspeople discovered in 1735.',
    },
    memoryTricks: [
      {
        mnemonic: 'EVEN = CIRCUIT',
        meaning: 'All even degrees means you can end where you started.',
        explanation: 'Associate even with a closed loop returning home.',
      },
    ],
    examTips: [
      'State both conditions (connectivity + degree) before naming Eulerian.',
      'For Fleury, say why you avoid bridges: cutting the graph leaves you stranded.',
    ],
    commonMistakes: [
      'Forgetting to check connectivity first, which makes the degree test wrong.',
      'Claiming Eulerian trail when more than two vertices have odd degree.',
    ],
    quickRecallQuestions: [
      'What is the degree condition for an Eulerian circuit?',
      'Where does Fleury algorithm direct you to avoid a bridge?',
    ],
    examQuestions: {
      twoMark: [
        { question: 'Define an Eulerian circuit.', modelAnswer: 'A closed walk covering every edge exactly once.' },
      ],
      fiveMark: [
        {
          question:
            'Prove that a connected graph has an Eulerian circuit iff every vertex has even degree.',
          modelAnswer: 'Necessity by pairing edges through each vertex on the closed walk; sufficiency by induction using a maximal trail that must use all edges if any edge lies in a cycle component reachable from it.',
        },
      ],
      tenMark: [
        {
          question: 'State and demonstrate Fleury algorithm on a small graph.',
          answerStructure: 'Definition, algorithm steps, worked trace, complexity, correctness sketch.',
          modelAnswer:
            'Present the bridge-avoidance rule, trace construction on a sample graph, and note the O(E^2) bound with runtimes per step.',
        },
      ],
    },
  },
  'Hamiltonian Cycles & TSP': {
    topicName: 'Hamiltonian Cycles & TSP',
    priority: { level: 'HIGH', reason: 'Classic exam pairing with TSP greedy and DP formulations.' },
    sourceLocation: 'Slides 21-30, Unit 1',
    definitions: [
      'A Hamiltonian cycle visits every vertex exactly once and returns to the start.',
      'The Traveling Salesperson Problem asks for the minimum-cost Hamiltonian cycle in a weighted graph.',
    ],
    sourceContent: {
      heading: 'What the source says',
      content:
        'Covers Dirac and Ore sufficient conditions, the NP-hard nature of the decision problem, and brute-force versus DP over subsets.',
    },
    easyExplanation: {
      heading: 'In very easy words',
      content:
        'A Hamiltonian cycle is a round trip that stops at every city once and comes home. The TSP asks for the cheapest such round trip.',
    },
    analogy:
      'Plan a road trip hitting every city once and returning to your garage. The cheapest complete tour is the answer, and checking every order is explosively slow.',
    keyPoints: [
      'Dirac: if n >= 3 and every degree >= n/2, a Hamiltonian cycle exists.',
      'Ore: if deg(u) + deg(v) >= n for every non-adjacent pair, a cycle exists.',
      'TSP is NP-hard; exact solutions use DP over subsets in O(n^2 * 2^n).',
      'The greedy nearest-neighbour heuristic is fast but not optimal.',
    ],
    diagram: {
      title: 'Cycle vs complete tour',
      caption: 'A Hamiltonian cycle visiting every vertex once on a five-city graph.',
      svg:
        '<svg viewBox="0 0 400 220" xmlns="http://www.w3.org/2000/svg"><rect x="1" y="1" width="398" height="218" rx="10" fill="none" stroke="#5b6b7c" stroke-width="1.5" stroke-dasharray="4 3"/><circle cx="200" cy="60" r="6" fill="#2f6ca3"/><circle cx="300" cy="150" r="6" fill="#2f6ca3"/><circle cx="100" cy="150" r="6" fill="#2f6ca3"/><circle cx="250" cy="190" r="6" fill="#0d9488"/><circle cx="150" cy="190" r="6" fill="#0d9488"/><path d="M200 60 L300 150 L250 190 L150 190 L100 150 Z" fill="none" stroke="#0d9488" stroke-width="2"/><path d="M100 150 L200 60 L300 150" fill="none" stroke="#334155" stroke-width="1"/></svg>',
      examDrawingSteps: [
        'Plot the vertices in a rough circle.',
        'Connect them in tour order with a closed polygon.',
        'Label start and arrow the direction of travel.',
      ],
    },
    workedExample: {
      title: 'Cheapest tour of four cities',
      given: 'Distances A-B 10, A-C 15, A-D 20, B-C 35, B-D 25, C-D 30.',
      required: 'Minimum Hamiltonian cycle.',
      formula: 'Brute force: (n-1)!/2 distinct tours.',
      substitution: 'Tours: A-B-C-D-A = 100, A-B-D-C-A = 95, A-C-B-D-A = 90.',
      calculation: 'All fixed tours only change cost by edge choice; optimum = 90.',
      answer: 'A-C-B-D-A at cost 90.',
      interpretation: 'Nearest-neighbour greedy starting at A gives A-B-D-C = 95, proving greedy is not always optimal.',
    },
    memoryTricks: [
      { mnemonic: 'HALF-DEGREE = HAMILTON', meaning: 'Dirac gives cycles when degrees are at least n/2.', explanation: 'Tie the bound to the name to recall it under time pressure.' },
    ],
    examTips: [
      'Cite exactly which theorem you use; Dirac and Ore are distinct.',
      'Write the DP recurrence T(S, i) = min over j to build the dynamic table.',
    ],
    commonMistakes: [
      'Confusing Eulerian (edges) with Hamiltonian (vertices).',
      'Assuming nearest-neighbour is optimal for TSP.',
    ],
    quickRecallQuestions: [
      'What differs between Dirac and Ore sufficient conditions?',
      'Why is TSP called NP-hard rather than polynomial?',
    ],
    examQuestions: {
      twoMark: [
        { question: 'Define a Hamiltonian cycle.', modelAnswer: 'A cycle that visits each vertex exactly once and returns to the start.' },
      ],
      fiveMark: [
        {
          question: 'Prove Dirac theorem for a small graph.',
          modelAnswer: 'Construct a longest path, show endpoints must be adjacent to internal vertices, then close the cycle when every remaining vertex connects to more than half the others.',
        },
      ],
      tenMark: [
        {
          question: 'Formulate TSP with dynamic programming and compare with greedy.',
          answerStructure: 'Set up subsets, recurrence, trace, complexity, and comparison table.',
          modelAnswer: 'Show T(S,i) recurrence, run on the worked example, note O(n^2 2^n) versus O(n^2 log n) for greedy with a correctness caveat.',
        },
      ],
    },
  },
  'Singly & Doubly Linked Lists': {
    topicName: 'Singly & Doubly Linked Lists',
    priority: { level: 'MEDIUM', reason: 'Core implementation topic; memory diagrams are frequent exam asks.' },
    sourceLocation: 'Slides 4-11, Unit 2',
    definitions: [
      'A linked list stores elements in nodes, each pointing to the next node, allowing O(1) insertion and deletion at known positions.',
      'A doubly linked list adds a previous pointer, enabling O(1) backward traversal and deletion of the previous node.',
    ],
    sourceContent: {
      heading: 'What the source says',
      content: 'Covers node structure, traversal, insertion at head and tail, deletion, and trade-offs against arrays.',
    },
    easyExplanation: {
      heading: 'In very easy words',
      content:
        'A linked list is a chain where each box points to the next. You always know the first box, and you walk the chain to reach any other.',
    },
    analogy:
      'A conga line: each dancer holds the shoulders of the person ahead. You can only leave the line by knowing who is already joined.',
    keyPoints: [
      'Head pointer alone stores the whole list.',
      'Insertion and deletion at the head are O(1), unlike arrays.',
      'Doubly linked lists add O(1) deletion of a given node.',
      'Cache locality is worse than arrays because nodes scatter in memory.',
    ],
    diagram: {
      title: 'Node-link anatomy',
      caption: 'A three-node singly linked list with head and null terminator.',
      svg:
        '<svg viewBox="0 0 400 160" xmlns="http://www.w3.org/2000/svg"><rect x="1" y="1" width="398" height="158" rx="10" fill="none" stroke="#5b6b7c" stroke-width="1.5" stroke-dasharray="4 3"/><rect x="40" y="55" width="52" height="46" fill="#2f6ca3"/><rect x="92" y="55" width="52" height="46" fill="none" stroke="#2f6ca3" stroke-width="2"/><rect x="164" y="55" width="52" height="46" fill="#2f6ca3"/><rect x="216" y="55" width="52" height="46" fill="none" stroke="#2f6ca3" stroke-width="2"/><rect x="288" y="55" width="52" height="46" fill="#0d9488"/><path d="M144 78 L164 78" stroke="#334155" stroke-width="1.5"/><path d="M268 78 L288 78" stroke="#334155" stroke-width="1.5"/><text x="40" y="70" font-family="Verdana" font-size="11" fill="#fff">data</text><text x="66" y="82" font-family="Verdana" font-size="11" fill="#fff">head</text><text x="44" y="92" font-family="Verdana" font-size="10" fill="#fff">next</text><text x="200" y="40" font-family="Verdana" font-size="10" fill="#334155">head</text><text x="306" y="82" font-family="Verdana" font-size="10" fill="#0b1521">NULL</text><text x="306" y="70" font-family="Verdana" font-size="10" fill="#0b1521">null</text></svg>',
      examDrawingSteps: [
        'Draw the node boxes and fill data values.',
        'Draw arrows from each next pointer to the following node.',
        'Terminate the final pointer at NULL.',
      ],
    },
    memoryTricks: [
      { mnemonic: 'HEAD KNOWS FIRST', meaning: 'Everything starts from the head pointer.', explanation: 'Recite this before complexity questions about linked lists.' },
    ],
    examTips: [
      'Always update the head when inserting or deleting at position zero.',
      'Draft the pointer sequence before touching code in exams.',
    ],
    commonMistakes: [
      'Losing the head pointer and stranding the list.',
      'Forgetting to update previous pointers in a doubly linked list.',
    ],
    quickRecallQuestions: [
      'Why is array access faster than linked-list access?',
      'When is a doubly linked list strictly better than a singly linked list?',
    ],
    examQuestions: {
      fiveMark: [
        { question: 'Insert a node at the head of a doubly linked list.', modelAnswer: 'Create the node, set its next to old head, set its prev to null, and adjust old head prev to the new node; then move head.' },
      ],
    },
  },
  'Stack & Queue Implementations': {
    topicName: 'Stack & Queue Implementations',
    priority: { level: 'HIGH', reason: 'Frequent application questions: expression evaluation, BFS, and circular queues.' },
    sourceLocation: 'Slides 13-20, Unit 2',
    definitions: [
      'A stack is a LIFO structure supporting push and pop in O(1) at one end.',
      'A queue is a FIFO structure supporting enqueue and dequeue in O(1).',
    ],
    sourceContent: {
      heading: 'What the source says',
      content: 'Presents array and linked-list variants, circular queue wrap-around, and classic applications.',
    },
    easyExplanation: {
      heading: 'In very easy words',
      content:
        'A stack is a stack of plates: you use the top one. A queue is a ticket line: the first person in is the first person out.',
    },
    analogy:
      'Browser back button is a stack of pages. Printer jobs form a queue that prints in arrival order.',
    keyPoints: [
      'Array stack resizes by doubling to keep amortized O(1).',
      'A circular queue reuses freed slots with modular arithmetic.',
      'Stacks evaluate postfix expressions; queues drive BFS.',
      'Both have O(1) worst-case operations when built on linked lists.',
    ],
    diagram: {
      title: 'Circular queue wrap-around',
      caption: 'Front and rear pointers wrapping in a fixed-size circular buffer.',
      svg:
        '<svg viewBox="0 0 400 160" xmlns="http://www.w3.org/2000/svg"><rect x="1" y="1" width="398" height="158" rx="10" fill="none" stroke="#5b6b7c" stroke-width="1.5" stroke-dasharray="4 3"/><rect x="30" y="55" width="40" height="46" fill="#2f6ca3"/><rect x="70" y="55" width="40" height="46" fill="none" stroke="#2f6ca3" stroke-width="2"/><rect x="110" y="55" width="40" height="46" fill="none" stroke="#2f6ca3" stroke-width="2"/><rect x="150" y="55" width="40" height="46" fill="#0d9488"/><rect x="190" y="55" width="40" height="46" fill="none" stroke="#2f6ca3" stroke-width="2"/><rect x="230" y="55" width="40" height="46" fill="none" stroke="#2f6ca3" stroke-width="2"/><rect x="270" y="55" width="40" height="46" fill="#0d9488"/><text x="30" y="82" font-family="Verdana" font-size="10" text-anchor="middle" fill="#fff">a</text><text x="150" y="82" font-family="Verdana" font-size="10" text-anchor="middle" fill="#0b1521">b</text><text x="270" y="82" font-family="Verdana" font-size="10" text-anchor="middle" fill="#0b1521">c</text><text x="50" y="125" font-family="Verdana" font-size="10" text-anchor="middle" fill="#0d9488">front</text><path d="M50 115 L50 101" stroke="#0d9488" stroke-width="1.5"/><text x="250" y="125" font-family="Verdana" font-size="10" text-anchor="middle" fill="#2f6ca3">rear</text><path d="M250 115 L250 101" stroke="#2f6ca3" stroke-width="1.5"/></svg>',
      examDrawingSteps: [
        'Draw a row of fixed-size cells.',
        'Mark front and rear pointers.',
        'Wrap the rear pointer back to index zero on the next enqueue.',
      ],
    },
    workedExample: {
      title: 'Evaluate postfix 5 3 + 2 *',
      given: 'Tokens 5, 3, +, 2, *.',
      required: 'Result using a stack.',
      formula: 'Pop two operands, apply operator, push result.',
      substitution: 'Push 5, push 3, pop 5 3 => 8, push 8, push 2, pop 8 2 => 16.',
      calculation: 'Final stack contains 16.',
      answer: '16.',
      interpretation: 'Postfix removes all parentheses ambiguity by construction.',
    },
    memoryTricks: [
      { mnemonic: 'FIFO CANT CUT, LIFO CAN', meaning: 'Queue is first-in-first-out; stack is last-in-first-out.', explanation: 'Remember LIFO like a stack of plates.' },
    ],
    examTips: [
      'Mention amortized analysis when discussing dynamic array resizing.',
      'Illustrate queue behavior with a draw-front and wrap example.',
    ],
    commonMistakes: [
      'Confusing front with rear during circular wrap-around.',
      'Forgetting queue overflow checks before any enqueue.',
    ],
    quickRecallQuestions: [
      'Name three applications of stacks.',
      'What does wrap-around do to a circular queue?',
    ],
    examQuestions: {
      twoMark: [{ question: 'State FIFO and LIFO with one application each.', modelAnswer: 'FIFO queue for printer jobs; LIFO stack for function call frames.' }],
    },
  },
};

export const mockMasterSummary = {
  summaryTable: [
    {
      topic: 'Eulerian Paths & Circuits',
      coreTakeaway: 'Every edge exactly once; even degrees decide circuit vs trail.',
      criticalMetric: 'deg(v) parity, O(E + V) check',
      examTip: 'Start answers with both connectivity and degree.',
    },
    {
      topic: 'Hamiltonian Cycles & TSP',
      coreTakeaway: 'Every vertex once; TSP finds the cheapest tour.',
      criticalMetric: 'O(n^2 2^n) DP',
      examTip: 'Quote Dirac or Ore explicitly.',
    },
    {
      topic: 'Singly & Doubly Linked Lists',
      coreTakeaway: 'O(1) insert and delete at known positions.',
      criticalMetric: 'O(1) head ops',
      examTip: 'Update head before any reasoning about the list.',
    },
    {
      topic: 'Stack & Queue Implementations',
      coreTakeaway: 'LIFO and FIFO with O(1) core ops.',
      criticalMetric: 'Amortized O(1) resize',
      examTip: 'Always check overflow and underflow.',
    },
  ],
  vivaQuestions: [
    { question: 'Can an Eulerian circuit exist in a graph with one vertex of odd degree?', answer: 'No. The handshaking lemma guarantees an even number of odd-degree vertices, so one odd vertex is impossible.' },
    { question: 'Why is TSP computationally expensive for 30 cities?', answer: 'Exact solutions explore permutations in O(n^2 2^n); 30 cities is far beyond brute force, pushing the need for heuristics.' },
  ],
  examTemplates: {
    twoMark:
      'Define the term in one precise sentence, add the key condition (even degrees / all vertices once), and close with a single example or application.',
    fiveMark:
      'State the theorem with conditions, sketch a proof in 3-4 steps, then apply it to one worked graph or trace one algorithm pass.',
    tenMark:
      'Open with definitions and assumptions, present the algorithm or proof systematically, run a full worked example with a diagram, discuss complexity, and end with a limitation or extension.',
  },
  lastMinuteRevision: [
    {
      topicName: 'Eulerian classification',
      definition: 'Circuit needs all even; trail allows exactly two odd vertices.',
      keyFormula: 'odd(v) in {0, 2}',
      highPriorityPoint: 'Always check connectivity before degree parity.',
    },
    {
      topicName: 'TSP DP state',
      definition: 'T(S, i) = cheapest path over set S ending at i.',
      keyFormula: 'T(S,i) = min(T(S-i,j) + w(j,i))',
      highPriorityPoint: 'Base case is the singleton set of the start city.',
    },
  ],
  memoryTrickMasterList: [
    { mnemonic: 'EVEN = CIRCUIT', meaning: 'All even degrees close the loop.', topic: 'Euler', explanation: 'Associate even with returning home.' },
    { mnemonic: 'HALF = HAMILTON', meaning: 'Dirac bound of n/2 guarantees cycles.', topic: 'Hamilton', explanation: 'Tie the half threshold to the theorem name.' },
  ],
  finalChecklist: [
    'Can I state both Eulerian conditions from memory?',
    'Can I write the TSP recurrence cold?',
    'Can I draw and label a linked-list insert at the head?',
    'Can I trace a circular queue wrap-around?',
  ],
};

export const mockSyllabusLines =
  'Unit 1: Graph Theory - Eulerian paths and circuits, Hamiltonian cycles, TSP.\nUnit 2: Linear Data Structures - linked lists, stacks, queues, applications.';