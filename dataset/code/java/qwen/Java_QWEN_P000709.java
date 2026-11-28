import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        permute(chars, 0);
    }
    static void permute(char[] chars, int idx) {
        if(idx == chars.length) {
            System.out.println(new String(chars));
            return;
        }
        Set<Character> used = new HashSet<>();
        for(int i=idx; i<chars.length; i++) {
            if(used.contains(chars[i])) continue;
            used.add(chars[i]);
            swap(chars, idx, i);
            permute(chars, idx + 1);
            swap(chars, idx, i);
        }
    }
    static void swap(char[] c, int i, int j) {
        char t = c[i]; c[i] = c[j]; c[j] = t;
    }
}
