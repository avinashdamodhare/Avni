////////////////////////////////////////////////////////////////////////////////////////////////
// Singleton Template
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SINGLETONTEMPLATE_H_
#define SINGLETONTEMPLATE_H_
#include "AvniInterfaces.h"

namespace Avni
{

    template <typename T>
    class SingletonTemplate
    {
    public:
        SingletonTemplate()
        {
            if (!m_instance)
            {
                m_instance = static_cast<T*>(this);
            }
            /*else
            {
                printf("Duplicate Singleton Creation!!");
            }*/
        }
        ~SingletonTemplate()
        {
            m_instance = NULL;
        }

        static T*   Instance();
        static T&   Get()                            { return *Instance(); }
        static void CreateSingleton();
        static void DestroySingleton();

    private:
        static T* m_instance;
    };

    template<typename T> T* SingletonTemplate<T>::m_instance = NULL;

    template<typename T> void SingletonTemplate<T>::CreateSingleton()
    {
        new T();
    }

    template<typename T> void SingletonTemplate<T>::DestroySingleton()
    {
        if (T::Instance())
            delete T::Instance();
    }

    template<typename T> T* SingletonTemplate<T>::Instance()
    {
        if (!T::m_instance)
            T::CreateSingleton();
        return T::m_instance;
    }
}
#endif