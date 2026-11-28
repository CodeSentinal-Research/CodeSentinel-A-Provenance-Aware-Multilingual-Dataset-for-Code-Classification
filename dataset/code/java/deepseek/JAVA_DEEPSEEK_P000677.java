import java.util.*;

public class Main {
    static class Node {
        String key;
        int value;
        Node next;
        Node prev;

        Node(String key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    static class OrderedDictionary {
        Node head = null;
        Node tail = null;
        Map<String, Node> map = new HashMap<>();

        void put(String key, int value) {
            if (map.containsKey(key)) {
                map.get(key).value = value;
                return;
            }
            Node node = new Node(key, value);
            if (head == null) {
                head = tail = node;
            } else {
                tail.next = node;
                node.prev = tail;
                tail = node;
            }
            map.put(key, node);
        }

        Integer get(String key) {
            if (!map.containsKey(key)) {
                return null;
            }
            return map.get(key).value;
        }

        void remove(String key) {
            if (!map.containsKey(key)) {
                return;
            }
            Node node = map.get(key);
            if (node.prev != null) {
                node.prev.next = node.next;
            } else {
                head = node.next;
            }
            if (node.next != null) {
                node.next.prev = node.prev;
            } else {
                tail = node.prev;
            }
            map.remove(key);
        }

        String firstKey() {
            return head == null ? null : head.key;
        }

        String lastKey() {
            return tail == null ? null : tail.key;
        }

        String nextKey(String key) {
            Node node = map.get(key);
            return node == null || node.next == null ? null : node.next.key;
        }

        String previousKey(String key) {
            Node node = map.get(key);
            return node == null || node.prev == null ? null : node.prev.key;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        OrderedDictionary dictionary = new OrderedDictionary();
        while (q-- > 0) {
            String operation = scanner.next();
            switch (operation) {
                case "put":
                    dictionary.put(scanner.next(), scanner.nextInt());
                    break;
                case "get":
                    Integer value = dictionary.get(scanner.next());
                    System.out.println(value != null ? value : "null");
                    break;
                case "remove":
                    dictionary.remove(scanner.next());
                    break;
                case "firstKey":
                    System.out.println(dictionary.firstKey() != null ? dictionary.firstKey() : "null");
                    break;
                case "lastKey":
                    System.out.println(dictionary.lastKey() != null ? dictionary.lastKey() : "null");
                    break;
                case "nextKey":
                    System.out.println(dictionary.nextKey(scanner.next()) != null ? dictionary.nextKey(scanner.next()) : "null");
                    break;
                case "previousKey":
                    System.out.println(dictionary.previousKey(scanner.next()) != null ? dictionary.previousKey(scanner.next()) : "null");
                    break;
            }
        }
    }
}
