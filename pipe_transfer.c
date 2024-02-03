#include <unistd.h>
#include <stdio.h>

int main(void) {
    char str1[6];  // Буфер для чтения строки
    char str[] = "hello";  // Строка, которую мы будем передавать
    int arr[2];  // Массив для хранения дескрипторов канала
    int a;

    // Создаем безымянный канал
    pipe(arr);

    // Создаем новый процесс
    a = fork();

    if (a > 0) {
        // Родительский процесс
        close(arr[0]);  // Закрываем конец для чтения

        // Пишем данные в канал
        write(arr[1], str, 6);

        close(arr[1]);  // Закрываем конец для записи

    }
    else {
        // Дочерний процесс
        close(arr[1]);  // Закрываем конец для записи

        // Читаем данные из канала
        read(arr[0], str1, 6);

        printf("\n%s\n", str1);

        close(arr[0]);  // Закрываем конец для чтения
    }

    return 0;
}
