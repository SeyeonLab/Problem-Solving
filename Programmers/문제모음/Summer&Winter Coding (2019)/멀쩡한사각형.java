class Solution {
    public int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    public long solution(int w, int h) {
        long answer = 1;
        long total = (long) w * h;
        int gcd = gcd(w, h);

        w /= gcd;
        h /= gcd;
        
        if (h == 1 || w == 1)
            answer = (long) w * h;
        else
            answer = h + w - 1;

        return total - answer * gcd;
    }
}