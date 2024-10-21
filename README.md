# MiniShell

## Descritption 
Minishell est un projet de shell minimaliste développé en C. Il implémente les fonctionnalités de base d'un interpréteur de commandes comme bash ou zsh. Ce shell prend en charge plusieurs commandes intégrées, la gestion des processus, les pipes, les redirections, et l'utilisation de variables d'environnement.

## Fonctionnalités

- Exécution de commandes intégrées : cd, echo, pwd, - export, unset, env, exit.
- Gestion des redirections (>, <, >>).
- Gestion des pipes (|).
- Gestion des variables d'environnement.
- Signal handling (Ctrl+C, Ctrl+, Ctrl+D).
- Gestion des erreurs de syntaxe.

## Installation

### Prérequis

- Un compilateur compatible avec le C (comme `gcc` ou `clang`).
- La bibliothèque `libft` incluse dans le projet.

### Étapes d'installation :

1. Clonez le dépôt dans votre répertoire local :
   ```bash
   git clone <url_du_projet>
   cd minishell

2. Compilez le projet avec le Makefile :
    make

3. Lancez le shell :
    ./minishell


## Utilisation

Une fois que `minishell` est lancé, vous pouvez entrer des commandes comme dans un shell traditionnel. Voici quelques exemples de commandes prises en charge :

- **Commande intégrée `cd` :**
  ```bash
  cd /path/vers/repertoire

- **Commande `echo` avec des options :**
    ```bash
    echo -n "Hello World

- **Redirection de la sortie vers un fichier :**
    ```bash
    ls > output.txt

- **Utilisation des pipes:**
    ```bash
    ls | grep minishell

- **Afficher les variables d'environnement :**
    ```bash
    env

- **Définir ou modifier une variable d'environnement :**
    ```bash
    export VAR=value

- **Supprimer une variable d'environnement :**
    ```bash
    unset VAR

- **Quitter le shell :**
    ```bash
    exit


## Dossier du projet

- libft : Contient la bibliothèque libft utilisée dans le projet.
- srcs : Contient le code source du projet.
- Makefile : Fichier pour automatiser la compilation du projet.