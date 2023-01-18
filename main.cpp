#include <iostream>
#define MAXMN 100
#define MINX 0
#define MAXX 10

#define MAXRNDX (MAXX - MINX + 1)

int main() {
    int arr[MAXMN][MAXMN];
    int m, n;
    do {
        printf("Enter number of rows (1..%i):", MAXMN);
        scanf("%i", &n);
    } while (n < 1 || n > MAXMN);
    do {
        printf("Enter number of columns (1..%i):", MAXMN);
        scanf("%i", &m);
    } while (m < 1 || m > MAXMN);

    srand(time(NULL));

    // -----------------------------------
    printf("\nTask 1. Sorting rows:");

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            arr[j][i] = rand() % MAXRNDX + MINX;
        }
    }

    printf("\nGenerated array:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%6i", arr[j][i]);
        }
        printf("\n");
    }

    for (int r = 0; r < n; r++) {
        for (int j = m-1; j > 0; j--) {
            for (int i = 0; i < j; i++) {
                if (arr[r][i] > arr[r][i+1]) {
                    int t = arr[r][i];
                    arr[r][i] = arr[r][i+1];
                    arr[r][i+1] = t;
                }
            }
        }
    }

    printf("\nArray with sorted rows:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%6i", arr[j][i]);
        }
        printf("\n");
    }

    // --------------------------------------
    printf("\nTask 2. Switching columns:");

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            arr[j][i] = rand() % MAXRNDX + MINX;
        }
    }

    printf("\nGenerated array:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%6i", arr[j][i]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        int t = arr[i][0];
        arr[i][0] = arr[i][m-1];
        arr[i][m-1] = t;
    }

    printf("\nArray with switched first and last column:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%6i", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
