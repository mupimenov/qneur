#ifndef HGRAPHTEST_H
#define HGRAPHTEST_H

#include <set>
#include "../../qgraph/src/HGraph.h"

namespace graph_test
{
class HGraphTest
{
public:
    HGraphTest();
    virtual ~HGraphTest();
    int runTest();
protected:
private:    
    graph::HGraph* fillRectangle(graph::HGraph* g, int width, int height);
    graph::HGraph* fillRandomEdges(graph::HGraph* g, int width, int height, int count);
};
}
#endif // HGRAPHTEST_H
