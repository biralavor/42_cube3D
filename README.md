# 42_cube3D
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever, to explore ray-casting.
> [!Tip]
> - We will build this game **without any game engine** (like Unity, Unreal Godot, etc). Instead, we will use just the **Math Library** and a **Image Controller Library** called [MXL Codam](https://github.com/codam-coding-college/MLX42)
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
  - Map Colors Manager
    - Color Digit Counter
    - Color Digit Quantity Checker
    - No Garbage at Color Values
    - Color Values into Array
    - Color with Min and Max Values
  - No Garbage
    - In GameMap
  - $\color{BurntOrange}{Map Graphics Checker <--- We-are-Here!!}$


![image](https://github.com/user-attachments/assets/effee62f-6b31-4a09-a036-86428f2d6cd1)



