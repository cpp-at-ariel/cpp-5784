#pragma once

#include "tooNoisy.h"

class Musician {
	std::string name;
public:
	Musician (std::string name);  
	~Musician ();
	void play () const;
private:		
	static const int M_MAX_CONCURRENTLY_PLAYING;
	static int m_currentPlayingMusicians;
};
