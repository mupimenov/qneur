#ifndef __STATE_H__
#define __STATE_H__

#include "../../qgraph/src/Vertex.h"

namespace neurnet
{
struct State
{
    const graph::Vertex* v;
    double value;

    bool operator<(const State& s) const
    {
        return (v < s.v);
    };
    bool operator==(const State& s) const
    {
        return (v == s.v); 
    };
};
}
#endif // __STATE_H__
