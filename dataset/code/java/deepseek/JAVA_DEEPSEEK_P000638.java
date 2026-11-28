import java.util.Scanner;

class Node {
    int coefficient;
    int exponent;
    Node next;

    Node(int coefficient, int exponent) {
        this.coefficient = coefficient;
        this.exponent = exponent;
        next = null;
    }
}

public class Main {
    Node head;

    void insert(int coefficient, int exponent) {
        Node newNode = new Node(coefficient, exponent);
        if (head == null || head.exponent < exponent) {
            newNode.next = head;
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null && current.next.exponent > exponent) {
                current = current.next;
            }
            if (current.next != null && current.next.exponent == exponent) {
                current.next.coefficient += coefficient;
            } else {
                newNode.next = current.next;
                current.next = newNode;
            }
        }
    }

    void delete(int exponent) {
        if (head == null) return;
        if (head.exponent == exponent) {
            head = head.next;
            return;
        }
        Node current = head;
        while (current.next != null && current.next.exponent != exponent) {
            current = current.next;
        }
        if (current.next != null) {
            current.next = current.next.next;
        }
    }

    int evaluate(int x) {
        int result = 0;
        Node current = head;
        while (current != null) {
            result += current.coefficient * (int)Math.pow(x, current.exponent);
            current = current.next;
        }
        return result;
    }

    void display() {
        if (head == null) return;
        Node current = head;
        while (current != null) {
            System.out.print(current.coefficient + "x^" + current.exponent);
            if (current.next != null) {
                System.out.print(" + ");
            }
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Main polynomial = new Main();
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        while (q-- > 0) {
            String operation = scanner.next();
            if (operation.equals("insert")) {
                int coefficient = scanner.nextInt();
                int exponent = scanner.nextInt();
                polynomial.insert(coefficient, exponent);
            } else if (operation.equals("delete")) {
                int exponent = scanner.nextInt();
                polynomial.delete(exponent);
            } else if (operation.equals("evaluate")) {
                int x = scanner.nextInt();
                System.out.println(polynomial.evaluate(x));
            } else if (operation.equals("display")) {
                polynomial.display();
            }
        }
    }
}
