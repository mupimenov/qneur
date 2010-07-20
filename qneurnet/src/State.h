#ifndef __STATE_H__
#define __STATE_H__

#include "../../qgraph/src/Vertex.h"

namespace neurnet
{
struct State
{
    const graph::Vertex* v;
    double value;
};
}
#endif // __STATE_H__
