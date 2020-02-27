# Mettre en place une communication en VNC entre la Jetson Nano et un ordinateur
# 1. Côté Jetson Nano
Le paquet *vino* est déjà installé par défaut
Copier le script de configuration *openvino* dans le *home* de la Jetson Nano
Lancer le script
```sh
./openvino
```

**Vérifier que la Jetson Nano et l'ordinateur soient sur le même réseau**
Connaître l'adresse IP de la Jetson Nano
```sh
ifconfig
```

# 2. Côté ordinateur
Installer VNCViewer
Se connecter à la Jetson avec le port 5901 ou 5902 si cela ne se connecte pas

# 3. Dans le cas d'une configuration sans écran
Si la Jetson Nano est sur le système aptère non connectée à l'écran, il est possible de la démarrer sans écran
Toutefois, **il faut configurer la carte Wifi pour qu'elle se connecte automatiquement au bon réseau**
Après le démarrage de la Jetson Nano, effectuer les étapes suivantes

Sur le PC, ouvrir une connexion ssh
```sh
ssh jetson@<adresse_ip>
```
Lancer le script openvino
Fermer la connexion ssh

Se conencter à la Jetson Nano par VNC

Des tests ont montré que la conenxion est très lente (une image par seconde en moyenne)
Cela semble venir de la carte réseau de la Jetson Nano

