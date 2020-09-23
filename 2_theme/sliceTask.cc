#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "%s <tNum> <qNum>\n", argv[0]);
        return 0;
    }
    int tNum = atoi(argv[1]);
    int qNum = atoi(argv[2]);
    if (tNum > qNum) {
        fprintf(stderr, "tNum=%d, qNum=%d\n", tNum, qNum);
        fprintf(stderr, "tNum should be less than qNum\n");
        return 0;
    }

    int tmp[tNum];
    memset(tmp, 0, tNum * sizeof(int));

    int aver = qNum / tNum;
    int rema = qNum % tNum;
    for (int i = 0; i < tNum; ++i) {
        if (!rema) {
            tmp[i] = aver;
            fprintf(stderr, "%d: %d-%d\n", tmp[i], i * aver, (i + 1)*aver - 1);
        } else {
            tmp[i] = aver;
            if (i < rema) {
                tmp[i] += 1;
                fprintf(stderr, "%d: %d-%d\n", tmp[i], tmp[i]*i, tmp[i] * (i + 1) - 1);
            } else {
                fprintf(stderr, "%d: %d-%d\n", tmp[i], i * aver + rema, (i + 1)*aver + rema - 1);
            }
        }
    }
}
