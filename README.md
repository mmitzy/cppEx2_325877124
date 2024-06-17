Graph Operations with Operator Overloading
Daniel Ben David

    ID: 325877124
    Email: dani.bendav@gmail.com

Overview

This project implements a Graph class that supports a variety of operations through operator overloading. The graph is represented as an adjacency matrix, a square matrix that indicates whether pairs of vertices have edges between them and the weights of these edges. If an edge weight is '0', it signifies that there is no edge between the vertices.
Class and Function Descriptions
Class: Graph
Constructors

    Graph()
        Default constructor that initializes an empty graph with zero vertices and zero edges.

Member Functions

    void loadGraph(std::vector<std::vector<int>>& v)
        Loads a graph from a given adjacency matrix v.
        Checks if the input matrix is a square matrix; if not, throws an error and terminates the program.
        Sets the number of vertices and edges based on the input matrix.

    std::string printGraph()
        Returns a string representation of the graph's adjacency matrix.

    bool isConnected()
        Checks if the graph is connected.

    bool isSubMatrix(Graph g1, Graph g2) const
        Checks if g2 is a submatrix of g1.

    void setMatrix(std::vector<std::vector<int>> o)
        Sets the graph's adjacency matrix to o.

    std::vector<std::vector<int>> getMatrix() const
        Returns the adjacency matrix of the graph.

    std::vector<std::pair<size_t, size_t>> getEdges()
        Returns a list of edges in the graph.

Overloaded Operators

    Graph operator+(Graph& g)
        Adds two graphs by summing their adjacency matrices.

    Graph operator-(Graph& g)
        Subtracts the adjacency matrix of g from the current graph.

    Graph operator(Graph& g)*
        Multiplies the adjacency matrix of the current graph with g (matrix multiplication).

    Graph operator/(Graph& g)
        Divides the adjacency matrix of the current graph by g.

    Graph operator+( )
        Unary plus operator that returns the graph itself.

    Graph operator-( )
        Unary minus operator that negates the adjacency matrix of the graph.

    Graph operator++()
        Prefix increment operator that increments all non-zero elements of the adjacency matrix by 1.

    Graph operator++(int)
        Postfix increment operator that increments all non-zero elements of the adjacency matrix by 1.

    Graph operator--()
        Prefix decrement operator that decrements all non-zero elements of the adjacency matrix by 1.

    Graph operator--(int)
        Postfix decrement operator that decrements all non-zero elements of the adjacency matrix by 1.

    Graph& operator+=(Graph& g)
        Adds the adjacency matrix of g to the current graph.

    Graph& operator-=(Graph& g)
        Subtracts the adjacency matrix of g from the current graph.

    Graph& operator=(int n)*
        Multiplies all elements of the adjacency matrix by n.

    Graph& operator/=(int n)
        Divides all elements of the adjacency matrix by n.

    bool operator==(Graph& g)
        Checks if two graphs are equal by comparing their adjacency matrices.

    bool operator!=(Graph& g)
        Checks if two graphs are different by comparing their adjacency matrices.

    bool operator>(Graph& g) const
        Compares two graphs. Returns true if the current graph is "bigger" than g.

    bool operator<(Graph& g)
        Compares two graphs. Returns true if the current graph is "smaller" than g.

    bool operator>=(Graph& g)
        Checks if the current graph is greater than or equal to g.

    bool operator<=(Graph& g)
        Checks if the current graph is less than or equal to g.

    friend std::ostream& operator<<(std::ostream& os, const Graph& g)
        Overloads the output stream operator to print the adjacency matrix of the graph.
