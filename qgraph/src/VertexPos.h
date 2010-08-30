#ifndef VERTEXPOS_H_INCLUDED
#define VERTEXPOS_H_INCLUDED

#include "Vertex.h"
#include "Edge.h"

namespace graph
{
struct VertexPos
{
    const Vertex* v;
    const Edge* e;
    unsigned int pos;
    
    bool operator<(const VertexPos& vp) const
    {
        const Vertex* vpv = vp.v;
        return (*v < *vpv);
    };
    bool operator==(const VertexPos& vp) const
    {
        return ((v == vp.v) && (e == vp.e));
    };
};
}
#endif // VERTEXPOS_H_INCLUDED
