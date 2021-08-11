#ifndef LUT_H
#define LUT_H

#include <stdint.h>

/**
 * Macro to create variable size lookup table at compile time 
 */
#define CREATE_LUT(name, lut_size) struct {                     \
                                    Pair table[lut_size];       \
                                    const size_t size;          \
                                    } name = {.size = lut_size}


#define LUT_MAX_KEY_SIZE 16
/**
 * Pair struct to keep lookup table data
 */
typedef struct Pair {
    char key[LUT_MAX_KEY_SIZE];
    int value; 
} Pair;

/**
 * @brief Insert key-value pair into lookup table
 * 
 * @param table table of the lookup table
 * @param size size of the lookup table
 * @param key key to be inserted
 * @param value value to be inserted
 */
void lut_insert(Pair* table, size_t size, const char* key, int value);

/**
 * @brief Get value of key from lookup table
 * 
 * @param table table of the lookup table
 * @param size size of the lookup table
 * @param key key for lookup
 * 
 * @return value paired with given key
 */
int lut_get(Pair* table, size_t size, const char* key);

/**
 * @brief Fill lookup table with reverse table (integers mapped to strings)
 * 
 * @param table table of the lookup table
 * @param size size of the lookup table
 * @param r_table array of strings
 * @param r_size size of \p r_table
 */
void lut_fill(Pair* table, size_t size,
              const char* const r_table[], size_t r_size);

#endif