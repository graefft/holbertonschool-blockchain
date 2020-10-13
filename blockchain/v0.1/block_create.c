#include "blockchain.h"

/**
 * block_create - creates new Block structure and initializes it
 *
 * @prev: pointer to previous Block in Blockchain
 * @data: memory area to duplicate in the Block's data
 * @data_len: stores number of bytes to duplicate
 *
 * index must be different than previous
 * difficulty and nonce must be initialized to 0
 * timestamp should be initialized with time(2) syscall
 * hash must be zeroed
 *
 * Return: pointer to allocated Block
 */
block_t *block_create(block_t const *prev, int8_t const *data,
	uint32_t data_len)
{
	block_t *new_block;
	uint32_t length;

	new_block = calloc(1, sizeof(*new_block));
	if (!new_block)
	{
		perror("Calloc");
		return (NULL);
	}
	new_block->info.index = prev->info.index + 1;
	new_block->info.difficulty = 0;
	new_block->info.nonce = 0;
	new_block->info.timestamp = (uint64_t)time(NULL);
	memcpy(new_block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
	length = data_len < BLOCKCHAIN_DATA_MAX ? data_len : BLOCKCHAIN_DATA_MAX;
	memcpy(new_block->data.buffer, data, length);
	new_block->data.len = length;

	return (new_block);
}
