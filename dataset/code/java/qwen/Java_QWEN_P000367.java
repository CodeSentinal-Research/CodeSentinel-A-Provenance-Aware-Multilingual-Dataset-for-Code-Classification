import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n];
        for(int i=0; i<n; i++) arr[i] = sc.next();
        int minIdx = 0;
        for(int i=1; i<n; i++) {
            if(arr[i].length() < arr[minIdx].length()) minIdx = i;
        }
        System.out.println(minIdx);
    }
}
