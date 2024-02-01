#include "smartPointer.h"

MusicianSmartPointer::MusicianSmartPointer (Musician* pMusician)
: m_pMusician (pMusician)
{}
	
MusicianSmartPointer::~MusicianSmartPointer ()
{
	delete m_pMusician;
}

