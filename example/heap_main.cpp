#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <openssl/md5.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <utility>
#include <vector>
#include <string>
#include <boost/format.hpp>
#include "utility.hpp"
#include "storage.hpp"
#include "heap.hpp"

struct Value
{
	uint32_t Uin;
};

int main(int argc, char* argv[])
{
	MinimumHeap<uint32_t, Value> min = MinimumHeap<uint32_t, Value>::CreateHeap(10);
	MaximumHeap<uint32_t, Value> max = MaximumHeap<uint32_t, Value>::CreateHeap(10);

	for(uint32_t i=0; i<10; ++i)
	{
		uint32_t distance = random() % 9;
		min.Push(distance)->Uin = distance;
		max.Push(distance)->Uin = distance;
		
		printf("distance: %u uin:%u\n", distance, i);
	}

	Value* pMinValue = min.Minimum();
	printf("Minimum(%lu): %u\n", min.Count(), pMinValue->Uin);

	Value* pMaxValue = max.Maximum();
	printf("Maximum(%lu): %u\n", max.Count(), pMaxValue->Uin);

	printf("min: \n");
	min.DumpHeap();
	printf("max: \n");
	max.DumpHeap();

	min.Delete();
	max.Delete();
	return 0;
}





