#include "blockchain.h"

/**
 * hash_matches_difficulty - checks whether a given hash matches
 *                           a given difficulty
 * @hash: hash to check
 * @difficulty: minimum difficulty the hash should match
 * Return: 1 if difficulty is respected or 0 otherwise
 */
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
	uint32_t difficulty)
{
	uint8_t i = 0, msb = difficulty & 7;

	difficulty -= difficulty & 7;
	difficulty /= 8;

	while (i < difficulty)
	{
		if (hash[i] & 1)
			return (0);
		i++;
	}

	if (hash[difficulty] >> (8 - msb))
		return (0);

	return (1);
}
