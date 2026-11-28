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

    static Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        } else {
            Node cur;
            if (data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    static boolean isSameLevelPalindrome(ArrayList<Integer> level) {
        int i = 0, j = level.size() - 1;
        while (i < j) {
            if (!level.get(i).equals(level.get(j)))
                return false;
            i++;
            j--;
        }
        return true;
    }

    static void levelOrder(Node root) {
        Queue<Node> q = new LinkedList<>();
        ArrayList<ArrayList<Integer>> levels = new ArrayList<>();

        ((LinkedList<Node>) q).add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            ArrayList<Integer> level = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                Node temp = q.poll();
                level.add(temp.data);
                if (temp.left != null)
                    ((LinkedList<Node>) q).add(temp.left);
                if (temp.right != null)
                    ((LinkedList<Node>) q).add(temp.right);
            }
            if (!isSameLevelPalindrome(level)) {
                System.out.println("NO");
                System.exit(0);
            }
        }
        System.out.println("YES");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int val = sc.nextInt();
            root = insert(root, val);
        }
        levelOrder(root);
    }
}
