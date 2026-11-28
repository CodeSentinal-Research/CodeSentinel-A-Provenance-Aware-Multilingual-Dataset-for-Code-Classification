import java.util.*;

public class Main {
    static class SkipList {
        private static final double RANDOM_FACTOR = Math.random();
        private Node head;

        public SkipList() {
            head = new Node(Integer.MAX_VALUE);
        }

        public boolean search(int target) {
            Node curr = head;
            while (curr != null) {
                while (curr.next != null && curr.next.val < target) {
                    curr = curr.next;
                }
                if (curr.val == target) {
                    return true;
               
                }
                curr = curr.down;
            }
            return false;
        }

        public void add(int num) {
            Stack<Node> stack = new Stack<>();
            Node curr = head;
            while (curr != null) {
                while (curr.next != null && curr.next.val < num) {
                    curr = curr.next;
                }
                stack.push(curr);
                curr = curr.down;
            }

            boolean coinToss = Math.random() < RANDOM_FACTOR;
            while (!stack.isEmpty()) {
                curr = stack.pop();
                Node newNode = new Node(num, curr.next, curr.down);
                curr.next = newNode;
                if (!coinToss) {
                    break;
                }
                coinToss = Math.random() < RANDOM_FACTOR;
            }
        }

        public boolean erase(int num) {
            boolean found = false;
            Node curr = head;
            while (curr != null) {
                while (curr.next != null && curr.next.val < num) {
                    curr = curr.next;
                }
                if (curr.next != null && curr.next.val == num) {
                    curr.next = curr.next.next;
                    found = true;
                }
                curr = curr.down;
            }
            return found;
        }

        static class Node {
            int val;
            Node next, down;

            Node(int val) {
                this.val = val;
            }

            Node(int val, Node next, Node down) {
                this.val = val;
                this.next = next;
                this.down = down;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        SkipList skipList = new SkipList();
        for (int i = 0; i < q; i++) {
            String operation = scanner.next();
            int num = scanner.nextInt();
            switch (operation) {
                case "add":
                    skipList.add(num);
                    break;
                case "search":
                    System.out.println(skipList.search(num));
                    break;
                case "erase":
                    System.out.println(skipList.erase(num));
                    break;
            }
        }
    }
}
