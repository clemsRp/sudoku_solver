<h1 align="center">🧩 Sudoku Solver</h1>

Bienvenue sur **Sudoku Solver** !  
Un programme en **C** permettant de résoudre automatiquement des grilles de Sudoku, conçu pour m’entraîner à l’algorithmique, à la gestion de la mémoire et à la programmation bas niveau. 🚀

## 🎨 Aperçu

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/600px-Sudoku-by-L2G-20050714.svg.png" alt="Sudoku Exemple" width="60%"/>

*(image illustrative, pas une capture d’écran réelle)*

## 📌 Fonctionnalités
- 📝 Résolution automatique de **toutes** les solutions possibles d’une grille
- 🔢 Comptage et affichage du **nombre total de solutions**
- 🔎 Vérification de la validité d’une grille
- ⚡ Algorithme de **backtracking** optimisé
- 📂 Chargement de grilles depuis un fichier texte
- 🖥️ Affichage clair et formaté en console
- 🧪 Génération de grilles aléatoires avec un script Perl fourni

## 🛠 Technologies utilisées
- **Langage** : C (ANSI C)
- **Outils** : `gcc`, `make`, `perl`
- **Algorithmie** : Backtracking / recherche exhaustive

## 🚀 Installation et Exécution

```sh
# Cloner le projet
git clone https://github.com/TON-USER/sudoku_solver.git
cd sudoku_solver

# Compiler le programme
make

# Exécuter avec une grille donnée (ex: grille.txt)
./sudoku_solver grille.txt
