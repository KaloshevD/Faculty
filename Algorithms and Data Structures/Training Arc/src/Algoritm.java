import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

import static java.util.Arrays.sort;


public class Algoritm {

    public static void numberSort(int n ,Integer [] arr){
        sort(arr, Collections.reverseOrder());
        for (int i = 0; i < arr.length; i++){
            System.out.print(arr[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer [] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        numberSort(n,arr);
    }


}
