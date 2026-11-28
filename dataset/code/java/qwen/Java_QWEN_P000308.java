import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        List<Integer> res = diffWays(s);
        Collections.sort(res);
        for (int x : res) System.out.print(x + " ");
    }
    static List<Integer> diffWays(String input) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                List<Integer> left = diffWays(input.substring(0, i));
                List<Integer> right = diffWays(input.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.add(l + r);
                        else if (c == '-') res.add(l - r);
                        else if (c == '*') res.add(l * r);
                    }
                }
            }
        }
        if (res.isEmpty()) res.add(Integer.parseInt(input));
        return res;
    }
}
