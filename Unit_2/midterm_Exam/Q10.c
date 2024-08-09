#include <stdio.h>
#include<stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    int a[100];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max_ones = 0, current_ones = 0;
    int found_zero = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (found_zero && current_ones > max_ones) {
                max_ones = current_ones;
            }
            found_zero = 1;
            current_ones = 0;
        } else {
            if (found_zero) {
                current_ones++;
            }
        }
    }

    printf(" %d\n", max_ones);

    return 0;
}
