#include <stdio.h>
#include <string.h>

#define MAX_LEN 100


void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}


void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    FILE *fp;
    int count, age, i;
    char name[MAX_LEN];
    char course[MAX_LEN];
    char line[256];

  
    fp = fopen("student_records.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }

    printf("Writing Student Database:\n");
    printf("How many students do you want to record? ");
    if (scanf("%d", &count) != 1 || count < 1) {
        printf("Invalid number of students.\n");
        fclose(fp);
        return 1;
    }
    clearBuffer();

    for (i = 1; i <= count; i++) {
        printf("\nStudent %d\n", i);

        printf("Enter Name: ");
        fgets(name, sizeof(name), stdin);
        removeNewline(name);

        printf("Enter Age: ");
        scanf("%d", &age);
        clearBuffer();

        printf("Enter Course: ");
        fgets(course, sizeof(course), stdin);
        removeNewline(course);

        
        fprintf(fp, "Student %d\n", i);
        fprintf(fp, "Name: %s\n", name);
        fprintf(fp, "Age: %d\n", age);
        fprintf(fp, "Course: %s\n", course);
        fprintf(fp, "____________________\n\n");
    }

    fclose(fp);
    printf("\nStudent database successfully saved to file.\n");

  
    fp = fopen("student_records.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file for reading.\n");
        return 1;
    }

    printf("\nReading Student Database:\n\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}