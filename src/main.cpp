#include "astar/common.hpp"
#include "astar/a-star-search.hpp"
#include "astar/graph.hpp"

#include <opencv2/core/utility.hpp>

#include <iostream>
#include <string>

int main(int argc, char ** argv){
    const std::string keys = 
        "{help h usage ?  |      | print this message }"
        "{@map            |      | map image          }"
        "{@start_x        |      | start x coord      }"
        "{@start_y        |      | start y coord      }"        "{@start_x        |      | start x coord     }"
        "{@goal_x          |      | goal x coord        }"
        "{@goal_y          |      | goal y coord        }"
        ;

    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("astar-search v0.0.1");
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }

    GraphGenerator graph_gen(parser.get<std::string>(0));
    graph_gen.DecomposeImg(0);
    graph_gen.ShowGraph();
    cv::waitKey(1);
    cv::Mat map = graph_gen.GetGraph();

    Position start(parser.get<double>(1),parser.get<double>(2));
    Position goal(parser.get<double>(3),parser.get<double>(4));
    std::cout << start << std::endl;
    std::cout << goal << std::endl;
    AStarSearch search(&map, start, goal);
    std::vector<Position> path = search.FindPath(start,goal);
    std::cout << "Path found:\n";
    std::vector<cv::Point2i> cv_path;
    for (Position wp : path) {
        std::cout << wp << "\n";
        cv_path.emplace_back(wp.y,wp.x);
    } 
    std::cout << std::endl;
    graph_gen.DrawPath(cv_path);
    graph_gen.ShowGraph();
    cv::waitKey(0);

    return 0;
}
