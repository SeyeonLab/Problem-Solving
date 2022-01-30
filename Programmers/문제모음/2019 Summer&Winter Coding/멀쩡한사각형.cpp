using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

long long solution(int w, int h) {
    long long answer = 1;
    long long total = (long long)h * w;
    int GCD = gcd(w, h);
    
    w /= GCD;
    h /= GCD;
    
    if (h == 1 || w == 1)
        answer = (long long)h * w;
    else
        answer = h + w - 1;
    
    return total - answer * GCD;
}