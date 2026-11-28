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

    static Node root;
    static Node node;
    static ArrayList<Integer> bstNodes = new ArrayList<>();
    static ArrayList<Integer> minHeapNodes = new ArrayList<>();

    static void storeBSTNodes(Node root) {
        if (root == null)
            return;

        storeBSTNodes(root.left);
        bstNodes.add(root.data);
        storeBSTNodes(root.right);
    }

    static void arrayToMinHeap(int[] array, int size) {
        for (int i = 0; i < size; i++) {
            minHeapNodes.add(array[i]);
        }
    }

    static void buildMinHeap(int i, int size) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && minHeapNodes.get(left) < minHeapNodes.get(smallest))
            smallest = left;

        if (right < size && minHeapNodes.get(right) < minHeapNodes.get(smallest))
            smallest = right;

        if (smallest != i) {
            Collections.swap(minHeapNodes, i, smallest);
            buildMinHeap(smallest, size);
        }
    }

    static Node minHeapToBST(int start, int end) {
        if (start > end)
            return null;

        int mid = (start + end) / 2;
        Node root = new Node(minHeapNodes.get(mid));

        root.left = minHeapToBST(start, mid - 1);
        root.right = minHeapToBST(mid + 1, end);

        return root;
    }

    static Node binaryTreeToBST(Node root) {
        if (root == null)
            return null;

        storeBSTNodes(root);
        Collections.sort(bstNodes);
        arrayToMinHeap(bstNodes.stream().mapToInt(i -> i).toArray(), bstNodes.size());
        buildMinHeap(0, minHeapNodes.size());
        return minHeapToBST(0, minHeapNodes.size() - 1);
    }

    public static void main(String[] args) {
        // Assuming the input is already provided and stored in the root node
        // The rest of the code is not provided in the problem statement
        // Here we are just calling the function and printing the result
        Node result = binaryTreeToBST(root);
        // Print the transformed tree
    }
}
