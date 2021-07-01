#!/usr/bin/env bash

## ANSI Colors (FG & BG)
RED="$(printf '\033[31m')"  GREEN="$(printf '\033[32m')"  ORANGE="$(printf '\033[33m')"  BLUE="$(printf '\033[34m')"
MAGENTA="$(printf '\033[35m')"  CYAN="$(printf '\033[36m')"  WHITE="$(printf '\033[37m')" BLACK="$(printf '\033[30m')"
REDBG="$(printf '\033[41m')"  GREENBG="$(printf '\033[42m')"  ORANGEBG="$(printf '\033[43m')"  BLUEBG="$(printf '\033[44m')"
MAGENTABG="$(printf '\033[45m')"  CYANBG="$(printf '\033[46m')"  WHITEBG="$(printf '\033[47m')" BLACKBG="$(printf '\033[40m')"


# Path
DIR=`pwd`
DES="/usr/bin"

uninstall() {
    sudo rm ${DES}/cattie
}

## Make dirs
check_previous_install() {
	echo -e ${ORANGE}"[*] Installing Cattie..."${WHITE}
	if [[ -f "$DES/cattie" ]]; then
    echo -e ${ORANGE}"[*] Cattie is previously installed, removing old files.."${WHITE}
    uninstall
    fi
}

## Copy files
install() {
	# copy executable
	sudo cp bin/cattie ${DES}/cattie
	echo -e ${GREEN}"[*] Installed Successfully. Execute 'cattie' to Run."${WHITE}
}

check_build_status () {
    if [[ -f "bin/cattie" ]]; then
        echo -e ${GREEN}"[*] Build status confrimed!"${WHITE}
    else
        if [[ ! -d "bin/" ]]; then
            mkdir -p bin
        fi
        echo -e ${ORANGE}"[*] Catties is not build, Building cattie..."${WHITE}
        make &> /dev/null
        echo -e ${GREEN}"[*] Build success!"${WHITE}
    fi
}

## Install
check_previous_install
check_build_status
install