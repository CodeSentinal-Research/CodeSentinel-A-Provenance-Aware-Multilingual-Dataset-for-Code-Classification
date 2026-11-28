import java.util.*;

class Node {
    String url;
    Node prev;
    Node next;
}

class BrowserHistory {
    Node current;

    public BrowserHistory(String homepage) {
        current = new Node();
        current.url = homepage;
    }

    public void visit(String url) {
        Node node = new Node();
        node.url = url;
        node.prev = current;
        current.next = node;
        current = node;
    }

    public String back(int steps) {
        while (current.prev != null && steps-- > 0) {
            current = current.prev;
        }
        return current.url;
    }

    public String forward(int steps) {
        while (current.next != null && steps-- > 0) {
            current = current.next;
        }
        return current.url;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        scanner.nextLine();

        Map<Integer, BrowserHistory> windows = new HashMap<>();
        int windowId = 0;

        for (int i = 0; i < q; i++) {
            String operation = scanner.next();
            if (operation.equals("visit")) {
                windowId = scanner.nextInt();
                String url = scanner.next();
                windows.computeIfAbsent(windowId, k -> new BrowserHistory(url)).visit(url);
            } else if (operation.equals("back")) {
                windowId = scanner.nextInt();
                int steps = scanner.nextInt();
                System.out.println(windows.get(windowId).back(steps));
            } else if (operation.equals("forward")) {
                windowId = scanner.nextInt();
                int steps = scanner.nextInt();
                System.out.println(windows.get(windowId).forward(steps));
            } else if (operation.equals("newWindow")) {
                windowId = scanner.nextInt();
                String homepage = scanner.next();
                windows.put(windowId, new BrowserHistory(homepage));
            } else if (operation.equals("closeWindow")) {
                windowId = scanner.nextInt();
                windows.remove(windowId);
            } else if (operation.equals("currentPage")) {
                windowId = scanner.nextInt();
                System.out.println(windows.get(windowId).current.url);
            }
        }
    }
}
