#ifndef ASTAR_GRAPH_HPP
#define ASTAR_GRAPH_HPP

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class GraphGenerator{
    public:
    GraphGenerator(std::string img_path);
    // ~GraphGenerator();

    /**
     * @brief Decompose loaded img to graph
     * 
     */
    void DecomposeImg(uint16_t size);

    cv::Mat GetGraph();

    private:
    cv::Mat raw_img_;
    cv::Mat graph_;
};

#endif /* ASTAR_GRAPH_HPP */
