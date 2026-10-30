/****************************************************************
* Program: C-calender_v1                                        *
* About  : This is a simple calender -ish where the user inputs *
*          a string consist of a day of the month and the what  *
*          he has to do on that date, our program takes all the *
*          day of months input, sort it and then match the task *
*                                                               *
* Author : Ammar MULLAOGLU                                      *
* Date   : 30.10.2026                                           *
*****************************************************************/
//Preprocessor MACROS
//////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////

//Global variables
//////////////////////////////////////////////////////////////////
char calender[60][152];                         //Store the output here.
int input_no = 0;                               //This is input number ? it will help me with sorting I believe.
int day_of_month_array[60];
int day_of_month_array_sorted[60];
char task_part[60][150] = {0};
//////////////////////////////////////////////////////////////////


//Prototypes
//////////////////////////////////////////////////////////////////
void read_input(void);                          //Read input as two parts, int parts for day of month and string part for the task.
void quick_sort(int arr[], int low, int high);  //Quick sort.
void copy_int_arr(int arr1[], const int arr2[], int length);
int find_number(const int arr[], int length, int key);
void process(void);
void print_output(void);
//////////////////////////////////////////////////////////////////


int main(void){
    system("title C-calendar_v1");
    printf( "/****************************************************************\n"
            "* Program: C-calender_v1                                        *\n"
            "* About  : This is a simple calender -ish where the user inputs *\n"
            "*          a string consist of a day of the month and the what  *\n"
            "*          he has to do on that date, our program takes all the *\n"
            "*          day of months input, sort it and then match the task.*\n"
            "*          In order to get the result enter 0.                  *\n"
            "*                                                               *\n"
            "* Author : Ammar MULLAOGLU                                      *\n"
            "* Date   : 30.10.2026                                           *\n"
            "*****************************************************************/\n\n\n");

    read_input();
    copy_int_arr(day_of_month_array_sorted, day_of_month_array, input_no);
    quick_sort(day_of_month_array_sorted, 0, input_no - 1);
    process();
    print_output();

    return 0;
}

void quick_sort(int arr[], int low, int high){
    if(low >= high)
        return;

    int temp = arr[low];
    int middle;
    int start = low;
    int end = high;



    while(low < high ){ //add another condition.
        while(arr[high] > temp && low < high)high--;
            if(low < high){
                arr[low] = arr[high];
                low++;
            }
        while(arr[low] <= temp && low < high)low++;
            if(low < high){
                arr[high] = arr[low];
                high--;
            }
    }
    arr[low] = temp;
    middle = low;
    quick_sort(arr, start, middle - 1);
    quick_sort(arr, middle + 1, end);
}

void read_input(){
    while(1){
        printf("Enter day and reminder: ");
        scanf("%2d", &day_of_month_array[input_no]);
        if(day_of_month_array[input_no] == 0) //add calling output.
            break;
        fgets(task_part[input_no], sizeof(task_part[0]), stdin);
        input_no++;
    }
}

void copy_int_arr(int arr1[], const int arr2[], int length){
    for(int i = 0; i < length; i++)
        arr1[i] = arr2[i];

    return;
}

int find_number(const int arr[], int length, int key){
    for(int i = 0; i < length; i++){
        if(key == arr[i])
            return i;
    }
        printf("Error!\n");
        exit(EXIT_FAILURE);
}

void process(void){
    int targeted_index = 0;
    for(int i = 0; i < input_no; i++){
        targeted_index = find_number(day_of_month_array, input_no, day_of_month_array_sorted[i]);
        sprintf(calender[i], "%2d", day_of_month_array_sorted[i]);
        strcat(calender[i], task_part[targeted_index]);
        day_of_month_array[targeted_index] = 0;
    }
}

void print_output(void){
    printf("Day reminder: \n");
    for(int i = 0; i < input_no; i++){
        printf("%s", calender[i]);
    }
    return;
}
