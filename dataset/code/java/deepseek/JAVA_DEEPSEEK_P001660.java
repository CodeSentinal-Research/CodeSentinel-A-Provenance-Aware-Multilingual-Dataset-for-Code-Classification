import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
            left = null;
            right = null;
        }
    }

    static class Info {
        Node node;
        int size;
        Info(Node node, int size) {
            this.node = node;
            this.size = size;
        }
    }

    static Map<String, Integer> map = new HashMap<>();
    static List<Info> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String[] s = br.readLine().split(" ");
            int m = Integer.parseInt(s[0]);
            Node root = new Node(Integer.parseInt(s[1]));
            for (int i = 2; i < m; i += 2) {
                root.left = new Node(Integer.parseInt(s[i]));
                if (i + 1 < m) root.right = new Node(Integer.parseInt(s[i + 1]));
            }
            list.add(new Info(root, dfs(root)));
        }
        for (Info info : list) {
            if (info.size > 1) pw.println(info.node.val);
        }
        pw.println("NONE");
        pw.flush();
    }

    static int dfs(Node node) {
        if (node == null) return 0;
        String key = node.val + "," + dfs(node.left) + "," + dfs(node.right);
        int size = map.getOrDefault(key, 0) + 1;
        map.put(key, size);
        return size;
    }
}
