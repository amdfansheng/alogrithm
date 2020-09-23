#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long long start(0), stop(0), range_num_(0);
    long range_size_ = atol(argv[1]);
    printf("range_size_: %ld\n", range_size_);
    long file_len = atol(argv[2]);
    printf("file_len: %ld\n", file_len);
    long local_file_len = atol(argv[3]);
    printf("local_file_len: %ld\n", local_file_len);
    file_len -= local_file_len;

    // file_len start from 0
    long rangeNum  = file_len / range_size_;
    printf("rangeNum: %ld\n", rangeNum);
    for (long i = 0; i <= rangeNum; i++) {
        if (i < rangeNum) {
            start = i * range_size_;
            stop  = (i + 1) * range_size_ - 1;
        } else {    // file_len < range_size_(rageNum = 0), last clice(rangeNum = i)
            if (file_len % range_size_ != 0) {   // last slice less than range_size_
                range_num_ = rangeNum + 1;
                start = i * range_size_;
                stop  = file_len - 1;
            } else { // last slice queal to range_size_ accurately
                range_num_ = rangeNum;
                break;
            }
        }
        start += local_file_len;
        stop += local_file_len;
        printf("[ %lld - %lld ]\n", start, stop);

        char range[64] = { 0 };
        snprintf(range, sizeof(range), "%ld-%ld", start, stop);
        printf(">>>> [ %s ]\n", range);
    }
    return 0;
}
