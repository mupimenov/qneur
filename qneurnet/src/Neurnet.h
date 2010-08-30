#ifndef NEURNET_H
#define NEURNET_H

#include <string>
#include <set>
#include <vector>
#include "../../qgraph/src/HGraph.h"

#include "State.h"
#include "Synapse.h"
#include "Cluster.h"

namespace neurnet
{

using std::string;
using std::set;
using std::vector;
using graph::Attribute;
using graph::Edge;
using graph::HGraph;
using graph::Mark;
using graph::Vertex;
using graph::VertexPos;

    typedef std::set<State> States;
    typedef std::vector<const graph::Vertex*> Order;
    typedef std::set<const graph::Vertex*> FuzzyOrder;
    typedef std::set<Cluster> Clusters;
    typedef std::set<Synapse> Synapses;
    typedef std::string name;

class Neurnet
{
     public:
  

        Neurnet();
        Neurnet(int inputCount, int hiddenCount, int outputCount);
        virtual ~Neurnet();
        /* compute */
        States compute(const States& input);
        /* end compute */
        States error(const States& input, const States& output);
        /* teaching */
        int qteach(const States& input, const States& output);
        /* end teaching */
        
    protected:
        int fVertices(const graph::Vertex* v, const graph::Attribute* a);
    private:
        /* for constructor */
        Order createLayer(int start, int count, name& attrName);
        const Order& linkLayers(const Order& va, const Order& vb);
        
        FuzzyOrder getLayer(name& attrName);
        FuzzyOrder getLayerAfter(FuzzyOrder& vs);
        /* end for constructor */

        /* prepareing net */
        Order* getOrder();
        States getState(const Order* ord, const States& input);
        States getState(const FuzzyOrder& ord);
        Clusters* getClusters(const Order* ord);
        int prepareTheNet();
        /* end prepareing net */

        /* computing */
        double justOutput(const Cluster& c, const States& vars);
        
        double error(const States& input, const States& output, const Clusters* c);
        States compute(const States& input, const Clusters& c);
        /* end computing */

        /* teaching */
        void adjustSynapse(const Cluster& c, const Synapse& s, const States& input, const States& output);

        /* end teaching */

        /* vars */
        HGraph* graph;
        Clusters* clusters;
        Order* order;

        /* end vars */
};
}
#endif // NEURNET_H

