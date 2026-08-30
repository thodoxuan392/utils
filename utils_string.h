#ifndef UTILS_STRING_H
#define UTILS_STRING_H

#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/**
 * @brief Compare Buffer with Len and Data String from the end of buffer to start of Buffer
 *
 * @param buffer Pointer to buffer
 * @param buffer_len Buffer Len
 * @param data String
 * @return true if Matched
 * @return false if not Matched
 */
bool utils_string_is_receive_data(char* buffer, uint16_t buffer_len, const char* data);

/**
 * @brief Convert String to Interger
 *
 * @param buffer Pointer to buffer
 * @param buffer_length Buffer Len
 * @return true Interger
 */
uint32_t utils_string_to_int(char* buffer, uint16_t buffer_length);

/**
 * @brief Split string into list of  token
 *
 * @param inputBuffer Input buffer to split
 * @param delimiter Delimiter
 * @param outputBuffer Output buffer to contain splitted token
 * @param fixedNo No token required
 * @return true If No splitted matched with fixedNo
 * @return false If it not matched
 */
bool utils_string_split_with_fixed_no(char* inputBuffer, uint32_t inputBufferLength,
									  char* delimiter, char** outputBuffer, uint32_t fixedNo,
									  char* endLine);

#endif // UTILS_BUFFER_H
