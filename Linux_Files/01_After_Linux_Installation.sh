cd

# sudo apt-get update && sudo apt-get upgrade -y
#un installinhg fire fox snap package
udo snap remove firefox

sudo apt-get install vim

sudo add-apt-repository ppa:danielrichter2007/grub-customizer  
sudo apt-get update 
sudo apt-get install grub-customizer -y

sudo apt install vlc

sudo apt install preload

#gnoome tweaks
sudo apt install gnome-tweaks

sudo apt install gnome-shell-extensions

sudo apt install gnome-shell-extension-manager

sudo apt  install konsole

sudo apt install gcc

sudo apt install dolphin

sudo apt install git && git --version

git config --global user.name "dinesh-kanth-98"

git config --global user.email "chdinesh9948@gmail.com"

mkdir ~/GIT

cd GIT/

git clone https://github.com/dinesh-kanth-98/Dinesh-Kanth.git

cd

cp ~/GIT/Dinesh-Kanth/Linux_Files/bash_aliases ~/.bash_aliases

sudo apt install copyq


# installing code

sudo apt install software-properties-common apt-transport-https wget -y

wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -

sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"

sudo apt-get update

sudo apt install code && code --version

sudo apt install make

sudo apt  install curl

sudo apt install meld -y

sudo apt  install expect -y

# for python

sudo apt-get install zlib1g-dev

# installing chrome
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb
sudo apt-get install -f
sudo apt autoremove



