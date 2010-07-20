#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include <set>
#include "Vertex.h"

namespace graph
{
struct Edge
{
    std::set<const Vertex*> vertices;
    
    bool operator<(const Edge& e) const
    {
        return (vertices.size() < e.vertices.size());
    };
    bool operator==(const Edge& e) const
    {
        bool r = true;
        if (vertices.size() == e.vertices.size())
        {
            for (std::set<const Vertex*>::iterator it = vertices.begin(); it != vertices.end(); it++)
            {
                if (e.vertices.find(*it) == e.vertices.end())
                {
                    r = false;
                    break;
                }
            }
        } 
        else 
        {
            r = false;
        }
        return r;
    };
};
}

#endif // EDGE_H_INCLUDED
