import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
        }
    }

    static Node root;

    static void createTree(String[] values) {
        for (String value : values) {
            insert(Integer.parseInt(value));
        }
    }

    static void insert(int value) {
        if (root == null) {
            root = new Node(value);
        } else {
            insertRecursive(root, value);
        }
    }

    static void insertRecursive(Node current, int value) {
        if (value < current.value) {
            if (current.left == null) {
                current.left = new Node(value);
            } else {
                insertRecursive(current.left, value);
            }
        } else if (value > current.value) {
            if (current.right == null) {
                current.right = new Node(value);
            } else {
                insertRecursive(current.right, value);
            }
        }
    }

    static List<Integer> longestDecreasingPath = new ArrayList<>();

    static void dfs(Node node, List<Integer> path) {
        if (node == null) {
            return;
        }
        path.add(node.value);
        if (node.left == null && node.right == null) {
            if (path.size() > longestDecreasingPath.size()) {
                longestDecreasingPath = new ArrayList<>(path);
            }
        } else {
            dfs(node.left, new ArrayList<>(path));
            dfs(node.right, new ArrayList<>(path));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] values = br.readLine().split(" ");
        createTree(values);
        dfs(root, new ArrayList<>());
        for (int i = longestDecreasingPath.size() - 1; i >= 0; i--) {
            System.out.print(longestDecreasingPath.get(i) + " ");
        }
    }
}
