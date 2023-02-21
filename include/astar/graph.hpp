#ifndef ASTAR_GRAPH_HPP
#define ASTAR_GRAPH_HPP

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

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

    private:
    cv::Mat raw_img_;
    cv::Mat graph_;
};

#endif /* ASTAR_GRAPH_HPP */
