#include <stdio.h>
#include "tovar.h"

int create_spisok(TOVAR *list, int max_size) {
    int n;
    printf("Введите количество товаров (макс %d): ", max_size);
    scanf("%d", &n);
    if (n > max_size) n = max_size;

    for (int i = 0; i < n; i++) {
        printf("\nТовар #%d\n", i + 1);
        printf("Название: "); scanf("%s", list[i].name);
        printf("Количество: "); scanf("%d", &list[i].count);
        printf("Стоимость: "); scanf("%f", &list[i].price);
        printf("Дата поступления (день месяц год): ");
        scanf("%d %d %d", &list[i].arrival_date.day, 
                          &list[i].arrival_date.month, 
                          &list[i].arrival_date.year);
    }
    return n;
}

int main() {
    TOVAR SPISOK[10];
    int count = create_spisok(SPISOK, 10);

    if (count == 0) return 0;

    printf("\nСредняя стоимость: %.2f\n", calculate_average_price(SPISOK, count));

    printf("\nСортировка по возрастанию цены...");
    sort_by_price(SPISOK, count);
    for(int i=0; i<count; i++) print_tovar(SPISOK[i]);

    // Текущая дата для проверки (3 марта 2026 года)
    DATE today = {2026, 3, 3};
    print_old_goods(SPISOK, count, today);

    return 0;
}
