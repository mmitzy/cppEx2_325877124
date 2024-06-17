/*
* id - 325877214
* name - Daniel Ben David
* email - dani.bendav@gmail.com
*/



#include "Graph.hpp"
#include <iostream>
#include <unordered_set>

using namespace ariel;
using namespace std;


//constructor
    void Graph :: loadGraph(std::vector<std::vector<int>> &v){

        if (v.empty()){
            std :: __throw_invalid_argument("matrix is empty");
        }
        if ( v.size() != v[0].size()){
            std :: __throw_invalid_argument("not a square matrix");
        }
        this->currentGraph=v;
        this->directed=(bool) isConnected();
    }

//printing the graph
    string Graph :: printGraph(){
        string h;
        for(size_t i=0;i<this->currentGraph.size();i++){
            for (size_t j=0;j<this->currentGraph[0].size();j++){
                if(j==0){
                    h+="["+ to_string( this->currentGraph[i][j]);  
                }
                else{
                    h+=", "+ to_string( this->currentGraph[i][j]);
                }
                if (j==this->currentGraph[0].size()-1){
                    h+="]";
                }
            }
            if(i!=this->currentGraph.size()-1){
            h+=",";}
        }
        return h;    
    }


//checking if the graph is connected
    bool Graph :: isConnected (){
        for(size_t i=0;i<this->currentGraph.size();i++){
            for (size_t j=0;j<this->currentGraph[0].size();j++){
                if(this->currentGraph[i][j] != this->currentGraph[j][i]){
                    return false;
                }
            }
        }
        return true;
    }

//getting the matrix of the graph
    std::vector<std::vector<int>> Graph :: getMatrix() const{
        return this->currentGraph;
    }

//getting the edges of the graph
    std::vector<std::pair<size_t, size_t>> Graph :: getEdges()  {
        std::vector<std::pair<size_t, size_t>> edges;
        size_t numVertices = this->currentGraph.size();
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                if (this->currentGraph[i][j] != 0) {
                    edges.push_back({i, j});
                }
            }
        }
        return edges;
    }

//adducting two matrices    
    Graph Graph::operator+(Graph& g1){
        if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
            std :: __throw_invalid_argument("matrices are not the same size");
        }
        size_t v = g1.getMatrix().size();
        std::vector<std::vector<int>> currentGraph;
        for(size_t b=0 ; b<v ; b++){
            vector<int> temp;
            for (size_t k=0 ;k<v; k++){
                temp.push_back(g1.getMatrix()[b][k]+ this->currentGraph[b][k]);
            }

        currentGraph.push_back(temp);
        }
        ariel::Graph g2;
        g2.loadGraph(currentGraph);
        return g2;
    }


    void Graph :: setMatrix(std::vector<std::vector<int>> o){
        this->currentGraph=o;
    }

//multiplication of two matrices
    Graph Graph::operator*( Graph& g1 ) {
        if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
            std :: __throw_invalid_argument("matrices are not the same size");
        }
        size_t v = g1.getMatrix().size();
        std::vector<std::vector<int>> currentGraph;
        for(size_t b=0 ; b<v ; b++){
            vector<int> temp;
            for (size_t k=0 ;k<v; k++){
                temp.push_back(this->currentGraph[b][k]*g1.getMatrix()[b][k]);
            }   
            currentGraph.push_back(temp);
        }
        ariel::Graph g2;
        g2.loadGraph(currentGraph);
        return g2;
        }

//division of two matrices
    Graph Graph::operator/(Graph& g1 ){
        if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
            std :: __throw_invalid_argument("matrices are not the same size");
            }
    size_t v =g1.getMatrix().size();
    std::vector<std::vector<int>> currentGraph;
    for(size_t b=0 ; b<v ; b++){
        vector<int> temp;
        for (size_t k=0 ;k<v; k++){
            temp.push_back(this->currentGraph[b][k]/g1.getMatrix()[b][k]);
        }

        currentGraph.push_back(temp);
    }
    ariel::Graph g4;
    g4.loadGraph(currentGraph);
    return g4;
}

//subtraction of two matrices
    Graph Graph::operator-(Graph& g1 ){
       if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
           std :: __throw_invalid_argument("matrices are not the same size");
           }
        size_t v =g1.getMatrix().size();
        std::vector<std::vector<int>> currentGraph;
        for(size_t b=0 ; b<v ; b++){
            vector<int> temp;
            for (size_t k=0 ;k<v; k++){
                temp.push_back(this->currentGraph[b][k]-g1.getMatrix()[b][k]);
            }

            currentGraph.push_back(temp);
        }
        ariel::Graph g4;
        g4.loadGraph(currentGraph);
        return g4;
    }


