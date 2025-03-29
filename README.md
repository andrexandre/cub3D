# Cub3D

A simple first-person perspective game engine inspired by the iconic Wolfenstein 3D game that renders environments using raycasting techniques. This project is built using the [MinilibX](https://github.com/42Paris/minilibx-linux) library and it has:

- Smooth player movement and rotation
- Minimap for navigation
- Support for customizable map files

## Usage

1. Clone the repository
```sh
git clone https://github.com/andrexandre/cub3D.git ; cd cub3D
```

2. Clone the library
```sh
git clone git@github.com:42Paris/minilibx-linux.git mlx
```

3. Compile the library and the program
```sh
make -C mlx ; make
```

4. Run the game
```sh
./cub3D maps/map_subject.cub
```

## Controls

- `W`, `A`, `S`, `D`: Move the player
- `Left` and `Right`: Rotate the camera
- `M`: Toggle minimap
- `Space`: Open or Close doors
- `ESC` or `Q`: Exit the game

### Map Configuration

Maps should be configured in `.cub` files with the following elements:

- `NO`, `SO`, `WE`, `EA`: Path to the North, South, West, and East wall textures
- `F`, `C`: RGB colors for the floor and ceiling
- Map layout using characters:
  - `1`: Wall
  - `0`: Empty space
  - `N`, `S`, `E`, `W`: Player starting position and orientation

Example map file:
```
NO ./path_to_the_north_texture.xpm
SO ./path_to_the_south_texture.xpm
WE ./path_to_the_west_texture.xpm
EA ./path_to_the_east_texture.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

> [!NOTE]
> This project is part of the 42 School curriculum
