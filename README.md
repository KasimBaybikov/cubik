# cubik

![image](./cubik_default.gif)

The goal of `cubik` is to make *something* using raycasting (like [Wolfenstein 3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D)).

## Rules

The configuration of the game is stored in the file `*.cub`, passed to the program as a parameter. Here is an example:
```
R 800 600

NO ./textures/greystone.xpm
SO ./textures/colorstone.xpm
WE ./textures/redbrick.xpm
EA ./textures/wood.xpm
S  ./textures/barrel.xpm

F  77,34,0
C  132,252,255

111111111111111
120010001000121
1210101N1010121
121000100010021
111111111111111
```
#### Parameters
R = Screen resolution.  
NO, SO, WE, EA = The path to the texture file for each side of the world.  
S = The path to texture file for sprite.  
F, C = Сolors for ceiling and floor on RGB.  
#### Map
0 = Empty.   
1 = Wall.   
2 = Sprites.   
N, S, W or E = Initial position and rotation of the player.  
> The map should always be covered by walls on all sides

## Usage

To compile the progam you should do `make` then to start it do `./cubik <path to .cub file>`
> To control, use the W,A,S,D buttons and the arrows to rotate the camera

*You can also create your own textures and apply them in the program*
![image](./cubik_custom.gif)
