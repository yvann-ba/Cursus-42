#!/bin/bash

# Lancer la War Machine
cd libft-war-machine
bash grademe.sh
cd ..

# Aller dans le répertoire de libft-unit-test et lancer le test
cd libft-unit-test
make f
cd ..

# Préparation pour libftTester
# Assurez-vous que le fichier libft.so n'existe pas dans Libft-42
rm -f Libft-42/libft.so

# Aller dans le répertoire de libftTester et lancer le test
cd libftTester
make
cd ..
