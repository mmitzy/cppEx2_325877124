#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph sum")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    
    CHECK(g3.printGraph() == "[0, 2, 1],[2, 0, 3],[1, 3, 0]");
    g3=-g3;
    CHECK(g3.printGraph() == "[0, -2, -1],[-2, 0, -3],[-1, -3, 0]");
    g3=+g3;
    CHECK(g3.printGraph() == "[0, -2, -1],[-2, 0, -3],[-1, -3, 0]");
    g3=++g3;
    CHECK(g3.printGraph() == "[1, -1, 0],[-1, 1, -2],[0, -2, 1]");
    g3=--g3;
    CHECK(g3.printGraph() == "[0, -2, -1],[-2, 0, -3],[-1, -3, 0]");
}

TEST_CASE("Test graph multiplication ")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g4;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    g4 = g1 * g2;
    CHECK(g4.printGraph() == "[0, 1, 0],[1, 0, 2],[0, 2, 0]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS( g1 + g2);
    

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 * g6);
}
TEST_CASE("Test graph devide ")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {1, 1, 1},
        {1, 1, 2},
        {1, 2, 1}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g4;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    g4 = g1 / g2;
    CHECK(g4.printGraph() == "[0, 1, 0],[1, 0, 0],[0, 0, 0]");
}
TEST_CASE("Test graph subtraction ")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g4;
    vector<vector<int>> expectedGraph = {
        {0, 0, -2},
        {-1, 0, -1},
        {-1, -2, 0}};
    g4 = g1 - g2;
    CHECK(g4.printGraph() == "[0, 0, -1],[0, 0, -1],[-1, -1, 0]");
}
TEST_CASE("Test graph operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    
    g3=-g3;
    CHECK(g3.printGraph() == "[0, -2, -1],[-2, 0, -3],[-1, -3, 0]");
    g3=+g3;
    CHECK(g3.printGraph() == "[0, -2, -1],[-2, 0, -3],[-1, -3, 0]");
    g3=++g3;
    CHECK(g3.printGraph() == "[1, -1, 0],[-1, 1, -2],[0, -2, 1]");
    g3=--g3;
    CHECK(g3.printGraph() == "[0, -2, -1],[-2, 0, -3],[-1, -3, 0]");
    g3+=g3;
    CHECK(g3.printGraph() == "[0, -4, -2],[-4, 0, -6],[-2, -6, 0]");
    g3*=2;
    CHECK(g3.printGraph() == "[0, -8, -4],[-8, 0, -12],[-4, -12, 0]");
    g3/=2;
    CHECK(g3.printGraph() == "[0, -4, -2],[-4, 0, -6],[-2, -6, 0]");
    g3-=g3;
    CHECK(g3.printGraph() == "[0, 0, 0],[0, 0, 0],[0, 0, 0]");
}
TEST_CASE("Test graph comparison")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    ariel::Graph g4 = g1 + g2;
    ariel::Graph g5 = g1 - g2;
    vector<vector<int>> hello = {
        {2,1},
        {0,1}};
    g5.loadGraph(hello);
    
    CHECK(g3 == g4);
    CHECK(g3 != g5);
    CHECK(g3 > g5);

    CHECK(g5 < g3);
    CHECK(g3 >= g4);
    CHECK(g5 <= g3);
}

TEST_CASE("checking algorithms")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ++g1;
    g1*=2;
    CHECK(ariel::Algorithms::isConnected(g1) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g1) == true);
    CHECK(ariel::Algorithms::isNegativeCycle(g1) == false);
    CHECK(ariel::Algorithms::isBipartite(g1) == "0");
}