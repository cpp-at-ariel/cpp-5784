#pragma once

#include <iostream>
#include "musician.h"

using namespace std;

class MusicianSmartPointer
{
public:
	MusicianSmartPointer (Musician* pMusician = 0);
	~MusicianSmartPointer ();

	inline MusicianSmartPointer& operator= (Musician* pMusician);	

	inline Musician& operator*() const;
	inline Musician* operator->() const;
	inline Musician* get() const;

private:
	Musician* m_pMusician;
	// Preventing copy and assignment operations
	MusicianSmartPointer (const MusicianSmartPointer&);
	MusicianSmartPointer& operator = (const MusicianSmartPointer&);	
};


inline MusicianSmartPointer& MusicianSmartPointer::operator = (Musician* pMusician)
{
	m_pMusician = pMusician;
	return *this;
}

inline Musician& MusicianSmartPointer::operator*() const 
{ 
	return *m_pMusician; 
}

inline Musician* MusicianSmartPointer::operator->() const 
{ 
	return m_pMusician; 
}

inline Musician* MusicianSmartPointer::get() const 
{ 
	return m_pMusician; 
}
