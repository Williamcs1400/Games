#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <Component.hpp>
    #include <Rect.hpp>
    #include <vector>
    using namespace std;

    class GameObject{
        public:
            GameObject();
            ~GameObject();
            void Update(float dt);
            void Render();
            bool IsDead();
            void RequestDelete();
            void AddComponent(Component* cpt);
            void RemoveComponent(Component* cpt);
            Component* GetComponent(string type);
            Rect box;

        private:
            vector<Component*> components;
            bool isDead;

    };

#endif