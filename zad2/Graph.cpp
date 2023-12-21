
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <csignal>
#include <queue>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/maximum_weighted_matching.hpp>
#include "Graph.h"

Graph::Graph(int vertecies):vert(vertecies)
    {
        std::vector<int> row(vert,0);
        std::vector<std::vector<int>> mat(vert,row);
        std::vector<std::vector<int>> weights(vert,row);
        std::vector<std::vector<int>> Doubleweights;
        this -> matrix = mat;
    }

    void Graph::showMatrix()
    {
        for (const auto&  i : matrix)
        {
            for (int j : i)
            {
                std::cout << j <<"\t";
            }
            std::cout << std::endl;
        }
    }

    void Graph::removeVertex(int num)
    {
        if (num > matrix.size())
        {
            printf("nie ma takiego wierzcholka\n");
        }
        else
        {
            matrix.erase(matrix.begin()+num-1);
        }
    }

    void Graph::addVertex()
    {
        for (int i = 0; i<matrix.size();i++)
        {
            matrix[i].push_back(0);
        }
        unsigned int len = matrix[0].size();
        std::vector<int> row(len,0);
        matrix.push_back(row);
    }

    void Graph::addEdge(int s, int e)
    {
        matrix[s][e] = 1;
        matrix[e][s] = 1;
    }
    std::vector<std::vector<int>> Graph::findEdges(std::vector<int> ed)
    {
        std::vector<std::vector<int>> edges;
        for (auto i : ed)
        {
            for (auto j : ed)
            {
                for (auto k : weights)
                {
                        if (k[1] == i && k[2] == j)
                        {
                            edges.push_back(k);
                        }
                }
            }
        }
        return edges;
    }
    int Graph::numEdges()
    {
        int count = 0;
        for (int i = 0; i < matrix.size();i++)
        {
            for (int j = 0; j < matrix.size();j++)
            {
                    if (matrix[i][j] == 1)
                    {
                        count++;
                    }

            }
        }
        return count/2;
    }
    std::vector<std::vector<int>> Graph::getWeights()
    {
        return weights;
    }
    void Graph::addWeight(int s, int e, int w)
    {
        bool exists = false;
        for (auto i : weights)
        {
            if (i[1] == e && i[2] == s || i[1] == s && i[2] == e)
            {
                exists = true;
                std::cout << "can't add weight";
                break;
            }
        }
        if (s >= 0 && s < matrix.size() && e >= 0 && e < matrix.size() && !exists)
        {
            if (e > s)
            {
                weights.push_back({w,e,s});
            }
            else
            {
                weights.push_back({w,s,e});
            }

        } else
        {
            printf("wrong index\n");
        }
    }
    void Graph::addDoubleEdges(int s, int e, int w)
    {
        if (s >= 0 && s < matrix.size() && e >= 0 && e < matrix.size())
        {
            if (e > s)
            {
                weights.push_back({w,e,s});
            }
            else
            {
                weights.push_back({w,s,e});
            }

        }
    }
    void Graph::sortWeights()
    {
        std::sort(weights.begin(), weights.end(), [](const std::vector<int>& a, const std::vector<int>& b){
            return a[0] < b[0];
        });
    }

    void Graph::displayWeights()
    {
        for (auto i : weights)
        {
            std::cout << i[0] << " " << i[1] << " " << i[2] << std::endl;
        }
    }
    int Graph::getWeight(int a, int b)
    {
        int max = a;
        int min = b;
        int weight = 0;
        if (a < b)
        {
            max = b;
            min = a;
        }
        for (auto i : weights)
        {
            if (i[1] == max && i[2] == min)
            {
                weight = i[0];
            }
        }
        return weight;
    }
    int Graph::getMaxWeight()
    {
        int max = 0;
        for(auto i : weights)
        {
            if (i[0] > max)
            {
                max = i[0];
            }
        }
        return max;
    }
    void Graph::removeEdge(int s, int e)
    {
        matrix[e][s] = 0;
        matrix[s][e] = 0;
    }

    int Graph::degreeV(int num)
    {
        int degree = 0;
        for (int i = 0;i<matrix[num].size();i++)
        {
            if (matrix[num][i] == 1)
            {
                degree += 1;
            }
        }
        return degree;
    }

    void Graph::showDegree(int num)
    {
        std::cout << degreeV(num) << std::endl;
    }

    void Graph::maxDegree()
    {
        int max = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int vDegree = degreeV(i);
            if (vDegree > max)
            {
                max = vDegree;
            }
        }
        std::cout << max <<std::endl;
    }

    void Graph::minDegree()
    {
        int min = degreeV(0);
        for (int i = 0; i < matrix.size(); i++)
        {
            int vDegree = degreeV(i);
            if (vDegree < min)
            {
                min = vDegree;
            }
        }
        std::cout <<min<<std::endl;
    }

    int Graph::numEven()
    {
        int num = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int vDegree = degreeV(i);
            if (vDegree % 2 == 0)
            {
                num += 1;
            }
        }
        return num;
    }

    int Graph::numOdd()
    {
        int num = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int vDegree = degreeV(i);
            if (vDegree % 2 == 1)
            {
                num += 1;
            }
        }
        return num;
    }

    void Graph::sequence()
    {
        std::vector<int> ver(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
        {
            int deg = degreeV(i);
            ver[i] = deg;
        }
        std::sort(ver.begin(), ver.end(), std::greater<>());
        for (auto j : ver)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

std::vector<std::vector<int>> Graph::multiplyMatrices()
{
    std::vector<int> row(vert,0);
    std::vector<std::vector<int>>  resultMatrix(vert,row);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            for (int k = 0; k < resultMatrix.size(); k++) {
                resultMatrix[i][j] += matrix[i][k] * matrix[k][j];
            }
            std::cout << resultMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return resultMatrix;
}

void Graph::findCycle3naive()
{
    int numberOfCycles = 0;
    for(int i = 0;i < matrix.size();i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 1)
            {
                for (int k = 0; k < matrix[j].size(); k++)
                {
                    if (matrix[k][i] == 1 && matrix[j][k] == 1)
                    {
                        numberOfCycles +=1;
                    }
                }
            }
        }
    }
    if (numberOfCycles == 0)
    {
        std::cout << "didn't found any C3 cycle" << std::endl;
    }
    else
    {
        std::cout << "graph contains cycle" << std::endl;
    }
}

