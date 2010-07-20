#ifndef __SYNAPSE_H__
#define __SYNAPSE_H__

#include "../../qgraph/src/Vertex.h"
namespace neurnet
{
struct Synapse {
    const graph::Vertex* v;
    double weight;
    
    bool operator<(const Synapse& s) const
    {
        return (weight < s.weight);
    };
    bool operator==(const Synapse& s) const
    {
        return ((v == s.v) && (weight == s.weight));
    };
};
}
#endif // __SYNAPSE_H__
