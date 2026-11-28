/** Aptitude, reasoning, coding, typing, GD, and interview question banks */

const APTITUDE_CATEGORIES = ['quantitative', 'logical', 'data_interpretation', 'verbal'];

const aptitudeQuestions = [
  { id: 'apt_1', question: 'If 20% of a number is 50, what is the number?', options: ['200', '250', '300', '350'], correctAnswer: '250', points: 1, category: 'quantitative', difficulty: 'easy' },
  { id: 'apt_2', question: 'A train 120m long passes a pole in 6 seconds. Speed (km/h)?', options: ['60', '72', '80', '90'], correctAnswer: '72', points: 1, category: 'quantitative', difficulty: 'medium' },
  { id: 'apt_3', question: 'Find the next term: 2, 6, 12, 20, ?', options: ['28', '30', '32', '34'], correctAnswer: '30', points: 1, category: 'logical', difficulty: 'easy' },
  { id: 'apt_4', question: 'Average of 5 numbers is 20. If one number is removed, average is 18. Removed number?', options: ['26', '28', '30', '32'], correctAnswer: '28', points: 1, category: 'quantitative', difficulty: 'medium' },
  { id: 'apt_5', question: 'Profit on selling at Rs. 575 = 15%. Cost price?', options: ['480', '500', '520', '550'], correctAnswer: '500', points: 1, category: 'quantitative', difficulty: 'medium' },
  { id: 'apt_6', question: 'A can do a work in 10 days, B in 15 days. Together they finish in how many days?', options: ['5', '6', '7', '8'], correctAnswer: '6', points: 1, category: 'quantitative', difficulty: 'medium' },
  { id: 'apt_7', question: 'Probability of getting heads twice in two coin tosses?', options: ['1/4', '1/2', '3/4', '1'], correctAnswer: '1/4', points: 1, category: 'quantitative', difficulty: 'easy' },
  { id: 'apt_8', question: 'If 30% of x is 90, then x is?', options: ['270', '300', '330', '360'], correctAnswer: '300', points: 1, category: 'quantitative', difficulty: 'easy' },
  { id: 'apt_9', question: 'Pointing to a man, Rita said "He is the only son of my mother\'s husband." Who is the man?', options: ['Brother', 'Father', 'Uncle', 'Cousin'], correctAnswer: 'Brother', points: 1, category: 'logical', difficulty: 'medium' },
  { id: 'apt_10', question: 'In a row of 40 students, A is 15th from left. Position from right?', options: ['24', '25', '26', '27'], correctAnswer: '26', points: 1, category: 'logical', difficulty: 'medium' },
  { id: 'apt_11', question: 'Table: Sales Q1=100, Q2=120, Q3=90, Q4=140. Average quarterly sales?', options: ['110', '112.5', '115', '120'], correctAnswer: '112.5', points: 1, category: 'data_interpretation', difficulty: 'medium' },
  { id: 'apt_12', question: 'Chart shows 40% Engineering, 25% Science, 20% Arts, 15% Commerce. If total=800, Engineering count?', options: ['280', '300', '320', '340'], correctAnswer: '320', points: 1, category: 'data_interpretation', difficulty: 'easy' },
  { id: 'apt_13', question: 'Choose the synonym of "Abundant".', options: ['Scarce', 'Plentiful', 'Rare', 'Limited'], correctAnswer: 'Plentiful', points: 1, category: 'verbal', difficulty: 'easy' },
  { id: 'apt_14', question: 'Antonym of "Benevolent"?', options: ['Kind', 'Generous', 'Malevolent', 'Charitable'], correctAnswer: 'Malevolent', points: 1, category: 'verbal', difficulty: 'easy' },
  { id: 'apt_15', question: 'Pipe A fills tank in 12 hrs, B empties in 18 hrs. Both open together time to fill?', options: ['24', '36', '48', '72'], correctAnswer: '36', points: 1, category: 'quantitative', difficulty: 'hard' },
  { id: 'apt_16', question: 'Series: 3, 9, 27, 81, ?', options: ['162', '243', '324', '405'], correctAnswer: '243', points: 1, category: 'logical', difficulty: 'easy' },
  { id: 'apt_17', question: 'A shopkeeper marks 40% above CP and gives 10% discount. Profit %?', options: ['26', '28', '30', '32'], correctAnswer: '26', points: 1, category: 'quantitative', difficulty: 'hard' },
  { id: 'apt_18', question: 'Revenue grew from 50L to 65L. Percentage increase?', options: ['25%', '30%', '35%', '40%'], correctAnswer: '30%', points: 1, category: 'data_interpretation', difficulty: 'easy' },
  { id: 'apt_19', question: 'Fill in the blank: The committee ___ unanimous in its decision.', options: ['was', 'were', 'have been', 'are'], correctAnswer: 'was', points: 1, category: 'verbal', difficulty: 'medium' },
  { id: 'apt_20', question: 'Two dice thrown. Probability sum is 7?', options: ['1/6', '1/9', '1/12', '1/36'], correctAnswer: '1/6', points: 1, category: 'quantitative', difficulty: 'medium' },
];

