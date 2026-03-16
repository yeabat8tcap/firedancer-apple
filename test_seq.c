#include <stdio.h>
#define ULONG_MAX 0xFFFFFFFFFFFFFFFFUL

int main() {
    unsigned long depth = 1024;
    unsigned long seq0 = 0;
    unsigned long mcache_seq[1024];
    for (unsigned long i = 0; i < depth; i++) {
        mcache_seq[i] = i - 1; // Unsigned underflow for 0-1 is ULONG_MAX
    }

    unsigned long this_in_seq = 0;
    for (int step = 0; step < 10; step++) {
        unsigned long line = this_in_seq & (depth - 1);
        unsigned long seq_found = mcache_seq[line];
        long diff = (long)(this_in_seq - seq_found);

        printf("step %d: this_in_seq=%lu, line=%lu, seq_found=%lu, diff=%ld\n",
            step, this_in_seq, line, seq_found, diff);

        if (diff < 0L) {
            this_in_seq = seq_found;
            printf("  -> OVERRUN: this_in_seq updated to %lu\n", this_in_seq);
        } else if (diff == 0L) {
            printf("  -> PROCESS FRAGMENT!\n");
            break;
        } else {
            printf("  -> AHEAD, wait\n");
            break;
        }
    }
    return 0;
}
