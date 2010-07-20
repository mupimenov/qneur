#include <iostream>
#include "HGraph.h"
namespace graph
{
HGraph::HGraph()
{
    vertices = new std::set<Vertex>();
    edges = new std::set<Edge>();
    attributes = new std::set<Attribute>();
    marks = new std::set<Mark>();
    positions = new std::set<VertexPos>();
}

HGraph::~HGraph()
{
    delete vertices;
    delete edges;
    delete attributes;
    delete marks;
    delete positions;
}

const Vertex*
HGraph::createVertex(const std::string& name)
{
    Vertex v = {name: name};
    vertices->insert(v);

    std::set<Vertex>::const_iterator it = vertices->find(v);
    return &*it;
}

const Vertex*
HGraph::createVertexAfterVertex(const Vertex* v, const std::string& name)
{
    Vertex nv = {name: name};
    vertices->insert(nv);

    Edge e;
    e.vertices.insert(v);
    e.vertices.insert(&nv);

    edges->insert(e);

    VertexPos vp_v =  {v: v, e: &e, pos: 0};    
    VertexPos vp_nv = {v: &nv, e: &e, pos: 1};

    positions->insert(vp_v);
    positions->insert(vp_nv);

    std::set<Vertex>::const_iterator it = vertices->find(nv);
    return &*it;
}

const Vertex*
HGraph::createVertexAfterVertexInEdge(const Vertex* v, Edge* e, const std::string& name)
{
    Vertex nv = {name: name};
    vertices->insert(nv);
    
    e->vertices.insert(&nv);
    
    int vpos = vertexPositionInEdge(v, e);
    VertexPos nvpos = {v: &nv, e: e, pos: ++vpos};
    positions->insert(nvpos);
    
    std::set<Vertex>::const_iterator it = vertices->find(nv);
    return &*it;
}

int 
HGraph::vertexPositionInEdge(const Vertex* v, Edge* e)
{
    VertexPos vpos = {v: v, e: e, pos: 0};
    std::set<VertexPos>::const_iterator it = positions->find(vpos);
    if (it != positions->end())
    {
        return it->pos;
    }
    else
    {
        return 0;
    }
}

const Vertex*
HGraph::getVertex(const std::string& name)
{    
    for (std::set<Vertex>::iterator it = vertices->begin(); it != vertices->end(); it++)
    {
        const Vertex* v = &*it;
        
        if (v->name == name)
        {            
            return v;
        }
    }
    return 0;
}

int
HGraph::countVertices()
{
    return vertices->size();
}

int
HGraph::linkVertices(const Vertex* a, const Vertex* b)
{
    Edge e;
    e.vertices.insert(a);
    e.vertices.insert(b);

    edges->insert(e);
    return 0;
}

const Vertex*
HGraph::markVertex(const Vertex* v, const char* attrName, double value = 0.)
{
    Attribute a = {name: attrName};
    attributes->insert(a);

    Mark m;
    m.v = v;
    m.a = &a;
    m.value = value;

    marks->insert(m);

    return v;
}
}

