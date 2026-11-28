import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String p = sc.next();
        
        List<Integer> res = new ArrayList<>();
        if(s.length() < p.length()) {
            for(int x : res) System.out.print(x + " ");
            return;
        }
        
        int[] pCount = new int[26];
        int[] sCount = new int[26];
        for(char c : p.toCharArray()) pCount[c-'a']++;
        
        int left = 0;
        for(int right=0; right<s.length(); right++) {
            sCount[s.charAt(right)-'a']++;
            if(right >= p.length()) {
                sCount[s.charAt(left)-'a']--;
                left++;
            }
            if(Arrays.equals(pCount, sCount)) res.add(left);
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
