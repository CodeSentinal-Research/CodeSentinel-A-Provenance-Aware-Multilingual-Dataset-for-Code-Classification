import javax.swing.tree.AbstractLayoutCache;
import java.util.Scanner;

public class Main
{
    public static class Node {
        protected int element;
        protected Node nextNode;

        Node(int element) {
            this.element = element;
            this.nextNode = null;
        }
    }

    public static class LinkedList
    {
        private Node head;

        LinkedList() {
            this.head = null;
        }

        //adds node in the beginning of the list
        void addToFront(int data)
        {
            Node newNode = new Node(data); //create a new node with the given data
            newNode.nextNode = head; //make the newly created node the head of the list
            head = newNode; //point to the new node that is the first in the list
        }

        //inserts a new node after the specified node in the function

        public void insertAfter(Node node, int data)
        {
            Node current = head;
            Node insertNode = new Node(data);

            if (current == null) {
                System.out.println("No element in the list");
                return;
            }

            while (current != null) {
                //check if the current node is equal to the node you're looking for
                if (current.element == node.element)
                {
                    insertNode.nextNode = current.nextNode; // sets the nextNode reference of the insertNode
                    current.nextNode = insertNode; // Point current to the new node

                }
                current = current.nextNode;
            }
        }
        public void printList()
        {
            Node current = head;
            while (current != null)
            {
                System.out.print(current.element);
                if (current.nextNode != null)
                {
                    System.out.print("->");
                }
                current = current.nextNode;
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        LinkedList list1 = new LinkedList();
        list1.addToFront(100);
        list1.addToFront(3);
        list1.addToFront(5);
        list1.addToFront(9);
        list1.addToFront(10);
        list1.addToFront(52);


        System.out.println("List before insertion: ");
        list1.printList();

        System.out.println("Enter the new node you want to insert: ");
        Scanner scanner = new Scanner(System.in);
        int data = scanner.nextInt(); //get the new data for the new node
        System.out.println("Enter after which node you want to insert it: ");
        int insert = scanner.nextInt(); //enter the node after which you want to insert
        Node newNode = new Node(insert);
        list1.insertAfter(newNode, data);
        System.out.println("List after insertion: ");
        list1.printList();
    }
}
