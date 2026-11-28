import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static int idx = 0;
    static Node buildTree(int[] inorder, int[] postorder, int start, int end) {
        if(start > end) return null;

        int val = postorder[idx--];
        Node node = new Node(val);

        if(start == end) return node;

        int partition = findPartition(inorder, start, end, val);

        node.right = buildTree(inorder, postorder, partition + 1, end);
        node.left = buildTree(inorder, postorder, start, partition - 1);

        return node;
    }

    static int findPartition(int[] inorder, int start, int end, int val) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == val) return i;
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] inorder = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] postorder = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        idx = n - 1;
        Node root = buildTree(inorder, postorder, 0, n - 1);
        // Print the constructed Cartesian Tree.
        // This part is not included in the problem statement, so it's not implemented.
    }
}
