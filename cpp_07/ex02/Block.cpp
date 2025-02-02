#include "Block.hpp"

Block::Block()
{
	member1 = 0;
	member2 = 0;
	member3 = 0;
}

Block::Block(int _member1, int _member2, int _member3)
{
	member1 = _member1;
	member2 = _member2;
	member3 = _member3;
}
#include <iostream>

Block Block::operator+(Block &otherBlock)
{
	Block result(member1 + otherBlock.member1 , member2 + otherBlock.member2 , member3 + otherBlock.member3);
	return result;
}

std::ostream &operator<<(std::ostream &stream, const t_Block &blockObj)
{
	stream << blockObj.member1 << ", ";
	stream << blockObj.member2 << ", ";
	stream << blockObj.member3 ;
	return stream;
}