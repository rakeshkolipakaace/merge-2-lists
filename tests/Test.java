package tests;

import solutions.Solution;

public class Test {
    public static void main(String[] args) {

        Solution.runTest(new int[]{1, 2, 4}, new int[]{1, 3, 4}, new int[]{1, 1, 2, 3, 4, 4}, "Basic merge with overlapping values");
        Solution.runTest(new int[]{}, new int[]{}, new int[]{}, "Both lists empty");
        Solution.runTest(new int[]{}, new int[]{0}, new int[]{0}, "First list empty");
        Solution.runTest(new int[]{5}, new int[]{}, new int[]{5}, "Second list empty");
        Solution.runTest(new int[]{1, 2, 3}, new int[]{4, 5, 6}, new int[]{1, 2, 3, 4, 5, 6}, "All elements in list1 < list2");
        Solution.runTest(new int[]{4, 5, 6}, new int[]{1, 2, 3}, new int[]{1, 2, 3, 4, 5, 6}, "All elements in list1 > list2");
        Solution.runTest(new int[]{1}, new int[]{1}, new int[]{1, 1}, "Single identical values");
        Solution.runTest(new int[]{1, 1, 1}, new int[]{1, 1, 1}, new int[]{1, 1, 1, 1, 1, 1}, "All values are same");
        Solution.runTest(new int[]{-3, -2, -1}, new int[]{0, 1, 2}, new int[]{-3, -2, -1, 0, 1, 2}, "Negative and positive numbers");
        Solution.runTest(new int[]{1, 4, 6}, new int[]{2, 3, 5}, new int[]{1, 2, 3, 4, 5, 6}, "Interleaved values");
        Solution.runTest(new int[]{1}, new int[]{2, 3, 4, 5}, new int[]{1, 2, 3, 4, 5}, "One list has only one element");
        Solution.runTest(new int[]{2, 3, 4, 5}, new int[]{1}, new int[]{1, 2, 3, 4, 5}, "One list has only one element (reverse)");
        Solution.runTest(new int[]{-10, -10, -5}, new int[]{-6, -6, -2}, new int[]{-10, -10, -6, -6, -5, -2}, "Duplicates with negatives");
        Solution.runTest(new int[]{0}, new int[]{0}, new int[]{0, 0}, "Both have one element with the same value");
      
    }
}
