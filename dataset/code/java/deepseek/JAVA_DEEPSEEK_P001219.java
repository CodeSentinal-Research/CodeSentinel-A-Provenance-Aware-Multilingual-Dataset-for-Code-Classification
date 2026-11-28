import java.util.*;
import java.io.*;

public class Main {
    static List<String> result = new ArrayList<>();
    static HashSet<String> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = Integer.parseInt(br.readLine());
        set.add("");
        dfs(s, n, "");
        Collections.sort(result);
        for (String str : result) {
            System.out.println(str);
        }
    }

    public static void dfs(String s, int n, String path) {
        if (n == 0) {
            result.add(path);
            return;
        }
        for (int i = 1; i <= s.length(); i++) {
            String subStr = s.substring(0, i);
            if (set.contains(subStr)) {
                dfs(s.substring(i), n - 1, path.equals("") ? subStr : path + " " + subStr);
            }
        }
    }
}
