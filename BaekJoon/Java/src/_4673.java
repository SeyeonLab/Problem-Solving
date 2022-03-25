public class _4673 {
    public static int d(int n) {
        int sum = n;

        while (n != 0) {
            sum += (n % 10);
            n /= 10;
        }

        return sum;
    }

    public static void main(String[] args) {
        boolean[] arr = new boolean[20000];
        int num;
        for (int i = 1; i <= 10000; ++i) {
            num = d(i);
            arr[num] = true;
        }

        for (int i = 1; i <= 10000; ++i) {
            if (!arr[i]) {
                System.out.println(i);
            }
        }
    }
}
