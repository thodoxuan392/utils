#include <utils_string.h>

char input[] =
	"2,1,206,0\r\nHTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: "
	"Upgrade\r\nSec-WebSocket-Accept: tuNFO/XNjXKBBczJqWfkXV1RTQA=\r\nSec-WebSocket-Protocol: "
	"ocpp1.6\r\n\r\n\210*\003ða connection with thisOK";

int main(int argc, char* argv[])
{
	char* outputBuffer[4];

	if(utils_string_split_with_fixed_no(input, strlen(input), ",", outputBuffer, 2, "OK"))
	{
		printf("mode:  %s\r\n", outputBuffer[0]);
		printf("linkNoStr:  %s\r\n", outputBuffer[1]);
		// printf("readLengthStr:  %s\r\n", outputBuffer[2]);
		// printf("restLengthStr:  %s\r\n", outputBuffer[3]);
	}
}