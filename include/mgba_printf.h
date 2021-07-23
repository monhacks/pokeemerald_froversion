#ifndef GUARD_MGBA_PRINTF_H
#define GUARD_MGBA_PRINTF_H
#if DEBUGGING

/* Very simple printf that only supports plain %d. */
void Printf(const char *fmt, ...);

#else

#define Printf(...) (void)0

#endif
#endif
