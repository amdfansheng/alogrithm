#include <cstdio>
#include <cstdlib>

int g_m = 0;
int g_n = 0;

void dump(int **matrix, int m, int n)
{
    for (int i = 0; i < m; ++i) {
        for (int y = 0; y < n; ++y) {
            printf("%-10d ", matrix[i][y]);
        }
        printf("\n");
    }
}

int uniquePaths(int m, int n)
{
    if (m == 1 && n == 1) return 1;

    // initialization
    int matrix[m][n] = {{0}};
    matrix[m-1][n-1] = -1;
    for (int i = 0; i < m - 1; ++i) {
        matrix[i][n-1] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        matrix[m-1][i] = 1;
    }

    // calculate
    for (int i = m - 2; i > -1; --i) {
        for (int y = n - 2; y > -1; --y) {
            matrix[i][y] = matrix[i][y+1] + matrix[i+1][y];
        }
    }

    // dump result
    //dump((int **)matrix, m, n); // will be segment fault
    for (int i = 0; i < m; ++i) {
        for (int y = 0; y < n; ++y) {
            printf("%-10d ", matrix[i][y]);
        }
        printf("\n");
    }
    return matrix[0][0];
}


int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "uniquePaths <m> <n>\n");
        return -1;
    }

    g_m = atoi(argv[1]);
    g_n = atoi(argv[2]);
    int ret = uniquePaths(g_m, g_n);
    printf("%d\n", ret);
}