//unary operators
    Graph Graph ::operator+(){
        return *this;
    }

//unary operators
    Graph Graph::operator-(){
        Graph g0=*this;
        return g0*=(-1);
    }   


//postfix increment
    Graph Graph::operator++(int) {
        ariel::Graph g1;
        g1.loadGraph(this->currentGraph);
        Graph temp = g1;
        vector<vector<int>> v1;
        size_t graphSize = g1.getMatrix().size();
        for(vector<int>::size_type i = 0; i < graphSize; i++) {
            vector<int> v2;
            for(vector<int>::size_type j = 0; j < graphSize; j++) {
                 v2.push_back(1 + g1.getMatrix()[i][j]);
            }
            v1.push_back(v2);
        }

        g1.loadGraph(v1);
        return temp;
    }

//prefix increment
    Graph Graph::operator++() {
        vector<vector<int>> v1;
        size_t graphSize = this->currentGraph.size();
        for(vector<int>::size_type i = 0; i < graphSize; i++) {
            vector<int> v2;
            for(vector<int>::size_type j = 0; j < graphSize; j++) {
                 v2.push_back(1 + this->getMatrix()[i][j]);
            }
            v1.push_back(v2);
        }

        this->loadGraph(v1);
        return *this;
    }

//postfix decrement
    Graph Graph::operator--(int) {
        ariel::Graph g1;
        g1.loadGraph(this->currentGraph);
        Graph temp = g1;
        vector<vector<int>> v1;
        size_t graphSize = g1.getMatrix().size();
        for(vector<int>::size_type i = 0; i < graphSize; i++) {
            vector<int> v2;
            for(vector<int>::size_type j = 0; j < graphSize; j++) {
                 v2.push_back(g1.getMatrix()[i][j] - 1);
            }
            v1.push_back(v2);
        }

        g1.loadGraph(v1);
        return temp;
    }

//prefix decrement
    Graph Graph ::operator--() {
        vector<vector<int>> v1;
        size_t graphSize = this->currentGraph.size();
        for(vector<int>::size_type i = 0; i < graphSize; i++) {
            vector<int> v2;
            for(vector<int>::size_type j = 0; j < graphSize; j++) {
                 v2.push_back(this->getMatrix()[i][j] - 1);
            }
            v1.push_back(v2);
        }

        this->loadGraph(v1);
        return *this;
    }


//addition of two matrices with =
    Graph& Graph ::operator+=(Graph& g1){
        if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
            std :: __throw_invalid_argument("matrices are not the same size");
        }
        size_t v = g1.getMatrix().size();
        std::vector<std::vector<int>> currentGraph;
        for(size_t b=0 ; b<v ; b++){
            vector<int> temp;
            for (size_t k=0 ;k<v; k++){
                temp.push_back(g1.getMatrix()[b][k]+this->currentGraph[b][k]);
            }

            currentGraph.push_back(temp);
        }
        this->loadGraph(currentGraph);
        return *this;
    }
    

 //subtraction of two matrices with = 
    Graph& Graph ::operator-=(Graph& g1){
        if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
            std :: __throw_invalid_argument("matrices are not the same size");
        }
        size_t v =g1.getMatrix().size();
        std::vector<std::vector<int>> currentGraph;
        for(size_t b=0 ; b<v ; b++){
            vector<int> temp;
            for (size_t k=0 ;k<v; k++){
                temp.push_back(this->currentGraph[b][k]-g1.getMatrix()[b][k]);
            }
            currentGraph.push_back(temp);
        }
        this->loadGraph(currentGraph);
        return *this;
    }

//multiplication of a matrix with a scalar
    Graph& Graph ::operator*=(int n){
        for(size_t i=0;i<this->currentGraph.size();i++){
            for (size_t j=0;j<this->currentGraph[0].size();j++){
                this->currentGraph[i][j]*=n;
            }
        }
        return *this;
    }

//division of a matrix with a scalar
    Graph& Graph ::operator/=(int n){
        if(n==0){
            std :: __throw_invalid_argument("division by zero");
        }
        for(size_t i=0;i<this->currentGraph.size();i++){
            for (size_t j=0;j<this->currentGraph[0].size();j++){
                this->currentGraph[i][j]/=n;
            }
        }
        return *this;
    }


//comparison operator - equals to
    bool Graph ::operator==(Graph& g1){
        if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
            return false;
        }
        size_t v =g1.getMatrix().size();
        for(size_t b=0 ; b<v ; b++){
            for (size_t k=0 ;k<v; k++){
                if(g1.getMatrix()[b][k]!=this->currentGraph[b][k]){
                    return false;
                }
            }
        }
        return true;
    }