void Graph::findCycle3fancy()
{
    std::vector<std::vector<int>> multipliedMatrix = multiplyMatrices();
    std::vector<int> cycleVertices;
    int number = 0;
    for (int i = 0; i < multipliedMatrix.size(); i++)
    {
        if (multipliedMatrix[i][i] > 1)
        {
            for(int j = 0; j < multipliedMatrix.size();j++)
            {
                if (matrix[i][j] == 1)
                {
                    for (int k = 0; k < matrix.size();k++)
                    {
                            if (matrix[j][k] ==  1 && matrix[k][i] == 1)
                            {
                                if (std::find(cycleVertices.begin(), cycleVertices.end(),i)==cycleVertices.end())
                                {
                                    cycleVertices.push_back(i);
                                }
                                if (std::find(cycleVertices.begin(), cycleVertices.end(),j)==cycleVertices.end())
                                {
                                    cycleVertices.push_back(j);
                                }
                                if (std::find(cycleVertices.begin(), cycleVertices.end(),k)==cycleVertices.end())
                                {
                                    cycleVertices.push_back(k);
                                }
                            }
                    }
                }

            }
        }
    }
    if (cycleVertices.size() > 0)
    {
        std::cout << "got "<<" cycles" <<std::endl;
        for (auto i : cycleVertices)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

}

std::vector<std::vector<int>> Graph::dfs(int vert=0)
{
    std::vector<int> stack(1,vert);
    std::vector<bool> visited(matrix.size(),false);
    std::vector<std::vector<int>> spanningTree;
    int i = stack.back();
    while(!stack.empty())
    {
        visited[i] = true;
        i = stack.back();
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 1 && !visited[j])
            {
                stack.push_back(j);
                spanningTree.push_back({i,j});
                break;
            } else if (j == matrix.size()-1)
            {
                stack.pop_back();
            }
        }
    }
    return spanningTree;
}
std::vector<std::vector<int>> Graph::dfs(std::vector<std::vector<int>> graph,int vert=0)
{
    std::vector<int> stack(1,vert);
    std::vector<bool> visited(graph.size(),false);
    std::vector<std::vector<int>> spanningTree;
    int i = stack.back();
    while(!stack.empty())
    {
        visited[i] = true;
        i = stack.back();
        for (int j = 0; j < graph.size(); j++)
        {
            if (graph[i][j] == 1 && !visited[j])
            {
                stack.push_back(j);
                spanningTree.push_back({i,j});
                break;
            } else if (j == graph.size()-1)
            {
                stack.pop_back();
            }
        }
    }
    return spanningTree;
}
void Graph::drawSpanningTree(int vert=0)
{
    std::vector<std::vector<int>> tree = this->dfs(vert);
    for (int i = 0; i < tree.size();i++)
    {
        std::cout<<tree[i][0]<<tree[i][1]<<std::endl;
    }
}
void Graph::findCycleDfs(int vert)
{
    std::vector<int> stack(1,vert);
    std::vector<bool> visited(matrix.size(),false);
    std::vector<std::vector<int>> spanningTree;
    int i = stack.back();
    while(!stack.empty())
    {

        visited[i] = true;
        i = stack.back();
        for (int j = 0; j < matrix.size(); j++)
        {
            bool ex = false;
            std::vector<int> cos = {j,i};
            for (auto k : spanningTree)
            {
                if (cos==k)
                {
                    ex = true;
                }
            }

            if (matrix[i][j] == 1 && visited[j] && ex)
            {
                std::cout << j << std::endl;
            }
            if (matrix[i][j] == 1 && !visited[j])
            {
                stack.push_back(j);
                spanningTree.push_back({i,j});
                break;
            }

            else if (j == matrix.size()-1)
            {
                stack.pop_back();
            }

        }
    }
    for (int i = 0; i < spanningTree.size();i++)
    {
        std::cout<<spanningTree[i][0]<<spanningTree[i][1]<<std::endl;
    }
}
std::vector<std::vector<int>> Graph::kruskalMST()
{
    std::vector<std::vector<int>> minimalSpanningTree;
    std::vector<std::vector<int>> sets;
    this->sortWeights();
    sets.reserve(matrix.size());
    for (int i = 0; i < matrix.size();i++)
    {
        sets.push_back({i});
    }
    for (auto edge : weights)
    {
        int s = edge[1];
        int e = edge[2];
        int sx;
        int ex;
        for (int j = 0;j<sets.size();j++)
        {
            if (std::find(sets[j].begin(),sets[j].end(),s) != sets[j].end())
            {
                sx = j;
            }
            if (std::find(sets[j].begin(),sets[j].end(),e) != sets[j].end())
            {
                ex = j;
            }
        }
        if (ex != sx)
        {
            sets[ex].insert(sets[ex].end(),sets[sx].begin(),sets[sx].end());
            sets[sx].clear();
            minimalSpanningTree.push_back({edge[0],s,e});
        }

    }
    int sum = 0;
    for (auto data : minimalSpanningTree)

    {
        sum += data[0];
        std::cout<<"weight: "<<data[0]<<" edge: "<<data[1]<<data[2]<<std::endl;
    }
    std::cout<<"sum: "<< sum << std::endl;
    return minimalSpanningTree;
}

