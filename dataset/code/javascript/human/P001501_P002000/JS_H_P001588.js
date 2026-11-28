// PrepForge — Data Layer + Supabase Integration
// ═══════════════════════════════════════════════════

const SUPABASE_URL = "https://rbdcsjcukvlrybeewbzc.supabase.co";
const SUPABASE_KEY = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InJiZGNzamN1a3ZscnliZWV3YnpjIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NzQxMTE0MjQsImV4cCI6MjA4OTY4NzQyNH0.2X5-ppM08HGKqwi8EJ2viGxGG4Or0uNVGjjYf9_7gbA";
const STORAGE_KEY = "prepforge_v3";

// Initialize Supabase client
const pfSupabase = window.supabase.createClient(SUPABASE_URL, SUPABASE_KEY);

// ═══ XP CONFIG ═══
const XP = { watch: 50, solve: 30, revise: 15, interview: 20, note: 10, hint: -10, streak7: 200, streak30: 1000 };

// ═══ LEVELS ═══
const LEVELS = [
  { l: 1, min: 0, name: "Rookie", icon: "🌱" },
  { l: 2, min: 500, name: "Coder", icon: "💻" },
  { l: 3, min: 1500, name: "Problem Solver", icon: "🧩" },
  { l: 4, min: 3500, name: "Algo Wizard", icon: "🧙" },
  { l: 5, min: 7000, name: "DSA Ninja", icon: "🥷" },
  { l: 6, min: 12000, name: "Interview God", icon: "👑" }
];

// ═══ QUOTES ═══
const QUOTES = [
  ["The only way to do great work is to love what you do.", "Steve Jobs"],
  ["First, solve the problem. Then, write the code.", "John Johnson"],
  ["Code is like humor. When you have to explain it, it's bad.", "Cory House"],
  ["Simplicity is the soul of efficiency.", "Austin Freeman"],
  ["It's not a bug — it's an undocumented feature.", "Anonymous"],
  ["Talk is cheap. Show me the code.", "Linus Torvalds"],
  ["Programs must be written for people to read.", "Harold Abelson"],
  ["Any fool can write code that a computer can understand.", "Martin Fowler"],
  ["The best error message is the one that never shows up.", "Thomas Fuchs"],
  ["In order to be irreplaceable, one must always be different.", "Coco Chanel"],
  ["Programming isn't about what you know; it's about what you can figure out.", "Chris Pine"],
  ["Strive not to be a success, but rather to be of value.", "Albert Einstein"],
  ["Success is not final, failure is not fatal: it is the courage to continue that counts.", "Winston Churchill"],
  ["The harder you work for something, the greater you'll feel when you achieve it.", "Anonymous"],
  ["Dream big, start small, act now.", "Robin Sharma"],
];

// ═══ BADGES ═══
const BADGES = [
  { id: "first-blood", emoji: "🌟", label: "First Blood", desc: "Solve your first problem" },
  { id: "on-fire", emoji: "🔥", label: "On Fire", desc: "7-day streak" },
  { id: "ice-cold", emoji: "❄️", label: "Ice Cold", desc: "30-day streak" },
  { id: "speed-demon", emoji: "⚡", label: "Speed Demon", desc: "10 problems in one day" },
  { id: "array-master", emoji: "🏆", label: "Array Master", desc: "Complete all array problems" },
  { id: "dp-god", emoji: "🧠", label: "DP God", desc: "Complete all DP problems" },
  { id: "observer", emoji: "👁️", label: "Observer", desc: "Watch 50 sessions" },
  { id: "note-taker", emoji: "📝", label: "Note Taker", desc: "Upload 10+ notes" },
  { id: "perfect-week", emoji: "🎯", label: "Perfect Week", desc: "Hit daily goal 7 days straight" },
  { id: "diamond", emoji: "💎", label: "Diamond Coder", desc: "455/455 problems solved" },
];

