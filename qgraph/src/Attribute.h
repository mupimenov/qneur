#ifndef ATTRIBUTE_H_INCLUDED
#define ATTRIBUTE_H_INCLUDED

#include <string>
namespace graph
{
struct Attribute
{
    const std::string name;
    
    bool operator<(const Attribute& a) const
    {
        return (name < a.name);
    };
    bool operator==(const Attribute& a) const
    {
        return (name == a.name);
    };
};
}
#endif // ATTRIBUTE_H_INCLUDED