std::vector<int> Graph::countDegrees() {
    std::vector<int> degrees;
    for (int i = 0; i < matrix.size(); i++) {
        degrees.push_back(degreeV(i));
    }
    return degrees;
}
int Graph::weightsSum()
{
    int sum = 0;
    for (auto i: weights)
    {
        sum += i[0];
    }
    return sum;
}
bool Graph::isEulerinan()
{
    bool onlyEvenDegrees = true;
    bool isConnected = true;
    if (this->numOdd() != 0)
    {
        onlyEvenDegrees = false;
    }
    if (this->dfs().size()+1 != matrix.size())
    {
        isConnected = false;
    }
    return onlyEvenDegrees && isConnected;
}
bool Graph::isSemiEulerian()
{
    bool semiEulerDegrees = true;
    bool isConnected = true;
    if (this->numOdd() != 2)
    {
        semiEulerDegrees = false;
    }
    if (this->dfs().size()+1 != matrix.size())
    {
        isConnected = false;
    }
    return semiEulerDegrees && isConnected;
}
std::vector<int> Graph::getOdd()
{
    std::vector<int> vecs;
    for (int i = 0; i < matrix.size();i++)
    {
        if(this->degreeV(i) % 2 != 0)
        {
            vecs.push_back(i);
        }

    }
    return vecs;
}
std::vector<int> Graph::getNeighbours(int i)
{
    std::vector<int> neigh;
    for (int j = 0; j < matrix[i].size();j++)
    {
        if (matrix[i][j]==1)
        {
            neigh.push_back(j);
        }
    }
    return neigh;
}
int Graph::getMin(std::vector<int> from,std::vector<int> to,int start)
{
    int min = std::numeric_limits<int>::max();
    int index = 0;
    for (auto i : from)
    {
        if (to[i] < min)
        {
            min = to[i];
            index = i;
        }
    }
    return index;
}
std::vector<std::vector<int>> Graph::dijkstra(int a)
{
    int maxWeight = this->weightsSum()+1;
    std::vector<int> cost(matrix.size(),maxWeight);
    std::vector<int> p(matrix.size(),-1);
    cost[a] = 0;
    std::vector<int>Q;
    Q.reserve(matrix.size());
for (int i = 0;i<matrix.size();i++)
    {
        Q.push_back(i);
    }
    int index=a;
    std::vector<int> n = this->getNeighbours(index);
    while(!Q.empty())
    {
            Q.erase(Q.begin()+index);
            for(auto j : n)
            {
                if (std::find(Q.begin(),Q.end(),j) != Q.end())
                {
                    if (cost[j] > (cost[index]+this->getWeight(index,j)))
                    {
                        cost[j] = cost[index]+this->getWeight(index,j);
                        p[j] = index;
                    }
                }
            }
        index = getMin(Q,cost,index);
        n = this->getNeighbours(index);
    }
    return {cost,p};
}
int Graph::minDistance(int a, int b)
{
   return this->dijkstra(a)[0][b];
}
std::vector<int> Graph::getDijkstraPath(int a, int b)
{
    std::vector<int> path;
    std::vector<int> dijkstra = this->dijkstra(a)[1];
    int index = b;
    while(index != -1)
    {
        path.push_back(index);
        index = dijkstra[index];

    }
    return path;
}
bool Graph::isBridge(int a,int b)
{
    if (matrix[a][b] == 0)
    {
        return false;
    }
    std::vector<std::vector<int>> check = this->matrix;
    check[a][b] = 0;
    check[b][a] = 0;
    auto tree = this->dfs(check,a);
    auto tree2 = this->dfs(a);
    return tree.size() != tree2.size();
}
std::vector<int> Graph::fleurAlgorithm(int vert)
{
    std::vector<int> stack;
    std::vector<std::vector<int>> copy = matrix;
    int run = true;
    int j = vert;
    stack.push_back(j);
    while(run)
    {
        for(int i = 0;i<copy.size();i++)
        {
            if (copy[j][i]==1)
            {
                if (!isBridge(j,i))
                {
                    copy[i][j] = 0;
                    copy[j][i] = 0;
                    j = i;
                    break;
                }
                else
                {
                    copy[i][j] = 0;
                    copy[j][i] = 0;
                    j = i;
                    break;
                }
            }


        }
        if (std::find(copy[j].begin(),copy[j].end(),1) == copy[j].end())
        {
            run = false;
        }
        stack.push_back(j);
    }
    return stack;

}