// ═══ DSA TOPICS ═══
const DSA_TOPICS = [
  { id: "arrays", name: "Arrays", icon: "🗃️", count: 40, playlist: "PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB",
   problems: ["Two Sum","Best Time to Buy and Sell Stock","Contains Duplicate","Product of Array Except Self","Maximum Subarray","Maximum Product Subarray","Find Minimum in Rotated Sorted Array","Search in Rotated Sorted Array","3Sum","Container With Most Water","Set Matrix Zeroes","Spiral Matrix","Rotate Image","Word Search","Longest Consecutive Sequence","Sort Colors","Next Permutation","Pascal's Triangle","Majority Element","Kadane's Algorithm","Stock Buy Sell Multiple","Rearrange by Sign","Leaders in Array","Longest Subarray with Sum K","Count Subarrays with Given XOR","Merge Overlapping Intervals","Merge Sorted Arrays","Missing Number","Count Inversions","Reverse Pairs","Maximum Subarray Sum Circular","Subarray Sum Equals K","Find Duplicate Number","Repeating and Missing","4Sum","Largest Subarray with 0 Sum","3Sum Closest","Trapping Rain Water","Chocolate Distribution","Array Partition"]},
  { id: "sorting", name: "Sorting", icon: "🔢", count: 7, playlist: "PLgUwDviBIf0pMFMWuuvDNF8KkFBfYB0Vn",
   problems: ["Selection Sort","Bubble Sort","Insertion Sort","Merge Sort","Quick Sort","Counting Sort","Radix Sort"]},
  { id: "binary-search", name: "Binary Search", icon: "🔎", count: 24, playlist: "PLgUwDviBIf0pMFMWuuvDNF8KkFBfYB0Vn",
   problems: ["Binary Search","Lower Bound","Upper Bound","Search Insert Position","Floor Ceil in Sorted Array","First and Last Position","Count Occurrences","Search in Rotated Sorted","Min in Rotated Sorted","Single Element in Sorted","Find Peak Element","Sqrt(x)","Nth Root","Koko Eating Bananas","Min Days to Make Bouquets","Smallest Divisor","Capacity to Ship Packages","Kth Missing Positive","Aggressive Cows","Allocate Books","Split Array Largest Sum","Painter's Partition","Median of Two Sorted Arrays","Kth Element of Two Sorted"]},
  { id: "strings", name: "Strings", icon: "🔤", count: 14, playlist: "PLgUwDviBIf0pMFMWuuvDNF8KkFBfYB0Vn",
   problems: ["Reverse Words in String","Largest Odd Number","Longest Common Prefix","Isomorphic Strings","Rotate String","Valid Anagram","Sort Characters by Frequency","Maximum Nesting Depth","Roman to Integer","Atoi","Count and Say","Longest Palindromic Substring","Sum of Beauty of Substrings","Reverse Every Word"]},
  { id: "linked-list", name: "Linked List", icon: "🔗", count: 26, playlist: "PLgUwDviBIf0r47RKH7zMRnFZwUs3n3nb0",
   problems: ["Reverse Linked List","Middle of Linked List","Merge Two Sorted Lists","Remove Nth from End","Add Two Numbers","Delete Node","Intersection of Two Lists","Detect Cycle","Find Starting Point of Cycle","Length of Cycle","Palindrome Linked List","Odd Even Linked List","Remove Duplicates Sorted","Sort Linked List","Sort 0s 1s 2s","Rotate List","Flatten Multi-level List","Clone with Random Pointer","Reverse in Groups of K","LRU Cache","Merge K Sorted Lists","Design Browser History","Find Pairs with Sum DLL","Remove Duplicates DLL","Delete All Occurrences DLL","Reverse DLL"]},
  { id: "recursion", name: "Recursion & Backtracking", icon: "🔄", count: 24, playlist: "PLgUwDviBIf0rGlzIn_7nLputFGcHpMkXy",
   problems: ["Print 1 to N","Print N to 1","Sum of N Numbers","Factorial","Reverse Array","Palindrome String","Fibonacci","Power Set","Subsequences with Sum K","Combination Sum I","Combination Sum II","Subset Sum I","Subset Sum II","Permutations","N-Queens","Sudoku Solver","M Coloring","Rat in Maze","Word Break","Palindrome Partitioning","Kth Permutation","Letter Combinations Phone","Generate Parentheses","Expression Add Operators"]},
  { id: "stack-queue", name: "Stack & Queue", icon: "📚", count: 24, playlist: "PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c",
   problems: ["Implement Stack using Array","Implement Queue using Array","Stack using Queues","Queue using Stacks","Valid Parentheses","Min Stack","Next Greater Element I","Next Greater Element II","Next Smaller Element","Trapping Rain Water","Sum of Subarray Minimums","Stock Span","Asteroid Collision","Largest Rectangle Histogram","Max Sliding Window","Implement Stack using LL","Implement Queue using LL","BFS of Graph","Implement Deque","Rotting Oranges","Celebrity Problem","LRU Cache","LFU Cache","Postfix Evaluation"]},
  { id: "sliding-window", name: "Sliding Window", icon: "🪟", count: 12, playlist: "PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL",
   problems: ["Max Sum Subarray of Size K","First Negative in Window","Count Anagrams","Max of All Subarrays","Longest Substring Without Repeating","Longest Substring K Distinct","Fruit Into Baskets","Minimum Window Substring","Count Nice Subarrays","Subarrays with K Different Integers","Min Window Subsequence","Longest Repeating Character Replacement"]},
  { id: "heaps", name: "Heaps", icon: "⛰️", count: 15, playlist: "PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c",
   problems: ["Min Heap Implementation","Max Heap Implementation","Kth Largest Element","Kth Smallest Element","Sort Nearly Sorted Array","K Closest Points","Top K Frequent Elements","Merge K Sorted Lists","Median in Stream","Task Scheduler","Hand of Straights","Design Twitter","K Most Frequent Words","Reorganize String","Smallest Range Covering K Lists"]},
  { id: "greedy", name: "Greedy", icon: "💰", count: 16, playlist: "PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma",
   problems: ["Assign Cookies","Fractional Knapsack","Greedy Coin Change","Lemonade Change","Valid Parenthesis String","N Meetings in Room","Minimum Platforms","Job Sequencing","Candy","Shortest Job First","Jump Game I","Jump Game II","Minimum Add to Make Parentheses Valid","Insert Interval","Merge Intervals","Non-overlapping Intervals"]},
  { id: "binary-trees", name: "Binary Trees", icon: "🌲", count: 28, playlist: "PLgUwDviBIf0q8Hx4LOHdR4ZVHZ9tIfcI6",
   problems: ["Inorder Traversal","Preorder Traversal","Postorder Traversal","Level Order Traversal","Max Depth","Balanced Binary Tree","Diameter","Max Path Sum","Same Tree","Zig-Zag Traversal","Boundary Traversal","Vertical Order","Top View","Bottom View","Left/Right View","Symmetric Tree","Root to Node Path","LCA","Width of Binary Tree","Children Sum Property","All Nodes Distance K","Count Total Nodes","Build from Inorder+Preorder","Build from Inorder+Postorder","Serialize Deserialize","Morris Traversal","Flatten to Linked List","Count Nodes in Complete Tree"]},
  { id: "bst", name: "BST", icon: "🌳", count: 15, playlist: "PLgUwDviBIf0q8Hx4LOHdR4ZVHZ9tIfcI6",
   problems: ["Search in BST","Ceil in BST","Floor in BST","Insert in BST","Delete in BST","Kth Smallest","Kth Largest","Validate BST","LCA in BST","Inorder Successor","BST Iterator","Two Sum BST","Recover BST","Largest BST in BT","Merge Two BSTs"]},
  { id: "graphs", name: "Graphs", icon: "🕸️", count: 34, playlist: "PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn",
   problems: ["BFS","DFS","Number of Provinces","Connected Components","Rotting Oranges","Detect Cycle Undirected","Detect Cycle Directed","Topological Sort","Kahn's Algorithm","Course Schedule","Dijkstra's Algorithm","Bellman-Ford","Floyd Warshall","Prim's MST","Kruskal's MST","Bridges in Graph","Articulation Points","Kosaraju's SCC","Tarjan's SCC","Bipartite Check","Alien Dictionary","Shortest Path DAG","Word Ladder I","Word Ladder II","Number of Islands","Surrounded Regions","01 Matrix","Pacific Atlantic Water","Cheapest Flights K Stops","Network Delay Time","Find City Smallest Neighbors","Accounts Merge","Making Large Island","Swim in Rising Water"]},
  { id: "dp", name: "Dynamic Programming", icon: "⚡", count: 55, playlist: "PLgUwDviBIf0qUlt5H_kiVlerqHWhkZau2",
   problems: ["Climbing Stairs","Frog Jump","Frog Jump II","Maximum Sum Non-Adjacent","House Robber","House Robber II","Ninja Training","Grid Unique Paths","Unique Paths II","Min Path Sum","Triangle","Min Falling Path Sum","Cherry Pickup","Cherry Pickup II","Subset Sum","Partition Equal Subset","Coin Change","Coin Change II","Target Sum","Rod Cutting","Unbounded Knapsack","0/1 Knapsack","LCS","Print LCS","Longest Common Substring","Shortest Common Supersequence","Distinct Subsequences","Edit Distance","Wildcard Matching","LIS","LIS Print","Largest Divisible Subset","Longest String Chain","Longest Bitonic Subsequence","Number of LIS","MCM","Burst Balloons","Evaluate Boolean Expression","Palindrome Partitioning II","Partition Array Max Sum","Max Rectangle in Histogram","Maximal Rectangle","Count Square Submatrices","Egg Drop","Word Break","Best Time Stock Cooldown","Best Time Stock Fee","Best Time Stock III","Best Time Stock IV","Interleaving String","Longest Palindromic Subsequence","Min Insertions to Palindrome","Min Insertion Steps","Distinct Subsequences II","Regular Expression Matching"]},
  { id: "tries", name: "Tries", icon: "🌐", count: 7, playlist: "PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp",
   problems: ["Implement Trie","Insert Search StartsWith","Count Distinct Substrings","Longest String with All Prefixes","Number of Distinct Substrings","Maximum XOR of Two Numbers","Maximum XOR with Element"]},
  { id: "bit", name: "Bit Manipulation", icon: "🔢", count: 16, playlist: "PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7",
   problems: ["Check if Bit Set","Set ith Bit","Clear ith Bit","Toggle ith Bit","Count Set Bits","Power of Two","One Odd Occurring","Two Odd Occurring","XOR of Range","Divide Two Integers","Single Number","Single Number II","Single Number III","Power Set","Find MSB","Count Total Set Bits"]},
  { id: "maths", name: "Maths", icon: "🧮", count: 10, playlist: "PLgUwDviBIf0pMFMWuuvDNF8KkFBfYB0Vn",
   problems: ["Count Digits","Reverse Number","Palindrome Number","GCD/HCF","Armstrong Number","Print Divisors","Check Prime","Sieve of Eratosthenes","Power Modular Exponentiation","All Primes Till N"]},
  { id: "hashing", name: "Hashing", icon: "#️⃣", count: 8, playlist: "PLgUwDviBIf0pMFMWuuvDNF8KkFBfYB0Vn",
   problems: ["Count Frequency","Find Highest/Lowest Freq","Two Sum","4Sum","Longest Consecutive Sequence","Longest Subarray Sum 0","Count Subarrays Sum K","Longest Substring No Repeat"]},
];

