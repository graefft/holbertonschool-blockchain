#include "blockchain.h"

/**
 * block_hash - computes the hash of a Block
 *
 * @block: Block to be hashed
 * @hash_buf: buffer to store resulting hash
 * Return: pointer to hash_buf
 */
uint8_t *block_hash(block_t const *block,
	uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t length = sizeof(block->info) + block->data.len;

	sha256((int8_t const *)block, length, hash_buf);

	return (hash_buf);
}
