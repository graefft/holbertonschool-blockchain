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

	new_block = malloc(sizeof(*new_block));

	new_block->info = 
