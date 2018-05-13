#include "graph_dfs.hpp"
#include <sstream>

int main(){
    graph_dfs g(4);
    std::string input
    {
        "0 1 0 0 \n"
        "1 0 1 1 \n"
        "0 1 0 0 \n"
        "0 1 0 0 \n"
    };
    std::istringstream stream(input);
    g.read(stream);
    std::cout<<std::endl;
    std::ostringstream output;
    g.write_result(g.DFS(2),output);
    std::cout<<std::endl;
    return 0;
}

