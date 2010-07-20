#ifndef __WEIGHTS_H__
#define __WEIGHTS_H__

#include <set>
#include "../../qgraph/src/Vertex.h"
namespace neurnet
{
struct Weights {
    const graph::Vertex* v;
    std::set<Synapse> synapses;
    
    bool operator<(const Weights& w) const
    {
        return (v < w.v);
    };
    bool operator==(const Weights& w) const
    {
        return (v == w.v);
    };
};
}
#endif // __WEIGHTS_H__
