#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class graph_dfs{
private:
   unsigned int members_graph;
   unsigned int **matr_graph;
public:
    
    graph_dfs(){
        members_graph = 0;
        matr_graph = nullptr;
    }
    
    
    
    unsigned int **Get_matr_graph () const {
        return matr_graph;
    }
    
    unsigned int Get_members_graph () const {
        return members_graph;
    }
    
    graph_dfs(unsigned int number){
        members_graph = number;
        matr_graph = new unsigned int *[members_graph];
        for (std::size_t i = 0; i<members_graph; i++) {
            matr_graph[i]=new unsigned int [members_graph];
        }
    }
    
    ~graph_dfs(){
        for (std::size_t i = 0; i<members_graph; i++) {
            delete [] matr_graph[i];
        }
        delete [] matr_graph;
    }
    
    void read(std::istringstream& stream){
        for (std::size_t i = 0; i<members_graph; i++) {
            for (std::size_t j = 0; j<members_graph; j++) {
                int m ;
                stream>>m;
                if (i == j && m != 0) {
                    throw "item cannot be linked to itself";
                }
                if (m == 1 | m == 0 ) {
                    matr_graph[i][j] = m;
                }
                else throw "incorrect input format";
            }
        }
    }
    
    void write_result (std::vector<unsigned int> result , std::ostringstream& stream) const
    {
        copy(result.begin(),result.end(),std::ostream_iterator<unsigned int> (stream," "));
    }
    
    void dfs(unsigned int index,std::vector<unsigned int> &list,std::vector<unsigned int> &result) const
    {
        list[index]=1;
        result.push_back(index+1);
        for(unsigned int i = 0;i<members_graph;i++){
            if (matr_graph[index][i] == 1) {
                if (list[i] == 0) {
                    dfs(i, list, result);
                }
            }
        }
    }
    
    std::vector <unsigned int> DFS(unsigned int index) const
    {
        index=index-1;
        std::vector<unsigned int> list (members_graph);
        std::vector<unsigned int> result;
        dfs(index,list,result);
        return result;
    }
    
};


