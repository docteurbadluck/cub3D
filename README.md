
# cub3D

> A minimal 3D game engine inspired by *Wolfenstein 3D*, built in C with raycasting and MiniLibX.  
> Collaborators: **docteurbadluck** & **jholter**

---

## Demo

<!-- Replace the src below with your video link (GitHub hosted .mp4, YouTube, or a GIF) -->
https://github.com/user-attachments/assets/YOUR_VIDEO_ID

<img width="800" alt="cub3D gameplay" src="https://github.com/user-attachments/assets/6adbbb7d-02e8-4392-b4d3-66de0259c3cd" />

---

## How it works

The engine is built on three core ideas: **direction math**, **DDA raycasting**, and **sprite projection**.

### 1 — Direction & angle

The player's direction is stored as a unit vector derived from the viewing angle.  
`vector_x = cos(angle)` / `vector_y = sin(angle)` gives the step direction for each ray.

<!-- Upload the angle/direction diagram and replace the src -->
<img width="700" alt="Direction and angle math" src="https://github.com/user-attachments/assets/YOUR_ANGLE_DIAGRAM_ID" />

---

### 2 — DDA (Digital Differential Analysis)

For each screen column, we cast a ray and step through the grid cell by cell.  
At each step we ask: is the next crossing on the X axis or the Y axis?  
We take the closest one until we hit a wall — giving us **distance**, **side hit**, and **hit coordinates**.

<!-- Upload the DDA grid diagram and replace the src -->
<img width="700" alt="DDA raycasting grid" src="https://github.com/user-attachments/assets/YOUR_DDA_DIAGRAM_ID" />

---

### 3 — Wall rendering

Once we have the ray distance, the wall column height is simply `screen_height / distance`.  
`hit_x` and `hit_y` tell us exactly which pixel of the texture to sample.

<!-- Upload the wall rendering diagram and replace the src -->
<img width="700" alt="Wall rendering" src="https://github.com/user-attachments/assets/YOUR_WALL_DIAGRAM_ID" />

---

### 4 — Sprite projection

Sprites are transformed into camera space using a 2D matrix, then projected onto the screen.  
We first check if the sprite is inside the player's FOV before drawing it.

<!-- Upload the sprite logic diagram and replace the src -->
<img width="700" alt="Sprite logic" src="https://github.com/user-attachments/assets/YOUR_SPRITE_DIAGRAM_ID" />

---

## Objectives

- Implement a minimal **raycasting engine** from scratch
- Handle **movement**, **rotation**, and **collision detection**
- Parse and validate a **custom `.cub` map file**
- Display **textured walls, floor/ceiling colors, and animated sprites**
- Apply **Clean Architecture** principles in C (inverted dependencies, single responsibility)

---

## Controls

| Key | Action |
|-----|--------|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` | Rotate camera |
| `ESC` | Exit |

---

## Build & Run

```bash
make
./build/cub3d test.cub
```

> **Note:** Update the texture paths in your `.cub` map file to match your local setup before running.

---

## Notes

- Architecture follows **Clean Architecture** principles — rendering and game logic are decoupled.
- The map parser validates the file format strictly: walls must be fully enclosed, all texture paths must resolve.
