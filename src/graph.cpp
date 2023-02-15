#include "astar/graph.hpp"

using namespace cv;

GraphGenerator::GraphGenerator(std::string img_path) {
  raw_img_ = imread(img_path, IMREAD_GRAYSCALE);
}

void GraphGenerator::DecomposeImg(uint16_t size){
  //graph_ = raw_img;
}

Mat GraphGenerator::GetGraph(){
  return graph_;
}