std::vector<std::vector<int>> Graph::getMinimalWeightMatch()
{
    std::vector<std::vector<int>> result;
    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
            boost::no_property, boost::property<boost::edge_weight_t, int>> Graph;

    Graph G;
    int maxWeight = this->getMaxWeight();
    for (auto i : weights)
    {
        add_edge(i[1], i[2], maxWeight-i[0], G);
    }
    int n_vertices = 4;
    std::vector< boost::graph_traits< Graph >::vertex_descriptor > mate1(
            n_vertices);
    boost::maximum_weighted_matching(G,&mate1[0]);
    boost::graph_traits<Graph>::edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = boost::edges(G); ei != ei_end; ++ei) {
        auto source = boost::source(*ei, G);
        auto target = boost::target(*ei, G);
        if (mate1[source] == target || mate1[target] == source) {
           result.push_back({maxWeight-boost::get(boost::edge_weight, G, *ei),static_cast<int>(source),static_cast<int>(target)});
        }
    }
    return result;
}
std::vector<std::vector<int>> Graph::findCPP()
{

    if(this->isEulerinan())
    {
        std::vector<std::vector<int>> path;
        path = {{},{}};
        std::vector<int> pfl = fleurAlgorithm(0);
        for (int i=0;i<pfl.size();i++)
        {
            printf("%d\n",pfl[i]);
            path[0].push_back(pfl[i]);
        }
        path[1] = {this->weightsSum()};
        printf("eulerian sum of weights: %d\n",path[1][0]);
        return path;
    }
    else if(this->isSemiEulerian())
    {
        auto vecs = this->getOdd();
        auto pathEu = this->fleurAlgorithm(vecs[1]);
        auto pathDij = this->getDijkstraPath(vecs[1],vecs[0]);
        std::vector<std::vector<int>> pathH;
        for (int i=0;i<pathEu.size();i++)
        {
            if (i < pathEu.size()-1)
            {
                pathH.push_back({pathEu[i],pathEu[i+1]});
                printf("%d\n",pathEu[i]);
            }
        }
        for (int i=0;i<pathDij.size();i++)
        {
            if (i < pathEu.size()-1)
            {
                pathH.push_back({pathDij[i],pathDij[i+1]});
            }
        }
        int sum = 0;
        for (auto i : pathH)
        {
            printf("%d %d\n",i[0],i[1]);
            sum += this->getWeight(i[0],i[1]);
        }
        printf("sum of weights: %d\n",sum);
        pathH.push_back({sum});
        return pathH;
    }
    else
    {

        auto oddVert = this->getOdd();
        Graph g = Graph(oddVert.size());
        int numEd = oddVert.size()-1;
        for (auto i : oddVert)
        {
            for(auto j : oddVert)
            {
                if (i != j)
                {
                    g.addEdge(i,j);
                    g.addDoubleEdges(i,j, minDistance(i,j));
                }
            }
        }
        auto minMatched = g.getMinimalWeightMatch();
    }
}
bool Graph::triangle()
{
    bool test = true;
    for (int i = 0; i < this->matrix.size();i++)
    {
        for (int j = 0; j < this->matrix.size();j++)
        {
            for (int k = 0; k < this->matrix.size();k++)
            {
                if ((getWeight(i,j) + getWeight(i,k)) < getWeight(k,j) && i != j && i != k && j!=k)
                {
                    test = false;
                }
            }
        }
    }
    return test;
}
std::vector<int> Graph::christofides()
{
    if (!this->triangle())
    {
        printf("graph edge weights don't obey triangle inequality\n");
        return {};
    }
    std::vector<std::vector<int>> mdr = this->kruskalMST();
    Graph minD = Graph(mdr.size()+1);
    for (auto i : mdr)
    {
        minD.addEdge(i[1],i[2]);
        minD.addWeight(i[1],i[2],i[0]);
    }
    std::vector<int> oddVer = minD.getOdd();
    std::vector<std::vector<int>> Oddedges = this->findEdges(oddVer);
    Graph min = Graph(mdr.size()+1);
    for (auto i : Oddedges)
    {
        min.addEdge(i[1],i[2]);
        min.addWeight(i[1],i[2],i[0]);
    }
    Graph euler = Graph(mdr.size()+1);
    for (auto i : min.getMinimalWeightMatch())
    {

        euler.addEdge(i[1],i[2]);
        euler.addWeight(i[1],i[2],i[0]);
    }
    for (auto i : mdr)
    {

        euler.addEdge(i[1],i[2]);
        euler.addWeight(i[1],i[2],i[0]);
    }
    printf("-----------------\n");
    std::vector<int> path;
    std::vector<std::vector<int>> eulerC = euler.findCPP();
    for (auto i : eulerC[0])
    {
        if (std::find(path.begin(),path.end(),i) == path.end())
        {
            path.push_back(i);
        }
    }
    return path;
}