import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            char[] a1 = scanner.next().toCharArray();
            char[] a2 = scanner.next().toCharArray();
            Arrays.sort(a1); Arrays.sort(a2);
            System.out.println(Arrays.equals(a1, a2) ? "Anagram" : "Not Anagram");
        }
    }
}