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

