#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "pixel.h"

// Run this program using g++ -std=c++11 -o pixel_processor main.cpp

void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);


int main(int argc, char* argv[])
{
	if (argc < 2) {
    	std::cerr << "Please provide the filename as a command line argument." << std::endl;
    	return 1;
   	}
    
    	std::string filename = argv[1];
    	std::ifstream infile(filename.c_str());
    	if (!infile) {
    	std::cerr << "Error opening file: " << filename << std::endl;
   	return 1;
    	}
    
   	std::vector<Pixel> pixel_list;
    	std::string line;
    
    	while (std::getline(infile, line)) {
    		std::stringstream ss(line);
  		std::string token;
    		Pixel pixel;
    
    		std::getline(ss, token, ',');
    		pixel.x = std::stoi(token);
    
    		std::getline(ss, token, ',');
    		pixel.y = std::stoi(token);
   
    		std::getline(ss, token, ',');
    		pixel.r = std::stof(token);
    
    		std::getline(ss, token, ',');
    		pixel.g = std::stof(token);
    
    		std::getline(ss, token, ',');
    		pixel.b = std::stof(token);
    
   		pixel_list.push_back(pixel);
   		}
    
   		infile.close();
                average_colors(pixel_list);
   		flip_vertically(pixel_list);
    
          	std::ofstream outfile("flipped.dat");
    		if (!outfile) {
   		std::cerr << "Error opening flipped.dat for writing." << std::endl;
    		return 1;
   		}
    		for (const Pixel &pixel : pixel_list) {
  		outfile << pixel.x << "," << pixel.y << ","
    		<< pixel.r << "," << pixel.g << "," << pixel.b << std::endl;
    		}
    
           	outfile.close();
  		return 0;
    		}
    
       
void average_colors(std::vector<Pixel> &pixel_list) {
	float total_r = 0, total_g = 0, total_b = 0;
    	int pixel_count = pixel_list.size();
    
    	for (const Pixel &pixel : pixel_list) {
       	total_r += pixel.r;
    	total_g += pixel.g;
    	total_b += pixel.b;
    	}
    
    	float avg_r = total_r / pixel_count;
    	float avg_g = total_g / pixel_count;
    	float avg_b = total_b / pixel_count;
    
    	std::cout << "Average R: " << avg_r << std::endl;
    	std::cout << "Average G: " << avg_g << std::endl;
   	std::cout << "Average B: " << avg_b << std::endl;
   	 }

void flip_vertically(std::vector<Pixel> &pixel_list) {
	int max_y = 255;  // Y-coordinates range from 0 to 255
    
  	for (Pixel &pixel : pixel_list) {
    	pixel.y = max_y - pixel.y;
    	}
}
