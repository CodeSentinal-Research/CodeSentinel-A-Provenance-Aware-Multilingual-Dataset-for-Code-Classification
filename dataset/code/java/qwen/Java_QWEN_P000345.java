import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        int[] c1 = new int[256];
        int[] c2 = new int[256];
        for (char c : s1.toCharArray()) c1[c]++;
        for (char c : s2.toCharArray()) c2[c]++;
        System.out.println(Arrays.equals(c1, c2) ? "Yes" : "No");
    }
}
