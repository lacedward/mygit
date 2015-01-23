#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 12
#define NULLKEY -1024
typedef struct
{
	int *elem;
	int count;
}HashTable;

int InitHashTable(HashTable *H)
{
	int i;
	H->elem = (int*)malloc(HASHSIZE* sizeof(int));

	if(!H->elem)
	{
		return -1;
	}
	for(i=0; i<HASHSIZE; i++)
	{
		H->elem[i] = NULLKEY;
	}
}

int HashFunc(int key)
{
	return  key % HASHSIZE;
}

void Insert_Hash(HashTable *H, int key)
{
	int addr;
	addr = HashFunc(key);
	while(H->elem[addr] != NULLKEY)
	{
		addr = (addr + 1) % HASHSIZE;
	}
	H->elem[addr] = key;
}

int Search_Hash(HashTable H, int key)
{
	int *addr;
	*addr = HashFunc(key);
	while(H.elem[*addr] != key)
	{
		*addr = (*addr + 1) % HASHSIZE;
		if(H.elem[*addr] == NULLKEY || *addr == HashFunc(key))
		{
			return -1;
		}
	}
	return *addr;
}

int main()
{
	return 0;
}