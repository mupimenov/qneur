/*
 * =====================================================================================
 *
 *       Filename:  Cluster.cpp
 *
 *    Description:  cluster some funcs.
 *
 *        Version:  1.0
 *        Created:  11.08.2010 15:54:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mikhail Pimenov (), mupimenov@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include "Cluster.h"
namespace neurnet
{
    
    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  Cluster::smult
     *  Description:  
     * =====================================================================================
     */
    double
        Cluster::smult (Cluster& c, std::set<State> so_s)
        {
            double sum = 0.;
            for (std::set<Synapse>::iterator it = c.synapses.begin(); it != c.synapses.end(); it++)
            {
                const Synapse& synapse = *it;
                State to_find = {v: synapse.v};
                const State& state = *so_s.find(to_find);
                sum += synapse.weight * state.value;
            }
            return sum;
        }		/* -----  end of function Cluster::smult  ----- */
}
