import java.util.*;

class Node {
    int key;
    int freq;
    Node left, right;

    Node(int key, int freq) {
        this.key = key;
        this.freq = freq;
        left = right = null;
    }
}

public class Main {
    static Node root;

    static void insert(Node node, int key, int freq) {
        if (node == null) {
            node = new Node(key, freq);
            return;
        }

        if (key < node.key) {
            if (node.left == null) {
                node.left = new Node(key, freq);
            } else {
                insert(node.left, key, freq);
            }
        } else if (key > node.key) {
            if (node.right == null) {
                node.right = new Node(key, freq);
            } else {
                insert(node.right, key, freq);
            }
        }
    }

    static void constructBST(int[] keys, int[] freqs, int n) {
        for (int i = 0; i < n; i++) {
            insert(root, keys[i], freqs[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] keys = new int[n];
        int[] freqs = new int[n];

        for (int i = 0; i < n; i++) {
            keys[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            freqs[i] = sc.nextInt();
        }

        root = new Node(keys[0], freqs[0]);
        constructBST(keys, freqs, n);
    }
}
