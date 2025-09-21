#include <stdio.h>

enum shape {
    ROCK,
    PAPER,
    SCISSORS
};

enum result {
    LOSS,
    DRAW,
    WIN
};

void print_shape(enum shape s) {
    switch (s) {
        case ROCK:
            printf("Rock");
            break;
        case PAPER:
            printf("Paper");
            break;
        case SCISSORS:
            printf("Scissors");
            break;
    }
}

void print_result(enum result r) {
    switch (r) {
        case LOSS:
            printf("Loss");
            break;
        case DRAW:
            printf("Draw");
            break;
        case WIN:
            printf("Win");
            break;
    }
}

enum result get_result(enum shape a, enum shape b) {
    if (a == b) {
        return DRAW;
    }
    switch (a) {
        case ROCK:
            if (b == SCISSORS) return WIN;
            if (b == PAPER) return LOSS;
            break;
        case PAPER:
            if (b == ROCK) return WIN;
            if (b == SCISSORS) return LOSS;
            break;
        case SCISSORS:
            if (b == PAPER) return WIN;
            if (b == ROCK) return LOSS;
            break;
    }
    return LOSS;
}

enum shape get_strength(enum shape s) {
    switch (s) {
        case ROCK:
            return SCISSORS;
        case PAPER:
            return ROCK;
        case SCISSORS:
            return PAPER;
    }
    return ROCK;
}

int main() {
    printf("Shapes:\n");
    print_shape(ROCK);
    printf("\n");
    print_shape(PAPER);
    printf("\n");
    print_shape(SCISSORS);
    printf("\n\n");

    printf("Results:\n");
    print_result(LOSS);
    printf("\n");
    print_result(DRAW);
    printf("\n");
    print_result(WIN);
    printf("\n\n");

    printf("Game outcomes (Rock vs. ?):\n");
    print_result(get_result(ROCK, PAPER));
    printf("\n");
    print_result(get_result(ROCK, SCISSORS));
    printf("\n");
    print_result(get_result(ROCK, ROCK));
    printf("\n\n");

    printf("Strength:\n");
    print_shape(get_strength(PAPER));
    printf("\n");
    print_shape(get_strength(ROCK));
    printf("\n");
    print_shape(get_strength(SCISSORS));
    printf("\n");

    return 0;
}
