import java.util.Scanner;

public class _2562 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int arr[] = new int[9];
        int max = 0, index = 0;

        for (int i = 0; i < 9; ++i) {
            arr[i] = scanner.nextInt();
            if (arr[i] > max) {
                max = arr[i];
                index = i;
            }
        }
        
        System.out.print(max + "\n" + index+1);
        scanner.close();
    }
}
