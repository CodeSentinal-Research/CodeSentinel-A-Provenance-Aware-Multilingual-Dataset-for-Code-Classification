import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a nested list
        List<Object> nestedList = new ArrayList<>();
        nestedList.add(1);
        nestedList.add(2);
        List<Object> nestedList2 = new ArrayList<>();
        nestedList2.add(3);
        nestedList2.add(4);
        nestedList.add(nestedList2);

        // Create an iterator
        NestedIterator iterator = new NestedIterator(nestedList);

        // Perform operations
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}

class NestedIterator implements Iterator<Integer> {
    private Stack<Iterator<Object>> stack = new Stack<>();

    public NestedIterator(List<Object> nestedList) {
        stack.push(nestedList.iterator());
    }

    @Override
    public Integer next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        return (Integer) stack.peek().next();
   }

    @Override
    public boolean hasNext() {
        while (!stack.isEmpty()) {
            if (!stack.peek().hasNext()) {
                stack.pop();
                continue;
            }
            Object next = stack.peek().next();
            if (next instanceof Integer) {
                return true;
            }
            if (next instanceof List) {
                stack.push(((List) next).iterator());
            }
        }
        return false;
    }
}
