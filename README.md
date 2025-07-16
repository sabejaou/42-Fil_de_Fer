# Fil de Fer (fdf)

Fil de Fer (fdf) est un projet graphique du cursus 42 qui permet de représenter en 3D fil de fer une carte de points issue d'un fichier. Il utilise la MiniLibX pour l'affichage et propose une navigation interactive.

## Sommaire
- [Fonctionnalités](#fonctionnalités)
- [Arborescence](#arborescence)
- [Installation](#installation)
- [Utilisation](#utilization)
- [Contrôles](#contrôles)
- [Auteur](#auteur)

---

## Fonctionnalités
- Lecture et parsing de fichiers de cartes (format .fdf)
- Affichage 3D isométrique en fil de fer
- Navigation clavier (zoom, déplacement, rotation, etc.)
- Utilisation de la MiniLibX (libmlx)
- Utilisation d'une libft personnelle

---

## Arborescence

```
42-Fil_de_Fer/
├── includes/
│   ├── fdf.h
│   └── get_next_line.h
├── src/
│   ├── drawing.c
│   ├── iso_projection.c
│   ├── keyhandle.c
│   ├── main.c
│   ├── parse_check.c
│   ├── parse_fdf_file.c
│   └── tab.c
├── libft/
│   ├── ... (libft sources et Makefile)
├── libmlx/
│   ├── ... (MiniLibX sources et Makefile)
├── test_maps/
│   ├── ... (exemples de cartes .fdf)
├── obj/
├── Makefile
└── README.md
```

---

## Installation

1. **Cloner le dépôt**  
   ```sh
   git clone https://github.com/sabejaou/42-Fil_de_Fer.git
   cd 42-Fil_de_Fer
   ```

2. **Compiler le projet**  
   ```sh
   make
   ```
   Cela compile la libft, la libmlx et le projet principal. Le binaire `fdf` est généré à la racine.

---

## Utilisation

1. **Lancer le programme avec une carte d'exemple :**
   ```sh
   ./fdf test_maps/42.fdf
   ```

2. **Ajouter vos propres cartes** dans le dossier `test_maps/` (format .fdf)

3. **Format des fichiers .fdf :**
   - Une ligne par ligne de la carte
   - Valeurs séparées par des espaces
   - Chaque valeur représente une altitude

---

## Contrôles

- **Flèches** : déplacer la carte
- **+/-** : zoom in/out
- **ESC** : quitter le programme

---

## Auteur

- **Sabejaou**  
  [sabejaou@student.42lyon.fr](mailto:sabejaou@student.42lyon.fr)