const reasoningQuestions = [
  { id: 'rea_1', question: 'All roses are flowers. Some flowers fade quickly. Conclusion?', options: ['All roses fade', 'Some roses may fade', 'No rose fades', 'Cannot determine'], correctAnswer: 'Some roses may fade', points: 1, category: 'syllogism', difficulty: 'medium', explanation: 'Some flowers fade; roses are flowers, so some roses may be among fading flowers.' },
  { id: 'rea_2', question: 'BOOK is to READ as FOOD is to ?', options: ['Cook', 'Eat', 'Buy', 'Serve'], correctAnswer: 'Eat', points: 1, category: 'analogy', difficulty: 'easy', explanation: 'Primary action associated with the object.' },
  { id: 'rea_3', question: 'If CODING is written as DPEJOH, how is HIREX written?', options: ['IJSFY', 'GISDW', 'HJSFY', 'IJTFY'], correctAnswer: 'IJSFY', points: 1, category: 'coding_decoding', difficulty: 'medium', explanation: 'Each letter shifted +1 in alphabet.' },
  { id: 'rea_4', question: 'Statement: All managers are leaders. Some leaders are innovators. Conclusion?', options: ['All managers are innovators', 'Some managers may be innovators', 'No manager is innovator', 'Cannot determine'], correctAnswer: 'Some managers may be innovators', points: 1, category: 'syllogism', difficulty: 'hard', explanation: 'Managers ⊆ Leaders; some Leaders are Innovators — possible overlap.' },
  { id: 'rea_5', question: 'Pattern: 2, 5, 11, 23, 47, ?', options: ['71', '95', '96', '101'], correctAnswer: '95', points: 1, category: 'pattern', difficulty: 'hard', explanation: 'Each term = previous * 2 + 1.' },
  { id: 'rea_6', question: 'A is north of B. C is east of A. D is south of C. Where is D relative to B?', options: ['North-East', 'East', 'South-East', 'South'], correctAnswer: 'East', points: 1, category: 'analytical', difficulty: 'medium', explanation: 'Spatial reasoning from directional clues.' },
  { id: 'rea_7', question: 'Statement: If it rains, the match is cancelled. The match was not cancelled. Assumption?', options: ['It did not rain', 'It rained anyway', 'Match was indoors', 'Rain is irrelevant'], correctAnswer: 'It did not rain', points: 1, category: 'assumption', difficulty: 'easy', explanation: 'Modus tollens: ¬cancelled → ¬rain (given rule).' },
  { id: 'rea_8', question: 'In a code, MONKEY = 58, DONKEY = 57. KEY = ?', options: ['23', '24', '25', '26'], correctAnswer: '23', points: 1, category: 'coding_decoding', difficulty: 'hard', explanation: 'Sum of letter positions (A=1).' },
  { id: 'rea_9', question: 'Six people sit in a row. P sits left of Q but right of R. Who is leftmost?', options: ['P', 'Q', 'R', 'Cannot say without more info'], correctAnswer: 'R', points: 1, category: 'seating', difficulty: 'medium', explanation: 'Order: R ... P ... Q.' },
  { id: 'rea_10', question: 'All cats are mammals. No mammal is a plant. Conclusion?', options: ['Some cats are plants', 'No cat is a plant', 'All plants are cats', 'Cannot determine'], correctAnswer: 'No cat is a plant', points: 1, category: 'syllogism', difficulty: 'easy', explanation: 'Cats ⊆ Mammals; Mammals ∩ Plants = ∅.' },
  { id: 'rea_11', question: 'Find odd one out: Square, Circle, Triangle, Cube', options: ['Square', 'Circle', 'Triangle', 'Cube'], correctAnswer: 'Cube', points: 1, category: 'pattern', difficulty: 'easy', explanation: 'Cube is 3D; others are 2D shapes.' },
  { id: 'rea_12', question: 'If @ means +, # means -, $ means *, then 5 @ 3 $ 4 # 1 = ?', options: ['15', '16', '17', '18'], correctAnswer: '16', points: 1, category: 'coding_decoding', difficulty: 'medium', explanation: '5 + 3 * 4 - 1 = 16.' },
  { id: 'rea_13', question: 'Statement: Only committed employees get promotions. Sam got promoted. Conclusion?', options: ['Sam is committed', 'Sam may not be committed', 'All employees are committed', 'None'], correctAnswer: 'Sam is committed', points: 1, category: 'assumption', difficulty: 'medium', explanation: 'Promotion implies commitment per rule.' },
  { id: 'rea_14', question: 'Series: Z, X, V, T, ?', options: ['Q', 'R', 'S', 'P'], correctAnswer: 'R', points: 1, category: 'pattern', difficulty: 'easy', explanation: 'Skip one letter backward.' },
  { id: 'rea_15', question: 'Argument: Remote work increases productivity. Counter-argument?', options: ['Always true', 'Collaboration may suffer without office interaction', 'Everyone prefers office', 'Productivity is fixed'], correctAnswer: 'Collaboration may suffer without office interaction', points: 1, category: 'analytical', difficulty: 'medium', explanation: 'Valid counter to blanket productivity claim.' },
];

