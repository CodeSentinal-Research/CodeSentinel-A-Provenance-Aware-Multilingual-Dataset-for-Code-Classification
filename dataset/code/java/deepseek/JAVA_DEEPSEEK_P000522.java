import java.util.Stack;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String homepage = scanner.nextLine();
        BrowserHistory browserHistory = new BrowserHistory(homepage);
        int q = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < q; i++) {
            String operation = scanner.nextLine();
            String[] parts = operation.split(" ");
            switch (parts[0]) {
                case "visit":
                    browserHistory.visit(parts[1]);
                    break;
                case "back":
                    System.out.println(browserHistory.back(Integer.parseInt(parts[1])));
                    break;
                case "forward":
                    System.out.println(browserHistory.forward(Integer.parseInt(parts[1])));
                    break;
            }
        }
    }
}

class BrowserHistory {
    private Stack<String> backStack;
    private Stack<String> forwardStack;
    private String currentPage;

    public BrowserHistory(String homepage) {
        backStack = new Stack<>();
        forwardStack = new Stack<>();
        visit(homepage);
    }

    public void visit(String url) {
        backStack.push(currentPage);
        currentPage = url;
        forwardStack.clear();
    }

    public String back(int steps) {
        while (steps-- > 0 && !backStack.isEmpty()) {
            forwardStack.push(currentPage);
            currentPage = backStack.pop();
        }
        return currentPage;
    }

    public String forward(int steps) {
        while (steps-- > 0 && !forwardStack.isEmpty()) {
            backStack.push(currentPage);
            currentPage = forwardStack.pop();
        }
        return currentPage;
    }
}
