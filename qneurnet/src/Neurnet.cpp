#include "Neurnet.h"

namespace neurnet
{

Neurnet::Neurnet()
{
    graph = new graph::HGraph();
    weights = new std::set<Weights>();
}

Neurnet::~Neurnet()
{
    delete graph;
    delete weights;
}

}