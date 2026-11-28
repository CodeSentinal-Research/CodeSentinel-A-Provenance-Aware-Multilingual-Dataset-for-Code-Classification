import java.util.*;

public class Main {
    public static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n) {
                nodes[i].left = nodes[left];
            }
            if (right < n) {
                nodes[i].right = nodes[right];
            }
       }
       
        Queue<Node> queue = new LinkedList<>();
        queue.offer(nodes[0]);
        while (!queue.isEmpty()) {
            int size = queue.size();
            int[] level = new int[size];
            for (int i = 0; i < size; i++) {
                Node curr = queue.poll();
                level[i] = curr.val;
                if (curr.left != null) {
                    queue.offer(curr.left);
                }
                if (curr.right != null) {
                    queue.offer(curr.right);
                }
            }
            Arrays.sort(level);
            if (size % 2 == 0) {
                System.out.println((level[size / 2 - 1] + level[size / 2]) / 2.0);
            } else {
                System.out.println(level[size / 2]);
            }
        }
    }
}
