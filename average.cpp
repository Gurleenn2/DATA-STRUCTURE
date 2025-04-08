#include <stdio.h>

int main() {
    int marks1, marks2, marks3, marks4, marks5;
    int sum;
    float average;

    printf("Enter marks of 5 subjects:\n");
    scanf("%d %d %d %d %d", &marks1, &marks2, &marks3, &marks4, &marks5);

    sum = marks1 + marks2 + marks3 + marks4 + marks5;
    average = sum / 5.0;

    printf("Average Marks: %.2f\n", average);

    if (marks1 >= 40 && marks2 >= 40 && marks3 >= 40 && marks4 >= 40 && marks5 >= 40) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }

    return 0;
}