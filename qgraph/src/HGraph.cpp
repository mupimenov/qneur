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
HGraph::vertexPositionInEdge(const Vertex* v, const Edge* e)
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
HGraph::markVertex(const Vertex* v, const std::string& attrName, double value = 0.)
{
    Attribute a = {name: attrName};
    attributes->insert(a);

    Mark m = {v: v, a: &a, value: value};

    marks->insert(m);

    return v;
}

std::set<const Edge*> 
HGraph::incidentEdges(const Vertex* v)
{
    std::set<const Edge*> es;
    for (std::set<Edge>::iterator it = edges->begin(); it != edges->end(); it++)
    {
        std::set<const Vertex*>::const_iterator vit = it->vertices.find(v);
        if (vit != it->vertices.end())
            es.insert(&*it);
    }
    return es;
}

const Vertex* 
HGraph::getVertexAroundVertexInEdge(const Vertex* v, const Edge* e, int dpos)
{
    int pos = vertexPositionInEdge(v, e);
    for (std::set<const Vertex*>::iterator vit = e->vertices.begin(); vit != e->vertices.end(); vit++)
    {
        if (vertexPositionInEdge(*vit, e) == pos + dpos)
            return *vit;
    }
    return NULL;
}

const Vertex* 
HGraph::nextVertexAfterVertexInEdge(const Vertex* v, const Edge* e)
{
    return getVertexAroundVertexInEdge(v, e, 1);
}

const Vertex* 
HGraph::prevVertexBeforeVertexInEdge(const Vertex* v, const Edge* e)
{
    return getVertexAroundVertexInEdge(v, e, -1);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  HGraph::adjacentVertices
 *  Description:  
 * =====================================================================================
 */
std::set<const Vertex*>
HGraph::adjacentVertices ( const Vertex* v, filterAdjacentVertices f) 
{

    std::set<const Vertex*> vs;
    std::set<const Edge*> es = incidentEdges(v);
    for (std::set<const Edge*>::iterator it = es.begin(); it != es.end(); it++)
    {
        const Vertex* av = (this->*f)(v, *it);
        if (av != 0)
            vs.insert(av);
    }
    return vs;
    
}		/* -----  end of function Neurnet::adjacentVertices  ----- */

std::set<const Vertex*> 
HGraph::nextAdjacentVertices(const Vertex* v)
{
    return adjacentVertices(v, &HGraph::nextVertexAfterVertexInEdge);
}

std::set<const Vertex*> 
HGraph::prevAdjacentVertices(const Vertex* v)
{
    return adjacentVertices(v, &HGraph::prevVertexBeforeVertexInEdge);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  HGraph::getAttibute
 *  Description:  Get point to attribute having actual name  
 * =====================================================================================
 */
const Attribute*
HGraph::getAttribute (const std::string& name)
{
    Attribute a = {name: name}; 
    std::set<Attribute>::const_iterator it = attributes->find(a);
    return &*it;
}		/* -----  end of function HGraph::getAttibute  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  HGraph::filterVertices
 *  Description:  
 * =====================================================================================
 */
std::set<const Vertex*>
HGraph::filterVertices ( const Attribute* a )
{
    std::set<const Vertex*> vs;
    for (std::set<Vertex>::iterator it = vertices->begin(); it != vertices->end(); it++)
    {
        if (isVertexMarked(&*it, a))
            vs.insert(&*it);
    }
    return vs;
}		/* -----  end of function HGraph::filterVertices  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  HGraph::isVertexMarked
 *  Description:  
 * =====================================================================================
 */
int
HGraph::isVertexMarked (const Vertex* v, const Attribute* a )
{
    Mark m = {v: v, a: a, value: 0.};
    std::set<Mark>::const_iterator it = marks->find(m);
    if (it != marks->end())
        return 1;
    return 0; 
}		/* -----  end of function HGraph::isVertexMarked  ----- */

}

