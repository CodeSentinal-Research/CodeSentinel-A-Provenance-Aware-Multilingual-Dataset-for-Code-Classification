const mongoose = require('mongoose');
const Question = require('./models/Question');
const Topic = require('./models/Topic');
const Section = require('./models/Section');

// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/dsa_tracker', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

const foundationTopicsData = [
  {
    topicName: "Sliding Window",
    questions: [
      "Maximum sum subarray of size k",
      "Minimum size subarray with sum ≥ k",
      "Count subarrays with at most K distinct elements",
      "Longest substring with at most K unique characters",
      "Maximum number of vowels in substring of length k",
      "First negative integer in every window of size k",
      "Number of subarrays with sum exactly k",
      "Count of subarrays with equal number of 0s and 1s",
      "Longest substring with at most two distinct characters",
      "Longest repeating character replacement",
      "Minimum window substring containing all characters",
      "Sliding window maximum",
      "Binary subarrays with sum",
      "Maximum points from cards (pick k from ends)",
      "Number of substrings with exactly k distinct characters"
    ]
  },
  {
    topicName: "Two Pointer",
    questions: [
      "Two sum in sorted array",
      "3Sum",
      "4Sum",
      "Container with most water",
      "Remove duplicates from sorted array",
      "Merge sorted arrays in-place",
      "Trapping rain water",
      "Subarray product less than K",
      "Longest mountain in array",
      "Minimum difference between elements of two arrays",
      "Find pair with given difference",
      "Check if string is palindrome (using two pointers)",
      "Find longest palindromic substring",
      "Reverse words in a string in-place",
      "Find intersection of two sorted arrays"
    ]
  },
  {
    topicName: "Prefix Sum",
    questions: [
      "Prefix sum of array",
      "Range sum queries (static)",
      "Find equilibrium index in array",
      "Subarray sum equals k",
      "Find pivot index",
      "Count of subarrays with sum divisible by k",
      "Subarrays with sum zero",
      "Longest subarray with equal 0s and 1s",
      "Count number of nice subarrays (with k odd numbers)",
      "Maximum average subarray of size k",
      "2D prefix sum – matrix sum queries",
      "Find total strength of wizards (Leetcode hard)",
      "Difference array for range updates",
      "Number of ways to split array into 3 parts with equal sum",
      "Count subarrays with sum less than or equal to k"
    ]
  },
  {
    topicName: "Greedy",
    questions: [
      "Activity selection problem",
      "Fractional knapsack",
      "Job sequencing problem",
      "Minimum number of platforms",
      "Candy distribution problem",
      "Jump game I and II",
      "Assign minimum number of coins",
      "Reorganize string (no same adjacent characters)",
      "Minimum number of arrows to burst balloons",
      "Gas station circular route",
      "Lemonade change",
      "Partition labels",
      "Interval partitioning",
      "Buy & sell stock to maximize profit",
      "Non-overlapping intervals",
      "Minimum swaps required to group all 1s together",
      "Split array into maximum number of balanced strings",
      "Minimize cash flow among friends (graph + greedy)"
    ]
  },
  {
    topicName: "Backtracking",
    questions: [
      "Generate all subsets",
      "Generate all permutations",
      "N-Queens problem",
      "Sudoku solver",
      "Combination sum I",
      "Combination sum II (no duplicates)",
      "Palindrome partitioning",
      "Generate valid parentheses",
      "Letter combinations of a phone number",
      "Word search in a 2D grid",
      "Restore IP addresses",
      "Expression add operators",
      "K-th permutation sequence",
      "All possible paths in matrix",
      "Word break problem (with dictionary)",
      "Binary string without consecutive 1s",
      "Count number of unique paths in maze",
      "Print all palindromic substrings",
      "Find all combinations that sum to target",
      "Combination sum III (k numbers from 1-9 to sum to n)"
    ]
  },
  {
    topicName: "Bit Manipulation",
    questions: [
      "Check if number is power of 2",
      "Count set bits",
      "Find only non-repeating element",
      "Find 2 non-repeating elements",
      "XOR from 1 to N",
      "Subset generation using bits",
      "Swap two numbers using XOR",
      "Add two numbers without + operator",
      "Find missing number in range",
      "Find single number (every other appears twice)",
      "Find single number when all others appear thrice",
      "Divide and multiply using left/right shifts",
      "Check if bits are alternating (like 1010)",
      "Find maximum XOR of two numbers in array",
      "Count number of bits to change to convert A to B"
    ]
  },
  {
    topicName: "Hashing",
    questions: [
      "Two sum",
      "Group anagrams",
      "Longest subarray with sum = k",
      "Subarray sum divisible by k",
      "Longest consecutive sequence",
      "Count frequency of elements",
      "First non-repeating character",
      "Check if two strings are anagrams",
      "Find all duplicates in array",
      "Isomorphic strings",
      "Count pairs with given XOR",
      "Reconstruct itinerary (graph with hash map)",
      "Minimum window substring",
      "Subarrays with equal number of 0s and 1s",
      "Find unique number when every other appears thrice"
    ]
  },
  {
    topicName: "Heap / Priority Queue",
    questions: [
      "Kth largest element in array",
      "Kth smallest element in array",
      "Top K frequent elements",
      "Sort characters by frequency",
      "Merge k sorted arrays/lists",
      "Connect ropes to minimize cost",
      "Find median from data stream",
      "K closest elements to X",
      "Reorganize string",
      "Task scheduler",
      "Sliding window maximum",
      "Minimum cost to hire K workers",
      "Top K frequent words",
      "Smallest range covering elements from k lists",
      "Kth largest element in a stream",
      "Minimize deviation in array"
    ]
  }
];

