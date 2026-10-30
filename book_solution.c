#include <stdio.h>
#include <string.h>
#define MAX_MSJ 60
#define MAX_REMINDER 60

int main(void){
    char calendar[MAX_REMINDER][MAX_MSJ + 3] = {0};
    char task_part[MAX_MSJ + 1] = {0};
    char day_of_month_str[3] = {0};
    int day_of_month_part, i, j, input_count = 0;

    while(1){
        if(input_count == MAX_REMINDER){
            printf("Error! The space if full!\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day_of_month_part);
        if(day_of_month_part == 0)
            break;
        sprintf(day_of_month_str, "%2d", day_of_month_part);
        fgets(task_part, MAX_MSJ + 1, stdin);
        for(i = 0; i < input_count; i++){
            if(strcmp(day_of_month_str, calendar[i]) < 0)
                break;
        }
        for(j = input_count; j > i; j--){
            strcpy(calendar[j], calendar[j-1]);
        }

        strcpy(calendar[i], day_of_month_str);
        strcat(calendar[i], task_part);

        input_count++;
    }

    printf("Day reminder: \n");

    for(i = 0; i < input_count; i++)
        printf("%s", calendar[i]);

    return 0;
}
