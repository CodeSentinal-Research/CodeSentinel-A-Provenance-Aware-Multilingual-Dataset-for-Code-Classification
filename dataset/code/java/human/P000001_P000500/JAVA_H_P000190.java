package grurgrma;

import java.util.HashSet;

/*
 * How do you find the duplicate elements in an array?

 */
class q16 {
  public static void main(String[] args) {
    int arr[] = { 2, 4, 6, 7, 4, 2, 9, 1, 7 };
    System.out.println(" the duplicate elements are ");
    // duplicate(arr);
    duplicateApproach(arr);

  }

  static void duplicate(int arr[]) {
    int n = arr.length;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (arr[i] == arr[j]) {
          System.out.println(arr[i]);
        }
      }
    }

  }

  static void duplicateApproach(int arr[]) {
    int n = arr.length;

    HashSet<Integer> seen = new HashSet<>();
    HashSet<Integer> duplicateApproach = new HashSet<>();
    for (int i = 0; i < n; i++) {
      if (!seen.add(arr[i])) {
        duplicateApproach.add(arr[i]);
      }
    }
    System.out.println("Duplicate elements are: " + duplicateApproach);
  }
}
