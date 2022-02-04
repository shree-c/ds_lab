#!/bin/bash
wget -q --spider http://google.com
if [ $? -ne 0 ]; then
    echo "!!!! no internet"
fi
if [ -d ~/ds ]; then
	rm -rf ~/ds
fi
if !command git &> /dev/null
then
	if command apt &> /dev/null
	then
		sudo apt install git
	elif command pacman &> /dev/null
	then
		sudo pacman -S git
	elif command pkg &> /dev/null
	then
		pkg install git
	fi
fi

git clone https://github.com/shree-c/ds_lab ~/ds

cd ds

make
