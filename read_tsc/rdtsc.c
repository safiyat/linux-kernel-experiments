/*
 * This program reads the current CPU cycle number that is
 * maintained in the Time Stamp Counter (TSC) and is read
 * using the rdtsc instruction.
 *
 * You can use this application (in a stupid way) to find
 * out the frequency of your CPU. Run this command program
 * twice, ten seconds apart, and then divide the difference
 * of the outputs by ten. Voila!
 * Of course the output won't be accurate.
 */


#include <stdio.h>
#include <stdlib.h>

static uint64_t rdtsc(void)
{
	uint64_t var;
	uint32_t hi, lo;

	__asm volatile
	    ("rdtsc" : "=a" (lo), "=d" (hi));

	var = ((uint64_t)hi << 32) | lo;
	return (var);
}


int main()
{
	printf("{\"rdtsc\": %llu}", rdtsc());
	return 0;
}
