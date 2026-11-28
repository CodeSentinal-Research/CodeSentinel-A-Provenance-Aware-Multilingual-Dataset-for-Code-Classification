import java.util.Arrays;
import java.util.Scanner;

class Q123_Largest_Number_Formation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of element: ");
        int n = sc.nextInt();
        System.out.print("Enter the element: ");
        Integer[] arr = new Integer[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr, (a, b) -> {
            String x = String.valueOf(a);
            String y = String.valueOf(b);
            return (y + x).compareTo(x + y);
        });
        System.out.print("Largest Number Formation: ");
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i]);
        }
    }
}
