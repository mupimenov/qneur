#ifndef HGRAPH_H
#define HGRAPH_H

#include <set>

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
    int vertexPositionInEdge(const Vertex* v, Edge* e);
    /*attribute and mark methods*/
    const Vertex* markVertex(const Vertex* v, const char* name, double value);
    /*тут ещё подумать и посмотреть теорию гиперграфов*/
    HGraph filterHGraph(int (*fun)(const Vertex& v, const Attribute& a));
protected:
private:
    std::set<Vertex>* vertices;
    std::set<Edge>* edges;
    std::set<Attribute>* attributes;
    std::set<Mark>* marks;
    std::set<VertexPos>* positions;
};
}
#endif // HGRAPH_H
