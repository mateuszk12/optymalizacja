#include <iostream>
#include <vector>
#include <bits/stdc++.h>

std::vector<std::vector<int>> createGraph(int v)
{
    std::vector<int> row(v,0);
    std::vector<std::vector<int>> matrix(v,row);
    return matrix;
};
void showMatrix(std::vector<std::vector<int>> &matrix)
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
void removeVertex(std::vector<std::vector<int>> &m, int num)
{
    if (num > m.size())
    {
            printf("nie ma takiego wierzcholka\n");
    }
    else
    {
        m.erase(m.begin()+num-1);
    }
}
void addVertex(std::vector<std::vector<int>> &m)
{
    for (int i = 0; i<m.size();i++)
    {
        m[i].push_back(0);
    }
    unsigned int len = m[0].size();
    std::vector<int> row(len,0);
    m.push_back(row);
}
void addEdge(std::vector<std::vector<int>> &m, int s,int e)
{
    m[s][e] = 1;
    m[e][s] = 1;
}
void removeEdge(std::vector<std::vector<int>> &m, int s,int e)
{
    if (e < m.size() || s < m.size())
    {
        m[e][s] = 0;
        m[s][e] = 0;
    }

}
int degreeV(std::vector<std::vector<int>> &m,int num)
{
    int degree = 0;
    for (int i = 0;i<m[num].size();i++)
    {
        if (m[num][i] == 1)
        {
            degree += 1;
        }
    }
    return degree;
}
void showDegree(std::vector<std::vector<int>> &m,int num)
{
    std::cout << degreeV(m,num) << std::endl;
}
void maxDegree(std::vector<std::vector<int>> &m)
{
    int max = 0;
    for (int i = 0; i < m.size(); i++)
    {
        int vDegree = degreeV(m,i);
                if (vDegree > max)
                {
                    max = vDegree;
                }
    }
   std::cout << max <<std::endl;
}

void minDegree(std::vector<std::vector<int>> &m)
{
    int min = degreeV(m,0);
    for (int i = 0; i < m.size(); i++)
    {
        int vDegree = degreeV(m,i);
        if (vDegree < min)
        {
            min = vDegree;
        }
    }
    std::cout <<min<<std::endl;
}
void even(std::vector<std::vector<int>> &m)
{
    int num = 0;
    for (int i = 0; i < m.size(); i++)
    {
        int vDegree = degreeV(m,i);
        if (vDegree % 2 == 0)
        {
            num += 1;
        }
    }
    std::cout << num <<std::endl;
}
void odd(std::vector<std::vector<int>> &m)
{
    int num = 0;
    for (int i = 0; i < m.size(); i++)
    {
        int vDegree = degreeV(m,i);
        if (vDegree % 2 == 1)
        {
            num += 1;
        }
    }
    std::cout << num << std::endl;
}

void sequence(std::vector<std::vector<int>> &m)
{
     std::vector<int> verticies(m.size());
    for (int i = 0; i < m.size(); i++)
     {
        int deg = degreeV(m,i);
        verticies[i] = deg;
     }
    std::sort(verticies.begin(),verticies.end(),std::greater<>());
    for (auto j : verticies)
    {
        std::cout << j << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<std::vector<int>> matrix = createGraph(4);
    addVertex(matrix);
    addEdge(matrix,0,4);
    addEdge(matrix,0,2);
    addEdge(matrix,0,3);
    addEdge(matrix,0,1);
    addEdge(matrix,0,0);
    removeVertex(matrix,0);
    showMatrix(matrix);
    removeEdge(matrix,0,1);
    showMatrix(matrix);
    showDegree(matrix,2);
    minDegree(matrix);
    maxDegree(matrix);
    even(matrix);
    odd(matrix);
    sequence(matrix);
    showMatrix(matrix);
    return 0;
}
