#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmpstrings(const void *str1, const void *str2) {
    return strcmp(*(const char**)str1, *(const char**)str2);
}


int main() {
    FILE *input_fd = fopen("input_files/0022_names.txt", "r");
    if (!input_fd) {
        printf("Error reading file!\n");
        return -1;
    }

    char *input_string = malloc(sizeof(char) * 50000);
    if (!input_string) {
        printf("Error allocating from heap!\n");
        return -1;
    }
   
    fscanf(input_fd, "%s", input_string);

    char *name = strtok(input_string, ",");
    int name_count = 0;
    char *name_arr[6000];
    while (name) {
        name_arr[name_count++] = name;
        name = strtok(NULL, ",");
    }

    qsort(name_arr, name_count, sizeof(char*), cmpstrings);
    
    unsigned long int score = 0;
    int name_len = 0;
    unsigned long int name_score = 0;
    for (int i = 0; i < name_count; ++i) {
        name = name_arr[i];
        name_len = strlen(name);
        name_score = 0;
        for (int j = 1; j < name_len-1; ++j) {
            name_score += toupper(name[j]) - 'A' + 1;
        }
        score += name_score * (i+1);
    }
    printf ("Total score: %lu\n", score);

    return 0;
}

