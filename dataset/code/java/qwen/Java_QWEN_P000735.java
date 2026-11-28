import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] chars = new char[n];
        for(int i=0; i<n; i++) chars[i] = sc.next().charAt(0);
        int k = sc.nextInt();
        Arrays.sort(chars);
        genStr(chars, k, new StringBuilder());
    }
    static void genStr(char[] chars, int k, StringBuilder curr) {
        if(curr.length() == k) {
            System.out.println(curr.toString());
            return;
        }
        for(char c : chars) {
            curr.append(c);
            genStr(chars, k, curr);
            curr.deleteCharAt(curr.length() - 1);
        }
    }
}
