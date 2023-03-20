#include "astar/graph.hpp"

using namespace cv;

GraphGenerator::GraphGenerator(std::string img_path) {
  raw_img_ = imread(img_path, IMREAD_GRAYSCALE);
}

void GraphGenerator::DecomposeImg(uint16_t size) {
  if (size == 0)
    graph_ = raw_img_;
  else {
    cv::resize(raw_img_,graph_,Size(),1.0/size,1.0/size,cv::INTER_AREA);
  }
}

Mat GraphGenerator::GetGraph() { return graph_; }
 
void GraphGenerator::ShowGraph() {
  imshow("Graph", graph_);
}

void GraphGenerator::DrawPath(std::vector<cv::Point2i> path) {
  cv::cvtColor(graph_, processed,cv::COLOR_GRAY2BGR);
  for(int i=1;i<path.size();i++) {
    cv::line(processed,path[i-1],path[i],cv::Scalar(0,0,255),2,cv::LINE_8);
  }
  cv::imshow("Processed", processed);
}