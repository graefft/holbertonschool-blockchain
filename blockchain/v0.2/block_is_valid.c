#include "blockchain.h"

/**
 * match_genesis - check if block matches genesis block
 *
 * @block: Block to check
 * Return: 0 on success or -1 on failure
 */
int match_genesis(block_t const *block)
{
	if (memcmp(block->data.buffer, GENESIS_DATA, GENESIS_DATA_LEN) != 0)
		return (-1);
	if (block->data.len != GENESIS_DATA_LEN)
		return (-1);
	if (memcmp(block->hash, GENESIS_HASH, SHA256_DIGEST_LENGTH) != 0)
		return (-1);
	if (block->info.timestamp != GENESIS_TIMESTAMP)
		return (-1);

	return (0);
}

/**
 * block_is_valid - verifies that a Block is valid
 *
 * @block: Block to check
 * @prev_block: previous Block in the Blockchain or NULL if block is genesis
 *
 * Block requirements:
 *  1 - block should not be NULL
 *  2 - prev_block should be NULL ONLY if block‘s index is 0
 *  3 - If the Block’s index is 0, the Block should match the Genesis Block
 *      described in the first task
 *  4 - The Block’s index must be the previous Block’s index, plus 1
 *  5 - The computed hash of the previous block must match the one it stores
 *  6 - The computed hash of the previous block must match the reference one
 *  7 - The computed hash of the Block must match the one it stores
 *  8 - The Block data length must not exceed BLOCKCHAIN_DATA_MAX
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int block_is_valid(block_t const *block, block_t const *prev_block)
{
	uint8_t block_sha[SHA256_DIGEST_LENGTH];
	uint8_t prev_hash[SHA256_DIGEST_LENGTH];

	if (!block)
		return (EXIT_FAILURE);
	if (block->info.index == 0)
	{
		if (prev_block)
			return (EXIT_FAILURE);
		if (match_genesis(block) == -1)
			return (EXIT_FAILURE);
	}
	if (prev_block)
	{
		if (block->info.index - 1 != prev_block->info.index)
			return (EXIT_FAILURE);
		if (!block_hash(prev_block, prev_hash))
			return (EXIT_FAILURE);
		if (memcmp(block->info.prev_hash, prev_hash, SHA256_DIGEST_LENGTH) != 0)
			return (EXIT_FAILURE);
	}
	if (!block_hash(block, block_sha))
		return (EXIT_FAILURE);
	if (memcmp(block->hash, block_sha, SHA256_DIGEST_LENGTH) != 0)
		return (EXIT_FAILURE);
	if (block->data.len > BLOCKCHAIN_DATA_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
