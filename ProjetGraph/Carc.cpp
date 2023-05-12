#include "Carc.h"

Carc::Carc(int dest) : iARCDestination(dest){}

int Carc::ARCLireDestination() const
{
	return iARCDestination;
}

void Carc::ARCModifierDestination(int dest)
{
	iARCDestination = dest;
}
