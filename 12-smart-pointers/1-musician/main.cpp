/**
 * A demo of C pointers vs. smart pointers.
 * 
 * Authors: Eran Kaufmann, Erel Segal-Halevi
 * Since:  2020-06
 */


#include <iostream>
#include <vector>
#include <cstdlib>
#include "musician.hpp"
#include "AutoPointer.hpp"
#include "UniquePointer.hpp"
#include "SharedPointer.hpp"


using namespace std;


// Play music with C-style pointers
void playMusic1 (int numMusicians) {
	vector<Musician*> band (numMusicians);
	for (int i = 0; i < numMusicians; ++i)
		band[i] = new Musician(to_string(i));								

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();

	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	

	for (int i = 0; i < numMusicians; ++i)
		delete band[i];
}

// Play music with Java-style finally block - does not work in C++
#if Java
void playMusic2 (int numMusicians) {
	vector<Musician*> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i)
		band[i] = new Musician(to_string(i));								

	try {            
		for (int i = 0; i < numMusicians; ++i)
			band[i]->play();	
		
		cout << endl << endl << "All musicians in band are playing!" << endl << endl;	
	} finally {      
		for (int i = 0; i < numMusicians; ++i)
			delete band[i];
	}
}
#endif

// Play music with smart auto-pointers
void playMusic3 (int numMusicians) {
	vector<AutoPointer<Musician>> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i)
		band[i] = new Musician(to_string(i));								

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();
	
	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	
	// AutoPointer<Musician> other1 = band[0];         // Does not compile
	// AutoPointer<Musician> other2; other2 = band[0]; // Does not compile
}


// AutoPointer<Musician> auto_musician_with_a_random_name(int i) {
// 	AutoPointer<Musician> new_musician = new Musician("m_"+to_string(i)+"_"+to_string(rand()));
// 	return new_musician; // Does not compile
// }

UniquePointer<Musician> musician_with_a_random_name(int i) {
	UniquePointer<Musician> new_musician = new Musician("m_"+to_string(i)+"_"+to_string(rand()));
	return new_musician;
}


UniquePointer<Musician> champion1;

// Play music with smart unique-pointers
void playMusic4 (int numMusicians) {
	vector<UniquePointer<Musician>> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i) {
		band[i] = musician_with_a_random_name(i);
	}

	// band[0] = band[1];

	// UniquePointer<Musician> other2 = move(band[2]);
	// UniquePointer<Musician> other3; other3 = move(band[3]);
	champion1 = move(band[4]);

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();

	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	

}


SharedPointer<Musician> shared_musician_with_a_random_name(int i) {
	SharedPointer<Musician> new_musician = new Musician("m_"+to_string(i)+"_"+to_string(rand()));
	return new_musician;
}


SharedPointer<Musician> champion2;

// Play music with smart shared-pointers
void playMusic5 (int numMusicians) {
	vector<SharedPointer<Musician>> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i) {
		band[i] = new Musician(to_string(i));
		// band[i] = shared_musician_with_a_random_name(i);
		cout << endl;
	}

	cout << " --- " << endl;

	SharedPointer<Musician> other2 = band[2];
	SharedPointer<Musician> other3; other3 = band[3];
	champion2 = band[4];

	cout << " --- " << endl;

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();

	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	
}


int main () {
	int numMusicans = 7;
	try	{
		playMusic5(numMusicans);
	} catch (TooNoisy noisy) {
		cout << endl << endl << "It is too noisy here! " << noisy.getNumMusicians() << " musicians are playing concurrently! Stop Playing!" << endl << endl;
	}
}
