import java.util.Scanner;

public class ReverseWord {

    public static void printReversed(String word) {
        StringBuilder novString= new StringBuilder();
        char char1;
        for (int i=0; i<word.length(); i++)
        {
            char1 = word.charAt(i);
            novString.insert(0, char1);
        }
        System.out.println(novString);
    }

    public static void main(String[] args) {
        int counter;
        Scanner sc = new Scanner(System.in);
        counter = sc.nextInt();
        for (int i = 0; i < counter; i++) {
            String word = sc.next();
            printReversed(word);
        }
    }
}
