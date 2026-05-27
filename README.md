# SURVIVALSPACE
 
**A terminal-based space shooter — survive waves of enemies in the void of space.**
 
![Preview](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExbXg1cDNtbWU1bHY4bHk2M25vNTVoN2tncmRsbnJsZjAwb2p2YTl1MiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/iMLulRc2Crm3PCleeG/giphy.gif)
 
---
 
## FEATURES
 
| | Description |
|---|---|
| Life system | 3 lives per session |
| Player controls | Directional movement and shooting |
| Death menu | Game over screen with restart |
| Enemies | Moving units with autonomous shooting |
| Statistics | Real-time score and performance display |
 
---
 
## PREREQUISITES
 
- C compiler: `cc`
- Library: [`ncurses`](https://invisible-island.net/ncurses/)
**Debian / Ubuntu**
```bash
sudo apt install libncurses5-dev libncursesw5-dev
```
 
---
 
## 📦 INSTALLATION
 
**1. Clone the repository**
```bash
git clone git@github.com:Devanoux/SurvivalSpace.git SurvivalSpace
cd SurvivalSpace
```
 
**2. Compile**
```bash
make
```
 
**3. Run**
```bash
./SurvivalSpace
```
 
Clean compiled files:
```bash
make fclean
```
 
---
 
## CONTROLS
 
| Key | Action |
|---|---|
| `↑` `↓` `←` `→` | Move |
| `z` `q` `s` `d` | Move |
| `Space` | Shoot |
| `Q` | Quit |
 
---
 
## CREDITS
 
- [Devanoux](https://github.com/Devanoux)
- [saumon-brule](https://github.com/saumon-brule)
---
 
*42 school project.*
