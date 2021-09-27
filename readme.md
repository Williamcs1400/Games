## **Respositório para a disciplina de jogos - UnB* - William Coelho da Silva

### Professora Carla Denise Castanho


#### Para compilar basta ter a biblioteca STD_Include no seu Path do TDM_GCC e executar o seguinte comando na pasta **src**: 

``` 
g++ -std=c++11  Game.cpp State.cpp Sprite.cpp Music.cpp Component.cpp GameObject.cpp Vec2.cpp Face.cpp Rect.cpp Sound.cpp Resources.cpp TileSet.cpp TileMap.cpp  -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -o Game
```
#### Após isso, pegue o **Game.exe** gerado na pasta **src** e mova-o para a pasta **assets** que ele conseguirá encontrar as dlls, imagens e sons necessários.