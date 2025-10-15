#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(Book* b) {
    printf("Title: %s, Pages: %d, Price: %.1f\n", b->title, b->pages, b->price);
}

int main() {
    Book a;
    strcpy(a.title, "Don Quixote");
    a.pages = 1000;
    a.price = 750.0;
    
    Book** p = (Book**)malloc(sizeof(Book*));
    *p = &a;
    
    print_book(*p);
    
    free(p);
    return 0;
}
