//package neetcode.slidingwindow.variablesize;
//import java.util.HashMap;
//import java.util.Map;
///*
//🔍 Problem Statement:
//Hume ek string `answerKey` diya gaya hai jo true/false type ke answer represent karta hai:
//'T' → true, 'F' → false.
//
//Ek integer `k` diya gaya hai jo batata hai ki hum maximum `k` answers flip kar sakte hain (T → F ya F → T).
//
//🎯 Goal:
//`answerKey` mein max kitne consecutive same answers (all T or all F) ho sakte hain after flipping at most k characters?
//
//🧠 Example:
//Input:  answerKey = "TTFF", k = 2
//Output: 4
//
//➡️ Explanation:
//Agar dono 'F' ko 'T' mein flip karein → "TTTT"
//Max consecutive same answers = 4
//*/
//
///*
//🧠 Approach:
//- Sliding Window use karenge jiska size vary karega (variable size).
//- Hum dekhte hain ki kitne maximum length ka window bana sakte hain jisme sirf 'T' ya sirf 'F' ho after flipping at most `k` other characters.
//- Hum ek map banayenge jo 'T' aur 'F' ka count rakhega window ke andar.
//- Jab kisi ek character (T/F) ka count `k` se zyada ho jaye to window ko shrink karenge left se.
//- Har step pe max window length calculate karenge.
//*/
//
//class MaxConsecutiveAnswers {
//
//    public int maxConsecutiveAnswers(String answerKey, int k) {
//        int result = k;  // 🎯 Initial result = k (worst case mein k hi replace karke same answers bana sakte hain)
//
//        Map<Character, Integer> mp = new HashMap<>();  // 🔢 Map banaya to count 'T' and 'F' in current window
//        int left = 0;  // 🧭 Sliding window ka left pointer
//
//        for (int right = 0; right < answerKey.length(); right++) {
//            char ch = answerKey.charAt(right);
//
//            // ✅ Window mein current character ka count badhaya
//            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
//
//            // ❌ Jab minimum of 'T' or 'F' window mein `k` se zyada ho jaye → matlab zyada flips chahiye
//            // Tab tak window shrink karte rahenge jab tak flip allowed ho jaye
//            while (Math.min(mp.getOrDefault('T', 0), mp.getOrDefault('F', 0)) > k) {
//                char leftChar = answerKey.charAt(left);
//                mp.put(leftChar, mp.get(leftChar) - 1);  // 🧹 Left char ka count kam karo (window se nikal diya)
//                left++;  // ➡️ Window ka left pointer aage badhao
//            }
//
//            // ✅ Window valid hai (flips ≤ k), to result update karo
//            result = Math.max(result, right - left + 1);  // 🧮 Max window size update
//        }
//
//        return result;  // 🎯 Final max consecutive answers return
//    }
//
//    public static void main(String[] args) {
//        MaxConsecutiveAnswers sol = new MaxConsecutiveAnswers();
//        String answerKey = "TTFTF";
//        int k = 1;
//        int result = sol.maxConsecutiveAnswers(answerKey, k);
//        System.out.println("Max Consecutive Answers: " + result);  // 📢 Output print karo
//    }
//}
