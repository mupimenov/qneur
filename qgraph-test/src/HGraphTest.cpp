/* */

#include <sstream>
#include <iostream>

#include <cstdlib>
#include <ctime> 

#include "HGraphTest.h"

namespace graph_test
{
HGraphTest::HGraphTest()
{

}

HGraphTest::~HGraphTest()
{

}

int
HGraphTest::runTest()
{
    graph::HGraph* g = new graph::HGraph();
    graph::HGraph* filled = fillRectangle(g, 1000, 100);
    std::cout << "count of vertices: " << filled->countVertices() << std::endl;
    graph::HGraph* linked = fillRandomEdges(filled, 1000, 100, 100); 
    delete linked;   
    return 0;
}

graph::HGraph*
HGraphTest::fillRectangle(graph::HGraph* g, int width, int height)
{
    int i = 0;
    std::stringstream sname;
    
    for (int h = 0; h < height; h++)
    {
        sname.str("");
        
        sname << "v" << i;
        const std::string name = sname.str();
        
        const graph::Vertex* v = g->createVertex(name);
        const graph::Vertex* from = v;
        
        std::cout << "[" << v->name << "]-";
        
        sname.str("");
        
        for (int w = 1; w < width; w++)
        {
            i++;
            
            sname.str("");
            
            sname << "v" << i;            
            const std::string name = sname.str();
            
            const graph::Vertex* to = g->createVertexAfterVertex(from, name);
            from = to;
            
            std::cout << ">" << to->name;
        }
        i++;
        std::cout << std::endl;
    }
    return g;
}

graph::HGraph*
HGraphTest::fillRandomEdges(graph::HGraph* g, int width, int height, int count)
{
    srand((unsigned)time(0));    
    std::stringstream sname;
    
    for (int i = 0; i < count; ++i)
    {
        sname.str("");
        
        int ia = rand() % (width * height);
        sname << "v" << ia;
        const std::string aname = sname.str();    
        
        sname.str("");
                
        int ib = rand() % (width * height);
        sname << "v" << ib;
        const std::string bname = sname.str();
        
        const graph::Vertex* a = g->getVertex(aname);
        const graph::Vertex* b = g->getVertex(bname);
        
        std::cout << "create random link: (" << a->name << ":" << b->name << ")" << std::endl;
    
        g->linkVertices(a, b);
    }
    return g;
}
}
