#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** result = (char**)malloc(4 * sizeof(char*));
    result[0] = (char*)malloc(4 * sizeof(char));
    result[1] = (char*)malloc(9 * sizeof(char));
    result[2] = (char*)malloc(6 * sizeof(char));
    result[3] = NULL;
    
    strcpy(result[0], "Cat");
    strcpy(result[1], "Elephant");
    strcpy(result[2], "Mouse");
    
    return result;
}

void print_strings(const char** string_array) {
    for (int i = 0; string_array[i] != NULL; i++) {
        printf("%s\n", string_array[i]);
    }
}

size_t* get_sizes(const char** string_array) {
    int count = 0;
    while (string_array[count] != NULL) {
        count++;
    }
    
    size_t* sizes = (size_t*)malloc(count * sizeof(size_t));
    for (int i = 0; i < count; i++) {
        sizes[i] = strlen(string_array[i]);
    }
    
    return sizes;
}

char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;
    
    int line_count = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') line_count++;
    }
    line_count++;
    
    fseek(file, 0, SEEK_SET);
    
    char** lines = (char**)malloc((line_count + 1) * sizeof(char*));
    lines[line_count] = NULL;
    
    int* line_lengths = (int*)malloc(line_count * sizeof(int));
    int current_line = 0;
    int current_length = 0;
    
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            line_lengths[current_line] = current_length;
            current_line++;
            current_length = 0;
        } else {
            current_length++;
        }
    }
    line_lengths[current_line] = current_length;
    
    fseek(file, 0, SEEK_SET);
    
    for (int i = 0; i < line_count; i++) {
        lines[i] = (char*)malloc((line_lengths[i] + 1) * sizeof(char));
        for (int j = 0; j < line_lengths[i]; j++) {
            lines[i][j] = fgetc(file);
        }
        lines[i][line_lengths[i]] = '\0';
        fgetc(file);
    }
    
    free(line_lengths);
    fclose(file);
    return lines;
}

void destroy_strings(char*** p_string_array) {
    char** array = *p_string_array;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    *p_string_array = NULL;
}

void sort_strings(char** words) {
    int count = 0;
    while (words[count] != NULL) {
        count++;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    
    char** lines = load_lines(argv[1]);
    if (!lines) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }
    
    sort_strings(lines);
    
    FILE* output = fopen(argv[2], "w");
    if (!output) {
        printf("Error: Cannot create file %s\n", argv[2]);
        destroy_strings(&lines);
        return 1;
    }
    
    for (int i = 0; lines[i] != NULL; i++) {
        fprintf(output, "%s\n", lines[i]);
    }
    
    fclose(output);
    destroy_strings(&lines);
    return 0;
}
