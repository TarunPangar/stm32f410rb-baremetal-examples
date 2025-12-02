#include <sys/stat.h>
#include <errno.h>
#include <stdint.h>

int _write(int file, char *ptr, int len) {
    return len;
}

int _read(int file, char *ptr, int len) {
    return 0;
}

int _close(int file) {
    return -1;
}

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    return 0;
}

void *_sbrk(ptrdiff_t incr) {
    extern uint8_t _end;     // Provided by linker
    extern uint8_t _estack;  // Provided by linker
    static uint8_t *heap_end;
    uint8_t *prev_heap_end;

    if (heap_end == 0) {
        heap_end = &_end;
    }
    prev_heap_end = heap_end;

    if (heap_end + incr > &_estack) {
        errno = ENOMEM;
        return (void *)-1;
    }

    heap_end += incr;
    return (void *)prev_heap_end;
}

