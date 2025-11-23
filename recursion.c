#include <stdio.h>

long long method(int n) {
    if (n <= 1)        
        return 1;
    long long ans = 0;
    for (int k = 1; k <= n - 1; k++) { 
        ans += method(k) * method(n - k);
    }
    return ans;
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Number of methods: %lld\n", method(n));
    return 0;
}

