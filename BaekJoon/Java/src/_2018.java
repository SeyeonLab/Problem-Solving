import java.util.Scanner;

public class _2018 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
       
        // 사용 변수 초기화
        int N = scanner.nextInt();
        int count = 1;
        int sum = 1;
        int startIndex = 1;
        int endIndex = 1;

        while (endIndex != N) {
            if (sum == N) {
                count++;
                endIndex++;
                sum += endIndex;
            } 
            else if (sum < N) {
                endIndex++;
                sum += endIndex;
            }
            else if (sum > N) {
                sum -= startIndex;
                startIndex++;
            } 
        }
        
        System.out.println(count);
        scanner.close();
    }
}
