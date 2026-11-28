import java.util.*;
public class Solution {
    static List<String> grayCode(int n) {
        if (n == 0) return Collections.singletonList("0");
        if (n == 1) return Arrays.asList("0", "1");
        List<String> prev = grayCode(n - 1);
        List<String> res = new ArrayList<>();
        for (String s : prev) res.add("0" + s);
        for (int i = prev.size() - 1; i >= 0; i--) res.add("1" + prev.get(i));
        return res;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            for (String s : grayCode(scanner.nextInt())) System.out.println(s);
        }
    }
}