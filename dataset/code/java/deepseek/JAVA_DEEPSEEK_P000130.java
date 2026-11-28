import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int[] res = nextSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            System.out.print(res[i] + " ");
        }
    }

    public static int[] nextSmaller(int[] arr, int n) {
        Stack<Integer> s = new Stack<>();
        int[] res = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && s.peek() >= arr[i]) {
                s.pop();
            }
            if (s.isEmpty()) {
                res[i] = -1;
           
            } else {
                res[i] = s.peek();
            }
            s.push(arr[i]);
        }
        return res;
    }
}
