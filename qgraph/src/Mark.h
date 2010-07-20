#ifndef MARK_H_INCLUDED
#define MARK_H_INCLUDED

#include "Vertex.h"
#include "Attribute.h"

namespace graph
{
struct Mark
{
    const Vertex* v;
    const Attribute* a;
    double value;
    
    bool operator<(const Mark& m) const
    {
        const Vertex* mv = m.v;
        return (*v < *mv);
    };
    bool operator==(const Mark& m) const
    {
        return ((v == m.v) && (a == m.a));
    };
};
}
#endif // MARK_H_INCLUDED
