#include <stdio.h>
#include "tovar.h"

float calculate_average_price(TOVAR *list, int size) {
    if (size <= 0) return 0;
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i].price;
    }
    return sum / size;
}

void sort_by_price(TOVAR *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j].price > list[j+1].price) {
                TOVAR temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

void print_old_goods(TOVAR *list, int size, DATE current_date) {
    printf("\nТовары, поступившие более 10 месяцев назад:\n");
    for (int i = 0; i < size; i++) {
        // Упрощенный расчет разницы в месяцах
        int months_diff = (current_date.year - list[i].arrival_date.year) * 12 
                        + (current_date.month - list[i].arrival_date.month);
        
        if (months_diff > 10) {
            print_tovar(list[i]);
        }
    }
}

void print_tovar(TOVAR t) {
    printf("Товар: %-15s | Кол-во: %-3d | Цена: %-8.2f | Дата: %02d.%02d.%d\n",
           t.name, t.count, t.price, t.arrival_date.day, t.arrival_date.month, t.arrival_date.year);
}
