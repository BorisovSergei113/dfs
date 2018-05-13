#include "catch.hpp"
#include <sstream>
#include "graph_dfs.hpp"
using namespace std;

TEST_CASE("Test Create new graph"){
    graph_dfs g;
    REQUIRE(g.Get_members_graph() == 0);
    REQUIRE(g.Get_matr_graph() == nullptr);
}

TEST_CASE("Test Read graph"){
    graph_dfs g(4);
    string input {
        "0 1 0 1\n"
        "1 0 1 0\n"
        "0 1 0 0\n"
        "1 0 0 0\n"
    };
    istringstream stream (input);
    g.read(stream);
    string result = "2 1 4 3 ";
    ostringstream output;
    g.write_result(g.DFS(2), output);
    REQUIRE(result == output.str());
}

TEST_CASE("Test incorrect input format"){
    graph_dfs g(4);
    string input {
        "0 1 8 1\n"
        "1 0 1 0\n"
        "0 1 0 0\n"
        "1 0 0 0\n"
    };
    istringstream stream (input);
    REQUIRE_THROWS(g.read(stream));
}

TEST_CASE("Test item cannot be linked to itself"){
    graph_dfs g(3);
    string input {
        "0 1 0 \n"
        "1 1 1 \n"
        "0 1 0 \n"
    };
    istringstream stream (input);
    REQUIRE_THROWS(g.read(stream));
}

