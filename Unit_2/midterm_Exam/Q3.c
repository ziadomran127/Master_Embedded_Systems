#include <stdio.h>
#include<stdlib.h>
#include <math.h>


int is_prime(int num) {
    if (num <= 1) return 0; 
    if (num == 2) return 1; 
    if (num % 2 == 0) return 0; 
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {

    int start, end;
    scanf("%d", &start);
    scanf("%d", &end);

    
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
