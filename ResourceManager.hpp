#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private:

    Resource* resource_ = nullptr;                                  // Zarządzany obiekt
    double out;                                                     // Zwracany wynik metody get()

    public:
    ResourceManager();                                              // Konstruktor domyslny
    ~ResourceManager();                                             // Destruktor
    ResourceManager(const ResourceManager& resource);               // Konstruktor kopiujacy
    ResourceManager& operator=(const ResourceManager& resource);    // Kopiujący operator przypisania

    double get();                                                   // metoda get
};

ResourceManager::ResourceManager() 
{
    resource_ = new Resource{};
    out = resource_->get();
}

ResourceManager::~ResourceManager()
{
    delete resource_;
}

ResourceManager::ResourceManager(const ResourceManager& resource)
{
    resource_ = new Resource{};
    out = resource.out;
}

ResourceManager& ResourceManager::operator=(const ResourceManager& resource)
{

    if(this == &resource){
        return *this;
    }

    delete resource_;
    resource_ = new Resource{};
    out = resource.out;

    return *this;
}

double ResourceManager::get()
{
    return out; 
}