import java.util.*;

public class Main {
    public static List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder(s);
        backtrack(res, sb, 0, 0, "");
        return res;
    }

    private static void backtrack(List<String> res, StringBuilder sb, int start, int seg, String path) {
        if (start == sb.length() && seg == 4) {
            res.add(path.substring(0, path.length() - 1));
            return;
        }
        if (seg == 4 && start != sb.length()) {
            return;
        }
        for (int len = 1; len <= 3 && start + len <= sb.length(); len++) {
            String curr = sb.substring(start, start + len);
            if (curr.startsWith("0") && curr.length() > len) {
                return;
            }
            int num = Integer.parseInt(curr);
            if (num > 255) {
                return;
            }
            backtrack(res, sb, start + len, seg + 1, path + curr + (seg == 3 ? "" : "."));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        List<String> res = restoreIpAddresses(s);
        Collections.sort(res);
        for (String ip : res) {
            System.out.println(ip);
        }
    }
}
