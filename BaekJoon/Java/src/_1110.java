import java.util.Scanner;

public class _1110 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int temp = N, newNum = N;
        int cycle = 0, sum = 0;

        do {
            temp = newNum;
            sum = (temp / 10) + (temp % 10);
            newNum = (temp % 10) * 10 + sum % 10;
            cycle++;
        } while (newNum != N);

        System.out.print(cycle);
        scanner.close();
    }    
}
