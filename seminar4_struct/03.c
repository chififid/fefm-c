#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct game {
    char title[50];
    double avg_rating;
};

int compare_games(const void* a, const void* b) {
    struct game* ga = (struct game*)a;
    struct game* gb = (struct game*)b;
    if (ga->avg_rating > gb->avg_rating) return -1;
    if (ga->avg_rating < gb->avg_rating) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct game games[100];
    
    for (int i = 0; i < n; i++) {
        char title[50];
        char temp;
        scanf("%[^:]", title);
        scanf("%c", &temp);
        
        int k;
        scanf("%d", &k);
        
        int sum = 0;
        for (int j = 0; j < k; j++) {
            int rating;
            scanf("%d", &rating);
            sum += rating;
        }
        
        strcpy(games[i].title, title);
        games[i].avg_rating = (double)sum / k;
        
        scanf("%c", &temp);
    }
    
    qsort(games, n, sizeof(struct game), compare_games);
    
    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].avg_rating);
    }
    
    return 0;
}
