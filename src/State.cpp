#include "../include/State.hpp"

using namespace std;

State::State(){
    quitRequested = true;

    GameObject* GO = new GameObject();
	Sprite *bg = new Sprite("./images/title.jpg", *GO);
	GO->AddComponent(bg);
	GO->AddComponent(new CameraFollower(*GO)); 
	GO -> box.x = 0;
	GO -> box.y = 0;

	objectArray.emplace_back(GO);

	GameObject* GO2 = new GameObject();
	TileSet* TS = new TileSet(64, 64, "./images/tileset.png");
	TileMap* aux = new TileMap(*GO2, "./map/tileMap.txt", TS);

	GO2->AddComponent(aux);
	GO2->box.x = 0;
	GO2->box.y = 0;

	objectArray.emplace_back(GO2);

    music = new Music("./musics/stageState.ogg");
    music->Play(-1);
}

State::~State(){
    objectArray.clear();
}

void State::LoadAssets(){
    
}

void State::Update(float dt){
    InputManager& InputManager = InputManager::GetInstance();
	quitRequested = InputManager.QuitRequested() || InputManager.IsKeyDown(ESCAPE_KEY);

	if(InputManager.KeyPress(SPACE_KEY)) {
		float pi = 3.14159265359;
		Vec2 objPos = Vec2(200, 0).GetRotated(-pi + pi * (rand() % 1001)/500.0 ) + Vec2(InputManager.GetMouseX(), InputManager.GetMouseY());
		AddObject((int)objPos.x, (int)objPos.y);
	}

    for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }

    for(unsigned int i = 0; i < objectArray.size(); i++){
        if(objectArray[i]->IsDead()){
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render(){
	TileMap* tileMap = nullptr;
    for(unsigned int i = 0; i < objectArray.size(); i++){
        if(objectArray[i]->GetComponent("TileMap") != nullptr){
			tileMap = (TileMap*) objectArray[i]->GetComponent("TileMap");
			tileMap->RenderLayer(0, Camera::pos.x, Camera::pos.y);
		}else{
			objectArray[i]->Render();
		}
    }
	if(tileMap != nullptr) {
        for(int i = 2; i <= tileMap->GetDepth(); i++) {
            tileMap->RenderLayer(i - 1, Camera::pos.x * i, Camera::pos.y * i);
        }
    }
}

void State::AddObject(int mouseX, int mouseY){
    GameObject* GO = new GameObject();
	Sprite* sprite = new Sprite("./images/penguinface.png", *GO);
	Sound* sound = new Sound(*GO, "./musics/boom.wav");
	Face* face = new Face(*GO);

	float posX = GO->box.w / 2;
	float posY = GO->box.h / 2;
    GO->box.x = mouseX - posX;
    GO->box.y = mouseY - posY;
    GO->box += Camera::pos;

	GO->AddComponent(sprite);
	GO->AddComponent(sound);
	GO->AddComponent(face);

	objectArray.emplace_back(GO);
}

bool State::getQuitRequested(){ 
    return quitRequested;
}