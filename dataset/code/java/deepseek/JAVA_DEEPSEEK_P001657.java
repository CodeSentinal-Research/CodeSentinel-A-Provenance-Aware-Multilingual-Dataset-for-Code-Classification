import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;
        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    static Node buildTree(String[] arr) {
        Node root = null;
        Queue<Node> queue = new LinkedList<>();
        if (arr[0].equals("x")) {
            root = new Node(Integer.parseInt(arr[1]));
            queue.add(root);
        } else {
            root = new Node(Integer.parseInt(arr[0]));
            queue.add(root);
        }
        int i = 1;
        while (!queue.isEmpty()) {
            Node temp = queue.poll();
            if (i < arr.length) {
                if (!arr[i].equals("x")) {
                    temp.left = new Node(Integer.parseInt(arr[i]));
                    queue.add(temp.left);
                }
                i++;
                if (i < arr.length) {
                    if (!arr[i].equals("x")) {
                        temp.right = new Node(Integer.parseInt(arr[i]));
                        queue.add(temp.right);
                    }
                    i++;
                }
            }
        }
        return root;
    }

    static int minTime(Node root, int target) {
        if (root == null) {
            return -1;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        int time = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean found = false;
            for (int i = 0; i < size; i++) {
                Node temp = queue.poll();
                if (temp.data == target) {
                    found = true;
                    return time;
                }
                if (temp.left != null) {
                    queue.add(temp.left);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                }
            }
            if (found) {
                return time;
            }
            time++;
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] arr = new String[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.next();
        }
        int target = sc.nextInt();
        Node root = buildTree(arr);
        System.out.println(minTime(root, target));
    }
}
