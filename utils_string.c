#include "utils_string.h"

bool utils_string_is_receive_data(char* buffer, uint16_t buffer_len, const char* data)
{
	if(buffer == NULL || data == NULL)
	{
		return false;
	}
	uint16_t data_len = strlen(data);
	uint16_t actual_buffer_len = strlen(buffer);
	// Validate valid buffer
	if(actual_buffer_len == 0 || actual_buffer_len < buffer_len || data_len == 0)
	{
		return false;
	}
	else
	{
		for(uint16_t index = 0; index < data_len; index++)
		{
			if(buffer[buffer_len - data_len + index] != data[index])
			{
				return false;
			}
		}
	}
	return true;
}

/**
 * @brief Convert String to Interger
 *
 * @param buffer Pointer to buffer
 * @param buffer_length Buffer Len
 * @return true Interger
 */
uint32_t utils_string_to_int(char* buffer, uint16_t buffer_length)
{
	uint32_t result = 0;
	for(uint16_t var = 0; var < buffer_length; ++var)
	{
		if((buffer[var] >= '0') && (buffer[var] <= '9'))
		{
			result = result * 10 + (uint8_t)buffer[var] - '0';
		}
	}
	return result;
}

/**
 * @brief Split string into list of  token
 *
 * @param inputBuffer Input buffer to split
 * @param delimiter Delimiter
 * @param outputBuffer Output buffer to contain splitted token
 * @param fixedNo No token required
 * @param endLine Input Buffer must be ended at same with endLine
 * @return true If No splitted matched with fixedNo
 * @return false If it not matched
 */
bool utils_string_split_with_fixed_no(char* inputBuffer, uint32_t inputBufferLength,
									  char* delimiter, char** outputBuffer, uint32_t fixedNo,
									  char* endLine)
{
	uint32_t splittedTokenNo = 0;
	char* token;
	uint32_t endLineStrLen = strlen(endLine);

	for(size_t i = 0; i < endLineStrLen; i++)
	{
		if(inputBuffer[inputBufferLength - endLineStrLen + i] != endLine[i])
		{
			// Not same endLine
			return false;
		}
	}

	token = strtok(inputBuffer, delimiter);

	outputBuffer[splittedTokenNo++] = token;

	while(1)
	{
		if((splittedTokenNo + 1) == fixedNo)
		{
			outputBuffer[splittedTokenNo++] = token + strlen(token) + strlen(delimiter);
			break;
		}
		token = strtok(NULL, delimiter);
		if(token == NULL)
		{
			break;
		}
		outputBuffer[splittedTokenNo++] = token;
	}
	return (splittedTokenNo == fixedNo);
}
