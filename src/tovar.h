#ifndef TOVAR_H
#define TOVAR_H

typedef struct {
    int year;
    int month;
    int day;
} DATE;

typedef struct {
    char name[50];
    int count;
    float price;
    DATE arrival_date;
} TOVAR;

// Прототипы функций
int create_spisok(TOVAR *list, int max_size);
float calculate_average_price(TOVAR *list, int size);
void sort_by_price(TOVAR *list, int size);
void print_old_goods(TOVAR *list, int size, DATE current_date);
void print_tovar(TOVAR t);

#endif
