#ifndef ASTAR_GRAPH_HPP
#define ASTAR_GRAPH_HPP

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

/// @brief Generates graph from image
class GraphGenerator{
    public:
    GraphGenerator(std::string img_path);
    // ~GraphGenerator();

    /**
     * @brief Decompose image to graph
     * 
     * @param size size to decompose, 0 to use raw
     */
    void DecomposeImg(uint16_t size);

    cv::Mat GetGraph();
    void ShowGraph();

    void DrawPath(std::vector<cv::Point2i> path);

    private:
    cv::Mat raw_img_;
    cv::Mat graph_;
    cv::Mat processed;
};

#endif /* ASTAR_GRAPH_HPP */
