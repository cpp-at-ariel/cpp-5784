#pragma once

class TooNoisy {
public:
	inline TooNoisy (int numMusicians);
	inline int getNumMusicians();
private:
	int m_numMusicians;
};


inline TooNoisy::TooNoisy (int numMusicians) : m_numMusicians (numMusicians)
{}

inline int TooNoisy::getNumMusicians()
{
	return m_numMusicians;
}
