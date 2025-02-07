#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort(int *a, int n, int m);
void sort_vertical(int *matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int *matrix, int n, int m, int **result_matrix);

void input(int *matrix, int n, int m);
void output(int **matrix, int n, int m);

int main() {
    int n, m;
    int error = 0;

    if (scanf("%d %d", &n, &m) == 2 || (n <= 0) || (m <= 0)) {
        error = -1;
    }
    int *matrix = (int *)malloc(n * m * sizeof(int *));
    int **result = (int **)malloc(n * m * sizeof(int *));

    input(matrix, n, m);
    sort(matrix, n, m);
    sort_vertical(matrix, n, m, result);
    output(result, n, m);
    printf("\n");
    sort_horizontal(matrix, n, m, result);
    output(result, n, m);
    free(matrix);
    free(result);
}

void input(int *matrix, int n, int m) {
    int error = 0;
    for (int i = 0; i < n * m; i++) {
        if (!scanf("%d", &matrix[i])) {
            error = -1;
        }
    }
}

void sort(int *a, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        for (int j = i + 1; j < n * m; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sort_vertical(int *matrix, int n, int m, int **result_matrix) {
    int count = 0, count_n = 1, plus_minus = 1;
    result_matrix[0] = &matrix[0];
    for (int i = 1; i < n * m; i++) {
        if (count_n < n) {
            count = count + m * plus_minus;
        }
        if (count_n == n) {
            count++;
            plus_minus *= -1;
            count_n = 0;
        }
        result_matrix[count] = &matrix[i];
        count_n++;
    }
}

void output(int **matrix, int n, int m) {
    int count = 1;
    for (int i = 0; i < n * m; i++) {
        if (count < m) {
            printf("%d ", *matrix[i]);
        } else if (count == m) {
            printf("%d", *matrix[i]);
            printf("\n");
            count = 0;
        }
        count++;
    }
}

void sort_horizontal(int *matrix, int n, int m, int **result_matrix) {
    int count = 0, count_n = 1, plus_minus = 1;
    result_matrix[0] = &matrix[0];
    for (int i = 1; i < n * m; i++) {
        if (count_n < m) {
            count += 1 * plus_minus;
        }
        if (count_n == m) {
            count += m;
            plus_minus *= -1;
            count_n = 0;
        }
        result_matrix[count] = &matrix[i];
        count_n++;
    }
}
