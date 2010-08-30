/*
 * =====================================================================================
 *
 *       Filename:  Cluster.h
 *
 *    Description:  cluster is a set of synapses for current vertex
 *
 *        Version:  1.0
 *        Created:  11.08.2010 15:48:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mikhail Pimenov (), mupimenov@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <set>
#include "Synapse.h"
#include "State.h"
#include "../../qgraph/src/Vertex.h"
namespace neurnet
{
struct Cluster
{
    const graph::Vertex* v;
    std::set<Synapse> synapses;


    bool operator<(const Cluster& c) const
    {
        return (v < c.v);
    };
    bool operator==(const Cluster& c) const
    {
        return (v == c.v); 
    };

    double smult(Cluster& c, std::set<State> so_s);

};
}
