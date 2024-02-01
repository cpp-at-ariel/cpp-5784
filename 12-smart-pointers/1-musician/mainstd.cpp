/**
 * A demo of C pointers vs. smart pointers, using the standard variables.
 * 
 * Authors: Eran Kaufmann, Erel Segal-Halevi
 * Since:  2020-06
 */


#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include "musician.hpp"


using namespace std;


unique_ptr<Musician> musician_with_a_random_name(int i) {
	unique_ptr<Musician> new_musician { new Musician("m_"+to_string(i)+"_"+to_string(rand())) };
	return new_musician;
}


unique_ptr<Musician> champion1;

// Play music with smart unique-pointers
void playMusic4 (int numMusicians) {
	vector<unique_ptr<Musician>> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i)
		band[i] = musician_with_a_random_name(i);

	unique_ptr<Musician> other2 = move(band[2]);
	unique_ptr<Musician> other3; other3 = move(band[3]);
	champion1 = move(band[4]);

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();

	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	

}


shared_ptr<Musician> shared_musician_with_a_random_name(int i) {
	shared_ptr<Musician> new_musician { new Musician("m_"+to_string(i)+"_"+to_string(rand())) };
	return new_musician;
}


shared_ptr<Musician> champion2;

// Play music with smart shared-pointers
void playMusic5 (int numMusicians) {
	vector<shared_ptr<Musician>> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i)
		band[i] = shared_musician_with_a_random_name(i);

	shared_ptr<Musician> other2 = band[2];
	shared_ptr<Musician> other3; other3 = band[3];
	champion2 = band[4];

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();

	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	
}


int main () {
	int numMusicans = 7;
	try	{
		playMusic4(numMusicans);
	} catch (TooNoisy& noisy) {
		cout << endl << endl << "It is too noisy here! " << noisy.getNumMusicians() << " musicians are playing concurrently! Stop Playing!" << endl << endl;
	}
}
