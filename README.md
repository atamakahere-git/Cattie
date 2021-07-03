
# Cattie
A Linux utility to view file content

# Installing Cattie

## Installing Dependecies
Install basic development package : 	<br>
	1. Debian based : `sudo apt-get install build-essential`<br>
	2. Arch based : `sudo pacman -S base-devel`<br>
	3. RHEL Based : `dnf group install "Development Tools"`<br>

## Install cattie
1. Clone the repository 
	`git clone https://github.com/tanveerraza789/Cattie.git`
2. Open the repository 
	`cd Cattie`
3. Change file permission to enable execution
	`chmod +x install.sh uninstall.sh`
4. Run `sh install.sh` to install.
5. Run `sh uninstall.sh` to uninstall.
6. To build in to local folder run `make` or `make run` to run after building.

# Usage

## Usage Example
	cattie -l 50 -r filename.txt
Expected output : Content of the file up to 50 lines or end of file whichever triggers before.
## Flags


|Flag |Usage  | Working|
--- | --- | ---
|l|`-l 10`|Number of lines to be displayed|
|r|`-r`	|View file from last|
|h|`-h`	|View the help message|
|rl|`-rl 10`|View number of lines from last|
