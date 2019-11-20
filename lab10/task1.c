#include <stdio.h>

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime list[50000];

DateTime min(const DateTime *arr, int cnt) {
    DateTime mindt = {0, 0, 0, 0, 0, 0};
    int min_days = 1825001;
    int min_sec = 31556927;

    for (int i = 0; i < cnt; i++) {
        int sec, days;
        sec = arr[i].hours * 3600 + arr[i].minutes * 60 + arr[i].seconds;
        days = arr[i].year * 365 + arr[i].month * 30 + arr[i].day;

        if (days < min_days) {
            min_days = days;
            min_sec = sec;
            mindt = arr[i];
        } else {
            if (days == min_days) {
                if (sec < min_sec) {
                    min_sec = sec;
                    mindt = arr[i];
                }
            }
        }
    }
    return mindt;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    DateTime dt;


    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &list[i].year, &list[i].month, &list[i].day);
        scanf("%d%d%d", &list[i].hours, &list[i].minutes, &list[i].seconds);
    }

    dt = min(list, n);
    
    printf("%d %d %d ", dt.year, dt.month, dt.day);
    printf("%d %d %d ", dt.hours, dt.minutes, dt.seconds);
}