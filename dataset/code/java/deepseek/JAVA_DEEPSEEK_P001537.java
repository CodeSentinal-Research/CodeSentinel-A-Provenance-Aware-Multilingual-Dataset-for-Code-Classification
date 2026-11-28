import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        String P = scanner.nextLine();
        System.out.println(findAnagrams(S, P));
    }

    public static List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if (s.length() == 0 || p.length() == 0) {
            return result;
        }
        int m = p.length();
        int n = s.length();
        for (int i = 0; i <= n - m; i++) {
            if (isAnagram(s.substring(i, i + m), p)) {
                result.add(i);
            }
        }
        return result;
    }

    public static boolean isAnagram(String s, String p) {
        char[] charArrayS = s.toCharArray();
        char[] charArrayP = p.toCharArray();
        Arrays.sort(charArrayS);
        Arrays.sort(charArrayP);
        return Arrays.equals(charArrayS, charArrayP);
    }
}