const codingProblems = [
  {
    id: 'reverse_string',
    title: 'Reverse a String',
    difficulty: 'easy',
    description: 'Write a function that reverses a given string.\n\nExample: reverseString("hello") returns "olleh"',
    starterCode: { javascript: 'function reverseString(str) {\n  // Your code here\n}\n', python: 'def reverse_string(s):\n    # Your code here\n    pass\n', java: 'class Solution {\n    public static String reverseString(String s) {\n        // Your code here\n        return "";\n    }\n}\n', cpp: '#include <string>\nusing namespace std;\nstring reverseString(string s) {\n    // Your code here\n    return "";\n}\n' },
    functionName: { javascript: 'reverseString', python: 'reverse_string', java: 'reverseString', cpp: 'reverseString' },
    testCases: [
      { input: '"hello"', output: '"olleh"', visible: true },
      { input: '"HIREX"', output: '"XERIH"', visible: true },
      { input: '"a"', output: '"a"', visible: false },
      { input: '""', output: '""', visible: false },
    ],
    minCodeLength: 15,
  },
  {
    id: 'second_largest',
    title: 'Find Second Largest Number',
    difficulty: 'medium',
    description: 'Given an array of integers, return the second largest distinct number. Return -1 if not possible.\n\nExample: secondLargest([3,1,4,4,2]) returns 3',
    starterCode: { javascript: 'function secondLargest(nums) {\n  // Your code here\n}\n', python: 'def second_largest(nums):\n    # Your code here\n    pass\n', java: 'class Solution {\n    public static int secondLargest(int[] nums) {\n        return -1;\n    }\n}\n', cpp: '#include <vector>\nusing namespace std;\nint secondLargest(vector<int> nums) {\n    return -1;\n}\n' },
    functionName: { javascript: 'secondLargest', python: 'second_largest', java: 'secondLargest', cpp: 'secondLargest' },
    testCases: [
      { input: '[3,1,4,4,2]', output: '3', visible: true },
      { input: '[10,20,30]', output: '20', visible: true },
      { input: '[5,5,5]', output: '-1', visible: false },
      { input: '[1]', output: '-1', visible: false },
    ],
    minCodeLength: 25,
  },
  {
    id: 'fibonacci',
    title: 'Fibonacci Sequence',
    difficulty: 'hard',
    description: 'Return the nth Fibonacci number (0-indexed: F(0)=0, F(1)=1).\n\nExample: fibonacci(6) returns 8',
    starterCode: { javascript: 'function fibonacci(n) {\n  // Your code here\n}\n', python: 'def fibonacci(n):\n    # Your code here\n    pass\n', java: 'class Solution {\n    public static long fibonacci(int n) {\n        return 0;\n    }\n}\n', cpp: 'long fibonacci(int n) {\n    return 0;\n}\n' },
    functionName: { javascript: 'fibonacci', python: 'fibonacci', java: 'fibonacci', cpp: 'fibonacci' },
    testCases: [
      { input: '0', output: '0', visible: true },
      { input: '1', output: '1', visible: true },
      { input: '6', output: '8', visible: true },
      { input: '10', output: '55', visible: false },
      { input: '15', output: '610', visible: false },
    ],
    minCodeLength: 20,
  },
  {
    id: 'palindrome_checker',
    title: 'Palindrome Checker',
    difficulty: 'easy',
    description: 'Return true if the string is a palindrome (ignoring case), else false.\n\nExample: isPalindrome("madam") returns true',
    starterCode: { javascript: 'function isPalindrome(str) {\n  // Your code here\n}\n', python: 'def is_palindrome(s):\n    pass\n', java: 'class Solution { public static boolean isPalindrome(String s) { return false; } }\n', cpp: 'bool isPalindrome(string s) { return false; }\n' },
    functionName: { javascript: 'isPalindrome', python: 'is_palindrome', java: 'isPalindrome', cpp: 'isPalindrome' },
    testCases: [
      { input: '"madam"', output: 'true', visible: true },
      { input: '"hello"', output: 'false', visible: true },
      { input: '"Racecar"', output: 'true', visible: false },
      { input: '""', output: 'true', visible: false },
    ],
    minCodeLength: 18,
  },
  {
    id: 'array_rotation',
    title: 'Array Rotation',
    difficulty: 'medium',
    description: 'Rotate array right by k positions. Return the rotated array as JSON string.\n\nExample: rotateArray([1,2,3,4,5], 2) returns [4,5,1,2,3]',
    starterCode: { javascript: 'function rotateArray(nums, k) {\n  // Your code here\n}\n', python: 'def rotate_array(nums, k):\n    pass\n', java: 'class Solution { public static int[] rotateArray(int[] nums, int k) { return nums; } }\n', cpp: 'vector<int> rotateArray(vector<int> nums, int k) { return nums; }\n' },
    functionName: { javascript: 'rotateArray', python: 'rotate_array', java: 'rotateArray', cpp: 'rotateArray' },
    testCases: [
      { input: '[1,2,3,4,5], 2', output: '[4,5,1,2,3]', visible: true },
      { input: '[1,2], 1', output: '[2,1]', visible: true },
      { input: '[1], 0', output: '[1]', visible: false },
    ],
    minCodeLength: 25,
  },
];

