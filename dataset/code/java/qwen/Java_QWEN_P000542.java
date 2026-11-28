import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        Deque<Integer> deque = new ArrayDeque<>();
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("pushFront")) deque.addFirst(sc.nextInt());
            else if(op.equals("pushMiddle")) {
                int val = sc.nextInt();
                List<Integer> list = new ArrayList<>(deque);
                list.add(list.size() / 2, val);
                deque.clear();
                deque.addAll(list);
            }
            else if(op.equals("pushBack")) deque.addLast(sc.nextInt());
            else if(op.equals("popFront")) System.out.println(deque.isEmpty() ? -1 : deque.pollFirst());
            else if(op.equals("popMiddle")) {
                if(deque.isEmpty()) System.out.println(-1);
                else {
                    List<Integer> list = new ArrayList<>(deque);
                    int val = list.remove((list.size() - 1) / 2);
                    deque.clear();
                    deque.addAll(list);
                    System.out.println(val);
                }
            }
            else if(op.equals("popBack")) System.out.println(deque.isEmpty() ? -1 : deque.pollLast());
        }
    }
}
