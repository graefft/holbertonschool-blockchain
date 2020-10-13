#include "blockchain.h"

#define GENESIS_DATA		"Holberton School"
#define GENESIS_DATA_LEN	16
#define GENESIS_HASH		"\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03"
#define GENESIS_TIMESTAMP	1537578000

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
