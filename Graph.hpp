
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>

using namespace std;
namespace ariel{

    class Graph{
        private:
        bool directed;
        std::vector<std::vector<int>> currentGraph;

        public:
        void loadGraph(std::vector<std::vector<int>> &v);
        string printGraph();
        bool isConnected();
        bool isSubMatrix(Graph g1 , Graph g2) const;
        void setMatrix(std::vector<std::vector<int>> o) ;
        std::vector<std::vector<int>> getMatrix() const;
        std::vector<std::pair<size_t, size_t>>  getEdges() ;
        Graph operator+(Graph& g);
        Graph operator-(Graph& g);
        Graph operator*(Graph& g);
        Graph operator/(Graph& g);
        Graph operator+(  );
        Graph operator-(  );
        Graph operator++();
        Graph operator++(int);
        Graph operator--();
        Graph operator--(int);
        Graph& operator+=(Graph& g);
        Graph& operator-=(Graph& g);
        Graph& operator*=(int n);
        Graph& operator/=(int n);
        bool operator==(Graph& g);
        bool operator!=(Graph& g) ;
        bool operator>(Graph& g) const;
        bool operator<(Graph& g);
        bool operator>=(Graph& g);
        bool operator<=(Graph& g);
        
        friend std::ostream& operator<<(std::ostream& os,Graph& g);
    };
}
#endif
