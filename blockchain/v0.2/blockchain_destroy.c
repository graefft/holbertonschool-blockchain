#include "blockchain.h"

/**
 * blockchain_destroy - deletes an existing blockchain and all of its blocks
 *
 * @blockchain: Blockchain to destroy
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;

	/* Free each block */
	llist_destroy(blockchain->chain, 1, NULL);

	free(blockchain);
}
