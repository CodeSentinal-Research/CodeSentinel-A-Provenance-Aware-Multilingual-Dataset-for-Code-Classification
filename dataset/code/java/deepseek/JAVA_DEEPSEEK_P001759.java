import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    Node root;
    Map<Integer, Integer> map = new HashMap<>();

    void insert(int data) {
        root = insertRec(root, data);
    }

    Node insertRec(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }

        if (data < root.data)
            root.left = insertRec(root.left, data);
        else if (data > root.data)
            root.right = insertRec(root.right, data);

        return root;
    }

    void inorder() {
        inorderRec(root);
    }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            map.put(root.data, map.getOrDefault(root.data, 0) + 1);
            inorderRec(root.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Main tree = new Main();
        for (int i = 0; i < n; i++) {
            tree.insert(sc.nextInt());
        }
        tree.inorder();
        int max = Collections.max(tree.map.values());
        List<Integer> modes = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : tree.map.entrySet()) {
            if (entry.getValue() == max) {
                modes.add(entry.getKey());
            }
        }
        Collections.sort(modes);
        for (int mode : modes) {
            System.out.println(mode);
        }
    }
}
