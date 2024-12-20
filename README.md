# **push_swap**

## **Description**
Le projet **push_swap** est une implémentation algorithmique visant à trier des nombres en utilisant deux piles et un ensemble d'instructions prédéfinies. L'objectif principal est d'optimiser le nombre d'opérations nécessaires pour atteindre un tableau trié.

Ce projet est conçu pour approfondir la compréhension des algorithmes de tri, la gestion efficace de la mémoire et la manipulation de structures de données simples comme les piles.

---

## **Fonctionnalités**
- Tri d'une liste d'entiers en utilisant deux piles (`a` et `b`).
- Ensemble d'instructions limité :
  - `sa`, `sb`, `ss` : Échanger les deux premiers éléments de la pile.
  - `ra`, `rb`, `rr` : Faire pivoter la pile vers le haut.
  - `rra`, `rrb`, `rrr` : Faire pivoter la pile vers le bas.
  - `pa`, `pb` : Pousser un élément d'une pile à l'autre.
- Optimisation des opérations pour minimiser le coût total.

---

## **Utilisation**
### **Compilation**
Pour compiler le programme, utilisez `make` :
```bash
make
```

### **Exécution**
Exemple d'utilisation pour trier une liste de nombres :
```bash
./push_swap 3 2 5 1 4
```

---

## **À propos de l'algorithme**
Mon algorithme s'inspire de l'article suivant pour l'optimisation des mouvements à effectuer lors du tri sur les piles de grande taille :  
[Push Swap: The Least Amount of Moves with Two Stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a).

---

Projet réalisé par JBmader.
