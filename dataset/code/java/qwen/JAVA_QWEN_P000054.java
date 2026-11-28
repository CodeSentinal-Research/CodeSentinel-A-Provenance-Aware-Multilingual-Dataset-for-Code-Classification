public class Main {
    public static void main(String[] args) {
        for (char c = 'A'; c <= 'Z'; c++) {
            System.out.print(c + (c == 'Z' ? "" : " "));
        }
        System.out.println();
    }
}