async function seedFoundationTopics() {
  try {
    console.log('🌱 Starting to seed Foundation topics and questions...');
    
    // First, find the Foundation section
    let foundationSection = await Section.findOne({ name: 'Foundation' });
    
    if (!foundationSection) {
      foundationSection = new Section({
        name: 'Foundation',
        description: 'Foundation Data Structures and Algorithms',
        color: '#28a745',
        icon: '🏗️'
      });
      await foundationSection.save();
      console.log('✅ Created Foundation section');
    } else {
      console.log('✅ Foundation section found');
    }
    
    // Get the current highest question number
    const lastQuestion = await Question.findOne().sort({ questionNumber: -1 });
    let currentNumber = lastQuestion ? lastQuestion.questionNumber + 1 : 1;
    
    console.log(`📊 Starting from question number: ${currentNumber}`);
    
    let totalQuestionsAdded = 0;
    
    for (const topicData of foundationTopicsData) {
      console.log(`\n📝 Processing topic: ${topicData.topicName}`);
      
      // Check if topic exists, if not create it
      let topic = await Topic.findOne({ name: topicData.topicName, sectionName: 'Foundation' });
      
      if (!topic) {
        topic = new Topic({
          name: topicData.topicName,
          section: foundationSection._id,
          sectionName: 'Foundation',
          description: `Foundation ${topicData.topicName} problems`,
          color: '#28a745',
          icon: '🧩'
        });
        await topic.save();
        console.log(`✅ Created topic: ${topicData.topicName}`);
      } else {
        console.log(`ℹ️  Topic already exists: ${topicData.topicName}`);
      }
      
      // Add questions for this topic
      for (const questionTitle of topicData.questions) {
        // Check if question already exists
        const existingQuestion = await Question.findOne({ title: questionTitle });
        
        if (!existingQuestion) {
          const question = new Question({
            questionNumber: currentNumber,
            title: questionTitle,
            topic: topicData.topicName,
            category: 'Foundation',
            difficulty: 'Medium', // Default difficulty
            description: `Solve the ${questionTitle} problem using ${topicData.topicName} technique.`,
            completed: false
          });
          
          await question.save();
          console.log(`   ✅ Q${currentNumber}: ${questionTitle}`);
          currentNumber++;
          totalQuestionsAdded++;
        } else {
          console.log(`   ⚠️  Question already exists: ${questionTitle}`);
        }
      }
    }
    
    console.log(`\n🎉 Successfully added ${totalQuestionsAdded} new Foundation questions!`);
    console.log(`📈 Question numbers: ${lastQuestion ? lastQuestion.questionNumber + 1 : 1} to ${currentNumber - 1}`);
    
    // Show summary
    for (const topicData of foundationTopicsData) {
      const topicCount = await Question.countDocuments({ 
        topic: topicData.topicName, 
        category: 'Foundation' 
      });
      console.log(`   📊 ${topicData.topicName}: ${topicCount} questions`);
    }
    
  } catch (error) {
    console.error('❌ Error seeding Foundation topics:', error);
  } finally {
    mongoose.connection.close();
    console.log('🔒 Database connection closed');
  }
}

// Run the seeding
seedFoundationTopics();
