#include <stdio.h>

long long method(int n) {
    if (n <= 1)        
        return 1;

    long long ans = 0;
    for (int k = 1; k <= n - 1; k++) {   // split between k and k+1
        ans += method(k) * method(n - k);
    }
    return ans;
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Number of ways: %lld\n", method(n));
    return 0;
}