// ═══ INTERVIEW SECTIONS ═══
const INTERVIEW_SECTIONS = [
  { id: "cn", title: "Computer Networks", icon: "🌐", questions: [
    "Explain the OSI model layers","TCP vs UDP differences","How DNS resolution works","HTTP vs HTTPS","What are TCP handshakes?","How does ARP work?","What is NAT?","Subnetting basics","What is DHCP?","How do routers work?","What is a firewall?","Explain MAC address","What is a proxy server?","What is a VPN?","IPv4 vs IPv6","What is ICMP?","Explain FTP protocol","What is SMTP?","How does email work?","What is BGP routing?"]},
  { id: "os", title: "Operating Systems", icon: "💾", questions: [
    "Process vs Thread","What is a deadlock?","Deadlock prevention methods","CPU scheduling algorithms","What is virtual memory?","Paging vs Segmentation","What is thrashing?","Mutex vs Semaphore","Race condition explained","What is context switching?","Process states","What is starvation?","Banker's algorithm","Page replacement algorithms","What is a kernel?","User vs Kernel mode","What is IPC?","Explain memory management","What is fragmentation?","Fork system call"]},
  { id: "dbms", title: "DBMS", icon: "🗄️", questions: [
    "ACID properties","Normalization forms (1NF-BCNF)","SQL vs NoSQL","What are indexes?","Clustered vs Non-clustered index","What are transactions?","Isolation levels","What is a deadlock in DB?","ER diagram concepts","Primary vs Foreign key","SQL JOINs types","GROUP BY vs HAVING","Stored Procedures","Views in SQL","What is denormalization?","CAP theorem","Sharding explained","Replication strategies","What is MVCC?","B-Tree vs B+ Tree indexes"]},
  { id: "system-design", title: "System Design", icon: "🏗️", questions: [
    "Design URL Shortener","Design WhatsApp/Chat","Design Netflix","Design Uber/Ride sharing","Design Twitter","Design Rate Limiter","Design Notification System","Design Payment System"]},
  { id: "oop-lld", title: "OOP & LLD", icon: "🧩", questions: [
    "SOLID principles with examples","Factory pattern","Observer pattern","Singleton pattern","Strategy pattern","Design Parking Lot","Design Library Management","Design Chess Game","Composition vs Inheritance","Abstract class vs Interface","Polymorphism types","Encapsulation benefits"]},
  { id: "hr", title: "Aptitude & HR", icon: "🎯", questions: [
    "Tell me about yourself","Why this company?","Strength and weakness","Describe a difficult project","How do you handle conflict?","Where do you see yourself in 5 years?","Why should we hire you?","Tell about a failure and lesson","How do you handle pressure?","Leadership experience"]},
];