const typingParagraphs = [
  'The rapid advancement of artificial intelligence is transforming industries across the globe. From healthcare diagnostics to autonomous vehicles, machine learning algorithms are enabling systems to learn from data and make predictions with remarkable accuracy. However, this technological revolution also raises important ethical questions about privacy, bias, and the future of employment. Organizations must balance innovation with responsibility, ensuring that AI systems are transparent, fair, and accountable. As developers and engineers, understanding both the capabilities and limitations of these tools is essential for building trustworthy applications that genuinely benefit society and respect human dignity in every interaction.',
  'Remote work has fundamentally changed how modern teams collaborate and deliver projects. Companies that once required daily office attendance now embrace hybrid models, offering flexibility while maintaining productivity through digital communication platforms. Video conferencing, cloud-based document sharing, and asynchronous messaging have become standard tools in the professional toolkit. Despite these advantages, remote work also presents challenges including timezone coordination, reduced spontaneous brainstorming, and the difficulty of building strong team culture across distances. Successful remote organizations invest in clear communication protocols, regular check-ins, and intentional efforts to foster connection among distributed employees worldwide.',
  'Climate change represents one of the most pressing challenges facing humanity in the twenty-first century. Rising global temperatures, extreme weather events, and shifting ecosystems demand coordinated international action from governments, businesses, and individuals alike. Renewable energy sources such as solar and wind power offer promising pathways toward reducing carbon emissions, while sustainable agriculture and conservation efforts protect vital natural resources. Education plays a crucial role in raising awareness and inspiring behavioral change. Every person can contribute through conscious choices about transportation, consumption, and energy use, collectively building momentum toward a more sustainable and resilient future for generations yet to come.',
  'Startup culture embodies the spirit of innovation, risk-taking, and relentless problem-solving that drives economic growth in competitive markets. Entrepreneurs often begin with limited resources but compensate through creativity, agility, and deep customer understanding. The journey from idea to viable product involves countless iterations, failures, and pivots before achieving product-market fit. Venture capital and angel investors provide crucial funding, yet founders must demonstrate traction, scalable business models, and strong leadership to attract serious investment. Mentorship networks, accelerator programs, and collaborative workspaces further support emerging companies. While most startups face significant obstacles, those that persevere can disrupt established industries and create lasting value for customers and communities alike.',
  'Software engineering excellence demands more than writing code that merely functions; it requires thoughtful architecture, maintainable design, comprehensive testing, and continuous collaboration with stakeholders across the organization. Modern development teams adopt agile methodologies, breaking large initiatives into manageable sprints while gathering feedback early and often from users and product owners. Version control systems like Git enable parallel development streams, code reviews catch defects before production deployment, and automated pipelines run unit tests, integration tests, and security scans on every commit. Developers must understand data structures, algorithmic complexity, database indexing strategies, caching layers, and observability tools that surface latency spikes and error rates in real time. Communication skills prove equally vital when explaining trade-offs between performance, cost, and delivery timelines. Candidates who demonstrate curiosity, ownership, and resilience during technical interviews often distinguish themselves regardless of which specific framework or cloud provider appears on their resume today.',
];

