import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    static class Pair {
        Node node;
        int state;

        Pair(Node node, int state) {
            this.node = node;
            this.state = state;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        Node root = new Node(Integer.parseInt(br.readLine()));
        Map<Integer, List<Node>> map = new HashMap<>();
        map.put(0, new ArrayList<>());
        map.get(0).add(root);

        for (int i = 1; i < n; i++) {
            String[] s = br.readLine().split(" ");
            int parent = Integer.parseInt(s[0]);
            int child = Integer.parseInt(s[1]);

            Node node = new Node(child);
            if (parent == -1) {
                root = node;
            } else {
                if (map.containsKey(parent)) {
                    map.get(parent).add(node);
                } else {
                    List<Node> list = new ArrayList<>();
                    list.add(node);
                    map.put(parent, list);
                }
            }
        }

        for (Map.Entry<Integer, List<Node>> entry : map.entrySet()) {
            List<Node> list = entry.getValue();
            Collections.sort(list, new Comparator<Node>() {
                public int compare(Node a, Node b) {
                    return a.data - b.data;
                }
            });

            for (Node node : list) {
                System.out.println(node.data);
            }
        }

        out.close();
    }
}
