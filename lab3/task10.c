#include <stdio.h>


int check_date(int day, int month, int year) {
    if ((month == 12) || (month == 10) || (month == 8) || (month == 6) || (month == 4)) {
        if ((day > 31) || (day < 1))
            return 1;
    }
    if ((month == 11) || (month == 9) || (month == 7) || (month == 5) || (month == 3)) {
        if ((day > 30) || (day < 1))
            return 1;
    }
    if (month == 2) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
            if ((day > 29) || (day < 1))
                return 1;
        } else {
            if ((day > 28) || (day < 1))
                return 1;
        }
    }
    if (month > 12){
        return 1;
    }
    if ((day <=0) || (month <= 0) || (year <= 0))
        return 1;
    return 0;
}

int count_days(int day, int month, int year) {
    int sum = 0;
    while (year != 1) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            sum += 366;
        } else {
            sum += 365;
        }
        year--;
    }

    while (month != 1) {
        if ((month == 12) || (month == 10) || (month == 8) || (month == 6) || (month == 4))
            sum += 31;
        if ((month == 11) || (month == 9) || (month == 7) || (month == 5) || (month == 3))
            sum += 30;
        if (month == 2)
            sum += 28;
        month--;
    }

    sum += day;

    return sum;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int d1, m1, y1, d2, m2, y2;
    int sum_first = 0, sum_second = 0;

    scanf("%d%d%d%d%d%d", &d1, &m1, &y1, &d2, &m2, &y2);

    if (check_date(d1, m1, y1)) {
        printf("ERROR");
        return 0;
    }
    if (check_date(d2, m2, y2)) {
        printf("ERROR");
        return 0;
    }
    sum_first = count_days(d1, m1, y1);
    sum_second = count_days(d2, m2, y2);

    if (sum_first > sum_second) {
        printf("%d", sum_first - sum_second);
    } else {
        printf("%d", sum_second - sum_first);
    }
    return 0;

}