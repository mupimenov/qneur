#ifndef NEURNET_H
#define NEURNET_H

#include <set>
#include "../../qgraph/src/HGraph.h"

#include "State.h"
#include "Synapse.h"
#include "Weights.h"

namespace neurnet
{
class Neurnet
{
    public:
        Neurnet();
        virtual ~Neurnet();
        std::set<State> compute(const std::set<State> input);
        std::set<State> error(const std::set<State> input, const std::set<State> output);
    protected:
    private:
        graph::HGraph* graph;
        std::set<Weights>* weights;
};
}
#endif // NEURNET_H

