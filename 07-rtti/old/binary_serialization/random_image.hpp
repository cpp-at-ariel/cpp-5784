#pragma once

#include "write_read_utils.hpp"
#include "../dice/dice.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>

class random_image {
	uint32_t _width;
    uint32_t _height;
    uint8_t _bytes_per_pixel;
	std::vector<uint8_t> _bytes;

public:
	
	/// Creates a random image
	random_image(
		int32_t width= 0,
		int32_t height= 0,
		uint8_t bytes_per_pixel= 1)
		: _width(width), _height(height), _bytes_per_pixel(bytes_per_pixel),
		  _bytes(width*height*bytes_per_pixel) {

		assert(bytes_per_pixel>0);
		std::generate(_bytes.begin(), _bytes.end(), dice<uint8_t>(0,255));

	}
	
	/// creates an image from a binary file
	random_image(const std::string& filename) {
		std::ifstream infile(filename.c_str(), std::ios::binary | std::ios::in);
		readPOD(infile, _width);
		readPOD(infile, _height);
		readPOD(infile, _bytes_per_pixel);
		_bytes.resize(_width*_height*_bytes_per_pixel);
		readVectorOfPOD(infile, _bytes);
		infile.close();		
	}
		
	/// Serialize the image to out
	void write(std::ostream& out) const {
		writePOD(out, _width);
		writePOD(out, _height);
		writePOD(out, _bytes_per_pixel);
		writeVectorOfPOD(out, _bytes);
	}

	/// Opens a file and serialize the image to the file and closes the file
	void writeToFile(const std::string& filename) const {
		std::ofstream outfile(filename.c_str(), std::ios::binary | std::ios::out);
		write(outfile);
		outfile.close();
	}

	/// Returns true if the image are exactly the same
	bool operator==(const random_image& other) const {
		return
			other._width==_width&&
			other._height==_height&&
			other._bytes_per_pixel==_bytes_per_pixel&&
			other._bytes==_bytes;
	}
	
};

