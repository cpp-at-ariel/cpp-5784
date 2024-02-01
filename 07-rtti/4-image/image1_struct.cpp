/**
 * Writes a PPM image file.
 * 
 * Author: Erel Segal-Halevi.
 * Based on C code in RosettaCode: 
 * http://rosettacode.org/wiki/Category:C
 * 
 * Since: 2018-04
 */

#include <iostream>
#include <fstream>
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB(): red(0), green(0), blue(0) {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};



int main() {
  const int dimx = 3200, dimy = 3200;
  const int max_color = 256;
  RGB* image = new RGB[dimx*dimy];
  // RGB image[dimx*dimy]; // works as well
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      int ii = (i*max_color/dimx);  // normalize i to the range [0, max_color]
      int jj = (j*max_color/dimy);
      image[dimx*j+i].green = ii % (max_color);
      image[dimx*j+i].red = jj % (max_color);
      image[dimx*j+i].blue = ( (ii*ii+jj*jj) % max_color);
    }
  }
  ///
  ///Writing the image
  ///

  ofstream imageFile("image1_struct.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;

  //imageFile.write(image, 3*dimx*dimy);         // compile error
  imageFile.write((char*)(image), 3*dimx*dimy);   // fine
  // imageFile.write(reinterpret_cast<char*>(image), 3*dimx*dimy);  // fine
  imageFile.close();
  return 0;
}
