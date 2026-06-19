#pragma once
#include <unordered_map>
#include <Entity.hpp>

template <typename T>
class ComponentStorage
{
public:
    void Add(Entity entity, const T &component)
    {
        components[entity] = component;
    }

    void Remove(Entity entity)
    {
        components.erase(entity);
    }

    bool Has(Entity entity) const
    {
        return components.find(entity) != components.end();
    }

    T &Get(Entity entity)
    {
        return components.at(entity);
    }

    std::unordered_map<Entity, T> &GetAll()
    {
        return components;
    }

private:
    std::unordered_map<Entity, T> components;
};