#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <string>

namespace graph
{
struct  Vertex
{
    const std::string name;
    
    bool operator<(const Vertex& v) const
    {
        return (name < v.name);
    };
    bool operator==(const Vertex& v) const
    {
        return (name == v.name);
    };
};
}
#endif // VERTEX_H_INCLUDED
