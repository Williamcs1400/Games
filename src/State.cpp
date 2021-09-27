#include "../include/State.hpp"

using namespace std;

State::State(){
    quitRequested = true;

    GameObject* GO = new GameObject();
	Sprite *bg = new Sprite("./images/title.jpg", *GO);
	GO->AddComponent(bg);
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

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.contains( {(float)mouseX, (float)mouseY} ) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				float pi = 3.14159265359;
				Vec2 objPos = Vec2(200, 0).GetRotated(-pi + pi * (rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::LoadAssets(){
    
}

void State::Update(float dt){
    Input();
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
    for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
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

	GO->AddComponent(sprite);
	GO->AddComponent(sound);
	GO->AddComponent(face);

	objectArray.emplace_back(GO);
}

bool State::getQuitRequested(){ 
    return quitRequested;
}