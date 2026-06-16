#ifndef KV_H
#define KV_H

#include <stdlib.h>

//RFDtypedef struct
//RFD{
//RFD	char *key;
//RFD	char *value;
//RFD} kv_entry_t;
//RFD
//RFDtypedef struct
//RFD{
//RFD	kv_entry_t *entries;
//RFD	size_t capacity;
//RFD	size_t count;
//RFD}kv_t;
//RFD
//RFDkv_t *kv_init(size_t capacity);
//RFDint kv_put(kv_t *db, char *key, char *value);
//RFDchar *kv_get(kv_t *db, char *key);
//RFDint kv_delete(kv_t *db, char *key);
//RFDint kv_free(kv_t *db);

#define TOMBSTONE ((char *)0x1)

typedef struct {
    char *key;
    char *value;
} kv_entry_t;

typedef struct {
    kv_entry_t *entries;
    size_t      capacity;
    size_t      count;
} kv_t;

kv_t  *kv_init(size_t capacity);
int    kv_put(kv_t *db, const char *key, const char *value);
char  *kv_get(kv_t *db, const char *key);
int    kv_delete(kv_t *db, const char *key);
int    kv_free(kv_t *db);

#endif