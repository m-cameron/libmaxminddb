#ifndef GEODB_HELPER
#define GEODB_HELPER (1)
#include "maxminddb.h"
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

/* dummy content */

#define die(...) do { \
    fprintf(stderr, __VA_ARGS__); \
    exit(1); \
} while(0)

#define free_list(...) do{ \
    { \
        void *ptr[] = { __VA_ARGS__ }; \
        for (int i = 0; i < sizeof(ptr)/sizeof(void *); i++){ \
            if (ptr[i]) \
                free(ptr[i]); \
        } \
    } \
}while(0)

char *bytesdup(MMDB_s * mmdb, MMDB_entry_data_s const *const ret);
void dump_meta(MMDB_s mmdb);
void usage(char *prg);
int is_ipv4(MMDB_s * mmdb);
MMDB_s open_or_die (const char *fname, int mode);
MMDB_lookup_result_s *lookup_or_die (MMDB_s *mmdb, const char *ipstr);
void dump_ipinfo(const char *ipstr, MMDB_lookup_result_s * ipinfo);
#endif