// ═══ SUPABASE DB HELPERS ═══
const DB = {
  // Auth
  async signUp(email, password, fullName) {
    const { data, error } = await pfSupabase.auth.signUp({
      email, password,
      options: { data: { full_name: fullName } }
    });
    if (error) throw error;
    return data;
  },

  async signIn(email, password) {
    const { data, error } = await pfSupabase.auth.signInWithPassword({ email, password });
    if (error) throw error;
    return data;
  },

  async signInWithGoogle() {
    const { data, error } = await pfSupabase.auth.signInWithOAuth({
      provider: 'google',
      options: { redirectTo: window.location.origin }
    });
    if (error) throw error;
    return data;
  },

  async signOut() {
    const { error } = await pfSupabase.auth.signOut();
    if (error) throw error;
  },

  async getSession() {
    const { data: { session } } = await pfSupabase.auth.getSession();
    return session;
  },

  // Profile
  async getProfile(userId) {
    const { data, error } = await pfSupabase.from('profiles').select('*').eq('id', userId).single();
    if (error && error.code !== 'PGRST116') throw error;
    return data;
  },

  async upsertProfile(profile) {
    const { data, error } = await pfSupabase.from('profiles').upsert(profile, { onConflict: 'id' }).select().single();
    if (error) throw error;
    return data;
  },

  // DSA Progress
  async getDSAProgress(userId) {
    const { data, error } = await pfSupabase.from('dsa_progress').select('*').eq('user_id', userId);
    if (error) throw error;
    return data || [];
  },

  async upsertDSAProgress(row) {
    const { data, error } = await pfSupabase.from('dsa_progress').upsert(row, {
      onConflict: 'user_id,section_id,problem_name'
    }).select().single();
    if (error) throw error;
    return data;
  },

  // Watch Sessions
  async getWatchSessions(userId) {
    const { data, error } = await pfSupabase.from('watch_sessions').select('*').eq('user_id', userId);
    if (error) throw error;
    return data || [];
  },

  async upsertWatchSession(row) {
    const { data, error } = await pfSupabase.from('watch_sessions').upsert(row, {
      onConflict: 'user_id,section_id,video_id'
    }).select().single();
    if (error) throw error;
    return data;
  },

  // Notes
  async getNotes(userId) {
    const { data, error } = await pfSupabase.from('notes').select('*').eq('user_id', userId).order('created_at', { ascending: false });
    if (error) throw error;
    return data || [];
  },

  async createNote(note) {
    const { data, error } = await pfSupabase.from('notes').insert(note).select().single();
    if (error) throw error;
    return data;
  },

  async updateNote(id, updates) {
    const { data, error } = await pfSupabase.from('notes').update({ ...updates, updated_at: new Date().toISOString() }).eq('id', id).select().single();
    if (error) throw error;
    return data;
  },

  async deleteNote(id) {
    const { error } = await pfSupabase.from('notes').delete().eq('id', id);
    if (error) throw error;
  },

  // Streak Log
  async getStreakLog(userId) {
    const { data, error } = await pfSupabase.from('streak_log').select('*').eq('user_id', userId).order('date', { ascending: false }).limit(400);
    if (error) throw error;
    return data || [];
  },

  async upsertStreakLog(row) {
    const { data, error } = await pfSupabase.from('streak_log').upsert(row, {
      onConflict: 'user_id,date'
    }).select().single();
    if (error) throw error;
    return data;
  },

  // Interview Progress
  async getInterviewProgress(userId) {
    const { data, error } = await pfSupabase.from('interview_progress').select('*').eq('user_id', userId);
    if (error) throw error;
    return data || [];
  },

  async upsertInterviewProgress(row) {
    const { data, error } = await pfSupabase.from('interview_progress').upsert(row, {
      onConflict: 'user_id,section_id,question_id'
    }).select().single();
    if (error) throw error;
    return data;
  },

  // Achievements
  async getAchievements(userId) {
    const { data, error } = await pfSupabase.from('achievements').select('*').eq('user_id', userId);
    if (error) throw error;
    return data || [];
  },

  async addAchievement(userId, badgeId) {
    const { data, error } = await pfSupabase.from('achievements').insert({ user_id: userId, badge_id: badgeId }).select().single();
    if (error && error.code !== '23505') throw error;
    return data;
  },

  // Revision Schedule
  async getRevisions(userId) {
    const { data, error } = await pfSupabase.from('revision_schedule').select('*').eq('user_id', userId);
    if (error) throw error;
    return data || [];
  },

  async upsertRevision(row) {
    const { data, error } = await pfSupabase.from('revision_schedule').upsert(row, {
      onConflict: 'user_id,section_id,problem_name'
    }).select().single();
    if (error) throw error;
    return data;
  },

  // File Storage
  async uploadFile(userId, file) {
    const filePath = `${userId}/${Date.now()}-${file.name}`;
    const { data, error } = await pfSupabase.storage.from('notes-files').upload(filePath, file);
    if (error) throw error;
    const { data: urlData } = pfSupabase.storage.from('notes-files').getPublicUrl(filePath);
    return { path: filePath, url: urlData.publicUrl };
  }
};