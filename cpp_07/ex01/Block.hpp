#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iostream>

typedef struct Block
{
	int member1;
	int member2;
	int member3;
	Block();
	Block(int _member1, int _member2, int _member3);
	Block operator+(Block &otherBlock);
}t_Block;

std::ostream &operator<<(std::ostream &stream, const t_Block &blockObj);

#endif
