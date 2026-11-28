import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] perm1 = new int[n];
        int[] perm2 = new int[n];
        for(int i=0; i<n; i++) perm1[i] = sc.nextInt();
        for(int i=0; i<n; i++) perm2[i] = sc.nextInt();
        
        int[] res = new int[n];
        Set<Integer> seen1 = new HashSet<>();
        Set<Integer> seen2 = new HashSet<>();
        int common = 0;
        
        for(int i=0; i<n; i++) {
            seen1.add(perm1[i]);
            seen2.add(perm2[i]);
            if(seen1.contains(perm2[i])) common++;
            if(seen2.contains(perm1[i])) common++; // This logic is flawed for prefix common
            
            // Correct logic:
            // We need count of elements present in perm1[0..i] AND perm2[0..i]
        }
        
        // Re-implementing correctly
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        int count = 0;
        for(int i=0; i<n; i++) {
            s1.add(perm1[i]);
            s2.add(perm2[i]);
            // Check how many elements in s1 are also in s2? No, that's O(N^2)
            // Better: maintain a count of elements seen in both
        }
        
        // Simpler approach for Prefix Common Array:
        // Since they are permutations of 1..N
        int[] pos1 = new int[n+1];
        int[] pos2 = new int[n+1];
        for(int i=0; i<n; i++) {
            pos1[perm1[i]] = i;
            pos2[perm2[i]] = i;
        }
        
        int[] ans = new int[n];
        int currCommon = 0;
        for(int i=0; i<n; i++) {
            // Element i+1 is now included in both prefixes if its position in both arrays is <= i
            int val = i + 1; // Wait, values are 1..N
            // Actually, let's just iterate values 1..N
        }
        
        // Let's stick to the definition:
        // prefix1[i] = set of perm1[0..i]
        // prefix2[i] = set of perm2[0..i]
        // ans[i] = |prefix1[i] intersect prefix2[i]|
        
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for(int i=0; i<n; i++) {
            set1.add(perm1[i]);
            set2.add(perm2[i]);
            int c = 0;
            for(int x : set1) {
                if(set2.contains(x)) c++;
            }
            res[i] = c;
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
