import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        
        // Check if they can be anagrams by removing at most one char from one of them
        // This is complex. Simplified: Check if edit distance is <= 1 and resulting strings are anagrams?
        // Or simply: Can we make them anagrams by removing 1 char from EITHER?
        
        // Let's check if s1 is subsequence of sorted s2 or vice versa? No.
        // Standard approach: Count frequencies. Difference in total counts should be small.
        
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];
        
        for (char c : s1.toCharArray()) freq1[c-'a']++;
        for (char c : s2.toCharArray()) freq2[c-'a']++;
        
        // Check if removing one from s1 makes it anagram of s2
        // Or removing one from s2 makes it anagram of s1
        
        boolean possible = false;
        
        // Try removing one from s1
        for (int i = 0; i < 26; i++) {
            if (freq1[i] > 0) {
                freq1[i]--;
                if (Arrays.equals(freq1, freq2)) {
                    possible = true;
                    break;
                }
                freq1[i]++;
            }
        }
        
        if (!possible) {
             // Try removing one from s2
             for (int i = 0; i < 26; i++) {
                if (freq2[i] > 0) {
                    freq2[i]--;
                    if (Arrays.equals(freq1, freq2)) {
                        possible = true;
                        break;
                    }
                    freq2[i]++;
                }
            }
        }
        
        System.out.println(possible ? "Yes" : "No");
    }
}