//comparison operator - does not equal to
    bool Graph ::operator!=(Graph& g1){
        if(this->currentGraph.size() != g1.getMatrix().size() || this->currentGraph[0].size() != g1.getMatrix()[0].size()){
            return true;
        }
        size_t v =g1.getMatrix().size();
        for(size_t b=0 ; b<v ; b++){
            for (size_t k=0 ;k<v; k++){
                if(g1.getMatrix()[b][k]!=this->currentGraph[b][k]){
                    return true;
                }
            }
        }
        return false;
    }



//is a matrix a submatrix of another matrix
    bool Graph :: isSubMatrix(Graph g1 , Graph g2) const{
        size_t v =g1.getMatrix().size();
        size_t v2 =g2.getMatrix().size();
        size_t min1=0;
        size_t max1=0;
        bool answer=false;
        if(v2>v){
            min1=v;
            max1=v2;
        }

        else{
            min1=v2;
            max1=v;
        }

        size_t until = max1-min1 ;
        for(size_t o=0;o<until+1;o++){//checking submatrix using 2 loops
            for(size_t x =0; x< until+1 ;x++){
                answer=true;
                for(size_t b=0 ; b<min1 ; b++){//comparisson loop
                    for (size_t k=0 ;k<min1; k++){
                        if(v2<v){
                            if(g1.getMatrix()[b+o][k+x]!=g2.getMatrix()[b][k]){
                                answer = false;
                                k=min1;
                            }
                        }
                        else{
                            if(g2.getMatrix()[b+o][k+x] !=g1.getMatrix()[b][k]){
                                answer = false;
                                k=min1;
                            }
                        }  
                    }
                }
                if(answer){
                    return true;
                }
            }
        
        }
        return answer;
    }


//comparison operator - greater than
    bool Graph ::operator>(Graph& g1) const{
        bool answer=true;
        Graph g0=*this;
        int sum1=0;
        int sum0=0;
        if(isSubMatrix(g0,g1)){
            if(g1.getMatrix().size()>g0.getMatrix().size()){
                return false;
            }
            return true;
        }
        if(g1.getMatrix().size() != g0.getMatrix().size() || g1.getMatrix()[0].size() != g0.getMatrix()[0].size()){
            answer = false; //if matrices are not the same size we can't compare them with certain rules
        }
        if(answer){   
            for (size_t i=0;i<g1.getMatrix().size();i++){
                for(size_t j=0;j<g1.getMatrix()[0].size();j++){
                    sum1+=g1.getMatrix()[i][j];
                    sum0+=g0.getMatrix()[i][j];
                    if(g1.getMatrix()[i][j]!=g0.getMatrix()[i][j]){
                        answer = false;
                    }    
                }
            }
            if(answer){//we have the same matrix
                return false;
            }
            if(sum1>sum0){
                return false;
            }
            else{
                return true;
            }
        }

        for (size_t i=0;i<g1.getMatrix().size();i++){//comparison of different sized matrices
            for(size_t j=0;j<g1.getMatrix()[0].size();j++){
                sum1+=g1.getMatrix()[i][j];
            }
        }
        for (size_t i=0;i<g0.getMatrix().size();i++){
            for(size_t j=0;j<g0.getMatrix()[0].size();j++){
                sum0+=g0.getMatrix()[i][j];
            }
        }
        if(sum1>sum0){//sum based comparison
            return false;
        }
        else{
            return true;
        }
        if(g1.getMatrix().size()>g0.getMatrix().size()){// the last term 
            return false;
        }
        return true;
    }

//comparison operator - less than
    bool Graph::operator<(Graph& g1){
        bool ans = g1>*this;
        return ans;
    }

//is greater or equal to    
    bool Graph::operator>=(Graph& g1){
        bool ans = g1<*this;
        bool ans2 = g1==*this;
        return ans || ans2;
    }

//is less or equal to    
    bool Graph::operator<=(Graph& g1){
        bool ans = g1>*this;
        bool ans2 = g1==*this;
        return ans || ans2;
    }


//output operator
    std::ostream& operator<<(std::ostream& os,Graph& g) {
        std::vector<std::vector<int>> vec = g.getMatrix();
        for(unsigned long i = 0; i < vec.size(); i++) {
            for(unsigned long j = 0; j < vec.size(); j++) {
                os << vec[i][j] << " ";
            }
            os << std::endl;
            }
        return os;
    }




