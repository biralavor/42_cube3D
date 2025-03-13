  # 42_cube3D
| ![cub3de](https://github.com/user-attachments/assets/1cfe735e-9574-4941-8bcf-4694896f40b5) | This project is inspired by the world-famous Wolfenstein 3D game,<br> which was the first FPS ever, to explore ray-casting.<br> Yes, this game repository is being built with NO GAME ENGINE. |
| :-: | :-: |


> [!Tip]
> - We are building this game **without any game engine** (like Unity, Unreal Godot, etc). Instead, we are using just the **Math Library** and a **Image Controller Library** called [MXL Codam](https://github.com/codam-coding-college/MLX42)
> - Our game will simulates a 3D environment (but it is totally 2D inside), using raycast calculations to a faster image rendering
> - This is a **Pair-programming** project with @GioGardinali, in a **TBD** mode ([Trunk Based Development](https://trunkbaseddevelopment.com/#one-line-summary) which help us to  do small merges, in a non-stop iteration). You can follow the **Project Development** at [Github Projects](https://github.com/users/biralavor/projects/10)
> - You can follow our **Automated Tests** at [GitHub Actions](https://github.com/biralavor/42_cube3D/actions)

> [!WARNING]
> **cub3d** is a WIP Project. Please check what we're doing now at [Github Projects](https://github.com/users/biralavor/projects/10)

## Here is what we have done so far:
The majority functions of `map_validation_manager` was built in boolean type. This approach helps code maintenance and readability.
- Map Validation Manager
  - File Checker
    - Valid Extension Checker
    - Map Reader
    - Unique Definitions for Compass Points
    - Nothing After Map
  - Map Player Checker
    - Player Detected
    - Player Free To Go
  - Closed Wall Manager
    - Top Wall Finder
    - Middle Wall Finder
    - Bottom Wall Finder
  - No Garbage Manager
    - No Garbage at Texture
    - No Garbage at Gamemap
  - Map Colors Manager
    - Color Digit Counter
    - Color Digit Quantity Checker
    - No Garbage at Color Values
    - Color Values into Array
    - Color with Min and Max Values
  
  This means that our $\color{BurntOrange}{Map Validation}$ is ready to go \o/

![image](https://github.com/user-attachments/assets/b3675c28-1094-4b77-859a-0839f642d644)

## How to run it:
### Cloning this repository:
```
mkdir 42_cube3D && cd 42_cube3D && git clone https://github.com/biralavor/42_cube3D.git .
```
### Compiling the executable file with `Makefile`.
It will generate a `cub3d` file
```
make
```
### Calling the executable `cub3d` with a map file attached.
This executable needs a map file. You can check all map files already created at the folder `maps/`.
There is more than 20 maps that could be added to the executable file.
To do so, you need to:
```
./cub3d maps/{add_the_map_filename_here}
```
Or, you can go faster by calling the `default.cub` map by typing:
```
make go
```

## Do you want to stress the executable?
We can help you with that!
We have a `Makefile` prepared to assist you with your curiosity:
### Run `valgrind` to verify memory leaks and invalid read/write at memory:
```
make val
```
### Run `gdb` to debug
```
make gdb
```
### Run `game instructions`
```
make help
```

> [!WARNING]
> **cub3d** is a WIP Project. Maybe the Game isn't fully ready yet as expected. Please check our [Releases](https://github.com/biralavor/42_cube3D/releases) and what we're doing now at [Github Projects](https://github.com/users/biralavor/projects/10)


> All 42 Badges -- the astronomer Human Coder -- were done by Larissa Cristina [@mewmewdevart](https://github.com/mewmewdevart/42Badges)
