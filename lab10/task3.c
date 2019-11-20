#include <stdio.h>
#include <string.h>

char str1[1000001] = {0};
char str2[100] = {0};

char *concat(char *pref, char *suff) {
    int len_pref = strlen(pref);
    int len_stuff = strlen(suff);

    for (int i = 0; i < len_stuff; i++) {
        pref[len_pref + i] = suff[i];
    }
    pref[len_pref + len_stuff] = '\0';
    return &pref[len_pref + len_stuff];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i ++){
        scanf("%s", str2);
        if(str2[0] == '0'){
            continue;
        }
        concat(str1, str2);
    }
    printf("%s", str1);


}