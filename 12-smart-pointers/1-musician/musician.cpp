#include <iostream>
#include "musician.hpp"

using namespace std;

const int Musician::M_MAX_CONCURRENTLY_PLAYING (5);
int Musician::m_currentPlayingMusicians (0);

Musician::Musician (string name): name(name) {
	cout << "Hello, I am " << name << ", a new musician!" << endl;
}

Musician::~Musician () {
	cout << "Musician " << name << " is deleted..." << endl;
}

void Musician::play() const //throw (TooNoisy)
{
	if (++m_currentPlayingMusicians > M_MAX_CONCURRENTLY_PLAYING)
		throw TooNoisy (m_currentPlayingMusicians);		
}
