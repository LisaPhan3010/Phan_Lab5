/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
void readData(const char *filePath, double sales[MONTHS]) {
    FILE *f;
    f = fopen(filePath, "r");
    if (f == NULL) {
        perror("Error of opening file.\n");
        exit(EXIT_FAILURE);
    }
    for (int i=0; i < MONTHS; ++i) {
        if(fscanf(f, "%lf", &sales[i]) != 1) {
            printf("Error of reading file.\n");
            exit(EXIT_FAILURE);
        }
    }
    fclose(f);
}   

void generate_report(const char *months[MONTHS], const double sales[MONTHS]) {
    printf("Monthly sales report for 2022:\n");
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; ++i) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

void generate_sales_summary(const double sales[MONTHS], const char *months[MONTHS]) {
    double min = sales[0], max = sales[0], sum = 0;
    int minMonth = 0, maxMonth = 0;
    
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        sum += sales[i];
    }
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: $%.2f\n", sum / MONTHS);
}

void generate_moving_average_report(const char *months[MONTHS], const double sales[MONTHS]) {
    double sum;
    printf("Six-month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; ++i) {
        sum = 0;
        for (int j = i; j < i + 6; ++j) {
            sum += sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i+5], sum/6);
    }
    printf("\n");
}

void generate_sorted_sales_report(const char *months[MONTHS], const double sales[MONTHS]) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("%-10s %10s\n", "Month", "Sales");

    int indices[MONTHS];
    for (int i = 0; i < MONTHS; ++i) {
        indices[i] = i;
    }

    for (int i = 0; i < MONTHS - 1; ++i) {
        for (int j = i + 1; j < MONTHS; ++j) {
            if (sales[indices[i]] < sales[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    for (int i = 0; i < MONTHS; ++i) {
        printf("%-10s $%10.2f\n", months[indices[i]], sales[indices[i]]);
    }
}
int main() {
    const char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double sales[MONTHS];
    const char *filePath = "sample_data.txt";
    readData(filePath, sales);
    generate_report(months, sales);
    generate_sales_summary(sales, months);
    generate_moving_average_report(months,sales);
    generate_sorted_sales_report(months, sales);

    return 0;
}