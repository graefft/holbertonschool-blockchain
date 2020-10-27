#include "blockchain.h"

/**
 * genesis_create - creates Genesis Block
 *
 * Return: pointer to created Genesis block or NULL on failure
 */
block_t *genesis_create(void)
{
	block_t *genesis;

	genesis = calloc(1, sizeof(*genesis));
	if (!genesis)
		return (NULL);

	memcpy(genesis->data.buffer, GENESIS_DATA, GENESIS_DATA_LEN);
	genesis->data.len = GENESIS_DATA_LEN;
	memcpy(genesis->hash, GENESIS_HASH, SHA256_DIGEST_LENGTH);
	genesis->info.timestamp = GENESIS_TIMESTAMP;

	return (genesis);
}

/**
 * blockchain_create - creates a Blockchain structure
 *
 * Return: pointer to created Blockchain
 */
blockchain_t *blockchain_create(void)
{
	blockchain_t *blockchain;
	block_t *genesis;

	blockchain = calloc(1, sizeof(*blockchain));
	if (!blockchain)
	{
		perror("Malloc");
		return (NULL);
	}
	genesis = genesis_create();
	if (!genesis)
	{
		free(blockchain);
		perror("Malloc");
		return (NULL);
	}
	blockchain->chain = llist_create(MT_SUPPORT_TRUE);
	if (!blockchain->chain)
	{
		free(blockchain), free(genesis);
		perror("Blockchain->chain");
		return (NULL);
	}
	if (llist_add_node(blockchain->chain, genesis, ADD_NODE_FRONT) == -1)
	{
		free(blockchain), free(genesis);
		perror("llist_add_node");
		return (NULL);
	}
	return (blockchain);
}
