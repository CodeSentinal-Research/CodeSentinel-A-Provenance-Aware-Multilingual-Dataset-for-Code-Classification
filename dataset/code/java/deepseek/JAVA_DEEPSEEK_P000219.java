import java.io.*;
import java.util.*;

public class Main {
    private Deque<Integer> deque;
    private long product;
    private int K;

    public Main(int K) {
        this.K = K;
        deque = new ArrayDeque<>();
        product = 1;
    }

    public void add(int num) {
        deque.addLast(num);
        product *= num;
        if (deque.size() > K) {
            int removed = deque.removeFirst();
            product /= removed;
        }
    }

    public long getProduct() {
        return deque.size() == K ? product : -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().split(" ");
        int K = Integer.parseInt(tokens[0]);
        int Q = Integer.parseInt(tokens[1]);
        Main dataStructure = new Main(K);
        for (int i = 0; i < Q; i++) {
            tokens = br.readLine().split(" ");
            if (tokens[0].equals("add")) {
                dataStructure.add(Integer.parseInt(tokens[1]));
            } else if (tokens[0].equals("getProduct")) {
                System.out.println(dataStructure.getProduct());
            }
        }
    }
}
