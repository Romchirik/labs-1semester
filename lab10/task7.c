#include <stdio.h>
#include <string.h>

char current_string[100] = {0};
union u1 {
    unsigned long long int u;
    double f;
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    union u1 number;

    for (int i = 0; i < n; i++) {
        double a = 0;
        double p, q;
        unsigned long long int mask;

        scanf("%lf/%lf xor %llx", &p, &q, &mask);

        number.f = p/q;
        number.u = number.u ^ mask;

        printf("%0.15g\n", number.f);
    }

}