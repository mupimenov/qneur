#include <sstream>
#include <vector>
#include <set>

#include "Neurnet.h"

namespace neurnet
{

Neurnet::Neurnet()
{
    graph = new HGraph();
    clusters = new Clusters();
    order = new Order();
}

Neurnet::~Neurnet()
{
    delete graph;
    delete clusters;
    delete order;
}

Neurnet::Neurnet(int inputCount, int hiddenCount, int outputCount)
{
    Neurnet();  
    
    /* input layer */
    name inputAttrName = "input"; 
    Order vs_input = createLayer(0, inputCount, inputAttrName);    
    /* hidden layer */
    name hiddenAttrName = "hidden";
    Order vs_hidden = createLayer(inputCount, inputCount + hiddenCount, hiddenAttrName);
    
    /* link */
    linkLayers(vs_input, vs_hidden);
    
    /* output layer */
    name outputAttrName = "output";
    Order vs_output = createLayer(inputCount + hiddenCount, inputCount + hiddenCount + outputCount, outputAttrName);
    
    /* link */
    linkLayers(vs_hidden, vs_output);
}

Order 
Neurnet::createLayer(int start, int count, name& attrName)
{
    Order vs;
    std::stringstream sname;    
    for (int i = start; i < count; ++i)
    {
        sname.str("");
        sname << "v" << i;
        const std::string name = sname.str();
        const graph::Vertex* v = graph->createVertex(name);        
        
        graph->markVertex(v, attrName, 0.);
        
        vs.insert(vs.end(), v);
    }
    return vs;
}

const Order&
Neurnet::linkLayers(const Order& va, const Order& vb)
{
    for (Order::iterator ita = va.begin(); ita < va.end(); ++ita)
    {
        for (Order::iterator itb = vb.begin(); itb < vb.end(); ++itb)
        {
            graph->linkVertices(*ita, *itb);
        }
    }
    return vb; 
}

int 
Neurnet::prepareTheNet()
{
   
    order = getOrder();
    clusters = getClusters(order);
    return 0;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::getLayer
 *  Description:  Returns set of Vertex* marked given attribute name
 * =====================================================================================
 */
FuzzyOrder
Neurnet::getLayer ( name& attrName )
{
    const graph::Attribute* a = graph->getAttribute(attrName);
    FuzzyOrder vs = graph->filterVertices(a);
    return vs;
}		/* -----  end of function Neurnet::getLayer  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::getLayerAfter
 *  Description:  Returns a set of Vertex* following after given vertices
 * =====================================================================================
 */
FuzzyOrder
Neurnet::getLayerAfter ( FuzzyOrder& vs )
{
    FuzzyOrder avs;
    for (FuzzyOrder::iterator it = vs.begin(); it != vs.end(); it++)
    {
        FuzzyOrder nextAdjVs = graph->nextAdjacentVertices(*it);
        avs.insert(nextAdjVs.begin(), nextAdjVs.end());
    }
    return avs;
}		/* -----  end of function Neurnet::getLayerAfter  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::getOrder
 *  Description:  
 * =====================================================================================
 */
Order*
Neurnet::getOrder ( )
{
    delete order;
    order = new Order();

    string attrName = "input";
    FuzzyOrder vs_i = getLayer(attrName);
    if (!vs_i.empty())
        order->insert(order->end(), vs_i.begin(), vs_i.end());
    FuzzyOrder vs_h = getLayerAfter(vs_i);
    if (!vs_h.empty())
        order->insert(order->end(), vs_h.begin(), vs_h.end());
    FuzzyOrder vs_o = getLayerAfter(vs_h);
    if (!vs_o.empty())
        order->insert(order->end(), vs_o.begin(), vs_o.end());

    return order; 

}		/* -----  end of function Neurnet::getOrder  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::getWeights
 *  Description:  
 * =====================================================================================
 */
Clusters* 
Neurnet::getClusters ( const Order* ord  )
{
    delete clusters;
    clusters = new Clusters();
    
    for (Order::iterator it = ord->begin(); it != ord->end(); it++)
    {
        FuzzyOrder prevVs = graph->prevAdjacentVertices(*it);
        Cluster c = {v: *it};
        for (FuzzyOrder::iterator vit = prevVs.begin(); vit != prevVs.end(); vit++)
        {
            Synapse sy = {v: *vit, weight: 1.0};
            c.synapses.insert(sy);
        }
    }

    return clusters; 
}		/* -----  end of function Neurnet::getWeights  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::getState
 *  Description:  
 * =====================================================================================
 */
States
Neurnet::getState (const Order* ord, const States& input)
{
    States ss;

    for (Order::iterator it = ord->begin(); it != ord->end(); it++)
    {
        State to_find = {v: *it};
        States::iterator sit = input.find(to_find);
        State s = {v: *it};
        if (sit == input.end())
        {
           s.value = 0.;
        }
        else
        {
           State found = *sit;
           s.value = found.value;
        }
        ss.insert(s);
    }

    return ss;
}		/* -----  end of function Neurnet::getState  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::compute
 *  Description:  
 * =====================================================================================
 */
States
Neurnet::compute ( const States& input )
{
    return compute(input, *clusters);
}		/* -----  end of function Neurnet::compute  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::compute
 *  Description:  
 * =====================================================================================
 */

States
Neurnet::compute (const States& input, const Clusters& c)
{

    States s = getState(order, input);

    for (Order::iterator it = order->begin(); it != order->end(); it++)
    {
        Cluster cl = {v: *it};
        Clusters::iterator cli = c.find(cl);
        if (cli == c.end())
            continue;
        double jOut = justOutput(*cli, s);
        State to_find = {v: *it};
        s.erase(s.find(to_find));
        to_find.value = jOut;
        s.insert(to_find);
    }

    return s;
}		/* -----  end of function Neurnet::compute  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::justOutput
 *  Description:  
 * =====================================================================================
 */
double
Neurnet::justOutput (const Cluster& c, const States& vars)
{
    double sum = 0;
    for (Synapses::iterator it = c.synapses.begin(); it != c.synapses.end(); it++)
    {
        const graph::Vertex* v = it->v;
        double weight = it->weight;
        State to_find = {v: v};
        States::const_iterator cit = vars.find(to_find);
        if (cit == vars.end())
            continue;
        const State& before = *cit;
        sum += weight * before.value;
    }
    return sum;
}		/* -----  end of function Neurnet::justOutput  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::qteach
 *  Description:  
 * =====================================================================================
 */
int
Neurnet::qteach ( const States& input, const States& output )
{
    for (Order::iterator it = order->begin(); it != order->end(); it++)
    {
        Cluster c = {v: *it};
        Clusters::iterator found_c = clusters->find(c);
        if (found_c == clusters->end())
            continue;
        const Cluster& cl = *found_c;
        for (Synapses::iterator sit = cl.synapses.begin(); sit != cl.synapses.end(); sit++)
        {
            adjustSynapse(cl, *sit, input, output);
        }
    }
    return 0;
}		/* -----  end of function Neurnet::qteach  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::adjustSynapse
 *  Description:  
 * =====================================================================================
 */

void
Neurnet::adjustSynapse( const Cluster& c,
                        const Synapse& s,
                        const States& input,
                        const States& output)
{
    char steps = 10;
    while (steps > 0)
    {
        Synapse old = s;
        Synapse nou = s;
        steps--;
    }
    return ;
}		/* -----  end of function Neurnet::adjustSynapse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Neurnet::error
 *  Description:  
 * =====================================================================================
 */
double 
Neurnet::error (const States& input, const States& output, const Clusters* c)
{
    /* 
    int n = output.size();
    double sumSqr = 0.;
    States computed = compute(input, c);
    for (States::iterator it = output.begin(); it != output.end(); it++)
    {
        if (computed.find(*it) == computed.end())
            continue;
        
    }
    */
    return 0.;
}		/* -----  end of function Neurnet::error  ----- */




}
