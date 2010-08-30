#ifndef HGRAPH_H
#define HGRAPH_H

#include <set>
#include <vector>

#include "Vertex.h"
#include "Edge.h"
#include "Attribute.h"
#include "Mark.h"
#include "VertexPos.h"

namespace graph
{


class HGraph
{
public:

    typedef const Vertex* (HGraph::*filterAdjacentVertices)(const Vertex*, const Edge*);

    /*constructors*/
    HGraph();    
    /*destructor*/
    virtual ~HGraph();
    /*vertex methods*/
    const Vertex* createVertex(const std::string& name);
    const Vertex* createVertexAfterVertex(const Vertex* v, const std::string& name);
    const Vertex* createVertexAfterVertexInEdge(const Vertex* v, Edge* e, const std::string& name);
    int removeVertex(Vertex* v);
    int linkVertices(const Vertex* a, const Vertex* b);
    const Vertex* getVertex(const std::string& name);
    int countVertices();
    int vertexPositionInEdge(const Vertex* v, const Edge* e);
    
    std::set<const Edge*> incidentEdges(const Vertex* v);
    const Vertex* nextVertexAfterVertexInEdge(const Vertex* v, const Edge* e);
    const Vertex* prevVertexBeforeVertexInEdge(const Vertex* v, const Edge* e);
    std::set<const Vertex*> nextAdjacentVertices(const Vertex* v);
    std::set<const Vertex*> prevAdjacentVertices(const Vertex* v);
    
    /*attribute and mark methods*/
    const Attribute* getAttribute(const std::string& name);
    const Vertex* markVertex(const Vertex* v, const std::string& name, double value);
    int isVertexMarked(const Vertex* v, const Attribute* a);
    /*тут ещё подумать и посмотреть теорию гиперграфов*/
    std::set<const Vertex*> filterVertices(const Attribute* a);
    HGraph filterHGraph(int (*fun)(const Vertex& v, const Attribute& a));
protected:
private:
    const Vertex* getVertexAroundVertexInEdge(const Vertex* v, const Edge* e, int dpos);
    std::set<const Vertex*> adjacentVertices ( const Vertex* v, filterAdjacentVertices f);
    std::set<Vertex>* vertices;
    std::set<Edge>* edges;
    std::set<Attribute>* attributes;
    std::set<Mark>* marks;
    std::set<VertexPos>* positions;
};

}
#endif // HGRAPH_H
