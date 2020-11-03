#include "blockchain.h"

/**
 * hash_matches_difficulty - checks whether a given hash matches 
 *                           a given difficulty
 * @hash: hash to check
 * @difficulty: minimum difficulty the hash should match
 * Return: 1 if difficulty is respected or 0 otherwise
 */
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH], uint32_t difficulty)
{
	uint8_t *p;

	while (p < hash + SHA256_DIGEST_LENGTH)
	{
		for (i = 8; i >= 1; i--)
		{
			if ((*p >> 1) & 1)
				return (difficulty);
			difficulty++;
		}
		p++;
	}
	if (hash[difficulty] >> (8 - (difficulty & 7)))
		return (0);
	return (1);

	return (0);
}
