#include <stdio.h>
#include <string.h>

typedef struct Label_s {
    char name[16]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
} Label;

typedef struct NameStats_s {
    int cntTotal; //сколько всего подписей
    int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s {
    int cntTotal; //сколько всего подписей
    int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids; //сколько подписей детей (меньше 14 лет)
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) {
    oNames->cntTotal = cnt;
    oAges->cntTotal = cnt;

    for (int i = 0; i < cnt; i++) {
        if (strlen(arr[i].name) > 10) {
            oNames->cntLong++;
        }
        if (arr[i].age >= 18) {
            oAges->cntAdults++;
        }
        if (arr[i].age < 14) {
            oAges->cntKids++;
        }

    }
}

Label list_of_Labels[1000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s%d let", list_of_Labels[i].name, &list_of_Labels[i].age);
    }

    NameStats n_statistic = {0, 0};
    AgeStats a_statistic = {0, 0, 0};
    calcStats(list_of_Labels, n, &n_statistic, &a_statistic);

    printf("names: total = %d\n", n_statistic.cntTotal);
    printf("names: long = %d\n", n_statistic.cntLong);
    printf("ages: total = %d\n", a_statistic.cntTotal);
    printf("ages: adult = %d\n", a_statistic.cntAdults);
    printf("ages: kid = %d\n", a_statistic.cntKids);
}