const gdTopics = [
  'AI replacing jobs: threat or opportunity for the workforce?',
  'The future of remote work versus return-to-office mandates',
  'Social media impact on mental health and society',
  'Climate change: individual responsibility versus corporate accountability',
  'Startup culture: innovation driver or unsustainable hustle mentality?',
];

const baseInterviewQuestions = {
  hr: [
    'Tell me about yourself and your professional background.',
    'Why are you interested in this role and our company?',
    'Describe a time you worked effectively in a team.',
    'What are your greatest strengths and areas for improvement?',
    'Where do you see yourself in five years?',
    'How do you handle stress and tight deadlines?',
    'Why should we hire you over other candidates?',
    'Describe a conflict at work and how you resolved it.',
    'What motivates you in your career?',
    'Do you have any questions for us?',
  ],
  technical: [
    'Explain the difference between SQL and NoSQL databases.',
    'What are the four pillars of Object-Oriented Programming?',
    'Describe the software development lifecycle you follow.',
    'Explain REST API principles and common HTTP methods.',
    'What is normalization in DBMS and why is it important?',
    'Explain how a load balancer works in cloud deployment.',
    'Describe the OSI model layers briefly.',
    'What is the difference between TCP and UDP?',
    'Explain version control workflow with Git branches.',
    'How would you optimize a slow database query?',
  ],
  behavioral: [
    'Describe a challenging project and how you overcame obstacles.',
    'Tell me about a time you failed and what you learned.',
    'Give an example of when you showed leadership.',
    'Describe a situation requiring creative problem-solving.',
    'How do you prioritize tasks when everything seems urgent?',
    'Tell me about feedback you received and how you applied it.',
    'Describe adapting to a major change at work or school.',
    'Give an example of going above and beyond expectations.',
  ],
  situational: [
    'If production goes down at midnight, what steps do you take?',
    'How would you handle disagreement with a senior engineer?',
    'A teammate consistently misses deadlines. What do you do?',
    'You discover a security vulnerability before release. Your approach?',
    'How would you explain a technical concept to a non-technical stakeholder?',
  ],
};

module.exports = {
  APTITUDE_CATEGORIES,
  aptitudeQuestions,
  reasoningQuestions,
  codingProblems,
  typingParagraphs,
  gdTopics,
  baseInterviewQuestions,
};
