
# cub3D

> A minimal 3D game engine inspired by *Wolfenstein 3D*, built in C with raycasting and MiniLibX.  
> Collaborators: **docteurbadluck** & **jholter**

---

## Demo
<img width="500" alt="cub3D gameplay" src="https://github.com/user-attachments/assets/6adbbb7d-02e8-4392-b4d3-66de0259c3cd" />


[recording-2026-05-16-11-49-59.webm](https://github.com/user-attachments/assets/06a88899-4386-483a-8b52-cebbeb8e2ceb)

---

## How it works

The engine is built on three core ideas: **direction math**, **DDA raycasting**, and **sprite projection**.

### 1 — Direction & angle

<img width="500" height="300" alt="Raycasting" src="https://github.com/user-attachments/assets/dddcefd4-90e6-40e8-9b14-5b9bdd70ad56" />


### 2 — DDA (Digital Differential Analysis)

<img width="500" height="275" alt="Raycasting_2" src="https://github.com/user-attachments/assets/3677b5a5-7924-4f22-adc4-466d07ad7f6c" />


### 3 — Wall rendering

Once we have the ray distance, the wall column height is simply `screen_height / distance`.  
`hit_x` and `hit_y` tell us exactly which pixel of the texture to sample.

<img width="500" height="325" alt="Raycasting_3" src="https://github.com/user-attachments/assets/0850084a-20dc-4e29-841c-a38a3555dddb" />


### 4 — Sprite projection

Sprites are transformed into camera space using a 2D matrix, then projected onto the screen.  
We first check if the sprite is inside the player's FOV before drawing it.

<img width="400" height="400" alt="sprite" src="https://github.com/user-attachments/assets/fe12dd54-8ccf-45e4-888e-c37ad27ab02b" />

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
## Architecture 

<img width="852" height="1012" alt="architecture_global drawio" src="https://github.com/user-attachments/assets/1ed23a66-a0cb-4647-8ff3-aabb748c6bf2" />


---
