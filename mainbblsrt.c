#include <stdio.h>
#include <windows.h>
#define p printf
#define s scanf
#define g gotoxy

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int arr[6];
    int n = 6;
    char ans;
    do {
        for (int i = 0; i < n; i++) {
        g(2, 2);p("Enter 6 numbers: ");
        scanf("%d", &arr[i]);
        g(20, 2);p("                ");
    }
    for (int i = 0; i < n; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;  
        }
    }
    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    p("Try again? Y/n ");
    s("%s", &ans);
    } while (ans == 'y' || ans == 'Y');
    

   
}
